/*
 * Unit tests for uiribbon
 *
 * Copyright (C) 2017 Fabian Maurer
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

#include <stdio.h>

#include "wine/test.h"
#include "initguid.h"
#include "uiribbon.h"

static BOOL test_availability(void)
{
    IUIFramework *pUIFramework = NULL;
    HRESULT hr;

    hr = CoCreateInstance(&CLSID_UIRibbonFramework, NULL, CLSCTX_INPROC_SERVER, &IID_IUIFramework, (PVOID *)&pUIFramework);
    if(FAILED(hr))
        return FALSE;

    IUIFramework_Release(pUIFramework);
    return TRUE;
}


START_TEST(uiribbon)
{
    CoInitialize(NULL);

    if(!test_availability())
    {
        CoUninitialize();
        return;
    }

    CoUninitialize();
}
