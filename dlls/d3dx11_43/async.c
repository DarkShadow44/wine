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
#include "wine/wined3d.h"

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

HRESULT WINAPI D3DX11CompileFromFileW(const WCHAR *filename, const D3D10_SHADER_MACRO *defines,
        ID3D10Include *include, const char *entry_point, const char *target, UINT sflags, UINT eflags,
        ID3DX11ThreadPump *pump, ID3D10Blob **shader, ID3D10Blob **error_messages, HRESULT *hresult)
{
    void *buffer;
    HRESULT ret;
    DWORD size;

    ret = wined3d_map_view_of_file(filename, &buffer, &size);

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

HRESULT WINAPI D3DX11CreateShaderResourceViewFromFileW(ID3D11Device *iface,
        WCHAR *filename, D3DX11_IMAGE_LOAD_INFO *load_info, ID3DX11ThreadPump *pump, ID3D11ShaderResourceView **view, HRESULT *hresult)
{
    D3D11_SHADER_RESOURCE_VIEW_DESC desc_view;
    D3D11_TEXTURE2D_DESC desc_texture;
    D3D11_SUBRESOURCE_DATA data_texture;
    ID3D11Texture2D *texture;
    HRESULT hr;
    void *buffer;
    void *raw_image;
    UINT image_width, image_height;
    HRESULT ret;
    DWORD size;

    if (pump)
        FIXME("Unimplemented ID3DX11ThreadPump handling.\n");

    ret = wined3d_map_view_of_file(filename, &buffer, &size);

    if (FAILED(ret))
        return E_FAIL;

    wined3d_load_imagedata_from_file_in_memory(buffer, size, &raw_image, 0, &image_width, &image_height);


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
