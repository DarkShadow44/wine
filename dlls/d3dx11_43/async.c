/*
 * Copyright 2016 Matteo Bruni for CodeWeavers
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

#include "config.h"
#include "wine/port.h"
#include "d3dx11.h"
#include "d3dcompiler.h"

#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(d3dx);

HRESULT WINAPI D3DX11CompileFromMemory(const char *data, SIZE_T data_size, const char *filename,
        const D3D10_SHADER_MACRO *defines, ID3D10Include *include, const char *entry_point,
        const char *target, UINT sflags, UINT eflags, ID3DX11ThreadPump *pump, ID3D10Blob **shader,
        ID3D10Blob **error_messages, HRESULT *hresult)
{
    TRACE("data %s, data_size %lu, filename %s, defines %p, include %p, entry_point %s, target %s, "
            "sflags %#x, eflags %#x, pump %p, shader %p, error_messages %p, hresult %p.\n",
            debugstr_a(data), data_size, debugstr_a(filename), defines, include, debugstr_a(entry_point),
            debugstr_a(target), sflags, eflags, pump, shader, error_messages, hresult);

    if (pump)
        FIXME("Unimplemented ID3DX11ThreadPump handling.\n");

    return D3DCompile(data, data_size, filename, defines, include, entry_point, target,
            sflags, eflags, shader, error_messages);
}

HRESULT WINAPI D3DX11CompileFromFileA(const char *filename, const D3D10_SHADER_MACRO *defines,
        ID3D10Include *include, const char *entry_point, const char *target, UINT sflags, UINT eflags,
        ID3DX11ThreadPump *pump, ID3D10Blob **shader, ID3D10Blob **error_messages, HRESULT *hresult)
{
    FIXME("filename %s, defines %p, include %p, entry_point %s, target %s, sflags %#x, "
            "eflags %#x, pump %p, shader %p, error_messages %p, hresult %p stub.\n",
            debugstr_a(filename), defines, include, debugstr_a(entry_point), debugstr_a(target),
            sflags, eflags, pump, shader, error_messages, hresult);

    return E_NOTIMPL;
}

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

HRESULT WINAPI D3DX11CompileFromFileW(const WCHAR *filename, const D3D10_SHADER_MACRO *defines,
        ID3D10Include *include, const char *entry_point, const char *target, UINT sflags, UINT eflags,
        ID3DX11ThreadPump *pump, ID3D10Blob **shader, ID3D10Blob **error_messages, HRESULT *hresult)
{
    void *buffer;
    HRESULT ret;
    DWORD size;

    ret = map_view_of_file(filename, &buffer, &size);

    if (FAILED(ret))
        return E_FAIL;

    //!!!fix path, convert to char*
    //!!!add trace
    ret = D3DX11CompileFromMemory(buffer, size, NULL, defines, include, entry_point, target,
            sflags, eflags, pump, shader, error_messages, hresult);

    UnmapViewOfFile(buffer);

    return S_OK;
}

HRESULT WINAPI D3DX11CreateTextureFromMemory(ID3D11Device *device, const void *data,
        SIZE_T data_size, D3DX11_IMAGE_LOAD_INFO *load_info, ID3DX11ThreadPump *pump,
        ID3D11Resource **texture, HRESULT *hresult)
{
    FIXME("device %p, data %p, data_size %lu, load_info %p, pump %p, texture %p, hresult %p stub.\n",
            device, data, data_size, load_info, pump, texture, hresult);

    return E_NOTIMPL;
}

#ifndef MAKEFOURCC
#define MAKEFOURCC(ch0, ch1, ch2, ch3)  \
    ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |  \
    ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))
#endif

typedef enum _D3DFORMAT {
    D3DFMT_UNKNOWN              =   0,

    D3DFMT_R8G8B8               =  20,
    D3DFMT_A8R8G8B8             =  21,
    D3DFMT_X8R8G8B8             =  22,
    D3DFMT_R5G6B5               =  23,
    D3DFMT_X1R5G5B5             =  24,
    D3DFMT_A1R5G5B5             =  25,
    D3DFMT_A4R4G4B4             =  26,
    D3DFMT_R3G3B2               =  27,
    D3DFMT_A8                   =  28,
    D3DFMT_A8R3G3B2             =  29,
    D3DFMT_X4R4G4B4             =  30,
    D3DFMT_A2B10G10R10          =  31,
    D3DFMT_A8B8G8R8             =  32,
    D3DFMT_X8B8G8R8             =  33,
    D3DFMT_G16R16               =  34,
    D3DFMT_A2R10G10B10          =  35,
    D3DFMT_A16B16G16R16         =  36,


    D3DFMT_A8P8                 =  40,
    D3DFMT_P8                   =  41,

    D3DFMT_L8                   =  50,
    D3DFMT_A8L8                 =  51,
    D3DFMT_A4L4                 =  52,

    D3DFMT_V8U8                 =  60,
    D3DFMT_L6V5U5               =  61,
    D3DFMT_X8L8V8U8             =  62,
    D3DFMT_Q8W8V8U8             =  63,
    D3DFMT_V16U16               =  64,
    D3DFMT_A2W10V10U10          =  67,

    D3DFMT_UYVY                 =  MAKEFOURCC('U', 'Y', 'V', 'Y'),
    D3DFMT_YUY2                 =  MAKEFOURCC('Y', 'U', 'Y', '2'),
    D3DFMT_DXT1                 =  MAKEFOURCC('D', 'X', 'T', '1'),
    D3DFMT_DXT2                 =  MAKEFOURCC('D', 'X', 'T', '2'),
    D3DFMT_DXT3                 =  MAKEFOURCC('D', 'X', 'T', '3'),
    D3DFMT_DXT4                 =  MAKEFOURCC('D', 'X', 'T', '4'),
    D3DFMT_DXT5                 =  MAKEFOURCC('D', 'X', 'T', '5'),
    D3DFMT_MULTI2_ARGB8         =  MAKEFOURCC('M', 'E', 'T', '1'),
    D3DFMT_G8R8_G8B8            =  MAKEFOURCC('G', 'R', 'G', 'B'),
    D3DFMT_R8G8_B8G8            =  MAKEFOURCC('R', 'G', 'B', 'G'),

    D3DFMT_D16_LOCKABLE         =  70,
    D3DFMT_D32                  =  71,
    D3DFMT_D15S1                =  73,
    D3DFMT_D24S8                =  75,
    D3DFMT_D24X8                =  77,
    D3DFMT_D24X4S4              =  79,
    D3DFMT_D16                  =  80,
    D3DFMT_L16                  =  81,
    D3DFMT_D32F_LOCKABLE        =  82,
    D3DFMT_D24FS8               =  83,

    D3DFMT_VERTEXDATA           = 100,
    D3DFMT_INDEX16              = 101,
    D3DFMT_INDEX32              = 102,
    D3DFMT_Q16W16V16U16         = 110,
    /* Floating point formats */
    D3DFMT_R16F                 = 111,
    D3DFMT_G16R16F              = 112,
    D3DFMT_A16B16G16R16F        = 113,

    /* IEEE formats */
    D3DFMT_R32F                 = 114,
    D3DFMT_G32R32F              = 115,
    D3DFMT_A32B32G32R32F        = 116,

    D3DFMT_CxV8U8               = 117,


    D3DFMT_FORCE_DWORD          = 0xFFFFFFFF
} D3DFORMAT;

