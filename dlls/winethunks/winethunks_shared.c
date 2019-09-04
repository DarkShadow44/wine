#include <windows.h>
#include "wine/debug.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

void* wine_thunk_get_for_user32(void *func);
void* wine_thunk_get_for_kernel32(void *func);

WINAPI void *wine_thunk_get_for_any(void *func)
{
	void *ret;
	if ((ret = wine_thunk_get_for_user32(func)) != NULL)
		return ret;
	if ((ret = wine_thunk_get_for_kernel32(func)) != NULL)
		return ret;

	ERR("Missing thunk!\n");
	return func;
}

void* wine_thunk_initialize_user32(void);
void* wine_thunk_initialize_kernel32(void);

WINAPI void wine_thunk_initialize_any(const char *dll)
{
	if (!strcasecmp("user32.dll", dll))
		wine_thunk_initialize_user32();
	if (!strcasecmp("kernel32.dll", dll))
		wine_thunk_initialize_kernel32();

}
