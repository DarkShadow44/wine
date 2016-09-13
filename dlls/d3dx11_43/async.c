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

#define COBJMACROS

#include "config.h"
#include "wine/port.h"
#include "d3dx11.h"
#include "d3dcompiler.h"

#include "wine/debug.h"

#include <objbase.h>
#include "initguid.h"
#include "wincodec.h"

#include "dxgiformat.h"
#include "wine/wined3d.h"

WINE_DEFAULT_DEBUG_CHANNEL(d3dx);

/* temporary defines to not break compilation */

#define IDirect3DSurface9_GetDesc(p,a)                 (p)->lpVtbl->GetDesc(p,a)
#define IDirect3DSurface9_LockRect(p,a,b,c)            (p)->lpVtbl->LockRect(p,a,b,c)
#define IDirect3DSurface9_UnlockRect(p)                (p)->lpVtbl->UnlockRect(p)

typedef struct _D3DSURFACE_DESC {
    DWORD           Format;
    DWORD     Type;
    DWORD               Usage;
    DWORD             Pool;
    DWORD MultiSampleType;
    DWORD               MultiSampleQuality;
    UINT                Width;
    UINT                Height;
} D3DSURFACE_DESC;

typedef struct _D3DLOCKED_RECT {
    INT                 Pitch;
    void*               pBits;
} D3DLOCKED_RECT;

#define INTERFACE IDirect3DSurface9
DECLARE_INTERFACE_(IDirect3DSurface9,IDirect3DResource9)
{
    /*** IUnknown methods ***/
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) PURE;
    STDMETHOD_(ULONG,AddRef)(THIS) PURE;
    STDMETHOD_(ULONG,Release)(THIS) PURE;
    /*** IDirect3DResource9 methods ***/
    STDMETHOD(GetDevice)(THIS_ struct IDirect3DDevice9** ppDevice) PURE;
    STDMETHOD(SetPrivateData)(THIS_ REFGUID guid, const void *data, DWORD data_size, DWORD flags) PURE;
    STDMETHOD(GetPrivateData)(THIS_ REFGUID refguid, void* pData, DWORD* pSizeOfData) PURE;
    STDMETHOD(FreePrivateData)(THIS_ REFGUID refguid) PURE;
    STDMETHOD_(DWORD, SetPriority)(THIS_ DWORD PriorityNew) PURE;
    STDMETHOD_(DWORD, GetPriority)(THIS) PURE;
    STDMETHOD_(void, PreLoad)(THIS) PURE;
    STDMETHOD_(DWORD, GetType)(THIS) PURE;
    /*** IDirect3DSurface9 methods ***/
    STDMETHOD(GetContainer)(THIS_ REFIID riid, void** ppContainer) PURE;
    STDMETHOD(GetDesc)(THIS_ D3DSURFACE_DESC* pDesc) PURE;
    STDMETHOD(LockRect)(THIS_ D3DLOCKED_RECT *locked_rect, const RECT *rect, DWORD flags) PURE;
    STDMETHOD(UnlockRect)(THIS) PURE;
    STDMETHOD(GetDC)(THIS_ HDC* phdc) PURE;
    STDMETHOD(ReleaseDC)(THIS_ HDC hdc) PURE;
};
#undef INTERFACE

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

/* currently taken from dxgi */

