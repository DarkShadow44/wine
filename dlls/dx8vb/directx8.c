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
    IDirectX8 IDirectX8_iface;
    LONG ref;
} directx8;

static inline directx8 *impl_from_IDirectX8(IDirectX8 *iface)
{
    return CONTAINING_RECORD(iface, directx8, IDirectX8_iface);
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
    FIXME("(%p): stub!\n", ret);

    return E_NOTIMPL;
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

