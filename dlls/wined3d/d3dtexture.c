/*
 * Texture handling for direct3d
 *
 * Most code taken from d3dx9_36/surface.c Copyright (C) 2012 Józef Kucia
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#define COBJMACROS

#include "config.h"
#include "wine/port.h"

#include "wine/debug.h"

#include <objbase.h>
#include "initguid.h"
#include "wincodec.h"

#include "wine/wined3d.h"



//DEFINE_GUID(IID_IWICImagingFactory, 0xec5ec8a9, 0xc395, 0x4314, 0x9c,0x77, 0x54,0xd7,0xa9,0x35,0xff,0x70)

WINE_DEFAULT_DEBUG_CHANNEL(d3d);

/* dummy defines */

#define D3D_OK S_OK
#define D3DXERR_INVALIDDATA ((HRESULT)-1)
#define D3DERR_INVALIDCALL ((HRESULT)-1)

/* defines currently taken from d3d9types.h */

typedef enum _D3DRESOURCETYPE {
    D3DRTYPE_SURFACE                =  1,
    D3DRTYPE_VOLUME                 =  2,
    D3DRTYPE_TEXTURE                =  3,
    D3DRTYPE_VOLUMETEXTURE          =  4,
    D3DRTYPE_CUBETEXTURE            =  5,
    D3DRTYPE_VERTEXBUFFER           =  6,
    D3DRTYPE_INDEXBUFFER            =  7,

    D3DRTYPE_FORCE_DWORD            = 0x7fffffff
} D3DRESOURCETYPE;

typedef DWORD D3DCOLOR;

/* defines currently taken from d3dx9tex.h */

typedef enum _D3DXIMAGE_FILEFORMAT
{
    D3DXIFF_BMP,
    D3DXIFF_JPG,
    D3DXIFF_TGA,
    D3DXIFF_PNG,
    D3DXIFF_DDS,
    D3DXIFF_PPM,
    D3DXIFF_DIB,
    D3DXIFF_HDR,
    D3DXIFF_PFM,
    D3DXIFF_FORCE_DWORD = 0x7fffffff
} D3DXIMAGE_FILEFORMAT;

typedef struct _D3DXIMAGE_INFO
{
    UINT Width;
    UINT Height;
    UINT Depth;
    UINT MipLevels;
    enum wined3d_format_id Format;

    D3DRESOURCETYPE ResourceType;
    D3DXIMAGE_FILEFORMAT ImageFileFormat;
} D3DXIMAGE_INFO;

/* defines currently taken from d3dx9_private.h */

struct vec4
{
    float x, y, z, w;
};

struct volume
{
    UINT width;
    UINT height;
    UINT depth;
};

/* for internal use */
enum format_type {
    FORMAT_ARGB,   /* unsigned */
    FORMAT_ARGBF16,/* float 16 */
    FORMAT_ARGBF,  /* float */
    FORMAT_DXT,
    FORMAT_INDEX,
    FORMAT_UNKNOWN
};

struct pixel_format_desc {
    enum wined3d_format_id format;
    BYTE bits[4];
    BYTE shift[4];
    UINT bytes_per_pixel;
    UINT block_width;
    UINT block_height;
    UINT block_byte_count;
    enum format_type type;
    void (*from_rgba)(const struct vec4 *src, struct vec4 *dst);
    void (*to_rgba)(const struct vec4 *src, struct vec4 *dst, const PALETTEENTRY *palette);
};

/* functions from d3dx9_36/util.c */

static void la_from_rgba(const struct vec4 *rgba, struct vec4 *la)
{
    la->x = rgba->x * 0.2125f + rgba->y * 0.7154f + rgba->z * 0.0721f;
    la->w = rgba->w;
}

static void la_to_rgba(const struct vec4 *la, struct vec4 *rgba, const PALETTEENTRY *palette)
{
    rgba->x = la->x;
    rgba->y = la->x;
    rgba->z = la->x;
    rgba->w = la->w;
}

static void index_to_rgba(const struct vec4 *index, struct vec4 *rgba, const PALETTEENTRY *palette)
{
    ULONG idx = (ULONG)(index->x * 255.0f + 0.5f);

    rgba->x = palette[idx].peRed / 255.0f;
    rgba->y = palette[idx].peGreen / 255.0f;
    rgba->z = palette[idx].peBlue / 255.0f;
    rgba->w = palette[idx].peFlags / 255.0f; /* peFlags is the alpha component in DX8 and higher */
}

/************************************************************
 * pixel format table providing info about number of bytes per pixel,
 * number of bits per channel and format type.
 *
 * Call get_format_info to request information about a specific format.
 */