DXGI_FORMAT dxgi_format_from_wined3dformat(enum wined3d_format_id format)
{
    switch(format)
    {
        case WINED3DFMT_UNKNOWN: return DXGI_FORMAT_UNKNOWN;
        case WINED3DFMT_R32G32B32A32_TYPELESS: return DXGI_FORMAT_R32G32B32A32_TYPELESS;
        case WINED3DFMT_R32G32B32A32_FLOAT: return DXGI_FORMAT_R32G32B32A32_FLOAT;
        case WINED3DFMT_R32G32B32A32_UINT: return DXGI_FORMAT_R32G32B32A32_UINT;
        case WINED3DFMT_R32G32B32A32_SINT: return DXGI_FORMAT_R32G32B32A32_SINT;
        case WINED3DFMT_R32G32B32_TYPELESS: return DXGI_FORMAT_R32G32B32_TYPELESS;
        case WINED3DFMT_R32G32B32_FLOAT: return DXGI_FORMAT_R32G32B32_FLOAT;
        case WINED3DFMT_R32G32B32_UINT: return DXGI_FORMAT_R32G32B32_UINT;
        case WINED3DFMT_R32G32B32_SINT: return DXGI_FORMAT_R32G32B32_SINT;
        case WINED3DFMT_R16G16B16A16_TYPELESS: return DXGI_FORMAT_R16G16B16A16_TYPELESS;
        case WINED3DFMT_R16G16B16A16_FLOAT: return DXGI_FORMAT_R16G16B16A16_FLOAT;
        case WINED3DFMT_R16G16B16A16_UNORM: return DXGI_FORMAT_R16G16B16A16_UNORM;
        case WINED3DFMT_R16G16B16A16_UINT: return DXGI_FORMAT_R16G16B16A16_UINT;
        case WINED3DFMT_R16G16B16A16_SNORM: return DXGI_FORMAT_R16G16B16A16_SNORM;
        case WINED3DFMT_R16G16B16A16_SINT: return DXGI_FORMAT_R16G16B16A16_SINT;
        case WINED3DFMT_R32G32_TYPELESS: return DXGI_FORMAT_R32G32_TYPELESS;
        case WINED3DFMT_R32G32_FLOAT: return DXGI_FORMAT_R32G32_FLOAT;
        case WINED3DFMT_R32G32_UINT: return DXGI_FORMAT_R32G32_UINT;
        case WINED3DFMT_R32G32_SINT: return DXGI_FORMAT_R32G32_SINT;
        case WINED3DFMT_R32G8X24_TYPELESS: return DXGI_FORMAT_R32G8X24_TYPELESS;
        case WINED3DFMT_D32_FLOAT_S8X24_UINT: return DXGI_FORMAT_D32_FLOAT_S8X24_UINT;
        case WINED3DFMT_R32_FLOAT_X8X24_TYPELESS: return DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS;
        case WINED3DFMT_X32_TYPELESS_G8X24_UINT: return DXGI_FORMAT_X32_TYPELESS_G8X24_UINT;
        case WINED3DFMT_R10G10B10A2_TYPELESS: return DXGI_FORMAT_R10G10B10A2_TYPELESS;
        case WINED3DFMT_R10G10B10A2_UNORM: return DXGI_FORMAT_R10G10B10A2_UNORM;
        case WINED3DFMT_R10G10B10A2_UINT: return DXGI_FORMAT_R10G10B10A2_UINT;
        case WINED3DFMT_R11G11B10_FLOAT: return DXGI_FORMAT_R11G11B10_FLOAT;
        case WINED3DFMT_R8G8B8A8_TYPELESS: return DXGI_FORMAT_R8G8B8A8_TYPELESS;
        case WINED3DFMT_R8G8B8A8_UNORM: return DXGI_FORMAT_R8G8B8A8_UNORM;
        case WINED3DFMT_R8G8B8A8_UNORM_SRGB: return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
        case WINED3DFMT_R8G8B8A8_UINT: return DXGI_FORMAT_R8G8B8A8_UINT;
        case WINED3DFMT_R8G8B8A8_SNORM: return DXGI_FORMAT_R8G8B8A8_SNORM;
        case WINED3DFMT_R8G8B8A8_SINT: return DXGI_FORMAT_R8G8B8A8_SINT;
        case WINED3DFMT_R16G16_TYPELESS: return DXGI_FORMAT_R16G16_TYPELESS;
        case WINED3DFMT_R16G16_FLOAT: return DXGI_FORMAT_R16G16_FLOAT;
        case WINED3DFMT_R16G16_UNORM: return DXGI_FORMAT_R16G16_UNORM;
        case WINED3DFMT_R16G16_UINT: return DXGI_FORMAT_R16G16_UINT;
        case WINED3DFMT_R16G16_SNORM: return DXGI_FORMAT_R16G16_SNORM;
        case WINED3DFMT_R16G16_SINT: return DXGI_FORMAT_R16G16_SINT;
        case WINED3DFMT_R32_TYPELESS: return DXGI_FORMAT_R32_TYPELESS;
        case WINED3DFMT_D32_FLOAT: return DXGI_FORMAT_D32_FLOAT;
        case WINED3DFMT_R32_FLOAT: return DXGI_FORMAT_R32_FLOAT;
        case WINED3DFMT_R32_UINT: return DXGI_FORMAT_R32_UINT;
        case WINED3DFMT_R32_SINT: return DXGI_FORMAT_R32_SINT;
        case WINED3DFMT_R24G8_TYPELESS: return DXGI_FORMAT_R24G8_TYPELESS;
        case WINED3DFMT_D24_UNORM_S8_UINT: return DXGI_FORMAT_D24_UNORM_S8_UINT;
        case WINED3DFMT_R24_UNORM_X8_TYPELESS: return DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
        case WINED3DFMT_X24_TYPELESS_G8_UINT: return DXGI_FORMAT_X24_TYPELESS_G8_UINT;
        case WINED3DFMT_R8G8_TYPELESS: return DXGI_FORMAT_R8G8_TYPELESS;
        case WINED3DFMT_R8G8_UNORM: return DXGI_FORMAT_R8G8_UNORM;
        case WINED3DFMT_R8G8_UINT: return DXGI_FORMAT_R8G8_UINT;
        case WINED3DFMT_R8G8_SNORM: return DXGI_FORMAT_R8G8_SNORM;
        case WINED3DFMT_R8G8_SINT: return DXGI_FORMAT_R8G8_SINT;
        case WINED3DFMT_R16_TYPELESS: return DXGI_FORMAT_R16_TYPELESS;
        case WINED3DFMT_R16_FLOAT: return DXGI_FORMAT_R16_FLOAT;
        case WINED3DFMT_D16_UNORM: return DXGI_FORMAT_D16_UNORM;
        case WINED3DFMT_R16_UNORM: return DXGI_FORMAT_R16_UNORM;
        case WINED3DFMT_R16_UINT: return DXGI_FORMAT_R16_UINT;
        case WINED3DFMT_R16_SNORM: return DXGI_FORMAT_R16_SNORM;
        case WINED3DFMT_R16_SINT: return DXGI_FORMAT_R16_SINT;
        case WINED3DFMT_R8_TYPELESS: return DXGI_FORMAT_R8_TYPELESS;
        case WINED3DFMT_R8_UNORM: return DXGI_FORMAT_R8_UNORM;
        case WINED3DFMT_R8_UINT: return DXGI_FORMAT_R8_UINT;
        case WINED3DFMT_R8_SNORM: return DXGI_FORMAT_R8_SNORM;
        case WINED3DFMT_R8_SINT: return DXGI_FORMAT_R8_SINT;
        case WINED3DFMT_A8_UNORM: return DXGI_FORMAT_A8_UNORM;
        case WINED3DFMT_R1_UNORM: return DXGI_FORMAT_R1_UNORM;
        case WINED3DFMT_R9G9B9E5_SHAREDEXP: return DXGI_FORMAT_R9G9B9E5_SHAREDEXP;
        case WINED3DFMT_R8G8_B8G8_UNORM: return DXGI_FORMAT_R8G8_B8G8_UNORM;
        case WINED3DFMT_G8R8_G8B8_UNORM: return DXGI_FORMAT_G8R8_G8B8_UNORM;
        case WINED3DFMT_BC1_TYPELESS: return DXGI_FORMAT_BC1_TYPELESS;
        case WINED3DFMT_BC1_UNORM: return DXGI_FORMAT_BC1_UNORM;
        case WINED3DFMT_BC1_UNORM_SRGB: return DXGI_FORMAT_BC1_UNORM_SRGB;
        case WINED3DFMT_BC2_TYPELESS: return DXGI_FORMAT_BC2_TYPELESS;
        case WINED3DFMT_BC2_UNORM: return DXGI_FORMAT_BC2_UNORM;
        case WINED3DFMT_BC2_UNORM_SRGB: return DXGI_FORMAT_BC2_UNORM_SRGB;
        case WINED3DFMT_BC3_TYPELESS: return DXGI_FORMAT_BC3_TYPELESS;
        case WINED3DFMT_BC3_UNORM: return DXGI_FORMAT_BC3_UNORM;
        case WINED3DFMT_BC3_UNORM_SRGB: return DXGI_FORMAT_BC3_UNORM_SRGB;
        case WINED3DFMT_BC4_TYPELESS: return DXGI_FORMAT_BC4_TYPELESS;
        case WINED3DFMT_BC4_UNORM: return DXGI_FORMAT_BC4_UNORM;
        case WINED3DFMT_BC4_SNORM: return DXGI_FORMAT_BC4_SNORM;
        case WINED3DFMT_BC5_TYPELESS: return DXGI_FORMAT_BC5_TYPELESS;
        case WINED3DFMT_BC5_UNORM: return DXGI_FORMAT_BC5_UNORM;
        case WINED3DFMT_BC5_SNORM: return DXGI_FORMAT_BC5_SNORM;
        case WINED3DFMT_B5G6R5_UNORM: return DXGI_FORMAT_B5G6R5_UNORM;
        case WINED3DFMT_B5G5R5A1_UNORM: return DXGI_FORMAT_B5G5R5A1_UNORM;
        case WINED3DFMT_B8G8R8A8_UNORM: return DXGI_FORMAT_B8G8R8A8_UNORM;
        case WINED3DFMT_B8G8R8X8_UNORM: return DXGI_FORMAT_B8G8R8X8_UNORM;
        case WINED3DFMT_R10G10B10_XR_BIAS_A2_UNORM: return DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM;
        case WINED3DFMT_B8G8R8A8_TYPELESS: return DXGI_FORMAT_B8G8R8A8_TYPELESS;
        case WINED3DFMT_B8G8R8A8_UNORM_SRGB: return DXGI_FORMAT_B8G8R8A8_UNORM_SRGB;
        case WINED3DFMT_B8G8R8X8_TYPELESS: return DXGI_FORMAT_B8G8R8X8_TYPELESS;
        case WINED3DFMT_B8G8R8X8_UNORM_SRGB: return DXGI_FORMAT_B8G8R8X8_UNORM_SRGB;
        case WINED3DFMT_BC6H_TYPELESS: return DXGI_FORMAT_BC6H_TYPELESS;
        case WINED3DFMT_BC6H_UF16: return DXGI_FORMAT_BC6H_UF16;
        case WINED3DFMT_BC6H_SF16: return DXGI_FORMAT_BC6H_SF16;
        case WINED3DFMT_BC7_TYPELESS: return DXGI_FORMAT_BC7_TYPELESS;
        case WINED3DFMT_BC7_UNORM: return DXGI_FORMAT_BC7_UNORM;
        case WINED3DFMT_BC7_UNORM_SRGB: return DXGI_FORMAT_BC7_UNORM_SRGB;
        default:
            FIXME("Unhandled wined3d format %#x.\n", format);
            return DXGI_FORMAT_UNKNOWN;
    }
}

