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

#ifndef __DX8VB_PRIVATE_INCLUDED__
#define __DX8VB_PRIVATE_INCLUDED__

#include <stdarg.h>
#include <string.h>

#include "windef.h"
#include "winbase.h"
#include "winuser.h"
#include "winreg.h"
#include "wingdi.h"

#undef CreateFont
#undef DrawText
#undef CreateEvent

#include "dx8vb.h"

HRESULT d3dx8_create(IUnknown *outer_unk, void **ppv) DECLSPEC_HIDDEN;
HRESULT directx8_create(IUnknown *outer_unk, void **ppv) DECLSPEC_HIDDEN;


#endif /* __DX8VB_PRIVATE_INCLUDED__ */

 