static const struct pixel_format_desc formats[] =
{
    /* format              bpc               shifts             bpp blocks   type            from_rgba     to_rgba */
    {WINED3DFMT_B8G8R8_UNORM,        { 0,  8,  8,  8}, { 0, 16,  8,  0},  3, 1, 1,  3, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_B8G8R8A8_UNORM,      { 8,  8,  8,  8}, {24, 16,  8,  0},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_B8G8R8X8_UNORM,      { 0,  8,  8,  8}, { 0, 16,  8,  0},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_R8G8B8A8_UNORM,      { 8,  8,  8,  8}, {24,  0,  8, 16},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_R8G8B8X8_UNORM,      { 0,  8,  8,  8}, { 0,  0,  8, 16},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_B5G6R5_UNORM,        { 0,  5,  6,  5}, { 0, 11,  5,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_B5G5R5X1_UNORM,      { 0,  5,  5,  5}, { 0, 10,  5,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_B5G5R5A1_UNORM,      { 1,  5,  5,  5}, {15, 10,  5,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_B2G3R3_UNORM,        { 0,  3,  3,  2}, { 0,  5,  2,  0},  1, 1, 1,  1, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_B2G3R3A8_UNORM,      { 8,  3,  3,  2}, { 8,  5,  2,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_B4G4R4A4_UNORM,      { 4,  4,  4,  4}, {12,  8,  4,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_B4G4R4X4_UNORM,      { 0,  4,  4,  4}, { 0,  8,  4,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_B10G10R10A2_UNORM,   { 2, 10, 10, 10}, {30, 20, 10,  0},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_R10G10B10A2_UNORM,   { 2, 10, 10, 10}, {30,  0, 10, 20},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_R16G16B16A16_UNORM,  {16, 16, 16, 16}, {48,  0, 16, 32},  8, 1, 1,  8, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_R16G16_UNORM,        { 0, 16, 16,  0}, { 0,  0, 16,  0},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_A8_UNORM,            { 8,  0,  0,  0}, { 0,  0,  0,  0},  1, 1, 1,  1, FORMAT_ARGB,    NULL,         NULL      },
    {WINED3DFMT_L8A8_UNORM,          { 8,  8,  0,  0}, { 8,  0,  0,  0},  2, 1, 1,  2, FORMAT_ARGB,    la_from_rgba, la_to_rgba},
    {WINED3DFMT_L4A4_UNORM,          { 4,  4,  0,  0}, { 4,  0,  0,  0},  1, 1, 1,  1, FORMAT_ARGB,    la_from_rgba, la_to_rgba},
    {WINED3DFMT_L8_UNORM,            { 0,  8,  0,  0}, { 0,  0,  0,  0},  1, 1, 1,  1, FORMAT_ARGB,    la_from_rgba, la_to_rgba},
    {WINED3DFMT_L16_UNORM,           { 0, 16,  0,  0}, { 0,  0,  0,  0},  2, 1, 1,  2, FORMAT_ARGB,    la_from_rgba, la_to_rgba},
    {WINED3DFMT_DXT1,          { 0,  0,  0,  0}, { 0,  0,  0,  0},  1, 4, 4,  8, FORMAT_DXT,     NULL,         NULL      },
    {WINED3DFMT_DXT2,          { 0,  0,  0,  0}, { 0,  0,  0,  0},  1, 4, 4, 16, FORMAT_DXT,     NULL,         NULL      },
    {WINED3DFMT_DXT3,          { 0,  0,  0,  0}, { 0,  0,  0,  0},  1, 4, 4, 16, FORMAT_DXT,     NULL,         NULL      },
    {WINED3DFMT_DXT4,          { 0,  0,  0,  0}, { 0,  0,  0,  0},  1, 4, 4, 16, FORMAT_DXT,     NULL,         NULL      },
    {WINED3DFMT_DXT5,          { 0,  0,  0,  0}, { 0,  0,  0,  0},  1, 4, 4, 16, FORMAT_DXT,     NULL,         NULL      },
    {WINED3DFMT_R16_FLOAT,          { 0, 16,  0,  0}, { 0,  0,  0,  0},  2, 1, 1,  2, FORMAT_ARGBF16, NULL,         NULL      },
    {WINED3DFMT_R16G16_FLOAT,       { 0, 16, 16,  0}, { 0,  0, 16,  0},  4, 1, 1,  4, FORMAT_ARGBF16, NULL,         NULL      },
    {WINED3DFMT_R16G16B16A16_FLOAT, {16, 16, 16, 16}, {48,  0, 16, 32},  8, 1, 1,  8, FORMAT_ARGBF16, NULL,         NULL      },
    {WINED3DFMT_R32_FLOAT,          { 0, 32,  0,  0}, { 0,  0,  0,  0},  4, 1, 1,  4, FORMAT_ARGBF,   NULL,         NULL      },
    {WINED3DFMT_R32G32_FLOAT,       { 0, 32, 32,  0}, { 0,  0, 32,  0},  8, 1, 1,  8, FORMAT_ARGBF,   NULL,         NULL      },
    {WINED3DFMT_R32G32B32A32_FLOAT, {32, 32, 32, 32}, {96,  0, 32, 64}, 16, 1, 1, 16, FORMAT_ARGBF,   NULL,         NULL      },
    {WINED3DFMT_P8_UINT,            { 8,  8,  8,  8}, { 0,  0,  0,  0},  1, 1, 1,  1, FORMAT_INDEX,   NULL,         index_to_rgba},
    {WINED3DFMT_R8G8_SNORM_L8X8_UNORM,      { 0,  8,  8,  8}, { 0,  0,  8, 16},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    /* marks last element */
    {WINED3DFMT_UNKNOWN,       { 0,  0,  0,  0}, { 0,  0,  0,  0},  0, 1, 1,  0, FORMAT_UNKNOWN, NULL,         NULL      },
};


/************************************************************
 * map_view_of_file
 *
 * Loads a file into buffer and stores the number of read bytes in length.
 *
 * PARAMS
 *   filename [I] name of the file to be loaded
 *   buffer   [O] pointer to destination buffer
 *   length   [O] size of the obtained data
 *
 * RETURNS
 *   Success: D3D_OK
 *   Failure:
 *     see error codes for CreateFileW, GetFileSize, CreateFileMapping and MapViewOfFile
 *
 * NOTES
 *   The caller must UnmapViewOfFile when it doesn't need the data anymore
 *
 */
HRESULT map_view_of_file(const WCHAR *filename, void **buffer, DWORD *length)
{
    HANDLE hfile, hmapping = NULL;

    hfile = CreateFileW(filename, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    if(hfile == INVALID_HANDLE_VALUE) goto error;

    *length = GetFileSize(hfile, NULL);
    if(*length == INVALID_FILE_SIZE) goto error;

    hmapping = CreateFileMappingW(hfile, NULL, PAGE_READONLY, 0, 0, NULL);
    if(!hmapping) goto error;

    *buffer = MapViewOfFile(hmapping, FILE_MAP_READ, 0, 0, 0);
    if(*buffer == NULL) goto error;

    CloseHandle(hmapping);
    CloseHandle(hfile);

    return S_OK;

error:
    CloseHandle(hmapping);
    CloseHandle(hfile);
    return HRESULT_FROM_WIN32(GetLastError());
}

const struct pixel_format_desc *get_format_info(enum wined3d_format_id format)
{
    unsigned int i = 0;
    while(formats[i].format != format && formats[i].format != WINED3DFMT_UNKNOWN) i++;
    if (formats[i].format == WINED3DFMT_UNKNOWN)
        FIXME("Unknown format %#x (as FOURCC %s).\n", format, debugstr_an((const char *)&format, 4));
    return &formats[i];
}


/* Functions from d3dx9_36/surface.c */

/* Wine-specific WIC GUIDs */
DEFINE_GUID(GUID_WineContainerFormatTga, 0x0c44fda1,0xa5c5,0x4298,0x96,0x85,0x47,0x3f,0xc1,0x7c,0xd3,0x22);

static const struct
{
    const GUID *wic_guid;
    enum wined3d_format_id d3dformat;
} wic_pixel_formats[] = {
    { &GUID_WICPixelFormat8bppIndexed, WINED3DFMT_P8_UINT },
    { &GUID_WICPixelFormat1bppIndexed, WINED3DFMT_P8_UINT },
    { &GUID_WICPixelFormat4bppIndexed, WINED3DFMT_P8_UINT },
    { &GUID_WICPixelFormat8bppGray, WINED3DFMT_L8_UNORM },
    { &GUID_WICPixelFormat16bppBGR555, WINED3DFMT_B5G5R5X1_UNORM },
    { &GUID_WICPixelFormat16bppBGR565, WINED3DFMT_B5G6R5_UNORM },
    { &GUID_WICPixelFormat24bppBGR, WINED3DFMT_B8G8R8_UNORM },
    { &GUID_WICPixelFormat32bppBGR, WINED3DFMT_B8G8R8X8_UNORM },
    { &GUID_WICPixelFormat32bppBGRA, WINED3DFMT_B8G8R8A8_UNORM }
};

static enum wined3d_format_id wic_guid_to_d3dformat(const GUID *guid)
{
    unsigned int i;

    for (i = 0; i < sizeof(wic_pixel_formats) / sizeof(wic_pixel_formats[0]); i++)
    {
        if (IsEqualGUID(wic_pixel_formats[i].wic_guid, guid))
            return wic_pixel_formats[i].d3dformat;
    }

    return WINED3DFMT_UNKNOWN;
}

/* dds_header.flags */
#define DDS_CAPS 0x1
#define DDS_HEIGHT 0x2
#define DDS_WIDTH 0x4
#define DDS_PITCH 0x8
#define DDS_PIXELFORMAT 0x1000
#define DDS_MIPMAPCOUNT 0x20000
#define DDS_LINEARSIZE 0x80000
#define DDS_DEPTH 0x800000

/* dds_header.caps */
#define DDS_CAPS_COMPLEX 0x8
#define DDS_CAPS_TEXTURE 0x1000
#define DDS_CAPS_MIPMAP 0x400000

/* dds_header.caps2 */
#define DDS_CAPS2_CUBEMAP 0x200
#define DDS_CAPS2_CUBEMAP_POSITIVEX 0x400
#define DDS_CAPS2_CUBEMAP_NEGATIVEX 0x800
#define DDS_CAPS2_CUBEMAP_POSITIVEY 0x1000
#define DDS_CAPS2_CUBEMAP_NEGATIVEY 0x2000
#define DDS_CAPS2_CUBEMAP_POSITIVEZ 0x4000
#define DDS_CAPS2_CUBEMAP_NEGATIVEZ 0x8000
#define DDS_CAPS2_CUBEMAP_ALL_FACES ( DDS_CAPS2_CUBEMAP_POSITIVEX | DDS_CAPS2_CUBEMAP_NEGATIVEX \
                                    | DDS_CAPS2_CUBEMAP_POSITIVEY | DDS_CAPS2_CUBEMAP_NEGATIVEY \
                                    | DDS_CAPS2_CUBEMAP_POSITIVEZ | DDS_CAPS2_CUBEMAP_NEGATIVEZ )
#define DDS_CAPS2_VOLUME 0x200000

/* dds_pixel_format.flags */
#define DDS_PF_ALPHA 0x1
#define DDS_PF_ALPHA_ONLY 0x2
#define DDS_PF_FOURCC 0x4
#define DDS_PF_RGB 0x40
#define DDS_PF_YUV 0x200
#define DDS_PF_LUMINANCE 0x20000
#define DDS_PF_BUMPLUMINANCE 0x40000
#define DDS_PF_BUMPDUDV 0x80000

struct dds_pixel_format
{
    DWORD size;
    DWORD flags;
    DWORD fourcc;
    DWORD bpp;
    DWORD rmask;
    DWORD gmask;
    DWORD bmask;
    DWORD amask;
};

struct dds_header
{
    DWORD signature;
    DWORD size;
    DWORD flags;
    DWORD height;
    DWORD width;
    DWORD pitch_or_linear_size;
    DWORD depth;
    DWORD miplevels;
    DWORD reserved[11];
    struct dds_pixel_format pixel_format;
    DWORD caps;
    DWORD caps2;
    DWORD caps3;
    DWORD caps4;
    DWORD reserved2;
};

static enum wined3d_format_id dds_fourcc_to_d3dformat(DWORD fourcc)
{
    unsigned int i;
    static const DWORD known_fourcc[] = {
        WINED3DFMT_UYVY,
        WINED3DFMT_YUY2,
        WINED3DFMT_R8G8_B8G8,
        WINED3DFMT_G8R8_G8B8,
        WINED3DFMT_DXT1,
        WINED3DFMT_DXT2,
        WINED3DFMT_DXT3,
        WINED3DFMT_DXT4,
        WINED3DFMT_DXT5,
        WINED3DFMT_R16_FLOAT,
        WINED3DFMT_R16G16_FLOAT,
        WINED3DFMT_R16G16B16A16_FLOAT,
        WINED3DFMT_R32_FLOAT,
        WINED3DFMT_R32G32_FLOAT,
        WINED3DFMT_R32G32B32A32_FLOAT,
    };

    for (i = 0; i < sizeof(known_fourcc) / sizeof(known_fourcc[0]); i++)
    {
        if (known_fourcc[i] == fourcc)
            return fourcc;
    }

    WARN("Unknown FourCC %#x\n", fourcc);
    return WINED3DFMT_UNKNOWN;
}

static const struct {
    DWORD bpp;
    DWORD rmask;
    DWORD gmask;
    DWORD bmask;
    DWORD amask;
    enum wined3d_format_id format;
} rgb_pixel_formats[] = {
    { 8, 0xe0, 0x1c, 0x03, 0, WINED3DFMT_B2G3R3_UNORM },
    { 16, 0xf800, 0x07e0, 0x001f, 0x0000, WINED3DFMT_B5G6R5_UNORM },
    { 16, 0x7c00, 0x03e0, 0x001f, 0x8000, WINED3DFMT_B5G5R5A1_UNORM },
    { 16, 0x7c00, 0x03e0, 0x001f, 0x0000, WINED3DFMT_B5G5R5X1_UNORM },
    { 16, 0x0f00, 0x00f0, 0x000f, 0xf000, WINED3DFMT_B4G4R4A4_UNORM },
    { 16, 0x0f00, 0x00f0, 0x000f, 0x0000, WINED3DFMT_B4G4R4X4_UNORM },
    { 16, 0x00e0, 0x001c, 0x0003, 0xff00, WINED3DFMT_B2G3R3A8_UNORM },
    { 24, 0xff0000, 0x00ff00, 0x0000ff, 0x000000, WINED3DFMT_B8G8R8_UNORM },
    { 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000, WINED3DFMT_B8G8R8A8_UNORM },
    { 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0x00000000, WINED3DFMT_B8G8R8X8_UNORM },
    { 32, 0x3ff00000, 0x000ffc00, 0x000003ff, 0xc0000000, WINED3DFMT_R10G10B10A2_UNORM },
    { 32, 0x000003ff, 0x000ffc00, 0x3ff00000, 0xc0000000, WINED3DFMT_B10G10R10A2_UNORM },
    { 32, 0x0000ffff, 0xffff0000, 0x00000000, 0x00000000, WINED3DFMT_R16G16_UNORM },
    { 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000, WINED3DFMT_R8G8B8A8_UNORM },
    { 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0x00000000, WINED3DFMT_R8G8B8X8_UNORM },
};

static enum wined3d_format_id dds_rgb_to_d3dformat(const struct dds_pixel_format *pixel_format)
{
    unsigned int i;

    for (i = 0; i < sizeof(rgb_pixel_formats) / sizeof(rgb_pixel_formats[0]); i++)
    {
        if (rgb_pixel_formats[i].bpp == pixel_format->bpp
            && rgb_pixel_formats[i].rmask == pixel_format->rmask
            && rgb_pixel_formats[i].gmask == pixel_format->gmask
            && rgb_pixel_formats[i].bmask == pixel_format->bmask)
        {
            if ((pixel_format->flags & DDS_PF_ALPHA) && rgb_pixel_formats[i].amask == pixel_format->amask)
                return rgb_pixel_formats[i].format;
            if (rgb_pixel_formats[i].amask == 0)
                return rgb_pixel_formats[i].format;
        }
    }

    WARN("Unknown RGB pixel format (%#x, %#x, %#x, %#x)\n",
        pixel_format->rmask, pixel_format->gmask, pixel_format->bmask, pixel_format->amask);
    return WINED3DFMT_UNKNOWN;
}

static enum wined3d_format_id dds_luminance_to_d3dformat(const struct dds_pixel_format *pixel_format)
{
    if (pixel_format->bpp == 8)
    {
        if (pixel_format->rmask == 0xff)
            return WINED3DFMT_L8_UNORM;
        if ((pixel_format->flags & DDS_PF_ALPHA) && pixel_format->rmask == 0x0f && pixel_format->amask == 0xf0)
            return WINED3DFMT_L4A4_UNORM;
    }
    if (pixel_format->bpp == 16)
    {
        if (pixel_format->rmask == 0xffff)
            return WINED3DFMT_L16_UNORM;
        if ((pixel_format->flags & DDS_PF_ALPHA) && pixel_format->rmask == 0x00ff && pixel_format->amask == 0xff00)
            return WINED3DFMT_L8A8_UNORM;
    }

    WARN("Unknown luminance pixel format (bpp %u, l %#x, a %#x)\n",
        pixel_format->bpp, pixel_format->rmask, pixel_format->amask);
    return WINED3DFMT_UNKNOWN;
}

static enum wined3d_format_id dds_alpha_to_d3dformat(const struct dds_pixel_format *pixel_format)
{
    if (pixel_format->bpp == 8 && pixel_format->amask == 0xff)
        return WINED3DFMT_A8_UNORM;

    WARN("Unknown Alpha pixel format (%u, %#x)\n", pixel_format->bpp, pixel_format->rmask);
    return WINED3DFMT_UNKNOWN;
}

static enum wined3d_format_id dds_bump_to_d3dformat(const struct dds_pixel_format *pixel_format)
{
    if (pixel_format->bpp == 16 && pixel_format->rmask == 0x00ff && pixel_format->gmask == 0xff00)
        return WINED3DFMT_R8G8_SNORM;
    if (pixel_format->bpp == 32 && pixel_format->rmask == 0x0000ffff && pixel_format->gmask == 0xffff0000)
        return WINED3DFMT_R16G16_SNORM;

    WARN("Unknown bump pixel format (%u, %#x, %#x, %#x, %#x)\n", pixel_format->bpp,
        pixel_format->rmask, pixel_format->gmask, pixel_format->bmask, pixel_format->amask);
    return WINED3DFMT_UNKNOWN;
}

static enum wined3d_format_id dds_bump_luminance_to_d3dformat(const struct dds_pixel_format *pixel_format)
{
    if (pixel_format->bpp == 32 && pixel_format->rmask == 0x000000ff && pixel_format->gmask == 0x0000ff00
            && pixel_format->bmask == 0x00ff0000)
        return WINED3DFMT_R8G8_SNORM_L8X8_UNORM;

    WARN("Unknown bump pixel format (%u, %#x, %#x, %#x, %#x)\n", pixel_format->bpp,
        pixel_format->rmask, pixel_format->gmask, pixel_format->bmask, pixel_format->amask);
    return WINED3DFMT_UNKNOWN;
}

static enum wined3d_format_id dds_pixel_format_to_d3dformat(const struct dds_pixel_format *pixel_format)
{
    TRACE("pixel_format: size %u, flags %#x, fourcc %#x, bpp %u.\n", pixel_format->size,
            pixel_format->flags, pixel_format->fourcc, pixel_format->bpp);
    TRACE("rmask %#x, gmask %#x, bmask %#x, amask %#x.\n", pixel_format->rmask, pixel_format->gmask,
            pixel_format->bmask, pixel_format->amask);

    if (pixel_format->flags & DDS_PF_FOURCC)
        return dds_fourcc_to_d3dformat(pixel_format->fourcc);
    if (pixel_format->flags & DDS_PF_RGB)
        return dds_rgb_to_d3dformat(pixel_format);
    if (pixel_format->flags & DDS_PF_LUMINANCE)
        return dds_luminance_to_d3dformat(pixel_format);
    if (pixel_format->flags & DDS_PF_ALPHA_ONLY)
        return dds_alpha_to_d3dformat(pixel_format);
    if (pixel_format->flags & DDS_PF_BUMPDUDV)
        return dds_bump_to_d3dformat(pixel_format);
    if (pixel_format->flags & DDS_PF_BUMPLUMINANCE)
        return dds_bump_luminance_to_d3dformat(pixel_format);

    WARN("Unknown pixel format (flags %#x, fourcc %#x, bpp %u, r %#x, g %#x, b %#x, a %#x)\n",
        pixel_format->flags, pixel_format->fourcc, pixel_format->bpp,
        pixel_format->rmask, pixel_format->gmask, pixel_format->bmask, pixel_format->amask);
    return WINED3DFMT_UNKNOWN;
}

static HRESULT calculate_dds_surface_size(enum wined3d_format_id format, UINT width, UINT height,
    UINT *pitch, UINT *size)
{
    const struct pixel_format_desc *format_desc = get_format_info(format);
    if (format_desc->type == FORMAT_UNKNOWN)
        return E_NOTIMPL;

    if (format_desc->block_width != 1 || format_desc->block_height != 1)
    {
        *pitch = format_desc->block_byte_count
            * max(1, (width + format_desc->block_width - 1) / format_desc->block_width);
        *size = *pitch
            * max(1, (height + format_desc->block_height - 1) / format_desc->block_height);
    }
    else
    {
        *pitch = width * format_desc->bytes_per_pixel;
        *size = *pitch * height;
    }

    return D3D_OK;
}

static UINT calculate_dds_file_size(enum wined3d_format_id format, UINT width, UINT height, UINT depth,
    UINT miplevels, UINT faces)
{
    UINT i, file_size = 0;

    for (i = 0; i < miplevels; i++)
    {
        UINT pitch, size = 0;
        calculate_dds_surface_size(format, width, height, &pitch, &size);
        size *= depth;
        file_size += size;
        width = max(1, width / 2);
        height = max(1, height / 2);
        depth = max(1, depth / 2);
    }

    file_size *= faces;
    file_size += sizeof(struct dds_header);
    return file_size;
}

/************************************************************
* get_image_info_from_dds
*
* Fills a D3DXIMAGE_INFO structure with information
* about a DDS file stored in the memory.
*
* PARAMS
*   buffer  [I] pointer to DDS data
*   length  [I] size of DDS data
*   info    [O] pointer to D3DXIMAGE_INFO structure
*
* RETURNS
*   Success: D3D_OK
*   Failure: D3DXERR_INVALIDDATA
*
*/
static HRESULT get_image_info_from_dds(const void *buffer, UINT length, D3DXIMAGE_INFO *info)
{
    UINT faces = 1;
    UINT expected_length;
    const struct dds_header *header = buffer;

    if (length < sizeof(*header) || !info)
        return D3DXERR_INVALIDDATA;

    if (header->pixel_format.size != sizeof(header->pixel_format))
        return D3DXERR_INVALIDDATA;

    info->Width = header->width;
    info->Height = header->height;
    info->Depth = 1;
    info->MipLevels = header->miplevels ? header->miplevels : 1;

    info->Format = dds_pixel_format_to_d3dformat(&header->pixel_format);
    if (info->Format == WINED3DFMT_UNKNOWN)
        return D3DXERR_INVALIDDATA;

    TRACE("Pixel format is %#x\n", info->Format);

    if (header->caps2 & DDS_CAPS2_VOLUME)
    {
        info->Depth = header->depth;
        info->ResourceType = D3DRTYPE_VOLUMETEXTURE;
    }
    else if (header->caps2 & DDS_CAPS2_CUBEMAP)
    {
        DWORD face;
        faces = 0;
        for (face = DDS_CAPS2_CUBEMAP_POSITIVEX; face <= DDS_CAPS2_CUBEMAP_NEGATIVEZ; face <<= 1)
        {
            if (header->caps2 & face)
                faces++;
        }
        info->ResourceType = D3DRTYPE_CUBETEXTURE;
    }
    else
    {
        info->ResourceType = D3DRTYPE_TEXTURE;
    }

    expected_length = calculate_dds_file_size(info->Format, info->Width, info->Height, info->Depth,
        info->MipLevels, faces);
    if (length < expected_length)
    {
        WARN("File is too short %u, expected at least %u bytes\n", length, expected_length);
        return D3DXERR_INVALIDDATA;
    }

    info->ImageFileFormat = D3DXIFF_DDS;
    return D3D_OK;
}

static BOOL convert_dib_to_bmp(void **data, UINT *size)
{
    ULONG header_size;
    ULONG count = 0;
    ULONG offset;
    BITMAPFILEHEADER *header;
    BYTE *new_data;
    UINT new_size;

    if ((*size < 4) || (*size < (header_size = *(ULONG*)*data)))
        return FALSE;

    if ((header_size == sizeof(BITMAPINFOHEADER)) ||
        (header_size == sizeof(BITMAPV4HEADER)) ||
        (header_size == sizeof(BITMAPV5HEADER)) ||
        (header_size == 64 /* sizeof(BITMAPCOREHEADER2) */))
    {
        /* All structures begin with the same memory layout as BITMAPINFOHEADER */
        BITMAPINFOHEADER *info_header = (BITMAPINFOHEADER*)*data;
        count = info_header->biClrUsed;

        if (!count && info_header->biBitCount <= 8)
            count = 1 << info_header->biBitCount;

        offset = sizeof(BITMAPFILEHEADER) + header_size + sizeof(RGBQUAD) * count;

        /* For BITMAPINFOHEADER with BI_BITFIELDS compression, there are 3 additional color masks after header */
        if ((info_header->biSize == sizeof(BITMAPINFOHEADER)) && (info_header->biCompression == BI_BITFIELDS))
            offset += 3 * sizeof(DWORD);
    }
    else if (header_size == sizeof(BITMAPCOREHEADER))
    {
        BITMAPCOREHEADER *core_header = (BITMAPCOREHEADER*)*data;

        if (core_header->bcBitCount <= 8)
            count = 1 << core_header->bcBitCount;

        offset = sizeof(BITMAPFILEHEADER) + header_size + sizeof(RGBTRIPLE) * count;
    }
    else
    {
        return FALSE;
    }

    TRACE("Converting DIB file to BMP\n");

    new_size = *size + sizeof(BITMAPFILEHEADER);
    new_data = HeapAlloc(GetProcessHeap(), 0, new_size);
    CopyMemory(new_data + sizeof(BITMAPFILEHEADER), *data, *size);

    /* Add BMP header */
    header = (BITMAPFILEHEADER*)new_data;
    header->bfType = 0x4d42; /* BM */
    header->bfSize = new_size;
    header->bfReserved1 = 0;
    header->bfReserved2 = 0;
    header->bfOffBits = offset;

    /* Update input data */
    *data = new_data;
    *size = new_size;

    return TRUE;
}

typedef BOOL (*wined3d_dxtn_conversion_func)(const BYTE *src, BYTE *dst, DWORD pitch_in, DWORD pitch_out,
                                     enum wined3d_format_id format, unsigned int w, unsigned int h);

static wined3d_dxtn_conversion_func wined3d_get_dxtn_conversion_func(enum wined3d_format_id format, BOOL encode)
{
    switch (format)
    {
        case WINED3DFMT_DXT1:
            if (!wined3d_dxtn_supported()) return NULL;
            return encode ? wined3d_dxt1_encode : wined3d_dxt1_decode;
        case WINED3DFMT_DXT3:
            if (!wined3d_dxtn_supported()) return NULL;
            return encode ? wined3d_dxt3_encode : wined3d_dxt3_decode;
        case WINED3DFMT_DXT5:
            if (!wined3d_dxtn_supported()) return NULL;
            return encode ? wined3d_dxt5_encode : wined3d_dxt5_decode;
        default:
            return NULL;
    }
}

/* Native d3dx9's D3DXFloat16to32Array lacks support for NaN and Inf. Specifically, e = 16 is treated as a
 * regular number - e.g., 0x7fff is converted to 131008.0 and 0xffff to -131008.0. */
float float_16_to_32(const unsigned short in)
{
    const unsigned short s = (in & 0x8000);
    const unsigned short e = (in & 0x7C00) >> 10;
    const unsigned short m = in & 0x3FF;
    const float sgn = (s ? -1.0f : 1.0f);

    if (e == 0)
    {
        if (m == 0) return sgn * 0.0f; /* +0.0 or -0.0 */
        else return sgn * powf(2, -14.0f) * (m / 1024.0f);
    }
    else
    {
        return sgn * powf(2, e - 15.0f) * (1.0f + (m / 1024.0f));
    }
}

unsigned short float_32_to_16(const float in)
{
    int exp = 0, origexp;
    float tmp = fabsf(in);
    int sign = (copysignf(1, in) < 0);
    unsigned int mantissa;
    unsigned short ret;

    /* Deal with special numbers */
    if (isinf(in)) return (sign ? 0xffff : 0x7fff);
    if (isnan(in)) return (sign ? 0xffff : 0x7fff);
    if (in == 0.0f) return (sign ? 0x8000 : 0x0000);

    if (tmp < (float)(1u << 10))
    {
        do
        {
            tmp *= 2.0f;
            exp--;
        } while (tmp < (float)(1u << 10));
    }
    else if (tmp >= (float)(1u << 11))
    {
        do
        {
            tmp /= 2.0f;
            exp++;
        } while (tmp >= (float)(1u << 11));
    }

    exp += 10;  /* Normalize the mantissa */
    exp += 15;  /* Exponent is encoded with excess 15 */

    origexp = exp;

    mantissa = (unsigned int) tmp;
    if ((tmp - mantissa == 0.5f && mantissa % 2 == 1) || /* round half to even */
        (tmp - mantissa > 0.5f))
    {
        mantissa++; /* round to nearest, away from zero */
    }
    if (mantissa == 2048)
    {
        mantissa = 1024;
        exp++;
    }

    if (exp > 31)
    {
        /* too big */
        ret = 0x7fff; /* INF */
    }
    else if (exp <= 0)
    {
        unsigned int rounding = 0;

        /* Denormalized half float */

        /* return 0x0000 (=0.0) for numbers too small to represent in half floats */
        if (exp < -11)
            return (sign ? 0x8000 : 0x0000);

        exp = origexp;

        /* the 13 extra bits from single precision are used for rounding */
        mantissa = (unsigned int)(tmp * (1u << 13));
        mantissa >>= 1 - exp; /* denormalize */

        mantissa -= ~(mantissa >> 13) & 1; /* round half to even */
        /* remove 13 least significant bits to get half float precision */
        mantissa >>= 12;
        rounding = mantissa & 1;
        mantissa >>= 1;

        ret = mantissa + rounding;
    }
    else
    {
        ret = (exp << 10) | (mantissa & 0x3ff);
    }

    ret |= ((sign ? 1 : 0) << 15); /* Add the sign */
    return ret;
}



struct argb_conversion_info
{
    const struct pixel_format_desc *srcformat;
    const struct pixel_format_desc *destformat;
    DWORD srcshift[4], destshift[4];
    DWORD srcmask[4], destmask[4];
    BOOL process_channel[4];
    DWORD channelmask;
};

static void init_argb_conversion_info(const struct pixel_format_desc *srcformat, const struct pixel_format_desc *destformat, struct argb_conversion_info *info)
{
    UINT i;
    ZeroMemory(info->process_channel, 4 * sizeof(BOOL));
    info->channelmask = 0;

    info->srcformat  =  srcformat;
    info->destformat = destformat;

    for(i = 0;i < 4;i++) {
        /* srcshift is used to extract the _relevant_ components */
        info->srcshift[i]  =  srcformat->shift[i] + max( srcformat->bits[i] - destformat->bits[i], 0);

        /* destshift is used to move the components to the correct position */
        info->destshift[i] = destformat->shift[i] + max(destformat->bits[i] -  srcformat->bits[i], 0);

        info->srcmask[i]  = ((1 <<  srcformat->bits[i]) - 1) <<  srcformat->shift[i];
        info->destmask[i] = ((1 << destformat->bits[i]) - 1) << destformat->shift[i];

        /* channelmask specifies bits which aren't used in the source format but in the destination one */
        if(destformat->bits[i]) {
            if(srcformat->bits[i]) info->process_channel[i] = TRUE;
            else info->channelmask |= info->destmask[i];
        }
    }
}

/************************************************************
 * get_relevant_argb_components
 *
 * Extracts the relevant components from the source color and
 * drops the less significant bits if they aren't used by the destination format.
 */
static void get_relevant_argb_components(const struct argb_conversion_info *info, const BYTE *col, DWORD *out)
{
    unsigned int i, j;
    unsigned int component, mask;

    for (i = 0; i < 4; ++i)
    {
        if (!info->process_channel[i])
            continue;

        component = 0;
        mask = info->srcmask[i];
        for (j = 0; j < 4 && mask; ++j)
        {
            if (info->srcshift[i] < j * 8)
                component |= (col[j] & mask) << (j * 8 - info->srcshift[i]);
            else
                component |= (col[j] & mask) >> (info->srcshift[i] - j * 8);
            mask >>= 8;
        }
        out[i] = component;
    }
}

/************************************************************
 * make_argb_color
 *
 * Recombines the output of get_relevant_argb_components and converts
 * it to the destination format.
 */
static DWORD make_argb_color(const struct argb_conversion_info *info, const DWORD *in)
{
    UINT i;
    DWORD val = 0;

    for(i = 0;i < 4;i++) {
        if(info->process_channel[i]) {
            /* necessary to make sure that e.g. an X4R4G4B4 white maps to an R8G8B8 white instead of 0xf0f0f0 */
            signed int shift;
            for(shift = info->destshift[i]; shift > info->destformat->shift[i]; shift -= info->srcformat->bits[i]) val |= in[i] << shift;
            val |= (in[i] >> (info->destformat->shift[i] - shift)) << info->destformat->shift[i];
        }
    }
    val |= info->channelmask;   /* new channels are set to their maximal value */
    return val;
}

/* It doesn't work for components bigger than 32 bits (or somewhat smaller but unaligned). */
static void format_to_vec4(const struct pixel_format_desc *format, const BYTE *src, struct vec4 *dst)
{
    DWORD mask, tmp;
    unsigned int c;

    for (c = 0; c < 4; ++c)
    {
        static const unsigned int component_offsets[4] = {3, 0, 1, 2};
        float *dst_component = (float *)dst + component_offsets[c];

        if (format->bits[c])
        {
            mask = ~0u >> (32 - format->bits[c]);

            memcpy(&tmp, src + format->shift[c] / 8,
                    min(sizeof(DWORD), (format->shift[c] % 8 + format->bits[c] + 7) / 8));

            if (format->type == FORMAT_ARGBF16)
                *dst_component = float_16_to_32(tmp);
            else if (format->type == FORMAT_ARGBF)
                *dst_component = *(float *)&tmp;
            else
                *dst_component = (float)((tmp >> format->shift[c] % 8) & mask) / mask;
        }
        else
            *dst_component = 1.0f;
    }
}

/* It doesn't work for components bigger than 32 bits. */
static void format_from_vec4(const struct pixel_format_desc *format, const struct vec4 *src, BYTE *dst)
{
    DWORD v, mask32;
    unsigned int c, i;

    memset(dst, 0, format->bytes_per_pixel);

    for (c = 0; c < 4; ++c)
    {
        static const unsigned int component_offsets[4] = {3, 0, 1, 2};
        const float src_component = *((const float *)src + component_offsets[c]);

        if (!format->bits[c])
            continue;

        mask32 = ~0u >> (32 - format->bits[c]);

        if (format->type == FORMAT_ARGBF16)
            v = float_32_to_16(src_component);
        else if (format->type == FORMAT_ARGBF)
            v = *(DWORD *)&src_component;
        else
            v = (DWORD)(src_component * ((1 << format->bits[c]) - 1) + 0.5f);

        for (i = format->shift[c] / 8 * 8; i < format->shift[c] + format->bits[c]; i += 8)
        {
            BYTE mask, byte;

            if (format->shift[c] > i)
            {
                mask = mask32 << (format->shift[c] - i);
                byte = (v << (format->shift[c] - i)) & mask;
            }
            else
            {
                mask = mask32 >> (i - format->shift[c]);
                byte = (v >> (i - format->shift[c])) & mask;
            }
            dst[i / 8] |= byte;
        }
    }
}

/************************************************************
 * copy_pixels
 *
 * Copies the source buffer to the destination buffer.
 * Works for any pixel format.
 * The source and the destination must be block-aligned.
 */
void copy_pixels(const BYTE *src, UINT src_row_pitch, UINT src_slice_pitch,
        BYTE *dst, UINT dst_row_pitch, UINT dst_slice_pitch, const struct volume *size,
        const struct pixel_format_desc *format)
{
    UINT row, slice;
    BYTE *dst_addr;
    const BYTE *src_addr;
    UINT row_block_count = (size->width + format->block_width - 1) / format->block_width;
    UINT row_count = (size->height + format->block_height - 1) / format->block_height;

    for (slice = 0; slice < size->depth; slice++)
    {
        src_addr = src + slice * src_slice_pitch;
        dst_addr = dst + slice * dst_slice_pitch;

        for (row = 0; row < row_count; row++)
        {
            memcpy(dst_addr, src_addr, row_block_count * format->block_byte_count);
            src_addr += src_row_pitch;
            dst_addr += dst_row_pitch;
        }
    }
}

/************************************************************
 * convert_argb_pixels
 *
 * Copies the source buffer to the destination buffer, performing
 * any necessary format conversion and color keying.
 * Pixels outsize the source rect are blacked out.
 */
void convert_argb_pixels(const BYTE *src, UINT src_row_pitch, UINT src_slice_pitch, const struct volume *src_size,
        const struct pixel_format_desc *src_format, BYTE *dst, UINT dst_row_pitch, UINT dst_slice_pitch,
        const struct volume *dst_size, const struct pixel_format_desc *dst_format, D3DCOLOR color_key,
        const PALETTEENTRY *palette)
{
    struct argb_conversion_info conv_info, ck_conv_info;
    const struct pixel_format_desc *ck_format = NULL;
    DWORD channels[4];
    UINT min_width, min_height, min_depth;
    UINT x, y, z;

    ZeroMemory(channels, sizeof(channels));
    init_argb_conversion_info(src_format, dst_format, &conv_info);

    min_width = min(src_size->width, dst_size->width);
    min_height = min(src_size->height, dst_size->height);
    min_depth = min(src_size->depth, dst_size->depth);

    if (color_key)
    {
        /* Color keys are always represented in WINED3DFMT_B8G8R8A8_UNORM format. */
        ck_format = get_format_info(WINED3DFMT_B8G8R8A8_UNORM);
        init_argb_conversion_info(src_format, ck_format, &ck_conv_info);
    }

    for (z = 0; z < min_depth; z++) {
        const BYTE *src_slice_ptr = src + z * src_slice_pitch;
        BYTE *dst_slice_ptr = dst + z * dst_slice_pitch;

        for (y = 0; y < min_height; y++) {
            const BYTE *src_ptr = src_slice_ptr + y * src_row_pitch;
            BYTE *dst_ptr = dst_slice_ptr + y * dst_row_pitch;

            for (x = 0; x < min_width; x++) {
                if (!src_format->to_rgba && !dst_format->from_rgba
                        && src_format->type == dst_format->type
                        && src_format->bytes_per_pixel <= 4 && dst_format->bytes_per_pixel <= 4)
                {
                    DWORD val;

                    get_relevant_argb_components(&conv_info, src_ptr, channels);
                    val = make_argb_color(&conv_info, channels);

                    if (color_key)
                    {
                        DWORD ck_pixel;

                        get_relevant_argb_components(&ck_conv_info, src_ptr, channels);
                        ck_pixel = make_argb_color(&ck_conv_info, channels);
                        if (ck_pixel == color_key)
                            val &= ~conv_info.destmask[0];
                    }
                    memcpy(dst_ptr, &val, dst_format->bytes_per_pixel);
                }
                else
                {
                    struct vec4 color, tmp;

                    format_to_vec4(src_format, src_ptr, &color);
                    if (src_format->to_rgba)
                        src_format->to_rgba(&color, &tmp, palette);
                    else
                        tmp = color;

                    if (ck_format)
                    {
                        DWORD ck_pixel;

                        format_from_vec4(ck_format, &tmp, (BYTE *)&ck_pixel);
                        if (ck_pixel == color_key)
                            tmp.w = 0.0f;
                    }

                    if (dst_format->from_rgba)
                        dst_format->from_rgba(&tmp, &color);
                    else
                        color = tmp;

                    format_from_vec4(dst_format, &color, dst_ptr);
                }

                src_ptr += src_format->bytes_per_pixel;
                dst_ptr += dst_format->bytes_per_pixel;
            }

            if (src_size->width < dst_size->width) /* black out remaining pixels */
                memset(dst_ptr, 0, dst_format->bytes_per_pixel * (dst_size->width - src_size->width));
        }

        if (src_size->height < dst_size->height) /* black out remaining pixels */
            memset(dst + src_size->height * dst_row_pitch, 0, dst_row_pitch * (dst_size->height - src_size->height));
    }
    if (src_size->depth < dst_size->depth) /* black out remaining pixels */
        memset(dst + src_size->depth * dst_slice_pitch, 0, dst_slice_pitch * (dst_size->depth - src_size->depth));
}

static HRESULT wined3d_convert_memory_to_rgba(int width, int height, const void *src_memory, void *dst_memory,
        enum wined3d_format_id src_format, UINT src_pitch, const PALETTEENTRY *src_palette, D3DCOLOR color_key)
{
    const struct pixel_format_desc *srcformatdesc, *destformatdesc;
    struct volume size;
    HRESULT ret = D3D_OK;
    wined3d_dxtn_conversion_func pre_convert;
    void *tmp_src_memory = NULL;
    UINT tmp_src_pitch;

    TRACE("(width=%d, height=%d, src_memory=%p, src_format=%#x, src_pitch=%u, src_paleette=%p, color_key=0x%08x)\n",
            width, height, src_memory, src_format, src_pitch, src_palette, color_key);

    if (!src_memory)
    {
        WARN("Invalid argument specified.\n");
        return D3DERR_INVALIDCALL;
    }
    if (src_format == WINED3DFMT_UNKNOWN)
    {
        WARN("Invalid src_format\n");
        return E_FAIL;
    }

    size.depth = 1;
    size.width = width;
    size.height = height;


    srcformatdesc = get_format_info(src_format);
    destformatdesc = get_format_info(WINED3DFMT_R8G8B8A8_UNORM);

    if (srcformatdesc->type == FORMAT_UNKNOWN)
    {
        FIXME("Unsupported pixel format conversion %#x -> %#x\n", src_format, WINED3DFMT_R8G8B8A8_UNORM);
        return E_NOTIMPL;
    }

    pre_convert  = wined3d_get_dxtn_conversion_func(srcformatdesc->format, FALSE);

    if (!pre_convert && (srcformatdesc->type != FORMAT_ARGB) && (srcformatdesc->type != FORMAT_INDEX))
    {
        FIXME("Format conversion missing %#x -> %#x\n", src_format, WINED3DFMT_R8G8B8A8_UNORM);
        return E_NOTIMPL;
    }

    /* handle pre-conversion */
    if (pre_convert)
    {
        tmp_src_memory = HeapAlloc(GetProcessHeap(), 0, width * height * sizeof(DWORD));
        if (!tmp_src_memory)
        {
            ret = E_OUTOFMEMORY;
            goto error;
        }
        tmp_src_pitch = width * sizeof(DWORD);
        if (!pre_convert(src_memory, tmp_src_memory, src_pitch, tmp_src_pitch,
                WINED3DFMT_B8G8R8A8_UNORM, width, height))
        {
            ret = E_FAIL;
            goto error;
        }
        srcformatdesc = get_format_info(WINED3DFMT_B8G8R8A8_UNORM);
    }
    else
    {
        tmp_src_memory = (void *)src_memory;
        tmp_src_pitch  = src_pitch;
    }

    convert_argb_pixels(tmp_src_memory, tmp_src_pitch, 0, &size, srcformatdesc,
            dst_memory, width * 4, 0, &size, destformatdesc, color_key, src_palette);


error:
    if (pre_convert)
        HeapFree(GetProcessHeap(), 0, tmp_src_memory);

    return ret;
}


HRESULT wined3d_get_imageinfo_from_file_in_memory(const void *data, UINT datasize, D3DXIMAGE_INFO *info)
{
    IWICImagingFactory *factory;
    IWICBitmapDecoder *decoder = NULL;
    IWICStream *stream;
    HRESULT hr;
    HRESULT initresult;
    BOOL dib;

    TRACE("(%p, %d, %p)\n", data, datasize, info);

    if (!data || !datasize)
        return D3DERR_INVALIDCALL;

    if (!info)
        return D3D_OK;

    if ((datasize >= 4) && !strncmp(data, "DDS ", 4)) {
        TRACE("File type is DDS\n");
        return get_image_info_from_dds(data, datasize, info);
    }

    /* In case of DIB file, convert it to BMP */
    dib = convert_dib_to_bmp((void**)&data, &datasize);

    initresult = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    hr = CoCreateInstance(&CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, &IID_IWICImagingFactory, (void**)&factory);

    if (SUCCEEDED(hr)) {
        IWICImagingFactory_CreateStream(factory, &stream);
        IWICStream_InitializeFromMemory(stream, (BYTE*)data, datasize);
        hr = IWICImagingFactory_CreateDecoderFromStream(factory, (IStream*)stream, NULL, 0, &decoder);
        IWICStream_Release(stream);
        IWICImagingFactory_Release(factory);
    }

    if (FAILED(hr)) {
        if ((datasize >= 2) && (!strncmp(data, "P3", 2) || !strncmp(data, "P6", 2)))
            FIXME("File type PPM is not supported yet\n");
        else if ((datasize >= 10) && !strncmp(data, "#?RADIANCE", 10))
            FIXME("File type HDR is not supported yet\n");
        else if ((datasize >= 2) && (!strncmp(data, "PF", 2) || !strncmp(data, "Pf", 2)))
            FIXME("File type PFM is not supported yet\n");
    }

    if (SUCCEEDED(hr)) {
        GUID container_format;
        UINT frame_count;

        hr = IWICBitmapDecoder_GetContainerFormat(decoder, &container_format);
        if (SUCCEEDED(hr)) {
            if (IsEqualGUID(&container_format, &GUID_ContainerFormatBmp)) {
                if (dib) {
                    TRACE("File type is DIB\n");
                    info->ImageFileFormat = D3DXIFF_DIB;
                } else {
                    TRACE("File type is BMP\n");
                    info->ImageFileFormat = D3DXIFF_BMP;
                }
            } else if (IsEqualGUID(&container_format, &GUID_ContainerFormatPng)) {
                TRACE("File type is PNG\n");
                info->ImageFileFormat = D3DXIFF_PNG;
            } else if(IsEqualGUID(&container_format, &GUID_ContainerFormatJpeg)) {
                TRACE("File type is JPG\n");
                info->ImageFileFormat = D3DXIFF_JPG;
            } else if(IsEqualGUID(&container_format, &GUID_WineContainerFormatTga)) {
                TRACE("File type is TGA\n");
                info->ImageFileFormat = D3DXIFF_TGA;
            } else {
                WARN("Unsupported image file format %s\n", debugstr_guid(&container_format));
                hr = D3DXERR_INVALIDDATA;
            }
        }

        if (SUCCEEDED(hr))
            hr = IWICBitmapDecoder_GetFrameCount(decoder, &frame_count);
        if (SUCCEEDED(hr) && !frame_count)
            hr = D3DXERR_INVALIDDATA;

        if (SUCCEEDED(hr)) {
            IWICBitmapFrameDecode *frame = NULL;

            hr = IWICBitmapDecoder_GetFrame(decoder, 0, &frame);

            if (SUCCEEDED(hr))
                hr = IWICBitmapFrameDecode_GetSize(frame, &info->Width, &info->Height);

            if (SUCCEEDED(hr)) {
                WICPixelFormatGUID pixel_format;

                hr = IWICBitmapFrameDecode_GetPixelFormat(frame, &pixel_format);
                if (SUCCEEDED(hr)) {
                    info->Format = wic_guid_to_d3dformat(&pixel_format);
                    if (info->Format == WINED3DFMT_UNKNOWN) {
                        WARN("Unsupported pixel format %s\n", debugstr_guid(&pixel_format));
                        hr = D3DXERR_INVALIDDATA;
                    }
                }
            }

            if (frame)
                 IWICBitmapFrameDecode_Release(frame);

            info->Depth = 1;
            info->MipLevels = 1;
            info->ResourceType = D3DRTYPE_TEXTURE;
        }
    }

    if (decoder)
        IWICBitmapDecoder_Release(decoder);

    if (SUCCEEDED(initresult))
        CoUninitialize();

    if (dib)
        HeapFree(GetProcessHeap(), 0, (void*)data);

    if (FAILED(hr)) {
        TRACE("Invalid or unsupported image file\n");
        return D3DXERR_INVALIDDATA;
    }

    return D3D_OK;
}

static HRESULT load_surface_from_dds(const void *src_data, void *dst_data, D3DCOLOR color_key, const D3DXIMAGE_INFO *src_info)
{
    UINT size;
    UINT src_pitch;
    const struct dds_header *header = src_data;
    const BYTE *pixels = (BYTE *)(header + 1);

    if (src_info->ResourceType != D3DRTYPE_TEXTURE)
        return D3DXERR_INVALIDDATA;

    if (FAILED(calculate_dds_surface_size(src_info->Format, src_info->Width, src_info->Height, &src_pitch, &size)))
        return E_NOTIMPL;

    return wined3d_convert_memory_to_rgba(src_info->Width, src_info->Height, pixels, dst_data, src_info->Format,
        src_pitch, NULL, color_key);
}

HRESULT CDECL wined3d_load_imagedata_from_file_in_memory (const void *pSrcData, UINT SrcDataSize, void **pDstData, DWORD Colorkey, UINT *width, UINT *height)
{
    D3DXIMAGE_INFO imginfo;
    HRESULT hr, com_init;

    IWICImagingFactory *factory = NULL;
    IWICBitmapDecoder *decoder;
    IWICBitmapFrameDecode *bitmapframe;
    IWICStream *stream;

    const struct pixel_format_desc *formatdesc;
    WICRect wicrect;

    TRACE("src_data %p, src_data_size %u, color_key 0x%08x, width %p, height %p.\n",
            pSrcData, SrcDataSize, Colorkey, width, height);

    if (!pSrcData || !SrcDataSize || !pDstData || !width || !height)
        return D3DERR_INVALIDCALL;

    hr = wined3d_get_imageinfo_from_file_in_memory(pSrcData, SrcDataSize, &imginfo);

    if (FAILED(hr))
        return hr;

    wicrect.X = 0;
    wicrect.Y = 0;
    wicrect.Width = imginfo.Width;
    wicrect.Height = imginfo.Height;

    *width = imginfo.Width;
    *height = imginfo.Height;

    *pDstData = HeapAlloc(GetProcessHeap(), 0, imginfo.Width * imginfo.Height * 4);

    if (imginfo.ImageFileFormat == D3DXIFF_DDS)
    {
        hr = load_surface_from_dds(pSrcData, *pDstData, Colorkey, &imginfo);
        if (FAILED(hr))
        {
            HeapFree(GetProcessHeap(), 0, *pDstData);
            *pDstData = NULL;
        }
        return hr;
    }

    if (imginfo.ImageFileFormat == D3DXIFF_DIB)
        convert_dib_to_bmp((void**)&pSrcData, &SrcDataSize);

    com_init = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    if (FAILED(CoCreateInstance(&CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, &IID_IWICImagingFactory, (void**)&factory)))
        goto cleanup_err;

    if (FAILED(IWICImagingFactory_CreateStream(factory, &stream)))
    {
        IWICImagingFactory_Release(factory);
        factory = NULL;
        goto cleanup_err;
    }

    IWICStream_InitializeFromMemory(stream, (BYTE*)pSrcData, SrcDataSize);

    hr = IWICImagingFactory_CreateDecoderFromStream(factory, (IStream*)stream, NULL, 0, &decoder);

    IWICStream_Release(stream);

    if (FAILED(hr))
        goto cleanup_err;

    hr = IWICBitmapDecoder_GetFrame(decoder, 0, &bitmapframe);

    if (FAILED(hr))
        goto cleanup_bmp;

    formatdesc = get_format_info(imginfo.Format);

    if (formatdesc->type == FORMAT_UNKNOWN)
    {
        FIXME("Unsupported pixel format\n");
        hr = D3DXERR_INVALIDDATA;
    }
    else
    {
        BYTE *buffer;
        DWORD pitch;
        PALETTEENTRY *palette = NULL;
        WICColor *colors = NULL;

        pitch = formatdesc->bytes_per_pixel * wicrect.Width;
        buffer = HeapAlloc(GetProcessHeap(), 0, pitch * wicrect.Height);

        hr = IWICBitmapFrameDecode_CopyPixels(bitmapframe, &wicrect, pitch,
                                              pitch * wicrect.Height, buffer);

        if (SUCCEEDED(hr) && (formatdesc->type == FORMAT_INDEX))
        {
            IWICPalette *wic_palette = NULL;
            UINT nb_colors;

            hr = IWICImagingFactory_CreatePalette(factory, &wic_palette);
            if (SUCCEEDED(hr))
                hr = IWICBitmapFrameDecode_CopyPalette(bitmapframe, wic_palette);
            if (SUCCEEDED(hr))
                hr = IWICPalette_GetColorCount(wic_palette, &nb_colors);
            if (SUCCEEDED(hr))
            {
                colors = HeapAlloc(GetProcessHeap(), 0, nb_colors * sizeof(colors[0]));
                palette = HeapAlloc(GetProcessHeap(), 0, nb_colors * sizeof(palette[0]));
                if (!colors || !palette)
                    hr = E_OUTOFMEMORY;
            }
            if (SUCCEEDED(hr))
                hr = IWICPalette_GetColors(wic_palette, nb_colors, colors, &nb_colors);
            if (SUCCEEDED(hr))
            {
                UINT i;

                /* Convert colors from WICColor (ARGB) to PALETTEENTRY (ABGR) */
                for (i = 0; i < nb_colors; i++)
                {
                    palette[i].peRed   = (colors[i] >> 16) & 0xff;
                    palette[i].peGreen = (colors[i] >> 8) & 0xff;
                    palette[i].peBlue  = colors[i] & 0xff;
                    palette[i].peFlags = (colors[i] >> 24) & 0xff; /* peFlags is the alpha component in DX8 and higher */
                }
            }
            if (wic_palette)
                IWICPalette_Release(wic_palette);
        }

        if (SUCCEEDED(hr))
        {
            hr = wined3d_convert_memory_to_rgba(wicrect.Width, wicrect.Height, buffer, *pDstData, imginfo.Format, pitch,
                                           palette, Colorkey);
        }

        HeapFree(GetProcessHeap(), 0, colors);
        HeapFree(GetProcessHeap(), 0, palette);
        HeapFree(GetProcessHeap(), 0, buffer);
    }

    IWICBitmapFrameDecode_Release(bitmapframe);

cleanup_bmp:
    IWICBitmapDecoder_Release(decoder);

cleanup_err:
    if (factory)
        IWICImagingFactory_Release(factory);

    if (SUCCEEDED(com_init))
        CoUninitialize();

    if (imginfo.ImageFileFormat == D3DXIFF_DIB)
        HeapFree(GetProcessHeap(), 0, (void*)pSrcData);

    if (FAILED(hr))
    {
        HeapFree(GetProcessHeap(), 0, *pDstData);
        *pDstData = NULL;
        return D3DXERR_INVALIDDATA;
    }

    return D3D_OK;
}

HRESULT CDECL wined3d_map_view_of_file(const WCHAR *filename, void **buffer, DWORD *length)
{
    HANDLE hfile, hmapping = NULL;

    hfile = CreateFileW(filename, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, 0, 0);
    if(hfile == INVALID_HANDLE_VALUE) goto error;

    *length = GetFileSize(hfile, NULL);
    if(*length == INVALID_FILE_SIZE) goto error;

    hmapping = CreateFileMappingW(hfile, NULL, PAGE_READONLY, 0, 0, NULL);
    if(!hmapping) goto error;

    *buffer = MapViewOfFile(hmapping, FILE_MAP_READ, 0, 0, 0);
    if(*buffer == NULL) goto error;

    CloseHandle(hmapping);
    CloseHandle(hfile);

    return S_OK;

error:
    CloseHandle(hmapping);
    CloseHandle(hfile);
    return HRESULT_FROM_WIN32(GetLastError());
}
