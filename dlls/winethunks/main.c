#include <windows.h>
#include "wine/winethunks.h"
#include "user32.h"

static BOOL initialized = FALSE;

WINAPI DWORD wine_make_thunk_function(void *addr, DWORD func)
{
    if (!initialized)
    {
        initialized = TRUE;
        init_user32();
    }
    return create_import_stub(addr, wine32a_MessageBoxA);
}