enum wined3d_format_id wined3dformat_from_dxgi_format(DXGI_FORMAT format)
{
    switch(format)
    {
        case DXGI_FORMAT_UNKNOWN: return WINED3DFMT_UNKNOWN;
        case DXGI_FORMAT_R32G32B32A32_TYPELESS: return WINED3DFMT_R32G32B32A32_TYPELESS;
        case DXGI_FORMAT_R32G32B32A32_FLOAT: return WINED3DFMT_R32G32B32A32_FLOAT;
        case DXGI_FORMAT_R32G32B32A32_UINT: return WINED3DFMT_R32G32B32A32_UINT;
        case DXGI_FORMAT_R32G32B32A32_SINT: return WINED3DFMT_R32G32B32A32_SINT;
        case DXGI_FORMAT_R32G32B32_TYPELESS: return WINED3DFMT_R32G32B32_TYPELESS;
        case DXGI_FORMAT_R32G32B32_FLOAT: return WINED3DFMT_R32G32B32_FLOAT;
        case DXGI_FORMAT_R32G32B32_UINT: return WINED3DFMT_R32G32B32_UINT;
        case DXGI_FORMAT_R32G32B32_SINT: return WINED3DFMT_R32G32B32_SINT;
        case DXGI_FORMAT_R16G16B16A16_TYPELESS: return WINED3DFMT_R16G16B16A16_TYPELESS;
        case DXGI_FORMAT_R16G16B16A16_FLOAT: return WINED3DFMT_R16G16B16A16_FLOAT;
        case DXGI_FORMAT_R16G16B16A16_UNORM: return WINED3DFMT_R16G16B16A16_UNORM;
        case DXGI_FORMAT_R16G16B16A16_UINT: return WINED3DFMT_R16G16B16A16_UINT;
        case DXGI_FORMAT_R16G16B16A16_SNORM: return WINED3DFMT_R16G16B16A16_SNORM;
        case DXGI_FORMAT_R16G16B16A16_SINT: return WINED3DFMT_R16G16B16A16_SINT;
        case DXGI_FORMAT_R32G32_TYPELESS: return WINED3DFMT_R32G32_TYPELESS;
        case DXGI_FORMAT_R32G32_FLOAT: return WINED3DFMT_R32G32_FLOAT;
        case DXGI_FORMAT_R32G32_UINT: return WINED3DFMT_R32G32_UINT;
        case DXGI_FORMAT_R32G32_SINT: return WINED3DFMT_R32G32_SINT;
        case DXGI_FORMAT_R32G8X24_TYPELESS: return WINED3DFMT_R32G8X24_TYPELESS;
        case DXGI_FORMAT_D32_FLOAT_S8X24_UINT: return WINED3DFMT_D32_FLOAT_S8X24_UINT;
        case DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS: return WINED3DFMT_R32_FLOAT_X8X24_TYPELESS;
        case DXGI_FORMAT_X32_TYPELESS_G8X24_UINT: return WINED3DFMT_X32_TYPELESS_G8X24_UINT;
        case DXGI_FORMAT_R10G10B10A2_TYPELESS: return WINED3DFMT_R10G10B10A2_TYPELESS;
        case DXGI_FORMAT_R10G10B10A2_UNORM: return WINED3DFMT_R10G10B10A2_UNORM;
        case DXGI_FORMAT_R10G10B10A2_UINT: return WINED3DFMT_R10G10B10A2_UINT;
        case DXGI_FORMAT_R11G11B10_FLOAT: return WINED3DFMT_R11G11B10_FLOAT;
        case DXGI_FORMAT_R8G8B8A8_TYPELESS: return WINED3DFMT_R8G8B8A8_TYPELESS;
        case DXGI_FORMAT_R8G8B8A8_UNORM: return WINED3DFMT_R8G8B8A8_UNORM;
        case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB: return WINED3DFMT_R8G8B8A8_UNORM_SRGB;
        case DXGI_FORMAT_R8G8B8A8_UINT: return WINED3DFMT_R8G8B8A8_UINT;
        case DXGI_FORMAT_R8G8B8A8_SNORM: return WINED3DFMT_R8G8B8A8_SNORM;
        case DXGI_FORMAT_R8G8B8A8_SINT: return WINED3DFMT_R8G8B8A8_SINT;
        case DXGI_FORMAT_R16G16_TYPELESS: return WINED3DFMT_R16G16_TYPELESS;
        case DXGI_FORMAT_R16G16_FLOAT: return WINED3DFMT_R16G16_FLOAT;
        case DXGI_FORMAT_R16G16_UNORM: return WINED3DFMT_R16G16_UNORM;
        case DXGI_FORMAT_R16G16_UINT: return WINED3DFMT_R16G16_UINT;
        case DXGI_FORMAT_R16G16_SNORM: return WINED3DFMT_R16G16_SNORM;
        case DXGI_FORMAT_R16G16_SINT: return WINED3DFMT_R16G16_SINT;
        case DXGI_FORMAT_R32_TYPELESS: return WINED3DFMT_R32_TYPELESS;
        case DXGI_FORMAT_D32_FLOAT: return WINED3DFMT_D32_FLOAT;
        case DXGI_FORMAT_R32_FLOAT: return WINED3DFMT_R32_FLOAT;
        case DXGI_FORMAT_R32_UINT: return WINED3DFMT_R32_UINT;
        case DXGI_FORMAT_R32_SINT: return WINED3DFMT_R32_SINT;
        case DXGI_FORMAT_R24G8_TYPELESS: return WINED3DFMT_R24G8_TYPELESS;
        case DXGI_FORMAT_D24_UNORM_S8_UINT: return WINED3DFMT_D24_UNORM_S8_UINT;
        case DXGI_FORMAT_R24_UNORM_X8_TYPELESS: return WINED3DFMT_R24_UNORM_X8_TYPELESS;
        case DXGI_FORMAT_X24_TYPELESS_G8_UINT: return WINED3DFMT_X24_TYPELESS_G8_UINT;
        case DXGI_FORMAT_R8G8_TYPELESS: return WINED3DFMT_R8G8_TYPELESS;
        case DXGI_FORMAT_R8G8_UNORM: return WINED3DFMT_R8G8_UNORM;
        case DXGI_FORMAT_R8G8_UINT: return WINED3DFMT_R8G8_UINT;
        case DXGI_FORMAT_R8G8_SNORM: return WINED3DFMT_R8G8_SNORM;
        case DXGI_FORMAT_R8G8_SINT: return WINED3DFMT_R8G8_SINT;
        case DXGI_FORMAT_R16_TYPELESS: return WINED3DFMT_R16_TYPELESS;
        case DXGI_FORMAT_R16_FLOAT: return WINED3DFMT_R16_FLOAT;
        case DXGI_FORMAT_D16_UNORM: return WINED3DFMT_D16_UNORM;
        case DXGI_FORMAT_R16_UNORM: return WINED3DFMT_R16_UNORM;
        case DXGI_FORMAT_R16_UINT: return WINED3DFMT_R16_UINT;
        case DXGI_FORMAT_R16_SNORM: return WINED3DFMT_R16_SNORM;
        case DXGI_FORMAT_R16_SINT: return WINED3DFMT_R16_SINT;
        case DXGI_FORMAT_R8_TYPELESS: return WINED3DFMT_R8_TYPELESS;
        case DXGI_FORMAT_R8_UNORM: return WINED3DFMT_R8_UNORM;
        case DXGI_FORMAT_R8_UINT: return WINED3DFMT_R8_UINT;
        case DXGI_FORMAT_R8_SNORM: return WINED3DFMT_R8_SNORM;
        case DXGI_FORMAT_R8_SINT: return WINED3DFMT_R8_SINT;
        case DXGI_FORMAT_A8_UNORM: return WINED3DFMT_A8_UNORM;
        case DXGI_FORMAT_R1_UNORM: return WINED3DFMT_R1_UNORM;
        case DXGI_FORMAT_R9G9B9E5_SHAREDEXP: return WINED3DFMT_R9G9B9E5_SHAREDEXP;
        case DXGI_FORMAT_R8G8_B8G8_UNORM: return WINED3DFMT_R8G8_B8G8_UNORM;
        case DXGI_FORMAT_G8R8_G8B8_UNORM: return WINED3DFMT_G8R8_G8B8_UNORM;
        case DXGI_FORMAT_BC1_TYPELESS: return WINED3DFMT_BC1_TYPELESS;
        case DXGI_FORMAT_BC1_UNORM: return WINED3DFMT_BC1_UNORM;
        case DXGI_FORMAT_BC1_UNORM_SRGB: return WINED3DFMT_BC1_UNORM_SRGB;
        case DXGI_FORMAT_BC2_TYPELESS: return WINED3DFMT_BC2_TYPELESS;
        case DXGI_FORMAT_BC2_UNORM: return WINED3DFMT_BC2_UNORM;
        case DXGI_FORMAT_BC2_UNORM_SRGB: return WINED3DFMT_BC2_UNORM_SRGB;
        case DXGI_FORMAT_BC3_TYPELESS: return WINED3DFMT_BC3_TYPELESS;
        case DXGI_FORMAT_BC3_UNORM: return WINED3DFMT_BC3_UNORM;
        case DXGI_FORMAT_BC3_UNORM_SRGB: return WINED3DFMT_BC3_UNORM_SRGB;
        case DXGI_FORMAT_BC4_TYPELESS: return WINED3DFMT_BC4_TYPELESS;
        case DXGI_FORMAT_BC4_UNORM: return WINED3DFMT_BC4_UNORM;
        case DXGI_FORMAT_BC4_SNORM: return WINED3DFMT_BC4_SNORM;
        case DXGI_FORMAT_BC5_TYPELESS: return WINED3DFMT_BC5_TYPELESS;
        case DXGI_FORMAT_BC5_UNORM: return WINED3DFMT_BC5_UNORM;
        case DXGI_FORMAT_BC5_SNORM: return WINED3DFMT_BC5_SNORM;
        case DXGI_FORMAT_B5G6R5_UNORM: return WINED3DFMT_B5G6R5_UNORM;
        case DXGI_FORMAT_B5G5R5A1_UNORM: return WINED3DFMT_B5G5R5A1_UNORM;
        case DXGI_FORMAT_B8G8R8A8_UNORM: return WINED3DFMT_B8G8R8A8_UNORM;
        case DXGI_FORMAT_B8G8R8X8_UNORM: return WINED3DFMT_B8G8R8X8_UNORM;
        case DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM: return WINED3DFMT_R10G10B10_XR_BIAS_A2_UNORM;
        case DXGI_FORMAT_B8G8R8A8_TYPELESS: return WINED3DFMT_B8G8R8A8_TYPELESS;
        case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB: return WINED3DFMT_B8G8R8A8_UNORM_SRGB;
        case DXGI_FORMAT_B8G8R8X8_TYPELESS: return WINED3DFMT_B8G8R8X8_TYPELESS;
        case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB: return WINED3DFMT_B8G8R8X8_UNORM_SRGB;
        case DXGI_FORMAT_BC6H_TYPELESS: return WINED3DFMT_BC6H_TYPELESS;
        case DXGI_FORMAT_BC6H_UF16: return WINED3DFMT_BC6H_UF16;
        case DXGI_FORMAT_BC6H_SF16: return WINED3DFMT_BC6H_SF16;
        case DXGI_FORMAT_BC7_TYPELESS: return WINED3DFMT_BC7_TYPELESS;
        case DXGI_FORMAT_BC7_UNORM: return WINED3DFMT_BC7_UNORM;
        case DXGI_FORMAT_BC7_UNORM_SRGB: return WINED3DFMT_BC7_UNORM_SRGB;
        default:
            FIXME("Unhandled DXGI_FORMAT %#x.\n", format);
            return WINED3DFMT_UNKNOWN;
    }
}

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