struct vec4
{
    float x, y, z, w;
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
    D3DFORMAT format;
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

static const struct pixel_format_desc formats[] =
{
    /* format              bpc               shifts             bpp blocks   type            from_rgba     to_rgba */
    {D3DFMT_R8G8B8,        { 0,  8,  8,  8}, { 0, 16,  8,  0},  3, 1, 1,  3, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_A8R8G8B8,      { 8,  8,  8,  8}, {24, 16,  8,  0},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_X8R8G8B8,      { 0,  8,  8,  8}, { 0, 16,  8,  0},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_A8B8G8R8,      { 8,  8,  8,  8}, {24,  0,  8, 16},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_X8B8G8R8,      { 0,  8,  8,  8}, { 0,  0,  8, 16},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_R5G6B5,        { 0,  5,  6,  5}, { 0, 11,  5,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_X1R5G5B5,      { 0,  5,  5,  5}, { 0, 10,  5,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_A1R5G5B5,      { 1,  5,  5,  5}, {15, 10,  5,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_R3G3B2,        { 0,  3,  3,  2}, { 0,  5,  2,  0},  1, 1, 1,  1, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_A8R3G3B2,      { 8,  3,  3,  2}, { 8,  5,  2,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_A4R4G4B4,      { 4,  4,  4,  4}, {12,  8,  4,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_X4R4G4B4,      { 0,  4,  4,  4}, { 0,  8,  4,  0},  2, 1, 1,  2, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_A2R10G10B10,   { 2, 10, 10, 10}, {30, 20, 10,  0},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_A2B10G10R10,   { 2, 10, 10, 10}, {30,  0, 10, 20},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_A16B16G16R16,  {16, 16, 16, 16}, {48,  0, 16, 32},  8, 1, 1,  8, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_G16R16,        { 0, 16, 16,  0}, { 0,  0, 16,  0},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_A8,            { 8,  0,  0,  0}, { 0,  0,  0,  0},  1, 1, 1,  1, FORMAT_ARGB,    NULL,         NULL      },
    {D3DFMT_A8L8,          { 8,  8,  0,  0}, { 8,  0,  0,  0},  2, 1, 1,  2, FORMAT_ARGB,    la_from_rgba, la_to_rgba},
    {D3DFMT_A4L4,          { 4,  4,  0,  0}, { 4,  0,  0,  0},  1, 1, 1,  1, FORMAT_ARGB,    la_from_rgba, la_to_rgba},
    {D3DFMT_L8,            { 0,  8,  0,  0}, { 0,  0,  0,  0},  1, 1, 1,  1, FORMAT_ARGB,    la_from_rgba, la_to_rgba},
    {D3DFMT_L16,           { 0, 16,  0,  0}, { 0,  0,  0,  0},  2, 1, 1,  2, FORMAT_ARGB,    la_from_rgba, la_to_rgba},
    {D3DFMT_DXT1,          { 0,  0,  0,  0}, { 0,  0,  0,  0},  1, 4, 4,  8, FORMAT_DXT,     NULL,         NULL      },
    {D3DFMT_DXT2,          { 0,  0,  0,  0}, { 0,  0,  0,  0},  1, 4, 4, 16, FORMAT_DXT,     NULL,         NULL      },
    {D3DFMT_DXT3,          { 0,  0,  0,  0}, { 0,  0,  0,  0},  1, 4, 4, 16, FORMAT_DXT,     NULL,         NULL      },
    {D3DFMT_DXT4,          { 0,  0,  0,  0}, { 0,  0,  0,  0},  1, 4, 4, 16, FORMAT_DXT,     NULL,         NULL      },
    {D3DFMT_DXT5,          { 0,  0,  0,  0}, { 0,  0,  0,  0},  1, 4, 4, 16, FORMAT_DXT,     NULL,         NULL      },
    {D3DFMT_R16F,          { 0, 16,  0,  0}, { 0,  0,  0,  0},  2, 1, 1,  2, FORMAT_ARGBF16, NULL,         NULL      },
    {D3DFMT_G16R16F,       { 0, 16, 16,  0}, { 0,  0, 16,  0},  4, 1, 1,  4, FORMAT_ARGBF16, NULL,         NULL      },
    {D3DFMT_A16B16G16R16F, {16, 16, 16, 16}, {48,  0, 16, 32},  8, 1, 1,  8, FORMAT_ARGBF16, NULL,         NULL      },
    {D3DFMT_R32F,          { 0, 32,  0,  0}, { 0,  0,  0,  0},  4, 1, 1,  4, FORMAT_ARGBF,   NULL,         NULL      },
    {D3DFMT_G32R32F,       { 0, 32, 32,  0}, { 0,  0, 32,  0},  8, 1, 1,  8, FORMAT_ARGBF,   NULL,         NULL      },
    {D3DFMT_A32B32G32R32F, {32, 32, 32, 32}, {96,  0, 32, 64}, 16, 1, 1, 16, FORMAT_ARGBF,   NULL,         NULL      },
    {D3DFMT_P8,            { 8,  8,  8,  8}, { 0,  0,  0,  0},  1, 1, 1,  1, FORMAT_INDEX,   NULL,         index_to_rgba},
    {D3DFMT_X8L8V8U8,      { 0,  8,  8,  8}, { 0,  0,  8, 16},  4, 1, 1,  4, FORMAT_ARGB,    NULL,         NULL      },
    /* marks last element */
    {D3DFMT_UNKNOWN,       { 0,  0,  0,  0}, { 0,  0,  0,  0},  0, 1, 1,  0, FORMAT_UNKNOWN, NULL,         NULL      },
};

typedef DWORD D3DCOLOR;

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

struct argb_conversion_info
{
    const struct pixel_format_desc *srcformat;
    const struct pixel_format_desc *destformat;
    DWORD srcshift[4], destshift[4];
    DWORD srcmask[4], destmask[4];
    BOOL process_channel[4];
    DWORD channelmask;
};

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

const struct pixel_format_desc *get_format_info(D3DFORMAT format)
{
    unsigned int i = 0;
    while(formats[i].format != format && formats[i].format != D3DFMT_UNKNOWN) i++;
    if (formats[i].format == D3DFMT_UNKNOWN)
        FIXME("Unknown format %#x (as FOURCC %s).\n", format, debugstr_an((const char *)&format, 4));
    return &formats[i];
}

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

struct volume
{
    UINT width;
    UINT height;
    UINT depth;
};

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
        /* Color keys are always represented in D3DFMT_A8R8G8B8 format. */
        ck_format = get_format_info(D3DFMT_A8R8G8B8);
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



static HRESULT calculate_dds_surface_size(D3DFORMAT format, UINT width, UINT height,
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

    return 0;
}

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

typedef struct _D3DXIMAGE_INFO
{
    UINT Width;
    UINT Height;
    UINT Depth;
    UINT MipLevels;
    D3DFORMAT Format;
    D3DRESOURCETYPE ResourceType;
    D3DXIMAGE_FILEFORMAT ImageFileFormat;
} D3DXIMAGE_INFO;

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

static D3DFORMAT dds_fourcc_to_d3dformat(DWORD fourcc)
{
    unsigned int i;
    static const DWORD known_fourcc[] = {
        D3DFMT_UYVY,
        D3DFMT_YUY2,
        D3DFMT_R8G8_B8G8,
        D3DFMT_G8R8_G8B8,
        D3DFMT_DXT1,
        D3DFMT_DXT2,
        D3DFMT_DXT3,
        D3DFMT_DXT4,
        D3DFMT_DXT5,
        D3DFMT_R16F,
        D3DFMT_G16R16F,
        D3DFMT_A16B16G16R16F,
        D3DFMT_R32F,
        D3DFMT_G32R32F,
        D3DFMT_A32B32G32R32F,
    };

    for (i = 0; i < sizeof(known_fourcc) / sizeof(known_fourcc[0]); i++)
    {
        if (known_fourcc[i] == fourcc)
            return fourcc;
    }

    WARN("Unknown FourCC %#x\n", fourcc);
    return D3DFMT_UNKNOWN;
}

static const struct {
    DWORD bpp;
    DWORD rmask;
    DWORD gmask;
    DWORD bmask;
    DWORD amask;
    D3DFORMAT format;
} rgb_pixel_formats[] = {
    { 8, 0xe0, 0x1c, 0x03, 0, D3DFMT_R3G3B2 },
    { 16, 0xf800, 0x07e0, 0x001f, 0x0000, D3DFMT_R5G6B5 },
    { 16, 0x7c00, 0x03e0, 0x001f, 0x8000, D3DFMT_A1R5G5B5 },
    { 16, 0x7c00, 0x03e0, 0x001f, 0x0000, D3DFMT_X1R5G5B5 },
    { 16, 0x0f00, 0x00f0, 0x000f, 0xf000, D3DFMT_A4R4G4B4 },
    { 16, 0x0f00, 0x00f0, 0x000f, 0x0000, D3DFMT_X4R4G4B4 },
    { 16, 0x00e0, 0x001c, 0x0003, 0xff00, D3DFMT_A8R3G3B2 },
    { 24, 0xff0000, 0x00ff00, 0x0000ff, 0x000000, D3DFMT_R8G8B8 },
    { 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000, D3DFMT_A8R8G8B8 },
    { 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0x00000000, D3DFMT_X8R8G8B8 },
    { 32, 0x3ff00000, 0x000ffc00, 0x000003ff, 0xc0000000, D3DFMT_A2B10G10R10 },
    { 32, 0x000003ff, 0x000ffc00, 0x3ff00000, 0xc0000000, D3DFMT_A2R10G10B10 },
    { 32, 0x0000ffff, 0xffff0000, 0x00000000, 0x00000000, D3DFMT_G16R16 },
    { 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000, D3DFMT_A8B8G8R8 },
    { 32, 0x000000ff, 0x0000ff00, 0x00ff0000, 0x00000000, D3DFMT_X8B8G8R8 },
};

static D3DFORMAT dds_rgb_to_d3dformat(const struct dds_pixel_format *pixel_format)
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
    return D3DFMT_UNKNOWN;
}

static D3DFORMAT dds_luminance_to_d3dformat(const struct dds_pixel_format *pixel_format)
{
    if (pixel_format->bpp == 8)
    {
        if (pixel_format->rmask == 0xff)
            return D3DFMT_L8;
        if ((pixel_format->flags & DDS_PF_ALPHA) && pixel_format->rmask == 0x0f && pixel_format->amask == 0xf0)
            return D3DFMT_A4L4;
    }
    if (pixel_format->bpp == 16)
    {
        if (pixel_format->rmask == 0xffff)
            return D3DFMT_L16;
        if ((pixel_format->flags & DDS_PF_ALPHA) && pixel_format->rmask == 0x00ff && pixel_format->amask == 0xff00)
            return D3DFMT_A8L8;
    }

    WARN("Unknown luminance pixel format (bpp %u, l %#x, a %#x)\n",
        pixel_format->bpp, pixel_format->rmask, pixel_format->amask);
    return D3DFMT_UNKNOWN;
}

static D3DFORMAT dds_alpha_to_d3dformat(const struct dds_pixel_format *pixel_format)
{
    if (pixel_format->bpp == 8 && pixel_format->amask == 0xff)
        return D3DFMT_A8;

    WARN("Unknown Alpha pixel format (%u, %#x)\n", pixel_format->bpp, pixel_format->rmask);
    return D3DFMT_UNKNOWN;
}

static D3DFORMAT dds_bump_to_d3dformat(const struct dds_pixel_format *pixel_format)
{
    if (pixel_format->bpp == 16 && pixel_format->rmask == 0x00ff && pixel_format->gmask == 0xff00)
        return D3DFMT_V8U8;
    if (pixel_format->bpp == 32 && pixel_format->rmask == 0x0000ffff && pixel_format->gmask == 0xffff0000)
        return D3DFMT_V16U16;

    WARN("Unknown bump pixel format (%u, %#x, %#x, %#x, %#x)\n", pixel_format->bpp,
        pixel_format->rmask, pixel_format->gmask, pixel_format->bmask, pixel_format->amask);
    return D3DFMT_UNKNOWN;
}

static D3DFORMAT dds_bump_luminance_to_d3dformat(const struct dds_pixel_format *pixel_format)
{
    if (pixel_format->bpp == 32 && pixel_format->rmask == 0x000000ff && pixel_format->gmask == 0x0000ff00
            && pixel_format->bmask == 0x00ff0000)
        return D3DFMT_X8L8V8U8;

    WARN("Unknown bump pixel format (%u, %#x, %#x, %#x, %#x)\n", pixel_format->bpp,
        pixel_format->rmask, pixel_format->gmask, pixel_format->bmask, pixel_format->amask);
    return D3DFMT_UNKNOWN;
}

static D3DFORMAT dds_pixel_format_to_d3dformat(const struct dds_pixel_format *pixel_format)
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
    return D3DFMT_UNKNOWN;
}

static UINT calculate_dds_file_size(D3DFORMAT format, UINT width, UINT height, UINT depth,
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

static HRESULT get_image_info_from_dds(const void *buffer, UINT length, D3DXIMAGE_INFO *info)
{
    UINT faces = 1;
    UINT expected_length;
    const struct dds_header *header = buffer;

    if (length < sizeof(*header) || !info)
        return (HRESULT)-1;

    if (header->pixel_format.size != sizeof(header->pixel_format))
        return (HRESULT)-1;

    info->Width = header->width;
    info->Height = header->height;
    info->Depth = 1;
    info->MipLevels = header->miplevels ? header->miplevels : 1;

    info->Format = dds_pixel_format_to_d3dformat(&header->pixel_format);
    if (info->Format == D3DFMT_UNKNOWN)
        return (HRESULT)-1;

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
        return (HRESULT)-1;
    }

    info->ImageFileFormat = D3DXIFF_DDS;
    return 0;
}


HRESULT load_texture_from_dds(BYTE *src_data, BYTE *dst_data, D3DXIMAGE_INFO *src_info)
{
    HRESULT hr;
    UINT src_pitch;
    UINT mip_level;
    UINT mip_levels;
    UINT mip_level_size;
    UINT width, height;
    const struct dds_header *header = (struct dds_header*)src_data;
    const BYTE *pixels = (BYTE *)(header + 1);
    struct volume volume_srcdst;

    /* Loading a cube texture as a simple texture is also supported
     * (only first face texture is taken). Same with volume textures. */
    if ((src_info->ResourceType != D3DRTYPE_TEXTURE)
            && (src_info->ResourceType != D3DRTYPE_CUBETEXTURE)
            && (src_info->ResourceType != D3DRTYPE_VOLUMETEXTURE))
    {
        WARN("Trying to load a %u resource as a 2D texture, returning failure.\n", src_info->ResourceType);
        return (HRESULT)-1;
    }

    width = src_info->Width;
    height = src_info->Height;
    mip_levels = 1; /* only take first mipmap */

    volume_srcdst.depth = 1;
    volume_srcdst.width = width;
    volume_srcdst.height = height;

    for (mip_level = 0; mip_level < mip_levels; ++mip_level)
    {
        hr = calculate_dds_surface_size(src_info->Format, width, height, &src_pitch, &mip_level_size);
        if (FAILED(hr)) return hr;

        //!!!handle compressed textures + DX10 textures
        convert_argb_pixels(pixels, src_pitch, 0, &volume_srcdst, get_format_info(dds_rgb_to_d3dformat(&header->pixel_format)), dst_data, width*4, 0, &volume_srcdst, get_format_info(D3DFMT_A8B8G8R8), 0, NULL);

        pixels += mip_level_size;
        width = max(1, width / 2);
        height = max(1, height / 2);
    }

    return (HRESULT)0;
}
/*
 * Turns an image (png/jpg/dds/...) into raw bgr data
 *
 */
static void get_raw_image(BYTE *image_data, UINT data_len,  BYTE **rgba_data, UINT *width, UINT *height)
{
    D3DXIMAGE_INFO image_info;
    int i;
    BYTE *data;

    get_image_info_from_dds(image_data, data_len, &image_info);

    data = HeapAlloc(GetProcessHeap(), 0, image_info.Width * image_info.Height * 4);

    load_texture_from_dds(image_data, data, &image_info);


    /* swap abgr -> rgba */
    /*for(i = 0; i < image_info.Width*image_info.Height*4; i += 4)
    {

        BYTE temp         = data[i+2];
        data[i+2] = data[i+0];
        data[i+0] = temp;
    }*/

    *width = image_info.Width;
    *height = image_info.Height;
    *rgba_data = data;
}


HRESULT WINAPI D3DX11CreateShaderResourceViewFromFileW(ID3D11Device *iface,
        WCHAR *filename, D3DX11_IMAGE_LOAD_INFO *load_info, ID3DX11ThreadPump *pump, ID3D11ShaderResourceView **view, HRESULT *hresult)
{
    D3D11_SHADER_RESOURCE_VIEW_DESC desc_view;
    D3D11_TEXTURE2D_DESC desc_texture;
    D3D11_SUBRESOURCE_DATA data_texture;
    ID3D11Texture2D *texture;
    HRESULT hr;
    void *buffer;
    BYTE *raw_image;
    UINT image_width, image_height;
    HRESULT ret;
    DWORD size;

    if (pump)
        FIXME("Unimplemented ID3DX11ThreadPump handling.\n");

    ret = map_view_of_file(filename, &buffer, &size);

    if (FAILED(ret))
        return E_FAIL;

    get_raw_image(buffer, size, &raw_image, &image_width, &image_height);


    //!!!add trace
    //fill desc
    //handle load_info

    desc_texture.Height = image_height;
    desc_texture.Width = image_width;
    desc_texture.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    desc_texture.MipLevels = 1;
    desc_texture.Usage = D3D11_USAGE_DEFAULT;
    desc_texture.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc_texture.CPUAccessFlags = 0;
    desc_texture.MiscFlags = 0;
    desc_texture.ArraySize = 1;
    desc_texture.SampleDesc.Count = 1;
    desc_texture.SampleDesc.Quality = 0;

    data_texture.pSysMem = raw_image;
    data_texture.SysMemSlicePitch = 0;
    data_texture.SysMemPitch = image_width * 4;

    if (FAILED(hr = iface->lpVtbl->CreateTexture2D(iface, &desc_texture, &data_texture, &texture)))
    {
        HeapFree(GetProcessHeap(), 0, raw_image);
        UnmapViewOfFile(buffer);
        return hr;
    }

    desc_view.Format = desc_texture.Format;
    desc_view.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;

    desc_view.Texture2D.MipLevels = 1;
    desc_view.Texture2D.MostDetailedMip = 0;

    HeapFree(GetProcessHeap(), 0, raw_image);

    if (FAILED(hr = iface->lpVtbl->CreateShaderResourceView(iface, (ID3D11Resource*)texture, &desc_view, view))) //!!cast ??
    {   UnmapViewOfFile(buffer);
        return hr;
    }

    UnmapViewOfFile(buffer);

    return S_OK;
}
