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
#include "ocidl.h"

#include "wine/debug.h"

WINE_DEFAULT_DEBUG_CHANNEL(dx8vb);

typedef struct
{
    ID3DX8 ID3DX8_iface;
    LONG ref;
} d3dx8;

static inline d3dx8 *impl_from_ID3DX8(ID3DX8 *iface)
{
    return CONTAINING_RECORD(iface, d3dx8, ID3DX8_iface);
}

/*** d3dx8 - IUnknown methods ***/

static HRESULT WINAPI d3dx8_QueryInterface(ID3DX8 *iface, REFIID riid, void **ppv)
{
    d3dx8 *This = impl_from_ID3DX8(iface);

    TRACE("(%p/%p)->(%s,%p)\n", iface, This, debugstr_guid(riid), ppv);

    *ppv = NULL;

    if (IsEqualGUID(riid, &IID_IUnknown))
        *ppv = &This->ID3DX8_iface;
    else if(IsEqualGUID(riid, &IID_ID3DX8))
        *ppv = &This->ID3DX8_iface;
    else if(IsEqualGUID(riid, &IID_IPersistPropertyBag))
        FIXME("No interface for IID_IPersistPropertyBag\n");
    else if(IsEqualGUID(riid, &IID_IPersistStreamInit))
        FIXME("No interface for IID_IPersistStreamInit\n");
    else
        FIXME("No interface for %s\n", debugstr_guid(riid));

    if (*ppv)
    {
        IUnknown_AddRef((IUnknown *)(*ppv));
        return S_OK;
    }

    return E_NOINTERFACE;
}

static ULONG WINAPI d3dx8_AddRef(ID3DX8 *iface)
{
    d3dx8 *This = impl_from_ID3DX8(iface);
    ULONG ref = InterlockedIncrement(&This->ref);

    TRACE("(%p/%p)->(): new ref %d\n", iface, This, ref);

    return ref;
}

static ULONG WINAPI d3dx8_Release(ID3DX8 *iface)
{
    d3dx8 *This = impl_from_ID3DX8(iface);
    ULONG ref = InterlockedDecrement(&This->ref);

    TRACE("(%p/%p)->(): new ref %d\n", iface, This, ref);

    if (!ref)
        HeapFree(GetProcessHeap(), 0, This);

    return ref;
}

/*** d3dx8 - ID3DX8 methods ***/