/* defines currently taken from d3dx9.h */

#define D3DX_DEFAULT         ((UINT)-1)

/* defines currently taken from d3dx9tex.h */

#define D3DX_FILTER_NONE                 0x00000001
#define D3DX_FILTER_POINT                0x00000002
#define D3DX_FILTER_LINEAR               0x00000003
#define D3DX_FILTER_TRIANGLE             0x00000004
#define D3DX_FILTER_BOX                  0x00000005
#define D3DX_FILTER_MIRROR_U             0x00010000
#define D3DX_FILTER_MIRROR_V             0x00020000
#define D3DX_FILTER_MIRROR_W             0x00040000
#define D3DX_FILTER_MIRROR               0x00070000
#define D3DX_FILTER_DITHER               0x00080000
#define D3DX_FILTER_DITHER_DIFFUSION     0x00100000
#define D3DX_FILTER_SRGB_IN              0x00200000
#define D3DX_FILTER_SRGB_OUT             0x00400000
#define D3DX_FILTER_SRGB                 0x00600000

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
    D3DFORMAT Format;
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
    /* marks last element */
    {D3DFMT_UNKNOWN,       { 0,  0,  0,  0}, { 0,  0,  0,  0},  0, 1, 1,  0, FORMAT_UNKNOWN, NULL,         NULL      },
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

