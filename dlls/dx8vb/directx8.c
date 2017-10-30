/*
 * Copyright 2017 Fabian Maurer
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

#include "dx8vb_private.h"
#define __WINE_D3D8TYPES_H
#define __WINE_D3D8CAPS_H
#include "d3d8.h"
#include "ocidl.h"

#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(dx8vb);

typedef struct
{
    IDirectX8 IDirectX8_iface;
    LONG ref;
} directx8;

typedef struct
{
    Direct3D8 Direct3D8_iface;
    IDirect3D8 *direct3d8;
    LONG ref;
} direct3d8;

typedef struct
{
    Direct3DDevice8 Direct3DDevice8_iface;
    IDirect3DDevice8 *direct3ddevice8;
    LONG ref;
} direct3ddevice8;

static inline directx8 *impl_from_IDirectX8(IDirectX8 *iface)
{
    return CONTAINING_RECORD(iface, directx8, IDirectX8_iface);
}

static inline direct3d8 *impl_from_Direct3D8(Direct3D8 *iface)
{
    return CONTAINING_RECORD(iface, direct3d8, Direct3D8_iface);
}

static inline direct3ddevice8 *impl_from_Direct3DDevice8(Direct3DDevice8 *iface)
{
    return CONTAINING_RECORD(iface, direct3ddevice8, Direct3DDevice8_iface);
}

/*** directd3ddevice8 - IUnknown methods ***/

static HRESULT WINAPI direct3ddevice8_QueryInterface(Direct3DDevice8 *iface, REFIID riid, void **ppv)
{
    direct3ddevice8 *This = impl_from_Direct3DDevice8(iface);

    TRACE("(%p/%p)->(%s,%p)\n", iface, This, debugstr_guid(riid), ppv);

    *ppv = NULL;

    if (IsEqualGUID(riid, &IID_IUnknown))
        *ppv = &This->Direct3DDevice8_iface;
     else if(IsEqualGUID(riid, &IID_ISupportErrorInfo))
        FIXME("No interface for IID_ISupportErrorInfo\n");
    else
        FIXME("No interface for %s\n", debugstr_guid(riid));

    if (*ppv)
    {
        IUnknown_AddRef((IUnknown *)(*ppv));
        return S_OK;
    }

    return E_NOINTERFACE;
}

static ULONG WINAPI direct3ddevice8_AddRef(Direct3DDevice8 *iface)
{
    direct3ddevice8 *This = impl_from_Direct3DDevice8(iface);
    ULONG ref = InterlockedIncrement(&This->ref);

    TRACE("(%p/%p)->(): new ref %d\n", iface, This, ref);

    return ref;
}

static ULONG WINAPI direct3ddevice8_Release(Direct3DDevice8 *iface)
{
    direct3ddevice8 *This = impl_from_Direct3DDevice8(iface);
    ULONG ref = InterlockedDecrement(&This->ref);

    TRACE("(%p/%p)->(): new ref %d\n", iface, This, ref);

    if (!ref)
    {
        IDirect3DDevice8_Release(This->direct3ddevice8);
        HeapFree(GetProcessHeap(), 0, This);
    }

    return ref;
}

/*** directd3ddevice8 - Direct3DDevice8 methods ***/

LONG WINAPI direct3ddevice8_TestCooperativeLevel(Direct3DDevice8 *iface)
{
    FIXME("(): stub!\n");

    return 0;
}

static int WINAPI direct3ddevice8_GetAvailableTextureMem(Direct3DDevice8 *iface, D3DPOOL pool)
{
    FIXME("(%x): stub!\n", pool);

    return 0;
}

