/*
typedef enum
{
    DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE = 1,
    DISPLAYCONFIG_MODE_INFO_TYPE_TARGET = 2,
    DISPLAYCONFIG_MODE_INFO_TYPE_DESKTOP_IMAGE = 3,
    DISPLAYCONFIG_MODE_INFO_TYPE_FORCE_UINT32 = 0xffffffff
} DISPLAYCONFIG_MODE_INFO_TYPE;

typedef struct
{
	int peter;
} str;

typedef struct tagCIEXYZTRIPLE
{
    CIEXYZ ciexyzRed;
    CIEXYZ ciexyzGreen;
    CIEXYZ ciexyzBlue;
} *CIEXYZTRIPLE, **CIEXYZTRIPLEss;

enum
{
	kasdasdk = 0,
};

typedef int klo;
*/

typedef enum
{
    INVALID_PATH = 0,
    UNC_PATH,              /* "//foo" */
    ABSOLUTE_DRIVE_PATH,   /* "c:/foo" */
    RELATIVE_DRIVE_PATH,   /* "c:foo" */
    ABSOLUTE_PATH,         /* "/foo" */
    RELATIVE_PATH,         /* "foo" */
    DEVICE_PATH,           /* "//./foo" */
    UNC_DOT_PATH           /* "//." */
} DOS_PATHNAME_TYPE;

int main()
{
}