/************************************************************
 * get_format_info
 *
 * Returns information about the specified format.
 * If the format is unsupported, it's filled with the D3DFMT_UNKNOWN desc.
 *
 * PARAMS
 *   format [I] format whose description is queried
 *
 */
const struct pixel_format_desc *get_format_info(D3DFORMAT format)
{
    unsigned int i = 0;
    while(formats[i].format != format && formats[i].format != D3DFMT_UNKNOWN) i++;
    if (formats[i].format == D3DFMT_UNKNOWN)
        FIXME("Unknown format %#x (as FOURCC %s).\n", format, debugstr_an((const char *)&format, 4));
    return &formats[i];
}

/* functions from d3dx9_36/math.c */

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

/* Functions from d3dx9_36/surface.c */

/* Wine-specific WIC GUIDs */
DEFINE_GUID(GUID_WineContainerFormatTga, 0x0c44fda1,0xa5c5,0x4298,0x96,0x85,0x47,0x3f,0xc1,0x7c,0xd3,0x22);

static const struct
{
    const GUID *wic_guid;
    D3DFORMAT d3dformat;
} wic_pixel_formats[] = {
    { &GUID_WICPixelFormat8bppIndexed, D3DFMT_P8 },
    { &GUID_WICPixelFormat1bppIndexed, D3DFMT_P8 },
    { &GUID_WICPixelFormat4bppIndexed, D3DFMT_P8 },
    { &GUID_WICPixelFormat8bppGray, D3DFMT_L8 },
    { &GUID_WICPixelFormat16bppBGR555, D3DFMT_X1R5G5B5 },
    { &GUID_WICPixelFormat16bppBGR565, D3DFMT_R5G6B5 },
    { &GUID_WICPixelFormat24bppBGR, D3DFMT_R8G8B8 },
    { &GUID_WICPixelFormat32bppBGR, D3DFMT_X8R8G8B8 },
    { &GUID_WICPixelFormat32bppBGRA, D3DFMT_A8R8G8B8 }
};

