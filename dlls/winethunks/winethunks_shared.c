#include <windows.h>

void* wine_thunk_get_for_user32(void *func);
void* wine_thunk_get_for_kernel32(void *func);
void* wine_thunk_get_for_advapi32(void *func);
void* wine_thunk_get_for_msvcrt(void *func);
void* wine_thunk_get_for_ntdll(void *func);
void* wine_thunk_get_for_kernelbase(void *func);

WINAPI void *wine_thunk_get_for_any(void *func)
{
	void *ret;
	if ((ret = wine_thunk_get_for_user32(func)) != NULL)
		return ret;
	if ((ret = wine_thunk_get_for_kernel32(func)) != NULL)
		return ret;
	if ((ret = wine_thunk_get_for_advapi32(func)) != NULL)
		return ret;
	if ((ret = wine_thunk_get_for_msvcrt(func)) != NULL)
		return ret;
	if ((ret = wine_thunk_get_for_ntdll(func)) != NULL)
		return ret;
	if ((ret = wine_thunk_get_for_kernelbase(func)) != NULL)
		return ret;

	return func;
}

void* wine_thunk_initialize_user32(void);
void* wine_thunk_initialize_kernel32(void);
void* wine_thunk_initialize_advapi32(void);
void* wine_thunk_initialize_msvcrt(void);
void* wine_thunk_initialize_ntdll(void);
void* wine_thunk_initialize_kernelbase(void);

WINAPI void wine_thunk_initialize_any(const char *dll)
{
	if (!strcasecmp("user32.dll", dll))
		wine_thunk_initialize_user32();
	if (!strcasecmp("kernel32.dll", dll))
		wine_thunk_initialize_kernel32();
	if (!strcasecmp("advapi32.dll", dll))
		wine_thunk_initialize_advapi32();
	if (!strcasecmp("msvcrt.dll", dll))
		wine_thunk_initialize_msvcrt();
	if (!strcasecmp("ntdll.dll", dll))
		wine_thunk_initialize_ntdll();
	if (!strcasecmp("kernelbase.dll", dll))
		wine_thunk_initialize_kernelbase();
}
