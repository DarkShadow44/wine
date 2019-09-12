#include <windows.h>


WINAPI void *wine_thunk_get_for_any(void *func)
{
	void *ret;

	return func;
}


WINAPI void wine_thunk_initialize_any(const char *dll)
{

}