static D3DFORMAT wic_guid_to_d3dformat(const GUID *guid)
{
    unsigned int i;

    for (i = 0; i < sizeof(wic_pixel_formats) / sizeof(wic_pixel_formats[0]); i++)
    {
        if (IsEqualGUID(wic_pixel_formats[i].wic_guid, guid))
            return wic_pixel_formats[i].d3dformat;
    }

    return D3DFMT_UNKNOWN;
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

    WARN("Unknown pixel format (flags %#x, fourcc %#x, bpp %u, r %#x, g %#x, b %#x, a %#x)\n",
        pixel_format->flags, pixel_format->fourcc, pixel_format->bpp,
        pixel_format->rmask, pixel_format->gmask, pixel_format->bmask, pixel_format->amask);
    return D3DFMT_UNKNOWN;
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

    return D3D_OK;
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
    if (info->Format == D3DFMT_UNKNOWN)
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

/************************************************************
 * helper functions for D3DXLoadSurfaceFromMemory
 */
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

/************************************************************
 * point_filter_argb_pixels
 *
 * Copies the source buffer to the destination buffer, performing
 * any necessary format conversion, color keying and stretching
 * using a point filter.
 */
void point_filter_argb_pixels(const BYTE *src, UINT src_row_pitch, UINT src_slice_pitch, const struct volume *src_size,
        const struct pixel_format_desc *src_format, BYTE *dst, UINT dst_row_pitch, UINT dst_slice_pitch,
        const struct volume *dst_size, const struct pixel_format_desc *dst_format, D3DCOLOR color_key,
        const PALETTEENTRY *palette)
{
    struct argb_conversion_info conv_info, ck_conv_info;
    const struct pixel_format_desc *ck_format = NULL;
    DWORD channels[4];
    UINT x, y, z;

    ZeroMemory(channels, sizeof(channels));
    init_argb_conversion_info(src_format, dst_format, &conv_info);

    if (color_key)
    {
        /* Color keys are always represented in D3DFMT_A8R8G8B8 format. */
        ck_format = get_format_info(D3DFMT_A8R8G8B8);
        init_argb_conversion_info(src_format, ck_format, &ck_conv_info);
    }

    for (z = 0; z < dst_size->depth; z++)
    {
        BYTE *dst_slice_ptr = dst + z * dst_slice_pitch;
        const BYTE *src_slice_ptr = src + src_slice_pitch * (z * src_size->depth / dst_size->depth);

        for (y = 0; y < dst_size->height; y++)
        {
            BYTE *dst_ptr = dst_slice_ptr + y * dst_row_pitch;
            const BYTE *src_row_ptr = src_slice_ptr + src_row_pitch * (y * src_size->height / dst_size->height);

            for (x = 0; x < dst_size->width; x++)
            {
                const BYTE *src_ptr = src_row_ptr + (x * src_size->width / dst_size->width) * src_format->bytes_per_pixel;

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

                dst_ptr += dst_format->bytes_per_pixel;
            }
        }
    }
}

/************************************************************
 * D3DXGetImageInfoFromFileInMemory
 *
 * Fills a D3DXIMAGE_INFO structure with info about an image
 *
 * PARAMS
 *   data     [I] pointer to the image file data
 *   datasize [I] size of the passed data
 *   info     [O] pointer to the destination structure
 *
 * RETURNS
 *   Success: D3D_OK, if info is not NULL and data and datasize make up a valid image file or
 *                    if info is NULL and data and datasize are not NULL
 *   Failure: D3DXERR_INVALIDDATA, if data is no valid image file and datasize and info are not NULL
 *            D3DERR_INVALIDCALL, if data is NULL or
 *                                if datasize is 0
 *
 * NOTES
 *   datasize may be bigger than the actual file size
 *
 */
HRESULT WINAPI D3DXGetImageInfoFromFileInMemory(const void *data, UINT datasize, D3DXIMAGE_INFO *info)
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
                    if (info->Format == D3DFMT_UNKNOWN) {
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

/************************************************************
 * D3DXLoadSurfaceFromMemory
 *
 * Loads data from a given memory chunk into a surface,
 * applying any of the specified filters.
 *
 * PARAMS
 *   pDestSurface [I] pointer to the surface
 *   pDestPalette [I] palette to use
 *   pDestRect    [I] to be filled area of the surface
 *   pSrcMemory   [I] pointer to the source data
 *   SrcFormat    [I] format of the source pixel data
 *   SrcPitch     [I] number of bytes in a row
 *   pSrcPalette  [I] palette used in the source image
 *   pSrcRect     [I] area of the source data to load
 *   dwFilter     [I] filter to apply on stretching
 *   Colorkey     [I] colorkey
 *
 * RETURNS
 *   Success: D3D_OK, if we successfully load the pixel data into our surface or
 *                    if pSrcMemory is NULL but the other parameters are valid
 *   Failure: D3DERR_INVALIDCALL, if pDestSurface, SrcPitch or pSrcRect is NULL or
 *                                if SrcFormat is an invalid format (other than D3DFMT_UNKNOWN) or
 *                                if DestRect is invalid
 *            D3DXERR_INVALIDDATA, if we fail to lock pDestSurface
 *            E_FAIL, if SrcFormat is D3DFMT_UNKNOWN or the dimensions of pSrcRect are invalid
 *
 * NOTES
 *   pSrcRect specifies the dimensions of the source data;
 *   negative values for pSrcRect are allowed as we're only looking at the width and height anyway.
 *
 */
HRESULT WINAPI D3DXLoadSurfaceFromMemory(IDirect3DSurface9 *dst_surface,
        const PALETTEENTRY *dst_palette, const RECT *dst_rect, const void *src_memory,
        D3DFORMAT src_format, UINT src_pitch, const PALETTEENTRY *src_palette, const RECT *src_rect,
        DWORD filter, D3DCOLOR color_key)
{
    const struct pixel_format_desc *srcformatdesc, *destformatdesc;
    D3DSURFACE_DESC surfdesc;
    D3DLOCKED_RECT lockrect;
    struct volume src_size, dst_size;

    TRACE("(%p, %p, %s, %p, %#x, %u, %p, %s, %#x, 0x%08x)\n",
            dst_surface, dst_palette, wine_dbgstr_rect(dst_rect), src_memory, src_format,
            src_pitch, src_palette, wine_dbgstr_rect(src_rect), filter, color_key);

    if (!dst_surface || !src_memory || !src_rect)
    {
        WARN("Invalid argument specified.\n");
        return D3DERR_INVALIDCALL;
    }
    if (src_format == D3DFMT_UNKNOWN
            || src_rect->left >= src_rect->right
            || src_rect->top >= src_rect->bottom)
    {
        WARN("Invalid src_format or src_rect.\n");
        return E_FAIL;
    }

    if (filter == D3DX_DEFAULT)
        filter = D3DX_FILTER_TRIANGLE | D3DX_FILTER_DITHER;

    IDirect3DSurface9_GetDesc(dst_surface, &surfdesc);

    src_size.width = src_rect->right - src_rect->left;
    src_size.height = src_rect->bottom - src_rect->top;
    src_size.depth = 1;
    if (!dst_rect)
    {
        dst_size.width = surfdesc.Width;
        dst_size.height = surfdesc.Height;
    }
    else
    {
        if (dst_rect->left > dst_rect->right || dst_rect->right > surfdesc.Width
                || dst_rect->top > dst_rect->bottom || dst_rect->bottom > surfdesc.Height
                || dst_rect->left < 0 || dst_rect->top < 0)
        {
            WARN("Invalid dst_rect specified.\n");
            return D3DERR_INVALIDCALL;
        }
        dst_size.width = dst_rect->right - dst_rect->left;
        dst_size.height = dst_rect->bottom - dst_rect->top;
        if (!dst_size.width || !dst_size.height)
            return D3D_OK;
    }
    dst_size.depth = 1;

    srcformatdesc = get_format_info(src_format);
    destformatdesc = get_format_info(surfdesc.Format);
    if (srcformatdesc->type == FORMAT_UNKNOWN || destformatdesc->type == FORMAT_UNKNOWN)
    {
        FIXME("Unsupported pixel format conversion %#x -> %#x\n", src_format, surfdesc.Format);
        return E_NOTIMPL;
    }

    if (src_format == surfdesc.Format
            && dst_size.width == src_size.width
            && dst_size.height == src_size.height
            && color_key == 0) /* Simple copy. */
    {
        if (src_rect->left & (srcformatdesc->block_width - 1)
                || src_rect->top & (srcformatdesc->block_height - 1)
                || (src_rect->right & (srcformatdesc->block_width - 1)
                    && src_size.width != surfdesc.Width)
                || (src_rect->bottom & (srcformatdesc->block_height - 1)
                    && src_size.height != surfdesc.Height))
        {
            WARN("Source rect %s is misaligned.\n", wine_dbgstr_rect(src_rect));
            return D3DXERR_INVALIDDATA;
        }

        if (FAILED(IDirect3DSurface9_LockRect(dst_surface, &lockrect, dst_rect, 0)))
            return D3DXERR_INVALIDDATA;

        copy_pixels(src_memory, src_pitch, 0, lockrect.pBits, lockrect.Pitch, 0,
                &src_size, srcformatdesc);

        IDirect3DSurface9_UnlockRect(dst_surface);
    }
    else /* Stretching or format conversion. */
    {
        if (((srcformatdesc->type != FORMAT_ARGB) && (srcformatdesc->type != FORMAT_INDEX)) ||
            (destformatdesc->type != FORMAT_ARGB))
        {
            FIXME("Format conversion missing %#x -> %#x\n", src_format, surfdesc.Format);
            return E_NOTIMPL;
        }

        if (FAILED(IDirect3DSurface9_LockRect(dst_surface, &lockrect, dst_rect, 0)))
            return D3DXERR_INVALIDDATA;

        if ((filter & 0xf) == D3DX_FILTER_NONE)
        {
            convert_argb_pixels(src_memory, src_pitch, 0, &src_size, srcformatdesc,
                    lockrect.pBits, lockrect.Pitch, 0, &dst_size, destformatdesc, color_key, src_palette);
        }
        else /* if ((filter & 0xf) == D3DX_FILTER_POINT) */
        {
            if ((filter & 0xf) != D3DX_FILTER_POINT)
                FIXME("Unhandled filter %#x.\n", filter);

            /* Always apply a point filter until D3DX_FILTER_LINEAR,
             * D3DX_FILTER_TRIANGLE and D3DX_FILTER_BOX are implemented. */
            point_filter_argb_pixels(src_memory, src_pitch, 0, &src_size, srcformatdesc,
                    lockrect.pBits, lockrect.Pitch, 0, &dst_size, destformatdesc, color_key, src_palette);
        }

        IDirect3DSurface9_UnlockRect(dst_surface);
    }

    return D3D_OK;
}

static HRESULT load_surface_from_dds(IDirect3DSurface9 *dst_surface, const PALETTEENTRY *dst_palette,
    const RECT *dst_rect, const void *src_data, const RECT *src_rect, DWORD filter, D3DCOLOR color_key,
    const D3DXIMAGE_INFO *src_info)
{
    UINT size;
    UINT src_pitch;
    const struct dds_header *header = src_data;
    const BYTE *pixels = (BYTE *)(header + 1);

    if (src_info->ResourceType != D3DRTYPE_TEXTURE)
        return D3DXERR_INVALIDDATA;

    if (FAILED(calculate_dds_surface_size(src_info->Format, src_info->Width, src_info->Height, &src_pitch, &size)))
        return E_NOTIMPL;

    return D3DXLoadSurfaceFromMemory(dst_surface, dst_palette, dst_rect, pixels, src_info->Format,
        src_pitch, NULL, src_rect, filter, color_key);
}

/************************************************************
 * D3DXLoadSurfaceFromFileInMemory
 *
 * Loads data from a given buffer into a surface and fills a given
 * D3DXIMAGE_INFO structure with info about the source data.
 *
 * PARAMS
 *   pDestSurface [I] pointer to the surface
 *   pDestPalette [I] palette to use
 *   pDestRect    [I] to be filled area of the surface
 *   pSrcData     [I] pointer to the source data
 *   SrcDataSize  [I] size of the source data in bytes
 *   pSrcRect     [I] area of the source data to load
 *   dwFilter     [I] filter to apply on stretching
 *   Colorkey     [I] colorkey
 *   pSrcInfo     [O] pointer to a D3DXIMAGE_INFO structure
 *
 * RETURNS
 *   Success: D3D_OK
 *   Failure: D3DERR_INVALIDCALL, if pDestSurface, pSrcData or SrcDataSize is NULL
 *            D3DXERR_INVALIDDATA, if pSrcData is no valid image file
 *
 */
HRESULT WINAPI D3DXLoadSurfaceFromFileInMemory(IDirect3DSurface9 *pDestSurface,
        const PALETTEENTRY *pDestPalette, const RECT *pDestRect, const void *pSrcData, UINT SrcDataSize,
        const RECT *pSrcRect, DWORD dwFilter, D3DCOLOR Colorkey, D3DXIMAGE_INFO *pSrcInfo)
{
    D3DXIMAGE_INFO imginfo;
    HRESULT hr, com_init;

    IWICImagingFactory *factory = NULL;
    IWICBitmapDecoder *decoder;
    IWICBitmapFrameDecode *bitmapframe;
    IWICStream *stream;

    const struct pixel_format_desc *formatdesc;
    WICRect wicrect;
    RECT rect;

    TRACE("dst_surface %p, dst_palette %p, dst_rect %s, src_data %p, src_data_size %u, "
            "src_rect %s, filter %#x, color_key 0x%08x, src_info %p.\n",
            pDestSurface, pDestPalette, wine_dbgstr_rect(pDestRect), pSrcData, SrcDataSize,
            wine_dbgstr_rect(pSrcRect), dwFilter, Colorkey, pSrcInfo);

    if (!pDestSurface || !pSrcData || !SrcDataSize)
        return D3DERR_INVALIDCALL;

    hr = D3DXGetImageInfoFromFileInMemory(pSrcData, SrcDataSize, &imginfo);

    if (FAILED(hr))
        return hr;

    if (pSrcRect)
    {
        wicrect.X = pSrcRect->left;
        wicrect.Y = pSrcRect->top;
        wicrect.Width = pSrcRect->right - pSrcRect->left;
        wicrect.Height = pSrcRect->bottom - pSrcRect->top;
    }
    else
    {
        wicrect.X = 0;
        wicrect.Y = 0;
        wicrect.Width = imginfo.Width;
        wicrect.Height = imginfo.Height;
    }

    SetRect(&rect, 0, 0, wicrect.Width, wicrect.Height);

    if (imginfo.ImageFileFormat == D3DXIFF_DDS)
    {
        hr = load_surface_from_dds(pDestSurface, pDestPalette, pDestRect, pSrcData, &rect,
            dwFilter, Colorkey, &imginfo);
        if (SUCCEEDED(hr) && pSrcInfo)
            *pSrcInfo = imginfo;
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
            hr = D3DXLoadSurfaceFromMemory(pDestSurface, pDestPalette, pDestRect,
                                           buffer, imginfo.Format, pitch,
                                           palette, &rect, dwFilter, Colorkey);
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
        return D3DXERR_INVALIDDATA;

    if (pSrcInfo)
        *pSrcInfo = imginfo;

    return D3D_OK;
}

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

HRESULT WINAPI D3DX11CompileFromFileW(const WCHAR *filename, const D3D10_SHADER_MACRO *defines,
        ID3D10Include *include, const char *entry_point, const char *target, UINT sflags, UINT eflags,
        ID3DX11ThreadPump *pump, ID3D10Blob **shader, ID3D10Blob **error_messages, HRESULT *hresult)
{
    FIXME("filename %s, defines %p, include %p, entry_point %s, target %s, sflags %#x, "
            "eflags %#x, pump %p, shader %p, error_messages %p, hresult %p stub.\n",
            debugstr_w(filename), defines, include, debugstr_a(entry_point), debugstr_a(target),
            sflags, eflags, pump, shader, error_messages, hresult);

    return E_NOTIMPL;
}

HRESULT WINAPI D3DX11CreateTextureFromMemory(ID3D11Device *device, const void *data,
        SIZE_T data_size, D3DX11_IMAGE_LOAD_INFO *load_info, ID3DX11ThreadPump *pump,
        ID3D11Resource **texture, HRESULT *hresult)
{
    FIXME("device %p, data %p, data_size %lu, load_info %p, pump %p, texture %p, hresult %p stub.\n",
            device, data, data_size, load_info, pump, texture, hresult);

    return E_NOTIMPL;
}
