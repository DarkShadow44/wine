/*
 * Unit test suite for ntdll heap functions
 *
 * Copyright 2018 Fabian Maurer
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

#include <stdio.h>

#include "ntdll_test.h"

static NTSTATUS (WINAPI *pRtlGetProcessHeaps)(ULONG count, HANDLE *heaps);

typedef struct _HEAPWin10 {
    void *unknown1[2];
    ULONG segment_signature;
    ULONG segment_flags;
    LIST_ENTRY segment_list_entry;
    struct _HEAPWin10* heap;
    ULONG unknown2a[2];
    void *unknown2b[7];
    DWORD flags;
    ULONG unknown3a[5];
    void *unknown3b[2];
    DWORD signature;
} HEAPWin10;

static void test_csrss_heap(void)
{
    const DWORD HEAP_CLASS_CSRSS = 0x00008000;
    const DWORD HEAP_CLASS_MASK = 0x0000f000;
    const DWORD HEAP_SEGMENT_SIGNATURE = 0xffeeffee;
    const DWORD HEAP_SIGNATURE = 0xeeffeeff;
    DWORD heap_count;
    HANDLE *heaps;
    HANDLE heap_csrss = NULL;
    int i;
    int version_major = GetVersion() & 0xff;

    if (version_major != 10)
    {
        skip("csrss heap skipped, only exists on >=Win10\n");
        return;
    }

    heap_count = pRtlGetProcessHeaps(0, 0);
    heaps = malloc(sizeof(HANDLE) * heap_count);
    pRtlGetProcessHeaps(heap_count, heaps);

    for (i = 0; i < heap_count; ++i)
    {
        HEAPWin10 *heap = (HEAPWin10 *)heaps[i];

        ok(heap->signature == HEAP_SIGNATURE, "Got wrong signature %x\n", heap->segment_signature);
        ok(heap->segment_signature == HEAP_SEGMENT_SIGNATURE, "Got wrong segment signature %x\n", heap->segment_signature);
        ok(heap->heap == heap, "Got wrong heap pointer, expected %p, got %p\n", heap, heap->heap);

        if ((heap->flags & HEAP_CLASS_MASK) == HEAP_CLASS_CSRSS)
        {
            ok(heap_csrss == NULL, "Found more than one csrss heap\n");
            heap_csrss = heaps[i];
        }
    }

    ok(heap_csrss != NULL, "Didn't find csrss heap\n");
    if (heap_csrss)
        ok(HeapDestroy(heap_csrss), "Failed to destroy csrss heap\n");
}

START_TEST(heap)
{
    HMODULE mod = GetModuleHandleA("ntdll.dll");
    if (!mod)
    {
        win_skip("Not running on NT, skipping tests\n");
        return;
    }

    pRtlGetProcessHeaps = (void *)GetProcAddress(mod, "RtlGetProcessHeaps");

    test_csrss_heap();
}