static HRESULT WINAPI d3dx8_CreateFont(ID3DX8 *iface, Direct3DDevice8 *device,
          LONG hFont, D3DXFont **retFont)
{
    FIXME("(%p, %i, %p): stub!\n", device, hFont, retFont);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_DrawText(ID3DX8 *iface, D3DXFont *d3dFont, LONG color, BSTR text, RECT *rect, LONG format)
{
    FIXME("(%p, %i, %s, %s, %i): stub!\n", d3dFont, color, debugstr_w(text), wine_dbgstr_rect(rect), format);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_GetFVFVertexSize(ID3DX8 *iface, LONG fvf, LONG *size)
{
    FIXME("(%i, %p): stub!\n", fvf, size);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_AssembleShaderFromFile(ID3DX8 *iface, BSTR file, LONG flags, BSTR *log,
        D3DXBuffer **constants, D3DXBuffer **ppVertexShader)
{
    FIXME("(%s, %i, %p, %p, %p): stub!\n", debugstr_w(file), flags, log, constants, ppVertexShader);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_AssembleShader(ID3DX8 *iface, BSTR data, LONG flags, D3DXBuffer **constants,
        BSTR *log, D3DXBuffer **ppVertexShader)
{
    FIXME("(%s, %i, %p, %p, %p): stub!\n", debugstr_w(data), flags, constants, log, ppVertexShader);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_GetErrorString(ID3DX8 *iface, LONG hr, BSTR *retStr)
{
    FIXME("(%i, %p): stub!\n", hr, retStr);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadSurfaceFromFile(ID3DX8 *iface, Direct3DSurface8 *destSurface, void *destPalette,
        void *destRect, BSTR srcFile, void *srcRect, LONG filter, LONG colorKey, void *srcInfo)
{
    FIXME("(%p, %p, %p, %s, %s, %i, %i, %p): stub!\n", destSurface, destPalette, destRect, debugstr_w(srcFile),
            wine_dbgstr_rect(srcRect), filter, colorKey, srcInfo);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadSurfaceFromFileInMemory(ID3DX8 *iface, Direct3DSurface8 *destSurface, void *destPalette,
        void *destRect, void *srcData, LONG lengthInBytes, void *srcRect, LONG filter, LONG colorKey, void *srcInfo)
{
   FIXME("(%p, %p, %p, %p, %i, %s, %i, %i, %p): stub!\n", destSurface, destPalette, destRect, srcData, lengthInBytes,
           wine_dbgstr_rect(srcRect), filter, colorKey, srcInfo);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadSurfaceFromSurface(ID3DX8 *iface, Direct3DSurface8 *destSurface, void *destPalette,
        void *destRect,Direct3DSurface8 *srcSurface, void *srcPalette, void *srcRect, LONG filter, LONG colorKey)
{
    FIXME("(%p, %p, %p, %p, %p, %s, %i, %i): stub!\n", destSurface, destPalette, destRect, srcSurface, srcPalette,
            wine_dbgstr_rect(srcRect), filter, colorKey);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadSurfaceFromMemory(ID3DX8 *iface, Direct3DSurface8 *destSurface, void *destPalette,
        void *destRect, void *srcData, D3DFORMAT formatSrc, LONG srcPitch, void *srcPalette, RECT *srcRect,
        LONG filter, LONG colorKey)
{
    FIXME("(%p, %p, %p, %p, %u, %i, %p, %s, %i, %i): stub!\n", destSurface, destPalette, destRect, srcData, formatSrc,
            srcPitch, srcPalette, wine_dbgstr_rect(srcRect), filter, colorKey);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CheckTextureRequirements(ID3DX8 *iface, Direct3DDevice8 *device, LONG *width, LONG *height,
        LONG *mipLevels, LONG usage, D3DFORMAT *pixelformat, D3DPOOL pool)
{
    FIXME("(%p, %p, %p, %p, %i, %p, %u): stub!\n", device, width, height, mipLevels, usage, pixelformat, pool);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateTexture(ID3DX8 *iface, Direct3DDevice8 *device, LONG width, LONG height,
        LONG mipLevels, LONG usage, D3DFORMAT pixelformat, D3DPOOL pool, Direct3DTexture8 **ppTexture)
{
    FIXME("(%p, %i, %i, %i, %i, %u, %u, %p): stub!\n", device, width, height, mipLevels, usage,
            pixelformat, pool, ppTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateTextureFromResource(ID3DX8 *iface, Direct3DDevice8 *device, LONG hModule,
        BSTR srcResource, Direct3DTexture8 **ppTexture)
{
    FIXME("(%p, %i, %s, %p): stub!\n", device, hModule, debugstr_w(srcResource), ppTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateTextureFromFile(ID3DX8 *iface, Direct3DDevice8 *device, BSTR srcFile,
        Direct3DTexture8 **ppTexture)
{
    FIXME("(%p, %s, %p): stub!\n", device, debugstr_w(srcFile), ppTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateTextureFromFileEx(ID3DX8 *iface, Direct3DDevice8 *device, BSTR srcFile, LONG width,
        LONG height, LONG mipLevels, LONG usage, D3DFORMAT pixelformat, D3DPOOL pool, LONG filter, LONG mipFilter,
        LONG colorKey, void *srcInfo, void *palette, Direct3DTexture8 **ppTexture)
{
    FIXME("(%p, %s, %i, %i, %i, %i, %u, %u, %i, %i, %i, %p, %p, %p): stub!\n", device, debugstr_w(srcFile), width,
            height, mipLevels, usage, pixelformat, pool, filter, mipFilter, colorKey, srcInfo, palette, ppTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateTextureFromFileInMemory(ID3DX8 *iface, Direct3DDevice8 *device, void *srcData,
        LONG lengthInBytes, Direct3DTexture8 **ppTexture)
{
    FIXME("(%p, %p, %i, %p): stub!\n", device, srcData, lengthInBytes, ppTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateTextureFromFileInMemoryEx(ID3DX8 *iface, Direct3DDevice8 *device, void *srcData,
        LONG lengthInBytes, LONG width, LONG height, LONG mipLevels, LONG usage, D3DFORMAT pixelformat, D3DPOOL pool,
        LONG filter, LONG mipFilter, LONG colorKey, void *srcInfo, void *palette, Direct3DTexture8 **ppTexture)
{
    FIXME("(%p, %p, %i, %i, %i, %i, %i, %u, %u, %i, %i, %i, %p, %p, %p): stub!\n", device, srcData, lengthInBytes,
            width, height, mipLevels, usage, pixelformat, pool, filter, mipFilter,
            colorKey, srcInfo, palette, ppTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_FilterTexture(ID3DX8 *iface, Direct3DTexture8 *texture, void *palette,
        LONG srcLevel, LONG filter)
{
    FIXME("(%p, %p, %i, %i): stub!\n", texture, palette, srcLevel, filter);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CheckCubeTextureRequirements(ID3DX8 *iface, Direct3DDevice8 *device,LONG *size,
        LONG *mipLevels, LONG usage, D3DFORMAT *pixelformat, D3DPOOL pool)
{
    FIXME("(%p, %p, %p, %i, %p, %u): stub!\n", device, size, mipLevels, usage, pixelformat, pool);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateCubeTexture(ID3DX8 *iface, Direct3DDevice8 *device, LONG size, LONG mipLevels,
        LONG usage, D3DFORMAT pixelformat, D3DPOOL pool, Direct3DCubeTexture8 **ppCubeTexture)
{
    FIXME("(%p, %i, %i, %i, %u, %u, %p): stub!\n", device, size, mipLevels, usage, pixelformat, pool, ppCubeTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateCubeTextureFromFile(ID3DX8 *iface, Direct3DDevice8 *device, BSTR srcFile,
        Direct3DCubeTexture8 **ppCubeTexture)
{
    FIXME("(%p, %s, %p): stub!\n", device, debugstr_w(srcFile), ppCubeTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateCubeTextureFromFileEx(ID3DX8 *iface, Direct3DDevice8 *device, BSTR srcFile,
        LONG textureSize, LONG mipLevels, LONG usage, D3DFORMAT pixelformat, D3DPOOL pool, LONG filter,
        LONG mipFilter, LONG colorKey, void *srcInfo, void *palette, Direct3DCubeTexture8 **ppTexture)
{
    FIXME("(%p, %s, %i, %i, %i, %u, %u, %i, %i, %i, %p, %p, %p): stub!\n", device, debugstr_w(srcFile),textureSize,
            mipLevels, usage, pixelformat, pool, filter, mipFilter, colorKey, srcInfo, palette, ppTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateCubeTextureFromFileInMemory(ID3DX8 *iface, Direct3DDevice8 *device, void *srcData,
        LONG lengthInBytes, Direct3DCubeTexture8 **ppTexture)
{
    FIXME("(%p, %p, %i, %p): stub!\n", device, srcData,lengthInBytes, ppTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateCubeTextureFromFileInMemoryEx(ID3DX8 *iface, Direct3DDevice8 *device, void *srcData,
        LONG lengthInBytes, LONG textureSize, LONG mipLevels, LONG usage, D3DFORMAT pixelformat, D3DPOOL pool,
        LONG filter, LONG mipFilter, LONG colorKey, void *srcInfo, void *palette, Direct3DCubeTexture8 **ppTexture)
{
    FIXME("(%p, %p, %i, %i, %i, %i, %u, %u, %i, %i, %i, %p, %p, %p): stub!\n", device, srcData, lengthInBytes,
            textureSize, mipLevels, usage, pixelformat, pool, filter, mipFilter, colorKey, srcInfo, palette, ppTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_FilterCubeTexture(ID3DX8 *iface, Direct3DCubeTexture8 *cubeTexture, void *palette,
        LONG srcLevel, LONG filter)
{
    FIXME("(%p, %p, %i, %i): stub!\n", cubeTexture, palette, srcLevel, filter);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CheckVolumeTextureRequirements(ID3DX8 *iface, Direct3DDevice8 *device, LONG *width,
        LONG *height, LONG *depth, LONG *mipLevels, LONG usage, D3DFORMAT *pixelformat, D3DPOOL pool)
{
    FIXME("(%p, %p, %p, %p, %p, %i, %p, %u): stub!\n", device, width, height, depth,
            mipLevels, usage, pixelformat, pool);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateTextureFromResourceEx(ID3DX8 *iface, Direct3DDevice8 *device, LONG hSrcModule,
        BSTR srcResource, LONG width, LONG height, LONG mipLevels, LONG usage, D3DFORMAT pixelformat, D3DPOOL pool,
        LONG filter, LONG mipFilter, LONG colorKey, void *srcInfo, void *palette, Direct3DTexture8 **retTexture)
{
    FIXME("(%p, %i, %s, %i, %i, %i, %i, %u, %u, %i, %i, %i, %p, %p, %p): stub!\n", device, hSrcModule,
            debugstr_w(srcResource), width, height, mipLevels, usage, pixelformat, pool, filter, mipFilter,
            colorKey, srcInfo, palette, retTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateVolumeTexture(ID3DX8 *iface, Direct3DDevice8 *device, LONG width, LONG height,
        LONG depth, LONG mipLevels, LONG usage, D3DFORMAT pixelformat, D3DPOOL pool, Direct3DVolume8 **ppVolumeTexture)
{
    FIXME("(%p, %i, %i, %i, %i, %i, %u, %u, %p): stub!\n", device, width, height, depth, mipLevels,
            usage, pixelformat, pool, ppVolumeTexture);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_FilterVolumeTexture(ID3DX8 *iface, Direct3DVolume8 *volumeTexture,
        void *palette, LONG srcLevel, LONG filter)
{
    FIXME("(%p, %p, %i, %i): stub!\n", volumeTexture, palette, srcLevel, filter);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadSurfaceFromResource(ID3DX8 *iface, Direct3DSurface8 *destSurface, void *destPalette,
        void *destRect, LONG hSrcModule, BSTR srcResource, void *srcRect, LONG filter, LONG colorKey, void *srcInfo)
{
    FIXME("(%p, %p, %p, %i, %s, %p, %i, %i, %p): stub!\n", destSurface, destPalette, destRect, hSrcModule,
            debugstr_w(srcResource), srcRect, filter, colorKey, srcInfo);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadVolumeFromVolume(ID3DX8 *iface, Direct3DVolume8 *destVolume, void *destPalette,
        void *destBox, Direct3DVolume8 *srcVolume, void *srcPalette, void *srcBox, LONG filter, LONG colorKey)
{
    FIXME("(%p, %p, %p, %p, %p, %p, %i, %i): stub!\n", destVolume, destPalette, destBox, srcVolume,
            srcPalette, srcBox, filter, colorKey);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadVolumeFromMemory(ID3DX8 *iface, Direct3DVolume8 *destVolume, void *destPalette,
        void *destBox, void *srcMemory, LONG srcFormat, LONG srcRowPitch, LONG srcSlicePitch, void *srcPalette,
        void *srcBox, LONG filter, LONG colorKey)
{
    FIXME("(%p, %p, %p, %p, %i, %i, %i, %p, %p, %i, %i): stub!\n", destVolume, destPalette, destBox, srcMemory,
            srcFormat, srcRowPitch, srcSlicePitch, srcPalette, srcBox, filter, colorKey);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateMesh(ID3DX8 *iface, LONG numFaces, LONG numVertices, LONG options,
        void *declaration, Direct3DDevice8 *pD3D, D3DXMesh **ppMesh)
{
    FIXME("(%i, %i, %i, %p, %p, %p): stub!\n", numFaces, numVertices, options, declaration, pD3D, ppMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateMeshFVF(ID3DX8 *iface, LONG numFaces, LONG numVertices, LONG options, LONG fvf,
        Direct3DDevice8 *pD3D, D3DXMesh **ppMesh)
{
    FIXME("(%i, %i, %i, %i, %p, %p): stub!\n", numFaces, numVertices, options, fvf, pD3D, ppMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateSPMesh(ID3DX8 *iface, D3DXMesh *pMesh, void *adjacency, void *vertexAttributeWeights,
        void *vertexWeights, D3DXSPMesh **ppSMesh)
{
    FIXME("(%p, %p, %p, %p, %p): stub!\n", pMesh, adjacency, vertexAttributeWeights, vertexWeights, ppSMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_GeneratePMesh(ID3DX8 *iface, D3DXMesh *mesh, void *adjacency, void *vertexAttributeWeights,
        void *vertexWeights, LONG minValue, LONG options, D3DXPMesh **ppPMesh)
{
    FIXME("(%p, %p, %p, %p, %i, %i, %p): stub!\n", mesh, adjacency, vertexAttributeWeights, vertexWeights,
            minValue, options, ppPMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_SimplifyMesh(ID3DX8 *iface, D3DXMesh *mesh, void *adjacency, void *vertexAttributeWeights,
        void *vertexWeights, LONG minValue, LONG options, D3DXMesh **ppMesh)
{
    FIXME("(%p, %p, %p, %p, %i, %i, %p): stub!\n", mesh, adjacency, vertexAttributeWeights, vertexWeights,
            minValue, options, ppMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_ComputeBoundingSphere(ID3DX8 *iface, void *pointsFVF, LONG numVertices, LONG fvf,
        D3DVECTOR *centers, float *radiusArray)
{
    FIXME("(%p, %i, %i, %p, %p): stub!\n", pointsFVF, numVertices, fvf, centers, radiusArray);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_ComputeBoundingBox(ID3DX8 *iface, void *pointsFVF, LONG numVertices, LONG fvf,
        D3DVECTOR *minVert, D3DVECTOR *maxVert)
{
    FIXME("(%p, %i, %i, %p, %p): stub!\n", pointsFVF, numVertices, fvf, minVert, maxVert);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_ComputeNormals(ID3DX8 *iface, D3DXBaseMesh *pMesh)
{
    FIXME("(%p): stub!\n", pMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_DeclaratorFromFVF(ID3DX8 *iface, LONG fvf, D3DXDECLARATOR *declarator)
{
    FIXME("(%i, %p): stub!\n", fvf, declarator);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_FVFFromDeclarator(ID3DX8 *iface, D3DXDECLARATOR *declarator, LONG *fvf)
{
    FIXME("(%p, %p): stub!\n", declarator, fvf);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateBuffer(ID3DX8 *iface, LONG numBytes, D3DXBuffer **ppBuffer)
{
    FIXME("(%i, %p): stub!\n", numBytes, ppBuffer);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadMeshFromX(ID3DX8 *iface, BSTR filename, LONG options, Direct3DDevice8 *device,
        D3DXBuffer **retAdjacency, D3DXBuffer **retMaterials, LONG *retMaterialCount, D3DXMesh **retMesh)
{
    FIXME("(%s, %i, %p, %p, %p, %p, %p): stub!\n", debugstr_w(filename), options, device, retAdjacency,
            retMaterials, retMaterialCount, retMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_SaveMeshToX(ID3DX8 *iface, BSTR filename, D3DXMesh *mesh, void *adjacencyArray,
        D3DXMATERIAL *materialArray, LONG materialCount, LONG xFormat)
{
    FIXME("(%s, %p, %p, %p, %i, %i): stub!\n", debugstr_w(filename), mesh, adjacencyArray,
            materialArray, materialCount, xFormat);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadMeshFromXof(ID3DX8 *iface, IUnknown *xofobjMesh, LONG options, Direct3DDevice8 *device,
        D3DXBuffer **retBufAdjacency, D3DXBuffer **retMaterials, LONG *retMaterialCount, D3DXMesh **retMesh)
{
    FIXME("(%p, %i, %p, %p, %p, %p, %p): stub!\n", xofobjMesh, options, device, retBufAdjacency,
            retMaterials, retMaterialCount, retMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_TessellateNPatches(ID3DX8 *iface, D3DXMesh *meshIn, void *adjacencyIn, float numSegs,
        VARIANT_BOOL quadraticInterpNormals, D3DXBuffer **adjacencyOut, D3DXMesh **meshOut)
{
    FIXME("(%p, %p, %f, %x, %p, %p): stub!\n", meshIn, adjacencyIn, numSegs, quadraticInterpNormals,
            adjacencyOut, meshOut);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_BufferGetMaterial(ID3DX8 *iface, D3DXBuffer *materialBuffer, LONG index, D3DMATERIAL8 *mat)
{
    FIXME("(%p, %i, %p): stub!\n", materialBuffer, index, mat);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_BufferGetTextureName(ID3DX8 *iface, D3DXBuffer *materialBuffer, LONG index, BSTR *retName)
{
    FIXME("(%p, %i, %p): stub!\n", materialBuffer, index, retName);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_BufferGetData(ID3DX8 *iface, D3DXBuffer *buffer, LONG index, LONG typesize,
        LONG typecount, void *data)
{
    FIXME("(%p, %i, %i, %i, %p): stub!\n", buffer, index, typesize, typecount, data);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_BufferSetData(ID3DX8 *iface, D3DXBuffer *buffer, LONG index, LONG typesize,
        LONG typecount, void *data)
{
    FIXME("(%p, %i, %i, %i, %p): stub!\n", buffer, index, typesize, typecount, data);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_Intersect(ID3DX8 *iface, D3DXMesh *meshIn, D3DVECTOR *rayPos, D3DVECTOR *rayDir,
        LONG *retHit, LONG *retFaceIndex, float *u, float *v, float *retDist, LONG *countHits, D3DXBuffer **allHits)
{
    FIXME("(%p, %p, %p, %p, %p, %p, %p, %p, %p, %p): stub!\n", meshIn, rayPos, rayDir, retHit, retFaceIndex, u, v,
            retDist, countHits, allHits);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_SphereBoundProbe(ID3DX8 *iface, D3DVECTOR *center, float radius, D3DVECTOR *rayPosition,
        D3DVECTOR *rayDirection, VARIANT_BOOL *retHit)
{
    FIXME("(%p, %f, %p, %p, %p): stub!\n", center, radius, rayPosition, rayDirection, retHit);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_ComputeBoundingSphereFromMesh(ID3DX8 *iface, D3DXMesh *meshIn,
        D3DVECTOR *centers, float *radiusArray)
{
    FIXME("(%p, %p, %p): stub!\n", meshIn, centers, radiusArray);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_ComputeBoundingBoxFromMesh(ID3DX8 *iface, D3DXMesh *meshIn,
        D3DVECTOR *minArray, D3DVECTOR *maxArray)
{
    FIXME("(%p, %p, %p): stub!\n", meshIn, minArray, maxArray);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateSkinMesh(ID3DX8 *iface, LONG numFaces, LONG numVertices, LONG numBones, LONG options,
        void *declaration, Direct3DDevice8 *device, D3DXSkinMesh **ppSkinMesh)
{
    FIXME("(%i, %i, %i, %i, %p, %p, %p): stub!\n", numFaces, numVertices, numBones, options, declaration,
            device, ppSkinMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateSkinMeshFVF(ID3DX8 *iface, LONG numFaces, LONG numVertices, LONG numBones,
        LONG options, LONG fvf, Direct3DDevice8 *device, D3DXSkinMesh **ppSkinMesh)
{
    FIXME("(%i, %i, %i, %i, %i, %p, %p): stub!\n", numFaces, numVertices, numBones, options, fvf, device, ppSkinMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateSkinMeshFromMesh(ID3DX8 *iface, D3DXMesh *mesh,
        LONG numBones, D3DXSkinMesh **ppSkinMesh)
{
    FIXME("(%p, %i, %p): stub!\n", mesh, numBones, ppSkinMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadSkinMeshFromXof(ID3DX8 *iface, IUnknown *xofobjMesh, LONG options,
        Direct3DDevice8 *device, D3DXBuffer **adjacencyOut, D3DXBuffer **materialsOut, LONG *numMatOut,
        D3DXBuffer **boneNamesOut, D3DXBuffer **boneTransformsOut, D3DXSkinMesh **ppMesh)
{
    FIXME("(%p, %i, %p, %p, %p, %p, %p, %p, %p): stub!\n", xofobjMesh, options, device, adjacencyOut,
            materialsOut, numMatOut, boneNamesOut, boneTransformsOut, ppMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreatePolygon(ID3DX8 *iface, Direct3DDevice8 *device, float length, LONG sides,
        D3DXBuffer **retAdjacency, D3DXMesh **retMesh)
{
    FIXME("(%p, %f, %i, %p, %p): stub!\n", device, length, sides, retAdjacency, retMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateBox(ID3DX8 *iface, Direct3DDevice8 *device, float width, float height, float depth,
        D3DXBuffer **retAdjacency, D3DXMesh **retMesh)
{
    FIXME("(%p, %f, %f, %f, %p, %p): stub!\n", device, width, height, depth, retAdjacency, retMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateCylinder(ID3DX8 *iface, Direct3DDevice8 *device, float radius1, float radius2,
        float length, LONG slices, LONG stacks, D3DXBuffer **retAdjacency, D3DXMesh **retMesh)
{
    FIXME("(%p, %f, %f, %f, %i, %i, %p, %p): stub!\n", device, radius1, radius2, length, slices,
            stacks, retAdjacency, retMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateSphere(ID3DX8 *iface, Direct3DDevice8 *device, float radius, LONG slices,
        LONG stacks, D3DXBuffer **retAdjacency, D3DXMesh **retMesh)
{
    FIXME("(%p, %f, %i, %i, %p, %p): stub!\n", device, radius, slices, stacks, retAdjacency, retMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateTorus(ID3DX8 *iface, Direct3DDevice8 *device, float innerRadius,
        float outerRadius, LONG sides, LONG rings, D3DXBuffer **retAdjacency, D3DXMesh **retMesh)
{
    FIXME("(%p, %f, %f, %i, %i, %p, %p): stub!\n", device, innerRadius, outerRadius, sides,
            rings, retAdjacency, retMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateTeapot(ID3DX8 *iface, Direct3DDevice8 *device,
        D3DXBuffer **retAdjacency, D3DXMesh **retMesh)
{
    FIXME("(%p, %p, %p): stub!\n", device, retAdjacency, retMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateText(ID3DX8 *iface, Direct3DDevice8 *device, LONG hDC, BSTR text, float deviation,
        float extrusion, D3DXMesh **retMesh, D3DXBuffer **adjacencyOut, void *glyphMetrics)
{
    FIXME("(%p, %i, %s, %f, %f, %p, %p, %p): stub!\n", device, hDC, debugstr_w(text), deviation, extrusion,
            retMesh, adjacencyOut, glyphMetrics);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_BufferGetBoneName(ID3DX8 *iface, D3DXBuffer *boneNameBuffer, LONG index, BSTR *retName)
{
    FIXME("(%p, %i, %p): stub!\n", boneNameBuffer, index, retName);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateSprite(ID3DX8 *iface, Direct3DDevice8 *device, D3DXSprite **retSprite)
{
    FIXME("(%p, %p): stub!\n", device, retSprite);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CreateRenderToSurface(ID3DX8 *iface, Direct3DDevice8 *device, LONG width, LONG height,
        D3DFORMAT format, LONG depthStencil, D3DFORMAT depthStencilFormat, D3DXRenderToSurface **retRenderToSurface)
{
    FIXME("(%p, %i, %i, %u, %i, %u, %p): stub!\n", device, width, height, format, depthStencil,
            depthStencilFormat, retRenderToSurface);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_CleanMesh(ID3DX8 *iface, D3DXMesh *meshIn, void *adjacency, BSTR *log,
        D3DXBuffer *adjacencyOut, D3DXMesh **meshOut)
{
    FIXME("(%p, %p, %p, %p, %p): stub!\n", meshIn, adjacency, log, adjacencyOut, meshOut);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_ValidMesh(ID3DX8 *iface, D3DXMesh *meshIn, void *adjacency, BSTR *log, VARIANT_BOOL *ret)
{
    FIXME("(%p, %p, %p, %p): stub!\n", meshIn, adjacency, log, ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_BoxBoundProbe(ID3DX8 *iface, D3DVECTOR *minVert, D3DVECTOR *maxVert,
        D3DVECTOR *rayPosition, D3DVECTOR *rayDirection, VARIANT_BOOL *ret)
{
    FIXME("(%p, %p, %p, %p, %p): stub!\n", minVert, maxVert, rayPosition, rayDirection, ret);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_SavePMeshToFile(ID3DX8 *iface, BSTR filename, D3DXPMesh *mesh,
        D3DXMATERIAL *materialArray, LONG materialCount)
{
    FIXME("(%s, %p, %p, %i): stub!\n", debugstr_w(filename), mesh, materialArray, materialCount);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_LoadPMeshFromFile(ID3DX8 *iface, BSTR filename, LONG options, Direct3DDevice8 *device,
        D3DXBuffer **retMaterials, LONG *retNumMaterials, D3DXPMesh **retPMesh)
{
    FIXME("(%s, %i, %p, %p, %p, %p): stub!\n", debugstr_w(filename), options, device,
            retMaterials, retNumMaterials, retPMesh);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_BufferGetBoneCombo(ID3DX8 *iface, D3DXBuffer *boneComboBuffer,
        LONG index, D3DXBONECOMBINATION *boneCombo)
{
    FIXME("(%p, %i, %p): stub!\n", boneComboBuffer, index, boneCombo);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_BufferGetBoneComboBoneIds(ID3DX8 *iface, D3DXBuffer *boneComboBuffer,
        LONG index, LONG paletteSize, void *boneIds)
{
    FIXME("(%p, %i, %i, %p): stub!\n", boneComboBuffer, index, paletteSize, boneIds);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_SaveSurfaceToFile(ID3DX8 *iface, BSTR destFile, D3DXIMAGE_FILEFORMAT destFormat,
        Direct3DSurface8 *srcSurface, PALETTEENTRY *srcPalette, RECT *srcRect)
{
    FIXME("(%s, %u, %p, %p, %s): stub!\n", debugstr_w(destFile), destFormat,
            srcSurface, srcPalette, wine_dbgstr_rect(srcRect));

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_SaveVolumeToFile(ID3DX8 *iface, BSTR destFile, D3DXIMAGE_FILEFORMAT destFormat,
        Direct3DVolume8 *srcVolume, PALETTEENTRY *srcPalette, void *srcBox)
{
    FIXME("(%s, %u, %p, %p, %p): stub!\n", debugstr_w(destFile), destFormat, srcVolume, srcPalette, srcBox);

    return E_NOTIMPL;
}

static HRESULT WINAPI d3dx8_SaveTextureToFile(ID3DX8 *iface, BSTR destFile, D3DXIMAGE_FILEFORMAT destFormat,
        Direct3DBaseTexture8 *srcTexture, PALETTEENTRY *srcPalette)
{
    FIXME("(%s, %u, %p, %p): stub!\n", debugstr_w(destFile), destFormat, srcTexture, srcPalette);

    return E_NOTIMPL;
}

static const ID3DX8Vtbl ID3DX8_Vtbl =
{
    /*** IUnknown methods ***/
    d3dx8_QueryInterface,
    d3dx8_AddRef,
    d3dx8_Release,
    /*** ID3DX8 methods ***/
    d3dx8_CreateFont,
    d3dx8_DrawText,
    d3dx8_GetFVFVertexSize,
    d3dx8_AssembleShaderFromFile,
    d3dx8_AssembleShader,
    d3dx8_GetErrorString,
    d3dx8_LoadSurfaceFromFile,
    d3dx8_LoadSurfaceFromFileInMemory,
    d3dx8_LoadSurfaceFromSurface,
    d3dx8_LoadSurfaceFromMemory,
    d3dx8_CheckTextureRequirements,
    d3dx8_CreateTexture,
    d3dx8_CreateTextureFromResource,
    d3dx8_CreateTextureFromFile,
    d3dx8_CreateTextureFromFileEx,
    d3dx8_CreateTextureFromFileInMemory,
    d3dx8_CreateTextureFromFileInMemoryEx,
    d3dx8_FilterTexture,
    d3dx8_CheckCubeTextureRequirements,
    d3dx8_CreateCubeTexture,
    d3dx8_CreateCubeTextureFromFile,
    d3dx8_CreateCubeTextureFromFileEx,
    d3dx8_CreateCubeTextureFromFileInMemory,
    d3dx8_CreateCubeTextureFromFileInMemoryEx,
    d3dx8_FilterCubeTexture,
    d3dx8_CheckVolumeTextureRequirements,
    d3dx8_CreateTextureFromResourceEx,
    d3dx8_CreateVolumeTexture,
    d3dx8_FilterVolumeTexture,
    d3dx8_LoadSurfaceFromResource,
    d3dx8_LoadVolumeFromVolume,
    d3dx8_LoadVolumeFromMemory,
    d3dx8_CreateMesh,
    d3dx8_CreateMeshFVF,
    d3dx8_CreateSPMesh,
    d3dx8_GeneratePMesh,
    d3dx8_SimplifyMesh,
    d3dx8_ComputeBoundingSphere,
    d3dx8_ComputeBoundingBox,
    d3dx8_ComputeNormals,
    d3dx8_DeclaratorFromFVF,
    d3dx8_FVFFromDeclarator,
    d3dx8_CreateBuffer,
    d3dx8_LoadMeshFromX,
    d3dx8_SaveMeshToX,
    d3dx8_LoadMeshFromXof,
    d3dx8_TessellateNPatches,
    d3dx8_BufferGetMaterial,
    d3dx8_BufferGetTextureName,
    d3dx8_BufferGetData,
    d3dx8_BufferSetData,
    d3dx8_Intersect,
    d3dx8_SphereBoundProbe,
    d3dx8_ComputeBoundingSphereFromMesh,
    d3dx8_ComputeBoundingBoxFromMesh,
    d3dx8_CreateSkinMesh,
    d3dx8_CreateSkinMeshFVF,
    d3dx8_CreateSkinMeshFromMesh,
    d3dx8_LoadSkinMeshFromXof,
    d3dx8_CreatePolygon,
    d3dx8_CreateBox,
    d3dx8_CreateCylinder,
    d3dx8_CreateSphere,
    d3dx8_CreateTorus,
    d3dx8_CreateTeapot,
    d3dx8_CreateText,
    d3dx8_BufferGetBoneName,
    d3dx8_CreateSprite,
    d3dx8_CreateRenderToSurface,
    d3dx8_CleanMesh,
    d3dx8_ValidMesh,
    d3dx8_BoxBoundProbe,
    d3dx8_SavePMeshToFile,
    d3dx8_LoadPMeshFromFile,
    d3dx8_BufferGetBoneCombo,
    d3dx8_BufferGetBoneComboBoneIds,
    d3dx8_SaveSurfaceToFile,
    d3dx8_SaveVolumeToFile,
    d3dx8_SaveTextureToFile
};

HRESULT d3dx8_create(IUnknown *outer_unk, void **ppv)
{
    d3dx8 *object;

    TRACE("(%p,%p)\n", outer_unk, ppv);

    object = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, sizeof(d3dx8));
    if (!object)
        return E_OUTOFMEMORY;

    object->ID3DX8_iface.lpVtbl = &ID3DX8_Vtbl;
    object->ref = 1;

    *ppv = &object->ID3DX8_iface;

    return S_OK;
}