static HRESULT WINAPI direct3ddevice8_ResourceManagerDiscardBytes(Direct3DDevice8 *iface, LONG numberOfBytes)
{
    FIXME("(%i): stub!\n", numberOfBytes);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetDirect3D(Direct3DDevice8 *iface, Direct3D8 **pD3D8)
{
    FIXME("(%p): stub!\n", pD3D8);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetDeviceCaps(Direct3DDevice8 *iface, D3DCAPS8 *caps)
{
    FIXME("(%p): stub!\n", caps);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetDisplayMode(Direct3DDevice8 *iface, D3DDISPLAYMODE *pMode)
{
    FIXME("(%p): stub!\n", pMode);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetCreationParameters(Direct3DDevice8 *iface,
        D3DDEVICE_CREATION_PARAMETERS *pCreationParams)
{
    FIXME("(%p): stub!\n", pCreationParams);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetCursorProperties(Direct3DDevice8 *iface,
        int xHotSpot, int yHotSpot, Direct3DSurface8 *cursorSurface)
{
    FIXME("(%i, %i, %p): stub!\n", xHotSpot, yHotSpot, cursorSurface);

    return E_NOTIMPL;
}

static void WINAPI direct3ddevice8_SetCursorPosition(Direct3DDevice8 *iface,
        int xScreenSpace, int yScreenSpace, D3DSCPFLAGS flags)
{
    FIXME("(%i, %i, %x): stub!\n", xScreenSpace, yScreenSpace, flags);
}

static LONG WINAPI direct3ddevice8_ShowCursor(Direct3DDevice8 *iface, LONG bShow)
{
    FIXME("(%i): stub!\n", bShow);

    return 0;
}

static HRESULT WINAPI direct3ddevice8_CreateAdditionalSwapChain(Direct3DDevice8 *iface,
        D3DPRESENT_PARAMETERS *presentationParameters, Direct3DSwapChain8 **ppSwapChain)
{
    FIXME("(%p, %p): stub!\n", presentationParameters, ppSwapChain);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_Reset(Direct3DDevice8 *iface, D3DPRESENT_PARAMETERS *presentationParameters)
{
    FIXME("(%p): stub!\n", presentationParameters);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_Present(Direct3DDevice8 *iface, void *pSourceRect, void *pDestRect,
        LONG hWndDestWindowOverride, void *pDirtyRegion)
{
    FIXME("(%p, %p, %i, %p): stub!\n", pSourceRect, pDestRect, hWndDestWindowOverride, pDirtyRegion);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetBackBuffer(Direct3DDevice8 *iface, LONG backBuffer,
        D3DBACKBUFFER_TYPE bufferType, Direct3DSurface8 **ppBackBuffer)
{
    FIXME("(%i, %x, %p): stub!\n", backBuffer, bufferType, ppBackBuffer);

    return E_NOTIMPL;
}

static D3DRASTER_STATUS* WINAPI direct3ddevice8_GetRasterStatus(Direct3DDevice8 *iface, D3DRASTER_STATUS *__ret)
{
    D3DRASTER_STATUS ret = {0};

    *__ret = ret;

    FIXME("(): stub!\n");

    return __ret;
}

static void WINAPI direct3ddevice8_SetGammaRamp(Direct3DDevice8 *iface, LONG dwFlags, D3DGAMMARAMP *pRamp)
{
    FIXME("(%i, %p): stub!\n", dwFlags, pRamp);
}

static void WINAPI direct3ddevice8_GetGammaRamp(Direct3DDevice8 *iface, D3DGAMMARAMP *pRamp)
{
    FIXME("(%p): stub!\n", pRamp);
}

static HRESULT WINAPI direct3ddevice8_CreateTexture(Direct3DDevice8 *iface, int width, int height,
        int levels, LONG usage, D3DFORMAT format, D3DPOOL pool, Direct3DTexture8 **ppMipMap)
{
    FIXME("(%i, %i, %i, %i, %x, %x, %p): stub!\n", width, height, levels, usage, format, pool, ppMipMap);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CreateVolumeTexture(Direct3DDevice8 *iface, int width, int height, int depth,
        int levels, LONG usage, D3DFORMAT format, D3DPOOL pool, Direct3DVolumeTexture8 **ppMipMap)
{
    FIXME("(%i, %i, %i, %i, %i, %x, %x, %p): stub!\n", width, height, depth, levels, usage, format, pool, ppMipMap);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CreateCubeTexture(Direct3DDevice8 *iface, int edgeLength, int levels,
        LONG usage, D3DFORMAT format, D3DPOOL pool, Direct3DCubeTexture8 **ppCubeMap)
{
    FIXME("(%i, %i, %i, %x, %x, %p): stub!\n", edgeLength, levels, usage, format, pool, ppCubeMap);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CreateVertexBuffer(Direct3DDevice8 *iface, int lengthInBytes, LONG usage,
        LONG fvf, D3DPOOL pool, Direct3DVertexBuffer8 **ppVertexBuffer)
{
    FIXME("(%i, %i, %i, %x, %p): stub!\n", lengthInBytes, usage, fvf, pool, ppVertexBuffer);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CreateIndexBuffer(Direct3DDevice8 *iface, int lengthInBytes, LONG usage,
        D3DFORMAT format, D3DPOOL pool, Direct3DIndexBuffer8 **ppIndexBuffer)
{
    FIXME("(%i, %i, %x, %x, %p): stub!\n", lengthInBytes, usage, format, pool, ppIndexBuffer);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CreateRenderTarget(Direct3DDevice8 *iface, int width, int height,
        D3DFORMAT format, D3DMULTISAMPLE_TYPE multiSample, LONG lockable, Direct3DSurface8 **ppSurface)
{
    FIXME("(%i, %i, %x, %x, %i, %p): stub!\n", width, height, format, multiSample, lockable, ppSurface);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CreateDepthStencilSurface(Direct3DDevice8 *iface, int width, int height,
        D3DFORMAT format, D3DMULTISAMPLE_TYPE multiSample, Direct3DSurface8 **ppSurface)
{
    FIXME("(%i, %i, %x, %x, %p): stub!\n", width, height, format, multiSample, ppSurface);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CreateImageSurface(Direct3DDevice8 *iface, int width, int height,
        D3DFORMAT format, Direct3DSurface8 **ppSurface)
{
    FIXME("(%i, %i, %x, %p): stub!\n", width, height, format, ppSurface);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CopyRects(Direct3DDevice8 *iface, Direct3DSurface8 *sourceSurface,
        void *firstElementOfSourceRectsArray, int numberOfRects, Direct3DSurface8 *destinationSurface,
        void *firstElementofDestPointArray)
{
    FIXME("(%p, %p, %i, %p, %p): stub!\n", sourceSurface, firstElementOfSourceRectsArray, numberOfRects,
            destinationSurface, firstElementofDestPointArray);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_UpdateTexture(Direct3DDevice8 *iface, Direct3DBaseTexture8 *sourceTexture,
        Direct3DBaseTexture8 *pDestinationTexture)
{
    FIXME("(%p, %p): stub!\n", sourceTexture, pDestinationTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetFrontBuffer(Direct3DDevice8 *iface, Direct3DSurface8 *pDestSurface)
{
    FIXME("(%p): stub!\n", pDestSurface);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetRenderTarget(Direct3DDevice8 *iface, Direct3DSurface8 *renderTarget,
        Direct3DSurface8 *newZStencil, LONG flags)
{
    FIXME("(%p, %p, %i): stub!\n", renderTarget, newZStencil, flags);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetRenderTarget(Direct3DDevice8 *iface, Direct3DSurface8 **ppRenderTarget)
{
    FIXME("(%p): stub!\n", ppRenderTarget);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetDepthStencilSurface(Direct3DDevice8 *iface, Direct3DSurface8 **zStencilSurface)
{
    FIXME("(%p): stub!\n", zStencilSurface);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_BeginScene(Direct3DDevice8 *iface)
{
    FIXME("(): stub!\n");

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_EndScene(Direct3DDevice8 *iface)
{
    FIXME("(): stub!\n");

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_Clear(Direct3DDevice8 *iface, LONG clearRectCount, void *clearD3DRect,
        D3DCLEARFLAGS flags, LONG color, float z, LONG stencil)
{
    FIXME("(%i, %p, %x, %i, %f, %i): stub!\n", clearRectCount, clearD3DRect, flags, color, z, stencil);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetTransform(Direct3DDevice8 *iface,
        D3DTRANSFORMSTATETYPE transformType, D3DMATRIX *matrix)
{
    FIXME("(%x, %p): stub!\n", transformType, matrix);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetTransform(Direct3DDevice8 *iface,
        D3DTRANSFORMSTATETYPE transformType, D3DMATRIX *matrix)
{
    FIXME("(%x, %p): stub!\n", transformType, matrix);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_MultiplyTransform(Direct3DDevice8 *iface,
        D3DTRANSFORMSTATETYPE transformType, D3DMATRIX *matrix)
{
    FIXME("(%x, %p): stub!\n", transformType, matrix);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetViewport(Direct3DDevice8 *iface, D3DVIEWPORT8 *viewport)
{
    FIXME("(%p): stub!\n", viewport);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetViewport(Direct3DDevice8 *iface, D3DVIEWPORT8 *viewport)
{
    FIXME("(%p): stub!\n", viewport);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetMaterial(Direct3DDevice8 *iface, D3DMATERIAL8 *material)
{
    FIXME("(%p): stub!\n", material);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetMaterial(Direct3DDevice8 *iface, D3DMATERIAL8 *material)
{
    FIXME("(%p): stub!\n", material);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetLight(Direct3DDevice8 *iface, LONG index, D3DLIGHT8 *light)
{
    FIXME("(%i, %p): stub!\n", index, light);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetLight(Direct3DDevice8 *iface, LONG index, D3DLIGHT8 *light)
{
    FIXME("(%i, %p): stub!\n", index, light);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_LightEnable(Direct3DDevice8 *iface, LONG index, LONG enabled)
{
    FIXME("(%i, %i): stub!\n", index, enabled);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetLightEnable(Direct3DDevice8 *iface, LONG index, LONG *enabled)
{
    FIXME("(%i, %p): stub!\n", index, enabled);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetClipPlane(Direct3DDevice8 *iface, LONG index, D3DPLANE *plane)
{
    FIXME("(%i, %p): stub!\n", index, plane);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetClipPlane(Direct3DDevice8 *iface, LONG index, D3DPLANE *plane)
{
    FIXME("(%i, %p): stub!\n", index, plane);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetRenderState(Direct3DDevice8 *iface, D3DRENDERSTATETYPE stateType, LONG value)
{
    FIXME("(%i, %i): stub!\n", stateType, value);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetRenderState(Direct3DDevice8 *iface, D3DRENDERSTATETYPE stateType, LONG *value)
{
    FIXME("(%i, %p): stub!\n", stateType, value);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_BeginStateBlock(Direct3DDevice8 *iface)
{
    FIXME("(): stub!\n");

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_EndStateBlock(Direct3DDevice8 *iface, LONG *blockid)
{
    FIXME("(%p): stub!\n", blockid);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_ApplyStateBlock(Direct3DDevice8 *iface, LONG blockid)
{
    FIXME("(%i): stub!\n", blockid);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CaptureStateBlock(Direct3DDevice8 *iface, LONG blockid)
{
    FIXME("(%i): stub!\n", blockid);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_DeleteStateBlock(Direct3DDevice8 *iface, LONG blockid)
{
    FIXME("(%i): stub!\n", blockid);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CreateStateBlock(Direct3DDevice8 *iface,
        D3DSTATEBLOCKTYPE blocktype, LONG *blockid)
{
    FIXME("(%x, %p): stub!\n", blocktype, blockid);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetClipStatus(Direct3DDevice8 *iface, D3DCLIPSTATUS8 *clipstatus)
{
    FIXME("(%p): stub!\n", clipstatus);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetClipStatus(Direct3DDevice8 *iface, D3DCLIPSTATUS8 *clipstatus)
{
    FIXME("(%p): stub!\n", clipstatus);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetTexture(Direct3DDevice8 *iface, LONG stage, Direct3DBaseTexture8 **texture)
{
    FIXME("(%i, %p): stub!\n", stage, texture);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetTexture(Direct3DDevice8 *iface, LONG stage, Direct3DBaseTexture8 *texture)
{
    FIXME("(%i, %p): stub!\n", stage, texture);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetTextureStageState(Direct3DDevice8 *iface, LONG stage,
        D3DTEXTURESTAGESTATETYPE stateType, LONG *state)
{
    FIXME("(%i, %x, %p): stub!\n", stage, stateType, state);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetTextureStageState(Direct3DDevice8 *iface, LONG stage,
        D3DTEXTURESTAGESTATETYPE stateType, LONG state)
{
    FIXME("(%i, %x, %i): stub!\n", stage, stateType, state);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_ValidateDevice(Direct3DDevice8 *iface, LONG *ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetInfo(Direct3DDevice8 *iface, LONG flags, void *info, LONG size)
{
    FIXME("(%i, %p, %i): stub!\n", flags, info, size);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetPaletteEntries(Direct3DDevice8 *iface, int paletteNumber, void *arrayOfEntries)
{
    FIXME("(%i, %p): stub!\n", paletteNumber, arrayOfEntries);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetPaletteEntries(Direct3DDevice8 *iface, int paletteNumber, void *arrayOfEntries)
{
    FIXME("(%i, %p): stub!\n", paletteNumber, arrayOfEntries);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetCurrentTexturePalette(Direct3DDevice8 *iface, int paletteNumber)
{
    FIXME("(%i): stub!\n", paletteNumber);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetCurrentTexturePalette(Direct3DDevice8 *iface, int *paletteNumber)
{
    FIXME("(%p): stub!\n", paletteNumber);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_DrawPrimitive(Direct3DDevice8 *iface, D3DPRIMITIVETYPE primitiveType,
        int startVertex, int primitiveCount)
{
    FIXME("(%x, %i, %i): stub!\n", primitiveType, startVertex, primitiveCount);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_DrawIndexedPrimitive(Direct3DDevice8 *iface, D3DPRIMITIVETYPE primitiveType,
        int minIndex, int numIndices, int startIndex, int primitiveCount)
{
    FIXME("(%x, %i, %i, %i, %i): stub!\n", primitiveType, minIndex, numIndices, startIndex, primitiveCount);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_DrawPrimitiveUP(Direct3DDevice8 *iface, D3DPRIMITIVETYPE primitiveType,
        int primitiveCount, void *vertexStreamZeroDataArray, int vertexStreamZeroStride)
{
    FIXME("(%x, %i, %p, %i): stub!\n", primitiveType, primitiveCount,
            vertexStreamZeroDataArray,vertexStreamZeroStride);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_DrawIndexedPrimitiveUP(Direct3DDevice8 *iface, D3DPRIMITIVETYPE primitiveType,
        int minVertexIndex, int numVertexIndices, int primitiveCount, void *IndexDataArray, D3DFORMAT indexDataFormat,
        void *vertexStreamZeroDataArray, int vertexStreamZeroStride)
{
    FIXME("(%x, %i, %i, %i, %p, %x, %p, %i): stub!\n", primitiveType, minVertexIndex, numVertexIndices,primitiveCount,
            IndexDataArray, indexDataFormat, vertexStreamZeroDataArray, vertexStreamZeroStride);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_ProcessVertices(Direct3DDevice8 *iface, int srcStartIndex, int destIndex,
        int vertexCount, Direct3DVertexBuffer8 *destBuffer, LONG flags)
{
    FIXME("(%i, %i, %i, %p, %i): stub!\n", srcStartIndex, destIndex, vertexCount, destBuffer, flags);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CreateVertexShader(Direct3DDevice8 *iface, LONG *declarationTokenArray,
        void *functionTokenArray, LONG *retHandle, LONG usage)
{
    FIXME("(%p, %p, %p, %i): stub!\n", declarationTokenArray, functionTokenArray, retHandle, usage);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetVertexShader(Direct3DDevice8 *iface, LONG vertexShaderHandle)
{
    FIXME("(%i): stub!\n", vertexShaderHandle);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetVertexShader(Direct3DDevice8 *iface, LONG *pdwHandle)
{
    FIXME("(%p): stub!\n", pdwHandle);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_DeleteVertexShader(Direct3DDevice8 *iface, LONG vertexShaderHandle)
{
    FIXME("(%i): stub!\n", vertexShaderHandle);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetVertexShaderConstant(Direct3DDevice8 *iface, LONG startRegister,
        void *pConstantData, LONG constantCount)
{
    FIXME("(%i, %p, %i): stub!\n", startRegister, pConstantData, constantCount);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetVertexShaderConstant(Direct3DDevice8 *iface, LONG startRegister,
        void *pConstantData, LONG constantCount)
{
     FIXME("(%i, %p, %i): stub!\n", startRegister, pConstantData, constantCount);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetVertexShaderDeclaration(Direct3DDevice8 *iface, LONG handle,
        void *data, LONG *sizeOfData)
{
    FIXME("(%i, %p, %p): stub!\n", handle, data, sizeOfData);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetVertexShaderFunction(Direct3DDevice8 *iface, LONG handle,
        void *pData, LONG *sizeOfData)
{
    FIXME("(%i, %p, %p): stub!\n", handle, pData, sizeOfData);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetStreamSource(Direct3DDevice8 *iface, int streamNumber,
        Direct3DVertexBuffer8 *streamData, int stride)
{
    FIXME("(%i, %p, %i): stub!\n", streamNumber, streamData, stride);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetStreamSource(Direct3DDevice8 *iface, int streamNumber,
        Direct3DVertexBuffer8 **retStreamData, int *retStride)
{
    FIXME("(%i, %p, %p): stub!\n", streamNumber, retStreamData, retStride);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetIndices(Direct3DDevice8 *iface,
        Direct3DIndexBuffer8 *indexData, int baseVertexIndex)
{
    FIXME("(%p, %i): stub!\n", indexData, baseVertexIndex);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetIndices(Direct3DDevice8 *iface,
        Direct3DIndexBuffer8 **retIndexData, int *retBaseVertexIndex)
{
    FIXME("(%p, %p): stub!\n", retIndexData, retBaseVertexIndex);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_CreatePixelShader(Direct3DDevice8 *iface,
        LONG *functionTokenArray, LONG *pdwHandle)
{
    FIXME("(%p, %p): stub!\n", functionTokenArray, pdwHandle);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetPixelShader(Direct3DDevice8 *iface, LONG pixelShaderHandle)
{
    FIXME("(%i): stub!\n", pixelShaderHandle);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetPixelShader(Direct3DDevice8 *iface, LONG *pdwHandle)
{
    FIXME("(%p): stub!\n", pdwHandle);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_DeletePixelShader(Direct3DDevice8 *iface, LONG pixelShaderHandle)
{
    FIXME("(%i): stub!\n", pixelShaderHandle);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_SetPixelShaderConstant(Direct3DDevice8 *iface, LONG startRegister,
        void *pConstantData, LONG constantCount)
{
    FIXME("(%i, %p, %i): stub!\n", startRegister, pConstantData, constantCount);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetPixelShaderConstant(Direct3DDevice8 *iface, LONG startRegister,
        void *pConstantData, LONG constantCount)
{
    FIXME("(%i, %p, %i): stub!\n", startRegister, pConstantData, constantCount);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_GetPixelShaderFunction(Direct3DDevice8 *iface, LONG handle,
        void *pData, LONG *sizeOfData)
{
    FIXME("(%i, %p, %p): stub!\n", handle, pData, sizeOfData);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_DrawRectPatch(Direct3DDevice8 *iface, LONG handle, float *numSegments, void *surf)
{
    FIXME("(%i, %p, %p): stub!\n", handle, numSegments, surf);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_DrawTriPatch(Direct3DDevice8 *iface, LONG handle, float *numSegments, void *surf)
{
    FIXME("(%i, %p, %p): stub!\n", handle, numSegments, surf);

    return E_NOTIMPL;
}

static HRESULT WINAPI direct3ddevice8_DeletePatch(Direct3DDevice8 *iface, LONG handle)
{
    FIXME("(%i): stub!\n", handle);

    return E_NOTIMPL;
}

static const Direct3DDevice8Vtbl Direct3DDevice8_Vtbl =
{
    /*** IUnknown methods ***/
    direct3ddevice8_QueryInterface,
    direct3ddevice8_AddRef,
    direct3ddevice8_Release,
    /*** Direct3DDevice8 methods ***/
    direct3ddevice8_TestCooperativeLevel,
    direct3ddevice8_GetAvailableTextureMem,
    direct3ddevice8_ResourceManagerDiscardBytes,
    direct3ddevice8_GetDirect3D,
    direct3ddevice8_GetDeviceCaps,
    direct3ddevice8_GetDisplayMode,
    direct3ddevice8_GetCreationParameters,
    direct3ddevice8_SetCursorProperties,
    direct3ddevice8_SetCursorPosition,
    direct3ddevice8_ShowCursor,
    direct3ddevice8_CreateAdditionalSwapChain,
    direct3ddevice8_Reset,
    direct3ddevice8_Present,
    direct3ddevice8_GetBackBuffer,
    direct3ddevice8_GetRasterStatus,
    direct3ddevice8_SetGammaRamp,
    direct3ddevice8_GetGammaRamp,
    direct3ddevice8_CreateTexture,
    direct3ddevice8_CreateVolumeTexture,
    direct3ddevice8_CreateCubeTexture,
    direct3ddevice8_CreateVertexBuffer,
    direct3ddevice8_CreateIndexBuffer,
    direct3ddevice8_CreateRenderTarget,
    direct3ddevice8_CreateDepthStencilSurface,
    direct3ddevice8_CreateImageSurface,
    direct3ddevice8_CopyRects,
    direct3ddevice8_UpdateTexture,
    direct3ddevice8_GetFrontBuffer,
    direct3ddevice8_SetRenderTarget,
    direct3ddevice8_GetRenderTarget,
    direct3ddevice8_GetDepthStencilSurface,
    direct3ddevice8_BeginScene,
    direct3ddevice8_EndScene,
    direct3ddevice8_Clear,
    direct3ddevice8_SetTransform,
    direct3ddevice8_GetTransform,
    direct3ddevice8_MultiplyTransform,
    direct3ddevice8_SetViewport,
    direct3ddevice8_GetViewport,
    direct3ddevice8_SetMaterial,
    direct3ddevice8_GetMaterial,
    direct3ddevice8_SetLight,
    direct3ddevice8_GetLight,
    direct3ddevice8_LightEnable,
    direct3ddevice8_GetLightEnable,
    direct3ddevice8_SetClipPlane,
    direct3ddevice8_GetClipPlane,
    direct3ddevice8_SetRenderState,
    direct3ddevice8_GetRenderState,
    direct3ddevice8_BeginStateBlock,
    direct3ddevice8_EndStateBlock,
    direct3ddevice8_ApplyStateBlock,
    direct3ddevice8_CaptureStateBlock,
    direct3ddevice8_DeleteStateBlock,
    direct3ddevice8_CreateStateBlock,
    direct3ddevice8_SetClipStatus,
    direct3ddevice8_GetClipStatus,
    direct3ddevice8_GetTexture,
    direct3ddevice8_SetTexture,
    direct3ddevice8_GetTextureStageState,
    direct3ddevice8_SetTextureStageState,
    direct3ddevice8_ValidateDevice,
    direct3ddevice8_GetInfo,
    direct3ddevice8_SetPaletteEntries,
    direct3ddevice8_GetPaletteEntries,
    direct3ddevice8_SetCurrentTexturePalette,
    direct3ddevice8_GetCurrentTexturePalette,
    direct3ddevice8_DrawPrimitive,
    direct3ddevice8_DrawIndexedPrimitive,
    direct3ddevice8_DrawPrimitiveUP,
    direct3ddevice8_DrawIndexedPrimitiveUP,
    direct3ddevice8_ProcessVertices,
    direct3ddevice8_CreateVertexShader,
    direct3ddevice8_SetVertexShader,
    direct3ddevice8_GetVertexShader,
    direct3ddevice8_DeleteVertexShader,
    direct3ddevice8_SetVertexShaderConstant,
    direct3ddevice8_GetVertexShaderConstant,
    direct3ddevice8_GetVertexShaderDeclaration,
    direct3ddevice8_GetVertexShaderFunction,
    direct3ddevice8_SetStreamSource,
    direct3ddevice8_GetStreamSource,
    direct3ddevice8_SetIndices,
    direct3ddevice8_GetIndices,
    direct3ddevice8_CreatePixelShader,
    direct3ddevice8_SetPixelShader,
    direct3ddevice8_GetPixelShader,
    direct3ddevice8_DeletePixelShader,
    direct3ddevice8_SetPixelShaderConstant,
    direct3ddevice8_GetPixelShaderConstant,
    direct3ddevice8_GetPixelShaderFunction,
    direct3ddevice8_DrawRectPatch,
    direct3ddevice8_DrawTriPatch,
    direct3ddevice8_DeletePatch
};

HRESULT direct3ddevice8_create(Direct3DDevice8 **ppv, IDirect3DDevice8 *device)
{
    direct3ddevice8 *object;

    TRACE("(%p, %p)\n", ppv, device);

    *ppv = NULL;
    object = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(direct3ddevice8));
    if (!object)
        return E_OUTOFMEMORY;

    object->Direct3DDevice8_iface.lpVtbl = &Direct3DDevice8_Vtbl;
    object->ref = 1;
    object->direct3ddevice8 = device;

    *ppv = &object->Direct3DDevice8_iface;

    return S_OK;
}

/*** direct3d8 - IUnknown methods ***/

static HRESULT WINAPI direct3d8_QueryInterface(Direct3D8 *iface, REFIID riid, void **ppv)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    TRACE("(%p/%p)->(%s,%p)\n", iface, This, debugstr_guid(riid), ppv);

    *ppv = NULL;

    if (IsEqualGUID(riid, &IID_IUnknown))
        *ppv = &This->Direct3D8_iface;
    else if(IsEqualGUID(riid, &IID_Direct3D8))
        *ppv = &This->Direct3D8_iface;
    else if(IsEqualGUID(riid, &IID_ISupportErrorInfo))
        FIXME("No interface for IID_ISupportErrorInfo\n");
    else
        FIXME("No interface for %s\n", debugstr_guid(riid));

    if (*ppv)
    {
        IUnknown_AddRef((IUnknown *)(*ppv));
        return S_OK;
    }

    return E_NOINTERFACE;
}

static ULONG WINAPI direct3d8_AddRef(Direct3D8 *iface)
{
    direct3d8 *This = impl_from_Direct3D8(iface);
    ULONG ref = InterlockedIncrement(&This->ref);

    TRACE("(%p/%p)->(): new ref %d\n", iface, This, ref);

    return ref;
}

static ULONG WINAPI direct3d8_Release(Direct3D8 *iface)
{
    direct3d8 *This = impl_from_Direct3D8(iface);
    ULONG ref = InterlockedDecrement(&This->ref);

    TRACE("(%p/%p)->(): new ref %d\n", iface, This, ref);

    if (!ref)
    {
        IDirect3D8_Release(This->direct3d8);
        HeapFree(GetProcessHeap(), 0, This);
    }

    return ref;
}

/*** direct3d8 - Direct3D8 methods ***/

static HRESULT WINAPI direct3d8_RegisterSoftwareDevice(Direct3D8 *iface, void *initializeFunction)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    HRESULT ret = IDirect3D8_RegisterSoftwareDevice(This->direct3d8, initializeFunction);

    FIXME("(%p) -> (%x)\n", initializeFunction, ret);

    return ret;
}

static int WINAPI direct3d8_GetAdapterCount(Direct3D8 *iface)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    int ret = IDirect3D8_GetAdapterCount(This->direct3d8);

    FIXME("() -> (%i)\n", ret);

    return ret;
}

static HRESULT WINAPI direct3d8_GetAdapterIdentifier(Direct3D8 *iface, int adapter,
        LONG flags, D3DADAPTER_IDENTIFIER8 *identifier)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    HRESULT ret = IDirect3D8_GetAdapterIdentifier(This->direct3d8, adapter, flags, identifier);

    FIXME("(%i, %i, %p) -> (%x)\n", adapter, flags, identifier, ret);

    return ret;
}

static int WINAPI direct3d8_GetAdapterModeCount(Direct3D8 *iface, int adapter)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    int ret = IDirect3D8_GetAdapterModeCount(This->direct3d8, adapter);

    FIXME("(%i) -> (%i)\n", adapter, ret);

    return ret;
}

static HRESULT WINAPI direct3d8_EnumAdapterModes(Direct3D8 *iface, int adapter, int mode, D3DDISPLAYMODE *displayMode)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    HRESULT ret = IDirect3D8_EnumAdapterModes(This->direct3d8, adapter, mode, displayMode);

    FIXME("(%i, %i, %p) -> (%x)\n", adapter, mode, displayMode, ret);

    return ret;
}

static HRESULT WINAPI direct3d8_GetAdapterDisplayMode(Direct3D8 *iface, int adapter, D3DDISPLAYMODE *displayMode)
{
    direct3d8 *This = impl_from_Direct3D8(iface);
    HRESULT ret;

    ret = IDirect3D8_GetAdapterDisplayMode(This->direct3d8, adapter, displayMode);

    TRACE("(%i, %p) -> (%x)\n", adapter, displayMode, ret);

    return ret;
}

static LONG WINAPI direct3d8_CheckDeviceType(Direct3D8 *iface, int adapter, D3DDEVTYPE checkType,
        D3DFORMAT displayFormat, D3DFORMAT backBufferFormat, LONG bWindowed)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    LONG ret = IDirect3D8_CheckDeviceType(This->direct3d8, adapter, checkType,
            displayFormat, backBufferFormat, bWindowed);

    FIXME("(%i, %u, %u, %u, %i) -> (%i)\n", adapter, checkType, displayFormat, backBufferFormat, bWindowed, ret);

    return ret;
}

static LONG WINAPI direct3d8_CheckDeviceFormat(Direct3D8 *iface, int adapter, D3DDEVTYPE deviceType,
        D3DFORMAT adapterFormat, LONG usage, D3DRESOURCETYPE rType, D3DFORMAT checkFormat)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    LONG ret = IDirect3D8_CheckDeviceFormat(This->direct3d8, adapter, deviceType,
            adapterFormat, usage, rType, checkFormat);

    FIXME("(%i, %u, %u, %i, %u, %u) -> (%i)\n", adapter, deviceType, adapterFormat, usage, rType, checkFormat, ret);

    return ret;
}

static LONG WINAPI direct3d8_CheckDeviceMultiSampleType(Direct3D8 *iface, int adapter, D3DDEVTYPE deviceType,
        D3DFORMAT renderTargetFormat, LONG windowed, D3DMULTISAMPLE_TYPE multiSampleType)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    LONG ret = IDirect3D8_CheckDeviceMultiSampleType(This->direct3d8, adapter, deviceType,
            renderTargetFormat, windowed, multiSampleType);

    FIXME("(%i, %u, %u, %i, %u) -> (%i)\n", adapter, deviceType, renderTargetFormat, windowed, multiSampleType, ret);

    return ret;
}

static LONG WINAPI direct3d8_CheckDepthStencilMatch(Direct3D8 *iface, int adapter, D3DDEVTYPE deviceType,
        D3DFORMAT adapterFormat, D3DFORMAT renderTargetFormat, D3DFORMAT depthStencilFormat)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    LONG ret = IDirect3D8_CheckDepthStencilMatch(This->direct3d8, adapter, deviceType, adapterFormat,
            renderTargetFormat, depthStencilFormat);

    TRACE("(%i, %u, %u, %u, %u) ->(%i)\n", adapter, deviceType, adapterFormat,
            renderTargetFormat, depthStencilFormat, ret);

    return ret;
}

static HRESULT WINAPI direct3d8_GetDeviceCaps(Direct3D8 *iface, int adapter, D3DDEVTYPE deviceType, D3DCAPS8 *caps)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    HRESULT ret = IDirect3D8_GetDeviceCaps(This->direct3d8, adapter, deviceType, caps);

    TRACE("(%i, %u, %p) -> (%x)\n", adapter, deviceType, caps, ret);

    return ret;
}

static LONG WINAPI direct3d8_GetAdapterMonitor(Direct3D8 *iface, int adapter)
{
    direct3d8 *This = impl_from_Direct3D8(iface);

    LONG ret = (LONG)IDirect3D8_GetAdapterMonitor(This->direct3d8, adapter);

    TRACE("(%i) -> (%i)!\n", adapter, ret);

    return ret;
}

static HRESULT WINAPI direct3d8_CreateDevice(Direct3D8 *iface, int adapter, D3DDEVTYPE deviceType, HWND hFocusWindow,
        D3DCREATEFLAGS behaviorFlags, D3DPRESENT_PARAMETERS *presentationParameters,
        Direct3DDevice8 **ppReturnedDeviceInterface)
{
    direct3d8 *This = impl_from_Direct3D8(iface);
    HRESULT ret;
    IDirect3DDevice8 *device;

    ret = IDirect3D8_CreateDevice(This->direct3d8, adapter, deviceType, hFocusWindow, behaviorFlags,
            presentationParameters, &device);
    ret = direct3ddevice8_create(ppReturnedDeviceInterface, device);

    TRACE("(%i, %u, %p, %u, %p, %p) -> (%x)\n", adapter, deviceType, hFocusWindow, behaviorFlags,
            presentationParameters, ppReturnedDeviceInterface, ret);

    return ret;
}

static const Direct3D8Vtbl Direct3D8_Vtbl =
{
    /*** IUnknown methods ***/
    direct3d8_QueryInterface,
    direct3d8_AddRef,
    direct3d8_Release,
    /*** Direct3D8 methods ***/
    direct3d8_RegisterSoftwareDevice,
    direct3d8_GetAdapterCount,
    direct3d8_GetAdapterIdentifier,
    direct3d8_GetAdapterModeCount,
    direct3d8_EnumAdapterModes,
    direct3d8_GetAdapterDisplayMode,
    direct3d8_CheckDeviceType,
    direct3d8_CheckDeviceFormat,
    direct3d8_CheckDeviceMultiSampleType,
    direct3d8_CheckDepthStencilMatch,
    direct3d8_GetDeviceCaps,
    direct3d8_GetAdapterMonitor,
    direct3d8_CreateDevice
};

HRESULT direct3d8_create(Direct3D8 **ppv)
{
    direct3d8 *object;

    TRACE("(%p)\n", ppv);

    object = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(direct3d8));
    if (!object)
        return E_OUTOFMEMORY;

    object->Direct3D8_iface.lpVtbl = &Direct3D8_Vtbl;
    object->ref = 1;
    object->direct3d8 = Direct3DCreate8(D3D_SDK_VERSION);
    if(!object->direct3d8)
        ERR("Can't create D3D8 object\n");

    *ppv = &object->Direct3D8_iface;

    return S_OK;
}

/*** directx8 - IUnknown methods ***/

static HRESULT WINAPI directx8_QueryInterface(IDirectX8 *iface, REFIID riid, void **ppv)
{
    directx8 *This = impl_from_IDirectX8(iface);

    TRACE("(%p/%p)->(%s,%p)\n", iface, This, debugstr_guid(riid), ppv);

    *ppv = NULL;

    if (IsEqualGUID(riid, &IID_IUnknown))
        *ppv = &This->IDirectX8_iface;
    else if(IsEqualGUID(riid, &IID_IDirectX8))
        *ppv = &This->IDirectX8_iface;
    else if(IsEqualGUID(riid, &IID_IPersistPropertyBag))
        FIXME("No interface for IID_IPersistPropertyBag\n");
    else if(IsEqualGUID(riid, &IID_IPersistStreamInit))
        FIXME("No interface for IID_IPersistStreamInit\n");
    else if(IsEqualGUID(riid, &IID_ISupportErrorInfo))
        FIXME("No interface for IID_ISupportErrorInfo\n");
    else
        FIXME("No interface for %s\n", debugstr_guid(riid));

    if (*ppv)
    {
        IUnknown_AddRef((IUnknown *)(*ppv));
        return S_OK;
    }

    return E_NOINTERFACE;
}

static ULONG WINAPI directx8_AddRef(IDirectX8 *iface)
{
    directx8 *This = impl_from_IDirectX8(iface);
    ULONG ref = InterlockedIncrement(&This->ref);

    TRACE("(%p/%p)->(): new ref %d\n", iface, This, ref);

    return ref;
}

static ULONG WINAPI directx8_Release(IDirectX8 *iface)
{
    directx8 *This = impl_from_IDirectX8(iface);
    ULONG ref = InterlockedDecrement(&This->ref);

    TRACE("(%p/%p)->(): new ref %d\n", iface, This, ref);

    if (!ref)
        HeapFree(GetProcessHeap(), 0, This);

    return ref;
}

/*** directx8 - IDirectX8 methods ***/

static HRESULT WINAPI directx8_DirectSoundCreate(IDirectX8 *iface, BSTR guid, DirectSound8 **ret)
{
    FIXME("(%p, %p): stub!\n", guid, ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectSoundCaptureCreate(IDirectX8 *iface, BSTR guid, DirectSoundCapture8 **ret)
{
    FIXME("(%p, %p): stub!\n", guid, ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_GetDSEnum(IDirectX8 *iface, DirectSoundEnum8 **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_GetDSCaptureEnum(IDirectX8 *iface, DirectSoundEnum8 **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectInputCreate(IDirectX8 *iface, DirectInput8 **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectMusicLoaderCreate(IDirectX8 *iface, DirectMusicLoader8 **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectMusicComposerCreate(IDirectX8 *iface, DirectMusicComposer8 **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectMusicPerformanceCreate(IDirectX8 *iface, DirectMusicPerformance8 **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_CreateEvent(IDirectX8 *iface, DirectXEvent8 *event, LONG *h)
{
    FIXME("(%p, %p): stub!\n", event, h);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_SetEvent(IDirectX8 *iface, LONG eventid)
{
    FIXME("(%i): stub!\n", eventid);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DestroyEvent(IDirectX8 *iface, LONG eventid)
{
    FIXME("(%i): stub!\n", eventid);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_CreateNewGuid(IDirectX8 *iface, BSTR *retGuid)
{
    FIXME("(%p): stub!\n", retGuid);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectPlayVoiceClientCreate(IDirectX8 *iface, DirectPlayVoiceClient8 **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectPlayVoiceServerCreate(IDirectX8 *iface, DirectPlayVoiceServer8 **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectPlayVoiceTestCreate(IDirectX8 *iface, DirectPlayVoiceTest8 **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectXFileCreate(IDirectX8 *iface, DirectXFile **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectPlayPeerCreate(IDirectX8 *iface, DirectPlay8Peer **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectPlayServerCreate(IDirectX8 *iface, DirectPlay8Server **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectPlayClientCreate(IDirectX8 *iface, DirectPlay8Client **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectPlayAddressCreate(IDirectX8 *iface, DirectPlay8Address **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_Direct3DCreate(IDirectX8 *iface, Direct3D8 **ret)
{
    HRESULT res = direct3d8_create(ret);

    TRACE("(%p) -> (%x)\n", ret, res);

    return res;
}

static HRESULT WINAPI directx8_DirectPlayLobbyClientCreate(IDirectX8 *iface, DirectPlay8LobbyClient **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI directx8_DirectPlayLobbiedApplicationCreate(IDirectX8 *iface, DirectPlay8LobbiedApplication **ret)
{
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
}

static const IDirectX8Vtbl IDirectX8_Vtbl =
{
    /*** IUnknown methods ***/
    directx8_QueryInterface,
    directx8_AddRef,
    directx8_Release,
    /*** IDirectX8 methods ***/
    directx8_DirectSoundCreate,
    directx8_DirectSoundCaptureCreate,
    directx8_GetDSEnum,
    directx8_GetDSCaptureEnum,
    directx8_DirectInputCreate,
    directx8_DirectMusicLoaderCreate,
    directx8_DirectMusicComposerCreate,
    directx8_DirectMusicPerformanceCreate,
    directx8_CreateEvent,
    directx8_SetEvent,
    directx8_DestroyEvent,
    directx8_CreateNewGuid,
    directx8_DirectPlayVoiceClientCreate,
    directx8_DirectPlayVoiceServerCreate,
    directx8_DirectPlayVoiceTestCreate,
    directx8_DirectXFileCreate,
    directx8_DirectPlayPeerCreate,
    directx8_DirectPlayServerCreate,
    directx8_DirectPlayClientCreate,
    directx8_DirectPlayAddressCreate,
    directx8_Direct3DCreate,
    directx8_DirectPlayLobbyClientCreate,
    directx8_DirectPlayLobbiedApplicationCreate
};

HRESULT directx8_create(IUnknown *outer_unk, void **ppv)
{
    directx8 *object;

    TRACE("(%p,%p)\n", outer_unk, ppv);

    object = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(directx8));
    if (!object)
        return E_OUTOFMEMORY;

    object->IDirectX8_iface.lpVtbl = &IDirectX8_Vtbl;
    object->ref = 1;

    *ppv = &object->IDirectX8_iface;

    return S_OK;
}

