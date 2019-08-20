#include <windows.h>
#include "wine/winethunks.h"
#include "user32.h"

INT WINAPI (*pMessageBoxA)(HWND hWnd, LPCSTR text, LPCSTR title, UINT type);

INT WINAPI wine32b_MessageBoxA(HWND hWnd, LPCSTR text, LPCSTR title, UINT type)
{
    pMessageBoxA = GetProcAddress(LoadLibraryA("user32"), "MessageBoxA");
    return pMessageBoxA(hWnd, text, title, type);
}


WINAPI DWORD wine_make_thunk_function(void* addr, DWORD func)
{
    return create_import_stub(addr, wine32a_MessageBoxA);
}
