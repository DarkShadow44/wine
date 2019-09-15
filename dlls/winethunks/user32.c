#include "windows.h"
#include "wine/asm.h"
#include "wine/debug.h"
#include "wine/winethunks.h"
WINE_DEFAULT_DEBUG_CHANNEL(thunks);

struct wow_handlers16; /* ../dlls/user32/controls.h:94 */
struct wow_handlers32; /* ../dlls/user32/controls.h:110 */
struct tagDIALOGINFO; /* ../dlls/user32/controls.h:229 */
struct HCONVLIST__; /* ../include/ddeml.h:305 */
struct HCONV__; /* ../include/ddeml.h:306 */
struct HSZ__; /* ../include/ddeml.h:307 */
struct HDDEDATA__; /* ../include/ddeml.h:308 */
struct tagCONVCONTEXT; /* ../include/ddeml.h:333 */
struct tagCONVINFO; /* ../include/ddeml.h:344 */

typedef unsigned short UINT16; /* ../include/basetsd.h:83 */

typedef unsigned int UINT32; /* ../include/basetsd.h:84 */

typedef long INT_PTR; /* ../include/basetsd.h:117 */

typedef long LONG_PTR; /* ../include/basetsd.h:118 */

typedef unsigned long UINT_PTR; /* ../include/basetsd.h:119 */

typedef unsigned long* PUINT_PTR; /* ../include/basetsd.h:119 */

typedef unsigned long ULONG_PTR; /* ../include/basetsd.h:120 */

typedef ULONG_PTR DWORD_PTR; /* ../include/basetsd.h:121 */

typedef ULONG_PTR* PDWORD_PTR; /* ../include/basetsd.h:121 */

struct wow_handlers16 /* ../dlls/user32/controls.h:94 */
{
    LRESULT (*button_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*combo_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*edit_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*listbox_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*mdiclient_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*scrollbar_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*static_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    DWORD (*wait_message) (DWORD, HANDLE*, DWORD, DWORD, DWORD);
    HWND (*create_window) (CREATESTRUCTW*, LPCWSTR, HINSTANCE, BOOL);
    LRESULT (*call_window_proc) (HWND, UINT, WPARAM, LPARAM, LRESULT*, void*);
    LRESULT (*call_dialog_proc) (HWND, UINT, WPARAM, LPARAM, LRESULT*, void*);
    void (*free_icon_param) (ULONG_PTR);
};


struct wow_handlers32 /* ../dlls/user32/controls.h:110 */
{
    LRESULT (*button_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*combo_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*edit_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*listbox_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*mdiclient_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*scrollbar_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    LRESULT (*static_proc) (HWND, UINT, WPARAM, LPARAM, BOOL);
    DWORD (*wait_message) (DWORD, HANDLE*, DWORD, DWORD, DWORD);
    HWND (*create_window) (CREATESTRUCTW*, LPCWSTR, HINSTANCE, BOOL);
    HWND (*get_win_handle) (HWND);
    WNDPROC (*alloc_winproc) (WNDPROC, BOOL);
    struct tagDIALOGINFO* (*get_dialog_info) (HWND, BOOL);
    INT (*dialog_box_loop) (HWND, HWND);
    ULONG_PTR (*get_icon_param) (HICON);
    ULONG_PTR (*set_icon_param) (HICON, ULONG_PTR);
};


struct tagDIALOGINFO /* ../dlls/user32/controls.h:229 */
{
    HWND hwndFocus;
    HFONT hUserFont;
    HMENU hMenu;
    UINT xBaseUnit;
    UINT yBaseUnit;
    INT idResult;
    UINT flags;
};


struct HCONVLIST__ /* ../include/ddeml.h:305 */
{
    int unused;
};


typedef struct HCONVLIST__* HCONVLIST; /* ../include/ddeml.h:305 */

struct HCONV__ /* ../include/ddeml.h:306 */
{
    int unused;
};


typedef struct HCONV__* HCONV; /* ../include/ddeml.h:306 */

struct HSZ__ /* ../include/ddeml.h:307 */
{
    int unused;
};


typedef struct HSZ__* HSZ; /* ../include/ddeml.h:307 */

struct HDDEDATA__ /* ../include/ddeml.h:308 */
{
    int unused;
};


typedef struct HDDEDATA__* HDDEDATA; /* ../include/ddeml.h:308 */

typedef HDDEDATA (*PFNCALLBACK) (UINT, UINT, HCONV, HSZ, HSZ, HDDEDATA, ULONG_PTR, ULONG_PTR); /* ../include/ddeml.h:318 */

struct tagCONVCONTEXT /* ../include/ddeml.h:333 */
{
    UINT cb;
    UINT wFlags;
    UINT wCountryID;
    INT iCodePage;
    DWORD dwLangID;
    DWORD dwSecurity;
    SECURITY_QUALITY_OF_SERVICE qos;
};


typedef struct tagCONVCONTEXT CONVCONTEXT; /* ../include/ddeml.h:342 */

typedef struct tagCONVCONTEXT* PCONVCONTEXT; /* ../include/ddeml.h:342 */

struct tagCONVINFO /* ../include/ddeml.h:344 */
{
    DWORD cb;
    DWORD_PTR hUser;
    HCONV hConvPartner;
    HSZ hszSvcPartner;
    HSZ hszServiceReq;
    HSZ hszTopic;
    HSZ hszItem;
    UINT wFmt;
    UINT wType;
    UINT wStatus;
    UINT wConvst;
    UINT wLastError;
    HCONVLIST hConvList;
    CONVCONTEXT ConvCtxt;
    HWND hwnd;
    HWND hwndPartner;
};


typedef struct tagCONVINFO* PCONVINFO; /* ../include/ddeml.h:362 */

typedef UINT16 HANDLE16; /* ../include/wine/windef16.h:37 */

typedef HANDLE16 HINSTANCE16; /* ../include/wine/windef16.h:86 */

typedef HINSTANCE16 HMODULE16; /* ../include/wine/windef16.h:114 */

static WINAPI HKL (*pActivateKeyboardLayout)(HKL  hLayout, UINT  flags);
static WINAPI BOOL (*pAddClipboardFormatListener)(HWND  hwnd);
static WINAPI BOOL (*pAdjustWindowRect)(LPRECT  rect, DWORD  style, BOOL  menu);
static WINAPI BOOL (*pAdjustWindowRectEx)(LPRECT  rect, DWORD  style, BOOL  menu, DWORD  exStyle);
static WINAPI BOOL (*pAdjustWindowRectExForDpi)(LPRECT  rect, DWORD  style, BOOL  menu, DWORD  exStyle, UINT  dpi);
static WINAPI BOOL (*pAlignRects)(LPRECT  rect, DWORD  b, DWORD  c, DWORD  d);
static WINAPI BOOL (*pAllowSetForegroundWindow)(DWORD  procid);
static WINAPI BOOL (*pAnimateWindow)(HWND  hwnd, DWORD  dwTime, DWORD  dwFlags);
static WINAPI BOOL (*pAnyPopup)(void);
static WINAPI BOOL (*pAppendMenuA)(HMENU  hMenu, UINT  flags, UINT_PTR  id, LPCSTR  data);
static WINAPI BOOL (*pAppendMenuW)(HMENU  hMenu, UINT  flags, UINT_PTR  id, LPCWSTR  data);
static WINAPI BOOL (*pAreDpiAwarenessContextsEqual)(DPI_AWARENESS_CONTEXT  ctx1, DPI_AWARENESS_CONTEXT  ctx2);
static WINAPI UINT (*pArrangeIconicWindows)(HWND  parent);
static WINAPI BOOL (*pAttachThreadInput)(DWORD  from, DWORD  to, BOOL  attach);
static WINAPI HDWP (*pBeginDeferWindowPos)(INT  count);
static WINAPI HDC (*pBeginPaint)(HWND  hwnd, PAINTSTRUCT*  lps);
static WINAPI BOOL (*pBlockInput)(BOOL  fBlockIt);
static WINAPI BOOL (*pBringWindowToTop)(HWND  hwnd);
static WINAPI LONG (*pBroadcastSystemMessageA)(DWORD  flags, LPDWORD  recipients, UINT  msg, WPARAM  wp, LPARAM  lp);
static WINAPI LONG (*pBroadcastSystemMessageExA)(DWORD  flags, LPDWORD  recipients, UINT  msg, WPARAM  wp, LPARAM  lp, PBSMINFO  pinfo);
static WINAPI LONG (*pBroadcastSystemMessageExW)(DWORD  flags, LPDWORD  recipients, UINT  msg, WPARAM  wp, LPARAM  lp, PBSMINFO  pinfo);
static WINAPI LONG (*pBroadcastSystemMessageW)(DWORD  flags, LPDWORD  recipients, UINT  msg, WPARAM  wp, LPARAM  lp);
static WINAPI void (*pCalcChildScroll)(HWND  hwnd, INT  scroll);
static WINAPI DWORD (*pCalcMenuBar)(HWND  hwnd, DWORD  left, DWORD  right, DWORD  top, RECT*  rect);
static WINAPI BOOL (*pCallMsgFilterA)(LPMSG  msg, INT  code);
static WINAPI BOOL (*pCallMsgFilterW)(LPMSG  msg, INT  code);
static WINAPI LRESULT (*pCallNextHookEx)(HHOOK  hhook, INT  code, WPARAM  wparam, LPARAM  lparam);
static WINAPI LRESULT (*pCallWindowProcA)(WNDPROC  func, HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam);
static WINAPI LRESULT (*pCallWindowProcW)(WNDPROC  func, HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam);
static WINAPI WORD (*pCascadeChildWindows)(HWND  parent, UINT  flags);
static WINAPI WORD (*pCascadeWindows)(HWND  hwndParent, UINT  wFlags, RECT*  lpRect, UINT  cKids, HWND*  lpKids);
static WINAPI BOOL (*pChangeClipboardChain)(HWND  hwnd, HWND  next);
static WINAPI LONG (*pChangeDisplaySettingsA)(LPDEVMODEA  devmode, DWORD  flags);
static WINAPI LONG (*pChangeDisplaySettingsExA)(LPCSTR  devname, LPDEVMODEA  devmode, HWND  hwnd, DWORD  flags, LPVOID  lparam);
static WINAPI LONG (*pChangeDisplaySettingsExW)(LPCWSTR  devname, LPDEVMODEW  devmode, HWND  hwnd, DWORD  flags, LPVOID  lparam);
static WINAPI LONG (*pChangeDisplaySettingsW)(LPDEVMODEW  devmode, DWORD  flags);
static WINAPI BOOL (*pChangeMenuA)(HMENU  hMenu, UINT  pos, LPCSTR  data, UINT  id, UINT  flags);
static WINAPI BOOL (*pChangeMenuW)(HMENU  hMenu, UINT  pos, LPCWSTR  data, UINT  id, UINT  flags);
static WINAPI BOOL (*pChangeWindowMessageFilter)(UINT  message, DWORD  flag);
static WINAPI BOOL (*pChangeWindowMessageFilterEx)(HWND  hwnd, UINT  message, DWORD  action, CHANGEFILTERSTRUCT*  changefilter);
static WINAPI LPSTR (*pCharLowerA)(LPSTR  str);
static WINAPI DWORD (*pCharLowerBuffA)(LPSTR  str, DWORD  len);
static WINAPI DWORD (*pCharLowerBuffW)(LPWSTR  str, DWORD  len);
static WINAPI LPWSTR (*pCharLowerW)(LPWSTR  str);
static WINAPI LPSTR (*pCharNextA)(LPCSTR  ptr);
static WINAPI LPSTR (*pCharNextExA)(WORD  codepage, LPCSTR  ptr, DWORD  flags);
static WINAPI LPWSTR (*pCharNextExW)(WORD  codepage, LPCWSTR  ptr, DWORD  flags);
static WINAPI LPWSTR (*pCharNextW)(LPCWSTR  x);
static WINAPI LPSTR (*pCharPrevA)(LPCSTR  start, LPCSTR  ptr);
static WINAPI LPSTR (*pCharPrevExA)(WORD  codepage, LPCSTR  start, LPCSTR  ptr, DWORD  flags);
static WINAPI LPSTR (*pCharPrevExW)(WORD  codepage, LPCWSTR  start, LPCWSTR  ptr, DWORD  flags);
static WINAPI LPWSTR (*pCharPrevW)(LPCWSTR  start, LPCWSTR  x);
static WINAPI BOOL (*pCharToOemA)(LPCSTR  s, LPSTR  d);
static WINAPI BOOL (*pCharToOemBuffA)(LPCSTR  s, LPSTR  d, DWORD  len);
static WINAPI BOOL (*pCharToOemBuffW)(LPCWSTR  s, LPSTR  d, DWORD  len);
static WINAPI BOOL (*pCharToOemW)(LPCWSTR  s, LPSTR  d);
static WINAPI LPSTR (*pCharUpperA)(LPSTR  str);
static WINAPI DWORD (*pCharUpperBuffA)(LPSTR  str, DWORD  len);
static WINAPI DWORD (*pCharUpperBuffW)(LPWSTR  str, DWORD  len);
static WINAPI LPWSTR (*pCharUpperW)(LPWSTR  str);
static WINAPI BOOL (*pCheckDlgButton)(HWND  hwnd, INT  id, UINT  check);
static WINAPI DWORD (*pCheckMenuItem)(HMENU  hMenu, UINT  id, UINT  flags);
static WINAPI BOOL (*pCheckMenuRadioItem)(HMENU  hMenu, UINT  first, UINT  last, UINT  check, UINT  flags);
static WINAPI BOOL (*pCheckRadioButton)(HWND  hwndDlg, int  firstID, int  lastID, int  checkID);
static WINAPI HWND (*pChildWindowFromPoint)(HWND  hwndParent, POINT  pt);
static WINAPI HWND (*pChildWindowFromPointEx)(HWND  hwndParent, POINT  pt, UINT  uFlags);
static WINAPI BOOL (*pClientToScreen)(HWND  hwnd, LPPOINT  lppnt);
static WINAPI BOOL (*pClipCursor)(RECT*  rect);
static WINAPI BOOL (*pCloseClipboard)(void);
static WINAPI BOOL (*pCloseDesktop)(HDESK  handle);
static WINAPI BOOL (*pCloseTouchInputHandle)(HTOUCHINPUT  handle);
static WINAPI BOOL (*pCloseWindow)(HWND  hwnd);
static WINAPI BOOL (*pCloseWindowStation)(HWINSTA  handle);
static WINAPI INT (*pCopyAcceleratorTableA)(HACCEL  src, LPACCEL  dst, INT  count);
static WINAPI INT (*pCopyAcceleratorTableW)(HACCEL  src, LPACCEL  dst, INT  count);
static WINAPI HICON (*pCopyIcon)(HICON  hIcon);
static WINAPI HANDLE (*pCopyImage)(HANDLE  hnd, UINT  type, INT  desiredx, INT  desiredy, UINT  flags);
static WINAPI BOOL (*pCopyRect)(RECT*  dest, RECT*  src);
static WINAPI INT (*pCountClipboardFormats)(void);
static WINAPI HACCEL (*pCreateAcceleratorTableA)(LPACCEL  lpaccel, INT  count);
static WINAPI HACCEL (*pCreateAcceleratorTableW)(LPACCEL  lpaccel, INT  count);
static WINAPI BOOL (*pCreateCaret)(HWND  hwnd, HBITMAP  bitmap, INT  width, INT  height);
static WINAPI HCURSOR (*pCreateCursor)(HINSTANCE  hInstance, INT  xHotSpot, INT  yHotSpot, INT  nWidth, INT  nHeight, LPCVOID  lpANDbits, LPCVOID  lpXORbits);
static WINAPI HDESK (*pCreateDesktopA)(LPCSTR  name, LPCSTR  device, LPDEVMODEA  devmode, DWORD  flags, ACCESS_MASK  access, LPSECURITY_ATTRIBUTES  sa);
static WINAPI HDESK (*pCreateDesktopW)(LPCWSTR  name, LPCWSTR  device, LPDEVMODEW  devmode, DWORD  flags, ACCESS_MASK  access, LPSECURITY_ATTRIBUTES  sa);
static WINAPI HWND (*pCreateDialogIndirectParamA)(HINSTANCE  hInst, LPCDLGTEMPLATEA  dlgTemplate, HWND  owner, DLGPROC  dlgProc, LPARAM  param);
static WINAPI HWND (*pCreateDialogIndirectParamAorW)(HINSTANCE  hInst, LPCVOID  dlgTemplate, HWND  owner, DLGPROC  dlgProc, LPARAM  param, DWORD  flags);
static WINAPI HWND (*pCreateDialogIndirectParamW)(HINSTANCE  hInst, LPCDLGTEMPLATEW  dlgTemplate, HWND  owner, DLGPROC  dlgProc, LPARAM  param);
static WINAPI HWND (*pCreateDialogParamA)(HINSTANCE  hInst, LPCSTR  name, HWND  owner, DLGPROC  dlgProc, LPARAM  param);
static WINAPI HWND (*pCreateDialogParamW)(HINSTANCE  hInst, LPCWSTR  name, HWND  owner, DLGPROC  dlgProc, LPARAM  param);
static WINAPI HICON (*pCreateIcon)(HINSTANCE  hInstance, INT  nWidth, INT  nHeight, BYTE  bPlanes, BYTE  bBitsPixel, LPCVOID  lpANDbits, LPCVOID  lpXORbits);
static WINAPI HICON (*pCreateIconFromResource)(LPBYTE  bits, UINT  cbSize, BOOL  bIcon, DWORD  dwVersion);
static WINAPI HICON (*pCreateIconFromResourceEx)(LPBYTE  bits, UINT  cbSize, BOOL  bIcon, DWORD  dwVersion, INT  width, INT  height, UINT  cFlag);
static WINAPI HICON (*pCreateIconIndirect)(PICONINFO  iconinfo);
static WINAPI HWND (*pCreateMDIWindowA)(LPCSTR  lpClassName, LPCSTR  lpWindowName, DWORD  dwStyle, INT  X, INT  Y, INT  nWidth, INT  nHeight, HWND  hWndParent, HINSTANCE  hInstance, LPARAM  lParam);
static WINAPI HWND (*pCreateMDIWindowW)(LPCWSTR  lpClassName, LPCWSTR  lpWindowName, DWORD  dwStyle, INT  X, INT  Y, INT  nWidth, INT  nHeight, HWND  hWndParent, HINSTANCE  hInstance, LPARAM  lParam);
static WINAPI HMENU (*pCreateMenu)(void);
static WINAPI HMENU (*pCreatePopupMenu)(void);
static WINAPI HWND (*pCreateWindowExA)(DWORD  exStyle, LPCSTR  className, LPCSTR  windowName, DWORD  style, INT  x, INT  y, INT  width, INT  height, HWND  parent, HMENU  menu, HINSTANCE  instance, LPVOID  data);
static WINAPI HWND (*pCreateWindowExW)(DWORD  exStyle, LPCWSTR  className, LPCWSTR  windowName, DWORD  style, INT  x, INT  y, INT  width, INT  height, HWND  parent, HMENU  menu, HINSTANCE  instance, LPVOID  data);
static WINAPI HWINSTA (*pCreateWindowStationA)(LPCSTR  name, DWORD  flags, ACCESS_MASK  access, LPSECURITY_ATTRIBUTES  sa);
static WINAPI HWINSTA (*pCreateWindowStationW)(LPCWSTR  name, DWORD  flags, ACCESS_MASK  access, LPSECURITY_ATTRIBUTES  sa);
static WINAPI BOOL (*pDdeAbandonTransaction)(DWORD  idInst, HCONV  hConv, DWORD  idTransaction);
static WINAPI LPBYTE (*pDdeAccessData)(HDDEDATA  hData, LPDWORD  pcbDataSize);
static WINAPI HDDEDATA (*pDdeAddData)(HDDEDATA  hData, LPBYTE  pSrc, DWORD  cb, DWORD  cbOff);
static WINAPI HDDEDATA (*pDdeClientTransaction)(LPBYTE  pData, DWORD  cbData, HCONV  hConv, HSZ  hszItem, UINT  wFmt, UINT  wType, DWORD  dwTimeout, LPDWORD  pdwResult);
static WINAPI INT (*pDdeCmpStringHandles)(HSZ  hsz1, HSZ  hsz2);
static WINAPI HCONV (*pDdeConnect)(DWORD  idInst, HSZ  hszService, HSZ  hszTopic, PCONVCONTEXT  pCC);
static WINAPI HCONVLIST (*pDdeConnectList)(DWORD  idInst, HSZ  hszService, HSZ  hszTopic, HCONVLIST  hConvList, PCONVCONTEXT  pCC);
static WINAPI HDDEDATA (*pDdeCreateDataHandle)(DWORD  idInst, LPBYTE  pSrc, DWORD  cb, DWORD  cbOff, HSZ  hszItem, UINT  wFmt, UINT  afCmd);
static WINAPI HSZ (*pDdeCreateStringHandleA)(DWORD  idInst, LPCSTR  psz, INT  codepage);
static WINAPI HSZ (*pDdeCreateStringHandleW)(DWORD  idInst, LPCWSTR  psz, INT  codepage);
static WINAPI BOOL (*pDdeDisconnect)(HCONV  hConv);
static WINAPI BOOL (*pDdeDisconnectList)(HCONVLIST  hConvList);
static WINAPI BOOL (*pDdeEnableCallback)(DWORD  idInst, HCONV  hConv, UINT  wCmd);
static WINAPI BOOL (*pDdeFreeDataHandle)(HDDEDATA  hData);
static WINAPI BOOL (*pDdeFreeStringHandle)(DWORD  idInst, HSZ  hsz);
static WINAPI DWORD (*pDdeGetData)(HDDEDATA  hData, LPBYTE  pDst, DWORD  cbMax, DWORD  cbOff);
static WINAPI UINT (*pDdeGetLastError)(DWORD  idInst);
static WINAPI BOOL (*pDdeImpersonateClient)(HCONV  hConv);
static WINAPI UINT (*pDdeInitializeA)(LPDWORD  pidInst, PFNCALLBACK  pfnCallback, DWORD  afCmd, DWORD  ulRes);
static WINAPI UINT (*pDdeInitializeW)(LPDWORD  pidInst, PFNCALLBACK  pfnCallback, DWORD  afCmd, DWORD  ulRes);
static WINAPI BOOL (*pDdeKeepStringHandle)(DWORD  idInst, HSZ  hsz);
static WINAPI HDDEDATA (*pDdeNameService)(DWORD  idInst, HSZ  hsz1, HSZ  hsz2, UINT  afCmd);
static WINAPI BOOL (*pDdePostAdvise)(DWORD  idInst, HSZ  hszTopic, HSZ  hszItem);
static WINAPI UINT (*pDdeQueryConvInfo)(HCONV  hConv, DWORD  id, PCONVINFO  lpConvInfo);
static WINAPI HCONV (*pDdeQueryNextServer)(HCONVLIST  hConvList, HCONV  hConvPrev);
static WINAPI DWORD (*pDdeQueryStringA)(DWORD  idInst, HSZ  hsz, LPSTR  psz, DWORD  cchMax, INT  iCodePage);
static WINAPI DWORD (*pDdeQueryStringW)(DWORD  idInst, HSZ  hsz, LPWSTR  psz, DWORD  cchMax, INT  iCodePage);
static WINAPI HCONV (*pDdeReconnect)(HCONV  hConv);
static WINAPI BOOL (*pDdeSetQualityOfService)(HWND  hwndClient, SECURITY_QUALITY_OF_SERVICE*  pqosNew, PSECURITY_QUALITY_OF_SERVICE  pqosPrev);
static WINAPI BOOL (*pDdeSetUserHandle)(HCONV  hConv, DWORD  id, DWORD  hUser);
static WINAPI BOOL (*pDdeUnaccessData)(HDDEDATA  hData);
static WINAPI BOOL (*pDdeUninitialize)(DWORD  idInst);
static WINAPI LRESULT (*pDefDlgProcA)(HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam);
static WINAPI LRESULT (*pDefDlgProcW)(HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam);
static WINAPI LRESULT (*pDefFrameProcA)(HWND  hwnd, HWND  hwndMDIClient, UINT  message, WPARAM  wParam, LPARAM  lParam);
static WINAPI LRESULT (*pDefFrameProcW)(HWND  hwnd, HWND  hwndMDIClient, UINT  message, WPARAM  wParam, LPARAM  lParam);
static WINAPI LRESULT (*pDefMDIChildProcA)(HWND  hwnd, UINT  message, WPARAM  wParam, LPARAM  lParam);
static WINAPI LRESULT (*pDefMDIChildProcW)(HWND  hwnd, UINT  message, WPARAM  wParam, LPARAM  lParam);
static WINAPI LRESULT (*pDefRawInputProc)(RAWINPUT**  data, INT  data_count, UINT  header_size);
static WINAPI LRESULT (*pDefWindowProcA)(HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam);
static WINAPI LRESULT (*pDefWindowProcW)(HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam);
static WINAPI HDWP (*pDeferWindowPos)(HDWP  hdwp, HWND  hwnd, HWND  hwndAfter, INT  x, INT  y, INT  cx, INT  cy, UINT  flags);
static WINAPI BOOL (*pDeleteMenu)(HMENU  hMenu, UINT  id, UINT  flags);
static WINAPI BOOL (*pDeregisterShellHookWindow)(HWND  hWnd);
static WINAPI BOOL (*pDestroyAcceleratorTable)(HACCEL  handle);
static WINAPI BOOL (*pDestroyCaret)(void);
static WINAPI BOOL (*pDestroyCursor)(HCURSOR  hCursor);
static WINAPI BOOL (*pDestroyIcon)(HICON  hIcon);
static WINAPI BOOL (*pDestroyMenu)(HMENU  hMenu);
static WINAPI BOOL (*pDestroyWindow)(HWND  hwnd);
static WINAPI INT_PTR (*pDialogBoxIndirectParamA)(HINSTANCE  hInstance, LPCDLGTEMPLATEA  template, HWND  owner, DLGPROC  dlgProc, LPARAM  param);
static WINAPI INT_PTR (*pDialogBoxIndirectParamAorW)(HINSTANCE  hInstance, LPCVOID  template, HWND  owner, DLGPROC  dlgProc, LPARAM  param, DWORD  flags);
static WINAPI INT_PTR (*pDialogBoxIndirectParamW)(HINSTANCE  hInstance, LPCDLGTEMPLATEW  template, HWND  owner, DLGPROC  dlgProc, LPARAM  param);
static WINAPI INT_PTR (*pDialogBoxParamA)(HINSTANCE  hInst, LPCSTR  name, HWND  owner, DLGPROC  dlgProc, LPARAM  param);
static WINAPI INT_PTR (*pDialogBoxParamW)(HINSTANCE  hInst, LPCWSTR  name, HWND  owner, DLGPROC  dlgProc, LPARAM  param);
static WINAPI void (*pDisableProcessWindowsGhosting)(void);
static WINAPI LRESULT (*pDispatchMessageA)(MSG*  msg);
static WINAPI LRESULT (*pDispatchMessageW)(MSG*  msg);
static WINAPI LONG (*pDisplayConfigGetDeviceInfo)(DISPLAYCONFIG_DEVICE_INFO_HEADER*  packet);
static WINAPI INT (*pDlgDirListA)(HWND  hDlg, LPSTR  spec, INT  idLBox, INT  idStatic, UINT  attrib);
static WINAPI INT (*pDlgDirListComboBoxA)(HWND  hDlg, LPSTR  spec, INT  idCBox, INT  idStatic, UINT  attrib);
static WINAPI INT (*pDlgDirListComboBoxW)(HWND  hDlg, LPWSTR  spec, INT  idCBox, INT  idStatic, UINT  attrib);
static WINAPI INT (*pDlgDirListW)(HWND  hDlg, LPWSTR  spec, INT  idLBox, INT  idStatic, UINT  attrib);
static WINAPI BOOL (*pDlgDirSelectComboBoxExA)(HWND  hwnd, LPSTR  str, INT  len, INT  id);
static WINAPI BOOL (*pDlgDirSelectComboBoxExW)(HWND  hwnd, LPWSTR  str, INT  len, INT  id);
static WINAPI BOOL (*pDlgDirSelectExA)(HWND  hwnd, LPSTR  str, INT  len, INT  id);
static WINAPI BOOL (*pDlgDirSelectExW)(HWND  hwnd, LPWSTR  str, INT  len, INT  id);
static WINAPI BOOL (*pDragDetect)(HWND  hWnd, POINT  pt);
static WINAPI BOOL (*pDrawAnimatedRects)(HWND  hwnd, INT  idAni, RECT*  lprcFrom, RECT*  lprcTo);
static WINAPI BOOL (*pDrawCaption)(HWND  hwnd, HDC  hdc, RECT*  lpRect, UINT  uFlags);
static WINAPI BOOL (*pDrawCaptionTempA)(HWND  hwnd, HDC  hdc, RECT*  rect, HFONT  hFont, HICON  hIcon, LPCSTR  str, UINT  uFlags);
static WINAPI BOOL (*pDrawCaptionTempW)(HWND  hwnd, HDC  hdc, RECT*  rect, HFONT  hFont, HICON  hIcon, LPCWSTR  str, UINT  uFlags);
static WINAPI BOOL (*pDrawEdge)(HDC  hdc, LPRECT  rc, UINT  edge, UINT  flags);
static WINAPI BOOL (*pDrawFocusRect)(HDC  hdc, RECT*  rc);
static WINAPI BOOL (*pDrawFrameControl)(HDC  hdc, LPRECT  rc, UINT  uType, UINT  uState);
static WINAPI BOOL (*pDrawIcon)(HDC  hdc, INT  x, INT  y, HICON  hIcon);
static WINAPI BOOL (*pDrawIconEx)(HDC  hdc, INT  x0, INT  y0, HICON  hIcon, INT  cxWidth, INT  cyWidth, UINT  istep, HBRUSH  hbr, UINT  flags);
static WINAPI BOOL (*pDrawMenuBar)(HWND  hWnd);
static WINAPI DWORD (*pDrawMenuBarTemp)(HWND  hwnd, HDC  hDC, LPRECT  lprect, HMENU  hMenu, HFONT  hFont);
static WINAPI BOOL (*pDrawStateA)(HDC  hdc, HBRUSH  hbr, DRAWSTATEPROC  func, LPARAM  ldata, WPARAM  wdata, INT  x, INT  y, INT  cx, INT  cy, UINT  flags);
static WINAPI BOOL (*pDrawStateW)(HDC  hdc, HBRUSH  hbr, DRAWSTATEPROC  func, LPARAM  ldata, WPARAM  wdata, INT  x, INT  y, INT  cx, INT  cy, UINT  flags);
static WINAPI INT (*pDrawTextA)(HDC  hdc, LPCSTR  str, INT  count, LPRECT  rect, UINT  flags);
static WINAPI INT (*pDrawTextExA)(HDC  hdc, LPSTR  str, INT  count, LPRECT  rect, UINT  flags, LPDRAWTEXTPARAMS  dtp);
static WINAPI INT (*pDrawTextExW)(HDC  hdc, LPWSTR  str, INT  i_count, LPRECT  rect, UINT  flags, LPDRAWTEXTPARAMS  dtp);
static WINAPI INT (*pDrawTextW)(HDC  hdc, LPCWSTR  str, INT  count, LPRECT  rect, UINT  flags);
static WINAPI LRESULT (*pEditWndProc)(HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam);
static WINAPI BOOL (*pEmptyClipboard)(void);
static WINAPI BOOL (*pEnableMenuItem)(HMENU  hMenu, UINT  id, UINT  wFlags);
static WINAPI BOOL (*pEnableMouseInPointer)(BOOL  enable);
static WINAPI BOOL (*pEnableScrollBar)(HWND  hwnd, UINT  nBar, UINT  flags);
static WINAPI BOOL (*pEnableWindow)(HWND  hwnd, BOOL  enable);
static WINAPI BOOL (*pEndDeferWindowPos)(HDWP  hdwp);
static WINAPI BOOL (*pEndDialog)(HWND  hwnd, INT_PTR  retval);
static WINAPI BOOL (*pEndMenu)(void);
static WINAPI BOOL (*pEndPaint)(HWND  hwnd, PAINTSTRUCT*  lps);
static WINAPI BOOL (*pEnumChildWindows)(HWND  parent, WNDENUMPROC  func, LPARAM  lParam);
static WINAPI UINT (*pEnumClipboardFormats)(UINT  format);
static WINAPI BOOL (*pEnumDesktopWindows)(HDESK  desktop, WNDENUMPROC  func, LPARAM  lparam);
static WINAPI BOOL (*pEnumDesktopsA)(HWINSTA  winsta, DESKTOPENUMPROCA  func, LPARAM  lparam);
static WINAPI BOOL (*pEnumDesktopsW)(HWINSTA  winsta, DESKTOPENUMPROCW  func, LPARAM  lparam);
static WINAPI BOOL (*pEnumDisplayDevicesA)(LPCSTR  device, DWORD  index, DISPLAY_DEVICEA*  info, DWORD  flags);
static WINAPI BOOL (*pEnumDisplayDevicesW)(LPCWSTR  device, DWORD  index, DISPLAY_DEVICEW*  info, DWORD  flags);
static WINAPI BOOL (*pEnumDisplayMonitors)(HDC  hdc, LPRECT  rect, MONITORENUMPROC  proc, LPARAM  lp);
static WINAPI BOOL (*pEnumDisplaySettingsA)(LPCSTR  name, DWORD  n, LPDEVMODEA  devmode);
static WINAPI BOOL (*pEnumDisplaySettingsExA)(LPCSTR  lpszDeviceName, DWORD  iModeNum, LPDEVMODEA  lpDevMode, DWORD  dwFlags);
static WINAPI BOOL (*pEnumDisplaySettingsExW)(LPCWSTR  lpszDeviceName, DWORD  iModeNum, LPDEVMODEW  lpDevMode, DWORD  dwFlags);
static WINAPI BOOL (*pEnumDisplaySettingsW)(LPCWSTR  name, DWORD  n, LPDEVMODEW  devmode);
static WINAPI INT (*pEnumPropsA)(HWND  hwnd, PROPENUMPROCA  func);
static WINAPI INT (*pEnumPropsExA)(HWND  hwnd, PROPENUMPROCEXA  func, LPARAM  lParam);
static WINAPI INT (*pEnumPropsExW)(HWND  hwnd, PROPENUMPROCEXW  func, LPARAM  lParam);
static WINAPI INT (*pEnumPropsW)(HWND  hwnd, PROPENUMPROCW  func);
static WINAPI BOOL (*pEnumThreadWindows)(DWORD  id, WNDENUMPROC  func, LPARAM  lParam);
static WINAPI BOOL (*pEnumWindowStationsA)(WINSTAENUMPROCA  func, LPARAM  lparam);
static WINAPI BOOL (*pEnumWindowStationsW)(WINSTAENUMPROCW  func, LPARAM  lparam);
static WINAPI BOOL (*pEnumWindows)(WNDENUMPROC  lpEnumFunc, LPARAM  lParam);
static WINAPI BOOL (*pEqualRect)(RECT*  rect1, RECT*  rect2);
static WINAPI INT (*pExcludeUpdateRgn)(HDC  hdc, HWND  hwnd);
static WINAPI BOOL (*pExitWindowsEx)(UINT  flags, DWORD  reason);
static WINAPI INT (*pFillRect)(HDC  hdc, RECT*  rect, HBRUSH  hbrush);
static WINAPI HWND (*pFindWindowA)(LPCSTR  className, LPCSTR  title);
static WINAPI HWND (*pFindWindowExA)(HWND  parent, HWND  child, LPCSTR  className, LPCSTR  title);
static WINAPI HWND (*pFindWindowExW)(HWND  parent, HWND  child, LPCWSTR  className, LPCWSTR  title);
static WINAPI HWND (*pFindWindowW)(LPCWSTR  className, LPCWSTR  title);
static WINAPI BOOL (*pFlashWindow)(HWND  hWnd, BOOL  bInvert);
static WINAPI BOOL (*pFlashWindowEx)(PFLASHWINFO  pfinfo);
static WINAPI INT (*pFrameRect)(HDC  hdc, RECT*  rect, HBRUSH  hbrush);
static WINAPI BOOL (*pFreeDDElParam)(UINT  msg, LPARAM  lParam);
static WINAPI HWND (*pGetActiveWindow)(void);
static WINAPI BOOL (*pGetAltTabInfoA)(HWND  hwnd, int  iItem, PALTTABINFO  pati, LPSTR  pszItemText, UINT  cchItemText);
static WINAPI BOOL (*pGetAltTabInfoW)(HWND  hwnd, int  iItem, PALTTABINFO  pati, LPWSTR  pszItemText, UINT  cchItemText);
static WINAPI HWND (*pGetAncestor)(HWND  hwnd, UINT  type);
static WINAPI DWORD (*pGetAppCompatFlags)(HTASK  hTask);
static WINAPI DWORD (*pGetAppCompatFlags2)(HTASK  hTask);
static WINAPI SHORT (*pGetAsyncKeyState)(INT  key);
static WINAPI BOOL (*pGetAutoRotationState)(AR_STATE*  state);
static WINAPI DPI_AWARENESS (*pGetAwarenessFromDpiAwarenessContext)(DPI_AWARENESS_CONTEXT  context);
static WINAPI HWND (*pGetCapture)(void);
static WINAPI UINT (*pGetCaretBlinkTime)(void);
static WINAPI BOOL (*pGetCaretPos)(LPPOINT  pt);
static WINAPI BOOL (*pGetClassInfoA)(HINSTANCE  hInstance, LPCSTR  name, WNDCLASSA*  wc);
static WINAPI BOOL (*pGetClassInfoExA)(HINSTANCE  hInstance, LPCSTR  name, WNDCLASSEXA*  wc);
static WINAPI BOOL (*pGetClassInfoExW)(HINSTANCE  hInstance, LPCWSTR  name, WNDCLASSEXW*  wc);
static WINAPI BOOL (*pGetClassInfoW)(HINSTANCE  hInstance, LPCWSTR  name, WNDCLASSW*  wc);
static WINAPI DWORD (*pGetClassLongA)(HWND  hwnd, INT  offset);
static WINAPI DWORD (*pGetClassLongW)(HWND  hwnd, INT  offset);
static WINAPI ULONG_PTR (*pGetClassLongPtrA)(HWND  hwnd, INT  offset);
static WINAPI ULONG_PTR (*pGetClassLongPtrW)(HWND  hwnd, INT  offset);
static WINAPI INT (*pGetClassNameA)(HWND  hwnd, LPSTR  buffer, INT  count);
static WINAPI INT (*pGetClassNameW)(HWND  hwnd, LPWSTR  buffer, INT  count);
static WINAPI WORD (*pGetClassWord)(HWND  hwnd, INT  offset);
static WINAPI BOOL (*pGetClientRect)(HWND  hwnd, LPRECT  rect);
static WINAPI BOOL (*pGetClipCursor)(RECT*  rect);
static WINAPI HANDLE (*pGetClipboardData)(UINT  format);
static WINAPI INT (*pGetClipboardFormatNameA)(UINT  format, LPSTR  buffer, INT  maxlen);
static WINAPI INT (*pGetClipboardFormatNameW)(UINT  format, LPWSTR  buffer, INT  maxlen);
static WINAPI HWND (*pGetClipboardOwner)(void);
static WINAPI DWORD (*pGetClipboardSequenceNumber)(void);
static WINAPI HWND (*pGetClipboardViewer)(void);
static WINAPI BOOL (*pGetComboBoxInfo)(HWND  hwndCombo, PCOMBOBOXINFO  pcbi);
static WINAPI BOOL (*pGetCurrentInputMessageSource)(INPUT_MESSAGE_SOURCE*  source);
static WINAPI HCURSOR (*pGetCursor)(void);
static WINAPI HCURSOR (*pGetCursorFrameInfo)(HCURSOR  hCursor, DWORD  reserved, DWORD  istep, DWORD*  rate_jiffies, DWORD*  num_steps);
static WINAPI BOOL (*pGetCursorInfo)(PCURSORINFO  pci);
static WINAPI BOOL (*pGetCursorPos)(POINT*  pt);
static WINAPI HDC (*pGetDC)(HWND  hwnd);
static WINAPI HDC (*pGetDCEx)(HWND  hwnd, HRGN  hrgnClip, DWORD  flags);
static WINAPI HWND (*pGetDesktopWindow)(void);
static WINAPI DWORD (*pGetDialogBaseUnits)(void);
static WINAPI BOOL (*pGetDisplayAutoRotationPreferences)(ORIENTATION_PREFERENCE*  orientation);
static WINAPI LONG (*pGetDisplayConfigBufferSizes)(UINT32  flags, UINT32*  num_path_info, UINT32*  num_mode_info);
static WINAPI INT (*pGetDlgCtrlID)(HWND  hwnd);
static WINAPI HWND (*pGetDlgItem)(HWND  hwndDlg, INT  id);
static WINAPI UINT (*pGetDlgItemInt)(HWND  hwnd, INT  id, BOOL*  translated, BOOL  fSigned);
static WINAPI UINT (*pGetDlgItemTextA)(HWND  hwnd, INT  id, LPSTR  str, INT  len);
static WINAPI UINT (*pGetDlgItemTextW)(HWND  hwnd, INT  id, LPWSTR  str, INT  len);
static WINAPI UINT (*pGetDoubleClickTime)(void);
static WINAPI BOOL (*pGetDpiForMonitorInternal)(HMONITOR  monitor, UINT  type, UINT*  x, UINT*  y);
static WINAPI UINT (*pGetDpiForSystem)(void);
static WINAPI UINT (*pGetDpiForWindow)(HWND  hwnd);
static WINAPI HWND (*pGetFocus)(void);
static WINAPI HWND (*pGetForegroundWindow)(void);
static WINAPI BOOL (*pGetGestureConfig)(HWND  hwnd, DWORD  reserved, DWORD  flags, UINT*  count, GESTURECONFIG*  config, UINT  size);
static WINAPI BOOL (*pGetGestureInfo)(HGESTUREINFO  handle, PGESTUREINFO  ptr);
static WINAPI BOOL (*pGetGUIThreadInfo)(DWORD  id, GUITHREADINFO*  info);
static WINAPI DWORD (*pGetGuiResources)(HANDLE  hProcess, DWORD  uiFlags);
static WINAPI BOOL (*pGetIconInfo)(HICON  hIcon, PICONINFO  iconinfo);
static WINAPI BOOL (*pGetIconInfoExA)(HICON  icon, ICONINFOEXA*  info);
static WINAPI BOOL (*pGetIconInfoExW)(HICON  icon, ICONINFOEXW*  info);
static WINAPI BOOL (*pGetInputState)(void);
static WINAPI UINT (*pGetInternalWindowPos)(HWND  hwnd, LPRECT  rectWnd, LPPOINT  ptIcon);
static WINAPI UINT (*pGetKBCodePage)(void);
static WINAPI INT (*pGetKeyNameTextA)(LONG  lParam, LPSTR  lpBuffer, INT  nSize);
static WINAPI INT (*pGetKeyNameTextW)(LONG  lParam, LPWSTR  lpBuffer, INT  nSize);
static WINAPI SHORT (*pGetKeyState)(INT  vkey);
static WINAPI HKL (*pGetKeyboardLayout)(DWORD  thread_id);
static WINAPI UINT (*pGetKeyboardLayoutList)(INT  nBuff, HKL*  layouts);
static WINAPI BOOL (*pGetKeyboardLayoutNameA)(LPSTR  pszKLID);
static WINAPI BOOL (*pGetKeyboardLayoutNameW)(LPWSTR  pwszKLID);
static WINAPI BOOL (*pGetKeyboardState)(LPBYTE  state);
static WINAPI INT (*pGetKeyboardType)(INT  nTypeFlag);
static WINAPI HWND (*pGetLastActivePopup)(HWND  hwnd);
static WINAPI BOOL (*pGetLastInputInfo)(PLASTINPUTINFO  plii);
static WINAPI BOOL (*pGetLayeredWindowAttributes)(HWND  hwnd, COLORREF*  key, BYTE*  alpha, DWORD*  flags);
static WINAPI DWORD (*pGetListBoxInfo)(HWND  hwnd);
static WINAPI HMENU (*pGetMenu)(HWND  hWnd);
static WINAPI BOOL (*pGetMenuBarInfo)(HWND  hwnd, LONG  idObject, LONG  idItem, PMENUBARINFO  pmbi);
static WINAPI DWORD (*pGetMenuCheckMarkDimensions)(void);
static WINAPI DWORD (*pGetMenuContextHelpId)(HMENU  hMenu);
static WINAPI UINT (*pGetMenuDefaultItem)(HMENU  hmenu, UINT  bypos, UINT  flags);
static WINAPI BOOL (*pGetMenuInfo)(HMENU  hMenu, LPMENUINFO  lpmi);
static WINAPI INT (*pGetMenuItemCount)(HMENU  hMenu);
static WINAPI UINT (*pGetMenuItemID)(HMENU  hMenu, INT  nPos);
static WINAPI BOOL (*pGetMenuItemInfoA)(HMENU  hmenu, UINT  item, BOOL  bypos, LPMENUITEMINFOA  lpmii);
static WINAPI BOOL (*pGetMenuItemInfoW)(HMENU  hmenu, UINT  item, BOOL  bypos, LPMENUITEMINFOW  lpmii);
static WINAPI BOOL (*pGetMenuItemRect)(HWND  hwnd, HMENU  hMenu, UINT  uItem, RECT*  rect);
static WINAPI UINT (*pGetMenuState)(HMENU  hMenu, UINT  wItemID, UINT  wFlags);
static WINAPI INT (*pGetMenuStringA)(HMENU  hMenu, UINT  wItemID, LPSTR  str, INT  nMaxSiz, UINT  wFlags);
static WINAPI INT (*pGetMenuStringW)(HMENU  hMenu, UINT  wItemID, LPWSTR  str, INT  nMaxSiz, UINT  wFlags);
static WINAPI BOOL (*pGetMessageA)(MSG*  msg, HWND  hwnd, UINT  first, UINT  last);
static WINAPI LPARAM (*pGetMessageExtraInfo)(void);
static WINAPI DWORD (*pGetMessagePos)(void);
static WINAPI LONG (*pGetMessageTime)(void);
static WINAPI BOOL (*pGetMessageW)(MSG*  msg, HWND  hwnd, UINT  first, UINT  last);
static WINAPI BOOL (*pGetMonitorInfoA)(HMONITOR  monitor, LPMONITORINFO  info);
static WINAPI BOOL (*pGetMonitorInfoW)(HMONITOR  monitor, LPMONITORINFO  info);
static WINAPI int (*pGetMouseMovePointsEx)(UINT  size, LPMOUSEMOVEPOINT  ptin, LPMOUSEMOVEPOINT  ptout, int  count, DWORD  res);
static WINAPI HWND (*pGetNextDlgGroupItem)(HWND  hwndDlg, HWND  hwndCtrl, BOOL  fPrevious);
static WINAPI HWND (*pGetNextDlgTabItem)(HWND  hwndDlg, HWND  hwndCtrl, BOOL  fPrevious);
static WINAPI HWND (*pGetOpenClipboardWindow)(void);
static WINAPI HWND (*pGetParent)(HWND  hwnd);
static WINAPI BOOL (*pGetPhysicalCursorPos)(POINT*  point);
static WINAPI BOOL (*pGetPointerDevices)(UINT32*  device_count, POINTER_DEVICE_INFO*  devices);
static WINAPI BOOL (*pGetPointerType)(UINT32  id, POINTER_INPUT_TYPE*  type);
static WINAPI INT (*pGetPriorityClipboardFormat)(UINT*  list, INT  nCount);
static WINAPI BOOL (*pGetProcessDefaultLayout)(DWORD*  layout);
static WINAPI BOOL (*pGetProcessDpiAwarenessInternal)(HANDLE  process, DPI_AWARENESS*  awareness);
static WINAPI HWINSTA (*pGetProcessWindowStation)(void);
static WINAPI HWND (*pGetProgmanWindow)(void);
static WINAPI HANDLE (*pGetPropA)(HWND  hwnd, LPCSTR  str);
static WINAPI HANDLE (*pGetPropW)(HWND  hwnd, LPCWSTR  str);
static WINAPI DWORD (*pGetQueueStatus)(UINT  flags);
static WINAPI UINT (*pGetRawInputBuffer)(RAWINPUT*  data, UINT*  data_size, UINT  header_size);
static WINAPI UINT (*pGetRawInputData)(HRAWINPUT  rawinput, UINT  command, void*  data, UINT*  data_size, UINT  header_size);
static WINAPI UINT (*pGetRawInputDeviceInfoA)(HANDLE  device, UINT  command, void*  data, UINT*  data_size);
static WINAPI UINT (*pGetRawInputDeviceInfoW)(HANDLE  device, UINT  command, void*  data, UINT*  data_size);
static WINAPI UINT (*pGetRawInputDeviceList)(RAWINPUTDEVICELIST*  devices, UINT*  device_count, UINT  size);
static WINAPI UINT (*pGetRegisteredRawInputDevices)(RAWINPUTDEVICE*  devices, UINT*  device_count, UINT  size);
static WINAPI BOOL (*pGetScrollBarInfo)(HWND  hwnd, LONG  idObject, LPSCROLLBARINFO  info);
static WINAPI BOOL (*pGetScrollInfo)(HWND  hwnd, INT  nBar, LPSCROLLINFO  info);
static WINAPI INT (*pGetScrollPos)(HWND  hwnd, INT  nBar);
static WINAPI BOOL (*pGetScrollRange)(HWND  hwnd, INT  nBar, LPINT  lpMin, LPINT  lpMax);
static WINAPI HWND (*pGetShellWindow)(void);
static WINAPI HMENU (*pGetSubMenu)(HMENU  hMenu, INT  nPos);
static WINAPI COLORREF (*pGetSysColor)(INT  nIndex);
static WINAPI HBRUSH (*pGetSysColorBrush)(INT  index);
static WINAPI HMENU (*pGetSystemMenu)(HWND  hWnd, BOOL  bRevert);
static WINAPI INT (*pGetSystemMetrics)(INT  index);
static WINAPI INT (*pGetSystemMetricsForDpi)(INT  index, UINT  dpi);
static WINAPI DWORD (*pGetTabbedTextExtentA)(HDC  hdc, LPCSTR  lpstr, INT  count, INT  cTabStops, INT*  lpTabPos);
static WINAPI DWORD (*pGetTabbedTextExtentW)(HDC  hdc, LPCWSTR  lpstr, INT  count, INT  cTabStops, INT*  lpTabPos);
static WINAPI HWND (*pGetTaskmanWindow)(void);
static WINAPI HDESK (*pGetThreadDesktop)(DWORD  thread);
static WINAPI DPI_AWARENESS_CONTEXT (*pGetThreadDpiAwarenessContext)(void);
static WINAPI BOOL (*pGetTitleBarInfo)(HWND  hwnd, PTITLEBARINFO  tbi);
static WINAPI HWND (*pGetTopWindow)(HWND  hwnd);
static WINAPI BOOL (*pGetTouchInputInfo)(HTOUCHINPUT  handle, UINT  count, TOUCHINPUT*  ptr, int  size);
static WINAPI BOOL (*pGetUpdateRect)(HWND  hwnd, LPRECT  rect, BOOL  erase);
static WINAPI INT (*pGetUpdateRgn)(HWND  hwnd, HRGN  hrgn, BOOL  erase);
static WINAPI BOOL (*pGetUpdatedClipboardFormats)(UINT*  formats, UINT  size, UINT*  out_size);
static WINAPI BOOL (*pGetUserObjectInformationA)(HANDLE  handle, INT  index, LPVOID  info, DWORD  len, LPDWORD  needed);
static WINAPI BOOL (*pGetUserObjectInformationW)(HANDLE  handle, INT  index, LPVOID  info, DWORD  len, LPDWORD  needed);
static WINAPI BOOL (*pGetUserObjectSecurity)(HANDLE  handle, PSECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  sid, DWORD  len, LPDWORD  needed);
static WINAPI HWND (*pGetWindow)(HWND  hwnd, UINT  rel);
static WINAPI DWORD (*pGetWindowContextHelpId)(HWND  hwnd);
static WINAPI HDC (*pGetWindowDC)(HWND  hwnd);
static WINAPI BOOL (*pGetWindowDisplayAffinity)(HWND  hwnd, DWORD*  affinity);
static WINAPI DPI_AWARENESS_CONTEXT (*pGetWindowDpiAwarenessContext)(HWND  hwnd);
static WINAPI BOOL (*pGetWindowInfo)(HWND  hwnd, PWINDOWINFO  pwi);
static WINAPI LONG (*pGetWindowLongA)(HWND  hwnd, INT  offset);
static WINAPI LONG_PTR (*pGetWindowLongPtrA)(HWND  hwnd, INT  offset);
static WINAPI LONG_PTR (*pGetWindowLongPtrW)(HWND  hwnd, INT  offset);
static WINAPI LONG (*pGetWindowLongW)(HWND  hwnd, INT  offset);
static WINAPI UINT (*pGetWindowModuleFileNameA)(HWND  hwnd, LPSTR  module, UINT  size);
static WINAPI UINT (*pGetWindowModuleFileNameW)(HWND  hwnd, LPWSTR  module, UINT  size);
static WINAPI BOOL (*pGetWindowPlacement)(HWND  hwnd, WINDOWPLACEMENT*  wndpl);
static WINAPI BOOL (*pGetWindowRect)(HWND  hwnd, LPRECT  rect);
static WINAPI INT (*pGetWindowRgn)(HWND  hwnd, HRGN  hrgn);
static WINAPI INT (*pGetWindowRgnBox)(HWND  hwnd, LPRECT  prect);
static WINAPI INT (*pGetWindowTextA)(HWND  hwnd, LPSTR  lpString, INT  nMaxCount);
static WINAPI INT (*pGetWindowTextLengthA)(HWND  hwnd);
static WINAPI INT (*pGetWindowTextLengthW)(HWND  hwnd);
static WINAPI INT (*pGetWindowTextW)(HWND  hwnd, LPWSTR  lpString, INT  nMaxCount);
static WINAPI DWORD (*pGetWindowThreadProcessId)(HWND  hwnd, LPDWORD  process);
static WINAPI WORD (*pGetWindowWord)(HWND  hwnd, INT  offset);
static WINAPI BOOL (*pGrayStringA)(HDC  hdc, HBRUSH  hbr, GRAYSTRINGPROC  gsprc, LPARAM  lParam, INT  cch, INT  x, INT  y, INT  cx, INT  cy);
static WINAPI BOOL (*pGrayStringW)(HDC  hdc, HBRUSH  hbr, GRAYSTRINGPROC  gsprc, LPARAM  lParam, INT  cch, INT  x, INT  y, INT  cx, INT  cy);
static WINAPI BOOL (*pHideCaret)(HWND  hwnd);
static WINAPI BOOL (*pHiliteMenuItem)(HWND  hWnd, HMENU  hMenu, UINT  wItemID, UINT  wHilite);
static WINAPI BOOL (*pImpersonateDdeClientWindow)(HWND  hWndClient, HWND  hWndServer);
static WINAPI BOOL (*pInSendMessage)(void);
static WINAPI DWORD (*pInSendMessageEx)(LPVOID  reserved);
static WINAPI BOOL (*pInflateRect)(LPRECT  rect, INT  x, INT  y);
static WINAPI BOOL (*pInsertMenuA)(HMENU  hMenu, UINT  pos, UINT  flags, UINT_PTR  id, LPCSTR  str);
static WINAPI BOOL (*pInsertMenuItemA)(HMENU  hMenu, UINT  uItem, BOOL  bypos, MENUITEMINFOA*  lpmii);
static WINAPI BOOL (*pInsertMenuItemW)(HMENU  hMenu, UINT  uItem, BOOL  bypos, MENUITEMINFOW*  lpmii);
static WINAPI BOOL (*pInsertMenuW)(HMENU  hMenu, UINT  pos, UINT  flags, UINT_PTR  id, LPCWSTR  str);
static WINAPI INT (*pInternalGetWindowText)(HWND  hwnd, LPWSTR  lpString, INT  nMaxCount);
static WINAPI BOOL (*pIntersectRect)(LPRECT  dest, RECT*  src1, RECT*  src2);
static WINAPI BOOL (*pInvalidateRect)(HWND  hwnd, RECT*  rect, BOOL  erase);
static WINAPI BOOL (*pInvalidateRgn)(HWND  hwnd, HRGN  hrgn, BOOL  erase);
static WINAPI BOOL (*pInvertRect)(HDC  hdc, RECT*  rect);
static WINAPI BOOL (*pIsCharAlphaA)(CHAR  x);
static WINAPI BOOL (*pIsCharAlphaNumericA)(CHAR  x);
static WINAPI BOOL (*pIsCharAlphaNumericW)(WCHAR  ch);
static WINAPI BOOL (*pIsCharAlphaW)(WCHAR  ch);
static WINAPI BOOL (*pIsCharLowerA)(CHAR  x);
static WINAPI BOOL (*pIsCharLowerW)(WCHAR  ch);
static WINAPI BOOL (*pIsCharUpperA)(CHAR  x);
static WINAPI BOOL (*pIsCharUpperW)(WCHAR  ch);
static WINAPI BOOL (*pIsChild)(HWND  parent, HWND  child);
static WINAPI BOOL (*pIsClipboardFormatAvailable)(UINT  format);
static WINAPI BOOL (*pIsDialogMessageA)(HWND  hwndDlg, LPMSG  pmsg);
static WINAPI BOOL (*pIsDialogMessageW)(HWND  hwndDlg, LPMSG  msg);
static WINAPI UINT (*pIsDlgButtonChecked)(HWND  hwnd, int  id);
static WINAPI BOOL (*pIsGUIThread)(BOOL  convert);
static WINAPI BOOL (*pIsHungAppWindow)(HWND  hWnd);
static WINAPI BOOL (*pIsIconic)(HWND  hWnd);
static WINAPI BOOL (*pIsMenu)(HMENU  hmenu);
static WINAPI BOOL (*pIsProcessDPIAware)(void);
static WINAPI BOOL (*pIsRectEmpty)(RECT*  rect);
static WINAPI BOOL (*pIsTouchWindow)(HWND  hwnd, PULONG  flags);
static WINAPI BOOL (*pIsValidDpiAwarenessContext)(DPI_AWARENESS_CONTEXT  context);
static WINAPI BOOL (*pIsWinEventHookInstalled)(DWORD  dwEvent);
static WINAPI BOOL (*pIsWindow)(HWND  hwnd);
static WINAPI BOOL (*pIsWindowEnabled)(HWND  hWnd);
static WINAPI BOOL (*pIsWindowRedirectedForPrint)(HWND  hwnd);
static WINAPI BOOL (*pIsWindowUnicode)(HWND  hwnd);
static WINAPI BOOL (*pIsWindowVisible)(HWND  hwnd);
static WINAPI BOOL (*pIsZoomed)(HWND  hWnd);
static WINAPI BOOL (*pKillSystemTimer)(HWND  hwnd, UINT_PTR  id);
static WINAPI BOOL (*pKillTimer)(HWND  hwnd, UINT_PTR  id);
static WINAPI HACCEL (*pLoadAcceleratorsA)(HINSTANCE  instance, LPCSTR  lpTableName);
static WINAPI HACCEL (*pLoadAcceleratorsW)(HINSTANCE  instance, LPCWSTR  name);
static WINAPI HBITMAP (*pLoadBitmapA)(HINSTANCE  instance, LPCSTR  name);
static WINAPI HBITMAP (*pLoadBitmapW)(HINSTANCE  instance, LPCWSTR  name);
static WINAPI HCURSOR (*pLoadCursorA)(HINSTANCE  hInstance, LPCSTR  name);
static WINAPI HCURSOR (*pLoadCursorFromFileA)(LPCSTR  name);
static WINAPI HCURSOR (*pLoadCursorFromFileW)(LPCWSTR  name);
static WINAPI HCURSOR (*pLoadCursorW)(HINSTANCE  hInstance, LPCWSTR  name);
static WINAPI HICON (*pLoadIconA)(HINSTANCE  hInstance, LPCSTR  name);
static WINAPI HICON (*pLoadIconW)(HINSTANCE  hInstance, LPCWSTR  name);
static WINAPI HANDLE (*pLoadImageA)(HINSTANCE  hinst, LPCSTR  name, UINT  type, INT  desiredx, INT  desiredy, UINT  loadflags);
static WINAPI HANDLE (*pLoadImageW)(HINSTANCE  hinst, LPCWSTR  name, UINT  type, INT  desiredx, INT  desiredy, UINT  loadflags);
static WINAPI HKL (*pLoadKeyboardLayoutA)(LPCSTR  pwszKLID, UINT  Flags);
static WINAPI HKL (*pLoadKeyboardLayoutW)(LPCWSTR  pwszKLID, UINT  Flags);
static WINAPI void (*pLoadLocalFonts)(void);
static WINAPI HMENU (*pLoadMenuA)(HINSTANCE  instance, LPCSTR  name);
static WINAPI HMENU (*pLoadMenuIndirectA)(LPCVOID  template);
static WINAPI HMENU (*pLoadMenuIndirectW)(LPCVOID  template);
static WINAPI HMENU (*pLoadMenuW)(HINSTANCE  instance, LPCWSTR  name);
static WINAPI INT (*pLoadStringA)(HINSTANCE  instance, UINT  resource_id, LPSTR  buffer, INT  buflen);
static WINAPI INT (*pLoadStringW)(HINSTANCE  instance, UINT  resource_id, LPWSTR  buffer, INT  buflen);
static WINAPI BOOL (*pLockSetForegroundWindow)(UINT  lockcode);
static WINAPI BOOL (*pLockWindowUpdate)(HWND  hwnd);
static WINAPI BOOL (*pLockWorkStation)(void);
static WINAPI BOOL (*pLogicalToPhysicalPoint)(HWND  hwnd, POINT*  point);
static WINAPI BOOL (*pLogicalToPhysicalPointForPerMonitorDPI)(HWND  hwnd, POINT*  pt);
static WINAPI INT (*pLookupIconIdFromDirectory)(LPBYTE  dir, BOOL  bIcon);
static WINAPI INT (*pLookupIconIdFromDirectoryEx)(LPBYTE  xdir, BOOL  bIcon, INT  width, INT  height, UINT  cFlag);
static WINAPI BOOL (*pMapDialogRect)(HWND  hwnd, LPRECT  rect);
static WINAPI UINT (*pMapVirtualKeyA)(UINT  code, UINT  maptype);
static WINAPI UINT (*pMapVirtualKeyExA)(UINT  code, UINT  maptype, HKL  hkl);
static WINAPI UINT (*pMapVirtualKeyExW)(UINT  code, UINT  maptype, HKL  hkl);
static WINAPI UINT (*pMapVirtualKeyW)(UINT  code, UINT  maptype);
static WINAPI INT (*pMapWindowPoints)(HWND  hwndFrom, HWND  hwndTo, LPPOINT  lppt, UINT  count);
static WINAPI INT (*pMenuItemFromPoint)(HWND  hWnd, HMENU  hMenu, POINT  ptScreen);
static WINAPI BOOL (*pMessageBeep)(UINT  i);
static WINAPI INT (*pMessageBoxA)(HWND  hWnd, LPCSTR  text, LPCSTR  title, UINT  type);
static WINAPI INT (*pMessageBoxExA)(HWND  hWnd, LPCSTR  text, LPCSTR  title, UINT  type, WORD  langid);
static WINAPI INT (*pMessageBoxExW)(HWND  hWnd, LPCWSTR  text, LPCWSTR  title, UINT  type, WORD  langid);
static WINAPI INT (*pMessageBoxIndirectA)(LPMSGBOXPARAMSA  msgbox);
static WINAPI INT (*pMessageBoxIndirectW)(LPMSGBOXPARAMSW  msgbox);
static WINAPI INT (*pMessageBoxTimeoutA)(HWND  hWnd, LPCSTR  text, LPCSTR  title, UINT  type, WORD  langid, DWORD  timeout);
static WINAPI INT (*pMessageBoxTimeoutW)(HWND  hWnd, LPCWSTR  text, LPCWSTR  title, UINT  type, WORD  langid, DWORD  timeout);
static WINAPI INT (*pMessageBoxW)(HWND  hwnd, LPCWSTR  text, LPCWSTR  title, UINT  type);
static WINAPI BOOL (*pModifyMenuA)(HMENU  hMenu, UINT  pos, UINT  flags, UINT_PTR  id, LPCSTR  str);
static WINAPI BOOL (*pModifyMenuW)(HMENU  hMenu, UINT  pos, UINT  flags, UINT_PTR  id, LPCWSTR  str);
static WINAPI HMONITOR (*pMonitorFromPoint)(POINT  pt, DWORD  flags);
static WINAPI HMONITOR (*pMonitorFromRect)(RECT*  rect, DWORD  flags);
static WINAPI HMONITOR (*pMonitorFromWindow)(HWND  hWnd, DWORD  dwFlags);
static WINAPI BOOL (*pMoveWindow)(HWND  hwnd, INT  x, INT  y, INT  cx, INT  cy, BOOL  repaint);
static WINAPI DWORD (*pMsgWaitForMultipleObjects)(DWORD  count, HANDLE*  handles, BOOL  wait_all, DWORD  timeout, DWORD  mask);
static WINAPI DWORD (*pMsgWaitForMultipleObjectsEx)(DWORD  count, HANDLE*  pHandles, DWORD  timeout, DWORD  mask, DWORD  flags);
static WINAPI void (*pNotifyWinEvent)(DWORD  event, HWND  hwnd, LONG  object_id, LONG  child_id);
static WINAPI DWORD (*pOemKeyScan)(WORD  oem);
static WINAPI BOOL (*pOemToCharA)(LPCSTR  s, LPSTR  d);
static WINAPI BOOL (*pOemToCharBuffA)(LPCSTR  s, LPSTR  d, DWORD  len);
static WINAPI BOOL (*pOemToCharBuffW)(LPCSTR  s, LPWSTR  d, DWORD  len);
static WINAPI BOOL (*pOemToCharW)(LPCSTR  s, LPWSTR  d);
static WINAPI BOOL (*pOffsetRect)(LPRECT  rect, INT  x, INT  y);
static WINAPI BOOL (*pOpenClipboard)(HWND  hwnd);
static WINAPI HDESK (*pOpenDesktopA)(LPCSTR  name, DWORD  flags, BOOL  inherit, ACCESS_MASK  access);
static WINAPI HDESK (*pOpenDesktopW)(LPCWSTR  name, DWORD  flags, BOOL  inherit, ACCESS_MASK  access);
static WINAPI BOOL (*pOpenIcon)(HWND  hwnd);
static WINAPI HDESK (*pOpenInputDesktop)(DWORD  flags, BOOL  inherit, ACCESS_MASK  access);
static WINAPI HWINSTA (*pOpenWindowStationA)(LPCSTR  name, BOOL  inherit, ACCESS_MASK  access);
static WINAPI HWINSTA (*pOpenWindowStationW)(LPCWSTR  name, BOOL  inherit, ACCESS_MASK  access);
static WINAPI LPARAM (*pPackDDElParam)(UINT  msg, UINT_PTR  uiLo, UINT_PTR  uiHi);
static WINAPI BOOL (*pPaintDesktop)(HDC  hdc);
static WINAPI BOOL (*pPeekMessageA)(MSG*  msg, HWND  hwnd, UINT  first, UINT  last, UINT  flags);
static WINAPI BOOL (*pPeekMessageW)(MSG*  msg_out, HWND  hwnd, UINT  first, UINT  last, UINT  flags);
static WINAPI BOOL (*pPhysicalToLogicalPoint)(HWND  hwnd, POINT*  point);
static WINAPI BOOL (*pPhysicalToLogicalPointForPerMonitorDPI)(HWND  hwnd, POINT*  pt);
static WINAPI BOOL (*pPostMessageA)(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam);
static WINAPI BOOL (*pPostMessageW)(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam);
static WINAPI void (*pPostQuitMessage)(INT  exit_code);
static WINAPI BOOL (*pPostThreadMessageA)(DWORD  thread, UINT  msg, WPARAM  wparam, LPARAM  lparam);
static WINAPI BOOL (*pPostThreadMessageW)(DWORD  thread, UINT  msg, WPARAM  wparam, LPARAM  lparam);
static WINAPI BOOL (*pPrintWindow)(HWND  hwnd, HDC  hdcBlt, UINT  nFlags);
static WINAPI UINT (*pPrivateExtractIconExA)(LPCSTR  lpstrFile, int  nIndex, HICON*  phIconLarge, HICON*  phIconSmall, UINT  nIcons);
static WINAPI UINT (*pPrivateExtractIconExW)(LPCWSTR  lpwstrFile, int  nIndex, HICON*  phIconLarge, HICON*  phIconSmall, UINT  nIcons);
static WINAPI UINT (*pPrivateExtractIconsA)(LPCSTR  lpstrFile, int  nIndex, int  sizeX, int  sizeY, HICON*  phicon, UINT*  piconid, UINT  nIcons, UINT  flags);
static WINAPI UINT (*pPrivateExtractIconsW)(LPCWSTR  lpwstrFile, int  nIndex, int  sizeX, int  sizeY, HICON*  phicon, UINT*  pIconId, UINT  nIcons, UINT  flags);
static WINAPI BOOL (*pPtInRect)(RECT*  rect, POINT  pt);
static WINAPI LONG (*pQueryDisplayConfig)(UINT32  flags, UINT32*  numpathelements, DISPLAYCONFIG_PATH_INFO*  pathinfo, UINT32*  numinfoelements, DISPLAYCONFIG_MODE_INFO*  modeinfo, DISPLAYCONFIG_TOPOLOGY_ID*  topologyid);
static WINAPI HWND (*pRealChildWindowFromPoint)(HWND  hwndParent, POINT  pt);
static WINAPI UINT (*pRealGetWindowClassA)(HWND  hwnd, LPSTR  buffer, UINT  count);
static WINAPI UINT (*pRealGetWindowClassW)(HWND  hwnd, LPWSTR  buffer, UINT  count);
static WINAPI BOOL (*pRedrawWindow)(HWND  hwnd, RECT*  rect, HRGN  hrgn, UINT  flags);
static WINAPI ATOM (*pRegisterClassA)(WNDCLASSA*  wc);
static WINAPI ATOM (*pRegisterClassExA)(WNDCLASSEXA*  wc);
static WINAPI ATOM (*pRegisterClassExW)(WNDCLASSEXW*  wc);
static WINAPI ATOM (*pRegisterClassW)(WNDCLASSW*  wc);
static WINAPI UINT (*pRegisterClipboardFormatA)(LPCSTR  name);
static WINAPI UINT (*pRegisterClipboardFormatW)(LPCWSTR  name);
static WINAPI HDEVNOTIFY (*pRegisterDeviceNotificationA)(HANDLE  hnd, LPVOID  notifyfilter, DWORD  flags);
static WINAPI HDEVNOTIFY (*pRegisterDeviceNotificationW)(HANDLE  hRecipient, LPVOID  pNotificationFilter, DWORD  dwFlags);
static WINAPI BOOL (*pRegisterHotKey)(HWND  hwnd, INT  id, UINT  modifiers, UINT  vk);
static WINAPI DWORD (*pRegisterLogonProcess)(HANDLE  hprocess, BOOL  x);
static WINAPI BOOL (*pRegisterPointerDeviceNotifications)(HWND  hwnd, BOOL  notifyrange);
static WINAPI HPOWERNOTIFY (*pRegisterPowerSettingNotification)(HANDLE  recipient, GUID*  guid, DWORD  flags);
static WINAPI BOOL (*pRegisterRawInputDevices)(RAWINPUTDEVICE*  devices, UINT  device_count, UINT  size);
static WINAPI int (*pRegisterServicesProcess)(DWORD  ServicesProcessId);
static WINAPI BOOL (*pRegisterShellHookWindow)(HWND  hWnd);
static WINAPI void (*pRegisterSystemThread)(DWORD  flags, DWORD  reserved);
static WINAPI DWORD (*pRegisterTasklist)(DWORD  x);
static WINAPI BOOL (*pRegisterTouchHitTestingWindow)(HWND  hwnd, ULONG  value);
static WINAPI BOOL (*pRegisterTouchWindow)(HWND  hwnd, ULONG  flags);
static WINAPI UINT (*pRegisterWindowMessageA)(LPCSTR  str);
static WINAPI UINT (*pRegisterWindowMessageW)(LPCWSTR  str);
static WINAPI BOOL (*pReleaseCapture)(void);
static WINAPI INT (*pReleaseDC)(HWND  hwnd, HDC  hdc);
static WINAPI BOOL (*pRemoveClipboardFormatListener)(HWND  hwnd);
static WINAPI BOOL (*pRemoveMenu)(HMENU  hMenu, UINT  id, UINT  flags);
static WINAPI HANDLE (*pRemovePropA)(HWND  hwnd, LPCSTR  str);
static WINAPI HANDLE (*pRemovePropW)(HWND  hwnd, LPCWSTR  str);
static WINAPI BOOL (*pReplyMessage)(LRESULT  result);
static WINAPI LPARAM (*pReuseDDElParam)(LPARAM  lParam, UINT  msgIn, UINT  msgOut, UINT_PTR  uiLo, UINT_PTR  uiHi);
static WINAPI BOOL (*pScreenToClient)(HWND  hwnd, LPPOINT  lppnt);
static WINAPI void (*pScrollChildren)(HWND  hWnd, UINT  uMsg, WPARAM  wParam, LPARAM  lParam);
static WINAPI BOOL (*pScrollDC)(HDC  hdc, INT  dx, INT  dy, RECT*  scroll, RECT*  clip, HRGN  ret_update_rgn, LPRECT  update_rect);
static WINAPI BOOL (*pScrollWindow)(HWND  hwnd, INT  dx, INT  dy, RECT*  rect, RECT*  clipRect);
static WINAPI INT (*pScrollWindowEx)(HWND  hwnd, INT  dx, INT  dy, RECT*  rect, RECT*  clipRect, HRGN  hrgnUpdate, LPRECT  rcUpdate, UINT  flags);
static WINAPI LRESULT (*pSendDlgItemMessageA)(HWND  hwnd, INT  id, UINT  msg, WPARAM  wParam, LPARAM  lParam);
static WINAPI LRESULT (*pSendDlgItemMessageW)(HWND  hwnd, INT  id, UINT  msg, WPARAM  wParam, LPARAM  lParam);
static WINAPI LRESULT (*pSendIMEMessageExA)(HWND  hwnd, LPARAM  lparam);
static WINAPI LRESULT (*pSendIMEMessageExW)(HWND  hwnd, LPARAM  lparam);
static WINAPI UINT (*pSendInput)(UINT  count, LPINPUT  inputs, int  size);
static WINAPI LRESULT (*pSendMessageA)(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam);
static WINAPI BOOL (*pSendMessageCallbackA)(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam, SENDASYNCPROC  callback, ULONG_PTR  data);
static WINAPI BOOL (*pSendMessageCallbackW)(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam, SENDASYNCPROC  callback, ULONG_PTR  data);
static WINAPI LRESULT (*pSendMessageTimeoutA)(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam, UINT  flags, UINT  timeout, PDWORD_PTR  res_ptr);
static WINAPI LRESULT (*pSendMessageTimeoutW)(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam, UINT  flags, UINT  timeout, PDWORD_PTR  res_ptr);
static WINAPI LRESULT (*pSendMessageW)(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam);
static WINAPI BOOL (*pSendNotifyMessageA)(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam);
static WINAPI BOOL (*pSendNotifyMessageW)(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam);
static WINAPI HWND (*pSetActiveWindow)(HWND  hwnd);
static WINAPI HWND (*pSetCapture)(HWND  hwnd);
static WINAPI BOOL (*pSetCaretBlinkTime)(UINT  msecs);
static WINAPI BOOL (*pSetCaretPos)(INT  x, INT  y);
static WINAPI DWORD (*pSetClassLongA)(HWND  hwnd, INT  offset, LONG  newval);
static WINAPI ULONG_PTR (*pSetClassLongPtrA)(HWND  hwnd, INT  offset, LONG_PTR  newval);
static WINAPI ULONG_PTR (*pSetClassLongPtrW)(HWND  hwnd, INT  offset, LONG_PTR  newval);
static WINAPI DWORD (*pSetClassLongW)(HWND  hwnd, INT  offset, LONG  newval);
static WINAPI WORD (*pSetClassWord)(HWND  hwnd, INT  offset, WORD  newval);
static WINAPI HANDLE (*pSetClipboardData)(UINT  format, HANDLE  data);
static WINAPI HWND (*pSetClipboardViewer)(HWND  hwnd);
static WINAPI UINT_PTR (*pSetCoalescableTimer)(HWND  hwnd, UINT_PTR  id, UINT  timeout, TIMERPROC  proc, ULONG  tolerance);
static WINAPI HCURSOR (*pSetCursor)(HCURSOR  hCursor);
static WINAPI BOOL (*pSetCursorPos)(INT  x, INT  y);
static WINAPI void (*pSetDebugErrorLevel)(DWORD  dwLevel);
static WINAPI BOOL (*pSetDeskWallPaper)(LPCSTR  filename);
static WINAPI BOOL (*pSetDlgItemInt)(HWND  hwnd, INT  id, UINT  value, BOOL  fSigned);
static WINAPI BOOL (*pSetDlgItemTextA)(HWND  hwnd, INT  id, LPCSTR  lpString);
static WINAPI BOOL (*pSetDlgItemTextW)(HWND  hwnd, INT  id, LPCWSTR  lpString);
static WINAPI BOOL (*pSetDoubleClickTime)(UINT  interval);
static WINAPI HWND (*pSetFocus)(HWND  hwnd);
static WINAPI BOOL (*pSetForegroundWindow)(HWND  hwnd);
static WINAPI BOOL (*pSetGestureConfig)(HWND  hwnd, DWORD  reserved, UINT  id, PGESTURECONFIG  config, UINT  size);
static WINAPI void (*pSetInternalWindowPos)(HWND  hwnd, UINT  showCmd, LPRECT  rect, LPPOINT  pt);
static WINAPI BOOL (*pSetKeyboardState)(LPBYTE  state);
static WINAPI void (*pSetLastErrorEx)(DWORD  error, DWORD  type);
static WINAPI BOOL (*pSetLayeredWindowAttributes)(HWND  hwnd, COLORREF  key, BYTE  alpha, DWORD  flags);
static WINAPI DWORD (*pSetLogonNotifyWindow)(HWINSTA  hwinsta, HWND  hwnd);
static WINAPI BOOL (*pSetMenu)(HWND  hWnd, HMENU  hMenu);
static WINAPI BOOL (*pSetMenuContextHelpId)(HMENU  hMenu, DWORD  dwContextHelpID);
static WINAPI BOOL (*pSetMenuDefaultItem)(HMENU  hmenu, UINT  uItem, UINT  bypos);
static WINAPI BOOL (*pSetMenuInfo)(HMENU  hMenu, LPCMENUINFO  lpmi);
static WINAPI BOOL (*pSetMenuItemBitmaps)(HMENU  hMenu, UINT  nPos, UINT  wFlags, HBITMAP  hNewUnCheck, HBITMAP  hNewCheck);
static WINAPI BOOL (*pSetMenuItemInfoA)(HMENU  hmenu, UINT  item, BOOL  bypos, MENUITEMINFOA*  lpmii);
static WINAPI BOOL (*pSetMenuItemInfoW)(HMENU  hmenu, UINT  item, BOOL  bypos, MENUITEMINFOW*  lpmii);
static WINAPI LPARAM (*pSetMessageExtraInfo)(LPARAM  lParam);
static WINAPI BOOL (*pSetMessageQueue)(INT  size);
static WINAPI HWND (*pSetParent)(HWND  hwnd, HWND  parent);
static WINAPI BOOL (*pSetPhysicalCursorPos)(INT  x, INT  y);
static WINAPI BOOL (*pSetProcessDPIAware)(void);
static WINAPI BOOL (*pSetProcessDefaultLayout)(DWORD  layout);
static WINAPI BOOL (*pSetProcessDpiAwarenessContext)(DPI_AWARENESS_CONTEXT  context);
static WINAPI BOOL (*pSetProcessDpiAwarenessInternal)(DPI_AWARENESS  awareness);
static WINAPI BOOL (*pSetProcessWindowStation)(HWINSTA  handle);
static WINAPI HWND (*pSetProgmanWindow)(HWND  hwnd);
static WINAPI BOOL (*pSetPropA)(HWND  hwnd, LPCSTR  str, HANDLE  handle);
static WINAPI BOOL (*pSetPropW)(HWND  hwnd, LPCWSTR  str, HANDLE  handle);
static WINAPI BOOL (*pSetRect)(LPRECT  rect, INT  left, INT  top, INT  right, INT  bottom);
static WINAPI BOOL (*pSetRectEmpty)(LPRECT  rect);
static WINAPI INT (*pSetScrollInfo)(HWND  hwnd, INT  nBar, SCROLLINFO*  info, BOOL  bRedraw);
static WINAPI INT (*pSetScrollPos)(HWND  hwnd, INT  nBar, INT  nPos, BOOL  bRedraw);
static WINAPI BOOL (*pSetScrollRange)(HWND  hwnd, INT  nBar, INT  minVal, INT  maxVal, BOOL  bRedraw);
static WINAPI BOOL (*pSetShellWindow)(HWND  hwndShell);
static WINAPI BOOL (*pSetShellWindowEx)(HWND  hwndShell, HWND  hwndListView);
static WINAPI BOOL (*pSetSysColors)(INT  count, INT*  colors, COLORREF*  values);
static WINAPI DWORD_PTR (*pSetSysColorsTemp)(COLORREF*  pPens, HBRUSH*  pBrushes, DWORD_PTR  n);
static WINAPI BOOL (*pSetSystemCursor)(HCURSOR  hcur, DWORD  id);
static WINAPI BOOL (*pSetSystemMenu)(HWND  hwnd, HMENU  hMenu);
static WINAPI UINT_PTR (*pSetSystemTimer)(HWND  hwnd, UINT_PTR  id, UINT  timeout, TIMERPROC  proc);
static WINAPI HWND (*pSetTaskmanWindow)(HWND  hwnd);
static WINAPI BOOL (*pSetThreadDesktop)(HDESK  handle);
static WINAPI DPI_AWARENESS_CONTEXT (*pSetThreadDpiAwarenessContext)(DPI_AWARENESS_CONTEXT  context);
static WINAPI UINT_PTR (*pSetTimer)(HWND  hwnd, UINT_PTR  id, UINT  timeout, TIMERPROC  proc);
static WINAPI BOOL (*pSetUserObjectInformationA)(HANDLE  handle, INT  index, LPVOID  info, DWORD  len);
static WINAPI BOOL (*pSetUserObjectInformationW)(HANDLE  handle, INT  index, LPVOID  info, DWORD  len);
static WINAPI BOOL (*pSetUserObjectSecurity)(HANDLE  handle, PSECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  sid);
static WINAPI HWINEVENTHOOK (*pSetWinEventHook)(DWORD  event_min, DWORD  event_max, HMODULE  inst, WINEVENTPROC  proc, DWORD  pid, DWORD  tid, DWORD  flags);
static WINAPI BOOL (*pSetWindowCompositionAttribute)(HWND  hwnd, void*  data);
static WINAPI BOOL (*pSetWindowContextHelpId)(HWND  hwnd, DWORD  id);
static WINAPI BOOL (*pSetWindowDisplayAffinity)(HWND  hwnd, DWORD  affinity);
static WINAPI LONG (*pSetWindowLongA)(HWND  hwnd, INT  offset, LONG  newval);
static WINAPI LONG_PTR (*pSetWindowLongPtrA)(HWND  hwnd, INT  offset, LONG_PTR  newval);
static WINAPI LONG_PTR (*pSetWindowLongPtrW)(HWND  hwnd, INT  offset, LONG_PTR  newval);
static WINAPI LONG (*pSetWindowLongW)(HWND  hwnd, INT  offset, LONG  newval);
static WINAPI BOOL (*pSetWindowPlacement)(HWND  hwnd, WINDOWPLACEMENT*  wpl);
static WINAPI BOOL (*pSetWindowPos)(HWND  hwnd, HWND  hwndInsertAfter, INT  x, INT  y, INT  cx, INT  cy, UINT  flags);
static WINAPI INT (*pSetWindowRgn)(HWND  hwnd, HRGN  hrgn, BOOL  bRedraw);
static WINAPI DWORD (*pSetWindowStationUser)(DWORD  x1, DWORD  x2);
static WINAPI BOOL (*pSetWindowTextA)(HWND  hwnd, LPCSTR  lpString);
static WINAPI BOOL (*pSetWindowTextW)(HWND  hwnd, LPCWSTR  lpString);
static WINAPI WORD (*pSetWindowWord)(HWND  hwnd, INT  offset, WORD  newval);
static WINAPI HHOOK (*pSetWindowsHookA)(INT  id, HOOKPROC  proc);
static WINAPI HHOOK (*pSetWindowsHookExA)(INT  id, HOOKPROC  proc, HINSTANCE  inst, DWORD  tid);
static WINAPI HHOOK (*pSetWindowsHookExW)(INT  id, HOOKPROC  proc, HINSTANCE  inst, DWORD  tid);
static WINAPI HHOOK (*pSetWindowsHookW)(INT  id, HOOKPROC  proc);
static WINAPI BOOL (*pShowCaret)(HWND  hwnd);
static WINAPI INT (*pShowCursor)(BOOL  bShow);
static WINAPI BOOL (*pShowOwnedPopups)(HWND  owner, BOOL  fShow);
static WINAPI BOOL (*pShowScrollBar)(HWND  hwnd, INT  nBar, BOOL  fShow);
static WINAPI BOOL (*pShowWindow)(HWND  hwnd, INT  cmd);
static WINAPI BOOL (*pShowWindowAsync)(HWND  hwnd, INT  cmd);
static WINAPI BOOL (*pShutdownBlockReasonCreate)(HWND  hwnd, LPCWSTR  reason);
static WINAPI BOOL (*pShutdownBlockReasonDestroy)(HWND  hwnd);
static WINAPI BOOL (*pSubtractRect)(LPRECT  dest, RECT*  src1, RECT*  src2);
static WINAPI BOOL (*pSwapMouseButton)(BOOL  fSwap);
static WINAPI BOOL (*pSwitchDesktop)(HDESK  hDesktop);
static WINAPI void (*pSwitchToThisWindow)(HWND  hwnd, BOOL  alt_tab);
static WINAPI BOOL (*pSystemParametersInfoA)(UINT  uiAction, UINT  uiParam, PVOID  pvParam, UINT  fuWinIni);
static WINAPI BOOL (*pSystemParametersInfoForDpi)(UINT  action, UINT  val, PVOID  ptr, UINT  winini, UINT  dpi);
static WINAPI BOOL (*pSystemParametersInfoW)(UINT  uiAction, UINT  uiParam, PVOID  pvParam, UINT  fWinIni);
static WINAPI LONG (*pTabbedTextOutA)(HDC  hdc, INT  x, INT  y, LPCSTR  lpstr, INT  count, INT  cTabStops, INT*  lpTabPos, INT  nTabOrg);
static WINAPI LONG (*pTabbedTextOutW)(HDC  hdc, INT  x, INT  y, LPCWSTR  str, INT  count, INT  cTabStops, INT*  lpTabPos, INT  nTabOrg);
static WINAPI WORD (*pTileChildWindows)(HWND  parent, UINT  flags);
static WINAPI WORD (*pTileWindows)(HWND  hwndParent, UINT  wFlags, RECT*  lpRect, UINT  cKids, HWND*  lpKids);
static WINAPI INT (*pToAscii)(UINT  virtKey, UINT  scanCode, BYTE*  lpKeyState, LPWORD  lpChar, UINT  flags);
static WINAPI INT (*pToAsciiEx)(UINT  virtKey, UINT  scanCode, BYTE*  lpKeyState, LPWORD  lpChar, UINT  flags, HKL  dwhkl);
static WINAPI INT (*pToUnicode)(UINT  virtKey, UINT  scanCode, BYTE*  lpKeyState, LPWSTR  lpwStr, int  size, UINT  flags);
static WINAPI INT (*pToUnicodeEx)(UINT  virtKey, UINT  scanCode, BYTE*  lpKeyState, LPWSTR  lpwStr, int  size, UINT  flags, HKL  hkl);
static WINAPI BOOL (*pTrackMouseEvent)(TRACKMOUSEEVENT*  ptme);
static WINAPI BOOL (*pTrackPopupMenu)(HMENU  hMenu, UINT  wFlags, INT  x, INT  y, INT  nReserved, HWND  hWnd, RECT*  lpRect);
static WINAPI BOOL (*pTrackPopupMenuEx)(HMENU  hMenu, UINT  wFlags, INT  x, INT  y, HWND  hWnd, LPTPMPARAMS  lpTpm);
static WINAPI INT (*pTranslateAcceleratorA)(HWND  hWnd, HACCEL  hAccel, LPMSG  msg);
static WINAPI INT (*pTranslateAcceleratorW)(HWND  hWnd, HACCEL  hAccel, LPMSG  msg);
static WINAPI BOOL (*pTranslateMDISysAccel)(HWND  hwndClient, LPMSG  msg);
static WINAPI BOOL (*pTranslateMessage)(MSG*  msg);
static WINAPI BOOL (*pUnhookWinEvent)(HWINEVENTHOOK  hEventHook);
static WINAPI BOOL (*pUnhookWindowsHook)(INT  id, HOOKPROC  proc);
static WINAPI BOOL (*pUnhookWindowsHookEx)(HHOOK  hhook);
static WINAPI BOOL (*pUnionRect)(LPRECT  dest, RECT*  src1, RECT*  src2);
static WINAPI BOOL (*pUnloadKeyboardLayout)(HKL  hkl);
static WINAPI BOOL (*pUnpackDDElParam)(UINT  msg, LPARAM  lParam, PUINT_PTR  uiLo, PUINT_PTR  uiHi);
static WINAPI BOOL (*pUnregisterClassA)(LPCSTR  className, HINSTANCE  hInstance);
static WINAPI BOOL (*pUnregisterClassW)(LPCWSTR  className, HINSTANCE  hInstance);
static WINAPI BOOL (*pUnregisterDeviceNotification)(HDEVNOTIFY  hnd);
static WINAPI BOOL (*pUnregisterHotKey)(HWND  hwnd, INT  id);
static WINAPI BOOL (*pUnregisterPowerSettingNotification)(HPOWERNOTIFY  handle);
static WINAPI BOOL (*pUnregisterTouchWindow)(HWND  hwnd);
static WINAPI BOOL (*pUpdateLayeredWindow)(HWND  hwnd, HDC  hdcDst, POINT*  pptDst, SIZE*  psize, HDC  hdcSrc, POINT*  pptSrc, COLORREF  crKey, BLENDFUNCTION*  pblend, DWORD  flags);
static WINAPI BOOL (*pUpdateLayeredWindowIndirect)(HWND  hwnd, UPDATELAYEREDWINDOWINFO*  info);
static WINAPI BOOL (*pUpdateWindow)(HWND  hwnd);
static WINAPI BOOL (*pUser32InitializeImmEntryTable)(DWORD  magic);
static WINAPI BOOL (*pUserClientDllInitialize)(HINSTANCE  inst, DWORD  reason, LPVOID  reserved);
static WINAPI BOOL (*pUserHandleGrantAccess)(HANDLE  handle, HANDLE  job, BOOL  grant);
static WINAPI UINT (*pUserRealizePalette)(HDC  hDC);
static WINAPI void (*pUserRegisterWowHandlers)(struct wow_handlers16*  new, struct wow_handlers32*  orig);
static WINAPI WORD (*pUserSignalProc)(UINT  uCode, DWORD  dwThreadOrProcessID, DWORD  dwFlags, HMODULE16  hModule);
static WINAPI BOOL (*pValidateRect)(HWND  hwnd, RECT*  rect);
static WINAPI BOOL (*pValidateRgn)(HWND  hwnd, HRGN  hrgn);
static WINAPI SHORT (*pVkKeyScanA)(CHAR  cChar);
static WINAPI WORD (*pVkKeyScanExA)(CHAR  cChar, HKL  dwhkl);
static WINAPI WORD (*pVkKeyScanExW)(WCHAR  cChar, HKL  dwhkl);
static WINAPI SHORT (*pVkKeyScanW)(WCHAR  cChar);
static WINAPI BOOL (*pWINNLSEnableIME)(HWND  hwnd, BOOL  enable);
static WINAPI BOOL (*pWINNLSGetEnableStatus)(HWND  hwnd);
static WINAPI UINT (*pWINNLSGetIMEHotkey)(HWND  hwnd);
static WINAPI DWORD (*pWaitForInputIdle)(HANDLE  hProcess, DWORD  dwTimeOut);
static WINAPI BOOL (*pWaitMessage)(void);
static WINAPI BOOL (*pWinHelpA)(HWND  hWnd, LPCSTR  lpHelpFile, UINT  wCommand, ULONG_PTR  dwData);
static WINAPI BOOL (*pWinHelpW)(HWND  hWnd, LPCWSTR  helpFile, UINT  command, ULONG_PTR  dwData);
static WINAPI HWND (*pWindowFromDC)(HDC  hdc);
static WINAPI HWND (*pWindowFromPoint)(POINT  pt);
static WINAPI void (*pkeybd_event)(BYTE  bVk, BYTE  bScan, DWORD  dwFlags, ULONG_PTR  dwExtraInfo);
static WINAPI void (*pmouse_event)(DWORD  dwFlags, DWORD  dx, DWORD  dy, DWORD  dwData, ULONG_PTR  dwExtraInfo);
static WINAPI INT (*pwsprintfA)(LPSTR  buffer, LPCSTR  spec);
static WINAPI INT (*pwsprintfW)(LPWSTR  buffer, LPCWSTR  spec);
static WINAPI INT (*pwvsprintfA)(LPSTR  buffer, LPCSTR  spec, __builtin_ms_va_list  args);
static WINAPI INT (*pwvsprintfW)(LPWSTR  buffer, LPCWSTR  spec, __builtin_ms_va_list  args);
static WINAPI BOOL (*p__wine_send_input)(HWND  hwnd, INPUT*  input);
static WINAPI BOOL (*p__wine_set_pixel_format)(HWND  hwnd, int  format);

extern WINAPI HKL wine32b_user32_ActivateKeyboardLayout(HKL  hLayout, UINT  flags) /* ../dlls/user32/input.c:899 */
{
	TRACE("Enter ActivateKeyboardLayout\n");
	return pActivateKeyboardLayout(hLayout, flags);
}

extern WINAPI void wine32a_user32_ActivateKeyboardLayout(void);  /* ../dlls/user32/input.c:899 */
__ASM_GLOBAL_FUNC(wine32a_user32_ActivateKeyboardLayout,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ActivateKeyboardLayout") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AddClipboardFormatListener(HWND  hwnd) /* ../dlls/user32/clipboard.c:1143 */
{
	TRACE("Enter AddClipboardFormatListener\n");
	return pAddClipboardFormatListener(hwnd);
}

extern WINAPI void wine32a_user32_AddClipboardFormatListener(void);  /* ../dlls/user32/clipboard.c:1143 */
__ASM_GLOBAL_FUNC(wine32a_user32_AddClipboardFormatListener,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AddClipboardFormatListener") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AdjustWindowRect(LPRECT  rect, DWORD  style, BOOL  menu) /* ../dlls/user32/nonclient.c:305 */
{
	TRACE("Enter AdjustWindowRect\n");
	return pAdjustWindowRect(rect, style, menu);
}

extern WINAPI void wine32a_user32_AdjustWindowRect(void);  /* ../dlls/user32/nonclient.c:305 */
__ASM_GLOBAL_FUNC(wine32a_user32_AdjustWindowRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AdjustWindowRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AdjustWindowRectEx(LPRECT  rect, DWORD  style, BOOL  menu, DWORD  exStyle) /* ../dlls/user32/nonclient.c:314 */
{
	TRACE("Enter AdjustWindowRectEx\n");
	return pAdjustWindowRectEx(rect, style, menu, exStyle);
}

extern WINAPI void wine32a_user32_AdjustWindowRectEx(void);  /* ../dlls/user32/nonclient.c:314 */
__ASM_GLOBAL_FUNC(wine32a_user32_AdjustWindowRectEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AdjustWindowRectEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AdjustWindowRectExForDpi(LPRECT  rect, DWORD  style, BOOL  menu, DWORD  exStyle, UINT  dpi) /* ../dlls/user32/nonclient.c:331 */
{
	TRACE("Enter AdjustWindowRectExForDpi\n");
	return pAdjustWindowRectExForDpi(rect, style, menu, exStyle, dpi);
}

extern WINAPI void wine32a_user32_AdjustWindowRectExForDpi(void);  /* ../dlls/user32/nonclient.c:331 */
__ASM_GLOBAL_FUNC(wine32a_user32_AdjustWindowRectExForDpi,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AdjustWindowRectExForDpi") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AlignRects(LPRECT  rect, DWORD  b, DWORD  c, DWORD  d) /* ../dlls/user32/misc.c:366 */
{
	TRACE("Enter AlignRects\n");
	return pAlignRects(rect, b, c, d);
}

extern WINAPI void wine32a_user32_AlignRects(void);  /* ../dlls/user32/misc.c:366 */
__ASM_GLOBAL_FUNC(wine32a_user32_AlignRects,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AlignRects") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AllowSetForegroundWindow(DWORD  procid) /* ../dlls/user32/winpos.c:640 */
{
	TRACE("Enter AllowSetForegroundWindow\n");
	return pAllowSetForegroundWindow(procid);
}

extern WINAPI void wine32a_user32_AllowSetForegroundWindow(void);  /* ../dlls/user32/winpos.c:640 */
__ASM_GLOBAL_FUNC(wine32a_user32_AllowSetForegroundWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AllowSetForegroundWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AnimateWindow(HWND  hwnd, DWORD  dwTime, DWORD  dwFlags) /* ../dlls/user32/winpos.c:1469 */
{
	TRACE("Enter AnimateWindow\n");
	return pAnimateWindow(hwnd, dwTime, dwFlags);
}

extern WINAPI void wine32a_user32_AnimateWindow(void);  /* ../dlls/user32/winpos.c:1469 */
__ASM_GLOBAL_FUNC(wine32a_user32_AnimateWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AnimateWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AnyPopup(void) /* ../dlls/user32/win.c:3629 */
{
	TRACE("Enter AnyPopup\n");
	return pAnyPopup();
}

extern WINAPI void wine32a_user32_AnyPopup(void);  /* ../dlls/user32/win.c:3629 */
__ASM_GLOBAL_FUNC(wine32a_user32_AnyPopup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AnyPopup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AppendMenuA(HMENU  hMenu, UINT  flags, UINT_PTR  id, LPCSTR  data) /* ../dlls/user32/menu.c:4059 */
{
	TRACE("Enter AppendMenuA\n");
	return pAppendMenuA(hMenu, flags, id, data);
}

extern WINAPI void wine32a_user32_AppendMenuA(void);  /* ../dlls/user32/menu.c:4059 */
__ASM_GLOBAL_FUNC(wine32a_user32_AppendMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AppendMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AppendMenuW(HMENU  hMenu, UINT  flags, UINT_PTR  id, LPCWSTR  data) /* ../dlls/user32/menu.c:4069 */
{
	TRACE("Enter AppendMenuW\n");
	return pAppendMenuW(hMenu, flags, id, data);
}

extern WINAPI void wine32a_user32_AppendMenuW(void);  /* ../dlls/user32/menu.c:4069 */
__ASM_GLOBAL_FUNC(wine32a_user32_AppendMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AppendMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AreDpiAwarenessContextsEqual(DPI_AWARENESS_CONTEXT  ctx1, DPI_AWARENESS_CONTEXT  ctx2) /* ../dlls/user32/sysparams.c:3465 */
{
	TRACE("Enter AreDpiAwarenessContextsEqual\n");
	return pAreDpiAwarenessContextsEqual(ctx1, ctx2);
}

extern WINAPI void wine32a_user32_AreDpiAwarenessContextsEqual(void);  /* ../dlls/user32/sysparams.c:3465 */
__ASM_GLOBAL_FUNC(wine32a_user32_AreDpiAwarenessContextsEqual,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AreDpiAwarenessContextsEqual") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_ArrangeIconicWindows(HWND  parent) /* ../dlls/user32/winpos.c:2540 */
{
	TRACE("Enter ArrangeIconicWindows\n");
	return pArrangeIconicWindows(parent);
}

extern WINAPI void wine32a_user32_ArrangeIconicWindows(void);  /* ../dlls/user32/winpos.c:2540 */
__ASM_GLOBAL_FUNC(wine32a_user32_ArrangeIconicWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ArrangeIconicWindows") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_AttachThreadInput(DWORD  from, DWORD  to, BOOL  attach) /* ../dlls/user32/input.c:531 */
{
	TRACE("Enter AttachThreadInput\n");
	return pAttachThreadInput(from, to, attach);
}

extern WINAPI void wine32a_user32_AttachThreadInput(void);  /* ../dlls/user32/input.c:531 */
__ASM_GLOBAL_FUNC(wine32a_user32_AttachThreadInput,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_AttachThreadInput") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDWP wine32b_user32_BeginDeferWindowPos(INT  count) /* ../dlls/user32/winpos.c:2385 */
{
	TRACE("Enter BeginDeferWindowPos\n");
	return pBeginDeferWindowPos(count);
}

extern WINAPI void wine32a_user32_BeginDeferWindowPos(void);  /* ../dlls/user32/winpos.c:2385 */
__ASM_GLOBAL_FUNC(wine32a_user32_BeginDeferWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_BeginDeferWindowPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDC wine32b_user32_BeginPaint(HWND  hwnd, PAINTSTRUCT*  lps) /* ../dlls/user32/painting.c:939 */
{
	TRACE("Enter BeginPaint\n");
	return pBeginPaint(hwnd, lps);
}

extern WINAPI void wine32a_user32_BeginPaint(void);  /* ../dlls/user32/painting.c:939 */
__ASM_GLOBAL_FUNC(wine32a_user32_BeginPaint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_BeginPaint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_BlockInput(BOOL  fBlockIt) /* ../dlls/user32/input.c:909 */
{
	TRACE("Enter BlockInput\n");
	return pBlockInput(fBlockIt);
}

extern WINAPI void wine32a_user32_BlockInput(void);  /* ../dlls/user32/input.c:909 */
__ASM_GLOBAL_FUNC(wine32a_user32_BlockInput,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_BlockInput") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_BringWindowToTop(HWND  hwnd) /* ../dlls/user32/winpos.c:662 */
{
	TRACE("Enter BringWindowToTop\n");
	return pBringWindowToTop(hwnd);
}

extern WINAPI void wine32a_user32_BringWindowToTop(void);  /* ../dlls/user32/winpos.c:662 */
__ASM_GLOBAL_FUNC(wine32a_user32_BringWindowToTop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_BringWindowToTop") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_BroadcastSystemMessageA(DWORD  flags, LPDWORD  recipients, UINT  msg, WPARAM  wp, LPARAM  lp) /* ../dlls/user32/message.c:4385 */
{
	TRACE("Enter BroadcastSystemMessageA\n");
	return pBroadcastSystemMessageA(flags, recipients, msg, wp, lp);
}

extern WINAPI void wine32a_user32_BroadcastSystemMessageA(void);  /* ../dlls/user32/message.c:4385 */
__ASM_GLOBAL_FUNC(wine32a_user32_BroadcastSystemMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_BroadcastSystemMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_BroadcastSystemMessageExA(DWORD  flags, LPDWORD  recipients, UINT  msg, WPARAM  wp, LPARAM  lp, PBSMINFO  pinfo) /* ../dlls/user32/message.c:4402 */
{
	TRACE("Enter BroadcastSystemMessageExA\n");
	return pBroadcastSystemMessageExA(flags, recipients, msg, wp, lp, pinfo);
}

extern WINAPI void wine32a_user32_BroadcastSystemMessageExA(void);  /* ../dlls/user32/message.c:4402 */
__ASM_GLOBAL_FUNC(wine32a_user32_BroadcastSystemMessageExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_BroadcastSystemMessageExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_BroadcastSystemMessageExW(DWORD  flags, LPDWORD  recipients, UINT  msg, WPARAM  wp, LPARAM  lp, PBSMINFO  pinfo) /* ../dlls/user32/message.c:4412 */
{
	TRACE("Enter BroadcastSystemMessageExW\n");
	return pBroadcastSystemMessageExW(flags, recipients, msg, wp, lp, pinfo);
}

extern WINAPI void wine32a_user32_BroadcastSystemMessageExW(void);  /* ../dlls/user32/message.c:4412 */
__ASM_GLOBAL_FUNC(wine32a_user32_BroadcastSystemMessageExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_BroadcastSystemMessageExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_BroadcastSystemMessageW(DWORD  flags, LPDWORD  recipients, UINT  msg, WPARAM  wp, LPARAM  lp) /* ../dlls/user32/message.c:4394 */
{
	TRACE("Enter BroadcastSystemMessageW\n");
	return pBroadcastSystemMessageW(flags, recipients, msg, wp, lp);
}

extern WINAPI void wine32a_user32_BroadcastSystemMessageW(void);  /* ../dlls/user32/message.c:4394 */
__ASM_GLOBAL_FUNC(wine32a_user32_BroadcastSystemMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_BroadcastSystemMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_CalcChildScroll(HWND  hwnd, INT  scroll) /* ../dlls/user32/mdi.c:1686 */
{
	TRACE("Enter CalcChildScroll\n");
	return pCalcChildScroll(hwnd, scroll);
}

extern WINAPI void wine32a_user32_CalcChildScroll(void);  /* ../dlls/user32/mdi.c:1686 */
__ASM_GLOBAL_FUNC(wine32a_user32_CalcChildScroll,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CalcChildScroll") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_CalcMenuBar(HWND  hwnd, DWORD  left, DWORD  right, DWORD  top, RECT*  rect) /* ../dlls/user32/menu.c:5498 */
{
	TRACE("Enter CalcMenuBar\n");
	return pCalcMenuBar(hwnd, left, right, top, rect);
}

extern WINAPI void wine32a_user32_CalcMenuBar(void);  /* ../dlls/user32/menu.c:5498 */
__ASM_GLOBAL_FUNC(wine32a_user32_CalcMenuBar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CalcMenuBar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CallMsgFilterA(LPMSG  msg, INT  code) /* ../dlls/user32/hook.c:667 */
{
	TRACE("Enter CallMsgFilterA\n");
	return pCallMsgFilterA(msg, code);
}

extern WINAPI void wine32a_user32_CallMsgFilterA(void);  /* ../dlls/user32/hook.c:667 */
__ASM_GLOBAL_FUNC(wine32a_user32_CallMsgFilterA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CallMsgFilterA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CallMsgFilterW(LPMSG  msg, INT  code) /* ../dlls/user32/hook.c:677 */
{
	TRACE("Enter CallMsgFilterW\n");
	return pCallMsgFilterW(msg, code);
}

extern WINAPI void wine32a_user32_CallMsgFilterW(void);  /* ../dlls/user32/hook.c:677 */
__ASM_GLOBAL_FUNC(wine32a_user32_CallMsgFilterW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CallMsgFilterW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_CallNextHookEx(HHOOK  hhook, INT  code, WPARAM  wparam, LPARAM  lparam) /* ../dlls/user32/hook.c:604 */
{
	TRACE("Enter CallNextHookEx\n");
	return pCallNextHookEx(hhook, code, wparam, lparam);
}

extern WINAPI void wine32a_user32_CallNextHookEx(void);  /* ../dlls/user32/hook.c:604 */
__ASM_GLOBAL_FUNC(wine32a_user32_CallNextHookEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CallNextHookEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_CallWindowProcA(WNDPROC  func, HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/winproc.c:991 */
{
	TRACE("Enter CallWindowProcA\n");
	return pCallWindowProcA(func, hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_user32_CallWindowProcA(void);  /* ../dlls/user32/winproc.c:991 */
__ASM_GLOBAL_FUNC(wine32a_user32_CallWindowProcA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CallWindowProcA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_CallWindowProcW(WNDPROC  func, HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/winproc.c:1021 */
{
	TRACE("Enter CallWindowProcW\n");
	return pCallWindowProcW(func, hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_user32_CallWindowProcW(void);  /* ../dlls/user32/winproc.c:1021 */
__ASM_GLOBAL_FUNC(wine32a_user32_CallWindowProcW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CallWindowProcW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_CascadeChildWindows(HWND  parent, UINT  flags) /* ../dlls/user32/mdi.c:1858 */
{
	TRACE("Enter CascadeChildWindows\n");
	return pCascadeChildWindows(parent, flags);
}

extern WINAPI void wine32a_user32_CascadeChildWindows(void);  /* ../dlls/user32/mdi.c:1858 */
__ASM_GLOBAL_FUNC(wine32a_user32_CascadeChildWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CascadeChildWindows") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_CascadeWindows(HWND  hwndParent, UINT  wFlags, RECT*  lpRect, UINT  cKids, HWND*  lpKids) /* ../dlls/user32/mdi.c:1847 */
{
	TRACE("Enter CascadeWindows\n");
	return pCascadeWindows(hwndParent, wFlags, lpRect, cKids, lpKids);
}

extern WINAPI void wine32a_user32_CascadeWindows(void);  /* ../dlls/user32/mdi.c:1847 */
__ASM_GLOBAL_FUNC(wine32a_user32_CascadeWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CascadeWindows") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ChangeClipboardChain(HWND  hwnd, HWND  next) /* ../dlls/user32/clipboard.c:851 */
{
	TRACE("Enter ChangeClipboardChain\n");
	return pChangeClipboardChain(hwnd, next);
}

extern WINAPI void wine32a_user32_ChangeClipboardChain(void);  /* ../dlls/user32/clipboard.c:851 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChangeClipboardChain,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChangeClipboardChain") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_ChangeDisplaySettingsA(LPDEVMODEA  devmode, DWORD  flags) /* ../dlls/user32/sysparams.c:3150 */
{
	TRACE("Enter ChangeDisplaySettingsA\n");
	return pChangeDisplaySettingsA(devmode, flags);
}

extern WINAPI void wine32a_user32_ChangeDisplaySettingsA(void);  /* ../dlls/user32/sysparams.c:3150 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChangeDisplaySettingsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChangeDisplaySettingsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_ChangeDisplaySettingsExA(LPCSTR  devname, LPDEVMODEA  devmode, HWND  hwnd, DWORD  flags, LPVOID  lparam) /* ../dlls/user32/sysparams.c:3172 */
{
	TRACE("Enter ChangeDisplaySettingsExA\n");
	return pChangeDisplaySettingsExA(devname, devmode, hwnd, flags, lparam);
}

extern WINAPI void wine32a_user32_ChangeDisplaySettingsExA(void);  /* ../dlls/user32/sysparams.c:3172 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChangeDisplaySettingsExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChangeDisplaySettingsExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_ChangeDisplaySettingsExW(LPCWSTR  devname, LPDEVMODEW  devmode, HWND  hwnd, DWORD  flags, LPVOID  lparam) /* ../dlls/user32/sysparams.c:3207 */
{
	TRACE("Enter ChangeDisplaySettingsExW\n");
	return pChangeDisplaySettingsExW(devname, devmode, hwnd, flags, lparam);
}

extern WINAPI void wine32a_user32_ChangeDisplaySettingsExW(void);  /* ../dlls/user32/sysparams.c:3207 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChangeDisplaySettingsExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChangeDisplaySettingsExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_ChangeDisplaySettingsW(LPDEVMODEW  devmode, DWORD  flags) /* ../dlls/user32/sysparams.c:3161 */
{
	TRACE("Enter ChangeDisplaySettingsW\n");
	return pChangeDisplaySettingsW(devmode, flags);
}

extern WINAPI void wine32a_user32_ChangeDisplaySettingsW(void);  /* ../dlls/user32/sysparams.c:3161 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChangeDisplaySettingsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChangeDisplaySettingsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ChangeMenuA(HMENU  hMenu, UINT  pos, LPCSTR  data, UINT  id, UINT  flags) /* ../dlls/user32/menu.c:3665 */
{
	TRACE("Enter ChangeMenuA\n");
	return pChangeMenuA(hMenu, pos, data, id, flags);
}

extern WINAPI void wine32a_user32_ChangeMenuA(void);  /* ../dlls/user32/menu.c:3665 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChangeMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChangeMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ChangeMenuW(HMENU  hMenu, UINT  pos, LPCWSTR  data, UINT  id, UINT  flags) /* ../dlls/user32/menu.c:3685 */
{
	TRACE("Enter ChangeMenuW\n");
	return pChangeMenuW(hMenu, pos, data, id, flags);
}

extern WINAPI void wine32a_user32_ChangeMenuW(void);  /* ../dlls/user32/menu.c:3685 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChangeMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChangeMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ChangeWindowMessageFilter(UINT  message, DWORD  flag) /* ../dlls/user32/message.c:4660 */
{
	TRACE("Enter ChangeWindowMessageFilter\n");
	return pChangeWindowMessageFilter(message, flag);
}

extern WINAPI void wine32a_user32_ChangeWindowMessageFilter(void);  /* ../dlls/user32/message.c:4660 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChangeWindowMessageFilter,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChangeWindowMessageFilter") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ChangeWindowMessageFilterEx(HWND  hwnd, UINT  message, DWORD  action, CHANGEFILTERSTRUCT*  changefilter) /* ../dlls/user32/message.c:4669 */
{
	TRACE("Enter ChangeWindowMessageFilterEx\n");
	return pChangeWindowMessageFilterEx(hwnd, message, action, changefilter);
}

extern WINAPI void wine32a_user32_ChangeWindowMessageFilterEx(void);  /* ../dlls/user32/message.c:4669 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChangeWindowMessageFilterEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChangeWindowMessageFilterEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_user32_CharLowerA(LPSTR  str) /* ../dlls/user32/lstr.c:239 */
{
	TRACE("Enter CharLowerA\n");
	return pCharLowerA(str);
}

extern WINAPI void wine32a_user32_CharLowerA(void);  /* ../dlls/user32/lstr.c:239 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharLowerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharLowerA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_CharLowerBuffA(LPSTR  str, DWORD  len) /* ../dlls/user32/lstr.c:329 */
{
	TRACE("Enter CharLowerBuffA\n");
	return pCharLowerBuffA(str, len);
}

extern WINAPI void wine32a_user32_CharLowerBuffA(void);  /* ../dlls/user32/lstr.c:329 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharLowerBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharLowerBuffA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_CharLowerBuffW(LPWSTR  str, DWORD  len) /* ../dlls/user32/lstr.c:354 */
{
	TRACE("Enter CharLowerBuffW\n");
	return pCharLowerBuffW(str, len);
}

extern WINAPI void wine32a_user32_CharLowerBuffW(void);  /* ../dlls/user32/lstr.c:354 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharLowerBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharLowerBuffW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_user32_CharLowerW(LPWSTR  str) /* ../dlls/user32/lstr.c:291 */
{
	TRACE("Enter CharLowerW\n");
	return pCharLowerW(str);
}

extern WINAPI void wine32a_user32_CharLowerW(void);  /* ../dlls/user32/lstr.c:291 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharLowerW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharLowerW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_user32_CharNextA(LPCSTR  ptr) /* ../dlls/user32/lstr.c:44 */
{
	TRACE("Enter CharNextA\n");
	return pCharNextA(ptr);
}

extern WINAPI void wine32a_user32_CharNextA(void);  /* ../dlls/user32/lstr.c:44 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharNextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharNextA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_user32_CharNextExA(WORD  codepage, LPCSTR  ptr, DWORD  flags) /* ../dlls/user32/lstr.c:55 */
{
	TRACE("Enter CharNextExA\n");
	return pCharNextExA(codepage, ptr, flags);
}

extern WINAPI void wine32a_user32_CharNextExA(void);  /* ../dlls/user32/lstr.c:55 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharNextExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharNextExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_user32_CharNextExW(WORD  codepage, LPCWSTR  ptr, DWORD  flags) /* ../dlls/user32/lstr.c:66 */
{
	TRACE("Enter CharNextExW\n");
	return pCharNextExW(codepage, ptr, flags);
}

extern WINAPI void wine32a_user32_CharNextExW(void);  /* ../dlls/user32/lstr.c:66 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharNextExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharNextExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_user32_CharNextW(LPCWSTR  x) /* ../dlls/user32/lstr.c:76 */
{
	TRACE("Enter CharNextW\n");
	return pCharNextW(x);
}

extern WINAPI void wine32a_user32_CharNextW(void);  /* ../dlls/user32/lstr.c:76 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharNextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharNextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_user32_CharPrevA(LPCSTR  start, LPCSTR  ptr) /* ../dlls/user32/lstr.c:87 */
{
	TRACE("Enter CharPrevA\n");
	return pCharPrevA(start, ptr);
}

extern WINAPI void wine32a_user32_CharPrevA(void);  /* ../dlls/user32/lstr.c:87 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharPrevA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharPrevA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_user32_CharPrevExA(WORD  codepage, LPCSTR  start, LPCSTR  ptr, DWORD  flags) /* ../dlls/user32/lstr.c:102 */
{
	TRACE("Enter CharPrevExA\n");
	return pCharPrevExA(codepage, start, ptr, flags);
}

extern WINAPI void wine32a_user32_CharPrevExA(void);  /* ../dlls/user32/lstr.c:102 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharPrevExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharPrevExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_user32_CharPrevExW(WORD  codepage, LPCWSTR  start, LPCWSTR  ptr, DWORD  flags) /* ../dlls/user32/lstr.c:117 */
{
	TRACE("Enter CharPrevExW\n");
	return pCharPrevExW(codepage, start, ptr, flags);
}

extern WINAPI void wine32a_user32_CharPrevExW(void);  /* ../dlls/user32/lstr.c:117 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharPrevExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharPrevExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_user32_CharPrevW(LPCWSTR  start, LPCWSTR  x) /* ../dlls/user32/lstr.c:127 */
{
	TRACE("Enter CharPrevW\n");
	return pCharPrevW(start, x);
}

extern WINAPI void wine32a_user32_CharPrevW(void);  /* ../dlls/user32/lstr.c:127 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharPrevW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharPrevW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CharToOemA(LPCSTR  s, LPSTR  d) /* ../dlls/user32/lstr.c:137 */
{
	TRACE("Enter CharToOemA\n");
	return pCharToOemA(s, d);
}

extern WINAPI void wine32a_user32_CharToOemA(void);  /* ../dlls/user32/lstr.c:137 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharToOemA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharToOemA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CharToOemBuffA(LPCSTR  s, LPSTR  d, DWORD  len) /* ../dlls/user32/lstr.c:147 */
{
	TRACE("Enter CharToOemBuffA\n");
	return pCharToOemBuffA(s, d, len);
}

extern WINAPI void wine32a_user32_CharToOemBuffA(void);  /* ../dlls/user32/lstr.c:147 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharToOemBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharToOemBuffA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CharToOemBuffW(LPCWSTR  s, LPSTR  d, DWORD  len) /* ../dlls/user32/lstr.c:167 */
{
	TRACE("Enter CharToOemBuffW\n");
	return pCharToOemBuffW(s, d, len);
}

extern WINAPI void wine32a_user32_CharToOemBuffW(void);  /* ../dlls/user32/lstr.c:167 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharToOemBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharToOemBuffW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CharToOemW(LPCWSTR  s, LPSTR  d) /* ../dlls/user32/lstr.c:178 */
{
	TRACE("Enter CharToOemW\n");
	return pCharToOemW(s, d);
}

extern WINAPI void wine32a_user32_CharToOemW(void);  /* ../dlls/user32/lstr.c:178 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharToOemW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharToOemW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPSTR wine32b_user32_CharUpperA(LPSTR  str) /* ../dlls/user32/lstr.c:265 */
{
	TRACE("Enter CharUpperA\n");
	return pCharUpperA(str);
}

extern WINAPI void wine32a_user32_CharUpperA(void);  /* ../dlls/user32/lstr.c:265 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharUpperA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharUpperA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_CharUpperBuffA(LPSTR  str, DWORD  len) /* ../dlls/user32/lstr.c:364 */
{
	TRACE("Enter CharUpperBuffA\n");
	return pCharUpperBuffA(str, len);
}

extern WINAPI void wine32a_user32_CharUpperBuffA(void);  /* ../dlls/user32/lstr.c:364 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharUpperBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharUpperBuffA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_CharUpperBuffW(LPWSTR  str, DWORD  len) /* ../dlls/user32/lstr.c:389 */
{
	TRACE("Enter CharUpperBuffW\n");
	return pCharUpperBuffW(str, len);
}

extern WINAPI void wine32a_user32_CharUpperBuffW(void);  /* ../dlls/user32/lstr.c:389 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharUpperBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharUpperBuffW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPWSTR wine32b_user32_CharUpperW(LPWSTR  str) /* ../dlls/user32/lstr.c:310 */
{
	TRACE("Enter CharUpperW\n");
	return pCharUpperW(str);
}

extern WINAPI void wine32a_user32_CharUpperW(void);  /* ../dlls/user32/lstr.c:310 */
__ASM_GLOBAL_FUNC(wine32a_user32_CharUpperW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CharUpperW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CheckDlgButton(HWND  hwnd, INT  id, UINT  check) /* ../dlls/user32/dialog.c:1455 */
{
	TRACE("Enter CheckDlgButton\n");
	return pCheckDlgButton(hwnd, id, check);
}

extern WINAPI void wine32a_user32_CheckDlgButton(void);  /* ../dlls/user32/dialog.c:1455 */
__ASM_GLOBAL_FUNC(wine32a_user32_CheckDlgButton,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CheckDlgButton") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_CheckMenuItem(HMENU  hMenu, UINT  id, UINT  flags) /* ../dlls/user32/menu.c:3705 */
{
	TRACE("Enter CheckMenuItem\n");
	return pCheckMenuItem(hMenu, id, flags);
}

extern WINAPI void wine32a_user32_CheckMenuItem(void);  /* ../dlls/user32/menu.c:3705 */
__ASM_GLOBAL_FUNC(wine32a_user32_CheckMenuItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CheckMenuItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CheckMenuRadioItem(HMENU  hMenu, UINT  first, UINT  last, UINT  check, UINT  flags) /* ../dlls/user32/menu.c:5256 */
{
	TRACE("Enter CheckMenuRadioItem\n");
	return pCheckMenuRadioItem(hMenu, first, last, check, flags);
}

extern WINAPI void wine32a_user32_CheckMenuRadioItem(void);  /* ../dlls/user32/menu.c:5256 */
__ASM_GLOBAL_FUNC(wine32a_user32_CheckMenuRadioItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CheckMenuRadioItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CheckRadioButton(HWND  hwndDlg, int  firstID, int  lastID, int  checkID) /* ../dlls/user32/dialog.c:1502 */
{
	TRACE("Enter CheckRadioButton\n");
	return pCheckRadioButton(hwndDlg, firstID, lastID, checkID);
}

extern WINAPI void wine32a_user32_CheckRadioButton(void);  /* ../dlls/user32/dialog.c:1502 */
__ASM_GLOBAL_FUNC(wine32a_user32_CheckRadioButton,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CheckRadioButton") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_ChildWindowFromPoint(HWND  hwndParent, POINT  pt) /* ../dlls/user32/winpos.c:348 */
{
	TRACE("Enter ChildWindowFromPoint\n");
	return pChildWindowFromPoint(hwndParent, pt);
}

extern WINAPI void wine32a_user32_ChildWindowFromPoint(void);  /* ../dlls/user32/winpos.c:348 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChildWindowFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChildWindowFromPoint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_ChildWindowFromPointEx(HWND  hwndParent, POINT  pt, UINT  uFlags) /* ../dlls/user32/winpos.c:364 */
{
	TRACE("Enter ChildWindowFromPointEx\n");
	return pChildWindowFromPointEx(hwndParent, pt, uFlags);
}

extern WINAPI void wine32a_user32_ChildWindowFromPointEx(void);  /* ../dlls/user32/winpos.c:364 */
__ASM_GLOBAL_FUNC(wine32a_user32_ChildWindowFromPointEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ChildWindowFromPointEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ClientToScreen(HWND  hwnd, LPPOINT  lppnt) /* ../dlls/user32/winpos.c:580 */
{
	TRACE("Enter ClientToScreen\n");
	return pClientToScreen(hwnd, lppnt);
}

extern WINAPI void wine32a_user32_ClientToScreen(void);  /* ../dlls/user32/winpos.c:580 */
__ASM_GLOBAL_FUNC(wine32a_user32_ClientToScreen,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ClientToScreen") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ClipCursor(RECT*  rect) /* ../dlls/user32/cursoricon.c:2117 */
{
	TRACE("Enter ClipCursor\n");
	return pClipCursor(rect);
}

extern WINAPI void wine32a_user32_ClipCursor(void);  /* ../dlls/user32/cursoricon.c:2117 */
__ASM_GLOBAL_FUNC(wine32a_user32_ClipCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ClipCursor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CloseClipboard(void) /* ../dlls/user32/clipboard.c:716 */
{
	TRACE("Enter CloseClipboard\n");
	return pCloseClipboard();
}

extern WINAPI void wine32a_user32_CloseClipboard(void);  /* ../dlls/user32/clipboard.c:716 */
__ASM_GLOBAL_FUNC(wine32a_user32_CloseClipboard,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CloseClipboard") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CloseDesktop(HDESK  handle) /* ../dlls/user32/winstation.c:383 */
{
	TRACE("Enter CloseDesktop\n");
	return pCloseDesktop(handle);
}

extern WINAPI void wine32a_user32_CloseDesktop(void);  /* ../dlls/user32/winstation.c:383 */
__ASM_GLOBAL_FUNC(wine32a_user32_CloseDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CloseDesktop") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CloseTouchInputHandle(HTOUCHINPUT  handle) /* ../dlls/user32/win.c:4173 */
{
	TRACE("Enter CloseTouchInputHandle\n");
	return pCloseTouchInputHandle(handle);
}

extern WINAPI void wine32a_user32_CloseTouchInputHandle(void);  /* ../dlls/user32/win.c:4173 */
__ASM_GLOBAL_FUNC(wine32a_user32_CloseTouchInputHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CloseTouchInputHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CloseWindow(HWND  hwnd) /* ../dlls/user32/win.c:1938 */
{
	TRACE("Enter CloseWindow\n");
	return pCloseWindow(hwnd);
}

extern WINAPI void wine32a_user32_CloseWindow(void);  /* ../dlls/user32/win.c:1938 */
__ASM_GLOBAL_FUNC(wine32a_user32_CloseWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CloseWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CloseWindowStation(HWINSTA  handle) /* ../dlls/user32/winstation.c:179 */
{
	TRACE("Enter CloseWindowStation\n");
	return pCloseWindowStation(handle);
}

extern WINAPI void wine32a_user32_CloseWindowStation(void);  /* ../dlls/user32/winstation.c:179 */
__ASM_GLOBAL_FUNC(wine32a_user32_CloseWindowStation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CloseWindowStation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_CopyAcceleratorTableA(HACCEL  src, LPACCEL  dst, INT  count) /* ../dlls/user32/resource.c:103 */
{
	TRACE("Enter CopyAcceleratorTableA\n");
	return pCopyAcceleratorTableA(src, dst, count);
}

extern WINAPI void wine32a_user32_CopyAcceleratorTableA(void);  /* ../dlls/user32/resource.c:103 */
__ASM_GLOBAL_FUNC(wine32a_user32_CopyAcceleratorTableA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CopyAcceleratorTableA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_CopyAcceleratorTableW(HACCEL  src, LPACCEL  dst, INT  count) /* ../dlls/user32/resource.c:123 */
{
	TRACE("Enter CopyAcceleratorTableW\n");
	return pCopyAcceleratorTableW(src, dst, count);
}

extern WINAPI void wine32a_user32_CopyAcceleratorTableW(void);  /* ../dlls/user32/resource.c:123 */
__ASM_GLOBAL_FUNC(wine32a_user32_CopyAcceleratorTableW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CopyAcceleratorTableW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HICON wine32b_user32_CopyIcon(HICON  hIcon) /* ../dlls/user32/cursoricon.c:1950 */
{
	TRACE("Enter CopyIcon\n");
	return pCopyIcon(hIcon);
}

extern WINAPI void wine32a_user32_CopyIcon(void);  /* ../dlls/user32/cursoricon.c:1950 */
__ASM_GLOBAL_FUNC(wine32a_user32_CopyIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CopyIcon") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_user32_CopyImage(HANDLE  hnd, UINT  type, INT  desiredx, INT  desiredy, UINT  flags) /* ../dlls/user32/cursoricon.c:3095 */
{
	TRACE("Enter CopyImage\n");
	return pCopyImage(hnd, type, desiredx, desiredy, flags);
}

extern WINAPI void wine32a_user32_CopyImage(void);  /* ../dlls/user32/cursoricon.c:3095 */
__ASM_GLOBAL_FUNC(wine32a_user32_CopyImage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CopyImage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CopyRect(RECT*  dest, RECT*  src) /* ../dlls/user32/uitools.c:1273 */
{
	TRACE("Enter CopyRect\n");
	return pCopyRect(dest, src);
}

extern WINAPI void wine32a_user32_CopyRect(void);  /* ../dlls/user32/uitools.c:1273 */
__ASM_GLOBAL_FUNC(wine32a_user32_CopyRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CopyRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_CountClipboardFormats(void) /* ../dlls/user32/clipboard.c:935 */
{
	TRACE("Enter CountClipboardFormats\n");
	return pCountClipboardFormats();
}

extern WINAPI void wine32a_user32_CountClipboardFormats(void);  /* ../dlls/user32/clipboard.c:935 */
__ASM_GLOBAL_FUNC(wine32a_user32_CountClipboardFormats,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CountClipboardFormats") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HACCEL wine32b_user32_CreateAcceleratorTableA(LPACCEL  lpaccel, INT  count) /* ../dlls/user32/resource.c:152 */
{
	TRACE("Enter CreateAcceleratorTableA\n");
	return pCreateAcceleratorTableA(lpaccel, count);
}

extern WINAPI void wine32a_user32_CreateAcceleratorTableA(void);  /* ../dlls/user32/resource.c:152 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateAcceleratorTableA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateAcceleratorTableA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HACCEL wine32b_user32_CreateAcceleratorTableW(LPACCEL  lpaccel, INT  count) /* ../dlls/user32/resource.c:186 */
{
	TRACE("Enter CreateAcceleratorTableW\n");
	return pCreateAcceleratorTableW(lpaccel, count);
}

extern WINAPI void wine32a_user32_CreateAcceleratorTableW(void);  /* ../dlls/user32/resource.c:186 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateAcceleratorTableW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateAcceleratorTableW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_CreateCaret(HWND  hwnd, HBITMAP  bitmap, INT  width, INT  height) /* ../dlls/user32/caret.c:109 */
{
	TRACE("Enter CreateCaret\n");
	return pCreateCaret(hwnd, bitmap, width, height);
}

extern WINAPI void wine32a_user32_CreateCaret(void);  /* ../dlls/user32/caret.c:109 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateCaret,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateCaret") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCURSOR wine32b_user32_CreateCursor(HINSTANCE  hInstance, INT  xHotSpot, INT  yHotSpot, INT  nWidth, INT  nHeight, LPCVOID  lpANDbits, LPCVOID  lpXORbits) /* ../dlls/user32/cursoricon.c:1875 */
{
	TRACE("Enter CreateCursor\n");
	return pCreateCursor(hInstance, xHotSpot, yHotSpot, nWidth, nHeight, lpANDbits, lpXORbits);
}

extern WINAPI void wine32a_user32_CreateCursor(void);  /* ../dlls/user32/cursoricon.c:1875 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateCursor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDESK wine32b_user32_CreateDesktopA(LPCSTR  name, LPCSTR  device, LPDEVMODEA  devmode, DWORD  flags, ACCESS_MASK  access, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/user32/winstation.c:275 */
{
	TRACE("Enter CreateDesktopA\n");
	return pCreateDesktopA(name, device, devmode, flags, access, sa);
}

extern WINAPI void wine32a_user32_CreateDesktopA(void);  /* ../dlls/user32/winstation.c:275 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateDesktopA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateDesktopA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDESK wine32b_user32_CreateDesktopW(LPCWSTR  name, LPCWSTR  device, LPDEVMODEW  devmode, DWORD  flags, ACCESS_MASK  access, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/user32/winstation.c:299 */
{
	TRACE("Enter CreateDesktopW\n");
	return pCreateDesktopW(name, device, devmode, flags, access, sa);
}

extern WINAPI void wine32a_user32_CreateDesktopW(void);  /* ../dlls/user32/winstation.c:299 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateDesktopW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateDesktopW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_CreateDialogIndirectParamA(HINSTANCE  hInst, LPCDLGTEMPLATEA  dlgTemplate, HWND  owner, DLGPROC  dlgProc, LPARAM  param) /* ../dlls/user32/dialog.c:757 */
{
	TRACE("Enter CreateDialogIndirectParamA\n");
	return pCreateDialogIndirectParamA(hInst, dlgTemplate, owner, dlgProc, param);
}

extern WINAPI void wine32a_user32_CreateDialogIndirectParamA(void);  /* ../dlls/user32/dialog.c:757 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateDialogIndirectParamA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateDialogIndirectParamA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_CreateDialogIndirectParamAorW(HINSTANCE  hInst, LPCVOID  dlgTemplate, HWND  owner, DLGPROC  dlgProc, LPARAM  param, DWORD  flags) /* ../dlls/user32/dialog.c:747 */
{
	TRACE("Enter CreateDialogIndirectParamAorW\n");
	return pCreateDialogIndirectParamAorW(hInst, dlgTemplate, owner, dlgProc, param, flags);
}

extern WINAPI void wine32a_user32_CreateDialogIndirectParamAorW(void);  /* ../dlls/user32/dialog.c:747 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateDialogIndirectParamAorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateDialogIndirectParamAorW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_CreateDialogIndirectParamW(HINSTANCE  hInst, LPCDLGTEMPLATEW  dlgTemplate, HWND  owner, DLGPROC  dlgProc, LPARAM  param) /* ../dlls/user32/dialog.c:766 */
{
	TRACE("Enter CreateDialogIndirectParamW\n");
	return pCreateDialogIndirectParamW(hInst, dlgTemplate, owner, dlgProc, param);
}

extern WINAPI void wine32a_user32_CreateDialogIndirectParamW(void);  /* ../dlls/user32/dialog.c:766 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateDialogIndirectParamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateDialogIndirectParamW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_CreateDialogParamA(HINSTANCE  hInst, LPCSTR  name, HWND  owner, DLGPROC  dlgProc, LPARAM  param) /* ../dlls/user32/dialog.c:717 */
{
	TRACE("Enter CreateDialogParamA\n");
	return pCreateDialogParamA(hInst, name, owner, dlgProc, param);
}

extern WINAPI void wine32a_user32_CreateDialogParamA(void);  /* ../dlls/user32/dialog.c:717 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateDialogParamA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateDialogParamA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_CreateDialogParamW(HINSTANCE  hInst, LPCWSTR  name, HWND  owner, DLGPROC  dlgProc, LPARAM  param) /* ../dlls/user32/dialog.c:732 */
{
	TRACE("Enter CreateDialogParamW\n");
	return pCreateDialogParamW(hInst, name, owner, dlgProc, param);
}

extern WINAPI void wine32a_user32_CreateDialogParamW(void);  /* ../dlls/user32/dialog.c:732 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateDialogParamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateDialogParamW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HICON wine32b_user32_CreateIcon(HINSTANCE  hInstance, INT  nWidth, INT  nHeight, BYTE  bPlanes, BYTE  bBitsPixel, LPCVOID  lpANDbits, LPCVOID  lpXORbits) /* ../dlls/user32/cursoricon.c:1917 */
{
	TRACE("Enter CreateIcon\n");
	return pCreateIcon(hInstance, nWidth, nHeight, bPlanes, bBitsPixel, lpANDbits, lpXORbits);
}

extern WINAPI void wine32a_user32_CreateIcon(void);  /* ../dlls/user32/cursoricon.c:1917 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateIcon") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HICON wine32b_user32_CreateIconFromResource(LPBYTE  bits, UINT  cbSize, BOOL  bIcon, DWORD  dwVersion) /* ../dlls/user32/cursoricon.c:1710 */
{
	TRACE("Enter CreateIconFromResource\n");
	return pCreateIconFromResource(bits, cbSize, bIcon, dwVersion);
}

extern WINAPI void wine32a_user32_CreateIconFromResource(void);  /* ../dlls/user32/cursoricon.c:1710 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateIconFromResource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateIconFromResource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HICON wine32b_user32_CreateIconFromResourceEx(LPBYTE  bits, UINT  cbSize, BOOL  bIcon, DWORD  dwVersion, INT  width, INT  height, UINT  cFlag) /* ../dlls/user32/cursoricon.c:1663 */
{
	TRACE("Enter CreateIconFromResourceEx\n");
	return pCreateIconFromResourceEx(bits, cbSize, bIcon, dwVersion, width, height, cFlag);
}

extern WINAPI void wine32a_user32_CreateIconFromResourceEx(void);  /* ../dlls/user32/cursoricon.c:1663 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateIconFromResourceEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateIconFromResourceEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HICON wine32b_user32_CreateIconIndirect(PICONINFO  iconinfo) /* ../dlls/user32/cursoricon.c:2522 */
{
	TRACE("Enter CreateIconIndirect\n");
	return pCreateIconIndirect(iconinfo);
}

extern WINAPI void wine32a_user32_CreateIconIndirect(void);  /* ../dlls/user32/cursoricon.c:2522 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateIconIndirect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateIconIndirect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_CreateMDIWindowA(LPCSTR  lpClassName, LPCSTR  lpWindowName, DWORD  dwStyle, INT  X, INT  Y, INT  nWidth, INT  nHeight, HWND  hWndParent, HINSTANCE  hInstance, LPARAM  lParam) /* ../dlls/user32/mdi.c:1593 */
{
	TRACE("Enter CreateMDIWindowA\n");
	return pCreateMDIWindowA(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam);
}

extern WINAPI void wine32a_user32_CreateMDIWindowA(void);  /* ../dlls/user32/mdi.c:1593 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateMDIWindowA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateMDIWindowA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $40, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_CreateMDIWindowW(LPCWSTR  lpClassName, LPCWSTR  lpWindowName, DWORD  dwStyle, INT  X, INT  Y, INT  nWidth, INT  nHeight, HWND  hWndParent, HINSTANCE  hInstance, LPARAM  lParam) /* ../dlls/user32/mdi.c:1621 */
{
	TRACE("Enter CreateMDIWindowW\n");
	return pCreateMDIWindowW(lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight, hWndParent, hInstance, lParam);
}

extern WINAPI void wine32a_user32_CreateMDIWindowW(void);  /* ../dlls/user32/mdi.c:1621 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateMDIWindowW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateMDIWindowW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $40, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_user32_CreateMenu(void) /* ../dlls/user32/menu.c:4248 */
{
	TRACE("Enter CreateMenu\n");
	return pCreateMenu();
}

extern WINAPI void wine32a_user32_CreateMenu(void);  /* ../dlls/user32/menu.c:4248 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_user32_CreatePopupMenu(void) /* ../dlls/user32/menu.c:4193 */
{
	TRACE("Enter CreatePopupMenu\n");
	return pCreatePopupMenu();
}

extern WINAPI void wine32a_user32_CreatePopupMenu(void);  /* ../dlls/user32/menu.c:4193 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreatePopupMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreatePopupMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_CreateWindowExA(DWORD  exStyle, LPCSTR  className, LPCSTR  windowName, DWORD  style, INT  x, INT  y, INT  width, INT  height, HWND  parent, HMENU  menu, HINSTANCE  instance, LPVOID  data) /* ../dlls/user32/win.c:1740 */
{
	TRACE("Enter CreateWindowExA\n");
	return pCreateWindowExA(exStyle, className, windowName, style, x, y, width, height, parent, menu, instance, data);
}

extern WINAPI void wine32a_user32_CreateWindowExA(void);  /* ../dlls/user32/win.c:1740 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateWindowExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateWindowExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $48, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_CreateWindowExW(DWORD  exStyle, LPCWSTR  className, LPCWSTR  windowName, DWORD  style, INT  x, INT  y, INT  width, INT  height, HWND  parent, HMENU  menu, HINSTANCE  instance, LPVOID  data) /* ../dlls/user32/win.c:1777 */
{
	TRACE("Enter CreateWindowExW\n");
	return pCreateWindowExW(exStyle, className, windowName, style, x, y, width, height, parent, menu, instance, data);
}

extern WINAPI void wine32a_user32_CreateWindowExW(void);  /* ../dlls/user32/win.c:1777 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateWindowExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateWindowExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $48, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWINSTA wine32b_user32_CreateWindowStationA(LPCSTR  name, DWORD  flags, ACCESS_MASK  access, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/user32/winstation.c:86 */
{
	TRACE("Enter CreateWindowStationA\n");
	return pCreateWindowStationA(name, flags, access, sa);
}

extern WINAPI void wine32a_user32_CreateWindowStationA(void);  /* ../dlls/user32/winstation.c:86 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateWindowStationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateWindowStationA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWINSTA wine32b_user32_CreateWindowStationW(LPCWSTR  name, DWORD  flags, ACCESS_MASK  access, LPSECURITY_ATTRIBUTES  sa) /* ../dlls/user32/winstation.c:105 */
{
	TRACE("Enter CreateWindowStationW\n");
	return pCreateWindowStationW(name, flags, access, sa);
}

extern WINAPI void wine32a_user32_CreateWindowStationW(void);  /* ../dlls/user32/winstation.c:105 */
__ASM_GLOBAL_FUNC(wine32a_user32_CreateWindowStationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_CreateWindowStationW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeAbandonTransaction(DWORD  idInst, HCONV  hConv, DWORD  idTransaction) /* ../dlls/user32/dde_client.c:1235 */
{
	TRACE("Enter DdeAbandonTransaction\n");
	return pDdeAbandonTransaction(idInst, hConv, idTransaction);
}

extern WINAPI void wine32a_user32_DdeAbandonTransaction(void);  /* ../dlls/user32/dde_client.c:1235 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeAbandonTransaction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeAbandonTransaction") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPBYTE wine32b_user32_DdeAccessData(HDDEDATA  hData, LPDWORD  pcbDataSize) /* ../dlls/user32/dde_misc.c:1435 */
{
	TRACE("Enter DdeAccessData\n");
	return pDdeAccessData(hData, pcbDataSize);
}

extern WINAPI void wine32a_user32_DdeAccessData(void);  /* ../dlls/user32/dde_misc.c:1435 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeAccessData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeAccessData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDDEDATA wine32b_user32_DdeAddData(HDDEDATA  hData, LPBYTE  pSrc, DWORD  cb, DWORD  cbOff) /* ../dlls/user32/dde_misc.c:1353 */
{
	TRACE("Enter DdeAddData\n");
	return pDdeAddData(hData, pSrc, cb, cbOff);
}

extern WINAPI void wine32a_user32_DdeAddData(void);  /* ../dlls/user32/dde_misc.c:1353 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeAddData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeAddData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDDEDATA wine32b_user32_DdeClientTransaction(LPBYTE  pData, DWORD  cbData, HCONV  hConv, HSZ  hszItem, UINT  wFmt, UINT  wType, DWORD  dwTimeout, LPDWORD  pdwResult) /* ../dlls/user32/dde_client.c:1133 */
{
	TRACE("Enter DdeClientTransaction\n");
	return pDdeClientTransaction(pData, cbData, hConv, hszItem, wFmt, wType, dwTimeout, pdwResult);
}

extern WINAPI void wine32a_user32_DdeClientTransaction(void);  /* ../dlls/user32/dde_client.c:1133 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeClientTransaction,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeClientTransaction") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_DdeCmpStringHandles(HSZ  hsz1, HSZ  hsz2) /* ../dlls/user32/dde_misc.c:698 */
{
	TRACE("Enter DdeCmpStringHandles\n");
	return pDdeCmpStringHandles(hsz1, hsz2);
}

extern WINAPI void wine32a_user32_DdeCmpStringHandles(void);  /* ../dlls/user32/dde_misc.c:698 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeCmpStringHandles,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeCmpStringHandles") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCONV wine32b_user32_DdeConnect(DWORD  idInst, HSZ  hszService, HSZ  hszTopic, PCONVCONTEXT  pCC) /* ../dlls/user32/dde_client.c:95 */
{
	TRACE("Enter DdeConnect\n");
	return pDdeConnect(idInst, hszService, hszTopic, pCC);
}

extern WINAPI void wine32a_user32_DdeConnect(void);  /* ../dlls/user32/dde_client.c:95 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeConnect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeConnect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCONVLIST wine32b_user32_DdeConnectList(DWORD  idInst, HSZ  hszService, HSZ  hszTopic, HCONVLIST  hConvList, PCONVCONTEXT  pCC) /* ../dlls/user32/dde_client.c:59 */
{
	TRACE("Enter DdeConnectList\n");
	return pDdeConnectList(idInst, hszService, hszTopic, hConvList, pCC);
}

extern WINAPI void wine32a_user32_DdeConnectList(void);  /* ../dlls/user32/dde_client.c:59 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeConnectList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeConnectList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDDEDATA wine32b_user32_DdeCreateDataHandle(DWORD  idInst, LPBYTE  pSrc, DWORD  cb, DWORD  cbOff, HSZ  hszItem, UINT  wFmt, UINT  afCmd) /* ../dlls/user32/dde_misc.c:1288 */
{
	TRACE("Enter DdeCreateDataHandle\n");
	return pDdeCreateDataHandle(idInst, pSrc, cb, cbOff, hszItem, wFmt, afCmd);
}

extern WINAPI void wine32a_user32_DdeCreateDataHandle(void);  /* ../dlls/user32/dde_misc.c:1288 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeCreateDataHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeCreateDataHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HSZ wine32b_user32_DdeCreateStringHandleA(DWORD  idInst, LPCSTR  psz, INT  codepage) /* ../dlls/user32/dde_misc.c:590 */
{
	TRACE("Enter DdeCreateStringHandleA\n");
	return pDdeCreateStringHandleA(idInst, psz, codepage);
}

extern WINAPI void wine32a_user32_DdeCreateStringHandleA(void);  /* ../dlls/user32/dde_misc.c:590 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeCreateStringHandleA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeCreateStringHandleA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HSZ wine32b_user32_DdeCreateStringHandleW(DWORD  idInst, LPCWSTR  psz, INT  codepage) /* ../dlls/user32/dde_misc.c:621 */
{
	TRACE("Enter DdeCreateStringHandleW\n");
	return pDdeCreateStringHandleW(idInst, psz, codepage);
}

extern WINAPI void wine32a_user32_DdeCreateStringHandleW(void);  /* ../dlls/user32/dde_misc.c:621 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeCreateStringHandleW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeCreateStringHandleW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeDisconnect(HCONV  hConv) /* ../dlls/user32/dde_client.c:1374 */
{
	TRACE("Enter DdeDisconnect\n");
	return pDdeDisconnect(hConv);
}

extern WINAPI void wine32a_user32_DdeDisconnect(void);  /* ../dlls/user32/dde_client.c:1374 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeDisconnect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeDisconnect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeDisconnectList(HCONVLIST  hConvList) /* ../dlls/user32/dde_client.c:86 */
{
	TRACE("Enter DdeDisconnectList\n");
	return pDdeDisconnectList(hConvList);
}

extern WINAPI void wine32a_user32_DdeDisconnectList(void);  /* ../dlls/user32/dde_client.c:86 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeDisconnectList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeDisconnectList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeEnableCallback(DWORD  idInst, HCONV  hConv, UINT  wCmd) /* ../dlls/user32/dde_misc.c:2191 */
{
	TRACE("Enter DdeEnableCallback\n");
	return pDdeEnableCallback(idInst, hConv, wCmd);
}

extern WINAPI void wine32a_user32_DdeEnableCallback(void);  /* ../dlls/user32/dde_misc.c:2191 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeEnableCallback,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeEnableCallback") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeFreeDataHandle(HDDEDATA  hData) /* ../dlls/user32/dde_misc.c:1474 */
{
	TRACE("Enter DdeFreeDataHandle\n");
	return pDdeFreeDataHandle(hData);
}

extern WINAPI void wine32a_user32_DdeFreeDataHandle(void);  /* ../dlls/user32/dde_misc.c:1474 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeFreeDataHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeFreeDataHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeFreeStringHandle(DWORD  idInst, HSZ  hsz) /* ../dlls/user32/dde_misc.c:644 */
{
	TRACE("Enter DdeFreeStringHandle\n");
	return pDdeFreeStringHandle(idInst, hsz);
}

extern WINAPI void wine32a_user32_DdeFreeStringHandle(void);  /* ../dlls/user32/dde_misc.c:644 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeFreeStringHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeFreeStringHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_DdeGetData(HDDEDATA  hData, LPBYTE  pDst, DWORD  cbMax, DWORD  cbOff) /* ../dlls/user32/dde_misc.c:1392 */
{
	TRACE("Enter DdeGetData\n");
	return pDdeGetData(hData, pDst, cbMax, cbOff);
}

extern WINAPI void wine32a_user32_DdeGetData(void);  /* ../dlls/user32/dde_misc.c:1392 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeGetData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeGetData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_DdeGetLastError(DWORD  idInst) /* ../dlls/user32/dde_misc.c:266 */
{
	TRACE("Enter DdeGetLastError\n");
	return pDdeGetLastError(idInst);
}

extern WINAPI void wine32a_user32_DdeGetLastError(void);  /* ../dlls/user32/dde_misc.c:266 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeGetLastError,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeGetLastError") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeImpersonateClient(HCONV  hConv) /* ../dlls/user32/dde_client.c:1423 */
{
	TRACE("Enter DdeImpersonateClient\n");
	return pDdeImpersonateClient(hConv);
}

extern WINAPI void wine32a_user32_DdeImpersonateClient(void);  /* ../dlls/user32/dde_client.c:1423 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeImpersonateClient,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeImpersonateClient") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_DdeInitializeA(LPDWORD  pidInst, PFNCALLBACK  pfnCallback, DWORD  afCmd, DWORD  ulRes) /* ../dlls/user32/dde_misc.c:1088 */
{
	TRACE("Enter DdeInitializeA\n");
	return pDdeInitializeA(pidInst, pfnCallback, afCmd, ulRes);
}

extern WINAPI void wine32a_user32_DdeInitializeA(void);  /* ../dlls/user32/dde_misc.c:1088 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeInitializeA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeInitializeA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_DdeInitializeW(LPDWORD  pidInst, PFNCALLBACK  pfnCallback, DWORD  afCmd, DWORD  ulRes) /* ../dlls/user32/dde_misc.c:1108 */
{
	TRACE("Enter DdeInitializeW\n");
	return pDdeInitializeW(pidInst, pfnCallback, afCmd, ulRes);
}

extern WINAPI void wine32a_user32_DdeInitializeW(void);  /* ../dlls/user32/dde_misc.c:1108 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeInitializeW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeInitializeW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeKeepStringHandle(DWORD  idInst, HSZ  hsz) /* ../dlls/user32/dde_misc.c:667 */
{
	TRACE("Enter DdeKeepStringHandle\n");
	return pDdeKeepStringHandle(idInst, hsz);
}

extern WINAPI void wine32a_user32_DdeKeepStringHandle(void);  /* ../dlls/user32/dde_misc.c:667 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeKeepStringHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeKeepStringHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDDEDATA wine32b_user32_DdeNameService(DWORD  idInst, HSZ  hsz1, HSZ  hsz2, UINT  afCmd) /* ../dlls/user32/dde_server.c:166 */
{
	TRACE("Enter DdeNameService\n");
	return pDdeNameService(idInst, hsz1, hsz2, afCmd);
}

extern WINAPI void wine32a_user32_DdeNameService(void);  /* ../dlls/user32/dde_server.c:166 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeNameService,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeNameService") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdePostAdvise(DWORD  idInst, HSZ  hszTopic, HSZ  hszItem) /* ../dlls/user32/dde_server.c:61 */
{
	TRACE("Enter DdePostAdvise\n");
	return pDdePostAdvise(idInst, hszTopic, hszItem);
}

extern WINAPI void wine32a_user32_DdePostAdvise(void);  /* ../dlls/user32/dde_server.c:61 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdePostAdvise,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdePostAdvise") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_DdeQueryConvInfo(HCONV  hConv, DWORD  id, PCONVINFO  lpConvInfo) /* ../dlls/user32/dde_misc.c:2439 */
{
	TRACE("Enter DdeQueryConvInfo\n");
	return pDdeQueryConvInfo(hConv, id, lpConvInfo);
}

extern WINAPI void wine32a_user32_DdeQueryConvInfo(void);  /* ../dlls/user32/dde_misc.c:2439 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeQueryConvInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeQueryConvInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCONV wine32b_user32_DdeQueryNextServer(HCONVLIST  hConvList, HCONV  hConvPrev) /* ../dlls/user32/dde_client.c:69 */
{
	TRACE("Enter DdeQueryNextServer\n");
	return pDdeQueryNextServer(hConvList, hConvPrev);
}

extern WINAPI void wine32a_user32_DdeQueryNextServer(void);  /* ../dlls/user32/dde_client.c:69 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeQueryNextServer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeQueryNextServer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_DdeQueryStringA(DWORD  idInst, HSZ  hsz, LPSTR  psz, DWORD  cchMax, INT  iCodePage) /* ../dlls/user32/dde_misc.c:514 */
{
	TRACE("Enter DdeQueryStringA\n");
	return pDdeQueryStringA(idInst, hsz, psz, cchMax, iCodePage);
}

extern WINAPI void wine32a_user32_DdeQueryStringA(void);  /* ../dlls/user32/dde_misc.c:514 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeQueryStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeQueryStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_DdeQueryStringW(DWORD  idInst, HSZ  hsz, LPWSTR  psz, DWORD  cchMax, INT  iCodePage) /* ../dlls/user32/dde_misc.c:538 */
{
	TRACE("Enter DdeQueryStringW\n");
	return pDdeQueryStringW(idInst, hsz, psz, cchMax, iCodePage);
}

extern WINAPI void wine32a_user32_DdeQueryStringW(void);  /* ../dlls/user32/dde_misc.c:538 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeQueryStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeQueryStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCONV wine32b_user32_DdeReconnect(HCONV  hConv) /* ../dlls/user32/dde_client.c:223 */
{
	TRACE("Enter DdeReconnect\n");
	return pDdeReconnect(hConv);
}

extern WINAPI void wine32a_user32_DdeReconnect(void);  /* ../dlls/user32/dde_client.c:223 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeReconnect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeReconnect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeSetQualityOfService(HWND  hwndClient, SECURITY_QUALITY_OF_SERVICE*  pqosNew, PSECURITY_QUALITY_OF_SERVICE  pqosPrev) /* ../dlls/user32/dde_misc.c:244 */
{
	TRACE("Enter DdeSetQualityOfService\n");
	return pDdeSetQualityOfService(hwndClient, pqosNew, pqosPrev);
}

extern WINAPI void wine32a_user32_DdeSetQualityOfService(void);  /* ../dlls/user32/dde_misc.c:244 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeSetQualityOfService,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeSetQualityOfService") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeSetUserHandle(HCONV  hConv, DWORD  id, DWORD  hUser) /* ../dlls/user32/dde_misc.c:2327 */
{
	TRACE("Enter DdeSetUserHandle\n");
	return pDdeSetUserHandle(hConv, id, hUser);
}

extern WINAPI void wine32a_user32_DdeSetUserHandle(void);  /* ../dlls/user32/dde_misc.c:2327 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeSetUserHandle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeSetUserHandle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeUnaccessData(HDDEDATA  hData) /* ../dlls/user32/dde_misc.c:1460 */
{
	TRACE("Enter DdeUnaccessData\n");
	return pDdeUnaccessData(hData);
}

extern WINAPI void wine32a_user32_DdeUnaccessData(void);  /* ../dlls/user32/dde_misc.c:1460 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeUnaccessData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeUnaccessData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DdeUninitialize(DWORD  idInst) /* ../dlls/user32/dde_misc.c:1125 */
{
	TRACE("Enter DdeUninitialize\n");
	return pDdeUninitialize(idInst);
}

extern WINAPI void wine32a_user32_DdeUninitialize(void);  /* ../dlls/user32/dde_misc.c:1125 */
__ASM_GLOBAL_FUNC(wine32a_user32_DdeUninitialize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DdeUninitialize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DefDlgProcA(HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/defdlg.c:360 */
{
	TRACE("Enter DefDlgProcA\n");
	return pDefDlgProcA(hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_user32_DefDlgProcA(void);  /* ../dlls/user32/defdlg.c:360 */
__ASM_GLOBAL_FUNC(wine32a_user32_DefDlgProcA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DefDlgProcA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DefDlgProcW(HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/defdlg.c:418 */
{
	TRACE("Enter DefDlgProcW\n");
	return pDefDlgProcW(hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_user32_DefDlgProcW(void);  /* ../dlls/user32/defdlg.c:418 */
__ASM_GLOBAL_FUNC(wine32a_user32_DefDlgProcW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DefDlgProcW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DefFrameProcA(HWND  hwnd, HWND  hwndMDIClient, UINT  message, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/mdi.c:1260 */
{
	TRACE("Enter DefFrameProcA\n");
	return pDefFrameProcA(hwnd, hwndMDIClient, message, wParam, lParam);
}

extern WINAPI void wine32a_user32_DefFrameProcA(void);  /* ../dlls/user32/mdi.c:1260 */
__ASM_GLOBAL_FUNC(wine32a_user32_DefFrameProcA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DefFrameProcA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DefFrameProcW(HWND  hwnd, HWND  hwndMDIClient, UINT  message, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/mdi.c:1292 */
{
	TRACE("Enter DefFrameProcW\n");
	return pDefFrameProcW(hwnd, hwndMDIClient, message, wParam, lParam);
}

extern WINAPI void wine32a_user32_DefFrameProcW(void);  /* ../dlls/user32/mdi.c:1292 */
__ASM_GLOBAL_FUNC(wine32a_user32_DefFrameProcW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DefFrameProcW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DefMDIChildProcA(HWND  hwnd, UINT  message, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/mdi.c:1389 */
{
	TRACE("Enter DefMDIChildProcA\n");
	return pDefMDIChildProcA(hwnd, message, wParam, lParam);
}

extern WINAPI void wine32a_user32_DefMDIChildProcA(void);  /* ../dlls/user32/mdi.c:1389 */
__ASM_GLOBAL_FUNC(wine32a_user32_DefMDIChildProcA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DefMDIChildProcA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DefMDIChildProcW(HWND  hwnd, UINT  message, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/mdi.c:1429 */
{
	TRACE("Enter DefMDIChildProcW\n");
	return pDefMDIChildProcW(hwnd, message, wParam, lParam);
}

extern WINAPI void wine32a_user32_DefMDIChildProcW(void);  /* ../dlls/user32/mdi.c:1429 */
__ASM_GLOBAL_FUNC(wine32a_user32_DefMDIChildProcW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DefMDIChildProcW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DefRawInputProc(RAWINPUT**  data, INT  data_count, UINT  header_size) /* ../dlls/user32/rawinput.c:486 */
{
	TRACE("Enter DefRawInputProc\n");
	return pDefRawInputProc(data, data_count, header_size);
}

extern WINAPI void wine32a_user32_DefRawInputProc(void);  /* ../dlls/user32/rawinput.c:486 */
__ASM_GLOBAL_FUNC(wine32a_user32_DefRawInputProc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DefRawInputProc") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DefWindowProcA(HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/defwnd.c:779 */
{
	TRACE("Enter DefWindowProcA\n");
	return pDefWindowProcA(hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_user32_DefWindowProcA(void);  /* ../dlls/user32/defwnd.c:779 */
__ASM_GLOBAL_FUNC(wine32a_user32_DefWindowProcA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DefWindowProcA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DefWindowProcW(HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/defwnd.c:961 */
{
	TRACE("Enter DefWindowProcW\n");
	return pDefWindowProcW(hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_user32_DefWindowProcW(void);  /* ../dlls/user32/defwnd.c:961 */
__ASM_GLOBAL_FUNC(wine32a_user32_DefWindowProcW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DefWindowProcW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDWP wine32b_user32_DeferWindowPos(HDWP  hdwp, HWND  hwnd, HWND  hwndAfter, INT  x, INT  y, INT  cx, INT  cy, UINT  flags) /* ../dlls/user32/winpos.c:2421 */
{
	TRACE("Enter DeferWindowPos\n");
	return pDeferWindowPos(hdwp, hwnd, hwndAfter, x, y, cx, cy, flags);
}

extern WINAPI void wine32a_user32_DeferWindowPos(void);  /* ../dlls/user32/winpos.c:2421 */
__ASM_GLOBAL_FUNC(wine32a_user32_DeferWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DeferWindowPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DeleteMenu(HMENU  hMenu, UINT  id, UINT  flags) /* ../dlls/user32/menu.c:4119 */
{
	TRACE("Enter DeleteMenu\n");
	return pDeleteMenu(hMenu, id, flags);
}

extern WINAPI void wine32a_user32_DeleteMenu(void);  /* ../dlls/user32/menu.c:4119 */
__ASM_GLOBAL_FUNC(wine32a_user32_DeleteMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DeleteMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DeregisterShellHookWindow(HWND  hWnd) /* ../dlls/user32/misc.c:275 */
{
	TRACE("Enter DeregisterShellHookWindow\n");
	return pDeregisterShellHookWindow(hWnd);
}

extern WINAPI void wine32a_user32_DeregisterShellHookWindow(void);  /* ../dlls/user32/misc.c:275 */
__ASM_GLOBAL_FUNC(wine32a_user32_DeregisterShellHookWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DeregisterShellHookWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DestroyAcceleratorTable(HACCEL  handle) /* ../dlls/user32/resource.c:223 */
{
	TRACE("Enter DestroyAcceleratorTable\n");
	return pDestroyAcceleratorTable(handle);
}

extern WINAPI void wine32a_user32_DestroyAcceleratorTable(void);  /* ../dlls/user32/resource.c:223 */
__ASM_GLOBAL_FUNC(wine32a_user32_DestroyAcceleratorTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DestroyAcceleratorTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DestroyCaret(void) /* ../dlls/user32/caret.c:203 */
{
	TRACE("Enter DestroyCaret\n");
	return pDestroyCaret();
}

extern WINAPI void wine32a_user32_DestroyCaret(void);  /* ../dlls/user32/caret.c:203 */
__ASM_GLOBAL_FUNC(wine32a_user32_DestroyCaret,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DestroyCaret") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DestroyCursor(HCURSOR  hCursor) /* ../dlls/user32/cursoricon.c:2019 */
{
	TRACE("Enter DestroyCursor\n");
	return pDestroyCursor(hCursor);
}

extern WINAPI void wine32a_user32_DestroyCursor(void);  /* ../dlls/user32/cursoricon.c:2019 */
__ASM_GLOBAL_FUNC(wine32a_user32_DestroyCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DestroyCursor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DestroyIcon(HICON  hIcon) /* ../dlls/user32/cursoricon.c:1998 */
{
	TRACE("Enter DestroyIcon\n");
	return pDestroyIcon(hIcon);
}

extern WINAPI void wine32a_user32_DestroyIcon(void);  /* ../dlls/user32/cursoricon.c:1998 */
__ASM_GLOBAL_FUNC(wine32a_user32_DestroyIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DestroyIcon") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DestroyMenu(HMENU  hMenu) /* ../dlls/user32/menu.c:4268 */
{
	TRACE("Enter DestroyMenu\n");
	return pDestroyMenu(hMenu);
}

extern WINAPI void wine32a_user32_DestroyMenu(void);  /* ../dlls/user32/menu.c:4268 */
__ASM_GLOBAL_FUNC(wine32a_user32_DestroyMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DestroyMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DestroyWindow(HWND  hwnd) /* ../dlls/user32/win.c:1848 */
{
	TRACE("Enter DestroyWindow\n");
	return pDestroyWindow(hwnd);
}

extern WINAPI void wine32a_user32_DestroyWindow(void);  /* ../dlls/user32/win.c:1848 */
__ASM_GLOBAL_FUNC(wine32a_user32_DestroyWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DestroyWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT_PTR wine32b_user32_DialogBoxIndirectParamA(HINSTANCE  hInstance, LPCDLGTEMPLATEA  template, HWND  owner, DLGPROC  dlgProc, LPARAM  param) /* ../dlls/user32/dialog.c:887 */
{
	TRACE("Enter DialogBoxIndirectParamA\n");
	return pDialogBoxIndirectParamA(hInstance, template, owner, dlgProc, param);
}

extern WINAPI void wine32a_user32_DialogBoxIndirectParamA(void);  /* ../dlls/user32/dialog.c:887 */
__ASM_GLOBAL_FUNC(wine32a_user32_DialogBoxIndirectParamA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DialogBoxIndirectParamA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT_PTR wine32b_user32_DialogBoxIndirectParamAorW(HINSTANCE  hInstance, LPCVOID  template, HWND  owner, DLGPROC  dlgProc, LPARAM  param, DWORD  flags) /* ../dlls/user32/dialog.c:875 */
{
	TRACE("Enter DialogBoxIndirectParamAorW\n");
	return pDialogBoxIndirectParamAorW(hInstance, template, owner, dlgProc, param, flags);
}

extern WINAPI void wine32a_user32_DialogBoxIndirectParamAorW(void);  /* ../dlls/user32/dialog.c:875 */
__ASM_GLOBAL_FUNC(wine32a_user32_DialogBoxIndirectParamAorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DialogBoxIndirectParamAorW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT_PTR wine32b_user32_DialogBoxIndirectParamW(HINSTANCE  hInstance, LPCDLGTEMPLATEW  template, HWND  owner, DLGPROC  dlgProc, LPARAM  param) /* ../dlls/user32/dialog.c:897 */
{
	TRACE("Enter DialogBoxIndirectParamW\n");
	return pDialogBoxIndirectParamW(hInstance, template, owner, dlgProc, param);
}

extern WINAPI void wine32a_user32_DialogBoxIndirectParamW(void);  /* ../dlls/user32/dialog.c:897 */
__ASM_GLOBAL_FUNC(wine32a_user32_DialogBoxIndirectParamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DialogBoxIndirectParamW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT_PTR wine32b_user32_DialogBoxParamA(HINSTANCE  hInst, LPCSTR  name, HWND  owner, DLGPROC  dlgProc, LPARAM  param) /* ../dlls/user32/dialog.c:837 */
{
	TRACE("Enter DialogBoxParamA\n");
	return pDialogBoxParamA(hInst, name, owner, dlgProc, param);
}

extern WINAPI void wine32a_user32_DialogBoxParamA(void);  /* ../dlls/user32/dialog.c:837 */
__ASM_GLOBAL_FUNC(wine32a_user32_DialogBoxParamA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DialogBoxParamA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT_PTR wine32b_user32_DialogBoxParamW(HINSTANCE  hInst, LPCWSTR  name, HWND  owner, DLGPROC  dlgProc, LPARAM  param) /* ../dlls/user32/dialog.c:856 */
{
	TRACE("Enter DialogBoxParamW\n");
	return pDialogBoxParamW(hInst, name, owner, dlgProc, param);
}

extern WINAPI void wine32a_user32_DialogBoxParamW(void);  /* ../dlls/user32/dialog.c:856 */
__ASM_GLOBAL_FUNC(wine32a_user32_DialogBoxParamW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DialogBoxParamW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_DisableProcessWindowsGhosting(void) /* ../dlls/user32/misc.c:475 */
{
	TRACE("Enter DisableProcessWindowsGhosting\n");
	return pDisableProcessWindowsGhosting();
}

extern WINAPI void wine32a_user32_DisableProcessWindowsGhosting(void);  /* ../dlls/user32/misc.c:475 */
__ASM_GLOBAL_FUNC(wine32a_user32_DisableProcessWindowsGhosting,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DisableProcessWindowsGhosting") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DispatchMessageA(MSG*  msg) /* ../dlls/user32/message.c:3957 */
{
	TRACE("Enter DispatchMessageA\n");
	return pDispatchMessageA(msg);
}

extern WINAPI void wine32a_user32_DispatchMessageA(void);  /* ../dlls/user32/message.c:3957 */
__ASM_GLOBAL_FUNC(wine32a_user32_DispatchMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DispatchMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_DispatchMessageW(MSG*  msg) /* ../dlls/user32/message.c:4028 */
{
	TRACE("Enter DispatchMessageW\n");
	return pDispatchMessageW(msg);
}

extern WINAPI void wine32a_user32_DispatchMessageW(void);  /* ../dlls/user32/message.c:4028 */
__ASM_GLOBAL_FUNC(wine32a_user32_DispatchMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DispatchMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_DisplayConfigGetDeviceInfo(DISPLAYCONFIG_DEVICE_INFO_HEADER*  packet) /* ../dlls/user32/sysparams.c:3217 */
{
	TRACE("Enter DisplayConfigGetDeviceInfo\n");
	return pDisplayConfigGetDeviceInfo(packet);
}

extern WINAPI void wine32a_user32_DisplayConfigGetDeviceInfo(void);  /* ../dlls/user32/sysparams.c:3217 */
__ASM_GLOBAL_FUNC(wine32a_user32_DisplayConfigGetDeviceInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DisplayConfigGetDeviceInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_DlgDirListA(HWND  hDlg, LPSTR  spec, INT  idLBox, INT  idStatic, UINT  attrib) /* ../dlls/user32/dialog.c:1972 */
{
	TRACE("Enter DlgDirListA\n");
	return pDlgDirListA(hDlg, spec, idLBox, idStatic, attrib);
}

extern WINAPI void wine32a_user32_DlgDirListA(void);  /* ../dlls/user32/dialog.c:1972 */
__ASM_GLOBAL_FUNC(wine32a_user32_DlgDirListA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DlgDirListA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_DlgDirListComboBoxA(HWND  hDlg, LPSTR  spec, INT  idCBox, INT  idStatic, UINT  attrib) /* ../dlls/user32/dialog.c:1992 */
{
	TRACE("Enter DlgDirListComboBoxA\n");
	return pDlgDirListComboBoxA(hDlg, spec, idCBox, idStatic, attrib);
}

extern WINAPI void wine32a_user32_DlgDirListComboBoxA(void);  /* ../dlls/user32/dialog.c:1992 */
__ASM_GLOBAL_FUNC(wine32a_user32_DlgDirListComboBoxA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DlgDirListComboBoxA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_DlgDirListComboBoxW(HWND  hDlg, LPWSTR  spec, INT  idCBox, INT  idStatic, UINT  attrib) /* ../dlls/user32/dialog.c:2002 */
{
	TRACE("Enter DlgDirListComboBoxW\n");
	return pDlgDirListComboBoxW(hDlg, spec, idCBox, idStatic, attrib);
}

extern WINAPI void wine32a_user32_DlgDirListComboBoxW(void);  /* ../dlls/user32/dialog.c:2002 */
__ASM_GLOBAL_FUNC(wine32a_user32_DlgDirListComboBoxW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DlgDirListComboBoxW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_DlgDirListW(HWND  hDlg, LPWSTR  spec, INT  idLBox, INT  idStatic, UINT  attrib) /* ../dlls/user32/dialog.c:1982 */
{
	TRACE("Enter DlgDirListW\n");
	return pDlgDirListW(hDlg, spec, idLBox, idStatic, attrib);
}

extern WINAPI void wine32a_user32_DlgDirListW(void);  /* ../dlls/user32/dialog.c:1982 */
__ASM_GLOBAL_FUNC(wine32a_user32_DlgDirListW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DlgDirListW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DlgDirSelectComboBoxExA(HWND  hwnd, LPSTR  str, INT  len, INT  id) /* ../dlls/user32/dialog.c:1952 */
{
	TRACE("Enter DlgDirSelectComboBoxExA\n");
	return pDlgDirSelectComboBoxExA(hwnd, str, len, id);
}

extern WINAPI void wine32a_user32_DlgDirSelectComboBoxExA(void);  /* ../dlls/user32/dialog.c:1952 */
__ASM_GLOBAL_FUNC(wine32a_user32_DlgDirSelectComboBoxExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DlgDirSelectComboBoxExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DlgDirSelectComboBoxExW(HWND  hwnd, LPWSTR  str, INT  len, INT  id) /* ../dlls/user32/dialog.c:1962 */
{
	TRACE("Enter DlgDirSelectComboBoxExW\n");
	return pDlgDirSelectComboBoxExW(hwnd, str, len, id);
}

extern WINAPI void wine32a_user32_DlgDirSelectComboBoxExW(void);  /* ../dlls/user32/dialog.c:1962 */
__ASM_GLOBAL_FUNC(wine32a_user32_DlgDirSelectComboBoxExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DlgDirSelectComboBoxExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DlgDirSelectExA(HWND  hwnd, LPSTR  str, INT  len, INT  id) /* ../dlls/user32/dialog.c:1934 */
{
	TRACE("Enter DlgDirSelectExA\n");
	return pDlgDirSelectExA(hwnd, str, len, id);
}

extern WINAPI void wine32a_user32_DlgDirSelectExA(void);  /* ../dlls/user32/dialog.c:1934 */
__ASM_GLOBAL_FUNC(wine32a_user32_DlgDirSelectExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DlgDirSelectExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DlgDirSelectExW(HWND  hwnd, LPWSTR  str, INT  len, INT  id) /* ../dlls/user32/dialog.c:1943 */
{
	TRACE("Enter DlgDirSelectExW\n");
	return pDlgDirSelectExW(hwnd, str, len, id);
}

extern WINAPI void wine32a_user32_DlgDirSelectExW(void);  /* ../dlls/user32/dialog.c:1943 */
__ASM_GLOBAL_FUNC(wine32a_user32_DlgDirSelectExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DlgDirSelectExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DragDetect(HWND  hWnd, POINT  pt) /* ../dlls/user32/win.c:3760 */
{
	TRACE("Enter DragDetect\n");
	return pDragDetect(hWnd, pt);
}

extern WINAPI void wine32a_user32_DragDetect(void);  /* ../dlls/user32/win.c:3760 */
__ASM_GLOBAL_FUNC(wine32a_user32_DragDetect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DragDetect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawAnimatedRects(HWND  hwnd, INT  idAni, RECT*  lprcFrom, RECT*  lprcTo) /* ../dlls/user32/uitools.c:1517 */
{
	TRACE("Enter DrawAnimatedRects\n");
	return pDrawAnimatedRects(hwnd, idAni, lprcFrom, lprcTo);
}

extern WINAPI void wine32a_user32_DrawAnimatedRects(void);  /* ../dlls/user32/uitools.c:1517 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawAnimatedRects,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawAnimatedRects") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawCaption(HWND  hwnd, HDC  hdc, RECT*  lpRect, UINT  uFlags) /* ../dlls/user32/nonclient.c:182 */
{
	TRACE("Enter DrawCaption\n");
	return pDrawCaption(hwnd, hdc, lpRect, uFlags);
}

extern WINAPI void wine32a_user32_DrawCaption(void);  /* ../dlls/user32/nonclient.c:182 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawCaption,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawCaption") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawCaptionTempA(HWND  hwnd, HDC  hdc, RECT*  rect, HFONT  hFont, HICON  hIcon, LPCSTR  str, UINT  uFlags) /* ../dlls/user32/nonclient.c:191 */
{
	TRACE("Enter DrawCaptionTempA\n");
	return pDrawCaptionTempA(hwnd, hdc, rect, hFont, hIcon, str, uFlags);
}

extern WINAPI void wine32a_user32_DrawCaptionTempA(void);  /* ../dlls/user32/nonclient.c:191 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawCaptionTempA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawCaptionTempA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawCaptionTempW(HWND  hwnd, HDC  hdc, RECT*  rect, HFONT  hFont, HICON  hIcon, LPCWSTR  str, UINT  uFlags) /* ../dlls/user32/nonclient.c:215 */
{
	TRACE("Enter DrawCaptionTempW\n");
	return pDrawCaptionTempW(hwnd, hdc, rect, hFont, hIcon, str, uFlags);
}

extern WINAPI void wine32a_user32_DrawCaptionTempW(void);  /* ../dlls/user32/nonclient.c:215 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawCaptionTempW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawCaptionTempW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawEdge(HDC  hdc, LPRECT  rc, UINT  edge, UINT  flags) /* ../dlls/user32/uitools.c:597 */
{
	TRACE("Enter DrawEdge\n");
	return pDrawEdge(hdc, rc, edge, flags);
}

extern WINAPI void wine32a_user32_DrawEdge(void);  /* ../dlls/user32/uitools.c:597 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawEdge,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawEdge") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawFocusRect(HDC  hdc, RECT*  rc) /* ../dlls/user32/uitools.c:1487 */
{
	TRACE("Enter DrawFocusRect\n");
	return pDrawFocusRect(hdc, rc);
}

extern WINAPI void wine32a_user32_DrawFocusRect(void);  /* ../dlls/user32/uitools.c:1487 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawFocusRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawFocusRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawFrameControl(HDC  hdc, LPRECT  rc, UINT  uType, UINT  uState) /* ../dlls/user32/uitools.c:1221 */
{
	TRACE("Enter DrawFrameControl\n");
	return pDrawFrameControl(hdc, rc, uType, uState);
}

extern WINAPI void wine32a_user32_DrawFrameControl(void);  /* ../dlls/user32/uitools.c:1221 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawFrameControl,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawFrameControl") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawIcon(HDC  hdc, INT  x, INT  y, HICON  hIcon) /* ../dlls/user32/cursoricon.c:2027 */
{
	TRACE("Enter DrawIcon\n");
	return pDrawIcon(hdc, x, y, hIcon);
}

extern WINAPI void wine32a_user32_DrawIcon(void);  /* ../dlls/user32/cursoricon.c:2027 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawIcon") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawIconEx(HDC  hdc, INT  x0, INT  y0, HICON  hIcon, INT  cxWidth, INT  cyWidth, UINT  istep, HBRUSH  hbr, UINT  flags) /* ../dlls/user32/cursoricon.c:2633 */
{
	TRACE("Enter DrawIconEx\n");
	return pDrawIconEx(hdc, x0, y0, hIcon, cxWidth, cyWidth, istep, hbr, flags);
}

extern WINAPI void wine32a_user32_DrawIconEx(void);  /* ../dlls/user32/cursoricon.c:2633 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawIconEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawIconEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $36, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawMenuBar(HWND  hWnd) /* ../dlls/user32/menu.c:4531 */
{
	TRACE("Enter DrawMenuBar\n");
	return pDrawMenuBar(hWnd);
}

extern WINAPI void wine32a_user32_DrawMenuBar(void);  /* ../dlls/user32/menu.c:4531 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawMenuBar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawMenuBar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_DrawMenuBarTemp(HWND  hwnd, HDC  hDC, LPRECT  lprect, HMENU  hMenu, HFONT  hFont) /* ../dlls/user32/menu.c:4564 */
{
	TRACE("Enter DrawMenuBarTemp\n");
	return pDrawMenuBarTemp(hwnd, hDC, lprect, hMenu, hFont);
}

extern WINAPI void wine32a_user32_DrawMenuBarTemp(void);  /* ../dlls/user32/menu.c:4564 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawMenuBarTemp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawMenuBarTemp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawStateA(HDC  hdc, HBRUSH  hbr, DRAWSTATEPROC  func, LPARAM  ldata, WPARAM  wdata, INT  x, INT  y, INT  cx, INT  cy, UINT  flags) /* ../dlls/user32/uitools.c:1739 */
{
	TRACE("Enter DrawStateA\n");
	return pDrawStateA(hdc, hbr, func, ldata, wdata, x, y, cx, cy, flags);
}

extern WINAPI void wine32a_user32_DrawStateA(void);  /* ../dlls/user32/uitools.c:1739 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawStateA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawStateA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $40, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_DrawStateW(HDC  hdc, HBRUSH  hbr, DRAWSTATEPROC  func, LPARAM  ldata, WPARAM  wdata, INT  x, INT  y, INT  cx, INT  cy, UINT  flags) /* ../dlls/user32/uitools.c:1749 */
{
	TRACE("Enter DrawStateW\n");
	return pDrawStateW(hdc, hbr, func, ldata, wdata, x, y, cx, cy, flags);
}

extern WINAPI void wine32a_user32_DrawStateW(void);  /* ../dlls/user32/uitools.c:1749 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawStateW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawStateW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $40, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_DrawTextA(HDC  hdc, LPCSTR  str, INT  count, LPRECT  rect, UINT  flags) /* ../dlls/user32/text.c:1173 */
{
	TRACE("Enter DrawTextA\n");
	return pDrawTextA(hdc, str, count, rect, flags);
}

extern WINAPI void wine32a_user32_DrawTextA(void);  /* ../dlls/user32/text.c:1173 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawTextA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_DrawTextExA(HDC  hdc, LPSTR  str, INT  count, LPRECT  rect, UINT  flags, LPDRAWTEXTPARAMS  dtp) /* ../dlls/user32/text.c:1082 */
{
	TRACE("Enter DrawTextExA\n");
	return pDrawTextExA(hdc, str, count, rect, flags, dtp);
}

extern WINAPI void wine32a_user32_DrawTextExA(void);  /* ../dlls/user32/text.c:1082 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawTextExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawTextExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_DrawTextExW(HDC  hdc, LPWSTR  str, INT  i_count, LPRECT  rect, UINT  flags, LPDRAWTEXTPARAMS  dtp) /* ../dlls/user32/text.c:870 */
{
	TRACE("Enter DrawTextExW\n");
	return pDrawTextExW(hdc, str, i_count, rect, flags, dtp);
}

extern WINAPI void wine32a_user32_DrawTextExW(void);  /* ../dlls/user32/text.c:870 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawTextExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawTextExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_DrawTextW(HDC  hdc, LPCWSTR  str, INT  count, LPRECT  rect, UINT  flags) /* ../dlls/user32/text.c:1156 */
{
	TRACE("Enter DrawTextW\n");
	return pDrawTextW(hdc, str, count, rect, flags);
}

extern WINAPI void wine32a_user32_DrawTextW(void);  /* ../dlls/user32/text.c:1156 */
__ASM_GLOBAL_FUNC(wine32a_user32_DrawTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_DrawTextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_EditWndProc(HWND  hwnd, UINT  msg, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/winproc.c:1115 */
{
	TRACE("Enter EditWndProc\n");
	return pEditWndProc(hwnd, msg, wParam, lParam);
}

extern WINAPI void wine32a_user32_EditWndProc(void);  /* ../dlls/user32/winproc.c:1115 */
__ASM_GLOBAL_FUNC(wine32a_user32_EditWndProc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EditWndProc") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EmptyClipboard(void) /* ../dlls/user32/clipboard.c:742 */
{
	TRACE("Enter EmptyClipboard\n");
	return pEmptyClipboard();
}

extern WINAPI void wine32a_user32_EmptyClipboard(void);  /* ../dlls/user32/clipboard.c:742 */
__ASM_GLOBAL_FUNC(wine32a_user32_EmptyClipboard,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EmptyClipboard") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnableMenuItem(HMENU  hMenu, UINT  id, UINT  wFlags) /* ../dlls/user32/menu.c:3727 */
{
	TRACE("Enter EnableMenuItem\n");
	return pEnableMenuItem(hMenu, id, wFlags);
}

extern WINAPI void wine32a_user32_EnableMenuItem(void);  /* ../dlls/user32/menu.c:3727 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnableMenuItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnableMenuItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnableMouseInPointer(BOOL  enable) /* ../dlls/user32/input.c:1296 */
{
	TRACE("Enter EnableMouseInPointer\n");
	return pEnableMouseInPointer(enable);
}

extern WINAPI void wine32a_user32_EnableMouseInPointer(void);  /* ../dlls/user32/input.c:1296 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnableMouseInPointer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnableMouseInPointer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnableScrollBar(HWND  hwnd, UINT  nBar, UINT  flags) /* ../dlls/user32/scroll.c:2034 */
{
	TRACE("Enter EnableScrollBar\n");
	return pEnableScrollBar(hwnd, nBar, flags);
}

extern WINAPI void wine32a_user32_EnableScrollBar(void);  /* ../dlls/user32/scroll.c:2034 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnableScrollBar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnableScrollBar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnableWindow(HWND  hwnd, BOOL  enable) /* ../dlls/user32/win.c:2158 */
{
	TRACE("Enter EnableWindow\n");
	return pEnableWindow(hwnd, enable);
}

extern WINAPI void wine32a_user32_EnableWindow(void);  /* ../dlls/user32/win.c:2158 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnableWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnableWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EndDeferWindowPos(HDWP  hdwp) /* ../dlls/user32/winpos.c:2505 */
{
	TRACE("Enter EndDeferWindowPos\n");
	return pEndDeferWindowPos(hdwp);
}

extern WINAPI void wine32a_user32_EndDeferWindowPos(void);  /* ../dlls/user32/winpos.c:2505 */
__ASM_GLOBAL_FUNC(wine32a_user32_EndDeferWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EndDeferWindowPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EndDialog(HWND  hwnd, INT_PTR  retval) /* ../dlls/user32/dialog.c:906 */
{
	TRACE("Enter EndDialog\n");
	return pEndDialog(hwnd, retval);
}

extern WINAPI void wine32a_user32_EndDialog(void);  /* ../dlls/user32/dialog.c:906 */
__ASM_GLOBAL_FUNC(wine32a_user32_EndDialog,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EndDialog") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EndMenu(void) /* ../dlls/user32/menu.c:4621 */
{
	TRACE("Enter EndMenu\n");
	return pEndMenu();
}

extern WINAPI void wine32a_user32_EndMenu(void);  /* ../dlls/user32/menu.c:4621 */
__ASM_GLOBAL_FUNC(wine32a_user32_EndMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EndMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EndPaint(HWND  hwnd, PAINTSTRUCT*  lps) /* ../dlls/user32/painting.c:970 */
{
	TRACE("Enter EndPaint\n");
	return pEndPaint(hwnd, lps);
}

extern WINAPI void wine32a_user32_EndPaint(void);  /* ../dlls/user32/painting.c:970 */
__ASM_GLOBAL_FUNC(wine32a_user32_EndPaint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EndPaint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumChildWindows(HWND  parent, WNDENUMPROC  func, LPARAM  lParam) /* ../dlls/user32/win.c:3612 */
{
	TRACE("Enter EnumChildWindows\n");
	return pEnumChildWindows(parent, func, lParam);
}

extern WINAPI void wine32a_user32_EnumChildWindows(void);  /* ../dlls/user32/win.c:3612 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumChildWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumChildWindows") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_EnumClipboardFormats(UINT  format) /* ../dlls/user32/clipboard.c:956 */
{
	TRACE("Enter EnumClipboardFormats\n");
	return pEnumClipboardFormats(format);
}

extern WINAPI void wine32a_user32_EnumClipboardFormats(void);  /* ../dlls/user32/clipboard.c:956 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumClipboardFormats,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumClipboardFormats") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumDesktopWindows(HDESK  desktop, WNDENUMPROC  func, LPARAM  lparam) /* ../dlls/user32/win.c:3538 */
{
	TRACE("Enter EnumDesktopWindows\n");
	return pEnumDesktopWindows(desktop, func, lparam);
}

extern WINAPI void wine32a_user32_EnumDesktopWindows(void);  /* ../dlls/user32/win.c:3538 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumDesktopWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumDesktopWindows") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumDesktopsA(HWINSTA  winsta, DESKTOPENUMPROCA  func, LPARAM  lparam) /* ../dlls/user32/winstation.c:441 */
{
	TRACE("Enter EnumDesktopsA\n");
	return pEnumDesktopsA(winsta, func, lparam);
}

extern WINAPI void wine32a_user32_EnumDesktopsA(void);  /* ../dlls/user32/winstation.c:441 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumDesktopsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumDesktopsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumDesktopsW(HWINSTA  winsta, DESKTOPENUMPROCW  func, LPARAM  lparam) /* ../dlls/user32/winstation.c:453 */
{
	TRACE("Enter EnumDesktopsW\n");
	return pEnumDesktopsW(winsta, func, lparam);
}

extern WINAPI void wine32a_user32_EnumDesktopsW(void);  /* ../dlls/user32/winstation.c:453 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumDesktopsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumDesktopsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumDisplayDevicesA(LPCSTR  device, DWORD  index, DISPLAY_DEVICEA*  info, DWORD  flags) /* ../dlls/user32/sysparams.c:4013 */
{
	TRACE("Enter EnumDisplayDevicesA\n");
	return pEnumDisplayDevicesA(device, index, info, flags);
}

extern WINAPI void wine32a_user32_EnumDisplayDevicesA(void);  /* ../dlls/user32/sysparams.c:4013 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumDisplayDevicesA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumDisplayDevicesA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumDisplayDevicesW(LPCWSTR  device, DWORD  index, DISPLAY_DEVICEW*  info, DWORD  flags) /* ../dlls/user32/sysparams.c:4046 */
{
	TRACE("Enter EnumDisplayDevicesW\n");
	return pEnumDisplayDevicesW(device, index, info, flags);
}

extern WINAPI void wine32a_user32_EnumDisplayDevicesW(void);  /* ../dlls/user32/sysparams.c:4046 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumDisplayDevicesW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumDisplayDevicesW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumDisplayMonitors(HDC  hdc, LPRECT  rect, MONITORENUMPROC  proc, LPARAM  lp) /* ../dlls/user32/sysparams.c:3987 */
{
	TRACE("Enter EnumDisplayMonitors\n");
	return pEnumDisplayMonitors(hdc, rect, proc, lp);
}

extern WINAPI void wine32a_user32_EnumDisplayMonitors(void);  /* ../dlls/user32/sysparams.c:3987 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumDisplayMonitors,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumDisplayMonitors") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumDisplaySettingsA(LPCSTR  name, DWORD  n, LPDEVMODEA  devmode) /* ../dlls/user32/sysparams.c:3239 */
{
	TRACE("Enter EnumDisplaySettingsA\n");
	return pEnumDisplaySettingsA(name, n, devmode);
}

extern WINAPI void wine32a_user32_EnumDisplaySettingsA(void);  /* ../dlls/user32/sysparams.c:3239 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumDisplaySettingsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumDisplaySettingsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumDisplaySettingsExA(LPCSTR  lpszDeviceName, DWORD  iModeNum, LPDEVMODEA  lpDevMode, DWORD  dwFlags) /* ../dlls/user32/sysparams.c:3248 */
{
	TRACE("Enter EnumDisplaySettingsExA\n");
	return pEnumDisplaySettingsExA(lpszDeviceName, iModeNum, lpDevMode, dwFlags);
}

extern WINAPI void wine32a_user32_EnumDisplaySettingsExA(void);  /* ../dlls/user32/sysparams.c:3248 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumDisplaySettingsExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumDisplaySettingsExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumDisplaySettingsExW(LPCWSTR  lpszDeviceName, DWORD  iModeNum, LPDEVMODEW  lpDevMode, DWORD  dwFlags) /* ../dlls/user32/sysparams.c:3287 */
{
	TRACE("Enter EnumDisplaySettingsExW\n");
	return pEnumDisplaySettingsExW(lpszDeviceName, iModeNum, lpDevMode, dwFlags);
}

extern WINAPI void wine32a_user32_EnumDisplaySettingsExW(void);  /* ../dlls/user32/sysparams.c:3287 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumDisplaySettingsExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumDisplaySettingsExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumDisplaySettingsW(LPCWSTR  name, DWORD  n, LPDEVMODEW  devmode) /* ../dlls/user32/sysparams.c:3230 */
{
	TRACE("Enter EnumDisplaySettingsW\n");
	return pEnumDisplaySettingsW(name, n, devmode);
}

extern WINAPI void wine32a_user32_EnumDisplaySettingsW(void);  /* ../dlls/user32/sysparams.c:3230 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumDisplaySettingsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumDisplaySettingsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_EnumPropsA(HWND  hwnd, PROPENUMPROCA  func) /* ../dlls/user32/property.c:99 */
{
	TRACE("Enter EnumPropsA\n");
	return pEnumPropsA(hwnd, func);
}

extern WINAPI void wine32a_user32_EnumPropsA(void);  /* ../dlls/user32/property.c:99 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumPropsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumPropsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_EnumPropsExA(HWND  hwnd, PROPENUMPROCEXA  func, LPARAM  lParam) /* ../dlls/user32/property.c:215 */
{
	TRACE("Enter EnumPropsExA\n");
	return pEnumPropsExA(hwnd, func, lParam);
}

extern WINAPI void wine32a_user32_EnumPropsExA(void);  /* ../dlls/user32/property.c:215 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumPropsExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumPropsExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_EnumPropsExW(HWND  hwnd, PROPENUMPROCEXW  func, LPARAM  lParam) /* ../dlls/user32/property.c:237 */
{
	TRACE("Enter EnumPropsExW\n");
	return pEnumPropsExW(hwnd, func, lParam);
}

extern WINAPI void wine32a_user32_EnumPropsExW(void);  /* ../dlls/user32/property.c:237 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumPropsExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumPropsExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_EnumPropsW(HWND  hwnd, PROPENUMPROCW  func) /* ../dlls/user32/property.c:108 */
{
	TRACE("Enter EnumPropsW\n");
	return pEnumPropsW(hwnd, func);
}

extern WINAPI void wine32a_user32_EnumPropsW(void);  /* ../dlls/user32/property.c:108 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumPropsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumPropsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumThreadWindows(DWORD  id, WNDENUMPROC  func, LPARAM  lParam) /* ../dlls/user32/win.c:3516 */
{
	TRACE("Enter EnumThreadWindows\n");
	return pEnumThreadWindows(id, func, lParam);
}

extern WINAPI void wine32a_user32_EnumThreadWindows(void);  /* ../dlls/user32/win.c:3516 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumThreadWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumThreadWindows") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumWindowStationsA(WINSTAENUMPROCA  func, LPARAM  lparam) /* ../dlls/user32/winstation.c:229 */
{
	TRACE("Enter EnumWindowStationsA\n");
	return pEnumWindowStationsA(func, lparam);
}

extern WINAPI void wine32a_user32_EnumWindowStationsA(void);  /* ../dlls/user32/winstation.c:229 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumWindowStationsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumWindowStationsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumWindowStationsW(WINSTAENUMPROCW  func, LPARAM  lparam) /* ../dlls/user32/winstation.c:241 */
{
	TRACE("Enter EnumWindowStationsW\n");
	return pEnumWindowStationsW(func, lparam);
}

extern WINAPI void wine32a_user32_EnumWindowStationsW(void);  /* ../dlls/user32/winstation.c:241 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumWindowStationsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumWindowStationsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EnumWindows(WNDENUMPROC  lpEnumFunc, LPARAM  lParam) /* ../dlls/user32/win.c:3486 */
{
	TRACE("Enter EnumWindows\n");
	return pEnumWindows(lpEnumFunc, lParam);
}

extern WINAPI void wine32a_user32_EnumWindows(void);  /* ../dlls/user32/win.c:3486 */
__ASM_GLOBAL_FUNC(wine32a_user32_EnumWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EnumWindows") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_EqualRect(RECT*  rect1, RECT*  rect2) /* ../dlls/user32/uitools.c:1386 */
{
	TRACE("Enter EqualRect\n");
	return pEqualRect(rect1, rect2);
}

extern WINAPI void wine32a_user32_EqualRect(void);  /* ../dlls/user32/uitools.c:1386 */
__ASM_GLOBAL_FUNC(wine32a_user32_EqualRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_EqualRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_ExcludeUpdateRgn(HDC  hdc, HWND  hwnd) /* ../dlls/user32/painting.c:1441 */
{
	TRACE("Enter ExcludeUpdateRgn\n");
	return pExcludeUpdateRgn(hdc, hwnd);
}

extern WINAPI void wine32a_user32_ExcludeUpdateRgn(void);  /* ../dlls/user32/painting.c:1441 */
__ASM_GLOBAL_FUNC(wine32a_user32_ExcludeUpdateRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ExcludeUpdateRgn") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ExitWindowsEx(UINT  flags, DWORD  reason) /* ../dlls/user32/user_main.c:426 */
{
	TRACE("Enter ExitWindowsEx\n");
	return pExitWindowsEx(flags, reason);
}

extern WINAPI void wine32a_user32_ExitWindowsEx(void);  /* ../dlls/user32/user_main.c:426 */
__ASM_GLOBAL_FUNC(wine32a_user32_ExitWindowsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ExitWindowsEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_FillRect(HDC  hdc, RECT*  rect, HBRUSH  hbrush) /* ../dlls/user32/uitools.c:1437 */
{
	TRACE("Enter FillRect\n");
	return pFillRect(hdc, rect, hbrush);
}

extern WINAPI void wine32a_user32_FillRect(void);  /* ../dlls/user32/uitools.c:1437 */
__ASM_GLOBAL_FUNC(wine32a_user32_FillRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_FillRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_FindWindowA(LPCSTR  className, LPCSTR  title) /* ../dlls/user32/win.c:2014 */
{
	TRACE("Enter FindWindowA\n");
	return pFindWindowA(className, title);
}

extern WINAPI void wine32a_user32_FindWindowA(void);  /* ../dlls/user32/win.c:2014 */
__ASM_GLOBAL_FUNC(wine32a_user32_FindWindowA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_FindWindowA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_FindWindowExA(HWND  parent, HWND  child, LPCSTR  className, LPCSTR  title) /* ../dlls/user32/win.c:2025 */
{
	TRACE("Enter FindWindowExA\n");
	return pFindWindowExA(parent, child, className, title);
}

extern WINAPI void wine32a_user32_FindWindowExA(void);  /* ../dlls/user32/win.c:2025 */
__ASM_GLOBAL_FUNC(wine32a_user32_FindWindowExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_FindWindowExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_FindWindowExW(HWND  parent, HWND  child, LPCWSTR  className, LPCWSTR  title) /* ../dlls/user32/win.c:1960 */
{
	TRACE("Enter FindWindowExW\n");
	return pFindWindowExW(parent, child, className, title);
}

extern WINAPI void wine32a_user32_FindWindowExW(void);  /* ../dlls/user32/win.c:1960 */
__ASM_GLOBAL_FUNC(wine32a_user32_FindWindowExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_FindWindowExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_FindWindowW(LPCWSTR  className, LPCWSTR  title) /* ../dlls/user32/win.c:2056 */
{
	TRACE("Enter FindWindowW\n");
	return pFindWindowW(className, title);
}

extern WINAPI void wine32a_user32_FindWindowW(void);  /* ../dlls/user32/win.c:2056 */
__ASM_GLOBAL_FUNC(wine32a_user32_FindWindowW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_FindWindowW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_FlashWindow(HWND  hWnd, BOOL  bInvert) /* ../dlls/user32/win.c:3649 */
{
	TRACE("Enter FlashWindow\n");
	return pFlashWindow(hWnd, bInvert);
}

extern WINAPI void wine32a_user32_FlashWindow(void);  /* ../dlls/user32/win.c:3649 */
__ASM_GLOBAL_FUNC(wine32a_user32_FlashWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_FlashWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_FlashWindowEx(PFLASHWINFO  pfinfo) /* ../dlls/user32/win.c:3664 */
{
	TRACE("Enter FlashWindowEx\n");
	return pFlashWindowEx(pfinfo);
}

extern WINAPI void wine32a_user32_FlashWindowEx(void);  /* ../dlls/user32/win.c:3664 */
__ASM_GLOBAL_FUNC(wine32a_user32_FlashWindowEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_FlashWindowEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_FrameRect(HDC  hdc, RECT*  rect, HBRUSH  hbrush) /* ../dlls/user32/uitools.c:1464 */
{
	TRACE("Enter FrameRect\n");
	return pFrameRect(hdc, rect, hbrush);
}

extern WINAPI void wine32a_user32_FrameRect(void);  /* ../dlls/user32/uitools.c:1464 */
__ASM_GLOBAL_FUNC(wine32a_user32_FrameRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_FrameRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_FreeDDElParam(UINT  msg, LPARAM  lParam) /* ../dlls/user32/dde_misc.c:160 */
{
	TRACE("Enter FreeDDElParam\n");
	return pFreeDDElParam(msg, lParam);
}

extern WINAPI void wine32a_user32_FreeDDElParam(void);  /* ../dlls/user32/dde_misc.c:160 */
__ASM_GLOBAL_FUNC(wine32a_user32_FreeDDElParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_FreeDDElParam") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetActiveWindow(void) /* ../dlls/user32/focus.c:332 */
{
	TRACE("Enter GetActiveWindow\n");
	return pGetActiveWindow();
}

extern WINAPI void wine32a_user32_GetActiveWindow(void);  /* ../dlls/user32/focus.c:332 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetActiveWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetActiveWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetAltTabInfoA(HWND  hwnd, int  iItem, PALTTABINFO  pati, LPSTR  pszItemText, UINT  cchItemText) /* ../dlls/user32/misc.c:185 */
{
	TRACE("Enter GetAltTabInfoA\n");
	return pGetAltTabInfoA(hwnd, iItem, pati, pszItemText, cchItemText);
}

extern WINAPI void wine32a_user32_GetAltTabInfoA(void);  /* ../dlls/user32/misc.c:185 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetAltTabInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetAltTabInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetAltTabInfoW(HWND  hwnd, int  iItem, PALTTABINFO  pati, LPWSTR  pszItemText, UINT  cchItemText) /* ../dlls/user32/misc.c:194 */
{
	TRACE("Enter GetAltTabInfoW\n");
	return pGetAltTabInfoW(hwnd, iItem, pati, pszItemText, cchItemText);
}

extern WINAPI void wine32a_user32_GetAltTabInfoW(void);  /* ../dlls/user32/misc.c:194 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetAltTabInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetAltTabInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetAncestor(HWND  hwnd, UINT  type) /* ../dlls/user32/win.c:3105 */
{
	TRACE("Enter GetAncestor\n");
	return pGetAncestor(hwnd, type);
}

extern WINAPI void wine32a_user32_GetAncestor(void);  /* ../dlls/user32/win.c:3105 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetAncestor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetAncestor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetAppCompatFlags(HTASK  hTask) /* ../dlls/user32/misc.c:347 */
{
	TRACE("Enter GetAppCompatFlags\n");
	return pGetAppCompatFlags(hTask);
}

extern WINAPI void wine32a_user32_GetAppCompatFlags(void);  /* ../dlls/user32/misc.c:347 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetAppCompatFlags,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetAppCompatFlags") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetAppCompatFlags2(HTASK  hTask) /* ../dlls/user32/misc.c:356 */
{
	TRACE("Enter GetAppCompatFlags2\n");
	return pGetAppCompatFlags2(hTask);
}

extern WINAPI void wine32a_user32_GetAppCompatFlags2(void);  /* ../dlls/user32/misc.c:356 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetAppCompatFlags2,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetAppCompatFlags2") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SHORT wine32b_user32_GetAsyncKeyState(INT  key) /* ../dlls/user32/input.c:393 */
{
	TRACE("Enter GetAsyncKeyState\n");
	return pGetAsyncKeyState(key);
}

extern WINAPI void wine32a_user32_GetAsyncKeyState(void);  /* ../dlls/user32/input.c:393 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetAsyncKeyState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetAsyncKeyState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetAutoRotationState(AR_STATE*  state) /* ../dlls/user32/sysparams.c:4263 */
{
	TRACE("Enter GetAutoRotationState\n");
	return pGetAutoRotationState(state);
}

extern WINAPI void wine32a_user32_GetAutoRotationState(void);  /* ../dlls/user32/sysparams.c:4263 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetAutoRotationState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetAutoRotationState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DPI_AWARENESS wine32b_user32_GetAwarenessFromDpiAwarenessContext(DPI_AWARENESS_CONTEXT  context) /* ../dlls/user32/sysparams.c:3475 */
{
	TRACE("Enter GetAwarenessFromDpiAwarenessContext\n");
	return pGetAwarenessFromDpiAwarenessContext(context);
}

extern WINAPI void wine32a_user32_GetAwarenessFromDpiAwarenessContext(void);  /* ../dlls/user32/sysparams.c:3475 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetAwarenessFromDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetAwarenessFromDpiAwarenessContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetCapture(void) /* ../dlls/user32/input.c:366 */
{
	TRACE("Enter GetCapture\n");
	return pGetCapture();
}

extern WINAPI void wine32a_user32_GetCapture(void);  /* ../dlls/user32/input.c:366 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetCapture,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetCapture") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetCaretBlinkTime(void) /* ../dlls/user32/caret.c:406 */
{
	TRACE("Enter GetCaretBlinkTime\n");
	return pGetCaretBlinkTime();
}

extern WINAPI void wine32a_user32_GetCaretBlinkTime(void);  /* ../dlls/user32/caret.c:406 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetCaretBlinkTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetCaretBlinkTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetCaretPos(LPPOINT  pt) /* ../dlls/user32/caret.c:367 */
{
	TRACE("Enter GetCaretPos\n");
	return pGetCaretPos(pt);
}

extern WINAPI void wine32a_user32_GetCaretPos(void);  /* ../dlls/user32/caret.c:367 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetCaretPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetCaretPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetClassInfoA(HINSTANCE  hInstance, LPCSTR  name, WNDCLASSA*  wc) /* ../dlls/user32/class.c:1261 */
{
	TRACE("Enter GetClassInfoA\n");
	return pGetClassInfoA(hInstance, name, wc);
}

extern WINAPI void wine32a_user32_GetClassInfoA(void);  /* ../dlls/user32/class.c:1261 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetClassInfoExA(HINSTANCE  hInstance, LPCSTR  name, WNDCLASSEXA*  wc) /* ../dlls/user32/class.c:1311 */
{
	TRACE("Enter GetClassInfoExA\n");
	return pGetClassInfoExA(hInstance, name, wc);
}

extern WINAPI void wine32a_user32_GetClassInfoExA(void);  /* ../dlls/user32/class.c:1311 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassInfoExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetClassInfoExW(HINSTANCE  hInstance, LPCWSTR  name, WNDCLASSEXW*  wc) /* ../dlls/user32/class.c:1362 */
{
	TRACE("Enter GetClassInfoExW\n");
	return pGetClassInfoExW(hInstance, name, wc);
}

extern WINAPI void wine32a_user32_GetClassInfoExW(void);  /* ../dlls/user32/class.c:1362 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassInfoExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetClassInfoW(HINSTANCE  hInstance, LPCWSTR  name, WNDCLASSW*  wc) /* ../dlls/user32/class.c:1286 */
{
	TRACE("Enter GetClassInfoW\n");
	return pGetClassInfoW(hInstance, name, wc);
}

extern WINAPI void wine32a_user32_GetClassInfoW(void);  /* ../dlls/user32/class.c:1286 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetClassLongA(HWND  hwnd, INT  offset) /* ../dlls/user32/class.c:1006 */
{
	TRACE("Enter GetClassLongA\n");
	return pGetClassLongA(hwnd, offset);
}

extern WINAPI void wine32a_user32_GetClassLongA(void);  /* ../dlls/user32/class.c:1006 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassLongA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassLongA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetClassLongW(HWND  hwnd, INT  offset) /* ../dlls/user32/class.c:996 */
{
	TRACE("Enter GetClassLongW\n");
	return pGetClassLongW(hwnd, offset);
}

extern WINAPI void wine32a_user32_GetClassLongW(void);  /* ../dlls/user32/class.c:996 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassLongW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassLongW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG_PTR wine32b_user32_GetClassLongPtrA(HWND  hwnd, INT  offset) /* ../dlls/user32/class.c:1460 */
{
	TRACE("Enter GetClassLongPtrA\n");
	return pGetClassLongPtrA(hwnd, offset);
}

extern WINAPI void wine32a_user32_GetClassLongPtrA(void);  /* ../dlls/user32/class.c:1460 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassLongPtrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassLongPtrA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG_PTR wine32b_user32_GetClassLongPtrW(HWND  hwnd, INT  offset) /* ../dlls/user32/class.c:1468 */
{
	TRACE("Enter GetClassLongPtrW\n");
	return pGetClassLongPtrW(hwnd, offset);
}

extern WINAPI void wine32a_user32_GetClassLongPtrW(void);  /* ../dlls/user32/class.c:1468 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassLongPtrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassLongPtrW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetClassNameA(HWND  hwnd, LPSTR  buffer, INT  count) /* ../dlls/user32/class.c:1178 */
{
	TRACE("Enter GetClassNameA\n");
	return pGetClassNameA(hwnd, buffer, count);
}

extern WINAPI void wine32a_user32_GetClassNameA(void);  /* ../dlls/user32/class.c:1178 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetClassNameW(HWND  hwnd, LPWSTR  buffer, INT  count) /* ../dlls/user32/class.c:1194 */
{
	TRACE("Enter GetClassNameW\n");
	return pGetClassNameW(hwnd, buffer, count);
}

extern WINAPI void wine32a_user32_GetClassNameW(void);  /* ../dlls/user32/class.c:1194 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_GetClassWord(HWND  hwnd, INT  offset) /* ../dlls/user32/class.c:821 */
{
	TRACE("Enter GetClassWord\n");
	return pGetClassWord(hwnd, offset);
}

extern WINAPI void wine32a_user32_GetClassWord(void);  /* ../dlls/user32/class.c:821 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClassWord,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClassWord") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetClientRect(HWND  hwnd, LPRECT  rect) /* ../dlls/user32/winpos.c:234 */
{
	TRACE("Enter GetClientRect\n");
	return pGetClientRect(hwnd, rect);
}

extern WINAPI void wine32a_user32_GetClientRect(void);  /* ../dlls/user32/winpos.c:234 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClientRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClientRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetClipCursor(RECT*  rect) /* ../dlls/user32/cursoricon.c:2166 */
{
	TRACE("Enter GetClipCursor\n");
	return pGetClipCursor(rect);
}

extern WINAPI void wine32a_user32_GetClipCursor(void);  /* ../dlls/user32/cursoricon.c:2166 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClipCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClipCursor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_user32_GetClipboardData(UINT  format) /* ../dlls/user32/clipboard.c:1030 */
{
	TRACE("Enter GetClipboardData\n");
	return pGetClipboardData(format);
}

extern WINAPI void wine32a_user32_GetClipboardData(void);  /* ../dlls/user32/clipboard.c:1030 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClipboardData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClipboardData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetClipboardFormatNameA(UINT  format, LPSTR  buffer, INT  maxlen) /* ../dlls/user32/clipboard.c:677 */
{
	TRACE("Enter GetClipboardFormatNameA\n");
	return pGetClipboardFormatNameA(format, buffer, maxlen);
}

extern WINAPI void wine32a_user32_GetClipboardFormatNameA(void);  /* ../dlls/user32/clipboard.c:677 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClipboardFormatNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClipboardFormatNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetClipboardFormatNameW(UINT  format, LPWSTR  buffer, INT  maxlen) /* ../dlls/user32/clipboard.c:667 */
{
	TRACE("Enter GetClipboardFormatNameW\n");
	return pGetClipboardFormatNameW(format, buffer, maxlen);
}

extern WINAPI void wine32a_user32_GetClipboardFormatNameW(void);  /* ../dlls/user32/clipboard.c:667 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClipboardFormatNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClipboardFormatNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetClipboardOwner(void) /* ../dlls/user32/clipboard.c:769 */
{
	TRACE("Enter GetClipboardOwner\n");
	return pGetClipboardOwner();
}

extern WINAPI void wine32a_user32_GetClipboardOwner(void);  /* ../dlls/user32/clipboard.c:769 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClipboardOwner,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClipboardOwner") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetClipboardSequenceNumber(void) /* ../dlls/user32/clipboard.c:1126 */
{
	TRACE("Enter GetClipboardSequenceNumber\n");
	return pGetClipboardSequenceNumber();
}

extern WINAPI void wine32a_user32_GetClipboardSequenceNumber(void);  /* ../dlls/user32/clipboard.c:1126 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClipboardSequenceNumber,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClipboardSequenceNumber") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetClipboardViewer(void) /* ../dlls/user32/clipboard.c:832 */
{
	TRACE("Enter GetClipboardViewer\n");
	return pGetClipboardViewer();
}

extern WINAPI void wine32a_user32_GetClipboardViewer(void);  /* ../dlls/user32/clipboard.c:832 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetClipboardViewer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetClipboardViewer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetComboBoxInfo(HWND  hwndCombo, PCOMBOBOXINFO  pcbi) /* ../dlls/user32/combo.c:2181 */
{
	TRACE("Enter GetComboBoxInfo\n");
	return pGetComboBoxInfo(hwndCombo, pcbi);
}

extern WINAPI void wine32a_user32_GetComboBoxInfo(void);  /* ../dlls/user32/combo.c:2181 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetComboBoxInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetComboBoxInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetCurrentInputMessageSource(INPUT_MESSAGE_SOURCE*  source) /* ../dlls/user32/message.c:4151 */
{
	TRACE("Enter GetCurrentInputMessageSource\n");
	return pGetCurrentInputMessageSource(source);
}

extern WINAPI void wine32a_user32_GetCurrentInputMessageSource(void);  /* ../dlls/user32/message.c:4151 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetCurrentInputMessageSource,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetCurrentInputMessageSource") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCURSOR wine32b_user32_GetCursor(void) /* ../dlls/user32/cursoricon.c:2099 */
{
	TRACE("Enter GetCursor\n");
	return pGetCursor();
}

extern WINAPI void wine32a_user32_GetCursor(void);  /* ../dlls/user32/cursoricon.c:2099 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetCursor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCURSOR wine32b_user32_GetCursorFrameInfo(HCURSOR  hCursor, DWORD  reserved, DWORD  istep, DWORD*  rate_jiffies, DWORD*  num_steps) /* ../dlls/user32/cursoricon.c:2323 */
{
	TRACE("Enter GetCursorFrameInfo\n");
	return pGetCursorFrameInfo(hCursor, reserved, istep, rate_jiffies, num_steps);
}

extern WINAPI void wine32a_user32_GetCursorFrameInfo(void);  /* ../dlls/user32/cursoricon.c:2323 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetCursorFrameInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetCursorFrameInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetCursorInfo(PCURSORINFO  pci) /* ../dlls/user32/input.c:285 */
{
	TRACE("Enter GetCursorInfo\n");
	return pGetCursorInfo(pci);
}

extern WINAPI void wine32a_user32_GetCursorInfo(void);  /* ../dlls/user32/input.c:285 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetCursorInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetCursorInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetCursorPos(POINT*  pt) /* ../dlls/user32/input.c:250 */
{
	TRACE("Enter GetCursorPos\n");
	return pGetCursorPos(pt);
}

extern WINAPI void wine32a_user32_GetCursorPos(void);  /* ../dlls/user32/input.c:250 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetCursorPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetCursorPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDC wine32b_user32_GetDC(HWND  hwnd) /* ../dlls/user32/painting.c:1135 */
{
	TRACE("Enter GetDC\n");
	return pGetDC(hwnd);
}

extern WINAPI void wine32a_user32_GetDC(void);  /* ../dlls/user32/painting.c:1135 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDC") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDC wine32b_user32_GetDCEx(HWND  hwnd, HRGN  hrgnClip, DWORD  flags) /* ../dlls/user32/painting.c:983 */
{
	TRACE("Enter GetDCEx\n");
	return pGetDCEx(hwnd, hrgnClip, flags);
}

extern WINAPI void wine32a_user32_GetDCEx(void);  /* ../dlls/user32/painting.c:983 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDCEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDCEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetDesktopWindow(void) /* ../dlls/user32/win.c:2065 */
{
	TRACE("Enter GetDesktopWindow\n");
	return pGetDesktopWindow();
}

extern WINAPI void wine32a_user32_GetDesktopWindow(void);  /* ../dlls/user32/win.c:2065 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDesktopWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDesktopWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetDialogBaseUnits(void) /* ../dlls/user32/dialog.c:1519 */
{
	TRACE("Enter GetDialogBaseUnits\n");
	return pGetDialogBaseUnits();
}

extern WINAPI void wine32a_user32_GetDialogBaseUnits(void);  /* ../dlls/user32/dialog.c:1519 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDialogBaseUnits,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDialogBaseUnits") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetDisplayAutoRotationPreferences(ORIENTATION_PREFERENCE*  orientation) /* ../dlls/user32/sysparams.c:4280 */
{
	TRACE("Enter GetDisplayAutoRotationPreferences\n");
	return pGetDisplayAutoRotationPreferences(orientation);
}

extern WINAPI void wine32a_user32_GetDisplayAutoRotationPreferences(void);  /* ../dlls/user32/sysparams.c:4280 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDisplayAutoRotationPreferences,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDisplayAutoRotationPreferences") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_GetDisplayConfigBufferSizes(UINT32  flags, UINT32*  num_path_info, UINT32*  num_mode_info) /* ../dlls/user32/misc.c:551 */
{
	TRACE("Enter GetDisplayConfigBufferSizes\n");
	return pGetDisplayConfigBufferSizes(flags, num_path_info, num_mode_info);
}

extern WINAPI void wine32a_user32_GetDisplayConfigBufferSizes(void);  /* ../dlls/user32/misc.c:551 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDisplayConfigBufferSizes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDisplayConfigBufferSizes") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetDlgCtrlID(HWND  hwnd) /* ../dlls/user32/dialog.c:1316 */
{
	TRACE("Enter GetDlgCtrlID\n");
	return pGetDlgCtrlID(hwnd);
}

extern WINAPI void wine32a_user32_GetDlgCtrlID(void);  /* ../dlls/user32/dialog.c:1316 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDlgCtrlID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDlgCtrlID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetDlgItem(HWND  hwndDlg, INT  id) /* ../dlls/user32/dialog.c:1325 */
{
	TRACE("Enter GetDlgItem\n");
	return pGetDlgItem(hwndDlg, id);
}

extern WINAPI void wine32a_user32_GetDlgItem(void);  /* ../dlls/user32/dialog.c:1325 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDlgItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDlgItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetDlgItemInt(HWND  hwnd, INT  id, BOOL*  translated, BOOL  fSigned) /* ../dlls/user32/dialog.c:1422 */
{
	TRACE("Enter GetDlgItemInt\n");
	return pGetDlgItemInt(hwnd, id, translated, fSigned);
}

extern WINAPI void wine32a_user32_GetDlgItemInt(void);  /* ../dlls/user32/dialog.c:1422 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDlgItemInt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDlgItemInt") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetDlgItemTextA(HWND  hwnd, INT  id, LPSTR  str, INT  len) /* ../dlls/user32/dialog.c:1385 */
{
	TRACE("Enter GetDlgItemTextA\n");
	return pGetDlgItemTextA(hwnd, id, str, len);
}

extern WINAPI void wine32a_user32_GetDlgItemTextA(void);  /* ../dlls/user32/dialog.c:1385 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDlgItemTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDlgItemTextA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetDlgItemTextW(HWND  hwnd, INT  id, LPWSTR  str, INT  len) /* ../dlls/user32/dialog.c:1396 */
{
	TRACE("Enter GetDlgItemTextW\n");
	return pGetDlgItemTextW(hwnd, id, str, len);
}

extern WINAPI void wine32a_user32_GetDlgItemTextW(void);  /* ../dlls/user32/dialog.c:1396 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDlgItemTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDlgItemTextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetDoubleClickTime(void) /* ../dlls/user32/sysparams.c:3024 */
{
	TRACE("Enter GetDoubleClickTime\n");
	return pGetDoubleClickTime();
}

extern WINAPI void wine32a_user32_GetDoubleClickTime(void);  /* ../dlls/user32/sysparams.c:3024 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDoubleClickTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDoubleClickTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetDpiForMonitorInternal(HMONITOR  monitor, UINT  type, UINT*  x, UINT*  y) /* ../dlls/user32/sysparams.c:3533 */
{
	TRACE("Enter GetDpiForMonitorInternal\n");
	return pGetDpiForMonitorInternal(monitor, type, x, y);
}

extern WINAPI void wine32a_user32_GetDpiForMonitorInternal(void);  /* ../dlls/user32/sysparams.c:3533 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDpiForMonitorInternal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDpiForMonitorInternal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetDpiForSystem(void) /* ../dlls/user32/sysparams.c:3524 */
{
	TRACE("Enter GetDpiForSystem\n");
	return pGetDpiForSystem();
}

extern WINAPI void wine32a_user32_GetDpiForSystem(void);  /* ../dlls/user32/sysparams.c:3524 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDpiForSystem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDpiForSystem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetDpiForWindow(HWND  hwnd) /* ../dlls/user32/win.c:2270 */
{
	TRACE("Enter GetDpiForWindow\n");
	return pGetDpiForWindow(hwnd);
}

extern WINAPI void wine32a_user32_GetDpiForWindow(void);  /* ../dlls/user32/win.c:2270 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetDpiForWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetDpiForWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetFocus(void) /* ../dlls/user32/focus.c:349 */
{
	TRACE("Enter GetFocus\n");
	return pGetFocus();
}

extern WINAPI void wine32a_user32_GetFocus(void);  /* ../dlls/user32/focus.c:349 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetFocus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetFocus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetForegroundWindow(void) /* ../dlls/user32/focus.c:366 */
{
	TRACE("Enter GetForegroundWindow\n");
	return pGetForegroundWindow();
}

extern WINAPI void wine32a_user32_GetForegroundWindow(void);  /* ../dlls/user32/focus.c:366 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetForegroundWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetForegroundWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetGestureConfig(HWND  hwnd, DWORD  reserved, DWORD  flags, UINT*  count, GESTURECONFIG*  config, UINT  size) /* ../dlls/user32/misc.c:513 */
{
	TRACE("Enter GetGestureConfig\n");
	return pGetGestureConfig(hwnd, reserved, flags, count, config, size);
}

extern WINAPI void wine32a_user32_GetGestureConfig(void);  /* ../dlls/user32/misc.c:513 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetGestureConfig,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetGestureConfig") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetGestureInfo(HGESTUREINFO  handle, PGESTUREINFO  ptr) /* ../dlls/user32/win.c:4193 */
{
	TRACE("Enter GetGestureInfo\n");
	return pGetGestureInfo(handle, ptr);
}

extern WINAPI void wine32a_user32_GetGestureInfo(void);  /* ../dlls/user32/win.c:4193 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetGestureInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetGestureInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetGUIThreadInfo(DWORD  id, GUITHREADINFO*  info) /* ../dlls/user32/message.c:4604 */
{
	TRACE("Enter GetGUIThreadInfo\n");
	return pGetGUIThreadInfo(id, info);
}

extern WINAPI void wine32a_user32_GetGUIThreadInfo(void);  /* ../dlls/user32/message.c:4604 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetGUIThreadInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetGUIThreadInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetGuiResources(HANDLE  hProcess, DWORD  uiFlags) /* ../dlls/user32/resource.c:326 */
{
	TRACE("Enter GetGuiResources\n");
	return pGetGuiResources(hProcess, uiFlags);
}

extern WINAPI void wine32a_user32_GetGuiResources(void);  /* ../dlls/user32/resource.c:326 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetGuiResources,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetGuiResources") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetIconInfo(HICON  hIcon, PICONINFO  iconinfo) /* ../dlls/user32/cursoricon.c:2386 */
{
	TRACE("Enter GetIconInfo\n");
	return pGetIconInfo(hIcon, iconinfo);
}

extern WINAPI void wine32a_user32_GetIconInfo(void);  /* ../dlls/user32/cursoricon.c:2386 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetIconInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetIconInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetIconInfoExA(HICON  icon, ICONINFOEXA*  info) /* ../dlls/user32/cursoricon.c:2403 */
{
	TRACE("Enter GetIconInfoExA\n");
	return pGetIconInfoExA(icon, info);
}

extern WINAPI void wine32a_user32_GetIconInfoExA(void);  /* ../dlls/user32/cursoricon.c:2403 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetIconInfoExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetIconInfoExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetIconInfoExW(HICON  icon, ICONINFOEXW*  info) /* ../dlls/user32/cursoricon.c:2428 */
{
	TRACE("Enter GetIconInfoExW\n");
	return pGetIconInfoExW(icon, info);
}

extern WINAPI void wine32a_user32_GetIconInfoExW(void);  /* ../dlls/user32/cursoricon.c:2428 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetIconInfoExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetIconInfoExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetInputState(void) /* ../dlls/user32/input.c:482 */
{
	TRACE("Enter GetInputState\n");
	return pGetInputState();
}

extern WINAPI void wine32a_user32_GetInputState(void);  /* ../dlls/user32/input.c:482 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetInputState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetInputState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetInternalWindowPos(HWND  hwnd, LPRECT  rectWnd, LPPOINT  ptIcon) /* ../dlls/user32/winpos.c:1241 */
{
	TRACE("Enter GetInternalWindowPos\n");
	return pGetInternalWindowPos(hwnd, rectWnd, ptIcon);
}

extern WINAPI void wine32a_user32_GetInternalWindowPos(void);  /* ../dlls/user32/winpos.c:1241 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetInternalWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetInternalWindowPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetKBCodePage(void) /* ../dlls/user32/input.c:777 */
{
	TRACE("Enter GetKBCodePage\n");
	return pGetKBCodePage();
}

extern WINAPI void wine32a_user32_GetKBCodePage(void);  /* ../dlls/user32/input.c:777 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetKBCodePage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetKBCodePage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetKeyNameTextA(LONG  lParam, LPSTR  lpBuffer, INT  nSize) /* ../dlls/user32/input.c:822 */
{
	TRACE("Enter GetKeyNameTextA\n");
	return pGetKeyNameTextA(lParam, lpBuffer, nSize);
}

extern WINAPI void wine32a_user32_GetKeyNameTextA(void);  /* ../dlls/user32/input.c:822 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetKeyNameTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetKeyNameTextA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetKeyNameTextW(LONG  lParam, LPWSTR  lpBuffer, INT  nSize) /* ../dlls/user32/input.c:846 */
{
	TRACE("Enter GetKeyNameTextW\n");
	return pGetKeyNameTextW(lParam, lpBuffer, nSize);
}

extern WINAPI void wine32a_user32_GetKeyNameTextW(void);  /* ../dlls/user32/input.c:846 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetKeyNameTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetKeyNameTextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SHORT wine32b_user32_GetKeyState(INT  vkey) /* ../dlls/user32/input.c:554 */
{
	TRACE("Enter GetKeyState\n");
	return pGetKeyState(vkey);
}

extern WINAPI void wine32a_user32_GetKeyState(void);  /* ../dlls/user32/input.c:554 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetKeyState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetKeyState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HKL wine32b_user32_GetKeyboardLayout(DWORD  thread_id) /* ../dlls/user32/input.c:789 */
{
	TRACE("Enter GetKeyboardLayout\n");
	return pGetKeyboardLayout(thread_id);
}

extern WINAPI void wine32a_user32_GetKeyboardLayout(void);  /* ../dlls/user32/input.c:789 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetKeyboardLayout,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetKeyboardLayout") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetKeyboardLayoutList(INT  nBuff, HKL*  layouts) /* ../dlls/user32/input.c:923 */
{
	TRACE("Enter GetKeyboardLayoutList\n");
	return pGetKeyboardLayoutList(nBuff, layouts);
}

extern WINAPI void wine32a_user32_GetKeyboardLayoutList(void);  /* ../dlls/user32/input.c:923 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetKeyboardLayoutList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetKeyboardLayoutList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetKeyboardLayoutNameA(LPSTR  pszKLID) /* ../dlls/user32/input.c:797 */
{
	TRACE("Enter GetKeyboardLayoutNameA\n");
	return pGetKeyboardLayoutNameA(pszKLID);
}

extern WINAPI void wine32a_user32_GetKeyboardLayoutNameA(void);  /* ../dlls/user32/input.c:797 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetKeyboardLayoutNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetKeyboardLayoutNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetKeyboardLayoutNameW(LPWSTR  pwszKLID) /* ../dlls/user32/input.c:809 */
{
	TRACE("Enter GetKeyboardLayoutNameW\n");
	return pGetKeyboardLayoutNameW(pwszKLID);
}

extern WINAPI void wine32a_user32_GetKeyboardLayoutNameW(void);  /* ../dlls/user32/input.c:809 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetKeyboardLayoutNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetKeyboardLayoutNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetKeyboardState(LPBYTE  state) /* ../dlls/user32/input.c:573 */
{
	TRACE("Enter GetKeyboardState\n");
	return pGetKeyboardState(state);
}

extern WINAPI void wine32a_user32_GetKeyboardState(void);  /* ../dlls/user32/input.c:573 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetKeyboardState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetKeyboardState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetKeyboardType(INT  nTypeFlag) /* ../dlls/user32/input.c:690 */
{
	TRACE("Enter GetKeyboardType\n");
	return pGetKeyboardType(nTypeFlag);
}

extern WINAPI void wine32a_user32_GetKeyboardType(void);  /* ../dlls/user32/input.c:690 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetKeyboardType,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetKeyboardType") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetLastActivePopup(HWND  hwnd) /* ../dlls/user32/win.c:3452 */
{
	TRACE("Enter GetLastActivePopup\n");
	return pGetLastActivePopup(hwnd);
}

extern WINAPI void wine32a_user32_GetLastActivePopup(void);  /* ../dlls/user32/win.c:3452 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetLastActivePopup,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetLastActivePopup") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetLastInputInfo(PLASTINPUTINFO  plii) /* ../dlls/user32/input.c:502 */
{
	TRACE("Enter GetLastInputInfo\n");
	return pGetLastInputInfo(plii);
}

extern WINAPI void wine32a_user32_GetLastInputInfo(void);  /* ../dlls/user32/input.c:502 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetLastInputInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetLastInputInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetLayeredWindowAttributes(HWND  hwnd, COLORREF*  key, BYTE*  alpha, DWORD*  flags) /* ../dlls/user32/win.c:3928 */
{
	TRACE("Enter GetLayeredWindowAttributes\n");
	return pGetLayeredWindowAttributes(hwnd, key, alpha, flags);
}

extern WINAPI void wine32a_user32_GetLayeredWindowAttributes(void);  /* ../dlls/user32/win.c:3928 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetLayeredWindowAttributes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetLayeredWindowAttributes") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetListBoxInfo(HWND  hwnd) /* ../dlls/user32/listbox.c:3263 */
{
	TRACE("Enter GetListBoxInfo\n");
	return pGetListBoxInfo(hwnd);
}

extern WINAPI void wine32a_user32_GetListBoxInfo(void);  /* ../dlls/user32/listbox.c:3263 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetListBoxInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetListBoxInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_user32_GetMenu(HWND  hWnd) /* ../dlls/user32/menu.c:4362 */
{
	TRACE("Enter GetMenu\n");
	return pGetMenu(hWnd);
}

extern WINAPI void wine32a_user32_GetMenu(void);  /* ../dlls/user32/menu.c:4362 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetMenuBarInfo(HWND  hwnd, LONG  idObject, LONG  idItem, PMENUBARINFO  pmbi) /* ../dlls/user32/menu.c:4372 */
{
	TRACE("Enter GetMenuBarInfo\n");
	return pGetMenuBarInfo(hwnd, idObject, idItem, pmbi);
}

extern WINAPI void wine32a_user32_GetMenuBarInfo(void);  /* ../dlls/user32/menu.c:4372 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuBarInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuBarInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetMenuCheckMarkDimensions(void) /* ../dlls/user32/menu.c:4209 */
{
	TRACE("Enter GetMenuCheckMarkDimensions\n");
	return pGetMenuCheckMarkDimensions();
}

extern WINAPI void wine32a_user32_GetMenuCheckMarkDimensions(void);  /* ../dlls/user32/menu.c:4209 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuCheckMarkDimensions,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuCheckMarkDimensions") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetMenuContextHelpId(HMENU  hMenu) /* ../dlls/user32/menu.c:5460 */
{
	TRACE("Enter GetMenuContextHelpId\n");
	return pGetMenuContextHelpId(hMenu);
}

extern WINAPI void wine32a_user32_GetMenuContextHelpId(void);  /* ../dlls/user32/menu.c:5460 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuContextHelpId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuContextHelpId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetMenuDefaultItem(HMENU  hmenu, UINT  bypos, UINT  flags) /* ../dlls/user32/menu.c:5166 */
{
	TRACE("Enter GetMenuDefaultItem\n");
	return pGetMenuDefaultItem(hmenu, bypos, flags);
}

extern WINAPI void wine32a_user32_GetMenuDefaultItem(void);  /* ../dlls/user32/menu.c:5166 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuDefaultItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuDefaultItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetMenuInfo(HMENU  hMenu, LPMENUINFO  lpmi) /* ../dlls/user32/menu.c:5407 */
{
	TRACE("Enter GetMenuInfo\n");
	return pGetMenuInfo(hMenu, lpmi);
}

extern WINAPI void wine32a_user32_GetMenuInfo(void);  /* ../dlls/user32/menu.c:5407 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetMenuItemCount(HMENU  hMenu) /* ../dlls/user32/menu.c:3923 */
{
	TRACE("Enter GetMenuItemCount\n");
	return pGetMenuItemCount(hMenu);
}

extern WINAPI void wine32a_user32_GetMenuItemCount(void);  /* ../dlls/user32/menu.c:3923 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuItemCount,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuItemCount") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetMenuItemID(HMENU  hMenu, INT  nPos) /* ../dlls/user32/menu.c:3940 */
{
	TRACE("Enter GetMenuItemID\n");
	return pGetMenuItemID(hMenu, nPos);
}

extern WINAPI void wine32a_user32_GetMenuItemID(void);  /* ../dlls/user32/menu.c:3940 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuItemID,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuItemID") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetMenuItemInfoA(HMENU  hmenu, UINT  item, BOOL  bypos, LPMENUITEMINFOA  lpmii) /* ../dlls/user32/menu.c:4849 */
{
	TRACE("Enter GetMenuItemInfoA\n");
	return pGetMenuItemInfoA(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_user32_GetMenuItemInfoA(void);  /* ../dlls/user32/menu.c:4849 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuItemInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuItemInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetMenuItemInfoW(HMENU  hmenu, UINT  item, BOOL  bypos, LPMENUITEMINFOW  lpmii) /* ../dlls/user32/menu.c:4871 */
{
	TRACE("Enter GetMenuItemInfoW\n");
	return pGetMenuItemInfoW(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_user32_GetMenuItemInfoW(void);  /* ../dlls/user32/menu.c:4871 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuItemInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuItemInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetMenuItemRect(HWND  hwnd, HMENU  hMenu, UINT  uItem, RECT*  rect) /* ../dlls/user32/menu.c:5311 */
{
	TRACE("Enter GetMenuItemRect\n");
	return pGetMenuItemRect(hwnd, hMenu, uItem, rect);
}

extern WINAPI void wine32a_user32_GetMenuItemRect(void);  /* ../dlls/user32/menu.c:5311 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuItemRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuItemRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetMenuState(HMENU  hMenu, UINT  wItemID, UINT  wFlags) /* ../dlls/user32/menu.c:3886 */
{
	TRACE("Enter GetMenuState\n");
	return pGetMenuState(hMenu, wItemID, wFlags);
}

extern WINAPI void wine32a_user32_GetMenuState(void);  /* ../dlls/user32/menu.c:3886 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetMenuStringA(HMENU  hMenu, UINT  wItemID, LPSTR  str, INT  nMaxSiz, UINT  wFlags) /* ../dlls/user32/menu.c:3774 */
{
	TRACE("Enter GetMenuStringA\n");
	return pGetMenuStringA(hMenu, wItemID, str, nMaxSiz, wFlags);
}

extern WINAPI void wine32a_user32_GetMenuStringA(void);  /* ../dlls/user32/menu.c:3774 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetMenuStringW(HMENU  hMenu, UINT  wItemID, LPWSTR  str, INT  nMaxSiz, UINT  wFlags) /* ../dlls/user32/menu.c:3817 */
{
	TRACE("Enter GetMenuStringW\n");
	return pGetMenuStringW(hMenu, wItemID, str, nMaxSiz, wFlags);
}

extern WINAPI void wine32a_user32_GetMenuStringW(void);  /* ../dlls/user32/menu.c:3817 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMenuStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMenuStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetMessageA(MSG*  msg, HWND  hwnd, UINT  first, UINT  last) /* ../dlls/user32/message.c:3866 */
{
	TRACE("Enter GetMessageA\n");
	return pGetMessageA(msg, hwnd, first, last);
}

extern WINAPI void wine32a_user32_GetMessageA(void);  /* ../dlls/user32/message.c:3866 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPARAM wine32b_user32_GetMessageExtraInfo(void) /* ../dlls/user32/message.c:4130 */
{
	TRACE("Enter GetMessageExtraInfo\n");
	return pGetMessageExtraInfo();
}

extern WINAPI void wine32a_user32_GetMessageExtraInfo(void);  /* ../dlls/user32/message.c:4130 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMessageExtraInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMessageExtraInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetMessagePos(void) /* ../dlls/user32/message.c:4099 */
{
	TRACE("Enter GetMessagePos\n");
	return pGetMessagePos();
}

extern WINAPI void wine32a_user32_GetMessagePos(void);  /* ../dlls/user32/message.c:4099 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMessagePos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMessagePos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_GetMessageTime(void) /* ../dlls/user32/message.c:4120 */
{
	TRACE("Enter GetMessageTime\n");
	return pGetMessageTime();
}

extern WINAPI void wine32a_user32_GetMessageTime(void);  /* ../dlls/user32/message.c:4120 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMessageTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMessageTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetMessageW(MSG*  msg, HWND  hwnd, UINT  first, UINT  last) /* ../dlls/user32/message.c:3834 */
{
	TRACE("Enter GetMessageW\n");
	return pGetMessageW(msg, hwnd, first, last);
}

extern WINAPI void wine32a_user32_GetMessageW(void);  /* ../dlls/user32/message.c:3834 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetMonitorInfoA(HMONITOR  monitor, LPMONITORINFO  info) /* ../dlls/user32/sysparams.c:3861 */
{
	TRACE("Enter GetMonitorInfoA\n");
	return pGetMonitorInfoA(monitor, info);
}

extern WINAPI void wine32a_user32_GetMonitorInfoA(void);  /* ../dlls/user32/sysparams.c:3861 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMonitorInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMonitorInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetMonitorInfoW(HMONITOR  monitor, LPMONITORINFO  info) /* ../dlls/user32/sysparams.c:3885 */
{
	TRACE("Enter GetMonitorInfoW\n");
	return pGetMonitorInfoW(monitor, info);
}

extern WINAPI void wine32a_user32_GetMonitorInfoW(void);  /* ../dlls/user32/sysparams.c:3885 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMonitorInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMonitorInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_user32_GetMouseMovePointsEx(UINT  size, LPMOUSEMOVEPOINT  ptin, LPMOUSEMOVEPOINT  ptout, int  count, DWORD  res) /* ../dlls/user32/input.c:1275 */
{
	TRACE("Enter GetMouseMovePointsEx\n");
	return pGetMouseMovePointsEx(size, ptin, ptout, count, res);
}

extern WINAPI void wine32a_user32_GetMouseMovePointsEx(void);  /* ../dlls/user32/input.c:1275 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetMouseMovePointsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetMouseMovePointsEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetNextDlgGroupItem(HWND  hwndDlg, HWND  hwndCtrl, BOOL  fPrevious) /* ../dlls/user32/dialog.c:1564 */
{
	TRACE("Enter GetNextDlgGroupItem\n");
	return pGetNextDlgGroupItem(hwndDlg, hwndCtrl, fPrevious);
}

extern WINAPI void wine32a_user32_GetNextDlgGroupItem(void);  /* ../dlls/user32/dialog.c:1564 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetNextDlgGroupItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetNextDlgGroupItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetNextDlgTabItem(HWND  hwndDlg, HWND  hwndCtrl, BOOL  fPrevious) /* ../dlls/user32/dialog.c:1732 */
{
	TRACE("Enter GetNextDlgTabItem\n");
	return pGetNextDlgTabItem(hwndDlg, hwndCtrl, fPrevious);
}

extern WINAPI void wine32a_user32_GetNextDlgTabItem(void);  /* ../dlls/user32/dialog.c:1732 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetNextDlgTabItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetNextDlgTabItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetOpenClipboardWindow(void) /* ../dlls/user32/clipboard.c:788 */
{
	TRACE("Enter GetOpenClipboardWindow\n");
	return pGetOpenClipboardWindow();
}

extern WINAPI void wine32a_user32_GetOpenClipboardWindow(void);  /* ../dlls/user32/clipboard.c:788 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetOpenClipboardWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetOpenClipboardWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetParent(HWND  hwnd) /* ../dlls/user32/win.c:3064 */
{
	TRACE("Enter GetParent\n");
	return pGetParent(hwnd);
}

extern WINAPI void wine32a_user32_GetParent(void);  /* ../dlls/user32/win.c:3064 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetParent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetParent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetPhysicalCursorPos(POINT*  point) /* ../dlls/user32/sysparams.c:4292 */
{
	TRACE("Enter GetPhysicalCursorPos\n");
	return pGetPhysicalCursorPos(point);
}

extern WINAPI void wine32a_user32_GetPhysicalCursorPos(void);  /* ../dlls/user32/sysparams.c:4292 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetPhysicalCursorPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetPhysicalCursorPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetPointerDevices(UINT32*  device_count, POINTER_DEVICE_INFO*  devices) /* ../dlls/user32/misc.c:575 */
{
	TRACE("Enter GetPointerDevices\n");
	return pGetPointerDevices(device_count, devices);
}

extern WINAPI void wine32a_user32_GetPointerDevices(void);  /* ../dlls/user32/misc.c:575 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetPointerDevices,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetPointerDevices") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetPointerType(UINT32  id, POINTER_INPUT_TYPE*  type) /* ../dlls/user32/misc.c:601 */
{
	TRACE("Enter GetPointerType\n");
	return pGetPointerType(id, type);
}

extern WINAPI void wine32a_user32_GetPointerType(void);  /* ../dlls/user32/misc.c:601 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetPointerType,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetPointerType") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetPriorityClipboardFormat(UINT*  list, INT  nCount) /* ../dlls/user32/clipboard.c:1106 */
{
	TRACE("Enter GetPriorityClipboardFormat\n");
	return pGetPriorityClipboardFormat(list, nCount);
}

extern WINAPI void wine32a_user32_GetPriorityClipboardFormat(void);  /* ../dlls/user32/clipboard.c:1106 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetPriorityClipboardFormat,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetPriorityClipboardFormat") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetProcessDefaultLayout(DWORD*  layout) /* ../dlls/user32/win.c:4041 */
{
	TRACE("Enter GetProcessDefaultLayout\n");
	return pGetProcessDefaultLayout(layout);
}

extern WINAPI void wine32a_user32_GetProcessDefaultLayout(void);  /* ../dlls/user32/win.c:4041 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetProcessDefaultLayout,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetProcessDefaultLayout") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetProcessDpiAwarenessInternal(HANDLE  process, DPI_AWARENESS*  awareness) /* ../dlls/user32/sysparams.c:3434 */
{
	TRACE("Enter GetProcessDpiAwarenessInternal\n");
	return pGetProcessDpiAwarenessInternal(process, awareness);
}

extern WINAPI void wine32a_user32_GetProcessDpiAwarenessInternal(void);  /* ../dlls/user32/sysparams.c:3434 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetProcessDpiAwarenessInternal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetProcessDpiAwarenessInternal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWINSTA wine32b_user32_GetProcessWindowStation(void) /* ../dlls/user32/winstation.c:195 */
{
	TRACE("Enter GetProcessWindowStation\n");
	return pGetProcessWindowStation();
}

extern WINAPI void wine32a_user32_GetProcessWindowStation(void);  /* ../dlls/user32/winstation.c:195 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetProcessWindowStation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetProcessWindowStation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetProgmanWindow(void) /* ../dlls/user32/focus.c:470 */
{
	TRACE("Enter GetProgmanWindow\n");
	return pGetProgmanWindow();
}

extern WINAPI void wine32a_user32_GetProgmanWindow(void);  /* ../dlls/user32/focus.c:470 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetProgmanWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetProgmanWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_user32_GetPropA(HWND  hwnd, LPCSTR  str) /* ../dlls/user32/property.c:117 */
{
	TRACE("Enter GetPropA\n");
	return pGetPropA(hwnd, str);
}

extern WINAPI void wine32a_user32_GetPropA(void);  /* ../dlls/user32/property.c:117 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetPropA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetPropA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_user32_GetPropW(HWND  hwnd, LPCWSTR  str) /* ../dlls/user32/property.c:130 */
{
	TRACE("Enter GetPropW\n");
	return pGetPropW(hwnd, str);
}

extern WINAPI void wine32a_user32_GetPropW(void);  /* ../dlls/user32/property.c:130 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetPropW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetPropW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetQueueStatus(UINT  flags) /* ../dlls/user32/input.c:456 */
{
	TRACE("Enter GetQueueStatus\n");
	return pGetQueueStatus(flags);
}

extern WINAPI void wine32a_user32_GetQueueStatus(void);  /* ../dlls/user32/input.c:456 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetQueueStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetQueueStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetRawInputBuffer(RAWINPUT*  data, UINT*  data_size, UINT  header_size) /* ../dlls/user32/rawinput.c:341 */
{
	TRACE("Enter GetRawInputBuffer\n");
	return pGetRawInputBuffer(data, data_size, header_size);
}

extern WINAPI void wine32a_user32_GetRawInputBuffer(void);  /* ../dlls/user32/rawinput.c:341 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetRawInputBuffer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetRawInputBuffer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetRawInputData(HRAWINPUT  rawinput, UINT  command, void*  data, UINT*  data_size, UINT  header_size) /* ../dlls/user32/rawinput.c:298 */
{
	TRACE("Enter GetRawInputData\n");
	return pGetRawInputData(rawinput, command, data, data_size, header_size);
}

extern WINAPI void wine32a_user32_GetRawInputData(void);  /* ../dlls/user32/rawinput.c:298 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetRawInputData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetRawInputData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetRawInputDeviceInfoA(HANDLE  device, UINT  command, void*  data, UINT*  data_size) /* ../dlls/user32/rawinput.c:351 */
{
	TRACE("Enter GetRawInputDeviceInfoA\n");
	return pGetRawInputDeviceInfoA(device, command, data, data_size);
}

extern WINAPI void wine32a_user32_GetRawInputDeviceInfoA(void);  /* ../dlls/user32/rawinput.c:351 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetRawInputDeviceInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetRawInputDeviceInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetRawInputDeviceInfoW(HANDLE  device, UINT  command, void*  data, UINT*  data_size) /* ../dlls/user32/rawinput.c:389 */
{
	TRACE("Enter GetRawInputDeviceInfoW\n");
	return pGetRawInputDeviceInfoW(device, command, data, data_size);
}

extern WINAPI void wine32a_user32_GetRawInputDeviceInfoW(void);  /* ../dlls/user32/rawinput.c:389 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetRawInputDeviceInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetRawInputDeviceInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetRawInputDeviceList(RAWINPUTDEVICELIST*  devices, UINT*  device_count, UINT  size) /* ../dlls/user32/rawinput.c:203 */
{
	TRACE("Enter GetRawInputDeviceList\n");
	return pGetRawInputDeviceList(devices, device_count, size);
}

extern WINAPI void wine32a_user32_GetRawInputDeviceList(void);  /* ../dlls/user32/rawinput.c:203 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetRawInputDeviceList,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetRawInputDeviceList") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetRegisteredRawInputDevices(RAWINPUTDEVICE*  devices, UINT*  device_count, UINT  size) /* ../dlls/user32/rawinput.c:475 */
{
	TRACE("Enter GetRegisteredRawInputDevices\n");
	return pGetRegisteredRawInputDevices(devices, device_count, size);
}

extern WINAPI void wine32a_user32_GetRegisteredRawInputDevices(void);  /* ../dlls/user32/rawinput.c:475 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetRegisteredRawInputDevices,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetRegisteredRawInputDevices") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetScrollBarInfo(HWND  hwnd, LONG  idObject, LPSCROLLBARINFO  info) /* ../dlls/user32/scroll.c:1824 */
{
	TRACE("Enter GetScrollBarInfo\n");
	return pGetScrollBarInfo(hwnd, idObject, info);
}

extern WINAPI void wine32a_user32_GetScrollBarInfo(void);  /* ../dlls/user32/scroll.c:1824 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetScrollBarInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetScrollBarInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetScrollInfo(HWND  hwnd, INT  nBar, LPSCROLLINFO  info) /* ../dlls/user32/scroll.c:1796 */
{
	TRACE("Enter GetScrollInfo\n");
	return pGetScrollInfo(hwnd, nBar, info);
}

extern WINAPI void wine32a_user32_GetScrollInfo(void);  /* ../dlls/user32/scroll.c:1796 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetScrollInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetScrollInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetScrollPos(HWND  hwnd, INT  nBar) /* ../dlls/user32/scroll.c:1887 */
{
	TRACE("Enter GetScrollPos\n");
	return pGetScrollPos(hwnd, nBar);
}

extern WINAPI void wine32a_user32_GetScrollPos(void);  /* ../dlls/user32/scroll.c:1887 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetScrollPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetScrollPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetScrollRange(HWND  hwnd, INT  nBar, LPINT  lpMin, LPINT  lpMax) /* ../dlls/user32/scroll.c:1946 */
{
	TRACE("Enter GetScrollRange\n");
	return pGetScrollRange(hwnd, nBar, lpMin, lpMax);
}

extern WINAPI void wine32a_user32_GetScrollRange(void);  /* ../dlls/user32/scroll.c:1946 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetScrollRange,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetScrollRange") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetShellWindow(void) /* ../dlls/user32/focus.c:435 */
{
	TRACE("Enter GetShellWindow\n");
	return pGetShellWindow();
}

extern WINAPI void wine32a_user32_GetShellWindow(void);  /* ../dlls/user32/focus.c:435 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetShellWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetShellWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_user32_GetSubMenu(HMENU  hMenu, INT  nPos) /* ../dlls/user32/menu.c:4509 */
{
	TRACE("Enter GetSubMenu\n");
	return pGetSubMenu(hMenu, nPos);
}

extern WINAPI void wine32a_user32_GetSubMenu(void);  /* ../dlls/user32/menu.c:4509 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetSubMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetSubMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI COLORREF wine32b_user32_GetSysColor(INT  nIndex) /* ../dlls/user32/sysparams.c:3037 */
{
	TRACE("Enter GetSysColor\n");
	return pGetSysColor(nIndex);
}

extern WINAPI void wine32a_user32_GetSysColor(void);  /* ../dlls/user32/sysparams.c:3037 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetSysColor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetSysColor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HBRUSH wine32b_user32_GetSysColorBrush(INT  index) /* ../dlls/user32/sysparams.c:3084 */
{
	TRACE("Enter GetSysColorBrush\n");
	return pGetSysColorBrush(index);
}

extern WINAPI void wine32a_user32_GetSysColorBrush(void);  /* ../dlls/user32/sysparams.c:3084 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetSysColorBrush,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetSysColorBrush") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_user32_GetSystemMenu(HWND  hWnd, BOOL  bRevert) /* ../dlls/user32/menu.c:4303 */
{
	TRACE("Enter GetSystemMenu\n");
	return pGetSystemMenu(hWnd, bRevert);
}

extern WINAPI void wine32a_user32_GetSystemMenu(void);  /* ../dlls/user32/menu.c:4303 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetSystemMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetSystemMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetSystemMetrics(INT  index) /* ../dlls/user32/sysparams.c:2647 */
{
	TRACE("Enter GetSystemMetrics\n");
	return pGetSystemMetrics(index);
}

extern WINAPI void wine32a_user32_GetSystemMetrics(void);  /* ../dlls/user32/sysparams.c:2647 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetSystemMetrics,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetSystemMetrics") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetSystemMetricsForDpi(INT  index, UINT  dpi) /* ../dlls/user32/sysparams.c:2899 */
{
	TRACE("Enter GetSystemMetricsForDpi\n");
	return pGetSystemMetricsForDpi(index, dpi);
}

extern WINAPI void wine32a_user32_GetSystemMetricsForDpi(void);  /* ../dlls/user32/sysparams.c:2899 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetSystemMetricsForDpi,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetSystemMetricsForDpi") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetTabbedTextExtentA(HDC  hdc, LPCSTR  lpstr, INT  count, INT  cTabStops, INT*  lpTabPos) /* ../dlls/user32/text.c:1465 */
{
	TRACE("Enter GetTabbedTextExtentA\n");
	return pGetTabbedTextExtentA(hdc, lpstr, count, cTabStops, lpTabPos);
}

extern WINAPI void wine32a_user32_GetTabbedTextExtentA(void);  /* ../dlls/user32/text.c:1465 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetTabbedTextExtentA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetTabbedTextExtentA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetTabbedTextExtentW(HDC  hdc, LPCWSTR  lpstr, INT  count, INT  cTabStops, INT*  lpTabPos) /* ../dlls/user32/text.c:1482 */
{
	TRACE("Enter GetTabbedTextExtentW\n");
	return pGetTabbedTextExtentW(hdc, lpstr, count, cTabStops, lpTabPos);
}

extern WINAPI void wine32a_user32_GetTabbedTextExtentW(void);  /* ../dlls/user32/text.c:1482 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetTabbedTextExtentW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetTabbedTextExtentW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetTaskmanWindow(void) /* ../dlls/user32/focus.c:506 */
{
	TRACE("Enter GetTaskmanWindow\n");
	return pGetTaskmanWindow();
}

extern WINAPI void wine32a_user32_GetTaskmanWindow(void);  /* ../dlls/user32/focus.c:506 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetTaskmanWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetTaskmanWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDESK wine32b_user32_GetThreadDesktop(DWORD  thread) /* ../dlls/user32/winstation.c:399 */
{
	TRACE("Enter GetThreadDesktop\n");
	return pGetThreadDesktop(thread);
}

extern WINAPI void wine32a_user32_GetThreadDesktop(void);  /* ../dlls/user32/winstation.c:399 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetThreadDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetThreadDesktop") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DPI_AWARENESS_CONTEXT wine32b_user32_GetThreadDpiAwarenessContext(void) /* ../dlls/user32/sysparams.c:3557 */
{
	TRACE("Enter GetThreadDpiAwarenessContext\n");
	return pGetThreadDpiAwarenessContext();
}

extern WINAPI void wine32a_user32_GetThreadDpiAwarenessContext(void);  /* ../dlls/user32/sysparams.c:3557 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetThreadDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetThreadDpiAwarenessContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetTitleBarInfo(HWND  hwnd, PTITLEBARINFO  tbi) /* ../dlls/user32/nonclient.c:1608 */
{
	TRACE("Enter GetTitleBarInfo\n");
	return pGetTitleBarInfo(hwnd, tbi);
}

extern WINAPI void wine32a_user32_GetTitleBarInfo(void);  /* ../dlls/user32/nonclient.c:1608 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetTitleBarInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetTitleBarInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetTopWindow(HWND  hwnd) /* ../dlls/user32/win.c:3346 */
{
	TRACE("Enter GetTopWindow\n");
	return pGetTopWindow(hwnd);
}

extern WINAPI void wine32a_user32_GetTopWindow(void);  /* ../dlls/user32/win.c:3346 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetTopWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetTopWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetTouchInputInfo(HTOUCHINPUT  handle, UINT  count, TOUCHINPUT*  ptr, int  size) /* ../dlls/user32/win.c:4183 */
{
	TRACE("Enter GetTouchInputInfo\n");
	return pGetTouchInputInfo(handle, count, ptr, size);
}

extern WINAPI void wine32a_user32_GetTouchInputInfo(void);  /* ../dlls/user32/win.c:4183 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetTouchInputInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetTouchInputInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetUpdateRect(HWND  hwnd, LPRECT  rect, BOOL  erase) /* ../dlls/user32/painting.c:1403 */
{
	TRACE("Enter GetUpdateRect\n");
	return pGetUpdateRect(hwnd, rect, erase);
}

extern WINAPI void wine32a_user32_GetUpdateRect(void);  /* ../dlls/user32/painting.c:1403 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetUpdateRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetUpdateRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetUpdateRgn(HWND  hwnd, HRGN  hrgn, BOOL  erase) /* ../dlls/user32/painting.c:1373 */
{
	TRACE("Enter GetUpdateRgn\n");
	return pGetUpdateRgn(hwnd, hrgn, erase);
}

extern WINAPI void wine32a_user32_GetUpdateRgn(void);  /* ../dlls/user32/painting.c:1373 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetUpdateRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetUpdateRgn") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetUpdatedClipboardFormats(UINT*  formats, UINT  size, UINT*  out_size) /* ../dlls/user32/clipboard.c:1001 */
{
	TRACE("Enter GetUpdatedClipboardFormats\n");
	return pGetUpdatedClipboardFormats(formats, size, out_size);
}

extern WINAPI void wine32a_user32_GetUpdatedClipboardFormats(void);  /* ../dlls/user32/clipboard.c:1001 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetUpdatedClipboardFormats,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetUpdatedClipboardFormats") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetUserObjectInformationA(HANDLE  handle, INT  index, LPVOID  info, DWORD  len, LPDWORD  needed) /* ../dlls/user32/winstation.c:516 */
{
	TRACE("Enter GetUserObjectInformationA\n");
	return pGetUserObjectInformationA(handle, index, info, len, needed);
}

extern WINAPI void wine32a_user32_GetUserObjectInformationA(void);  /* ../dlls/user32/winstation.c:516 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetUserObjectInformationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetUserObjectInformationA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetUserObjectInformationW(HANDLE  handle, INT  index, LPVOID  info, DWORD  len, LPDWORD  needed) /* ../dlls/user32/winstation.c:546 */
{
	TRACE("Enter GetUserObjectInformationW\n");
	return pGetUserObjectInformationW(handle, index, info, len, needed);
}

extern WINAPI void wine32a_user32_GetUserObjectInformationW(void);  /* ../dlls/user32/winstation.c:546 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetUserObjectInformationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetUserObjectInformationW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetUserObjectSecurity(HANDLE  handle, PSECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  sid, DWORD  len, LPDWORD  needed) /* ../dlls/user32/winstation.c:674 */
{
	TRACE("Enter GetUserObjectSecurity\n");
	return pGetUserObjectSecurity(handle, info, sid, len, needed);
}

extern WINAPI void wine32a_user32_GetUserObjectSecurity(void);  /* ../dlls/user32/winstation.c:674 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetUserObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetUserObjectSecurity") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_GetWindow(HWND  hwnd, UINT  rel) /* ../dlls/user32/win.c:3356 */
{
	TRACE("Enter GetWindow\n");
	return pGetWindow(hwnd, rel);
}

extern WINAPI void wine32a_user32_GetWindow(void);  /* ../dlls/user32/win.c:3356 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetWindowContextHelpId(HWND  hwnd) /* ../dlls/user32/win.c:3723 */
{
	TRACE("Enter GetWindowContextHelpId\n");
	return pGetWindowContextHelpId(hwnd);
}

extern WINAPI void wine32a_user32_GetWindowContextHelpId(void);  /* ../dlls/user32/win.c:3723 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowContextHelpId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowContextHelpId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDC wine32b_user32_GetWindowDC(HWND  hwnd) /* ../dlls/user32/painting.c:1145 */
{
	TRACE("Enter GetWindowDC\n");
	return pGetWindowDC(hwnd);
}

extern WINAPI void wine32a_user32_GetWindowDC(void);  /* ../dlls/user32/painting.c:1145 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowDC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowDC") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetWindowDisplayAffinity(HWND  hwnd, DWORD*  affinity) /* ../dlls/user32/win.c:4203 */
{
	TRACE("Enter GetWindowDisplayAffinity\n");
	return pGetWindowDisplayAffinity(hwnd, affinity);
}

extern WINAPI void wine32a_user32_GetWindowDisplayAffinity(void);  /* ../dlls/user32/win.c:4203 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowDisplayAffinity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowDisplayAffinity") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DPI_AWARENESS_CONTEXT wine32b_user32_GetWindowDpiAwarenessContext(HWND  hwnd) /* ../dlls/user32/win.c:2238 */
{
	TRACE("Enter GetWindowDpiAwarenessContext\n");
	return pGetWindowDpiAwarenessContext(hwnd);
}

extern WINAPI void wine32a_user32_GetWindowDpiAwarenessContext(void);  /* ../dlls/user32/win.c:2238 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowDpiAwarenessContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetWindowInfo(HWND  hwnd, PWINDOWINFO  pwi) /* ../dlls/user32/win.c:3846 */
{
	TRACE("Enter GetWindowInfo\n");
	return pGetWindowInfo(hwnd, pwi);
}

extern WINAPI void wine32a_user32_GetWindowInfo(void);  /* ../dlls/user32/win.c:3846 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_GetWindowLongA(HWND  hwnd, INT  offset) /* ../dlls/user32/win.c:2692 */
{
	TRACE("Enter GetWindowLongA\n");
	return pGetWindowLongA(hwnd, offset);
}

extern WINAPI void wine32a_user32_GetWindowLongA(void);  /* ../dlls/user32/win.c:2692 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowLongA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowLongA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG_PTR wine32b_user32_GetWindowLongPtrA(HWND  hwnd, INT  offset) /* ../dlls/user32/win.c:4129 */
{
	TRACE("Enter GetWindowLongPtrA\n");
	return pGetWindowLongPtrA(hwnd, offset);
}

extern WINAPI void wine32a_user32_GetWindowLongPtrA(void);  /* ../dlls/user32/win.c:4129 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowLongPtrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowLongPtrA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG_PTR wine32b_user32_GetWindowLongPtrW(HWND  hwnd, INT  offset) /* ../dlls/user32/win.c:4121 */
{
	TRACE("Enter GetWindowLongPtrW\n");
	return pGetWindowLongPtrW(hwnd, offset);
}

extern WINAPI void wine32a_user32_GetWindowLongPtrW(void);  /* ../dlls/user32/win.c:4121 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowLongPtrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowLongPtrW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_GetWindowLongW(HWND  hwnd, INT  offset) /* ../dlls/user32/win.c:2713 */
{
	TRACE("Enter GetWindowLongW\n");
	return pGetWindowLongW(hwnd, offset);
}

extern WINAPI void wine32a_user32_GetWindowLongW(void);  /* ../dlls/user32/win.c:2713 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowLongW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowLongW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetWindowModuleFileNameA(HWND  hwnd, LPSTR  module, UINT  size) /* ../dlls/user32/win.c:3800 */
{
	TRACE("Enter GetWindowModuleFileNameA\n");
	return pGetWindowModuleFileNameA(hwnd, module, size);
}

extern WINAPI void wine32a_user32_GetWindowModuleFileNameA(void);  /* ../dlls/user32/win.c:3800 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowModuleFileNameA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowModuleFileNameA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_GetWindowModuleFileNameW(HWND  hwnd, LPWSTR  module, UINT  size) /* ../dlls/user32/win.c:3822 */
{
	TRACE("Enter GetWindowModuleFileNameW\n");
	return pGetWindowModuleFileNameW(hwnd, module, size);
}

extern WINAPI void wine32a_user32_GetWindowModuleFileNameW(void);  /* ../dlls/user32/win.c:3822 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowModuleFileNameW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowModuleFileNameW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetWindowPlacement(HWND  hwnd, WINDOWPLACEMENT*  wndpl) /* ../dlls/user32/winpos.c:1263 */
{
	TRACE("Enter GetWindowPlacement\n");
	return pGetWindowPlacement(hwnd, wndpl);
}

extern WINAPI void wine32a_user32_GetWindowPlacement(void);  /* ../dlls/user32/winpos.c:1263 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowPlacement,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowPlacement") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GetWindowRect(HWND  hwnd, LPRECT  rect) /* ../dlls/user32/winpos.c:97 */
{
	TRACE("Enter GetWindowRect\n");
	return pGetWindowRect(hwnd, rect);
}

extern WINAPI void wine32a_user32_GetWindowRect(void);  /* ../dlls/user32/winpos.c:97 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetWindowRgn(HWND  hwnd, HRGN  hrgn) /* ../dlls/user32/winpos.c:108 */
{
	TRACE("Enter GetWindowRgn\n");
	return pGetWindowRgn(hwnd, hrgn);
}

extern WINAPI void wine32a_user32_GetWindowRgn(void);  /* ../dlls/user32/winpos.c:108 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowRgn") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetWindowRgnBox(HWND  hwnd, LPRECT  prect) /* ../dlls/user32/winpos.c:157 */
{
	TRACE("Enter GetWindowRgnBox\n");
	return pGetWindowRgnBox(hwnd, prect);
}

extern WINAPI void wine32a_user32_GetWindowRgnBox(void);  /* ../dlls/user32/winpos.c:157 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowRgnBox,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowRgnBox") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetWindowTextA(HWND  hwnd, LPSTR  lpString, INT  nMaxCount) /* ../dlls/user32/win.c:2869 */
{
	TRACE("Enter GetWindowTextA\n");
	return pGetWindowTextA(hwnd, lpString, nMaxCount);
}

extern WINAPI void wine32a_user32_GetWindowTextA(void);  /* ../dlls/user32/win.c:2869 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowTextA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetWindowTextLengthA(HWND  hwnd) /* ../dlls/user32/win.c:2972 */
{
	TRACE("Enter GetWindowTextLengthA\n");
	return pGetWindowTextLengthA(hwnd);
}

extern WINAPI void wine32a_user32_GetWindowTextLengthA(void);  /* ../dlls/user32/win.c:2972 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowTextLengthA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowTextLengthA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetWindowTextLengthW(HWND  hwnd) /* ../dlls/user32/win.c:2986 */
{
	TRACE("Enter GetWindowTextLengthW\n");
	return pGetWindowTextLengthW(hwnd);
}

extern WINAPI void wine32a_user32_GetWindowTextLengthW(void);  /* ../dlls/user32/win.c:2986 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowTextLengthW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowTextLengthW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_GetWindowTextW(HWND  hwnd, LPWSTR  lpString, INT  nMaxCount) /* ../dlls/user32/win.c:2918 */
{
	TRACE("Enter GetWindowTextW\n");
	return pGetWindowTextW(hwnd, lpString, nMaxCount);
}

extern WINAPI void wine32a_user32_GetWindowTextW(void);  /* ../dlls/user32/win.c:2918 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowTextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_GetWindowThreadProcessId(HWND  hwnd, LPDWORD  process) /* ../dlls/user32/win.c:3026 */
{
	TRACE("Enter GetWindowThreadProcessId\n");
	return pGetWindowThreadProcessId(hwnd, process);
}

extern WINAPI void wine32a_user32_GetWindowThreadProcessId(void);  /* ../dlls/user32/win.c:3026 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowThreadProcessId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowThreadProcessId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_GetWindowWord(HWND  hwnd, INT  offset) /* ../dlls/user32/win.c:2668 */
{
	TRACE("Enter GetWindowWord\n");
	return pGetWindowWord(hwnd, offset);
}

extern WINAPI void wine32a_user32_GetWindowWord(void);  /* ../dlls/user32/win.c:2668 */
__ASM_GLOBAL_FUNC(wine32a_user32_GetWindowWord,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GetWindowWord") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GrayStringA(HDC  hdc, HBRUSH  hbr, GRAYSTRINGPROC  gsprc, LPARAM  lParam, INT  cch, INT  x, INT  y, INT  cx, INT  cy) /* ../dlls/user32/text.c:1265 */
{
	TRACE("Enter GrayStringA\n");
	return pGrayStringA(hdc, hbr, gsprc, lParam, cch, x, y, cx, cy);
}

extern WINAPI void wine32a_user32_GrayStringA(void);  /* ../dlls/user32/text.c:1265 */
__ASM_GLOBAL_FUNC(wine32a_user32_GrayStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GrayStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $36, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_GrayStringW(HDC  hdc, HBRUSH  hbr, GRAYSTRINGPROC  gsprc, LPARAM  lParam, INT  cch, INT  x, INT  y, INT  cx, INT  cy) /* ../dlls/user32/text.c:1285 */
{
	TRACE("Enter GrayStringW\n");
	return pGrayStringW(hdc, hbr, gsprc, lParam, cch, x, y, cx, cy);
}

extern WINAPI void wine32a_user32_GrayStringW(void);  /* ../dlls/user32/text.c:1285 */
__ASM_GLOBAL_FUNC(wine32a_user32_GrayStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_GrayStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $36, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_HideCaret(HWND  hwnd) /* ../dlls/user32/caret.c:289 */
{
	TRACE("Enter HideCaret\n");
	return pHideCaret(hwnd);
}

extern WINAPI void wine32a_user32_HideCaret(void);  /* ../dlls/user32/caret.c:289 */
__ASM_GLOBAL_FUNC(wine32a_user32_HideCaret,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_HideCaret") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_HiliteMenuItem(HWND  hWnd, HMENU  hMenu, UINT  wItemID, UINT  wHilite) /* ../dlls/user32/menu.c:3857 */
{
	TRACE("Enter HiliteMenuItem\n");
	return pHiliteMenuItem(hWnd, hMenu, wItemID, wHilite);
}

extern WINAPI void wine32a_user32_HiliteMenuItem(void);  /* ../dlls/user32/menu.c:3857 */
__ASM_GLOBAL_FUNC(wine32a_user32_HiliteMenuItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_HiliteMenuItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ImpersonateDdeClientWindow(HWND  hWndClient, HWND  hWndServer) /* ../dlls/user32/dde_misc.c:234 */
{
	TRACE("Enter ImpersonateDdeClientWindow\n");
	return pImpersonateDdeClientWindow(hWndClient, hWndServer);
}

extern WINAPI void wine32a_user32_ImpersonateDdeClientWindow(void);  /* ../dlls/user32/dde_misc.c:234 */
__ASM_GLOBAL_FUNC(wine32a_user32_ImpersonateDdeClientWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ImpersonateDdeClientWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_InSendMessage(void) /* ../dlls/user32/message.c:3636 */
{
	TRACE("Enter InSendMessage\n");
	return pInSendMessage();
}

extern WINAPI void wine32a_user32_InSendMessage(void);  /* ../dlls/user32/message.c:3636 */
__ASM_GLOBAL_FUNC(wine32a_user32_InSendMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InSendMessage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_InSendMessageEx(LPVOID  reserved) /* ../dlls/user32/message.c:3645 */
{
	TRACE("Enter InSendMessageEx\n");
	return pInSendMessageEx(reserved);
}

extern WINAPI void wine32a_user32_InSendMessageEx(void);  /* ../dlls/user32/message.c:3645 */
__ASM_GLOBAL_FUNC(wine32a_user32_InSendMessageEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InSendMessageEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_InflateRect(LPRECT  rect, INT  x, INT  y) /* ../dlls/user32/uitools.c:1321 */
{
	TRACE("Enter InflateRect\n");
	return pInflateRect(rect, x, y);
}

extern WINAPI void wine32a_user32_InflateRect(void);  /* ../dlls/user32/uitools.c:1321 */
__ASM_GLOBAL_FUNC(wine32a_user32_InflateRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InflateRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_InsertMenuA(HMENU  hMenu, UINT  pos, UINT  flags, UINT_PTR  id, LPCSTR  str) /* ../dlls/user32/menu.c:4035 */
{
	TRACE("Enter InsertMenuA\n");
	return pInsertMenuA(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_user32_InsertMenuA(void);  /* ../dlls/user32/menu.c:4035 */
__ASM_GLOBAL_FUNC(wine32a_user32_InsertMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InsertMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_InsertMenuItemA(HMENU  hMenu, UINT  uItem, BOOL  bypos, MENUITEMINFOA*  lpmii) /* ../dlls/user32/menu.c:5208 */
{
	TRACE("Enter InsertMenuItemA\n");
	return pInsertMenuItemA(hMenu, uItem, bypos, lpmii);
}

extern WINAPI void wine32a_user32_InsertMenuItemA(void);  /* ../dlls/user32/menu.c:5208 */
__ASM_GLOBAL_FUNC(wine32a_user32_InsertMenuItemA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InsertMenuItemA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_InsertMenuItemW(HMENU  hMenu, UINT  uItem, BOOL  bypos, MENUITEMINFOW*  lpmii) /* ../dlls/user32/menu.c:5232 */
{
	TRACE("Enter InsertMenuItemW\n");
	return pInsertMenuItemW(hMenu, uItem, bypos, lpmii);
}

extern WINAPI void wine32a_user32_InsertMenuItemW(void);  /* ../dlls/user32/menu.c:5232 */
__ASM_GLOBAL_FUNC(wine32a_user32_InsertMenuItemW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InsertMenuItemW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_InsertMenuW(HMENU  hMenu, UINT  pos, UINT  flags, UINT_PTR  id, LPCWSTR  str) /* ../dlls/user32/menu.c:4000 */
{
	TRACE("Enter InsertMenuW\n");
	return pInsertMenuW(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_user32_InsertMenuW(void);  /* ../dlls/user32/menu.c:4000 */
__ASM_GLOBAL_FUNC(wine32a_user32_InsertMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InsertMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_InternalGetWindowText(HWND  hwnd, LPWSTR  lpString, INT  nMaxCount) /* ../dlls/user32/win.c:2894 */
{
	TRACE("Enter InternalGetWindowText\n");
	return pInternalGetWindowText(hwnd, lpString, nMaxCount);
}

extern WINAPI void wine32a_user32_InternalGetWindowText(void);  /* ../dlls/user32/win.c:2894 */
__ASM_GLOBAL_FUNC(wine32a_user32_InternalGetWindowText,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InternalGetWindowText") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IntersectRect(LPRECT  dest, RECT*  src1, RECT*  src2) /* ../dlls/user32/uitools.c:1335 */
{
	TRACE("Enter IntersectRect\n");
	return pIntersectRect(dest, src1, src2);
}

extern WINAPI void wine32a_user32_IntersectRect(void);  /* ../dlls/user32/uitools.c:1335 */
__ASM_GLOBAL_FUNC(wine32a_user32_IntersectRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IntersectRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_InvalidateRect(HWND  hwnd, RECT*  rect, BOOL  erase) /* ../dlls/user32/painting.c:1321 */
{
	TRACE("Enter InvalidateRect\n");
	return pInvalidateRect(hwnd, rect, erase);
}

extern WINAPI void wine32a_user32_InvalidateRect(void);  /* ../dlls/user32/painting.c:1321 */
__ASM_GLOBAL_FUNC(wine32a_user32_InvalidateRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InvalidateRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_InvalidateRgn(HWND  hwnd, HRGN  hrgn, BOOL  erase) /* ../dlls/user32/painting.c:1303 */
{
	TRACE("Enter InvalidateRgn\n");
	return pInvalidateRgn(hwnd, hrgn, erase);
}

extern WINAPI void wine32a_user32_InvalidateRgn(void);  /* ../dlls/user32/painting.c:1303 */
__ASM_GLOBAL_FUNC(wine32a_user32_InvalidateRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InvalidateRgn") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_InvertRect(HDC  hdc, RECT*  rect) /* ../dlls/user32/uitools.c:1454 */
{
	TRACE("Enter InvertRect\n");
	return pInvertRect(hdc, rect);
}

extern WINAPI void wine32a_user32_InvertRect(void);  /* ../dlls/user32/uitools.c:1454 */
__ASM_GLOBAL_FUNC(wine32a_user32_InvertRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_InvertRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsCharAlphaA(CHAR  x) /* ../dlls/user32/lstr.c:466 */
{
	TRACE("Enter IsCharAlphaA\n");
	return pIsCharAlphaA(x);
}

extern WINAPI void wine32a_user32_IsCharAlphaA(void);  /* ../dlls/user32/lstr.c:466 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsCharAlphaA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsCharAlphaA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsCharAlphaNumericA(CHAR  x) /* ../dlls/user32/lstr.c:444 */
{
	TRACE("Enter IsCharAlphaNumericA\n");
	return pIsCharAlphaNumericA(x);
}

extern WINAPI void wine32a_user32_IsCharAlphaNumericA(void);  /* ../dlls/user32/lstr.c:444 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsCharAlphaNumericA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsCharAlphaNumericA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsCharAlphaNumericW(WCHAR  ch) /* ../dlls/user32/lstr.c:455 */
{
	TRACE("Enter IsCharAlphaNumericW\n");
	return pIsCharAlphaNumericW(ch);
}

extern WINAPI void wine32a_user32_IsCharAlphaNumericW(void);  /* ../dlls/user32/lstr.c:455 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsCharAlphaNumericW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsCharAlphaNumericW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsCharAlphaW(WCHAR  ch) /* ../dlls/user32/lstr.c:477 */
{
	TRACE("Enter IsCharAlphaW\n");
	return pIsCharAlphaW(ch);
}

extern WINAPI void wine32a_user32_IsCharAlphaW(void);  /* ../dlls/user32/lstr.c:477 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsCharAlphaW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsCharAlphaW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsCharLowerA(CHAR  x) /* ../dlls/user32/lstr.c:400 */
{
	TRACE("Enter IsCharLowerA\n");
	return pIsCharLowerA(x);
}

extern WINAPI void wine32a_user32_IsCharLowerA(void);  /* ../dlls/user32/lstr.c:400 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsCharLowerA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsCharLowerA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsCharLowerW(WCHAR  ch) /* ../dlls/user32/lstr.c:411 */
{
	TRACE("Enter IsCharLowerW\n");
	return pIsCharLowerW(ch);
}

extern WINAPI void wine32a_user32_IsCharLowerW(void);  /* ../dlls/user32/lstr.c:411 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsCharLowerW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsCharLowerW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsCharUpperA(CHAR  x) /* ../dlls/user32/lstr.c:422 */
{
	TRACE("Enter IsCharUpperA\n");
	return pIsCharUpperA(x);
}

extern WINAPI void wine32a_user32_IsCharUpperA(void);  /* ../dlls/user32/lstr.c:422 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsCharUpperA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsCharUpperA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsCharUpperW(WCHAR  ch) /* ../dlls/user32/lstr.c:433 */
{
	TRACE("Enter IsCharUpperW\n");
	return pIsCharUpperW(ch);
}

extern WINAPI void wine32a_user32_IsCharUpperW(void);  /* ../dlls/user32/lstr.c:433 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsCharUpperW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsCharUpperW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsChild(HWND  parent, HWND  child) /* ../dlls/user32/win.c:3268 */
{
	TRACE("Enter IsChild\n");
	return pIsChild(parent, child);
}

extern WINAPI void wine32a_user32_IsChild(void);  /* ../dlls/user32/win.c:3268 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsChild,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsChild") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsClipboardFormatAvailable(UINT  format) /* ../dlls/user32/clipboard.c:979 */
{
	TRACE("Enter IsClipboardFormatAvailable\n");
	return pIsClipboardFormatAvailable(format);
}

extern WINAPI void wine32a_user32_IsClipboardFormatAvailable(void);  /* ../dlls/user32/clipboard.c:979 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsClipboardFormatAvailable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsClipboardFormatAvailable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsDialogMessageA(HWND  hwndDlg, LPMSG  pmsg) /* ../dlls/user32/message.c:3879 */
{
	TRACE("Enter IsDialogMessageA\n");
	return pIsDialogMessageA(hwndDlg, pmsg);
}

extern WINAPI void wine32a_user32_IsDialogMessageA(void);  /* ../dlls/user32/message.c:3879 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsDialogMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsDialogMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsDialogMessageW(HWND  hwndDlg, LPMSG  msg) /* ../dlls/user32/dialog.c:1159 */
{
	TRACE("Enter IsDialogMessageW\n");
	return pIsDialogMessageW(hwndDlg, msg);
}

extern WINAPI void wine32a_user32_IsDialogMessageW(void);  /* ../dlls/user32/dialog.c:1159 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsDialogMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsDialogMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_IsDlgButtonChecked(HWND  hwnd, int  id) /* ../dlls/user32/dialog.c:1465 */
{
	TRACE("Enter IsDlgButtonChecked\n");
	return pIsDlgButtonChecked(hwnd, id);
}

extern WINAPI void wine32a_user32_IsDlgButtonChecked(void);  /* ../dlls/user32/dialog.c:1465 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsDlgButtonChecked,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsDlgButtonChecked") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsGUIThread(BOOL  convert) /* ../dlls/user32/message.c:4594 */
{
	TRACE("Enter IsGUIThread\n");
	return pIsGUIThread(convert);
}

extern WINAPI void wine32a_user32_IsGUIThread(void);  /* ../dlls/user32/message.c:4594 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsGUIThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsGUIThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsHungAppWindow(HWND  hWnd) /* ../dlls/user32/message.c:4644 */
{
	TRACE("Enter IsHungAppWindow\n");
	return pIsHungAppWindow(hWnd);
}

extern WINAPI void wine32a_user32_IsHungAppWindow(void);  /* ../dlls/user32/message.c:4644 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsHungAppWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsHungAppWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsIconic(HWND  hWnd) /* ../dlls/user32/winpos.c:622 */
{
	TRACE("Enter IsIconic\n");
	return pIsIconic(hWnd);
}

extern WINAPI void wine32a_user32_IsIconic(void);  /* ../dlls/user32/winpos.c:622 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsIconic,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsIconic") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsMenu(HMENU  hmenu) /* ../dlls/user32/menu.c:4714 */
{
	TRACE("Enter IsMenu\n");
	return pIsMenu(hmenu);
}

extern WINAPI void wine32a_user32_IsMenu(void);  /* ../dlls/user32/menu.c:4714 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsProcessDPIAware(void) /* ../dlls/user32/sysparams.c:3516 */
{
	TRACE("Enter IsProcessDPIAware\n");
	return pIsProcessDPIAware();
}

extern WINAPI void wine32a_user32_IsProcessDPIAware(void);  /* ../dlls/user32/sysparams.c:3516 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsProcessDPIAware,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsProcessDPIAware") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsRectEmpty(RECT*  rect) /* ../dlls/user32/uitools.c:1286 */
{
	TRACE("Enter IsRectEmpty\n");
	return pIsRectEmpty(rect);
}

extern WINAPI void wine32a_user32_IsRectEmpty(void);  /* ../dlls/user32/uitools.c:1286 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsRectEmpty,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsRectEmpty") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsTouchWindow(HWND  hwnd, PULONG  flags) /* ../dlls/user32/misc.c:533 */
{
	TRACE("Enter IsTouchWindow\n");
	return pIsTouchWindow(hwnd, flags);
}

extern WINAPI void wine32a_user32_IsTouchWindow(void);  /* ../dlls/user32/misc.c:533 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsTouchWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsTouchWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsValidDpiAwarenessContext(DPI_AWARENESS_CONTEXT  context) /* ../dlls/user32/sysparams.c:3498 */
{
	TRACE("Enter IsValidDpiAwarenessContext\n");
	return pIsValidDpiAwarenessContext(context);
}

extern WINAPI void wine32a_user32_IsValidDpiAwarenessContext(void);  /* ../dlls/user32/sysparams.c:3498 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsValidDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsValidDpiAwarenessContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsWinEventHookInstalled(DWORD  dwEvent) /* ../dlls/user32/hook.c:961 */
{
	TRACE("Enter IsWinEventHookInstalled\n");
	return pIsWinEventHookInstalled(dwEvent);
}

extern WINAPI void wine32a_user32_IsWinEventHookInstalled(void);  /* ../dlls/user32/hook.c:961 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsWinEventHookInstalled,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsWinEventHookInstalled") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsWindow(HWND  hwnd) /* ../dlls/user32/win.c:2998 */
{
	TRACE("Enter IsWindow\n");
	return pIsWindow(hwnd);
}

extern WINAPI void wine32a_user32_IsWindow(void);  /* ../dlls/user32/win.c:2998 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsWindowEnabled(HWND  hWnd) /* ../dlls/user32/win.c:2195 */
{
	TRACE("Enter IsWindowEnabled\n");
	return pIsWindowEnabled(hWnd);
}

extern WINAPI void wine32a_user32_IsWindowEnabled(void);  /* ../dlls/user32/win.c:2195 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsWindowEnabled,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsWindowEnabled") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsWindowRedirectedForPrint(HWND  hwnd) /* ../dlls/user32/misc.c:542 */
{
	TRACE("Enter IsWindowRedirectedForPrint\n");
	return pIsWindowRedirectedForPrint(hwnd);
}

extern WINAPI void wine32a_user32_IsWindowRedirectedForPrint(void);  /* ../dlls/user32/misc.c:542 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsWindowRedirectedForPrint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsWindowRedirectedForPrint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsWindowUnicode(HWND  hwnd) /* ../dlls/user32/win.c:2208 */
{
	TRACE("Enter IsWindowUnicode\n");
	return pIsWindowUnicode(hwnd);
}

extern WINAPI void wine32a_user32_IsWindowUnicode(void);  /* ../dlls/user32/win.c:2208 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsWindowUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsWindowUnicode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsWindowVisible(HWND  hwnd) /* ../dlls/user32/win.c:3294 */
{
	TRACE("Enter IsWindowVisible\n");
	return pIsWindowVisible(hwnd);
}

extern WINAPI void wine32a_user32_IsWindowVisible(void);  /* ../dlls/user32/win.c:3294 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsWindowVisible,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsWindowVisible") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_IsZoomed(HWND  hWnd) /* ../dlls/user32/winpos.c:631 */
{
	TRACE("Enter IsZoomed\n");
	return pIsZoomed(hWnd);
}

extern WINAPI void wine32a_user32_IsZoomed(void);  /* ../dlls/user32/winpos.c:631 */
__ASM_GLOBAL_FUNC(wine32a_user32_IsZoomed,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_IsZoomed") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_KillSystemTimer(HWND  hwnd, UINT_PTR  id) /* ../dlls/user32/message.c:4575 */
{
	TRACE("Enter KillSystemTimer\n");
	return pKillSystemTimer(hwnd, id);
}

extern WINAPI void wine32a_user32_KillSystemTimer(void);  /* ../dlls/user32/message.c:4575 */
__ASM_GLOBAL_FUNC(wine32a_user32_KillSystemTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_KillSystemTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_KillTimer(HWND  hwnd, UINT_PTR  id) /* ../dlls/user32/message.c:4556 */
{
	TRACE("Enter KillTimer\n");
	return pKillTimer(hwnd, id);
}

extern WINAPI void wine32a_user32_KillTimer(void);  /* ../dlls/user32/message.c:4556 */
__ASM_GLOBAL_FUNC(wine32a_user32_KillTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_KillTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HACCEL wine32b_user32_LoadAcceleratorsA(HINSTANCE  instance, LPCSTR  lpTableName) /* ../dlls/user32/resource.c:82 */
{
	TRACE("Enter LoadAcceleratorsA\n");
	return pLoadAcceleratorsA(instance, lpTableName);
}

extern WINAPI void wine32a_user32_LoadAcceleratorsA(void);  /* ../dlls/user32/resource.c:82 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadAcceleratorsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadAcceleratorsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HACCEL wine32b_user32_LoadAcceleratorsW(HINSTANCE  instance, LPCWSTR  name) /* ../dlls/user32/resource.c:57 */
{
	TRACE("Enter LoadAcceleratorsW\n");
	return pLoadAcceleratorsW(instance, name);
}

extern WINAPI void wine32a_user32_LoadAcceleratorsW(void);  /* ../dlls/user32/resource.c:57 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadAcceleratorsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadAcceleratorsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HBITMAP wine32b_user32_LoadBitmapA(HINSTANCE  instance, LPCSTR  name) /* ../dlls/user32/cursoricon.c:3312 */
{
	TRACE("Enter LoadBitmapA\n");
	return pLoadBitmapA(instance, name);
}

extern WINAPI void wine32a_user32_LoadBitmapA(void);  /* ../dlls/user32/cursoricon.c:3312 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadBitmapA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadBitmapA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HBITMAP wine32b_user32_LoadBitmapW(HINSTANCE  instance, LPCWSTR  name) /* ../dlls/user32/cursoricon.c:3300 */
{
	TRACE("Enter LoadBitmapW\n");
	return pLoadBitmapW(instance, name);
}

extern WINAPI void wine32a_user32_LoadBitmapW(void);  /* ../dlls/user32/cursoricon.c:3300 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadBitmapW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadBitmapW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCURSOR wine32b_user32_LoadCursorA(HINSTANCE  hInstance, LPCSTR  name) /* ../dlls/user32/cursoricon.c:2253 */
{
	TRACE("Enter LoadCursorA\n");
	return pLoadCursorA(hInstance, name);
}

extern WINAPI void wine32a_user32_LoadCursorA(void);  /* ../dlls/user32/cursoricon.c:2253 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadCursorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadCursorA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCURSOR wine32b_user32_LoadCursorFromFileA(LPCSTR  name) /* ../dlls/user32/cursoricon.c:2275 */
{
	TRACE("Enter LoadCursorFromFileA\n");
	return pLoadCursorFromFileA(name);
}

extern WINAPI void wine32a_user32_LoadCursorFromFileA(void);  /* ../dlls/user32/cursoricon.c:2275 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadCursorFromFileA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadCursorFromFileA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCURSOR wine32b_user32_LoadCursorFromFileW(LPCWSTR  name) /* ../dlls/user32/cursoricon.c:2264 */
{
	TRACE("Enter LoadCursorFromFileW\n");
	return pLoadCursorFromFileW(name);
}

extern WINAPI void wine32a_user32_LoadCursorFromFileW(void);  /* ../dlls/user32/cursoricon.c:2264 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadCursorFromFileW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadCursorFromFileW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCURSOR wine32b_user32_LoadCursorW(HINSTANCE  hInstance, LPCWSTR  name) /* ../dlls/user32/cursoricon.c:2242 */
{
	TRACE("Enter LoadCursorW\n");
	return pLoadCursorW(hInstance, name);
}

extern WINAPI void wine32a_user32_LoadCursorW(void);  /* ../dlls/user32/cursoricon.c:2242 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadCursorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadCursorW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HICON wine32b_user32_LoadIconA(HINSTANCE  hInstance, LPCSTR  name) /* ../dlls/user32/cursoricon.c:2297 */
{
	TRACE("Enter LoadIconA\n");
	return pLoadIconA(hInstance, name);
}

extern WINAPI void wine32a_user32_LoadIconA(void);  /* ../dlls/user32/cursoricon.c:2297 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadIconA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadIconA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HICON wine32b_user32_LoadIconW(HINSTANCE  hInstance, LPCWSTR  name) /* ../dlls/user32/cursoricon.c:2286 */
{
	TRACE("Enter LoadIconW\n");
	return pLoadIconW(hInstance, name);
}

extern WINAPI void wine32a_user32_LoadIconW(void);  /* ../dlls/user32/cursoricon.c:2286 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadIconW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadIconW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_user32_LoadImageA(HINSTANCE  hinst, LPCSTR  name, UINT  type, INT  desiredx, INT  desiredy, UINT  loadflags) /* ../dlls/user32/cursoricon.c:2998 */
{
	TRACE("Enter LoadImageA\n");
	return pLoadImageA(hinst, name, type, desiredx, desiredy, loadflags);
}

extern WINAPI void wine32a_user32_LoadImageA(void);  /* ../dlls/user32/cursoricon.c:2998 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadImageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadImageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_user32_LoadImageW(HINSTANCE  hinst, LPCWSTR  name, UINT  type, INT  desiredx, INT  desiredy, UINT  loadflags) /* ../dlls/user32/cursoricon.c:3040 */
{
	TRACE("Enter LoadImageW\n");
	return pLoadImageW(hinst, name, type, desiredx, desiredy, loadflags);
}

extern WINAPI void wine32a_user32_LoadImageW(void);  /* ../dlls/user32/cursoricon.c:3040 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadImageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadImageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HKL wine32b_user32_LoadKeyboardLayoutA(LPCSTR  pwszKLID, UINT  Flags) /* ../dlls/user32/input.c:1007 */
{
	TRACE("Enter LoadKeyboardLayoutA\n");
	return pLoadKeyboardLayoutA(pwszKLID, Flags);
}

extern WINAPI void wine32a_user32_LoadKeyboardLayoutA(void);  /* ../dlls/user32/input.c:1007 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadKeyboardLayoutA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadKeyboardLayoutA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HKL wine32b_user32_LoadKeyboardLayoutW(LPCWSTR  pwszKLID, UINT  Flags) /* ../dlls/user32/input.c:997 */
{
	TRACE("Enter LoadKeyboardLayoutW\n");
	return pLoadKeyboardLayoutW(pwszKLID, Flags);
}

extern WINAPI void wine32a_user32_LoadKeyboardLayoutW(void);  /* ../dlls/user32/input.c:997 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadKeyboardLayoutW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadKeyboardLayoutW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_LoadLocalFonts(void) /* ../dlls/user32/misc.c:379 */
{
	TRACE("Enter LoadLocalFonts\n");
	return pLoadLocalFonts();
}

extern WINAPI void wine32a_user32_LoadLocalFonts(void);  /* ../dlls/user32/misc.c:379 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadLocalFonts,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadLocalFonts") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_user32_LoadMenuA(HINSTANCE  instance, LPCSTR  name) /* ../dlls/user32/menu.c:4642 */
{
	TRACE("Enter LoadMenuA\n");
	return pLoadMenuA(instance, name);
}

extern WINAPI void wine32a_user32_LoadMenuA(void);  /* ../dlls/user32/menu.c:4642 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_user32_LoadMenuIndirectA(LPCVOID  template) /* ../dlls/user32/menu.c:4705 */
{
	TRACE("Enter LoadMenuIndirectA\n");
	return pLoadMenuIndirectA(template);
}

extern WINAPI void wine32a_user32_LoadMenuIndirectA(void);  /* ../dlls/user32/menu.c:4705 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadMenuIndirectA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadMenuIndirectA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_user32_LoadMenuIndirectW(LPCVOID  template) /* ../dlls/user32/menu.c:4664 */
{
	TRACE("Enter LoadMenuIndirectW\n");
	return pLoadMenuIndirectW(template);
}

extern WINAPI void wine32a_user32_LoadMenuIndirectW(void);  /* ../dlls/user32/menu.c:4664 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadMenuIndirectW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadMenuIndirectW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMENU wine32b_user32_LoadMenuW(HINSTANCE  instance, LPCWSTR  name) /* ../dlls/user32/menu.c:4653 */
{
	TRACE("Enter LoadMenuW\n");
	return pLoadMenuW(instance, name);
}

extern WINAPI void wine32a_user32_LoadMenuW(void);  /* ../dlls/user32/menu.c:4653 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_LoadStringA(HINSTANCE  instance, UINT  resource_id, LPSTR  buffer, INT  buflen) /* ../dlls/user32/resource.c:294 */
{
	TRACE("Enter LoadStringA\n");
	return pLoadStringA(instance, resource_id, buffer, buflen);
}

extern WINAPI void wine32a_user32_LoadStringA(void);  /* ../dlls/user32/resource.c:294 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadStringA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadStringA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_LoadStringW(HINSTANCE  instance, UINT  resource_id, LPWSTR  buffer, INT  buflen) /* ../dlls/user32/resource.c:239 */
{
	TRACE("Enter LoadStringW\n");
	return pLoadStringW(instance, resource_id, buffer, buflen);
}

extern WINAPI void wine32a_user32_LoadStringW(void);  /* ../dlls/user32/resource.c:239 */
__ASM_GLOBAL_FUNC(wine32a_user32_LoadStringW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LoadStringW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_LockSetForegroundWindow(UINT  lockcode) /* ../dlls/user32/winpos.c:651 */
{
	TRACE("Enter LockSetForegroundWindow\n");
	return pLockSetForegroundWindow(lockcode);
}

extern WINAPI void wine32a_user32_LockSetForegroundWindow(void);  /* ../dlls/user32/winpos.c:651 */
__ASM_GLOBAL_FUNC(wine32a_user32_LockSetForegroundWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LockSetForegroundWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_LockWindowUpdate(HWND  hwnd) /* ../dlls/user32/painting.c:1197 */
{
	TRACE("Enter LockWindowUpdate\n");
	return pLockWindowUpdate(hwnd);
}

extern WINAPI void wine32a_user32_LockWindowUpdate(void);  /* ../dlls/user32/painting.c:1197 */
__ASM_GLOBAL_FUNC(wine32a_user32_LockWindowUpdate,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LockWindowUpdate") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_LockWorkStation(void) /* ../dlls/user32/user_main.c:470 */
{
	TRACE("Enter LockWorkStation\n");
	return pLockWorkStation();
}

extern WINAPI void wine32a_user32_LockWorkStation(void);  /* ../dlls/user32/user_main.c:470 */
__ASM_GLOBAL_FUNC(wine32a_user32_LockWorkStation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LockWorkStation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_LogicalToPhysicalPoint(HWND  hwnd, POINT*  point) /* ../dlls/user32/sysparams.c:4308 */
{
	TRACE("Enter LogicalToPhysicalPoint\n");
	return pLogicalToPhysicalPoint(hwnd, point);
}

extern WINAPI void wine32a_user32_LogicalToPhysicalPoint(void);  /* ../dlls/user32/sysparams.c:4308 */
__ASM_GLOBAL_FUNC(wine32a_user32_LogicalToPhysicalPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LogicalToPhysicalPoint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_LogicalToPhysicalPointForPerMonitorDPI(HWND  hwnd, POINT*  pt) /* ../dlls/user32/sysparams.c:3593 */
{
	TRACE("Enter LogicalToPhysicalPointForPerMonitorDPI\n");
	return pLogicalToPhysicalPointForPerMonitorDPI(hwnd, pt);
}

extern WINAPI void wine32a_user32_LogicalToPhysicalPointForPerMonitorDPI(void);  /* ../dlls/user32/sysparams.c:3593 */
__ASM_GLOBAL_FUNC(wine32a_user32_LogicalToPhysicalPointForPerMonitorDPI,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LogicalToPhysicalPointForPerMonitorDPI") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_LookupIconIdFromDirectory(LPBYTE  dir, BOOL  bIcon) /* ../dlls/user32/cursoricon.c:2234 */
{
	TRACE("Enter LookupIconIdFromDirectory\n");
	return pLookupIconIdFromDirectory(dir, bIcon);
}

extern WINAPI void wine32a_user32_LookupIconIdFromDirectory(void);  /* ../dlls/user32/cursoricon.c:2234 */
__ASM_GLOBAL_FUNC(wine32a_user32_LookupIconIdFromDirectory,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LookupIconIdFromDirectory") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_LookupIconIdFromDirectoryEx(LPBYTE  xdir, BOOL  bIcon, INT  width, INT  height, UINT  cFlag) /* ../dlls/user32/cursoricon.c:2210 */
{
	TRACE("Enter LookupIconIdFromDirectoryEx\n");
	return pLookupIconIdFromDirectoryEx(xdir, bIcon, width, height, cFlag);
}

extern WINAPI void wine32a_user32_LookupIconIdFromDirectoryEx(void);  /* ../dlls/user32/cursoricon.c:2210 */
__ASM_GLOBAL_FUNC(wine32a_user32_LookupIconIdFromDirectoryEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_LookupIconIdFromDirectoryEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_MapDialogRect(HWND  hwnd, LPRECT  rect) /* ../dlls/user32/dialog.c:1543 */
{
	TRACE("Enter MapDialogRect\n");
	return pMapDialogRect(hwnd, rect);
}

extern WINAPI void wine32a_user32_MapDialogRect(void);  /* ../dlls/user32/dialog.c:1543 */
__ASM_GLOBAL_FUNC(wine32a_user32_MapDialogRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MapDialogRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_MapVirtualKeyA(UINT  code, UINT  maptype) /* ../dlls/user32/input.c:732 */
{
	TRACE("Enter MapVirtualKeyA\n");
	return pMapVirtualKeyA(code, maptype);
}

extern WINAPI void wine32a_user32_MapVirtualKeyA(void);  /* ../dlls/user32/input.c:732 */
__ASM_GLOBAL_FUNC(wine32a_user32_MapVirtualKeyA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MapVirtualKeyA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_MapVirtualKeyExA(UINT  code, UINT  maptype, HKL  hkl) /* ../dlls/user32/input.c:748 */
{
	TRACE("Enter MapVirtualKeyExA\n");
	return pMapVirtualKeyExA(code, maptype, hkl);
}

extern WINAPI void wine32a_user32_MapVirtualKeyExA(void);  /* ../dlls/user32/input.c:748 */
__ASM_GLOBAL_FUNC(wine32a_user32_MapVirtualKeyExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MapVirtualKeyExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_MapVirtualKeyExW(UINT  code, UINT  maptype, HKL  hkl) /* ../dlls/user32/input.c:767 */
{
	TRACE("Enter MapVirtualKeyExW\n");
	return pMapVirtualKeyExW(code, maptype, hkl);
}

extern WINAPI void wine32a_user32_MapVirtualKeyExW(void);  /* ../dlls/user32/input.c:767 */
__ASM_GLOBAL_FUNC(wine32a_user32_MapVirtualKeyExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MapVirtualKeyExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_MapVirtualKeyW(UINT  code, UINT  maptype) /* ../dlls/user32/input.c:740 */
{
	TRACE("Enter MapVirtualKeyW\n");
	return pMapVirtualKeyW(code, maptype);
}

extern WINAPI void wine32a_user32_MapVirtualKeyW(void);  /* ../dlls/user32/input.c:740 */
__ASM_GLOBAL_FUNC(wine32a_user32_MapVirtualKeyW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MapVirtualKeyW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_MapWindowPoints(HWND  hwndFrom, HWND  hwndTo, LPPOINT  lppt, UINT  count) /* ../dlls/user32/winpos.c:553 */
{
	TRACE("Enter MapWindowPoints\n");
	return pMapWindowPoints(hwndFrom, hwndTo, lppt, count);
}

extern WINAPI void wine32a_user32_MapWindowPoints(void);  /* ../dlls/user32/winpos.c:553 */
__ASM_GLOBAL_FUNC(wine32a_user32_MapWindowPoints,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MapWindowPoints") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_MenuItemFromPoint(HWND  hWnd, HMENU  hMenu, POINT  ptScreen) /* ../dlls/user32/menu.c:5479 */
{
	TRACE("Enter MenuItemFromPoint\n");
	return pMenuItemFromPoint(hWnd, hMenu, ptScreen);
}

extern WINAPI void wine32a_user32_MenuItemFromPoint(void);  /* ../dlls/user32/menu.c:5479 */
__ASM_GLOBAL_FUNC(wine32a_user32_MenuItemFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MenuItemFromPoint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_MessageBeep(UINT  i) /* ../dlls/user32/message.c:4469 */
{
	TRACE("Enter MessageBeep\n");
	return pMessageBeep(i);
}

extern WINAPI void wine32a_user32_MessageBeep(void);  /* ../dlls/user32/message.c:4469 */
__ASM_GLOBAL_FUNC(wine32a_user32_MessageBeep,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MessageBeep") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_MessageBoxA(HWND  hWnd, LPCSTR  text, LPCSTR  title, UINT  type) /* ../dlls/user32/msgbox.c:386 */
{
	TRACE("Enter MessageBoxA\n");
	return pMessageBoxA(hWnd, text, title, type);
}

extern WINAPI void wine32a_user32_MessageBoxA(void);  /* ../dlls/user32/msgbox.c:386 */
__ASM_GLOBAL_FUNC(wine32a_user32_MessageBoxA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MessageBoxA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_MessageBoxExA(HWND  hWnd, LPCSTR  text, LPCSTR  title, UINT  type, WORD  langid) /* ../dlls/user32/msgbox.c:404 */
{
	TRACE("Enter MessageBoxExA\n");
	return pMessageBoxExA(hWnd, text, title, type, langid);
}

extern WINAPI void wine32a_user32_MessageBoxExA(void);  /* ../dlls/user32/msgbox.c:404 */
__ASM_GLOBAL_FUNC(wine32a_user32_MessageBoxExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MessageBoxExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_MessageBoxExW(HWND  hWnd, LPCWSTR  text, LPCWSTR  title, UINT  type, WORD  langid) /* ../dlls/user32/msgbox.c:426 */
{
	TRACE("Enter MessageBoxExW\n");
	return pMessageBoxExW(hWnd, text, title, type, langid);
}

extern WINAPI void wine32a_user32_MessageBoxExW(void);  /* ../dlls/user32/msgbox.c:426 */
__ASM_GLOBAL_FUNC(wine32a_user32_MessageBoxExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MessageBoxExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_MessageBoxIndirectA(LPMSGBOXPARAMSA  msgbox) /* ../dlls/user32/msgbox.c:468 */
{
	TRACE("Enter MessageBoxIndirectA\n");
	return pMessageBoxIndirectA(msgbox);
}

extern WINAPI void wine32a_user32_MessageBoxIndirectA(void);  /* ../dlls/user32/msgbox.c:468 */
__ASM_GLOBAL_FUNC(wine32a_user32_MessageBoxIndirectA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MessageBoxIndirectA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_MessageBoxIndirectW(LPMSGBOXPARAMSW  msgbox) /* ../dlls/user32/msgbox.c:515 */
{
	TRACE("Enter MessageBoxIndirectW\n");
	return pMessageBoxIndirectW(msgbox);
}

extern WINAPI void wine32a_user32_MessageBoxIndirectW(void);  /* ../dlls/user32/msgbox.c:515 */
__ASM_GLOBAL_FUNC(wine32a_user32_MessageBoxIndirectW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MessageBoxIndirectW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_MessageBoxTimeoutA(HWND  hWnd, LPCSTR  text, LPCSTR  title, UINT  type, WORD  langid, DWORD  timeout) /* ../dlls/user32/msgbox.c:448 */
{
	TRACE("Enter MessageBoxTimeoutA\n");
	return pMessageBoxTimeoutA(hWnd, text, title, type, langid, timeout);
}

extern WINAPI void wine32a_user32_MessageBoxTimeoutA(void);  /* ../dlls/user32/msgbox.c:448 */
__ASM_GLOBAL_FUNC(wine32a_user32_MessageBoxTimeoutA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MessageBoxTimeoutA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_MessageBoxTimeoutW(HWND  hWnd, LPCWSTR  text, LPCWSTR  title, UINT  type, WORD  langid, DWORD  timeout) /* ../dlls/user32/msgbox.c:458 */
{
	TRACE("Enter MessageBoxTimeoutW\n");
	return pMessageBoxTimeoutW(hWnd, text, title, type, langid, timeout);
}

extern WINAPI void wine32a_user32_MessageBoxTimeoutW(void);  /* ../dlls/user32/msgbox.c:458 */
__ASM_GLOBAL_FUNC(wine32a_user32_MessageBoxTimeoutW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MessageBoxTimeoutW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_MessageBoxW(HWND  hwnd, LPCWSTR  text, LPCWSTR  title, UINT  type) /* ../dlls/user32/msgbox.c:395 */
{
	TRACE("Enter MessageBoxW\n");
	return pMessageBoxW(hwnd, text, title, type);
}

extern WINAPI void wine32a_user32_MessageBoxW(void);  /* ../dlls/user32/msgbox.c:395 */
__ASM_GLOBAL_FUNC(wine32a_user32_MessageBoxW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MessageBoxW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ModifyMenuA(HMENU  hMenu, UINT  pos, UINT  flags, UINT_PTR  id, LPCSTR  str) /* ../dlls/user32/menu.c:4169 */
{
	TRACE("Enter ModifyMenuA\n");
	return pModifyMenuA(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_user32_ModifyMenuA(void);  /* ../dlls/user32/menu.c:4169 */
__ASM_GLOBAL_FUNC(wine32a_user32_ModifyMenuA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ModifyMenuA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ModifyMenuW(HMENU  hMenu, UINT  pos, UINT  flags, UINT_PTR  id, LPCWSTR  str) /* ../dlls/user32/menu.c:4139 */
{
	TRACE("Enter ModifyMenuW\n");
	return pModifyMenuW(hMenu, pos, flags, id, str);
}

extern WINAPI void wine32a_user32_ModifyMenuW(void);  /* ../dlls/user32/menu.c:4139 */
__ASM_GLOBAL_FUNC(wine32a_user32_ModifyMenuW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ModifyMenuW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMONITOR wine32b_user32_MonitorFromPoint(POINT  pt, DWORD  flags) /* ../dlls/user32/sysparams.c:3711 */
{
	TRACE("Enter MonitorFromPoint\n");
	return pMonitorFromPoint(pt, flags);
}

extern WINAPI void wine32a_user32_MonitorFromPoint(void);  /* ../dlls/user32/sysparams.c:3711 */
__ASM_GLOBAL_FUNC(wine32a_user32_MonitorFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MonitorFromPoint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMONITOR wine32b_user32_MonitorFromRect(RECT*  rect, DWORD  flags) /* ../dlls/user32/sysparams.c:3680 */
{
	TRACE("Enter MonitorFromRect\n");
	return pMonitorFromRect(rect, flags);
}

extern WINAPI void wine32a_user32_MonitorFromRect(void);  /* ../dlls/user32/sysparams.c:3680 */
__ASM_GLOBAL_FUNC(wine32a_user32_MonitorFromRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MonitorFromRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HMONITOR wine32b_user32_MonitorFromWindow(HWND  hWnd, DWORD  dwFlags) /* ../dlls/user32/sysparams.c:3722 */
{
	TRACE("Enter MonitorFromWindow\n");
	return pMonitorFromWindow(hWnd, dwFlags);
}

extern WINAPI void wine32a_user32_MonitorFromWindow(void);  /* ../dlls/user32/sysparams.c:3722 */
__ASM_GLOBAL_FUNC(wine32a_user32_MonitorFromWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MonitorFromWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_MoveWindow(HWND  hwnd, INT  x, INT  y, INT  cx, INT  cy, BOOL  repaint) /* ../dlls/user32/winpos.c:671 */
{
	TRACE("Enter MoveWindow\n");
	return pMoveWindow(hwnd, x, y, cx, cy, repaint);
}

extern WINAPI void wine32a_user32_MoveWindow(void);  /* ../dlls/user32/winpos.c:671 */
__ASM_GLOBAL_FUNC(wine32a_user32_MoveWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MoveWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_MsgWaitForMultipleObjects(DWORD  count, HANDLE*  handles, BOOL  wait_all, DWORD  timeout, DWORD  mask) /* ../dlls/user32/message.c:4198 */
{
	TRACE("Enter MsgWaitForMultipleObjects\n");
	return pMsgWaitForMultipleObjects(count, handles, wait_all, timeout, mask);
}

extern WINAPI void wine32a_user32_MsgWaitForMultipleObjects(void);  /* ../dlls/user32/message.c:4198 */
__ASM_GLOBAL_FUNC(wine32a_user32_MsgWaitForMultipleObjects,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MsgWaitForMultipleObjects") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_MsgWaitForMultipleObjectsEx(DWORD  count, HANDLE*  pHandles, DWORD  timeout, DWORD  mask, DWORD  flags) /* ../dlls/user32/message.c:4174 */
{
	TRACE("Enter MsgWaitForMultipleObjectsEx\n");
	return pMsgWaitForMultipleObjectsEx(count, pHandles, timeout, mask, flags);
}

extern WINAPI void wine32a_user32_MsgWaitForMultipleObjectsEx(void);  /* ../dlls/user32/message.c:4174 */
__ASM_GLOBAL_FUNC(wine32a_user32_MsgWaitForMultipleObjectsEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_MsgWaitForMultipleObjectsEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_NotifyWinEvent(DWORD  event, HWND  hwnd, LONG  object_id, LONG  child_id) /* ../dlls/user32/hook.c:876 */
{
	TRACE("Enter NotifyWinEvent\n");
	return pNotifyWinEvent(event, hwnd, object_id, child_id);
}

extern WINAPI void wine32a_user32_NotifyWinEvent(void);  /* ../dlls/user32/hook.c:876 */
__ASM_GLOBAL_FUNC(wine32a_user32_NotifyWinEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_NotifyWinEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_OemKeyScan(WORD  oem) /* ../dlls/user32/input.c:669 */
{
	TRACE("Enter OemKeyScan\n");
	return pOemKeyScan(oem);
}

extern WINAPI void wine32a_user32_OemKeyScan(void);  /* ../dlls/user32/input.c:669 */
__ASM_GLOBAL_FUNC(wine32a_user32_OemKeyScan,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OemKeyScan") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_OemToCharA(LPCSTR  s, LPSTR  d) /* ../dlls/user32/lstr.c:188 */
{
	TRACE("Enter OemToCharA\n");
	return pOemToCharA(s, d);
}

extern WINAPI void wine32a_user32_OemToCharA(void);  /* ../dlls/user32/lstr.c:188 */
__ASM_GLOBAL_FUNC(wine32a_user32_OemToCharA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OemToCharA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_OemToCharBuffA(LPCSTR  s, LPSTR  d, DWORD  len) /* ../dlls/user32/lstr.c:198 */
{
	TRACE("Enter OemToCharBuffA\n");
	return pOemToCharBuffA(s, d, len);
}

extern WINAPI void wine32a_user32_OemToCharBuffA(void);  /* ../dlls/user32/lstr.c:198 */
__ASM_GLOBAL_FUNC(wine32a_user32_OemToCharBuffA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OemToCharBuffA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_OemToCharBuffW(LPCSTR  s, LPWSTR  d, DWORD  len) /* ../dlls/user32/lstr.c:218 */
{
	TRACE("Enter OemToCharBuffW\n");
	return pOemToCharBuffW(s, d, len);
}

extern WINAPI void wine32a_user32_OemToCharBuffW(void);  /* ../dlls/user32/lstr.c:218 */
__ASM_GLOBAL_FUNC(wine32a_user32_OemToCharBuffW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OemToCharBuffW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_OemToCharW(LPCSTR  s, LPWSTR  d) /* ../dlls/user32/lstr.c:229 */
{
	TRACE("Enter OemToCharW\n");
	return pOemToCharW(s, d);
}

extern WINAPI void wine32a_user32_OemToCharW(void);  /* ../dlls/user32/lstr.c:229 */
__ASM_GLOBAL_FUNC(wine32a_user32_OemToCharW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OemToCharW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_OffsetRect(LPRECT  rect, INT  x, INT  y) /* ../dlls/user32/uitools.c:1307 */
{
	TRACE("Enter OffsetRect\n");
	return pOffsetRect(rect, x, y);
}

extern WINAPI void wine32a_user32_OffsetRect(void);  /* ../dlls/user32/uitools.c:1307 */
__ASM_GLOBAL_FUNC(wine32a_user32_OffsetRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OffsetRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_OpenClipboard(HWND  hwnd) /* ../dlls/user32/clipboard.c:687 */
{
	TRACE("Enter OpenClipboard\n");
	return pOpenClipboard(hwnd);
}

extern WINAPI void wine32a_user32_OpenClipboard(void);  /* ../dlls/user32/clipboard.c:687 */
__ASM_GLOBAL_FUNC(wine32a_user32_OpenClipboard,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OpenClipboard") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDESK wine32b_user32_OpenDesktopA(LPCSTR  name, DWORD  flags, BOOL  inherit, ACCESS_MASK  access) /* ../dlls/user32/winstation.c:333 */
{
	TRACE("Enter OpenDesktopA\n");
	return pOpenDesktopA(name, flags, inherit, access);
}

extern WINAPI void wine32a_user32_OpenDesktopA(void);  /* ../dlls/user32/winstation.c:333 */
__ASM_GLOBAL_FUNC(wine32a_user32_OpenDesktopA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OpenDesktopA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDESK wine32b_user32_OpenDesktopW(LPCWSTR  name, DWORD  flags, BOOL  inherit, ACCESS_MASK  access) /* ../dlls/user32/winstation.c:374 */
{
	TRACE("Enter OpenDesktopW\n");
	return pOpenDesktopW(name, flags, inherit, access);
}

extern WINAPI void wine32a_user32_OpenDesktopW(void);  /* ../dlls/user32/winstation.c:374 */
__ASM_GLOBAL_FUNC(wine32a_user32_OpenDesktopW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OpenDesktopW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_OpenIcon(HWND  hwnd) /* ../dlls/user32/win.c:1949 */
{
	TRACE("Enter OpenIcon\n");
	return pOpenIcon(hwnd);
}

extern WINAPI void wine32a_user32_OpenIcon(void);  /* ../dlls/user32/win.c:1949 */
__ASM_GLOBAL_FUNC(wine32a_user32_OpenIcon,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OpenIcon") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDESK wine32b_user32_OpenInputDesktop(DWORD  flags, BOOL  inherit, ACCESS_MASK  access) /* ../dlls/user32/winstation.c:491 */
{
	TRACE("Enter OpenInputDesktop\n");
	return pOpenInputDesktop(flags, inherit, access);
}

extern WINAPI void wine32a_user32_OpenInputDesktop(void);  /* ../dlls/user32/winstation.c:491 */
__ASM_GLOBAL_FUNC(wine32a_user32_OpenInputDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OpenInputDesktop") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWINSTA wine32b_user32_OpenWindowStationA(LPCSTR  name, BOOL  inherit, ACCESS_MASK  access) /* ../dlls/user32/winstation.c:136 */
{
	TRACE("Enter OpenWindowStationA\n");
	return pOpenWindowStationA(name, inherit, access);
}

extern WINAPI void wine32a_user32_OpenWindowStationA(void);  /* ../dlls/user32/winstation.c:136 */
__ASM_GLOBAL_FUNC(wine32a_user32_OpenWindowStationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OpenWindowStationA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWINSTA wine32b_user32_OpenWindowStationW(LPCWSTR  name, BOOL  inherit, ACCESS_MASK  access) /* ../dlls/user32/winstation.c:154 */
{
	TRACE("Enter OpenWindowStationW\n");
	return pOpenWindowStationW(name, inherit, access);
}

extern WINAPI void wine32a_user32_OpenWindowStationW(void);  /* ../dlls/user32/winstation.c:154 */
__ASM_GLOBAL_FUNC(wine32a_user32_OpenWindowStationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_OpenWindowStationW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPARAM wine32b_user32_PackDDElParam(UINT  msg, UINT_PTR  uiLo, UINT_PTR  uiHi) /* ../dlls/user32/dde_misc.c:76 */
{
	TRACE("Enter PackDDElParam\n");
	return pPackDDElParam(msg, uiLo, uiHi);
}

extern WINAPI void wine32a_user32_PackDDElParam(void);  /* ../dlls/user32/dde_misc.c:76 */
__ASM_GLOBAL_FUNC(wine32a_user32_PackDDElParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PackDDElParam") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PaintDesktop(HDC  hdc) /* ../dlls/user32/desktop.c:141 */
{
	TRACE("Enter PaintDesktop\n");
	return pPaintDesktop(hdc);
}

extern WINAPI void wine32a_user32_PaintDesktop(void);  /* ../dlls/user32/desktop.c:141 */
__ASM_GLOBAL_FUNC(wine32a_user32_PaintDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PaintDesktop") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PeekMessageA(MSG*  msg, HWND  hwnd, UINT  first, UINT  last, UINT  flags) /* ../dlls/user32/message.c:3822 */
{
	TRACE("Enter PeekMessageA\n");
	return pPeekMessageA(msg, hwnd, first, last, flags);
}

extern WINAPI void wine32a_user32_PeekMessageA(void);  /* ../dlls/user32/message.c:3822 */
__ASM_GLOBAL_FUNC(wine32a_user32_PeekMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PeekMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PeekMessageW(MSG*  msg_out, HWND  hwnd, UINT  first, UINT  last, UINT  flags) /* ../dlls/user32/message.c:3786 */
{
	TRACE("Enter PeekMessageW\n");
	return pPeekMessageW(msg_out, hwnd, first, last, flags);
}

extern WINAPI void wine32a_user32_PeekMessageW(void);  /* ../dlls/user32/message.c:3786 */
__ASM_GLOBAL_FUNC(wine32a_user32_PeekMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PeekMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PhysicalToLogicalPoint(HWND  hwnd, POINT*  point) /* ../dlls/user32/sysparams.c:4316 */
{
	TRACE("Enter PhysicalToLogicalPoint\n");
	return pPhysicalToLogicalPoint(hwnd, point);
}

extern WINAPI void wine32a_user32_PhysicalToLogicalPoint(void);  /* ../dlls/user32/sysparams.c:4316 */
__ASM_GLOBAL_FUNC(wine32a_user32_PhysicalToLogicalPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PhysicalToLogicalPoint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PhysicalToLogicalPointForPerMonitorDPI(HWND  hwnd, POINT*  pt) /* ../dlls/user32/sysparams.c:3606 */
{
	TRACE("Enter PhysicalToLogicalPointForPerMonitorDPI\n");
	return pPhysicalToLogicalPointForPerMonitorDPI(hwnd, pt);
}

extern WINAPI void wine32a_user32_PhysicalToLogicalPointForPerMonitorDPI(void);  /* ../dlls/user32/sysparams.c:3606 */
__ASM_GLOBAL_FUNC(wine32a_user32_PhysicalToLogicalPointForPerMonitorDPI,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PhysicalToLogicalPointForPerMonitorDPI") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PostMessageA(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam) /* ../dlls/user32/message.c:3657 */
{
	TRACE("Enter PostMessageA\n");
	return pPostMessageA(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_user32_PostMessageA(void);  /* ../dlls/user32/message.c:3657 */
__ASM_GLOBAL_FUNC(wine32a_user32_PostMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PostMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PostMessageW(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam) /* ../dlls/user32/message.c:3667 */
{
	TRACE("Enter PostMessageW\n");
	return pPostMessageW(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_user32_PostMessageW(void);  /* ../dlls/user32/message.c:3667 */
__ASM_GLOBAL_FUNC(wine32a_user32_PostMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PostMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_PostQuitMessage(INT  exit_code) /* ../dlls/user32/message.c:3757 */
{
	TRACE("Enter PostQuitMessage\n");
	return pPostQuitMessage(exit_code);
}

extern WINAPI void wine32a_user32_PostQuitMessage(void);  /* ../dlls/user32/message.c:3757 */
__ASM_GLOBAL_FUNC(wine32a_user32_PostQuitMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PostQuitMessage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PostThreadMessageA(DWORD  thread, UINT  msg, WPARAM  wparam, LPARAM  lparam) /* ../dlls/user32/message.c:3707 */
{
	TRACE("Enter PostThreadMessageA\n");
	return pPostThreadMessageA(thread, msg, wparam, lparam);
}

extern WINAPI void wine32a_user32_PostThreadMessageA(void);  /* ../dlls/user32/message.c:3707 */
__ASM_GLOBAL_FUNC(wine32a_user32_PostThreadMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PostThreadMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PostThreadMessageW(DWORD  thread, UINT  msg, WPARAM  wparam, LPARAM  lparam) /* ../dlls/user32/message.c:3717 */
{
	TRACE("Enter PostThreadMessageW\n");
	return pPostThreadMessageW(thread, msg, wparam, lparam);
}

extern WINAPI void wine32a_user32_PostThreadMessageW(void);  /* ../dlls/user32/message.c:3717 */
__ASM_GLOBAL_FUNC(wine32a_user32_PostThreadMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PostThreadMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PrintWindow(HWND  hwnd, HDC  hdcBlt, UINT  nFlags) /* ../dlls/user32/painting.c:1762 */
{
	TRACE("Enter PrintWindow\n");
	return pPrintWindow(hwnd, hdcBlt, nFlags);
}

extern WINAPI void wine32a_user32_PrintWindow(void);  /* ../dlls/user32/painting.c:1762 */
__ASM_GLOBAL_FUNC(wine32a_user32_PrintWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PrintWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_PrivateExtractIconExA(LPCSTR  lpstrFile, int  nIndex, HICON*  phIconLarge, HICON*  phIconSmall, UINT  nIcons) /* ../dlls/user32/exticon.c:672 */
{
	TRACE("Enter PrivateExtractIconExA\n");
	return pPrivateExtractIconExA(lpstrFile, nIndex, phIconLarge, phIconSmall, nIcons);
}

extern WINAPI void wine32a_user32_PrivateExtractIconExA(void);  /* ../dlls/user32/exticon.c:672 */
__ASM_GLOBAL_FUNC(wine32a_user32_PrivateExtractIconExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PrivateExtractIconExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_PrivateExtractIconExW(LPCWSTR  lpwstrFile, int  nIndex, HICON*  phIconLarge, HICON*  phIconSmall, UINT  nIcons) /* ../dlls/user32/exticon.c:618 */
{
	TRACE("Enter PrivateExtractIconExW\n");
	return pPrivateExtractIconExW(lpwstrFile, nIndex, phIconLarge, phIconSmall, nIcons);
}

extern WINAPI void wine32a_user32_PrivateExtractIconExW(void);  /* ../dlls/user32/exticon.c:618 */
__ASM_GLOBAL_FUNC(wine32a_user32_PrivateExtractIconExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PrivateExtractIconExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_PrivateExtractIconsA(LPCSTR  lpstrFile, int  nIndex, int  sizeX, int  sizeY, HICON*  phicon, UINT*  piconid, UINT  nIcons, UINT  flags) /* ../dlls/user32/exticon.c:592 */
{
	TRACE("Enter PrivateExtractIconsA\n");
	return pPrivateExtractIconsA(lpstrFile, nIndex, sizeX, sizeY, phicon, piconid, nIcons, flags);
}

extern WINAPI void wine32a_user32_PrivateExtractIconsA(void);  /* ../dlls/user32/exticon.c:592 */
__ASM_GLOBAL_FUNC(wine32a_user32_PrivateExtractIconsA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PrivateExtractIconsA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_PrivateExtractIconsW(LPCWSTR  lpwstrFile, int  nIndex, int  sizeX, int  sizeY, HICON*  phicon, UINT*  pIconId, UINT  nIcons, UINT  flags) /* ../dlls/user32/exticon.c:568 */
{
	TRACE("Enter PrivateExtractIconsW\n");
	return pPrivateExtractIconsW(lpwstrFile, nIndex, sizeX, sizeY, phicon, pIconId, nIcons, flags);
}

extern WINAPI void wine32a_user32_PrivateExtractIconsW(void);  /* ../dlls/user32/exticon.c:568 */
__ASM_GLOBAL_FUNC(wine32a_user32_PrivateExtractIconsW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PrivateExtractIconsW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_PtInRect(RECT*  rect, POINT  pt) /* ../dlls/user32/uitools.c:1296 */
{
	TRACE("Enter PtInRect\n");
	return pPtInRect(rect, pt);
}

extern WINAPI void wine32a_user32_PtInRect(void);  /* ../dlls/user32/uitools.c:1296 */
__ASM_GLOBAL_FUNC(wine32a_user32_PtInRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_PtInRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_QueryDisplayConfig(UINT32  flags, UINT32*  numpathelements, DISPLAYCONFIG_PATH_INFO*  pathinfo, UINT32*  numinfoelements, DISPLAYCONFIG_MODE_INFO*  modeinfo, DISPLAYCONFIG_TOPOLOGY_ID*  topologyid) /* ../dlls/user32/misc.c:246 */
{
	TRACE("Enter QueryDisplayConfig\n");
	return pQueryDisplayConfig(flags, numpathelements, pathinfo, numinfoelements, modeinfo, topologyid);
}

extern WINAPI void wine32a_user32_QueryDisplayConfig(void);  /* ../dlls/user32/misc.c:246 */
__ASM_GLOBAL_FUNC(wine32a_user32_QueryDisplayConfig,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_QueryDisplayConfig") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_RealChildWindowFromPoint(HWND  hwndParent, POINT  pt) /* ../dlls/user32/winpos.c:356 */
{
	TRACE("Enter RealChildWindowFromPoint\n");
	return pRealChildWindowFromPoint(hwndParent, pt);
}

extern WINAPI void wine32a_user32_RealChildWindowFromPoint(void);  /* ../dlls/user32/winpos.c:356 */
__ASM_GLOBAL_FUNC(wine32a_user32_RealChildWindowFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RealChildWindowFromPoint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_RealGetWindowClassA(HWND  hwnd, LPSTR  buffer, UINT  count) /* ../dlls/user32/class.c:1243 */
{
	TRACE("Enter RealGetWindowClassA\n");
	return pRealGetWindowClassA(hwnd, buffer, count);
}

extern WINAPI void wine32a_user32_RealGetWindowClassA(void);  /* ../dlls/user32/class.c:1243 */
__ASM_GLOBAL_FUNC(wine32a_user32_RealGetWindowClassA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RealGetWindowClassA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_RealGetWindowClassW(HWND  hwnd, LPWSTR  buffer, UINT  count) /* ../dlls/user32/class.c:1252 */
{
	TRACE("Enter RealGetWindowClassW\n");
	return pRealGetWindowClassW(hwnd, buffer, count);
}

extern WINAPI void wine32a_user32_RealGetWindowClassW(void);  /* ../dlls/user32/class.c:1252 */
__ASM_GLOBAL_FUNC(wine32a_user32_RealGetWindowClassW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RealGetWindowClassW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_RedrawWindow(HWND  hwnd, RECT*  rect, HRGN  hrgn, UINT  flags) /* ../dlls/user32/painting.c:1228 */
{
	TRACE("Enter RedrawWindow\n");
	return pRedrawWindow(hwnd, rect, hrgn, flags);
}

extern WINAPI void wine32a_user32_RedrawWindow(void);  /* ../dlls/user32/painting.c:1228 */
__ASM_GLOBAL_FUNC(wine32a_user32_RedrawWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RedrawWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_user32_RegisterClassA(WNDCLASSA*  wc) /* ../dlls/user32/class.c:625 */
{
	TRACE("Enter RegisterClassA\n");
	return pRegisterClassA(wc);
}

extern WINAPI void wine32a_user32_RegisterClassA(void);  /* ../dlls/user32/class.c:625 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterClassA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterClassA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_user32_RegisterClassExA(WNDCLASSEXA*  wc) /* ../dlls/user32/class.c:673 */
{
	TRACE("Enter RegisterClassExA\n");
	return pRegisterClassExA(wc);
}

extern WINAPI void wine32a_user32_RegisterClassExA(void);  /* ../dlls/user32/class.c:673 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterClassExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterClassExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_user32_RegisterClassExW(WNDCLASSEXW*  wc) /* ../dlls/user32/class.c:731 */
{
	TRACE("Enter RegisterClassExW\n");
	return pRegisterClassExW(wc);
}

extern WINAPI void wine32a_user32_RegisterClassExW(void);  /* ../dlls/user32/class.c:731 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterClassExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterClassExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ATOM wine32b_user32_RegisterClassW(WNDCLASSW*  wc) /* ../dlls/user32/class.c:650 */
{
	TRACE("Enter RegisterClassW\n");
	return pRegisterClassW(wc);
}

extern WINAPI void wine32a_user32_RegisterClassW(void);  /* ../dlls/user32/class.c:650 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterClassW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterClassW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_RegisterClipboardFormatA(LPCSTR  name) /* ../dlls/user32/clipboard.c:658 */
{
	TRACE("Enter RegisterClipboardFormatA\n");
	return pRegisterClipboardFormatA(name);
}

extern WINAPI void wine32a_user32_RegisterClipboardFormatA(void);  /* ../dlls/user32/clipboard.c:658 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterClipboardFormatA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterClipboardFormatA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_RegisterClipboardFormatW(LPCWSTR  name) /* ../dlls/user32/clipboard.c:649 */
{
	TRACE("Enter RegisterClipboardFormatW\n");
	return pRegisterClipboardFormatW(name);
}

extern WINAPI void wine32a_user32_RegisterClipboardFormatW(void);  /* ../dlls/user32/clipboard.c:649 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterClipboardFormatW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterClipboardFormatW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDEVNOTIFY wine32b_user32_RegisterDeviceNotificationA(HANDLE  hnd, LPVOID  notifyfilter, DWORD  flags) /* ../dlls/user32/misc.c:297 */
{
	TRACE("Enter RegisterDeviceNotificationA\n");
	return pRegisterDeviceNotificationA(hnd, notifyfilter, flags);
}

extern WINAPI void wine32a_user32_RegisterDeviceNotificationA(void);  /* ../dlls/user32/misc.c:297 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterDeviceNotificationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterDeviceNotificationA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HDEVNOTIFY wine32b_user32_RegisterDeviceNotificationW(HANDLE  hRecipient, LPVOID  pNotificationFilter, DWORD  dwFlags) /* ../dlls/user32/misc.c:327 */
{
	TRACE("Enter RegisterDeviceNotificationW\n");
	return pRegisterDeviceNotificationW(hRecipient, pNotificationFilter, dwFlags);
}

extern WINAPI void wine32a_user32_RegisterDeviceNotificationW(void);  /* ../dlls/user32/misc.c:327 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterDeviceNotificationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterDeviceNotificationW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_RegisterHotKey(HWND  hwnd, INT  id, UINT  modifiers, UINT  vk) /* ../dlls/user32/input.c:934 */
{
	TRACE("Enter RegisterHotKey\n");
	return pRegisterHotKey(hwnd, id, modifiers, vk);
}

extern WINAPI void wine32a_user32_RegisterHotKey(void);  /* ../dlls/user32/input.c:934 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterHotKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterHotKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_RegisterLogonProcess(HANDLE  hprocess, BOOL  x) /* ../dlls/user32/misc.c:228 */
{
	TRACE("Enter RegisterLogonProcess\n");
	return pRegisterLogonProcess(hprocess, x);
}

extern WINAPI void wine32a_user32_RegisterLogonProcess(void);  /* ../dlls/user32/misc.c:228 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterLogonProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterLogonProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_RegisterPointerDeviceNotifications(HWND  hwnd, BOOL  notifyrange) /* ../dlls/user32/misc.c:566 */
{
	TRACE("Enter RegisterPointerDeviceNotifications\n");
	return pRegisterPointerDeviceNotifications(hwnd, notifyrange);
}

extern WINAPI void wine32a_user32_RegisterPointerDeviceNotifications(void);  /* ../dlls/user32/misc.c:566 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterPointerDeviceNotifications,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterPointerDeviceNotifications") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HPOWERNOTIFY wine32b_user32_RegisterPowerSettingNotification(HANDLE  recipient, GUID*  guid, DWORD  flags) /* ../dlls/user32/misc.c:495 */
{
	TRACE("Enter RegisterPowerSettingNotification\n");
	return pRegisterPowerSettingNotification(recipient, guid, flags);
}

extern WINAPI void wine32a_user32_RegisterPowerSettingNotification(void);  /* ../dlls/user32/misc.c:495 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterPowerSettingNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterPowerSettingNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_RegisterRawInputDevices(RAWINPUTDEVICE*  devices, UINT  device_count, UINT  size) /* ../dlls/user32/rawinput.c:253 */
{
	TRACE("Enter RegisterRawInputDevices\n");
	return pRegisterRawInputDevices(devices, device_count, size);
}

extern WINAPI void wine32a_user32_RegisterRawInputDevices(void);  /* ../dlls/user32/rawinput.c:253 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterRawInputDevices,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterRawInputDevices") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI int wine32b_user32_RegisterServicesProcess(DWORD  ServicesProcessId) /* ../dlls/user32/user_main.c:480 */
{
	TRACE("Enter RegisterServicesProcess\n");
	return pRegisterServicesProcess(ServicesProcessId);
}

extern WINAPI void wine32a_user32_RegisterServicesProcess(void);  /* ../dlls/user32/user_main.c:480 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterServicesProcess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterServicesProcess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_RegisterShellHookWindow(HWND  hWnd) /* ../dlls/user32/misc.c:265 */
{
	TRACE("Enter RegisterShellHookWindow\n");
	return pRegisterShellHookWindow(hWnd);
}

extern WINAPI void wine32a_user32_RegisterShellHookWindow(void);  /* ../dlls/user32/misc.c:265 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterShellHookWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterShellHookWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_RegisterSystemThread(DWORD  flags, DWORD  reserved) /* ../dlls/user32/misc.c:257 */
{
	TRACE("Enter RegisterSystemThread\n");
	return pRegisterSystemThread(flags, reserved);
}

extern WINAPI void wine32a_user32_RegisterSystemThread(void);  /* ../dlls/user32/misc.c:257 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterSystemThread,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterSystemThread") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_RegisterTasklist(DWORD  x) /* ../dlls/user32/misc.c:285 */
{
	TRACE("Enter RegisterTasklist\n");
	return pRegisterTasklist(x);
}

extern WINAPI void wine32a_user32_RegisterTasklist(void);  /* ../dlls/user32/misc.c:285 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterTasklist,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterTasklist") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_RegisterTouchHitTestingWindow(HWND  hwnd, ULONG  value) /* ../dlls/user32/misc.c:592 */
{
	TRACE("Enter RegisterTouchHitTestingWindow\n");
	return pRegisterTouchHitTestingWindow(hwnd, value);
}

extern WINAPI void wine32a_user32_RegisterTouchHitTestingWindow(void);  /* ../dlls/user32/misc.c:592 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterTouchHitTestingWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterTouchHitTestingWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_RegisterTouchWindow(HWND  hwnd, ULONG  flags) /* ../dlls/user32/win.c:4153 */
{
	TRACE("Enter RegisterTouchWindow\n");
	return pRegisterTouchWindow(hwnd, flags);
}

extern WINAPI void wine32a_user32_RegisterTouchWindow(void);  /* ../dlls/user32/win.c:4153 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterTouchWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterTouchWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_RegisterWindowMessageA(LPCSTR  str) /* ../dlls/user32/message.c:4263 */
{
	TRACE("Enter RegisterWindowMessageA\n");
	return pRegisterWindowMessageA(str);
}

extern WINAPI void wine32a_user32_RegisterWindowMessageA(void);  /* ../dlls/user32/message.c:4263 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterWindowMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterWindowMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_RegisterWindowMessageW(LPCWSTR  str) /* ../dlls/user32/message.c:4274 */
{
	TRACE("Enter RegisterWindowMessageW\n");
	return pRegisterWindowMessageW(str);
}

extern WINAPI void wine32a_user32_RegisterWindowMessageW(void);  /* ../dlls/user32/message.c:4274 */
__ASM_GLOBAL_FUNC(wine32a_user32_RegisterWindowMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RegisterWindowMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ReleaseCapture(void) /* ../dlls/user32/input.c:352 */
{
	TRACE("Enter ReleaseCapture\n");
	return pReleaseCapture();
}

extern WINAPI void wine32a_user32_ReleaseCapture(void);  /* ../dlls/user32/input.c:352 */
__ASM_GLOBAL_FUNC(wine32a_user32_ReleaseCapture,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ReleaseCapture") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_ReleaseDC(HWND  hwnd, HDC  hdc) /* ../dlls/user32/painting.c:1160 */
{
	TRACE("Enter ReleaseDC\n");
	return pReleaseDC(hwnd, hdc);
}

extern WINAPI void wine32a_user32_ReleaseDC(void);  /* ../dlls/user32/painting.c:1160 */
__ASM_GLOBAL_FUNC(wine32a_user32_ReleaseDC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ReleaseDC") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_RemoveClipboardFormatListener(HWND  hwnd) /* ../dlls/user32/clipboard.c:1159 */
{
	TRACE("Enter RemoveClipboardFormatListener\n");
	return pRemoveClipboardFormatListener(hwnd);
}

extern WINAPI void wine32a_user32_RemoveClipboardFormatListener(void);  /* ../dlls/user32/clipboard.c:1159 */
__ASM_GLOBAL_FUNC(wine32a_user32_RemoveClipboardFormatListener,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RemoveClipboardFormatListener") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_RemoveMenu(HMENU  hMenu, UINT  id, UINT  flags) /* ../dlls/user32/menu.c:4079 */
{
	TRACE("Enter RemoveMenu\n");
	return pRemoveMenu(hMenu, id, flags);
}

extern WINAPI void wine32a_user32_RemoveMenu(void);  /* ../dlls/user32/menu.c:4079 */
__ASM_GLOBAL_FUNC(wine32a_user32_RemoveMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RemoveMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_user32_RemovePropA(HWND  hwnd, LPCSTR  str) /* ../dlls/user32/property.c:182 */
{
	TRACE("Enter RemovePropA\n");
	return pRemovePropA(hwnd, str);
}

extern WINAPI void wine32a_user32_RemovePropA(void);  /* ../dlls/user32/property.c:182 */
__ASM_GLOBAL_FUNC(wine32a_user32_RemovePropA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RemovePropA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_user32_RemovePropW(HWND  hwnd, LPCWSTR  str) /* ../dlls/user32/property.c:195 */
{
	TRACE("Enter RemovePropW\n");
	return pRemovePropW(hwnd, str);
}

extern WINAPI void wine32a_user32_RemovePropW(void);  /* ../dlls/user32/property.c:195 */
__ASM_GLOBAL_FUNC(wine32a_user32_RemovePropW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_RemovePropW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ReplyMessage(LRESULT  result) /* ../dlls/user32/message.c:3623 */
{
	TRACE("Enter ReplyMessage\n");
	return pReplyMessage(result);
}

extern WINAPI void wine32a_user32_ReplyMessage(void);  /* ../dlls/user32/message.c:3623 */
__ASM_GLOBAL_FUNC(wine32a_user32_ReplyMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ReplyMessage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPARAM wine32b_user32_ReuseDDElParam(LPARAM  lParam, UINT  msgIn, UINT  msgOut, UINT_PTR  uiLo, UINT_PTR  uiHi) /* ../dlls/user32/dde_misc.c:184 */
{
	TRACE("Enter ReuseDDElParam\n");
	return pReuseDDElParam(lParam, msgIn, msgOut, uiLo, uiHi);
}

extern WINAPI void wine32a_user32_ReuseDDElParam(void);  /* ../dlls/user32/dde_misc.c:184 */
__ASM_GLOBAL_FUNC(wine32a_user32_ReuseDDElParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ReuseDDElParam") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ScreenToClient(HWND  hwnd, LPPOINT  lppnt) /* ../dlls/user32/winpos.c:601 */
{
	TRACE("Enter ScreenToClient\n");
	return pScreenToClient(hwnd, lppnt);
}

extern WINAPI void wine32a_user32_ScreenToClient(void);  /* ../dlls/user32/winpos.c:601 */
__ASM_GLOBAL_FUNC(wine32a_user32_ScreenToClient,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ScreenToClient") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_ScrollChildren(HWND  hWnd, UINT  uMsg, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/mdi.c:1758 */
{
	TRACE("Enter ScrollChildren\n");
	return pScrollChildren(hWnd, uMsg, wParam, lParam);
}

extern WINAPI void wine32a_user32_ScrollChildren(void);  /* ../dlls/user32/mdi.c:1758 */
__ASM_GLOBAL_FUNC(wine32a_user32_ScrollChildren,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ScrollChildren") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ScrollDC(HDC  hdc, INT  dx, INT  dy, RECT*  scroll, RECT*  clip, HRGN  ret_update_rgn, LPRECT  update_rect) /* ../dlls/user32/painting.c:1653 */
{
	TRACE("Enter ScrollDC\n");
	return pScrollDC(hdc, dx, dy, scroll, clip, ret_update_rgn, update_rect);
}

extern WINAPI void wine32a_user32_ScrollDC(void);  /* ../dlls/user32/painting.c:1653 */
__ASM_GLOBAL_FUNC(wine32a_user32_ScrollDC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ScrollDC") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ScrollWindow(HWND  hwnd, INT  dx, INT  dy, RECT*  rect, RECT*  clipRect) /* ../dlls/user32/painting.c:1638 */
{
	TRACE("Enter ScrollWindow\n");
	return pScrollWindow(hwnd, dx, dy, rect, clipRect);
}

extern WINAPI void wine32a_user32_ScrollWindow(void);  /* ../dlls/user32/painting.c:1638 */
__ASM_GLOBAL_FUNC(wine32a_user32_ScrollWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ScrollWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_ScrollWindowEx(HWND  hwnd, INT  dx, INT  dy, RECT*  rect, RECT*  clipRect, HRGN  hrgnUpdate, LPRECT  rcUpdate, UINT  flags) /* ../dlls/user32/painting.c:1626 */
{
	TRACE("Enter ScrollWindowEx\n");
	return pScrollWindowEx(hwnd, dx, dy, rect, clipRect, hrgnUpdate, rcUpdate, flags);
}

extern WINAPI void wine32a_user32_ScrollWindowEx(void);  /* ../dlls/user32/painting.c:1626 */
__ASM_GLOBAL_FUNC(wine32a_user32_ScrollWindowEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ScrollWindowEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_SendDlgItemMessageA(HWND  hwnd, INT  id, UINT  msg, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/dialog.c:1343 */
{
	TRACE("Enter SendDlgItemMessageA\n");
	return pSendDlgItemMessageA(hwnd, id, msg, wParam, lParam);
}

extern WINAPI void wine32a_user32_SendDlgItemMessageA(void);  /* ../dlls/user32/dialog.c:1343 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendDlgItemMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendDlgItemMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_SendDlgItemMessageW(HWND  hwnd, INT  id, UINT  msg, WPARAM  wParam, LPARAM  lParam) /* ../dlls/user32/dialog.c:1355 */
{
	TRACE("Enter SendDlgItemMessageW\n");
	return pSendDlgItemMessageW(hwnd, id, msg, wParam, lParam);
}

extern WINAPI void wine32a_user32_SendDlgItemMessageW(void);  /* ../dlls/user32/dialog.c:1355 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendDlgItemMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendDlgItemMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_SendIMEMessageExA(HWND  hwnd, LPARAM  lparam) /* ../dlls/user32/misc.c:453 */
{
	TRACE("Enter SendIMEMessageExA\n");
	return pSendIMEMessageExA(hwnd, lparam);
}

extern WINAPI void wine32a_user32_SendIMEMessageExA(void);  /* ../dlls/user32/misc.c:453 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendIMEMessageExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendIMEMessageExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_SendIMEMessageExW(HWND  hwnd, LPARAM  lparam) /* ../dlls/user32/misc.c:464 */
{
	TRACE("Enter SendIMEMessageExW\n");
	return pSendIMEMessageExW(hwnd, lparam);
}

extern WINAPI void wine32a_user32_SendIMEMessageExW(void);  /* ../dlls/user32/misc.c:464 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendIMEMessageExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendIMEMessageExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_SendInput(UINT  count, LPINPUT  inputs, int  size) /* ../dlls/user32/input.c:183 */
{
	TRACE("Enter SendInput\n");
	return pSendInput(count, inputs, size);
}

extern WINAPI void wine32a_user32_SendInput(void);  /* ../dlls/user32/input.c:183 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendInput,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendInput") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_SendMessageA(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam) /* ../dlls/user32/message.c:3497 */
{
	TRACE("Enter SendMessageA\n");
	return pSendMessageA(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_user32_SendMessageA(void);  /* ../dlls/user32/message.c:3497 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SendMessageCallbackA(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam, SENDASYNCPROC  callback, ULONG_PTR  data) /* ../dlls/user32/message.c:3568 */
{
	TRACE("Enter SendMessageCallbackA\n");
	return pSendMessageCallbackA(hwnd, msg, wparam, lparam, callback, data);
}

extern WINAPI void wine32a_user32_SendMessageCallbackA(void);  /* ../dlls/user32/message.c:3568 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendMessageCallbackA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendMessageCallbackA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SendMessageCallbackW(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam, SENDASYNCPROC  callback, ULONG_PTR  data) /* ../dlls/user32/message.c:3596 */
{
	TRACE("Enter SendMessageCallbackW\n");
	return pSendMessageCallbackW(hwnd, msg, wparam, lparam, callback, data);
}

extern WINAPI void wine32a_user32_SendMessageCallbackW(void);  /* ../dlls/user32/message.c:3596 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendMessageCallbackW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendMessageCallbackW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_SendMessageTimeoutA(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam, UINT  flags, UINT  timeout, PDWORD_PTR  res_ptr) /* ../dlls/user32/message.c:3455 */
{
	TRACE("Enter SendMessageTimeoutA\n");
	return pSendMessageTimeoutA(hwnd, msg, wparam, lparam, flags, timeout, res_ptr);
}

extern WINAPI void wine32a_user32_SendMessageTimeoutA(void);  /* ../dlls/user32/message.c:3455 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendMessageTimeoutA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendMessageTimeoutA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_SendMessageTimeoutW(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam, UINT  flags, UINT  timeout, PDWORD_PTR  res_ptr) /* ../dlls/user32/message.c:3436 */
{
	TRACE("Enter SendMessageTimeoutW\n");
	return pSendMessageTimeoutW(hwnd, msg, wparam, lparam, flags, timeout, res_ptr);
}

extern WINAPI void wine32a_user32_SendMessageTimeoutW(void);  /* ../dlls/user32/message.c:3436 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendMessageTimeoutW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendMessageTimeoutW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LRESULT wine32b_user32_SendMessageW(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam) /* ../dlls/user32/message.c:3476 */
{
	TRACE("Enter SendMessageW\n");
	return pSendMessageW(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_user32_SendMessageW(void);  /* ../dlls/user32/message.c:3476 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SendNotifyMessageA(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam) /* ../dlls/user32/message.c:3519 */
{
	TRACE("Enter SendNotifyMessageA\n");
	return pSendNotifyMessageA(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_user32_SendNotifyMessageA(void);  /* ../dlls/user32/message.c:3519 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendNotifyMessageA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendNotifyMessageA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SendNotifyMessageW(HWND  hwnd, UINT  msg, WPARAM  wparam, LPARAM  lparam) /* ../dlls/user32/message.c:3544 */
{
	TRACE("Enter SendNotifyMessageW\n");
	return pSendNotifyMessageW(hwnd, msg, wparam, lparam);
}

extern WINAPI void wine32a_user32_SendNotifyMessageW(void);  /* ../dlls/user32/message.c:3544 */
__ASM_GLOBAL_FUNC(wine32a_user32_SendNotifyMessageW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SendNotifyMessageW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_SetActiveWindow(HWND  hwnd) /* ../dlls/user32/focus.c:230 */
{
	TRACE("Enter SetActiveWindow\n");
	return pSetActiveWindow(hwnd);
}

extern WINAPI void wine32a_user32_SetActiveWindow(void);  /* ../dlls/user32/focus.c:230 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetActiveWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetActiveWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_SetCapture(HWND  hwnd) /* ../dlls/user32/input.c:340 */
{
	TRACE("Enter SetCapture\n");
	return pSetCapture(hwnd);
}

extern WINAPI void wine32a_user32_SetCapture(void);  /* ../dlls/user32/input.c:340 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetCapture,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetCapture") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetCaretBlinkTime(UINT  msecs) /* ../dlls/user32/caret.c:393 */
{
	TRACE("Enter SetCaretBlinkTime\n");
	return pSetCaretBlinkTime(msecs);
}

extern WINAPI void wine32a_user32_SetCaretBlinkTime(void);  /* ../dlls/user32/caret.c:393 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetCaretBlinkTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetCaretBlinkTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetCaretPos(INT  x, INT  y) /* ../dlls/user32/caret.c:244 */
{
	TRACE("Enter SetCaretPos\n");
	return pSetCaretPos(x, y);
}

extern WINAPI void wine32a_user32_SetCaretPos(void);  /* ../dlls/user32/caret.c:244 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetCaretPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetCaretPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_SetClassLongA(HWND  hwnd, INT  offset, LONG  newval) /* ../dlls/user32/class.c:1169 */
{
	TRACE("Enter SetClassLongA\n");
	return pSetClassLongA(hwnd, offset, newval);
}

extern WINAPI void wine32a_user32_SetClassLongA(void);  /* ../dlls/user32/class.c:1169 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetClassLongA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetClassLongA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG_PTR wine32b_user32_SetClassLongPtrA(HWND  hwnd, INT  offset, LONG_PTR  newval) /* ../dlls/user32/class.c:1484 */
{
	TRACE("Enter SetClassLongPtrA\n");
	return pSetClassLongPtrA(hwnd, offset, newval);
}

extern WINAPI void wine32a_user32_SetClassLongPtrA(void);  /* ../dlls/user32/class.c:1484 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetClassLongPtrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetClassLongPtrA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI ULONG_PTR wine32b_user32_SetClassLongPtrW(HWND  hwnd, INT  offset, LONG_PTR  newval) /* ../dlls/user32/class.c:1476 */
{
	TRACE("Enter SetClassLongPtrW\n");
	return pSetClassLongPtrW(hwnd, offset, newval);
}

extern WINAPI void wine32a_user32_SetClassLongPtrW(void);  /* ../dlls/user32/class.c:1476 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetClassLongPtrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetClassLongPtrW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_SetClassLongW(HWND  hwnd, INT  offset, LONG  newval) /* ../dlls/user32/class.c:1160 */
{
	TRACE("Enter SetClassLongW\n");
	return pSetClassLongW(hwnd, offset, newval);
}

extern WINAPI void wine32a_user32_SetClassLongW(void);  /* ../dlls/user32/class.c:1160 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetClassLongW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetClassLongW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_SetClassWord(HWND  hwnd, INT  offset, WORD  newval) /* ../dlls/user32/class.c:1015 */
{
	TRACE("Enter SetClassWord\n");
	return pSetClassWord(hwnd, offset, newval);
}

extern WINAPI void wine32a_user32_SetClassWord(void);  /* ../dlls/user32/class.c:1015 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetClassWord,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetClassWord") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HANDLE wine32b_user32_SetClipboardData(UINT  format, HANDLE  data) /* ../dlls/user32/clipboard.c:878 */
{
	TRACE("Enter SetClipboardData\n");
	return pSetClipboardData(format, data);
}

extern WINAPI void wine32a_user32_SetClipboardData(void);  /* ../dlls/user32/clipboard.c:878 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetClipboardData,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetClipboardData") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_SetClipboardViewer(HWND  hwnd) /* ../dlls/user32/clipboard.c:807 */
{
	TRACE("Enter SetClipboardViewer\n");
	return pSetClipboardViewer(hwnd);
}

extern WINAPI void wine32a_user32_SetClipboardViewer(void);  /* ../dlls/user32/clipboard.c:807 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetClipboardViewer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetClipboardViewer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT_PTR wine32b_user32_SetCoalescableTimer(HWND  hwnd, UINT_PTR  id, UINT  timeout, TIMERPROC  proc, ULONG  tolerance) /* ../dlls/user32/message.c:4481 */
{
	TRACE("Enter SetCoalescableTimer\n");
	return pSetCoalescableTimer(hwnd, id, timeout, proc, tolerance);
}

extern WINAPI void wine32a_user32_SetCoalescableTimer(void);  /* ../dlls/user32/message.c:4481 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetCoalescableTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetCoalescableTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HCURSOR wine32b_user32_SetCursor(HCURSOR  hCursor) /* ../dlls/user32/cursoricon.c:2040 */
{
	TRACE("Enter SetCursor\n");
	return pSetCursor(hCursor);
}

extern WINAPI void wine32a_user32_SetCursor(void);  /* ../dlls/user32/cursoricon.c:2040 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetCursor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetCursorPos(INT  x, INT  y) /* ../dlls/user32/input.c:309 */
{
	TRACE("Enter SetCursorPos\n");
	return pSetCursorPos(x, y);
}

extern WINAPI void wine32a_user32_SetCursorPos(void);  /* ../dlls/user32/input.c:309 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetCursorPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetCursorPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_SetDebugErrorLevel(DWORD  dwLevel) /* ../dlls/user32/misc.c:210 */
{
	TRACE("Enter SetDebugErrorLevel\n");
	return pSetDebugErrorLevel(dwLevel);
}

extern WINAPI void wine32a_user32_SetDebugErrorLevel(void);  /* ../dlls/user32/misc.c:210 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetDebugErrorLevel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetDebugErrorLevel") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetDeskWallPaper(LPCSTR  filename) /* ../dlls/user32/desktop.c:199 */
{
	TRACE("Enter SetDeskWallPaper\n");
	return pSetDeskWallPaper(filename);
}

extern WINAPI void wine32a_user32_SetDeskWallPaper(void);  /* ../dlls/user32/desktop.c:199 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetDeskWallPaper,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetDeskWallPaper") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetDlgItemInt(HWND  hwnd, INT  id, UINT  value, BOOL  fSigned) /* ../dlls/user32/dialog.c:1407 */
{
	TRACE("Enter SetDlgItemInt\n");
	return pSetDlgItemInt(hwnd, id, value, fSigned);
}

extern WINAPI void wine32a_user32_SetDlgItemInt(void);  /* ../dlls/user32/dialog.c:1407 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetDlgItemInt,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetDlgItemInt") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetDlgItemTextA(HWND  hwnd, INT  id, LPCSTR  lpString) /* ../dlls/user32/dialog.c:1367 */
{
	TRACE("Enter SetDlgItemTextA\n");
	return pSetDlgItemTextA(hwnd, id, lpString);
}

extern WINAPI void wine32a_user32_SetDlgItemTextA(void);  /* ../dlls/user32/dialog.c:1367 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetDlgItemTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetDlgItemTextA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetDlgItemTextW(HWND  hwnd, INT  id, LPCWSTR  lpString) /* ../dlls/user32/dialog.c:1376 */
{
	TRACE("Enter SetDlgItemTextW\n");
	return pSetDlgItemTextW(hwnd, id, lpString);
}

extern WINAPI void wine32a_user32_SetDlgItemTextW(void);  /* ../dlls/user32/dialog.c:1376 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetDlgItemTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetDlgItemTextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetDoubleClickTime(UINT  interval) /* ../dlls/user32/sysparams.c:3015 */
{
	TRACE("Enter SetDoubleClickTime\n");
	return pSetDoubleClickTime(interval);
}

extern WINAPI void wine32a_user32_SetDoubleClickTime(void);  /* ../dlls/user32/sysparams.c:3015 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetDoubleClickTime,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetDoubleClickTime") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_SetFocus(HWND  hwnd) /* ../dlls/user32/focus.c:260 */
{
	TRACE("Enter SetFocus\n");
	return pSetFocus(hwnd);
}

extern WINAPI void wine32a_user32_SetFocus(void);  /* ../dlls/user32/focus.c:260 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetFocus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetFocus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetForegroundWindow(HWND  hwnd) /* ../dlls/user32/focus.c:320 */
{
	TRACE("Enter SetForegroundWindow\n");
	return pSetForegroundWindow(hwnd);
}

extern WINAPI void wine32a_user32_SetForegroundWindow(void);  /* ../dlls/user32/focus.c:320 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetForegroundWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetForegroundWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetGestureConfig(HWND  hwnd, DWORD  reserved, UINT  id, PGESTURECONFIG  config, UINT  size) /* ../dlls/user32/misc.c:523 */
{
	TRACE("Enter SetGestureConfig\n");
	return pSetGestureConfig(hwnd, reserved, id, config, size);
}

extern WINAPI void wine32a_user32_SetGestureConfig(void);  /* ../dlls/user32/misc.c:523 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetGestureConfig,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetGestureConfig") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_SetInternalWindowPos(HWND  hwnd, UINT  showCmd, LPRECT  rect, LPPOINT  pt) /* ../dlls/user32/winpos.c:1492 */
{
	TRACE("Enter SetInternalWindowPos\n");
	return pSetInternalWindowPos(hwnd, showCmd, rect, pt);
}

extern WINAPI void wine32a_user32_SetInternalWindowPos(void);  /* ../dlls/user32/winpos.c:1492 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetInternalWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetInternalWindowPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetKeyboardState(LPBYTE  state) /* ../dlls/user32/input.c:595 */
{
	TRACE("Enter SetKeyboardState\n");
	return pSetKeyboardState(state);
}

extern WINAPI void wine32a_user32_SetKeyboardState(void);  /* ../dlls/user32/input.c:595 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetKeyboardState,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetKeyboardState") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_SetLastErrorEx(DWORD  error, DWORD  type) /* ../dlls/user32/misc.c:163 */
{
	TRACE("Enter SetLastErrorEx\n");
	return pSetLastErrorEx(error, type);
}

extern WINAPI void wine32a_user32_SetLastErrorEx(void);  /* ../dlls/user32/misc.c:163 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetLastErrorEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetLastErrorEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetLayeredWindowAttributes(HWND  hwnd, COLORREF  key, BYTE  alpha, DWORD  flags) /* ../dlls/user32/win.c:3899 */
{
	TRACE("Enter SetLayeredWindowAttributes\n");
	return pSetLayeredWindowAttributes(hwnd, key, alpha, flags);
}

extern WINAPI void wine32a_user32_SetLayeredWindowAttributes(void);  /* ../dlls/user32/win.c:3899 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetLayeredWindowAttributes,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetLayeredWindowAttributes") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_SetLogonNotifyWindow(HWINSTA  hwinsta, HWND  hwnd) /* ../dlls/user32/misc.c:237 */
{
	TRACE("Enter SetLogonNotifyWindow\n");
	return pSetLogonNotifyWindow(hwinsta, hwnd);
}

extern WINAPI void wine32a_user32_SetLogonNotifyWindow(void);  /* ../dlls/user32/misc.c:237 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetLogonNotifyWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetLogonNotifyWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetMenu(HWND  hWnd, HMENU  hMenu) /* ../dlls/user32/menu.c:4495 */
{
	TRACE("Enter SetMenu\n");
	return pSetMenu(hWnd, hMenu);
}

extern WINAPI void wine32a_user32_SetMenu(void);  /* ../dlls/user32/menu.c:4495 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetMenuContextHelpId(HMENU  hMenu, DWORD  dwContextHelpID) /* ../dlls/user32/menu.c:5441 */
{
	TRACE("Enter SetMenuContextHelpId\n");
	return pSetMenuContextHelpId(hMenu, dwContextHelpID);
}

extern WINAPI void wine32a_user32_SetMenuContextHelpId(void);  /* ../dlls/user32/menu.c:5441 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetMenuContextHelpId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetMenuContextHelpId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetMenuDefaultItem(HMENU  hmenu, UINT  uItem, UINT  bypos) /* ../dlls/user32/menu.c:5149 */
{
	TRACE("Enter SetMenuDefaultItem\n");
	return pSetMenuDefaultItem(hmenu, uItem, bypos);
}

extern WINAPI void wine32a_user32_SetMenuDefaultItem(void);  /* ../dlls/user32/menu.c:5149 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetMenuDefaultItem,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetMenuDefaultItem") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetMenuInfo(HMENU  hMenu, LPCMENUINFO  lpmi) /* ../dlls/user32/menu.c:5385 */
{
	TRACE("Enter SetMenuInfo\n");
	return pSetMenuInfo(hMenu, lpmi);
}

extern WINAPI void wine32a_user32_SetMenuInfo(void);  /* ../dlls/user32/menu.c:5385 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetMenuInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetMenuInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetMenuItemBitmaps(HMENU  hMenu, UINT  nPos, UINT  wFlags, HBITMAP  hNewUnCheck, HBITMAP  hNewCheck) /* ../dlls/user32/menu.c:4218 */
{
	TRACE("Enter SetMenuItemBitmaps\n");
	return pSetMenuItemBitmaps(hMenu, nPos, wFlags, hNewUnCheck, hNewCheck);
}

extern WINAPI void wine32a_user32_SetMenuItemBitmaps(void);  /* ../dlls/user32/menu.c:4218 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetMenuItemBitmaps,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetMenuItemBitmaps") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetMenuItemInfoA(HMENU  hmenu, UINT  item, BOOL  bypos, MENUITEMINFOA*  lpmii) /* ../dlls/user32/menu.c:5057 */
{
	TRACE("Enter SetMenuItemInfoA\n");
	return pSetMenuItemInfoA(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_user32_SetMenuItemInfoA(void);  /* ../dlls/user32/menu.c:5057 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetMenuItemInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetMenuItemInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetMenuItemInfoW(HMENU  hmenu, UINT  item, BOOL  bypos, MENUITEMINFOW*  lpmii) /* ../dlls/user32/menu.c:5083 */
{
	TRACE("Enter SetMenuItemInfoW\n");
	return pSetMenuItemInfoW(hmenu, item, bypos, lpmii);
}

extern WINAPI void wine32a_user32_SetMenuItemInfoW(void);  /* ../dlls/user32/menu.c:5083 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetMenuItemInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetMenuItemInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LPARAM wine32b_user32_SetMessageExtraInfo(LPARAM  lParam) /* ../dlls/user32/message.c:4139 */
{
	TRACE("Enter SetMessageExtraInfo\n");
	return pSetMessageExtraInfo(lParam);
}

extern WINAPI void wine32a_user32_SetMessageExtraInfo(void);  /* ../dlls/user32/message.c:4139 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetMessageExtraInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetMessageExtraInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetMessageQueue(INT  size) /* ../dlls/user32/message.c:4459 */
{
	TRACE("Enter SetMessageQueue\n");
	return pSetMessageQueue(size);
}

extern WINAPI void wine32a_user32_SetMessageQueue(void);  /* ../dlls/user32/message.c:4459 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetMessageQueue,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetMessageQueue") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_SetParent(HWND  hwnd, HWND  parent) /* ../dlls/user32/win.c:3166 */
{
	TRACE("Enter SetParent\n");
	return pSetParent(hwnd, parent);
}

extern WINAPI void wine32a_user32_SetParent(void);  /* ../dlls/user32/win.c:3166 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetParent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetParent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetPhysicalCursorPos(INT  x, INT  y) /* ../dlls/user32/sysparams.c:4300 */
{
	TRACE("Enter SetPhysicalCursorPos\n");
	return pSetPhysicalCursorPos(x, y);
}

extern WINAPI void wine32a_user32_SetPhysicalCursorPos(void);  /* ../dlls/user32/sysparams.c:4300 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetPhysicalCursorPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetPhysicalCursorPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetProcessDPIAware(void) /* ../dlls/user32/sysparams.c:3506 */
{
	TRACE("Enter SetProcessDPIAware\n");
	return pSetProcessDPIAware();
}

extern WINAPI void wine32a_user32_SetProcessDPIAware(void);  /* ../dlls/user32/sysparams.c:3506 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetProcessDPIAware,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetProcessDPIAware") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetProcessDefaultLayout(DWORD  layout) /* ../dlls/user32/win.c:4093 */
{
	TRACE("Enter SetProcessDefaultLayout\n");
	return pSetProcessDefaultLayout(layout);
}

extern WINAPI void wine32a_user32_SetProcessDefaultLayout(void);  /* ../dlls/user32/win.c:4093 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetProcessDefaultLayout,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetProcessDefaultLayout") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT  context) /* ../dlls/user32/sysparams.c:3412 */
{
	TRACE("Enter SetProcessDpiAwarenessContext\n");
	return pSetProcessDpiAwarenessContext(context);
}

extern WINAPI void wine32a_user32_SetProcessDpiAwarenessContext(void);  /* ../dlls/user32/sysparams.c:3412 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetProcessDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetProcessDpiAwarenessContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetProcessDpiAwarenessInternal(DPI_AWARENESS  awareness) /* ../dlls/user32/sysparams.c:3448 */
{
	TRACE("Enter SetProcessDpiAwarenessInternal\n");
	return pSetProcessDpiAwarenessInternal(awareness);
}

extern WINAPI void wine32a_user32_SetProcessDpiAwarenessInternal(void);  /* ../dlls/user32/sysparams.c:3448 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetProcessDpiAwarenessInternal,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetProcessDpiAwarenessInternal") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetProcessWindowStation(HWINSTA  handle) /* ../dlls/user32/winstation.c:212 */
{
	TRACE("Enter SetProcessWindowStation\n");
	return pSetProcessWindowStation(handle);
}

extern WINAPI void wine32a_user32_SetProcessWindowStation(void);  /* ../dlls/user32/winstation.c:212 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetProcessWindowStation,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetProcessWindowStation") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_SetProgmanWindow(HWND  hwnd) /* ../dlls/user32/focus.c:454 */
{
	TRACE("Enter SetProgmanWindow\n");
	return pSetProgmanWindow(hwnd);
}

extern WINAPI void wine32a_user32_SetProgmanWindow(void);  /* ../dlls/user32/focus.c:454 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetProgmanWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetProgmanWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetPropA(HWND  hwnd, LPCSTR  str, HANDLE  handle) /* ../dlls/user32/property.c:149 */
{
	TRACE("Enter SetPropA\n");
	return pSetPropA(hwnd, str, handle);
}

extern WINAPI void wine32a_user32_SetPropA(void);  /* ../dlls/user32/property.c:149 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetPropA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetPropA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetPropW(HWND  hwnd, LPCWSTR  str, HANDLE  handle) /* ../dlls/user32/property.c:162 */
{
	TRACE("Enter SetPropW\n");
	return pSetPropW(hwnd, str, handle);
}

extern WINAPI void wine32a_user32_SetPropW(void);  /* ../dlls/user32/property.c:162 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetPropW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetPropW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetRect(LPRECT  rect, INT  left, INT  top, INT  right, INT  bottom) /* ../dlls/user32/uitools.c:1247 */
{
	TRACE("Enter SetRect\n");
	return pSetRect(rect, left, top, right, bottom);
}

extern WINAPI void wine32a_user32_SetRect(void);  /* ../dlls/user32/uitools.c:1247 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetRectEmpty(LPRECT  rect) /* ../dlls/user32/uitools.c:1262 */
{
	TRACE("Enter SetRectEmpty\n");
	return pSetRectEmpty(rect);
}

extern WINAPI void wine32a_user32_SetRectEmpty(void);  /* ../dlls/user32/uitools.c:1262 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetRectEmpty,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetRectEmpty") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_SetScrollInfo(HWND  hwnd, INT  nBar, SCROLLINFO*  info, BOOL  bRedraw) /* ../dlls/user32/scroll.c:1626 */
{
	TRACE("Enter SetScrollInfo\n");
	return pSetScrollInfo(hwnd, nBar, info, bRedraw);
}

extern WINAPI void wine32a_user32_SetScrollInfo(void);  /* ../dlls/user32/scroll.c:1626 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetScrollInfo,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetScrollInfo") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_SetScrollPos(HWND  hwnd, INT  nBar, INT  nPos, BOOL  bRedraw) /* ../dlls/user32/scroll.c:1855 */
{
	TRACE("Enter SetScrollPos\n");
	return pSetScrollPos(hwnd, nBar, nPos, bRedraw);
}

extern WINAPI void wine32a_user32_SetScrollPos(void);  /* ../dlls/user32/scroll.c:1855 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetScrollPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetScrollPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetScrollRange(HWND  hwnd, INT  nBar, INT  minVal, INT  maxVal, BOOL  bRedraw) /* ../dlls/user32/scroll.c:1917 */
{
	TRACE("Enter SetScrollRange\n");
	return pSetScrollRange(hwnd, nBar, minVal, maxVal, bRedraw);
}

extern WINAPI void wine32a_user32_SetScrollRange(void);  /* ../dlls/user32/scroll.c:1917 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetScrollRange,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetScrollRange") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetShellWindow(HWND  hwndShell) /* ../dlls/user32/focus.c:426 */
{
	TRACE("Enter SetShellWindow\n");
	return pSetShellWindow(hwndShell);
}

extern WINAPI void wine32a_user32_SetShellWindow(void);  /* ../dlls/user32/focus.c:426 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetShellWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetShellWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetShellWindowEx(HWND  hwndShell, HWND  hwndListView) /* ../dlls/user32/focus.c:391 */
{
	TRACE("Enter SetShellWindowEx\n");
	return pSetShellWindowEx(hwndShell, hwndListView);
}

extern WINAPI void wine32a_user32_SetShellWindowEx(void);  /* ../dlls/user32/focus.c:391 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetShellWindowEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetShellWindowEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetSysColors(INT  count, INT*  colors, COLORREF*  values) /* ../dlls/user32/sysparams.c:3050 */
{
	TRACE("Enter SetSysColors\n");
	return pSetSysColors(count, colors, values);
}

extern WINAPI void wine32a_user32_SetSysColors(void);  /* ../dlls/user32/sysparams.c:3050 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetSysColors,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetSysColors") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD_PTR wine32b_user32_SetSysColorsTemp(COLORREF*  pPens, HBRUSH*  pBrushes, DWORD_PTR  n) /* ../dlls/user32/sysparams.c:3074 */
{
	TRACE("Enter SetSysColorsTemp\n");
	return pSetSysColorsTemp(pPens, pBrushes, n);
}

extern WINAPI void wine32a_user32_SetSysColorsTemp(void);  /* ../dlls/user32/sysparams.c:3074 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetSysColorsTemp,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetSysColorsTemp") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetSystemCursor(HCURSOR  hcur, DWORD  id) /* ../dlls/user32/cursoricon.c:2200 */
{
	TRACE("Enter SetSystemCursor\n");
	return pSetSystemCursor(hcur, id);
}

extern WINAPI void wine32a_user32_SetSystemCursor(void);  /* ../dlls/user32/cursoricon.c:2200 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetSystemCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetSystemCursor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetSystemMenu(HWND  hwnd, HMENU  hMenu) /* ../dlls/user32/menu.c:4344 */
{
	TRACE("Enter SetSystemMenu\n");
	return pSetSystemMenu(hwnd, hMenu);
}

extern WINAPI void wine32a_user32_SetSystemMenu(void);  /* ../dlls/user32/menu.c:4344 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetSystemMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetSystemMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT_PTR wine32b_user32_SetSystemTimer(HWND  hwnd, UINT_PTR  id, UINT  timeout, TIMERPROC  proc) /* ../dlls/user32/message.c:4523 */
{
	TRACE("Enter SetSystemTimer\n");
	return pSetSystemTimer(hwnd, id, timeout, proc);
}

extern WINAPI void wine32a_user32_SetSystemTimer(void);  /* ../dlls/user32/message.c:4523 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetSystemTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetSystemTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_SetTaskmanWindow(HWND  hwnd) /* ../dlls/user32/focus.c:491 */
{
	TRACE("Enter SetTaskmanWindow\n");
	return pSetTaskmanWindow(hwnd);
}

extern WINAPI void wine32a_user32_SetTaskmanWindow(void);  /* ../dlls/user32/focus.c:491 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetTaskmanWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetTaskmanWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetThreadDesktop(HDESK  handle) /* ../dlls/user32/winstation.c:416 */
{
	TRACE("Enter SetThreadDesktop\n");
	return pSetThreadDesktop(handle);
}

extern WINAPI void wine32a_user32_SetThreadDesktop(void);  /* ../dlls/user32/winstation.c:416 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetThreadDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetThreadDesktop") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DPI_AWARENESS_CONTEXT wine32b_user32_SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT  context) /* ../dlls/user32/sysparams.c:3569 */
{
	TRACE("Enter SetThreadDpiAwarenessContext\n");
	return pSetThreadDpiAwarenessContext(context);
}

extern WINAPI void wine32a_user32_SetThreadDpiAwarenessContext(void);  /* ../dlls/user32/sysparams.c:3569 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetThreadDpiAwarenessContext,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetThreadDpiAwarenessContext") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT_PTR wine32b_user32_SetTimer(HWND  hwnd, UINT_PTR  id, UINT  timeout, TIMERPROC  proc) /* ../dlls/user32/message.c:4514 */
{
	TRACE("Enter SetTimer\n");
	return pSetTimer(hwnd, id, timeout, proc);
}

extern WINAPI void wine32a_user32_SetTimer(void);  /* ../dlls/user32/message.c:4514 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetTimer,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetTimer") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetUserObjectInformationA(HANDLE  handle, INT  index, LPVOID  info, DWORD  len) /* ../dlls/user32/winstation.c:639 */
{
	TRACE("Enter SetUserObjectInformationA\n");
	return pSetUserObjectInformationA(handle, index, info, len);
}

extern WINAPI void wine32a_user32_SetUserObjectInformationA(void);  /* ../dlls/user32/winstation.c:639 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetUserObjectInformationA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetUserObjectInformationA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetUserObjectInformationW(HANDLE  handle, INT  index, LPVOID  info, DWORD  len) /* ../dlls/user32/winstation.c:648 */
{
	TRACE("Enter SetUserObjectInformationW\n");
	return pSetUserObjectInformationW(handle, index, info, len);
}

extern WINAPI void wine32a_user32_SetUserObjectInformationW(void);  /* ../dlls/user32/winstation.c:648 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetUserObjectInformationW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetUserObjectInformationW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetUserObjectSecurity(HANDLE  handle, PSECURITY_INFORMATION  info, PSECURITY_DESCRIPTOR  sid) /* ../dlls/user32/winstation.c:691 */
{
	TRACE("Enter SetUserObjectSecurity\n");
	return pSetUserObjectSecurity(handle, info, sid);
}

extern WINAPI void wine32a_user32_SetUserObjectSecurity(void);  /* ../dlls/user32/winstation.c:691 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetUserObjectSecurity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetUserObjectSecurity") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWINEVENTHOOK wine32b_user32_SetWinEventHook(DWORD  event_min, DWORD  event_max, HMODULE  inst, WINEVENTPROC  proc, DWORD  pid, DWORD  tid, DWORD  flags) /* ../dlls/user32/hook.c:702 */
{
	TRACE("Enter SetWinEventHook\n");
	return pSetWinEventHook(event_min, event_max, inst, proc, pid, tid, flags);
}

extern WINAPI void wine32a_user32_SetWinEventHook(void);  /* ../dlls/user32/hook.c:702 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWinEventHook,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWinEventHook") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetWindowCompositionAttribute(HWND  hwnd, void*  data) /* ../dlls/user32/win.c:4237 */
{
	TRACE("Enter SetWindowCompositionAttribute\n");
	return pSetWindowCompositionAttribute(hwnd, data);
}

extern WINAPI void wine32a_user32_SetWindowCompositionAttribute(void);  /* ../dlls/user32/win.c:4237 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowCompositionAttribute,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowCompositionAttribute") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetWindowContextHelpId(HWND  hwnd, DWORD  id) /* ../dlls/user32/win.c:3742 */
{
	TRACE("Enter SetWindowContextHelpId\n");
	return pSetWindowContextHelpId(hwnd, id);
}

extern WINAPI void wine32a_user32_SetWindowContextHelpId(void);  /* ../dlls/user32/win.c:3742 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowContextHelpId,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowContextHelpId") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetWindowDisplayAffinity(HWND  hwnd, DWORD  affinity) /* ../dlls/user32/win.c:4220 */
{
	TRACE("Enter SetWindowDisplayAffinity\n");
	return pSetWindowDisplayAffinity(hwnd, affinity);
}

extern WINAPI void wine32a_user32_SetWindowDisplayAffinity(void);  /* ../dlls/user32/win.c:4220 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowDisplayAffinity,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowDisplayAffinity") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_SetWindowLongA(HWND  hwnd, INT  offset, LONG  newval) /* ../dlls/user32/win.c:2760 */
{
	TRACE("Enter SetWindowLongA\n");
	return pSetWindowLongA(hwnd, offset, newval);
}

extern WINAPI void wine32a_user32_SetWindowLongA(void);  /* ../dlls/user32/win.c:2760 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowLongA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowLongA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG_PTR wine32b_user32_SetWindowLongPtrA(HWND  hwnd, INT  offset, LONG_PTR  newval) /* ../dlls/user32/win.c:4145 */
{
	TRACE("Enter SetWindowLongPtrA\n");
	return pSetWindowLongPtrA(hwnd, offset, newval);
}

extern WINAPI void wine32a_user32_SetWindowLongPtrA(void);  /* ../dlls/user32/win.c:4145 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowLongPtrA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowLongPtrA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG_PTR wine32b_user32_SetWindowLongPtrW(HWND  hwnd, INT  offset, LONG_PTR  newval) /* ../dlls/user32/win.c:4137 */
{
	TRACE("Enter SetWindowLongPtrW\n");
	return pSetWindowLongPtrW(hwnd, offset, newval);
}

extern WINAPI void wine32a_user32_SetWindowLongPtrW(void);  /* ../dlls/user32/win.c:4137 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowLongPtrW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowLongPtrW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_SetWindowLongW(HWND  hwnd, INT  offset, LONG  newval) /* ../dlls/user32/win.c:2844 */
{
	TRACE("Enter SetWindowLongW\n");
	return pSetWindowLongW(hwnd, offset, newval);
}

extern WINAPI void wine32a_user32_SetWindowLongW(void);  /* ../dlls/user32/win.c:2844 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowLongW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowLongW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetWindowPlacement(HWND  hwnd, WINDOWPLACEMENT*  wpl) /* ../dlls/user32/winpos.c:1455 */
{
	TRACE("Enter SetWindowPlacement\n");
	return pSetWindowPlacement(hwnd, wpl);
}

extern WINAPI void wine32a_user32_SetWindowPlacement(void);  /* ../dlls/user32/winpos.c:1455 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowPlacement,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowPlacement") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetWindowPos(HWND  hwnd, HWND  hwndInsertAfter, INT  x, INT  y, INT  cx, INT  cy, UINT  flags) /* ../dlls/user32/winpos.c:2350 */
{
	TRACE("Enter SetWindowPos\n");
	return pSetWindowPos(hwnd, hwndInsertAfter, x, y, cx, cy, flags);
}

extern WINAPI void wine32a_user32_SetWindowPos(void);  /* ../dlls/user32/winpos.c:2350 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowPos,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowPos") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_SetWindowRgn(HWND  hwnd, HRGN  hrgn, BOOL  bRedraw) /* ../dlls/user32/winpos.c:178 */
{
	TRACE("Enter SetWindowRgn\n");
	return pSetWindowRgn(hwnd, hrgn, bRedraw);
}

extern WINAPI void wine32a_user32_SetWindowRgn(void);  /* ../dlls/user32/winpos.c:178 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowRgn") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_SetWindowStationUser(DWORD  x1, DWORD  x2) /* ../dlls/user32/misc.c:219 */
{
	TRACE("Enter SetWindowStationUser\n");
	return pSetWindowStationUser(x1, x2);
}

extern WINAPI void wine32a_user32_SetWindowStationUser(void);  /* ../dlls/user32/misc.c:219 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowStationUser,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowStationUser") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetWindowTextA(HWND  hwnd, LPCSTR  lpString) /* ../dlls/user32/win.c:2938 */
{
	TRACE("Enter SetWindowTextA\n");
	return pSetWindowTextA(hwnd, lpString);
}

extern WINAPI void wine32a_user32_SetWindowTextA(void);  /* ../dlls/user32/win.c:2938 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowTextA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowTextA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SetWindowTextW(HWND  hwnd, LPCWSTR  lpString) /* ../dlls/user32/win.c:2955 */
{
	TRACE("Enter SetWindowTextW\n");
	return pSetWindowTextW(hwnd, lpString);
}

extern WINAPI void wine32a_user32_SetWindowTextW(void);  /* ../dlls/user32/win.c:2955 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowTextW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowTextW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_SetWindowWord(HWND  hwnd, INT  offset, WORD  newval) /* ../dlls/user32/win.c:2734 */
{
	TRACE("Enter SetWindowWord\n");
	return pSetWindowWord(hwnd, offset, newval);
}

extern WINAPI void wine32a_user32_SetWindowWord(void);  /* ../dlls/user32/win.c:2734 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowWord,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowWord") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HHOOK wine32b_user32_SetWindowsHookA(INT  id, HOOKPROC  proc) /* ../dlls/user32/hook.c:525 */
{
	TRACE("Enter SetWindowsHookA\n");
	return pSetWindowsHookA(id, proc);
}

extern WINAPI void wine32a_user32_SetWindowsHookA(void);  /* ../dlls/user32/hook.c:525 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowsHookA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowsHookA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HHOOK wine32b_user32_SetWindowsHookExA(INT  id, HOOKPROC  proc, HINSTANCE  inst, DWORD  tid) /* ../dlls/user32/hook.c:543 */
{
	TRACE("Enter SetWindowsHookExA\n");
	return pSetWindowsHookExA(id, proc, inst, tid);
}

extern WINAPI void wine32a_user32_SetWindowsHookExA(void);  /* ../dlls/user32/hook.c:543 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowsHookExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowsHookExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HHOOK wine32b_user32_SetWindowsHookExW(INT  id, HOOKPROC  proc, HINSTANCE  inst, DWORD  tid) /* ../dlls/user32/hook.c:551 */
{
	TRACE("Enter SetWindowsHookExW\n");
	return pSetWindowsHookExW(id, proc, inst, tid);
}

extern WINAPI void wine32a_user32_SetWindowsHookExW(void);  /* ../dlls/user32/hook.c:551 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowsHookExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowsHookExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HHOOK wine32b_user32_SetWindowsHookW(INT  id, HOOKPROC  proc) /* ../dlls/user32/hook.c:534 */
{
	TRACE("Enter SetWindowsHookW\n");
	return pSetWindowsHookW(id, proc);
}

extern WINAPI void wine32a_user32_SetWindowsHookW(void);  /* ../dlls/user32/hook.c:534 */
__ASM_GLOBAL_FUNC(wine32a_user32_SetWindowsHookW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SetWindowsHookW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ShowCaret(HWND  hwnd) /* ../dlls/user32/caret.c:329 */
{
	TRACE("Enter ShowCaret\n");
	return pShowCaret(hwnd);
}

extern WINAPI void wine32a_user32_ShowCaret(void);  /* ../dlls/user32/caret.c:329 */
__ASM_GLOBAL_FUNC(wine32a_user32_ShowCaret,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ShowCaret") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_ShowCursor(BOOL  bShow) /* ../dlls/user32/cursoricon.c:2072 */
{
	TRACE("Enter ShowCursor\n");
	return pShowCursor(bShow);
}

extern WINAPI void wine32a_user32_ShowCursor(void);  /* ../dlls/user32/cursoricon.c:2072 */
__ASM_GLOBAL_FUNC(wine32a_user32_ShowCursor,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ShowCursor") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ShowOwnedPopups(HWND  owner, BOOL  fShow) /* ../dlls/user32/win.c:3414 */
{
	TRACE("Enter ShowOwnedPopups\n");
	return pShowOwnedPopups(owner, fShow);
}

extern WINAPI void wine32a_user32_ShowOwnedPopups(void);  /* ../dlls/user32/win.c:3414 */
__ASM_GLOBAL_FUNC(wine32a_user32_ShowOwnedPopups,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ShowOwnedPopups") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ShowScrollBar(HWND  hwnd, INT  nBar, BOOL  fShow) /* ../dlls/user32/scroll.c:2018 */
{
	TRACE("Enter ShowScrollBar\n");
	return pShowScrollBar(hwnd, nBar, fShow);
}

extern WINAPI void wine32a_user32_ShowScrollBar(void);  /* ../dlls/user32/scroll.c:2018 */
__ASM_GLOBAL_FUNC(wine32a_user32_ShowScrollBar,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ShowScrollBar") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ShowWindow(HWND  hwnd, INT  cmd) /* ../dlls/user32/winpos.c:1219 */
{
	TRACE("Enter ShowWindow\n");
	return pShowWindow(hwnd, cmd);
}

extern WINAPI void wine32a_user32_ShowWindow(void);  /* ../dlls/user32/winpos.c:1219 */
__ASM_GLOBAL_FUNC(wine32a_user32_ShowWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ShowWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ShowWindowAsync(HWND  hwnd, INT  cmd) /* ../dlls/user32/winpos.c:1199 */
{
	TRACE("Enter ShowWindowAsync\n");
	return pShowWindowAsync(hwnd, cmd);
}

extern WINAPI void wine32a_user32_ShowWindowAsync(void);  /* ../dlls/user32/winpos.c:1199 */
__ASM_GLOBAL_FUNC(wine32a_user32_ShowWindowAsync,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ShowWindowAsync") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ShutdownBlockReasonCreate(HWND  hwnd, LPCWSTR  reason) /* ../dlls/user32/user_main.c:489 */
{
	TRACE("Enter ShutdownBlockReasonCreate\n");
	return pShutdownBlockReasonCreate(hwnd, reason);
}

extern WINAPI void wine32a_user32_ShutdownBlockReasonCreate(void);  /* ../dlls/user32/user_main.c:489 */
__ASM_GLOBAL_FUNC(wine32a_user32_ShutdownBlockReasonCreate,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ShutdownBlockReasonCreate") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ShutdownBlockReasonDestroy(HWND  hwnd) /* ../dlls/user32/user_main.c:499 */
{
	TRACE("Enter ShutdownBlockReasonDestroy\n");
	return pShutdownBlockReasonDestroy(hwnd);
}

extern WINAPI void wine32a_user32_ShutdownBlockReasonDestroy(void);  /* ../dlls/user32/user_main.c:499 */
__ASM_GLOBAL_FUNC(wine32a_user32_ShutdownBlockReasonDestroy,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ShutdownBlockReasonDestroy") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SubtractRect(LPRECT  dest, RECT*  src1, RECT*  src2) /* ../dlls/user32/uitools.c:1397 */
{
	TRACE("Enter SubtractRect\n");
	return pSubtractRect(dest, src1, src2);
}

extern WINAPI void wine32a_user32_SubtractRect(void);  /* ../dlls/user32/uitools.c:1397 */
__ASM_GLOBAL_FUNC(wine32a_user32_SubtractRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SubtractRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SwapMouseButton(BOOL  fSwap) /* ../dlls/user32/sysparams.c:3004 */
{
	TRACE("Enter SwapMouseButton\n");
	return pSwapMouseButton(fSwap);
}

extern WINAPI void wine32a_user32_SwapMouseButton(void);  /* ../dlls/user32/sysparams.c:3004 */
__ASM_GLOBAL_FUNC(wine32a_user32_SwapMouseButton,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SwapMouseButton") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SwitchDesktop(HDESK  hDesktop) /* ../dlls/user32/win.c:3869 */
{
	TRACE("Enter SwitchDesktop\n");
	return pSwitchDesktop(hDesktop);
}

extern WINAPI void wine32a_user32_SwitchDesktop(void);  /* ../dlls/user32/win.c:3869 */
__ASM_GLOBAL_FUNC(wine32a_user32_SwitchDesktop,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SwitchDesktop") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_SwitchToThisWindow(HWND  hwnd, BOOL  alt_tab) /* ../dlls/user32/winpos.c:87 */
{
	TRACE("Enter SwitchToThisWindow\n");
	return pSwitchToThisWindow(hwnd, alt_tab);
}

extern WINAPI void wine32a_user32_SwitchToThisWindow(void);  /* ../dlls/user32/winpos.c:87 */
__ASM_GLOBAL_FUNC(wine32a_user32_SwitchToThisWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SwitchToThisWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SystemParametersInfoA(UINT  uiAction, UINT  uiParam, PVOID  pvParam, UINT  fuWinIni) /* ../dlls/user32/sysparams.c:2508 */
{
	TRACE("Enter SystemParametersInfoA\n");
	return pSystemParametersInfoA(uiAction, uiParam, pvParam, fuWinIni);
}

extern WINAPI void wine32a_user32_SystemParametersInfoA(void);  /* ../dlls/user32/sysparams.c:2508 */
__ASM_GLOBAL_FUNC(wine32a_user32_SystemParametersInfoA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SystemParametersInfoA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SystemParametersInfoForDpi(UINT  action, UINT  val, PVOID  ptr, UINT  winini, UINT  dpi) /* ../dlls/user32/sysparams.c:1601 */
{
	TRACE("Enter SystemParametersInfoForDpi\n");
	return pSystemParametersInfoForDpi(action, val, ptr, winini, dpi);
}

extern WINAPI void wine32a_user32_SystemParametersInfoForDpi(void);  /* ../dlls/user32/sysparams.c:1601 */
__ASM_GLOBAL_FUNC(wine32a_user32_SystemParametersInfoForDpi,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SystemParametersInfoForDpi") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_SystemParametersInfoW(UINT  uiAction, UINT  uiParam, PVOID  pvParam, UINT  fWinIni) /* ../dlls/user32/sysparams.c:1676 */
{
	TRACE("Enter SystemParametersInfoW\n");
	return pSystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni);
}

extern WINAPI void wine32a_user32_SystemParametersInfoW(void);  /* ../dlls/user32/sysparams.c:1676 */
__ASM_GLOBAL_FUNC(wine32a_user32_SystemParametersInfoW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_SystemParametersInfoW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_TabbedTextOutA(HDC  hdc, INT  x, INT  y, LPCSTR  lpstr, INT  count, INT  cTabStops, INT*  lpTabPos, INT  nTabOrg) /* ../dlls/user32/text.c:1412 */
{
	TRACE("Enter TabbedTextOutA\n");
	return pTabbedTextOutA(hdc, x, y, lpstr, count, cTabStops, lpTabPos, nTabOrg);
}

extern WINAPI void wine32a_user32_TabbedTextOutA(void);  /* ../dlls/user32/text.c:1412 */
__ASM_GLOBAL_FUNC(wine32a_user32_TabbedTextOutA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TabbedTextOutA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI LONG wine32b_user32_TabbedTextOutW(HDC  hdc, INT  x, INT  y, LPCWSTR  str, INT  count, INT  cTabStops, INT*  lpTabPos, INT  nTabOrg) /* ../dlls/user32/text.c:1454 */
{
	TRACE("Enter TabbedTextOutW\n");
	return pTabbedTextOutW(hdc, x, y, str, count, cTabStops, lpTabPos, nTabOrg);
}

extern WINAPI void wine32a_user32_TabbedTextOutW(void);  /* ../dlls/user32/text.c:1454 */
__ASM_GLOBAL_FUNC(wine32a_user32_TabbedTextOutW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TabbedTextOutW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $32, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_TileChildWindows(HWND  parent, UINT  flags) /* ../dlls/user32/mdi.c:1883 */
{
	TRACE("Enter TileChildWindows\n");
	return pTileChildWindows(parent, flags);
}

extern WINAPI void wine32a_user32_TileChildWindows(void);  /* ../dlls/user32/mdi.c:1883 */
__ASM_GLOBAL_FUNC(wine32a_user32_TileChildWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TileChildWindows") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_TileWindows(HWND  hwndParent, UINT  wFlags, RECT*  lpRect, UINT  cKids, HWND*  lpKids) /* ../dlls/user32/mdi.c:1872 */
{
	TRACE("Enter TileWindows\n");
	return pTileWindows(hwndParent, wFlags, lpRect, cKids, lpKids);
}

extern WINAPI void wine32a_user32_TileWindows(void);  /* ../dlls/user32/mdi.c:1872 */
__ASM_GLOBAL_FUNC(wine32a_user32_TileWindows,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TileWindows") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_ToAscii(UINT  virtKey, UINT  scanCode, BYTE*  lpKeyState, LPWORD  lpChar, UINT  flags) /* ../dlls/user32/input.c:874 */
{
	TRACE("Enter ToAscii\n");
	return pToAscii(virtKey, scanCode, lpKeyState, lpChar, flags);
}

extern WINAPI void wine32a_user32_ToAscii(void);  /* ../dlls/user32/input.c:874 */
__ASM_GLOBAL_FUNC(wine32a_user32_ToAscii,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ToAscii") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_ToAsciiEx(UINT  virtKey, UINT  scanCode, BYTE*  lpKeyState, LPWORD  lpChar, UINT  flags, HKL  dwhkl) /* ../dlls/user32/input.c:883 */
{
	TRACE("Enter ToAsciiEx\n");
	return pToAsciiEx(virtKey, scanCode, lpKeyState, lpChar, flags, dwhkl);
}

extern WINAPI void wine32a_user32_ToAsciiEx(void);  /* ../dlls/user32/input.c:883 */
__ASM_GLOBAL_FUNC(wine32a_user32_ToAsciiEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ToAsciiEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_ToUnicode(UINT  virtKey, UINT  scanCode, BYTE*  lpKeyState, LPWSTR  lpwStr, int  size, UINT  flags) /* ../dlls/user32/input.c:855 */
{
	TRACE("Enter ToUnicode\n");
	return pToUnicode(virtKey, scanCode, lpKeyState, lpwStr, size, flags);
}

extern WINAPI void wine32a_user32_ToUnicode(void);  /* ../dlls/user32/input.c:855 */
__ASM_GLOBAL_FUNC(wine32a_user32_ToUnicode,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ToUnicode") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_ToUnicodeEx(UINT  virtKey, UINT  scanCode, BYTE*  lpKeyState, LPWSTR  lpwStr, int  size, UINT  flags, HKL  hkl) /* ../dlls/user32/input.c:864 */
{
	TRACE("Enter ToUnicodeEx\n");
	return pToUnicodeEx(virtKey, scanCode, lpKeyState, lpwStr, size, flags, hkl);
}

extern WINAPI void wine32a_user32_ToUnicodeEx(void);  /* ../dlls/user32/input.c:864 */
__ASM_GLOBAL_FUNC(wine32a_user32_ToUnicodeEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ToUnicodeEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_TrackMouseEvent(TRACKMOUSEEVENT*  ptme) /* ../dlls/user32/input.c:1175 */
{
	TRACE("Enter TrackMouseEvent\n");
	return pTrackMouseEvent(ptme);
}

extern WINAPI void wine32a_user32_TrackMouseEvent(void);  /* ../dlls/user32/input.c:1175 */
__ASM_GLOBAL_FUNC(wine32a_user32_TrackMouseEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TrackMouseEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_TrackPopupMenu(HMENU  hMenu, UINT  wFlags, INT  x, INT  y, INT  nReserved, HWND  hWnd, RECT*  lpRect) /* ../dlls/user32/menu.c:3562 */
{
	TRACE("Enter TrackPopupMenu\n");
	return pTrackPopupMenu(hMenu, wFlags, x, y, nReserved, hWnd, lpRect);
}

extern WINAPI void wine32a_user32_TrackPopupMenu(void);  /* ../dlls/user32/menu.c:3562 */
__ASM_GLOBAL_FUNC(wine32a_user32_TrackPopupMenu,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TrackPopupMenu") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $28, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_TrackPopupMenuEx(HMENU  hMenu, UINT  wFlags, INT  x, INT  y, HWND  hWnd, LPTPMPARAMS  lpTpm) /* ../dlls/user32/menu.c:3498 */
{
	TRACE("Enter TrackPopupMenuEx\n");
	return pTrackPopupMenuEx(hMenu, wFlags, x, y, hWnd, lpTpm);
}

extern WINAPI void wine32a_user32_TrackPopupMenuEx(void);  /* ../dlls/user32/menu.c:3498 */
__ASM_GLOBAL_FUNC(wine32a_user32_TrackPopupMenuEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TrackPopupMenuEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $24, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_TranslateAcceleratorA(HWND  hWnd, HACCEL  hAccel, LPMSG  msg) /* ../dlls/user32/menu.c:5673 */
{
	TRACE("Enter TranslateAcceleratorA\n");
	return pTranslateAcceleratorA(hWnd, hAccel, msg);
}

extern WINAPI void wine32a_user32_TranslateAcceleratorA(void);  /* ../dlls/user32/menu.c:5673 */
__ASM_GLOBAL_FUNC(wine32a_user32_TranslateAcceleratorA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TranslateAcceleratorA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_TranslateAcceleratorW(HWND  hWnd, HACCEL  hAccel, LPMSG  msg) /* ../dlls/user32/menu.c:5700 */
{
	TRACE("Enter TranslateAcceleratorW\n");
	return pTranslateAcceleratorW(hWnd, hAccel, msg);
}

extern WINAPI void wine32a_user32_TranslateAcceleratorW(void);  /* ../dlls/user32/menu.c:5700 */
__ASM_GLOBAL_FUNC(wine32a_user32_TranslateAcceleratorW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TranslateAcceleratorW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_TranslateMDISysAccel(HWND  hwndClient, LPMSG  msg) /* ../dlls/user32/mdi.c:1645 */
{
	TRACE("Enter TranslateMDISysAccel\n");
	return pTranslateMDISysAccel(hwndClient, msg);
}

extern WINAPI void wine32a_user32_TranslateMDISysAccel(void);  /* ../dlls/user32/mdi.c:1645 */
__ASM_GLOBAL_FUNC(wine32a_user32_TranslateMDISysAccel,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TranslateMDISysAccel") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_TranslateMessage(MSG*  msg) /* ../dlls/user32/message.c:3903 */
{
	TRACE("Enter TranslateMessage\n");
	return pTranslateMessage(msg);
}

extern WINAPI void wine32a_user32_TranslateMessage(void);  /* ../dlls/user32/message.c:3903 */
__ASM_GLOBAL_FUNC(wine32a_user32_TranslateMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_TranslateMessage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnhookWinEvent(HWINEVENTHOOK  hEventHook) /* ../dlls/user32/hook.c:776 */
{
	TRACE("Enter UnhookWinEvent\n");
	return pUnhookWinEvent(hEventHook);
}

extern WINAPI void wine32a_user32_UnhookWinEvent(void);  /* ../dlls/user32/hook.c:776 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnhookWinEvent,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnhookWinEvent") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnhookWindowsHook(INT  id, HOOKPROC  proc) /* ../dlls/user32/hook.c:560 */
{
	TRACE("Enter UnhookWindowsHook\n");
	return pUnhookWindowsHook(id, proc);
}

extern WINAPI void wine32a_user32_UnhookWindowsHook(void);  /* ../dlls/user32/hook.c:560 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnhookWindowsHook,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnhookWindowsHook") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnhookWindowsHookEx(HHOOK  hhook) /* ../dlls/user32/hook.c:584 */
{
	TRACE("Enter UnhookWindowsHookEx\n");
	return pUnhookWindowsHookEx(hhook);
}

extern WINAPI void wine32a_user32_UnhookWindowsHookEx(void);  /* ../dlls/user32/hook.c:584 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnhookWindowsHookEx,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnhookWindowsHookEx") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnionRect(LPRECT  dest, RECT*  src1, RECT*  src2) /* ../dlls/user32/uitools.c:1356 */
{
	TRACE("Enter UnionRect\n");
	return pUnionRect(dest, src1, src2);
}

extern WINAPI void wine32a_user32_UnionRect(void);  /* ../dlls/user32/uitools.c:1356 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnionRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnionRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnloadKeyboardLayout(HKL  hkl) /* ../dlls/user32/input.c:1024 */
{
	TRACE("Enter UnloadKeyboardLayout\n");
	return pUnloadKeyboardLayout(hkl);
}

extern WINAPI void wine32a_user32_UnloadKeyboardLayout(void);  /* ../dlls/user32/input.c:1024 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnloadKeyboardLayout,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnloadKeyboardLayout") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnpackDDElParam(UINT  msg, LPARAM  lParam, PUINT_PTR  uiLo, PUINT_PTR  uiHi) /* ../dlls/user32/dde_misc.c:118 */
{
	TRACE("Enter UnpackDDElParam\n");
	return pUnpackDDElParam(msg, lParam, uiLo, uiHi);
}

extern WINAPI void wine32a_user32_UnpackDDElParam(void);  /* ../dlls/user32/dde_misc.c:118 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnpackDDElParam,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnpackDDElParam") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnregisterClassA(LPCSTR  className, HINSTANCE  hInstance) /* ../dlls/user32/class.c:781 */
{
	TRACE("Enter UnregisterClassA\n");
	return pUnregisterClassA(className, hInstance);
}

extern WINAPI void wine32a_user32_UnregisterClassA(void);  /* ../dlls/user32/class.c:781 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnregisterClassA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnregisterClassA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnregisterClassW(LPCWSTR  className, HINSTANCE  hInstance) /* ../dlls/user32/class.c:797 */
{
	TRACE("Enter UnregisterClassW\n");
	return pUnregisterClassW(className, hInstance);
}

extern WINAPI void wine32a_user32_UnregisterClassW(void);  /* ../dlls/user32/class.c:797 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnregisterClassW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnregisterClassW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnregisterDeviceNotification(HDEVNOTIFY  hnd) /* ../dlls/user32/misc.c:338 */
{
	TRACE("Enter UnregisterDeviceNotification\n");
	return pUnregisterDeviceNotification(hnd);
}

extern WINAPI void wine32a_user32_UnregisterDeviceNotification(void);  /* ../dlls/user32/misc.c:338 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnregisterDeviceNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnregisterDeviceNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnregisterHotKey(HWND  hwnd, INT  id) /* ../dlls/user32/input.c:969 */
{
	TRACE("Enter UnregisterHotKey\n");
	return pUnregisterHotKey(hwnd, id);
}

extern WINAPI void wine32a_user32_UnregisterHotKey(void);  /* ../dlls/user32/input.c:969 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnregisterHotKey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnregisterHotKey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnregisterPowerSettingNotification(HPOWERNOTIFY  handle) /* ../dlls/user32/misc.c:504 */
{
	TRACE("Enter UnregisterPowerSettingNotification\n");
	return pUnregisterPowerSettingNotification(handle);
}

extern WINAPI void wine32a_user32_UnregisterPowerSettingNotification(void);  /* ../dlls/user32/misc.c:504 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnregisterPowerSettingNotification,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnregisterPowerSettingNotification") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UnregisterTouchWindow(HWND  hwnd) /* ../dlls/user32/win.c:4163 */
{
	TRACE("Enter UnregisterTouchWindow\n");
	return pUnregisterTouchWindow(hwnd);
}

extern WINAPI void wine32a_user32_UnregisterTouchWindow(void);  /* ../dlls/user32/win.c:4163 */
__ASM_GLOBAL_FUNC(wine32a_user32_UnregisterTouchWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UnregisterTouchWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UpdateLayeredWindow(HWND  hwnd, HDC  hdcDst, POINT*  pptDst, SIZE*  psize, HDC  hdcSrc, POINT*  pptSrc, COLORREF  crKey, BLENDFUNCTION*  pblend, DWORD  flags) /* ../dlls/user32/win.c:4011 */
{
	TRACE("Enter UpdateLayeredWindow\n");
	return pUpdateLayeredWindow(hwnd, hdcDst, pptDst, psize, hdcSrc, pptSrc, crKey, pblend, flags);
}

extern WINAPI void wine32a_user32_UpdateLayeredWindow(void);  /* ../dlls/user32/win.c:4011 */
__ASM_GLOBAL_FUNC(wine32a_user32_UpdateLayeredWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UpdateLayeredWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $36, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UpdateLayeredWindowIndirect(HWND  hwnd, UPDATELAYEREDWINDOWINFO*  info) /* ../dlls/user32/win.c:3951 */
{
	TRACE("Enter UpdateLayeredWindowIndirect\n");
	return pUpdateLayeredWindowIndirect(hwnd, info);
}

extern WINAPI void wine32a_user32_UpdateLayeredWindowIndirect(void);  /* ../dlls/user32/win.c:3951 */
__ASM_GLOBAL_FUNC(wine32a_user32_UpdateLayeredWindowIndirect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UpdateLayeredWindowIndirect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UpdateWindow(HWND  hwnd) /* ../dlls/user32/painting.c:1288 */
{
	TRACE("Enter UpdateWindow\n");
	return pUpdateWindow(hwnd);
}

extern WINAPI void wine32a_user32_UpdateWindow(void);  /* ../dlls/user32/painting.c:1288 */
__ASM_GLOBAL_FUNC(wine32a_user32_UpdateWindow,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UpdateWindow") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_User32InitializeImmEntryTable(DWORD  magic) /* ../dlls/user32/misc.c:389 */
{
	TRACE("Enter User32InitializeImmEntryTable\n");
	return pUser32InitializeImmEntryTable(magic);
}

extern WINAPI void wine32a_user32_User32InitializeImmEntryTable(void);  /* ../dlls/user32/misc.c:389 */
__ASM_GLOBAL_FUNC(wine32a_user32_User32InitializeImmEntryTable,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_User32InitializeImmEntryTable") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UserClientDllInitialize(HINSTANCE  inst, DWORD  reason, LPVOID  reserved) /* ../dlls/user32/user_main.c:396 */
{
	TRACE("Enter UserClientDllInitialize\n");
	return pUserClientDllInitialize(inst, reason, reserved);
}

extern WINAPI void wine32a_user32_UserClientDllInitialize(void);  /* ../dlls/user32/user_main.c:396 */
__ASM_GLOBAL_FUNC(wine32a_user32_UserClientDllInitialize,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UserClientDllInitialize") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_UserHandleGrantAccess(HANDLE  handle, HANDLE  job, BOOL  grant) /* ../dlls/user32/misc.c:486 */
{
	TRACE("Enter UserHandleGrantAccess\n");
	return pUserHandleGrantAccess(handle, job, grant);
}

extern WINAPI void wine32a_user32_UserHandleGrantAccess(void);  /* ../dlls/user32/misc.c:486 */
__ASM_GLOBAL_FUNC(wine32a_user32_UserHandleGrantAccess,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UserHandleGrantAccess") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_UserRealizePalette(HDC  hDC) /* ../dlls/user32/user_main.c:124 */
{
	TRACE("Enter UserRealizePalette\n");
	return pUserRealizePalette(hDC);
}

extern WINAPI void wine32a_user32_UserRealizePalette(void);  /* ../dlls/user32/user_main.c:124 */
__ASM_GLOBAL_FUNC(wine32a_user32_UserRealizePalette,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UserRealizePalette") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_UserRegisterWowHandlers(struct wow_handlers16*  new, struct wow_handlers32*  orig) /* ../dlls/user32/winproc.c:1179 */
{
	TRACE("Enter UserRegisterWowHandlers\n");
	return pUserRegisterWowHandlers(new, orig);
}

extern WINAPI void wine32a_user32_UserRegisterWowHandlers(void);  /* ../dlls/user32/winproc.c:1179 */
__ASM_GLOBAL_FUNC(wine32a_user32_UserRegisterWowHandlers,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UserRegisterWowHandlers") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_UserSignalProc(UINT  uCode, DWORD  dwThreadOrProcessID, DWORD  dwFlags, HMODULE16  hModule) /* ../dlls/user32/misc.c:145 */
{
	TRACE("Enter UserSignalProc\n");
	return pUserSignalProc(uCode, dwThreadOrProcessID, dwFlags, hModule);
}

extern WINAPI void wine32a_user32_UserSignalProc(void);  /* ../dlls/user32/misc.c:145 */
__ASM_GLOBAL_FUNC(wine32a_user32_UserSignalProc,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_UserSignalProc") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ValidateRect(HWND  hwnd, RECT*  rect) /* ../dlls/user32/painting.c:1356 */
{
	TRACE("Enter ValidateRect\n");
	return pValidateRect(hwnd, rect);
}

extern WINAPI void wine32a_user32_ValidateRect(void);  /* ../dlls/user32/painting.c:1356 */
__ASM_GLOBAL_FUNC(wine32a_user32_ValidateRect,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ValidateRect") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_ValidateRgn(HWND  hwnd, HRGN  hrgn) /* ../dlls/user32/painting.c:1338 */
{
	TRACE("Enter ValidateRgn\n");
	return pValidateRgn(hwnd, hrgn);
}

extern WINAPI void wine32a_user32_ValidateRgn(void);  /* ../dlls/user32/painting.c:1338 */
__ASM_GLOBAL_FUNC(wine32a_user32_ValidateRgn,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_ValidateRgn") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SHORT wine32b_user32_VkKeyScanA(CHAR  cChar) /* ../dlls/user32/input.c:627 */
{
	TRACE("Enter VkKeyScanA\n");
	return pVkKeyScanA(cChar);
}

extern WINAPI void wine32a_user32_VkKeyScanA(void);  /* ../dlls/user32/input.c:627 */
__ASM_GLOBAL_FUNC(wine32a_user32_VkKeyScanA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_VkKeyScanA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_VkKeyScanExA(CHAR  cChar, HKL  dwhkl) /* ../dlls/user32/input.c:648 */
{
	TRACE("Enter VkKeyScanExA\n");
	return pVkKeyScanExA(cChar, dwhkl);
}

extern WINAPI void wine32a_user32_VkKeyScanExA(void);  /* ../dlls/user32/input.c:648 */
__ASM_GLOBAL_FUNC(wine32a_user32_VkKeyScanExA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_VkKeyScanExA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI WORD wine32b_user32_VkKeyScanExW(WCHAR  cChar, HKL  dwhkl) /* ../dlls/user32/input.c:661 */
{
	TRACE("Enter VkKeyScanExW\n");
	return pVkKeyScanExW(cChar, dwhkl);
}

extern WINAPI void wine32a_user32_VkKeyScanExW(void);  /* ../dlls/user32/input.c:661 */
__ASM_GLOBAL_FUNC(wine32a_user32_VkKeyScanExW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_VkKeyScanExW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI SHORT wine32b_user32_VkKeyScanW(WCHAR  cChar) /* ../dlls/user32/input.c:640 */
{
	TRACE("Enter VkKeyScanW\n");
	return pVkKeyScanW(cChar);
}

extern WINAPI void wine32a_user32_VkKeyScanW(void);  /* ../dlls/user32/input.c:640 */
__ASM_GLOBAL_FUNC(wine32a_user32_VkKeyScanW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_VkKeyScanW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_WINNLSEnableIME(HWND  hwnd, BOOL  enable) /* ../dlls/user32/misc.c:433 */
{
	TRACE("Enter WINNLSEnableIME\n");
	return pWINNLSEnableIME(hwnd, enable);
}

extern WINAPI void wine32a_user32_WINNLSEnableIME(void);  /* ../dlls/user32/misc.c:433 */
__ASM_GLOBAL_FUNC(wine32a_user32_WINNLSEnableIME,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_WINNLSEnableIME") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_WINNLSGetEnableStatus(HWND  hwnd) /* ../dlls/user32/misc.c:443 */
{
	TRACE("Enter WINNLSGetEnableStatus\n");
	return pWINNLSGetEnableStatus(hwnd);
}

extern WINAPI void wine32a_user32_WINNLSGetEnableStatus(void);  /* ../dlls/user32/misc.c:443 */
__ASM_GLOBAL_FUNC(wine32a_user32_WINNLSGetEnableStatus,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_WINNLSGetEnableStatus") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI UINT wine32b_user32_WINNLSGetIMEHotkey(HWND  hwnd) /* ../dlls/user32/misc.c:423 */
{
	TRACE("Enter WINNLSGetIMEHotkey\n");
	return pWINNLSGetIMEHotkey(hwnd);
}

extern WINAPI void wine32a_user32_WINNLSGetIMEHotkey(void);  /* ../dlls/user32/misc.c:423 */
__ASM_GLOBAL_FUNC(wine32a_user32_WINNLSGetIMEHotkey,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_WINNLSGetIMEHotkey") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI DWORD wine32b_user32_WaitForInputIdle(HANDLE  hProcess, DWORD  dwTimeOut) /* ../dlls/user32/message.c:4209 */
{
	TRACE("Enter WaitForInputIdle\n");
	return pWaitForInputIdle(hProcess, dwTimeOut);
}

extern WINAPI void wine32a_user32_WaitForInputIdle(void);  /* ../dlls/user32/message.c:4209 */
__ASM_GLOBAL_FUNC(wine32a_user32_WaitForInputIdle,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_WaitForInputIdle") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_WaitMessage(void) /* ../dlls/user32/message.c:4165 */
{
	TRACE("Enter WaitMessage\n");
	return pWaitMessage();
}

extern WINAPI void wine32a_user32_WaitMessage(void);  /* ../dlls/user32/message.c:4165 */
__ASM_GLOBAL_FUNC(wine32a_user32_WaitMessage,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_WaitMessage") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $0, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_WinHelpA(HWND  hWnd, LPCSTR  lpHelpFile, UINT  wCommand, ULONG_PTR  dwData) /* ../dlls/user32/winhelp.c:77 */
{
	TRACE("Enter WinHelpA\n");
	return pWinHelpA(hWnd, lpHelpFile, wCommand, dwData);
}

extern WINAPI void wine32a_user32_WinHelpA(void);  /* ../dlls/user32/winhelp.c:77 */
__ASM_GLOBAL_FUNC(wine32a_user32_WinHelpA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_WinHelpA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32_WinHelpW(HWND  hWnd, LPCWSTR  helpFile, UINT  command, ULONG_PTR  dwData) /* ../dlls/user32/winhelp.c:169 */
{
	TRACE("Enter WinHelpW\n");
	return pWinHelpW(hWnd, helpFile, command, dwData);
}

extern WINAPI void wine32a_user32_WinHelpW(void);  /* ../dlls/user32/winhelp.c:169 */
__ASM_GLOBAL_FUNC(wine32a_user32_WinHelpW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_WinHelpW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_WindowFromDC(HDC  hdc) /* ../dlls/user32/painting.c:1169 */
{
	TRACE("Enter WindowFromDC\n");
	return pWindowFromDC(hdc);
}

extern WINAPI void wine32a_user32_WindowFromDC(void);  /* ../dlls/user32/painting.c:1169 */
__ASM_GLOBAL_FUNC(wine32a_user32_WindowFromDC,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_WindowFromDC") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI HWND wine32b_user32_WindowFromPoint(POINT  pt) /* ../dlls/user32/winpos.c:338 */
{
	TRACE("Enter WindowFromPoint\n");
	return pWindowFromPoint(pt);
}

extern WINAPI void wine32a_user32_WindowFromPoint(void);  /* ../dlls/user32/winpos.c:338 */
__ASM_GLOBAL_FUNC(wine32a_user32_WindowFromPoint,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_WindowFromPoint") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $4, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_keybd_event(BYTE  bVk, BYTE  bScan, DWORD  dwFlags, ULONG_PTR  dwExtraInfo) /* ../dlls/user32/input.c:213 */
{
	TRACE("Enter keybd_event\n");
	return pkeybd_event(bVk, bScan, dwFlags, dwExtraInfo);
}

extern WINAPI void wine32a_user32_keybd_event(void);  /* ../dlls/user32/input.c:213 */
__ASM_GLOBAL_FUNC(wine32a_user32_keybd_event,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_keybd_event") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $16, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI void wine32b_user32_mouse_event(DWORD  dwFlags, DWORD  dx, DWORD  dy, DWORD  dwData, ULONG_PTR  dwExtraInfo) /* ../dlls/user32/input.c:231 */
{
	TRACE("Enter mouse_event\n");
	return pmouse_event(dwFlags, dx, dy, dwData, dwExtraInfo);
}

extern WINAPI void wine32a_user32_mouse_event(void);  /* ../dlls/user32/input.c:231 */
__ASM_GLOBAL_FUNC(wine32a_user32_mouse_event,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"movl 0x20(%rsp), %r9d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_mouse_event") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $20, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_wsprintfA(LPSTR  buffer, LPCSTR  spec) /* ../dlls/user32/wsprintf.c:543 */
{
	TRACE("Enter wsprintfA\n");
	return pwsprintfA(buffer, spec);
}

extern WINAPI void wine32a_user32_wsprintfA(void);  /* ../dlls/user32/wsprintf.c:543 */
__ASM_GLOBAL_FUNC(wine32a_user32_wsprintfA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_wsprintfA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_wsprintfW(LPWSTR  buffer, LPCWSTR  spec) /* ../dlls/user32/wsprintf.c:558 */
{
	TRACE("Enter wsprintfW\n");
	return pwsprintfW(buffer, spec);
}

extern WINAPI void wine32a_user32_wsprintfW(void);  /* ../dlls/user32/wsprintf.c:558 */
__ASM_GLOBAL_FUNC(wine32a_user32_wsprintfW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_wsprintfW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_wvsprintfA(LPSTR  buffer, LPCSTR  spec, __builtin_ms_va_list  args) /* ../dlls/user32/wsprintf.c:523 */
{
	TRACE("Enter wvsprintfA\n");
	return pwvsprintfA(buffer, spec, args);
}

extern WINAPI void wine32a_user32_wvsprintfA(void);  /* ../dlls/user32/wsprintf.c:523 */
__ASM_GLOBAL_FUNC(wine32a_user32_wvsprintfA,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_wvsprintfA") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI INT wine32b_user32_wvsprintfW(LPWSTR  buffer, LPCWSTR  spec, __builtin_ms_va_list  args) /* ../dlls/user32/wsprintf.c:533 */
{
	TRACE("Enter wvsprintfW\n");
	return pwvsprintfW(buffer, spec, args);
}

extern WINAPI void wine32a_user32_wvsprintfW(void);  /* ../dlls/user32/wsprintf.c:533 */
__ASM_GLOBAL_FUNC(wine32a_user32_wvsprintfW,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"movl 0x1C(%rsp), %r8d \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32_wvsprintfW") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $12, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32___wine_send_input(HWND  hwnd, INPUT*  input) /* ../dlls/user32/input.c:125 */
{
	TRACE("Enter __wine_send_input\n");
	return p__wine_send_input(hwnd, input);
}

extern WINAPI void wine32a_user32___wine_send_input(void);  /* ../dlls/user32/input.c:125 */
__ASM_GLOBAL_FUNC(wine32a_user32___wine_send_input,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32___wine_send_input") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

extern WINAPI BOOL wine32b_user32___wine_set_pixel_format(HWND  hwnd, int  format) /* ../dlls/user32/win.c:3879 */
{
	TRACE("Enter __wine_set_pixel_format\n");
	return p__wine_set_pixel_format(hwnd, format);
}

extern WINAPI void wine32a_user32___wine_set_pixel_format(void);  /* ../dlls/user32/win.c:3879 */
__ASM_GLOBAL_FUNC(wine32a_user32___wine_set_pixel_format,
	"push %rbp \n"
	"mov %rsp, %rbp \n"
	"movl 0x14(%rsp), %ecx \n"
	"movl 0x18(%rsp), %edx \n"
	"sub $0x100, %rsp \n"
	"call " __ASM_NAME("wine32b_user32___wine_set_pixel_format") "\n"
	"add $0x100, %rsp \n"
	"pop %rbp \n"
	"movl 0x00(%rsp), %ecx \n"
	"movl 0x04(%rsp), %edx \n"
	"movl 0x08(%rsp), %r8d \n"
	"addq $8, %rsp \n"
	"movl %ecx, 0x00(%rsp) \n"
	"movl %edx, 0x04(%rsp) \n"
	"movl %r8d, 0x08(%rsp) \n"
	"ret \n"
)

static BOOL initialized = FALSE;

void wine_thunk_initialize_user32(void)
{
	HMODULE library = LoadLibraryA("user32.dll");
	pActivateKeyboardLayout = (void *)GetProcAddress(library, "ActivateKeyboardLayout");
	pAddClipboardFormatListener = (void *)GetProcAddress(library, "AddClipboardFormatListener");
	pAdjustWindowRect = (void *)GetProcAddress(library, "AdjustWindowRect");
	pAdjustWindowRectEx = (void *)GetProcAddress(library, "AdjustWindowRectEx");
	pAdjustWindowRectExForDpi = (void *)GetProcAddress(library, "AdjustWindowRectExForDpi");
	pAlignRects = (void *)GetProcAddress(library, "AlignRects");
	pAllowSetForegroundWindow = (void *)GetProcAddress(library, "AllowSetForegroundWindow");
	pAnimateWindow = (void *)GetProcAddress(library, "AnimateWindow");
	pAnyPopup = (void *)GetProcAddress(library, "AnyPopup");
	pAppendMenuA = (void *)GetProcAddress(library, "AppendMenuA");
	pAppendMenuW = (void *)GetProcAddress(library, "AppendMenuW");
	pAreDpiAwarenessContextsEqual = (void *)GetProcAddress(library, "AreDpiAwarenessContextsEqual");
	pArrangeIconicWindows = (void *)GetProcAddress(library, "ArrangeIconicWindows");
	pAttachThreadInput = (void *)GetProcAddress(library, "AttachThreadInput");
	pBeginDeferWindowPos = (void *)GetProcAddress(library, "BeginDeferWindowPos");
	pBeginPaint = (void *)GetProcAddress(library, "BeginPaint");
	pBlockInput = (void *)GetProcAddress(library, "BlockInput");
	pBringWindowToTop = (void *)GetProcAddress(library, "BringWindowToTop");
	pBroadcastSystemMessageA = (void *)GetProcAddress(library, "BroadcastSystemMessageA");
	pBroadcastSystemMessageExA = (void *)GetProcAddress(library, "BroadcastSystemMessageExA");
	pBroadcastSystemMessageExW = (void *)GetProcAddress(library, "BroadcastSystemMessageExW");
	pBroadcastSystemMessageW = (void *)GetProcAddress(library, "BroadcastSystemMessageW");
	pCalcChildScroll = (void *)GetProcAddress(library, "CalcChildScroll");
	pCalcMenuBar = (void *)GetProcAddress(library, "CalcMenuBar");
	pCallMsgFilterA = (void *)GetProcAddress(library, "CallMsgFilterA");
	pCallMsgFilterW = (void *)GetProcAddress(library, "CallMsgFilterW");
	pCallNextHookEx = (void *)GetProcAddress(library, "CallNextHookEx");
	pCallWindowProcA = (void *)GetProcAddress(library, "CallWindowProcA");
	pCallWindowProcW = (void *)GetProcAddress(library, "CallWindowProcW");
	pCascadeChildWindows = (void *)GetProcAddress(library, "CascadeChildWindows");
	pCascadeWindows = (void *)GetProcAddress(library, "CascadeWindows");
	pChangeClipboardChain = (void *)GetProcAddress(library, "ChangeClipboardChain");
	pChangeDisplaySettingsA = (void *)GetProcAddress(library, "ChangeDisplaySettingsA");
	pChangeDisplaySettingsExA = (void *)GetProcAddress(library, "ChangeDisplaySettingsExA");
	pChangeDisplaySettingsExW = (void *)GetProcAddress(library, "ChangeDisplaySettingsExW");
	pChangeDisplaySettingsW = (void *)GetProcAddress(library, "ChangeDisplaySettingsW");
	pChangeMenuA = (void *)GetProcAddress(library, "ChangeMenuA");
	pChangeMenuW = (void *)GetProcAddress(library, "ChangeMenuW");
	pChangeWindowMessageFilter = (void *)GetProcAddress(library, "ChangeWindowMessageFilter");
	pChangeWindowMessageFilterEx = (void *)GetProcAddress(library, "ChangeWindowMessageFilterEx");
	pCharLowerA = (void *)GetProcAddress(library, "CharLowerA");
	pCharLowerBuffA = (void *)GetProcAddress(library, "CharLowerBuffA");
	pCharLowerBuffW = (void *)GetProcAddress(library, "CharLowerBuffW");
	pCharLowerW = (void *)GetProcAddress(library, "CharLowerW");
	pCharNextA = (void *)GetProcAddress(library, "CharNextA");
	pCharNextExA = (void *)GetProcAddress(library, "CharNextExA");
	pCharNextExW = (void *)GetProcAddress(library, "CharNextExW");
	pCharNextW = (void *)GetProcAddress(library, "CharNextW");
	pCharPrevA = (void *)GetProcAddress(library, "CharPrevA");
	pCharPrevExA = (void *)GetProcAddress(library, "CharPrevExA");
	pCharPrevExW = (void *)GetProcAddress(library, "CharPrevExW");
	pCharPrevW = (void *)GetProcAddress(library, "CharPrevW");
	pCharToOemA = (void *)GetProcAddress(library, "CharToOemA");
	pCharToOemBuffA = (void *)GetProcAddress(library, "CharToOemBuffA");
	pCharToOemBuffW = (void *)GetProcAddress(library, "CharToOemBuffW");
	pCharToOemW = (void *)GetProcAddress(library, "CharToOemW");
	pCharUpperA = (void *)GetProcAddress(library, "CharUpperA");
	pCharUpperBuffA = (void *)GetProcAddress(library, "CharUpperBuffA");
	pCharUpperBuffW = (void *)GetProcAddress(library, "CharUpperBuffW");
	pCharUpperW = (void *)GetProcAddress(library, "CharUpperW");
	pCheckDlgButton = (void *)GetProcAddress(library, "CheckDlgButton");
	pCheckMenuItem = (void *)GetProcAddress(library, "CheckMenuItem");
	pCheckMenuRadioItem = (void *)GetProcAddress(library, "CheckMenuRadioItem");
	pCheckRadioButton = (void *)GetProcAddress(library, "CheckRadioButton");
	pChildWindowFromPoint = (void *)GetProcAddress(library, "ChildWindowFromPoint");
	pChildWindowFromPointEx = (void *)GetProcAddress(library, "ChildWindowFromPointEx");
	pClientToScreen = (void *)GetProcAddress(library, "ClientToScreen");
	pClipCursor = (void *)GetProcAddress(library, "ClipCursor");
	pCloseClipboard = (void *)GetProcAddress(library, "CloseClipboard");
	pCloseDesktop = (void *)GetProcAddress(library, "CloseDesktop");
	pCloseTouchInputHandle = (void *)GetProcAddress(library, "CloseTouchInputHandle");
	pCloseWindow = (void *)GetProcAddress(library, "CloseWindow");
	pCloseWindowStation = (void *)GetProcAddress(library, "CloseWindowStation");
	pCopyAcceleratorTableA = (void *)GetProcAddress(library, "CopyAcceleratorTableA");
	pCopyAcceleratorTableW = (void *)GetProcAddress(library, "CopyAcceleratorTableW");
	pCopyIcon = (void *)GetProcAddress(library, "CopyIcon");
	pCopyImage = (void *)GetProcAddress(library, "CopyImage");
	pCopyRect = (void *)GetProcAddress(library, "CopyRect");
	pCountClipboardFormats = (void *)GetProcAddress(library, "CountClipboardFormats");
	pCreateAcceleratorTableA = (void *)GetProcAddress(library, "CreateAcceleratorTableA");
	pCreateAcceleratorTableW = (void *)GetProcAddress(library, "CreateAcceleratorTableW");
	pCreateCaret = (void *)GetProcAddress(library, "CreateCaret");
	pCreateCursor = (void *)GetProcAddress(library, "CreateCursor");
	pCreateDesktopA = (void *)GetProcAddress(library, "CreateDesktopA");
	pCreateDesktopW = (void *)GetProcAddress(library, "CreateDesktopW");
	pCreateDialogIndirectParamA = (void *)GetProcAddress(library, "CreateDialogIndirectParamA");
	pCreateDialogIndirectParamAorW = (void *)GetProcAddress(library, "CreateDialogIndirectParamAorW");
	pCreateDialogIndirectParamW = (void *)GetProcAddress(library, "CreateDialogIndirectParamW");
	pCreateDialogParamA = (void *)GetProcAddress(library, "CreateDialogParamA");
	pCreateDialogParamW = (void *)GetProcAddress(library, "CreateDialogParamW");
	pCreateIcon = (void *)GetProcAddress(library, "CreateIcon");
	pCreateIconFromResource = (void *)GetProcAddress(library, "CreateIconFromResource");
	pCreateIconFromResourceEx = (void *)GetProcAddress(library, "CreateIconFromResourceEx");
	pCreateIconIndirect = (void *)GetProcAddress(library, "CreateIconIndirect");
	pCreateMDIWindowA = (void *)GetProcAddress(library, "CreateMDIWindowA");
	pCreateMDIWindowW = (void *)GetProcAddress(library, "CreateMDIWindowW");
	pCreateMenu = (void *)GetProcAddress(library, "CreateMenu");
	pCreatePopupMenu = (void *)GetProcAddress(library, "CreatePopupMenu");
	pCreateWindowExA = (void *)GetProcAddress(library, "CreateWindowExA");
	pCreateWindowExW = (void *)GetProcAddress(library, "CreateWindowExW");
	pCreateWindowStationA = (void *)GetProcAddress(library, "CreateWindowStationA");
	pCreateWindowStationW = (void *)GetProcAddress(library, "CreateWindowStationW");
	pDdeAbandonTransaction = (void *)GetProcAddress(library, "DdeAbandonTransaction");
	pDdeAccessData = (void *)GetProcAddress(library, "DdeAccessData");
	pDdeAddData = (void *)GetProcAddress(library, "DdeAddData");
	pDdeClientTransaction = (void *)GetProcAddress(library, "DdeClientTransaction");
	pDdeCmpStringHandles = (void *)GetProcAddress(library, "DdeCmpStringHandles");
	pDdeConnect = (void *)GetProcAddress(library, "DdeConnect");
	pDdeConnectList = (void *)GetProcAddress(library, "DdeConnectList");
	pDdeCreateDataHandle = (void *)GetProcAddress(library, "DdeCreateDataHandle");
	pDdeCreateStringHandleA = (void *)GetProcAddress(library, "DdeCreateStringHandleA");
	pDdeCreateStringHandleW = (void *)GetProcAddress(library, "DdeCreateStringHandleW");
	pDdeDisconnect = (void *)GetProcAddress(library, "DdeDisconnect");
	pDdeDisconnectList = (void *)GetProcAddress(library, "DdeDisconnectList");
	pDdeEnableCallback = (void *)GetProcAddress(library, "DdeEnableCallback");
	pDdeFreeDataHandle = (void *)GetProcAddress(library, "DdeFreeDataHandle");
	pDdeFreeStringHandle = (void *)GetProcAddress(library, "DdeFreeStringHandle");
	pDdeGetData = (void *)GetProcAddress(library, "DdeGetData");
	pDdeGetLastError = (void *)GetProcAddress(library, "DdeGetLastError");
	pDdeImpersonateClient = (void *)GetProcAddress(library, "DdeImpersonateClient");
	pDdeInitializeA = (void *)GetProcAddress(library, "DdeInitializeA");
	pDdeInitializeW = (void *)GetProcAddress(library, "DdeInitializeW");
	pDdeKeepStringHandle = (void *)GetProcAddress(library, "DdeKeepStringHandle");
	pDdeNameService = (void *)GetProcAddress(library, "DdeNameService");
	pDdePostAdvise = (void *)GetProcAddress(library, "DdePostAdvise");
	pDdeQueryConvInfo = (void *)GetProcAddress(library, "DdeQueryConvInfo");
	pDdeQueryNextServer = (void *)GetProcAddress(library, "DdeQueryNextServer");
	pDdeQueryStringA = (void *)GetProcAddress(library, "DdeQueryStringA");
	pDdeQueryStringW = (void *)GetProcAddress(library, "DdeQueryStringW");
	pDdeReconnect = (void *)GetProcAddress(library, "DdeReconnect");
	pDdeSetQualityOfService = (void *)GetProcAddress(library, "DdeSetQualityOfService");
	pDdeSetUserHandle = (void *)GetProcAddress(library, "DdeSetUserHandle");
	pDdeUnaccessData = (void *)GetProcAddress(library, "DdeUnaccessData");
	pDdeUninitialize = (void *)GetProcAddress(library, "DdeUninitialize");
	pDefDlgProcA = (void *)GetProcAddress(library, "DefDlgProcA");
	pDefDlgProcW = (void *)GetProcAddress(library, "DefDlgProcW");
	pDefFrameProcA = (void *)GetProcAddress(library, "DefFrameProcA");
	pDefFrameProcW = (void *)GetProcAddress(library, "DefFrameProcW");
	pDefMDIChildProcA = (void *)GetProcAddress(library, "DefMDIChildProcA");
	pDefMDIChildProcW = (void *)GetProcAddress(library, "DefMDIChildProcW");
	pDefRawInputProc = (void *)GetProcAddress(library, "DefRawInputProc");
	pDefWindowProcA = (void *)GetProcAddress(library, "DefWindowProcA");
	pDefWindowProcW = (void *)GetProcAddress(library, "DefWindowProcW");
	pDeferWindowPos = (void *)GetProcAddress(library, "DeferWindowPos");
	pDeleteMenu = (void *)GetProcAddress(library, "DeleteMenu");
	pDeregisterShellHookWindow = (void *)GetProcAddress(library, "DeregisterShellHookWindow");
	pDestroyAcceleratorTable = (void *)GetProcAddress(library, "DestroyAcceleratorTable");
	pDestroyCaret = (void *)GetProcAddress(library, "DestroyCaret");
	pDestroyCursor = (void *)GetProcAddress(library, "DestroyCursor");
	pDestroyIcon = (void *)GetProcAddress(library, "DestroyIcon");
	pDestroyMenu = (void *)GetProcAddress(library, "DestroyMenu");
	pDestroyWindow = (void *)GetProcAddress(library, "DestroyWindow");
	pDialogBoxIndirectParamA = (void *)GetProcAddress(library, "DialogBoxIndirectParamA");
	pDialogBoxIndirectParamAorW = (void *)GetProcAddress(library, "DialogBoxIndirectParamAorW");
	pDialogBoxIndirectParamW = (void *)GetProcAddress(library, "DialogBoxIndirectParamW");
	pDialogBoxParamA = (void *)GetProcAddress(library, "DialogBoxParamA");
	pDialogBoxParamW = (void *)GetProcAddress(library, "DialogBoxParamW");
	pDisableProcessWindowsGhosting = (void *)GetProcAddress(library, "DisableProcessWindowsGhosting");
	pDispatchMessageA = (void *)GetProcAddress(library, "DispatchMessageA");
	pDispatchMessageW = (void *)GetProcAddress(library, "DispatchMessageW");
	pDisplayConfigGetDeviceInfo = (void *)GetProcAddress(library, "DisplayConfigGetDeviceInfo");
	pDlgDirListA = (void *)GetProcAddress(library, "DlgDirListA");
	pDlgDirListComboBoxA = (void *)GetProcAddress(library, "DlgDirListComboBoxA");
	pDlgDirListComboBoxW = (void *)GetProcAddress(library, "DlgDirListComboBoxW");
	pDlgDirListW = (void *)GetProcAddress(library, "DlgDirListW");
	pDlgDirSelectComboBoxExA = (void *)GetProcAddress(library, "DlgDirSelectComboBoxExA");
	pDlgDirSelectComboBoxExW = (void *)GetProcAddress(library, "DlgDirSelectComboBoxExW");
	pDlgDirSelectExA = (void *)GetProcAddress(library, "DlgDirSelectExA");
	pDlgDirSelectExW = (void *)GetProcAddress(library, "DlgDirSelectExW");
	pDragDetect = (void *)GetProcAddress(library, "DragDetect");
	pDrawAnimatedRects = (void *)GetProcAddress(library, "DrawAnimatedRects");
	pDrawCaption = (void *)GetProcAddress(library, "DrawCaption");
	pDrawCaptionTempA = (void *)GetProcAddress(library, "DrawCaptionTempA");
	pDrawCaptionTempW = (void *)GetProcAddress(library, "DrawCaptionTempW");
	pDrawEdge = (void *)GetProcAddress(library, "DrawEdge");
	pDrawFocusRect = (void *)GetProcAddress(library, "DrawFocusRect");
	pDrawFrameControl = (void *)GetProcAddress(library, "DrawFrameControl");
	pDrawIcon = (void *)GetProcAddress(library, "DrawIcon");
	pDrawIconEx = (void *)GetProcAddress(library, "DrawIconEx");
	pDrawMenuBar = (void *)GetProcAddress(library, "DrawMenuBar");
	pDrawMenuBarTemp = (void *)GetProcAddress(library, "DrawMenuBarTemp");
	pDrawStateA = (void *)GetProcAddress(library, "DrawStateA");
	pDrawStateW = (void *)GetProcAddress(library, "DrawStateW");
	pDrawTextA = (void *)GetProcAddress(library, "DrawTextA");
	pDrawTextExA = (void *)GetProcAddress(library, "DrawTextExA");
	pDrawTextExW = (void *)GetProcAddress(library, "DrawTextExW");
	pDrawTextW = (void *)GetProcAddress(library, "DrawTextW");
	pEditWndProc = (void *)GetProcAddress(library, "EditWndProc");
	pEmptyClipboard = (void *)GetProcAddress(library, "EmptyClipboard");
	pEnableMenuItem = (void *)GetProcAddress(library, "EnableMenuItem");
	pEnableMouseInPointer = (void *)GetProcAddress(library, "EnableMouseInPointer");
	pEnableScrollBar = (void *)GetProcAddress(library, "EnableScrollBar");
	pEnableWindow = (void *)GetProcAddress(library, "EnableWindow");
	pEndDeferWindowPos = (void *)GetProcAddress(library, "EndDeferWindowPos");
	pEndDialog = (void *)GetProcAddress(library, "EndDialog");
	pEndMenu = (void *)GetProcAddress(library, "EndMenu");
	pEndPaint = (void *)GetProcAddress(library, "EndPaint");
	pEnumChildWindows = (void *)GetProcAddress(library, "EnumChildWindows");
	pEnumClipboardFormats = (void *)GetProcAddress(library, "EnumClipboardFormats");
	pEnumDesktopWindows = (void *)GetProcAddress(library, "EnumDesktopWindows");
	pEnumDesktopsA = (void *)GetProcAddress(library, "EnumDesktopsA");
	pEnumDesktopsW = (void *)GetProcAddress(library, "EnumDesktopsW");
	pEnumDisplayDevicesA = (void *)GetProcAddress(library, "EnumDisplayDevicesA");
	pEnumDisplayDevicesW = (void *)GetProcAddress(library, "EnumDisplayDevicesW");
	pEnumDisplayMonitors = (void *)GetProcAddress(library, "EnumDisplayMonitors");
	pEnumDisplaySettingsA = (void *)GetProcAddress(library, "EnumDisplaySettingsA");
	pEnumDisplaySettingsExA = (void *)GetProcAddress(library, "EnumDisplaySettingsExA");
	pEnumDisplaySettingsExW = (void *)GetProcAddress(library, "EnumDisplaySettingsExW");
	pEnumDisplaySettingsW = (void *)GetProcAddress(library, "EnumDisplaySettingsW");
	pEnumPropsA = (void *)GetProcAddress(library, "EnumPropsA");
	pEnumPropsExA = (void *)GetProcAddress(library, "EnumPropsExA");
	pEnumPropsExW = (void *)GetProcAddress(library, "EnumPropsExW");
	pEnumPropsW = (void *)GetProcAddress(library, "EnumPropsW");
	pEnumThreadWindows = (void *)GetProcAddress(library, "EnumThreadWindows");
	pEnumWindowStationsA = (void *)GetProcAddress(library, "EnumWindowStationsA");
	pEnumWindowStationsW = (void *)GetProcAddress(library, "EnumWindowStationsW");
	pEnumWindows = (void *)GetProcAddress(library, "EnumWindows");
	pEqualRect = (void *)GetProcAddress(library, "EqualRect");
	pExcludeUpdateRgn = (void *)GetProcAddress(library, "ExcludeUpdateRgn");
	pExitWindowsEx = (void *)GetProcAddress(library, "ExitWindowsEx");
	pFillRect = (void *)GetProcAddress(library, "FillRect");
	pFindWindowA = (void *)GetProcAddress(library, "FindWindowA");
	pFindWindowExA = (void *)GetProcAddress(library, "FindWindowExA");
	pFindWindowExW = (void *)GetProcAddress(library, "FindWindowExW");
	pFindWindowW = (void *)GetProcAddress(library, "FindWindowW");
	pFlashWindow = (void *)GetProcAddress(library, "FlashWindow");
	pFlashWindowEx = (void *)GetProcAddress(library, "FlashWindowEx");
	pFrameRect = (void *)GetProcAddress(library, "FrameRect");
	pFreeDDElParam = (void *)GetProcAddress(library, "FreeDDElParam");
	pGetActiveWindow = (void *)GetProcAddress(library, "GetActiveWindow");
	pGetAltTabInfoA = (void *)GetProcAddress(library, "GetAltTabInfoA");
	pGetAltTabInfoW = (void *)GetProcAddress(library, "GetAltTabInfoW");
	pGetAncestor = (void *)GetProcAddress(library, "GetAncestor");
	pGetAppCompatFlags = (void *)GetProcAddress(library, "GetAppCompatFlags");
	pGetAppCompatFlags2 = (void *)GetProcAddress(library, "GetAppCompatFlags2");
	pGetAsyncKeyState = (void *)GetProcAddress(library, "GetAsyncKeyState");
	pGetAutoRotationState = (void *)GetProcAddress(library, "GetAutoRotationState");
	pGetAwarenessFromDpiAwarenessContext = (void *)GetProcAddress(library, "GetAwarenessFromDpiAwarenessContext");
	pGetCapture = (void *)GetProcAddress(library, "GetCapture");
	pGetCaretBlinkTime = (void *)GetProcAddress(library, "GetCaretBlinkTime");
	pGetCaretPos = (void *)GetProcAddress(library, "GetCaretPos");
	pGetClassInfoA = (void *)GetProcAddress(library, "GetClassInfoA");
	pGetClassInfoExA = (void *)GetProcAddress(library, "GetClassInfoExA");
	pGetClassInfoExW = (void *)GetProcAddress(library, "GetClassInfoExW");
	pGetClassInfoW = (void *)GetProcAddress(library, "GetClassInfoW");
	pGetClassLongA = (void *)GetProcAddress(library, "GetClassLongA");
	pGetClassLongW = (void *)GetProcAddress(library, "GetClassLongW");
	pGetClassLongPtrA = (void *)GetProcAddress(library, "GetClassLongPtrA");
	pGetClassLongPtrW = (void *)GetProcAddress(library, "GetClassLongPtrW");
	pGetClassNameA = (void *)GetProcAddress(library, "GetClassNameA");
	pGetClassNameW = (void *)GetProcAddress(library, "GetClassNameW");
	pGetClassWord = (void *)GetProcAddress(library, "GetClassWord");
	pGetClientRect = (void *)GetProcAddress(library, "GetClientRect");
	pGetClipCursor = (void *)GetProcAddress(library, "GetClipCursor");
	pGetClipboardData = (void *)GetProcAddress(library, "GetClipboardData");
	pGetClipboardFormatNameA = (void *)GetProcAddress(library, "GetClipboardFormatNameA");
	pGetClipboardFormatNameW = (void *)GetProcAddress(library, "GetClipboardFormatNameW");
	pGetClipboardOwner = (void *)GetProcAddress(library, "GetClipboardOwner");
	pGetClipboardSequenceNumber = (void *)GetProcAddress(library, "GetClipboardSequenceNumber");
	pGetClipboardViewer = (void *)GetProcAddress(library, "GetClipboardViewer");
	pGetComboBoxInfo = (void *)GetProcAddress(library, "GetComboBoxInfo");
	pGetCurrentInputMessageSource = (void *)GetProcAddress(library, "GetCurrentInputMessageSource");
	pGetCursor = (void *)GetProcAddress(library, "GetCursor");
	pGetCursorFrameInfo = (void *)GetProcAddress(library, "GetCursorFrameInfo");
	pGetCursorInfo = (void *)GetProcAddress(library, "GetCursorInfo");
	pGetCursorPos = (void *)GetProcAddress(library, "GetCursorPos");
	pGetDC = (void *)GetProcAddress(library, "GetDC");
	pGetDCEx = (void *)GetProcAddress(library, "GetDCEx");
	pGetDesktopWindow = (void *)GetProcAddress(library, "GetDesktopWindow");
	pGetDialogBaseUnits = (void *)GetProcAddress(library, "GetDialogBaseUnits");
	pGetDisplayAutoRotationPreferences = (void *)GetProcAddress(library, "GetDisplayAutoRotationPreferences");
	pGetDisplayConfigBufferSizes = (void *)GetProcAddress(library, "GetDisplayConfigBufferSizes");
	pGetDlgCtrlID = (void *)GetProcAddress(library, "GetDlgCtrlID");
	pGetDlgItem = (void *)GetProcAddress(library, "GetDlgItem");
	pGetDlgItemInt = (void *)GetProcAddress(library, "GetDlgItemInt");
	pGetDlgItemTextA = (void *)GetProcAddress(library, "GetDlgItemTextA");
	pGetDlgItemTextW = (void *)GetProcAddress(library, "GetDlgItemTextW");
	pGetDoubleClickTime = (void *)GetProcAddress(library, "GetDoubleClickTime");
	pGetDpiForMonitorInternal = (void *)GetProcAddress(library, "GetDpiForMonitorInternal");
	pGetDpiForSystem = (void *)GetProcAddress(library, "GetDpiForSystem");
	pGetDpiForWindow = (void *)GetProcAddress(library, "GetDpiForWindow");
	pGetFocus = (void *)GetProcAddress(library, "GetFocus");
	pGetForegroundWindow = (void *)GetProcAddress(library, "GetForegroundWindow");
	pGetGestureConfig = (void *)GetProcAddress(library, "GetGestureConfig");
	pGetGestureInfo = (void *)GetProcAddress(library, "GetGestureInfo");
	pGetGUIThreadInfo = (void *)GetProcAddress(library, "GetGUIThreadInfo");
	pGetGuiResources = (void *)GetProcAddress(library, "GetGuiResources");
	pGetIconInfo = (void *)GetProcAddress(library, "GetIconInfo");
	pGetIconInfoExA = (void *)GetProcAddress(library, "GetIconInfoExA");
	pGetIconInfoExW = (void *)GetProcAddress(library, "GetIconInfoExW");
	pGetInputState = (void *)GetProcAddress(library, "GetInputState");
	pGetInternalWindowPos = (void *)GetProcAddress(library, "GetInternalWindowPos");
	pGetKBCodePage = (void *)GetProcAddress(library, "GetKBCodePage");
	pGetKeyNameTextA = (void *)GetProcAddress(library, "GetKeyNameTextA");
	pGetKeyNameTextW = (void *)GetProcAddress(library, "GetKeyNameTextW");
	pGetKeyState = (void *)GetProcAddress(library, "GetKeyState");
	pGetKeyboardLayout = (void *)GetProcAddress(library, "GetKeyboardLayout");
	pGetKeyboardLayoutList = (void *)GetProcAddress(library, "GetKeyboardLayoutList");
	pGetKeyboardLayoutNameA = (void *)GetProcAddress(library, "GetKeyboardLayoutNameA");
	pGetKeyboardLayoutNameW = (void *)GetProcAddress(library, "GetKeyboardLayoutNameW");
	pGetKeyboardState = (void *)GetProcAddress(library, "GetKeyboardState");
	pGetKeyboardType = (void *)GetProcAddress(library, "GetKeyboardType");
	pGetLastActivePopup = (void *)GetProcAddress(library, "GetLastActivePopup");
	pGetLastInputInfo = (void *)GetProcAddress(library, "GetLastInputInfo");
	pGetLayeredWindowAttributes = (void *)GetProcAddress(library, "GetLayeredWindowAttributes");
	pGetListBoxInfo = (void *)GetProcAddress(library, "GetListBoxInfo");
	pGetMenu = (void *)GetProcAddress(library, "GetMenu");
	pGetMenuBarInfo = (void *)GetProcAddress(library, "GetMenuBarInfo");
	pGetMenuCheckMarkDimensions = (void *)GetProcAddress(library, "GetMenuCheckMarkDimensions");
	pGetMenuContextHelpId = (void *)GetProcAddress(library, "GetMenuContextHelpId");
	pGetMenuDefaultItem = (void *)GetProcAddress(library, "GetMenuDefaultItem");
	pGetMenuInfo = (void *)GetProcAddress(library, "GetMenuInfo");
	pGetMenuItemCount = (void *)GetProcAddress(library, "GetMenuItemCount");
	pGetMenuItemID = (void *)GetProcAddress(library, "GetMenuItemID");
	pGetMenuItemInfoA = (void *)GetProcAddress(library, "GetMenuItemInfoA");
	pGetMenuItemInfoW = (void *)GetProcAddress(library, "GetMenuItemInfoW");
	pGetMenuItemRect = (void *)GetProcAddress(library, "GetMenuItemRect");
	pGetMenuState = (void *)GetProcAddress(library, "GetMenuState");
	pGetMenuStringA = (void *)GetProcAddress(library, "GetMenuStringA");
	pGetMenuStringW = (void *)GetProcAddress(library, "GetMenuStringW");
	pGetMessageA = (void *)GetProcAddress(library, "GetMessageA");
	pGetMessageExtraInfo = (void *)GetProcAddress(library, "GetMessageExtraInfo");
	pGetMessagePos = (void *)GetProcAddress(library, "GetMessagePos");
	pGetMessageTime = (void *)GetProcAddress(library, "GetMessageTime");
	pGetMessageW = (void *)GetProcAddress(library, "GetMessageW");
	pGetMonitorInfoA = (void *)GetProcAddress(library, "GetMonitorInfoA");
	pGetMonitorInfoW = (void *)GetProcAddress(library, "GetMonitorInfoW");
	pGetMouseMovePointsEx = (void *)GetProcAddress(library, "GetMouseMovePointsEx");
	pGetNextDlgGroupItem = (void *)GetProcAddress(library, "GetNextDlgGroupItem");
	pGetNextDlgTabItem = (void *)GetProcAddress(library, "GetNextDlgTabItem");
	pGetOpenClipboardWindow = (void *)GetProcAddress(library, "GetOpenClipboardWindow");
	pGetParent = (void *)GetProcAddress(library, "GetParent");
	pGetPhysicalCursorPos = (void *)GetProcAddress(library, "GetPhysicalCursorPos");
	pGetPointerDevices = (void *)GetProcAddress(library, "GetPointerDevices");
	pGetPointerType = (void *)GetProcAddress(library, "GetPointerType");
	pGetPriorityClipboardFormat = (void *)GetProcAddress(library, "GetPriorityClipboardFormat");
	pGetProcessDefaultLayout = (void *)GetProcAddress(library, "GetProcessDefaultLayout");
	pGetProcessDpiAwarenessInternal = (void *)GetProcAddress(library, "GetProcessDpiAwarenessInternal");
	pGetProcessWindowStation = (void *)GetProcAddress(library, "GetProcessWindowStation");
	pGetProgmanWindow = (void *)GetProcAddress(library, "GetProgmanWindow");
	pGetPropA = (void *)GetProcAddress(library, "GetPropA");
	pGetPropW = (void *)GetProcAddress(library, "GetPropW");
	pGetQueueStatus = (void *)GetProcAddress(library, "GetQueueStatus");
	pGetRawInputBuffer = (void *)GetProcAddress(library, "GetRawInputBuffer");
	pGetRawInputData = (void *)GetProcAddress(library, "GetRawInputData");
	pGetRawInputDeviceInfoA = (void *)GetProcAddress(library, "GetRawInputDeviceInfoA");
	pGetRawInputDeviceInfoW = (void *)GetProcAddress(library, "GetRawInputDeviceInfoW");
	pGetRawInputDeviceList = (void *)GetProcAddress(library, "GetRawInputDeviceList");
	pGetRegisteredRawInputDevices = (void *)GetProcAddress(library, "GetRegisteredRawInputDevices");
	pGetScrollBarInfo = (void *)GetProcAddress(library, "GetScrollBarInfo");
	pGetScrollInfo = (void *)GetProcAddress(library, "GetScrollInfo");
	pGetScrollPos = (void *)GetProcAddress(library, "GetScrollPos");
	pGetScrollRange = (void *)GetProcAddress(library, "GetScrollRange");
	pGetShellWindow = (void *)GetProcAddress(library, "GetShellWindow");
	pGetSubMenu = (void *)GetProcAddress(library, "GetSubMenu");
	pGetSysColor = (void *)GetProcAddress(library, "GetSysColor");
	pGetSysColorBrush = (void *)GetProcAddress(library, "GetSysColorBrush");
	pGetSystemMenu = (void *)GetProcAddress(library, "GetSystemMenu");
	pGetSystemMetrics = (void *)GetProcAddress(library, "GetSystemMetrics");
	pGetSystemMetricsForDpi = (void *)GetProcAddress(library, "GetSystemMetricsForDpi");
	pGetTabbedTextExtentA = (void *)GetProcAddress(library, "GetTabbedTextExtentA");
	pGetTabbedTextExtentW = (void *)GetProcAddress(library, "GetTabbedTextExtentW");
	pGetTaskmanWindow = (void *)GetProcAddress(library, "GetTaskmanWindow");
	pGetThreadDesktop = (void *)GetProcAddress(library, "GetThreadDesktop");
	pGetThreadDpiAwarenessContext = (void *)GetProcAddress(library, "GetThreadDpiAwarenessContext");
	pGetTitleBarInfo = (void *)GetProcAddress(library, "GetTitleBarInfo");
	pGetTopWindow = (void *)GetProcAddress(library, "GetTopWindow");
	pGetTouchInputInfo = (void *)GetProcAddress(library, "GetTouchInputInfo");
	pGetUpdateRect = (void *)GetProcAddress(library, "GetUpdateRect");
	pGetUpdateRgn = (void *)GetProcAddress(library, "GetUpdateRgn");
	pGetUpdatedClipboardFormats = (void *)GetProcAddress(library, "GetUpdatedClipboardFormats");
	pGetUserObjectInformationA = (void *)GetProcAddress(library, "GetUserObjectInformationA");
	pGetUserObjectInformationW = (void *)GetProcAddress(library, "GetUserObjectInformationW");
	pGetUserObjectSecurity = (void *)GetProcAddress(library, "GetUserObjectSecurity");
	pGetWindow = (void *)GetProcAddress(library, "GetWindow");
	pGetWindowContextHelpId = (void *)GetProcAddress(library, "GetWindowContextHelpId");
	pGetWindowDC = (void *)GetProcAddress(library, "GetWindowDC");
	pGetWindowDisplayAffinity = (void *)GetProcAddress(library, "GetWindowDisplayAffinity");
	pGetWindowDpiAwarenessContext = (void *)GetProcAddress(library, "GetWindowDpiAwarenessContext");
	pGetWindowInfo = (void *)GetProcAddress(library, "GetWindowInfo");
	pGetWindowLongA = (void *)GetProcAddress(library, "GetWindowLongA");
	pGetWindowLongPtrA = (void *)GetProcAddress(library, "GetWindowLongPtrA");
	pGetWindowLongPtrW = (void *)GetProcAddress(library, "GetWindowLongPtrW");
	pGetWindowLongW = (void *)GetProcAddress(library, "GetWindowLongW");
	pGetWindowModuleFileNameA = (void *)GetProcAddress(library, "GetWindowModuleFileNameA");
	pGetWindowModuleFileNameW = (void *)GetProcAddress(library, "GetWindowModuleFileNameW");
	pGetWindowPlacement = (void *)GetProcAddress(library, "GetWindowPlacement");
	pGetWindowRect = (void *)GetProcAddress(library, "GetWindowRect");
	pGetWindowRgn = (void *)GetProcAddress(library, "GetWindowRgn");
	pGetWindowRgnBox = (void *)GetProcAddress(library, "GetWindowRgnBox");
	pGetWindowTextA = (void *)GetProcAddress(library, "GetWindowTextA");
	pGetWindowTextLengthA = (void *)GetProcAddress(library, "GetWindowTextLengthA");
	pGetWindowTextLengthW = (void *)GetProcAddress(library, "GetWindowTextLengthW");
	pGetWindowTextW = (void *)GetProcAddress(library, "GetWindowTextW");
	pGetWindowThreadProcessId = (void *)GetProcAddress(library, "GetWindowThreadProcessId");
	pGetWindowWord = (void *)GetProcAddress(library, "GetWindowWord");
	pGrayStringA = (void *)GetProcAddress(library, "GrayStringA");
	pGrayStringW = (void *)GetProcAddress(library, "GrayStringW");
	pHideCaret = (void *)GetProcAddress(library, "HideCaret");
	pHiliteMenuItem = (void *)GetProcAddress(library, "HiliteMenuItem");
	pImpersonateDdeClientWindow = (void *)GetProcAddress(library, "ImpersonateDdeClientWindow");
	pInSendMessage = (void *)GetProcAddress(library, "InSendMessage");
	pInSendMessageEx = (void *)GetProcAddress(library, "InSendMessageEx");
	pInflateRect = (void *)GetProcAddress(library, "InflateRect");
	pInsertMenuA = (void *)GetProcAddress(library, "InsertMenuA");
	pInsertMenuItemA = (void *)GetProcAddress(library, "InsertMenuItemA");
	pInsertMenuItemW = (void *)GetProcAddress(library, "InsertMenuItemW");
	pInsertMenuW = (void *)GetProcAddress(library, "InsertMenuW");
	pInternalGetWindowText = (void *)GetProcAddress(library, "InternalGetWindowText");
	pIntersectRect = (void *)GetProcAddress(library, "IntersectRect");
	pInvalidateRect = (void *)GetProcAddress(library, "InvalidateRect");
	pInvalidateRgn = (void *)GetProcAddress(library, "InvalidateRgn");
	pInvertRect = (void *)GetProcAddress(library, "InvertRect");
	pIsCharAlphaA = (void *)GetProcAddress(library, "IsCharAlphaA");
	pIsCharAlphaNumericA = (void *)GetProcAddress(library, "IsCharAlphaNumericA");
	pIsCharAlphaNumericW = (void *)GetProcAddress(library, "IsCharAlphaNumericW");
	pIsCharAlphaW = (void *)GetProcAddress(library, "IsCharAlphaW");
	pIsCharLowerA = (void *)GetProcAddress(library, "IsCharLowerA");
	pIsCharLowerW = (void *)GetProcAddress(library, "IsCharLowerW");
	pIsCharUpperA = (void *)GetProcAddress(library, "IsCharUpperA");
	pIsCharUpperW = (void *)GetProcAddress(library, "IsCharUpperW");
	pIsChild = (void *)GetProcAddress(library, "IsChild");
	pIsClipboardFormatAvailable = (void *)GetProcAddress(library, "IsClipboardFormatAvailable");
	pIsDialogMessageA = (void *)GetProcAddress(library, "IsDialogMessageA");
	pIsDialogMessageW = (void *)GetProcAddress(library, "IsDialogMessageW");
	pIsDlgButtonChecked = (void *)GetProcAddress(library, "IsDlgButtonChecked");
	pIsGUIThread = (void *)GetProcAddress(library, "IsGUIThread");
	pIsHungAppWindow = (void *)GetProcAddress(library, "IsHungAppWindow");
	pIsIconic = (void *)GetProcAddress(library, "IsIconic");
	pIsMenu = (void *)GetProcAddress(library, "IsMenu");
	pIsProcessDPIAware = (void *)GetProcAddress(library, "IsProcessDPIAware");
	pIsRectEmpty = (void *)GetProcAddress(library, "IsRectEmpty");
	pIsTouchWindow = (void *)GetProcAddress(library, "IsTouchWindow");
	pIsValidDpiAwarenessContext = (void *)GetProcAddress(library, "IsValidDpiAwarenessContext");
	pIsWinEventHookInstalled = (void *)GetProcAddress(library, "IsWinEventHookInstalled");
	pIsWindow = (void *)GetProcAddress(library, "IsWindow");
	pIsWindowEnabled = (void *)GetProcAddress(library, "IsWindowEnabled");
	pIsWindowRedirectedForPrint = (void *)GetProcAddress(library, "IsWindowRedirectedForPrint");
	pIsWindowUnicode = (void *)GetProcAddress(library, "IsWindowUnicode");
	pIsWindowVisible = (void *)GetProcAddress(library, "IsWindowVisible");
	pIsZoomed = (void *)GetProcAddress(library, "IsZoomed");
	pKillSystemTimer = (void *)GetProcAddress(library, "KillSystemTimer");
	pKillTimer = (void *)GetProcAddress(library, "KillTimer");
	pLoadAcceleratorsA = (void *)GetProcAddress(library, "LoadAcceleratorsA");
	pLoadAcceleratorsW = (void *)GetProcAddress(library, "LoadAcceleratorsW");
	pLoadBitmapA = (void *)GetProcAddress(library, "LoadBitmapA");
	pLoadBitmapW = (void *)GetProcAddress(library, "LoadBitmapW");
	pLoadCursorA = (void *)GetProcAddress(library, "LoadCursorA");
	pLoadCursorFromFileA = (void *)GetProcAddress(library, "LoadCursorFromFileA");
	pLoadCursorFromFileW = (void *)GetProcAddress(library, "LoadCursorFromFileW");
	pLoadCursorW = (void *)GetProcAddress(library, "LoadCursorW");
	pLoadIconA = (void *)GetProcAddress(library, "LoadIconA");
	pLoadIconW = (void *)GetProcAddress(library, "LoadIconW");
	pLoadImageA = (void *)GetProcAddress(library, "LoadImageA");
	pLoadImageW = (void *)GetProcAddress(library, "LoadImageW");
	pLoadKeyboardLayoutA = (void *)GetProcAddress(library, "LoadKeyboardLayoutA");
	pLoadKeyboardLayoutW = (void *)GetProcAddress(library, "LoadKeyboardLayoutW");
	pLoadLocalFonts = (void *)GetProcAddress(library, "LoadLocalFonts");
	pLoadMenuA = (void *)GetProcAddress(library, "LoadMenuA");
	pLoadMenuIndirectA = (void *)GetProcAddress(library, "LoadMenuIndirectA");
	pLoadMenuIndirectW = (void *)GetProcAddress(library, "LoadMenuIndirectW");
	pLoadMenuW = (void *)GetProcAddress(library, "LoadMenuW");
	pLoadStringA = (void *)GetProcAddress(library, "LoadStringA");
	pLoadStringW = (void *)GetProcAddress(library, "LoadStringW");
	pLockSetForegroundWindow = (void *)GetProcAddress(library, "LockSetForegroundWindow");
	pLockWindowUpdate = (void *)GetProcAddress(library, "LockWindowUpdate");
	pLockWorkStation = (void *)GetProcAddress(library, "LockWorkStation");
	pLogicalToPhysicalPoint = (void *)GetProcAddress(library, "LogicalToPhysicalPoint");
	pLogicalToPhysicalPointForPerMonitorDPI = (void *)GetProcAddress(library, "LogicalToPhysicalPointForPerMonitorDPI");
	pLookupIconIdFromDirectory = (void *)GetProcAddress(library, "LookupIconIdFromDirectory");
	pLookupIconIdFromDirectoryEx = (void *)GetProcAddress(library, "LookupIconIdFromDirectoryEx");
	pMapDialogRect = (void *)GetProcAddress(library, "MapDialogRect");
	pMapVirtualKeyA = (void *)GetProcAddress(library, "MapVirtualKeyA");
	pMapVirtualKeyExA = (void *)GetProcAddress(library, "MapVirtualKeyExA");
	pMapVirtualKeyExW = (void *)GetProcAddress(library, "MapVirtualKeyExW");
	pMapVirtualKeyW = (void *)GetProcAddress(library, "MapVirtualKeyW");
	pMapWindowPoints = (void *)GetProcAddress(library, "MapWindowPoints");
	pMenuItemFromPoint = (void *)GetProcAddress(library, "MenuItemFromPoint");
	pMessageBeep = (void *)GetProcAddress(library, "MessageBeep");
	pMessageBoxA = (void *)GetProcAddress(library, "MessageBoxA");
	pMessageBoxExA = (void *)GetProcAddress(library, "MessageBoxExA");
	pMessageBoxExW = (void *)GetProcAddress(library, "MessageBoxExW");
	pMessageBoxIndirectA = (void *)GetProcAddress(library, "MessageBoxIndirectA");
	pMessageBoxIndirectW = (void *)GetProcAddress(library, "MessageBoxIndirectW");
	pMessageBoxTimeoutA = (void *)GetProcAddress(library, "MessageBoxTimeoutA");
	pMessageBoxTimeoutW = (void *)GetProcAddress(library, "MessageBoxTimeoutW");
	pMessageBoxW = (void *)GetProcAddress(library, "MessageBoxW");
	pModifyMenuA = (void *)GetProcAddress(library, "ModifyMenuA");
	pModifyMenuW = (void *)GetProcAddress(library, "ModifyMenuW");
	pMonitorFromPoint = (void *)GetProcAddress(library, "MonitorFromPoint");
	pMonitorFromRect = (void *)GetProcAddress(library, "MonitorFromRect");
	pMonitorFromWindow = (void *)GetProcAddress(library, "MonitorFromWindow");
	pMoveWindow = (void *)GetProcAddress(library, "MoveWindow");
	pMsgWaitForMultipleObjects = (void *)GetProcAddress(library, "MsgWaitForMultipleObjects");
	pMsgWaitForMultipleObjectsEx = (void *)GetProcAddress(library, "MsgWaitForMultipleObjectsEx");
	pNotifyWinEvent = (void *)GetProcAddress(library, "NotifyWinEvent");
	pOemKeyScan = (void *)GetProcAddress(library, "OemKeyScan");
	pOemToCharA = (void *)GetProcAddress(library, "OemToCharA");
	pOemToCharBuffA = (void *)GetProcAddress(library, "OemToCharBuffA");
	pOemToCharBuffW = (void *)GetProcAddress(library, "OemToCharBuffW");
	pOemToCharW = (void *)GetProcAddress(library, "OemToCharW");
	pOffsetRect = (void *)GetProcAddress(library, "OffsetRect");
	pOpenClipboard = (void *)GetProcAddress(library, "OpenClipboard");
	pOpenDesktopA = (void *)GetProcAddress(library, "OpenDesktopA");
	pOpenDesktopW = (void *)GetProcAddress(library, "OpenDesktopW");
	pOpenIcon = (void *)GetProcAddress(library, "OpenIcon");
	pOpenInputDesktop = (void *)GetProcAddress(library, "OpenInputDesktop");
	pOpenWindowStationA = (void *)GetProcAddress(library, "OpenWindowStationA");
	pOpenWindowStationW = (void *)GetProcAddress(library, "OpenWindowStationW");
	pPackDDElParam = (void *)GetProcAddress(library, "PackDDElParam");
	pPaintDesktop = (void *)GetProcAddress(library, "PaintDesktop");
	pPeekMessageA = (void *)GetProcAddress(library, "PeekMessageA");
	pPeekMessageW = (void *)GetProcAddress(library, "PeekMessageW");
	pPhysicalToLogicalPoint = (void *)GetProcAddress(library, "PhysicalToLogicalPoint");
	pPhysicalToLogicalPointForPerMonitorDPI = (void *)GetProcAddress(library, "PhysicalToLogicalPointForPerMonitorDPI");
	pPostMessageA = (void *)GetProcAddress(library, "PostMessageA");
	pPostMessageW = (void *)GetProcAddress(library, "PostMessageW");
	pPostQuitMessage = (void *)GetProcAddress(library, "PostQuitMessage");
	pPostThreadMessageA = (void *)GetProcAddress(library, "PostThreadMessageA");
	pPostThreadMessageW = (void *)GetProcAddress(library, "PostThreadMessageW");
	pPrintWindow = (void *)GetProcAddress(library, "PrintWindow");
	pPrivateExtractIconExA = (void *)GetProcAddress(library, "PrivateExtractIconExA");
	pPrivateExtractIconExW = (void *)GetProcAddress(library, "PrivateExtractIconExW");
	pPrivateExtractIconsA = (void *)GetProcAddress(library, "PrivateExtractIconsA");
	pPrivateExtractIconsW = (void *)GetProcAddress(library, "PrivateExtractIconsW");
	pPtInRect = (void *)GetProcAddress(library, "PtInRect");
	pQueryDisplayConfig = (void *)GetProcAddress(library, "QueryDisplayConfig");
	pRealChildWindowFromPoint = (void *)GetProcAddress(library, "RealChildWindowFromPoint");
	pRealGetWindowClassA = (void *)GetProcAddress(library, "RealGetWindowClassA");
	pRealGetWindowClassW = (void *)GetProcAddress(library, "RealGetWindowClassW");
	pRedrawWindow = (void *)GetProcAddress(library, "RedrawWindow");
	pRegisterClassA = (void *)GetProcAddress(library, "RegisterClassA");
	pRegisterClassExA = (void *)GetProcAddress(library, "RegisterClassExA");
	pRegisterClassExW = (void *)GetProcAddress(library, "RegisterClassExW");
	pRegisterClassW = (void *)GetProcAddress(library, "RegisterClassW");
	pRegisterClipboardFormatA = (void *)GetProcAddress(library, "RegisterClipboardFormatA");
	pRegisterClipboardFormatW = (void *)GetProcAddress(library, "RegisterClipboardFormatW");
	pRegisterDeviceNotificationA = (void *)GetProcAddress(library, "RegisterDeviceNotificationA");
	pRegisterDeviceNotificationW = (void *)GetProcAddress(library, "RegisterDeviceNotificationW");
	pRegisterHotKey = (void *)GetProcAddress(library, "RegisterHotKey");
	pRegisterLogonProcess = (void *)GetProcAddress(library, "RegisterLogonProcess");
	pRegisterPointerDeviceNotifications = (void *)GetProcAddress(library, "RegisterPointerDeviceNotifications");
	pRegisterPowerSettingNotification = (void *)GetProcAddress(library, "RegisterPowerSettingNotification");
	pRegisterRawInputDevices = (void *)GetProcAddress(library, "RegisterRawInputDevices");
	pRegisterServicesProcess = (void *)GetProcAddress(library, "RegisterServicesProcess");
	pRegisterShellHookWindow = (void *)GetProcAddress(library, "RegisterShellHookWindow");
	pRegisterSystemThread = (void *)GetProcAddress(library, "RegisterSystemThread");
	pRegisterTasklist = (void *)GetProcAddress(library, "RegisterTasklist");
	pRegisterTouchHitTestingWindow = (void *)GetProcAddress(library, "RegisterTouchHitTestingWindow");
	pRegisterTouchWindow = (void *)GetProcAddress(library, "RegisterTouchWindow");
	pRegisterWindowMessageA = (void *)GetProcAddress(library, "RegisterWindowMessageA");
	pRegisterWindowMessageW = (void *)GetProcAddress(library, "RegisterWindowMessageW");
	pReleaseCapture = (void *)GetProcAddress(library, "ReleaseCapture");
	pReleaseDC = (void *)GetProcAddress(library, "ReleaseDC");
	pRemoveClipboardFormatListener = (void *)GetProcAddress(library, "RemoveClipboardFormatListener");
	pRemoveMenu = (void *)GetProcAddress(library, "RemoveMenu");
	pRemovePropA = (void *)GetProcAddress(library, "RemovePropA");
	pRemovePropW = (void *)GetProcAddress(library, "RemovePropW");
	pReplyMessage = (void *)GetProcAddress(library, "ReplyMessage");
	pReuseDDElParam = (void *)GetProcAddress(library, "ReuseDDElParam");
	pScreenToClient = (void *)GetProcAddress(library, "ScreenToClient");
	pScrollChildren = (void *)GetProcAddress(library, "ScrollChildren");
	pScrollDC = (void *)GetProcAddress(library, "ScrollDC");
	pScrollWindow = (void *)GetProcAddress(library, "ScrollWindow");
	pScrollWindowEx = (void *)GetProcAddress(library, "ScrollWindowEx");
	pSendDlgItemMessageA = (void *)GetProcAddress(library, "SendDlgItemMessageA");
	pSendDlgItemMessageW = (void *)GetProcAddress(library, "SendDlgItemMessageW");
	pSendIMEMessageExA = (void *)GetProcAddress(library, "SendIMEMessageExA");
	pSendIMEMessageExW = (void *)GetProcAddress(library, "SendIMEMessageExW");
	pSendInput = (void *)GetProcAddress(library, "SendInput");
	pSendMessageA = (void *)GetProcAddress(library, "SendMessageA");
	pSendMessageCallbackA = (void *)GetProcAddress(library, "SendMessageCallbackA");
	pSendMessageCallbackW = (void *)GetProcAddress(library, "SendMessageCallbackW");
	pSendMessageTimeoutA = (void *)GetProcAddress(library, "SendMessageTimeoutA");
	pSendMessageTimeoutW = (void *)GetProcAddress(library, "SendMessageTimeoutW");
	pSendMessageW = (void *)GetProcAddress(library, "SendMessageW");
	pSendNotifyMessageA = (void *)GetProcAddress(library, "SendNotifyMessageA");
	pSendNotifyMessageW = (void *)GetProcAddress(library, "SendNotifyMessageW");
	pSetActiveWindow = (void *)GetProcAddress(library, "SetActiveWindow");
	pSetCapture = (void *)GetProcAddress(library, "SetCapture");
	pSetCaretBlinkTime = (void *)GetProcAddress(library, "SetCaretBlinkTime");
	pSetCaretPos = (void *)GetProcAddress(library, "SetCaretPos");
	pSetClassLongA = (void *)GetProcAddress(library, "SetClassLongA");
	pSetClassLongPtrA = (void *)GetProcAddress(library, "SetClassLongPtrA");
	pSetClassLongPtrW = (void *)GetProcAddress(library, "SetClassLongPtrW");
	pSetClassLongW = (void *)GetProcAddress(library, "SetClassLongW");
	pSetClassWord = (void *)GetProcAddress(library, "SetClassWord");
	pSetClipboardData = (void *)GetProcAddress(library, "SetClipboardData");
	pSetClipboardViewer = (void *)GetProcAddress(library, "SetClipboardViewer");
	pSetCoalescableTimer = (void *)GetProcAddress(library, "SetCoalescableTimer");
	pSetCursor = (void *)GetProcAddress(library, "SetCursor");
	pSetCursorPos = (void *)GetProcAddress(library, "SetCursorPos");
	pSetDebugErrorLevel = (void *)GetProcAddress(library, "SetDebugErrorLevel");
	pSetDeskWallPaper = (void *)GetProcAddress(library, "SetDeskWallPaper");
	pSetDlgItemInt = (void *)GetProcAddress(library, "SetDlgItemInt");
	pSetDlgItemTextA = (void *)GetProcAddress(library, "SetDlgItemTextA");
	pSetDlgItemTextW = (void *)GetProcAddress(library, "SetDlgItemTextW");
	pSetDoubleClickTime = (void *)GetProcAddress(library, "SetDoubleClickTime");
	pSetFocus = (void *)GetProcAddress(library, "SetFocus");
	pSetForegroundWindow = (void *)GetProcAddress(library, "SetForegroundWindow");
	pSetGestureConfig = (void *)GetProcAddress(library, "SetGestureConfig");
	pSetInternalWindowPos = (void *)GetProcAddress(library, "SetInternalWindowPos");
	pSetKeyboardState = (void *)GetProcAddress(library, "SetKeyboardState");
	pSetLastErrorEx = (void *)GetProcAddress(library, "SetLastErrorEx");
	pSetLayeredWindowAttributes = (void *)GetProcAddress(library, "SetLayeredWindowAttributes");
	pSetLogonNotifyWindow = (void *)GetProcAddress(library, "SetLogonNotifyWindow");
	pSetMenu = (void *)GetProcAddress(library, "SetMenu");
	pSetMenuContextHelpId = (void *)GetProcAddress(library, "SetMenuContextHelpId");
	pSetMenuDefaultItem = (void *)GetProcAddress(library, "SetMenuDefaultItem");
	pSetMenuInfo = (void *)GetProcAddress(library, "SetMenuInfo");
	pSetMenuItemBitmaps = (void *)GetProcAddress(library, "SetMenuItemBitmaps");
	pSetMenuItemInfoA = (void *)GetProcAddress(library, "SetMenuItemInfoA");
	pSetMenuItemInfoW = (void *)GetProcAddress(library, "SetMenuItemInfoW");
	pSetMessageExtraInfo = (void *)GetProcAddress(library, "SetMessageExtraInfo");
	pSetMessageQueue = (void *)GetProcAddress(library, "SetMessageQueue");
	pSetParent = (void *)GetProcAddress(library, "SetParent");
	pSetPhysicalCursorPos = (void *)GetProcAddress(library, "SetPhysicalCursorPos");
	pSetProcessDPIAware = (void *)GetProcAddress(library, "SetProcessDPIAware");
	pSetProcessDefaultLayout = (void *)GetProcAddress(library, "SetProcessDefaultLayout");
	pSetProcessDpiAwarenessContext = (void *)GetProcAddress(library, "SetProcessDpiAwarenessContext");
	pSetProcessDpiAwarenessInternal = (void *)GetProcAddress(library, "SetProcessDpiAwarenessInternal");
	pSetProcessWindowStation = (void *)GetProcAddress(library, "SetProcessWindowStation");
	pSetProgmanWindow = (void *)GetProcAddress(library, "SetProgmanWindow");
	pSetPropA = (void *)GetProcAddress(library, "SetPropA");
	pSetPropW = (void *)GetProcAddress(library, "SetPropW");
	pSetRect = (void *)GetProcAddress(library, "SetRect");
	pSetRectEmpty = (void *)GetProcAddress(library, "SetRectEmpty");
	pSetScrollInfo = (void *)GetProcAddress(library, "SetScrollInfo");
	pSetScrollPos = (void *)GetProcAddress(library, "SetScrollPos");
	pSetScrollRange = (void *)GetProcAddress(library, "SetScrollRange");
	pSetShellWindow = (void *)GetProcAddress(library, "SetShellWindow");
	pSetShellWindowEx = (void *)GetProcAddress(library, "SetShellWindowEx");
	pSetSysColors = (void *)GetProcAddress(library, "SetSysColors");
	pSetSysColorsTemp = (void *)GetProcAddress(library, "SetSysColorsTemp");
	pSetSystemCursor = (void *)GetProcAddress(library, "SetSystemCursor");
	pSetSystemMenu = (void *)GetProcAddress(library, "SetSystemMenu");
	pSetSystemTimer = (void *)GetProcAddress(library, "SetSystemTimer");
	pSetTaskmanWindow = (void *)GetProcAddress(library, "SetTaskmanWindow");
	pSetThreadDesktop = (void *)GetProcAddress(library, "SetThreadDesktop");
	pSetThreadDpiAwarenessContext = (void *)GetProcAddress(library, "SetThreadDpiAwarenessContext");
	pSetTimer = (void *)GetProcAddress(library, "SetTimer");
	pSetUserObjectInformationA = (void *)GetProcAddress(library, "SetUserObjectInformationA");
	pSetUserObjectInformationW = (void *)GetProcAddress(library, "SetUserObjectInformationW");
	pSetUserObjectSecurity = (void *)GetProcAddress(library, "SetUserObjectSecurity");
	pSetWinEventHook = (void *)GetProcAddress(library, "SetWinEventHook");
	pSetWindowCompositionAttribute = (void *)GetProcAddress(library, "SetWindowCompositionAttribute");
	pSetWindowContextHelpId = (void *)GetProcAddress(library, "SetWindowContextHelpId");
	pSetWindowDisplayAffinity = (void *)GetProcAddress(library, "SetWindowDisplayAffinity");
	pSetWindowLongA = (void *)GetProcAddress(library, "SetWindowLongA");
	pSetWindowLongPtrA = (void *)GetProcAddress(library, "SetWindowLongPtrA");
	pSetWindowLongPtrW = (void *)GetProcAddress(library, "SetWindowLongPtrW");
	pSetWindowLongW = (void *)GetProcAddress(library, "SetWindowLongW");
	pSetWindowPlacement = (void *)GetProcAddress(library, "SetWindowPlacement");
	pSetWindowPos = (void *)GetProcAddress(library, "SetWindowPos");
	pSetWindowRgn = (void *)GetProcAddress(library, "SetWindowRgn");
	pSetWindowStationUser = (void *)GetProcAddress(library, "SetWindowStationUser");
	pSetWindowTextA = (void *)GetProcAddress(library, "SetWindowTextA");
	pSetWindowTextW = (void *)GetProcAddress(library, "SetWindowTextW");
	pSetWindowWord = (void *)GetProcAddress(library, "SetWindowWord");
	pSetWindowsHookA = (void *)GetProcAddress(library, "SetWindowsHookA");
	pSetWindowsHookExA = (void *)GetProcAddress(library, "SetWindowsHookExA");
	pSetWindowsHookExW = (void *)GetProcAddress(library, "SetWindowsHookExW");
	pSetWindowsHookW = (void *)GetProcAddress(library, "SetWindowsHookW");
	pShowCaret = (void *)GetProcAddress(library, "ShowCaret");
	pShowCursor = (void *)GetProcAddress(library, "ShowCursor");
	pShowOwnedPopups = (void *)GetProcAddress(library, "ShowOwnedPopups");
	pShowScrollBar = (void *)GetProcAddress(library, "ShowScrollBar");
	pShowWindow = (void *)GetProcAddress(library, "ShowWindow");
	pShowWindowAsync = (void *)GetProcAddress(library, "ShowWindowAsync");
	pShutdownBlockReasonCreate = (void *)GetProcAddress(library, "ShutdownBlockReasonCreate");
	pShutdownBlockReasonDestroy = (void *)GetProcAddress(library, "ShutdownBlockReasonDestroy");
	pSubtractRect = (void *)GetProcAddress(library, "SubtractRect");
	pSwapMouseButton = (void *)GetProcAddress(library, "SwapMouseButton");
	pSwitchDesktop = (void *)GetProcAddress(library, "SwitchDesktop");
	pSwitchToThisWindow = (void *)GetProcAddress(library, "SwitchToThisWindow");
	pSystemParametersInfoA = (void *)GetProcAddress(library, "SystemParametersInfoA");
	pSystemParametersInfoForDpi = (void *)GetProcAddress(library, "SystemParametersInfoForDpi");
	pSystemParametersInfoW = (void *)GetProcAddress(library, "SystemParametersInfoW");
	pTabbedTextOutA = (void *)GetProcAddress(library, "TabbedTextOutA");
	pTabbedTextOutW = (void *)GetProcAddress(library, "TabbedTextOutW");
	pTileChildWindows = (void *)GetProcAddress(library, "TileChildWindows");
	pTileWindows = (void *)GetProcAddress(library, "TileWindows");
	pToAscii = (void *)GetProcAddress(library, "ToAscii");
	pToAsciiEx = (void *)GetProcAddress(library, "ToAsciiEx");
	pToUnicode = (void *)GetProcAddress(library, "ToUnicode");
	pToUnicodeEx = (void *)GetProcAddress(library, "ToUnicodeEx");
	pTrackMouseEvent = (void *)GetProcAddress(library, "TrackMouseEvent");
	pTrackPopupMenu = (void *)GetProcAddress(library, "TrackPopupMenu");
	pTrackPopupMenuEx = (void *)GetProcAddress(library, "TrackPopupMenuEx");
	pTranslateAcceleratorA = (void *)GetProcAddress(library, "TranslateAcceleratorA");
	pTranslateAcceleratorW = (void *)GetProcAddress(library, "TranslateAcceleratorW");
	pTranslateMDISysAccel = (void *)GetProcAddress(library, "TranslateMDISysAccel");
	pTranslateMessage = (void *)GetProcAddress(library, "TranslateMessage");
	pUnhookWinEvent = (void *)GetProcAddress(library, "UnhookWinEvent");
	pUnhookWindowsHook = (void *)GetProcAddress(library, "UnhookWindowsHook");
	pUnhookWindowsHookEx = (void *)GetProcAddress(library, "UnhookWindowsHookEx");
	pUnionRect = (void *)GetProcAddress(library, "UnionRect");
	pUnloadKeyboardLayout = (void *)GetProcAddress(library, "UnloadKeyboardLayout");
	pUnpackDDElParam = (void *)GetProcAddress(library, "UnpackDDElParam");
	pUnregisterClassA = (void *)GetProcAddress(library, "UnregisterClassA");
	pUnregisterClassW = (void *)GetProcAddress(library, "UnregisterClassW");
	pUnregisterDeviceNotification = (void *)GetProcAddress(library, "UnregisterDeviceNotification");
	pUnregisterHotKey = (void *)GetProcAddress(library, "UnregisterHotKey");
	pUnregisterPowerSettingNotification = (void *)GetProcAddress(library, "UnregisterPowerSettingNotification");
	pUnregisterTouchWindow = (void *)GetProcAddress(library, "UnregisterTouchWindow");
	pUpdateLayeredWindow = (void *)GetProcAddress(library, "UpdateLayeredWindow");
	pUpdateLayeredWindowIndirect = (void *)GetProcAddress(library, "UpdateLayeredWindowIndirect");
	pUpdateWindow = (void *)GetProcAddress(library, "UpdateWindow");
	pUser32InitializeImmEntryTable = (void *)GetProcAddress(library, "User32InitializeImmEntryTable");
	pUserClientDllInitialize = (void *)GetProcAddress(library, "UserClientDllInitialize");
	pUserHandleGrantAccess = (void *)GetProcAddress(library, "UserHandleGrantAccess");
	pUserRealizePalette = (void *)GetProcAddress(library, "UserRealizePalette");
	pUserRegisterWowHandlers = (void *)GetProcAddress(library, "UserRegisterWowHandlers");
	pUserSignalProc = (void *)GetProcAddress(library, "UserSignalProc");
	pValidateRect = (void *)GetProcAddress(library, "ValidateRect");
	pValidateRgn = (void *)GetProcAddress(library, "ValidateRgn");
	pVkKeyScanA = (void *)GetProcAddress(library, "VkKeyScanA");
	pVkKeyScanExA = (void *)GetProcAddress(library, "VkKeyScanExA");
	pVkKeyScanExW = (void *)GetProcAddress(library, "VkKeyScanExW");
	pVkKeyScanW = (void *)GetProcAddress(library, "VkKeyScanW");
	pWINNLSEnableIME = (void *)GetProcAddress(library, "WINNLSEnableIME");
	pWINNLSGetEnableStatus = (void *)GetProcAddress(library, "WINNLSGetEnableStatus");
	pWINNLSGetIMEHotkey = (void *)GetProcAddress(library, "WINNLSGetIMEHotkey");
	pWaitForInputIdle = (void *)GetProcAddress(library, "WaitForInputIdle");
	pWaitMessage = (void *)GetProcAddress(library, "WaitMessage");
	pWinHelpA = (void *)GetProcAddress(library, "WinHelpA");
	pWinHelpW = (void *)GetProcAddress(library, "WinHelpW");
	pWindowFromDC = (void *)GetProcAddress(library, "WindowFromDC");
	pWindowFromPoint = (void *)GetProcAddress(library, "WindowFromPoint");
	pkeybd_event = (void *)GetProcAddress(library, "keybd_event");
	pmouse_event = (void *)GetProcAddress(library, "mouse_event");
	pwsprintfA = (void *)GetProcAddress(library, "wsprintfA");
	pwsprintfW = (void *)GetProcAddress(library, "wsprintfW");
	pwvsprintfA = (void *)GetProcAddress(library, "wvsprintfA");
	pwvsprintfW = (void *)GetProcAddress(library, "wvsprintfW");
	p__wine_send_input = (void *)GetProcAddress(library, "__wine_send_input");
	p__wine_set_pixel_format = (void *)GetProcAddress(library, "__wine_set_pixel_format");
	initialized = TRUE;
}

void* wine_thunk_get_for_user32(void *func)
{
	if (!initialized)
		return NULL;

	if (func == pActivateKeyboardLayout)
		return wine32a_user32_ActivateKeyboardLayout;
	if (func == pAddClipboardFormatListener)
		return wine32a_user32_AddClipboardFormatListener;
	if (func == pAdjustWindowRect)
		return wine32a_user32_AdjustWindowRect;
	if (func == pAdjustWindowRectEx)
		return wine32a_user32_AdjustWindowRectEx;
	if (func == pAdjustWindowRectExForDpi)
		return wine32a_user32_AdjustWindowRectExForDpi;
	if (func == pAlignRects)
		return wine32a_user32_AlignRects;
	if (func == pAllowSetForegroundWindow)
		return wine32a_user32_AllowSetForegroundWindow;
	if (func == pAnimateWindow)
		return wine32a_user32_AnimateWindow;
	if (func == pAnyPopup)
		return wine32a_user32_AnyPopup;
	if (func == pAppendMenuA)
		return wine32a_user32_AppendMenuA;
	if (func == pAppendMenuW)
		return wine32a_user32_AppendMenuW;
	if (func == pAreDpiAwarenessContextsEqual)
		return wine32a_user32_AreDpiAwarenessContextsEqual;
	if (func == pArrangeIconicWindows)
		return wine32a_user32_ArrangeIconicWindows;
	if (func == pAttachThreadInput)
		return wine32a_user32_AttachThreadInput;
	if (func == pBeginDeferWindowPos)
		return wine32a_user32_BeginDeferWindowPos;
	if (func == pBeginPaint)
		return wine32a_user32_BeginPaint;
	if (func == pBlockInput)
		return wine32a_user32_BlockInput;
	if (func == pBringWindowToTop)
		return wine32a_user32_BringWindowToTop;
	if (func == pBroadcastSystemMessageA)
		return wine32a_user32_BroadcastSystemMessageA;
	if (func == pBroadcastSystemMessageExA)
		return wine32a_user32_BroadcastSystemMessageExA;
	if (func == pBroadcastSystemMessageExW)
		return wine32a_user32_BroadcastSystemMessageExW;
	if (func == pBroadcastSystemMessageW)
		return wine32a_user32_BroadcastSystemMessageW;
	if (func == pCalcChildScroll)
		return wine32a_user32_CalcChildScroll;
	if (func == pCalcMenuBar)
		return wine32a_user32_CalcMenuBar;
	if (func == pCallMsgFilterA)
		return wine32a_user32_CallMsgFilterA;
	if (func == pCallMsgFilterW)
		return wine32a_user32_CallMsgFilterW;
	if (func == pCallNextHookEx)
		return wine32a_user32_CallNextHookEx;
	if (func == pCallWindowProcA)
		return wine32a_user32_CallWindowProcA;
	if (func == pCallWindowProcW)
		return wine32a_user32_CallWindowProcW;
	if (func == pCascadeChildWindows)
		return wine32a_user32_CascadeChildWindows;
	if (func == pCascadeWindows)
		return wine32a_user32_CascadeWindows;
	if (func == pChangeClipboardChain)
		return wine32a_user32_ChangeClipboardChain;
	if (func == pChangeDisplaySettingsA)
		return wine32a_user32_ChangeDisplaySettingsA;
	if (func == pChangeDisplaySettingsExA)
		return wine32a_user32_ChangeDisplaySettingsExA;
	if (func == pChangeDisplaySettingsExW)
		return wine32a_user32_ChangeDisplaySettingsExW;
	if (func == pChangeDisplaySettingsW)
		return wine32a_user32_ChangeDisplaySettingsW;
	if (func == pChangeMenuA)
		return wine32a_user32_ChangeMenuA;
	if (func == pChangeMenuW)
		return wine32a_user32_ChangeMenuW;
	if (func == pChangeWindowMessageFilter)
		return wine32a_user32_ChangeWindowMessageFilter;
	if (func == pChangeWindowMessageFilterEx)
		return wine32a_user32_ChangeWindowMessageFilterEx;
	if (func == pCharLowerA)
		return wine32a_user32_CharLowerA;
	if (func == pCharLowerBuffA)
		return wine32a_user32_CharLowerBuffA;
	if (func == pCharLowerBuffW)
		return wine32a_user32_CharLowerBuffW;
	if (func == pCharLowerW)
		return wine32a_user32_CharLowerW;
	if (func == pCharNextA)
		return wine32a_user32_CharNextA;
	if (func == pCharNextExA)
		return wine32a_user32_CharNextExA;
	if (func == pCharNextExW)
		return wine32a_user32_CharNextExW;
	if (func == pCharNextW)
		return wine32a_user32_CharNextW;
	if (func == pCharPrevA)
		return wine32a_user32_CharPrevA;
	if (func == pCharPrevExA)
		return wine32a_user32_CharPrevExA;
	if (func == pCharPrevExW)
		return wine32a_user32_CharPrevExW;
	if (func == pCharPrevW)
		return wine32a_user32_CharPrevW;
	if (func == pCharToOemA)
		return wine32a_user32_CharToOemA;
	if (func == pCharToOemBuffA)
		return wine32a_user32_CharToOemBuffA;
	if (func == pCharToOemBuffW)
		return wine32a_user32_CharToOemBuffW;
	if (func == pCharToOemW)
		return wine32a_user32_CharToOemW;
	if (func == pCharUpperA)
		return wine32a_user32_CharUpperA;
	if (func == pCharUpperBuffA)
		return wine32a_user32_CharUpperBuffA;
	if (func == pCharUpperBuffW)
		return wine32a_user32_CharUpperBuffW;
	if (func == pCharUpperW)
		return wine32a_user32_CharUpperW;
	if (func == pCheckDlgButton)
		return wine32a_user32_CheckDlgButton;
	if (func == pCheckMenuItem)
		return wine32a_user32_CheckMenuItem;
	if (func == pCheckMenuRadioItem)
		return wine32a_user32_CheckMenuRadioItem;
	if (func == pCheckRadioButton)
		return wine32a_user32_CheckRadioButton;
	if (func == pChildWindowFromPoint)
		return wine32a_user32_ChildWindowFromPoint;
	if (func == pChildWindowFromPointEx)
		return wine32a_user32_ChildWindowFromPointEx;
	if (func == pClientToScreen)
		return wine32a_user32_ClientToScreen;
	if (func == pClipCursor)
		return wine32a_user32_ClipCursor;
	if (func == pCloseClipboard)
		return wine32a_user32_CloseClipboard;
	if (func == pCloseDesktop)
		return wine32a_user32_CloseDesktop;
	if (func == pCloseTouchInputHandle)
		return wine32a_user32_CloseTouchInputHandle;
	if (func == pCloseWindow)
		return wine32a_user32_CloseWindow;
	if (func == pCloseWindowStation)
		return wine32a_user32_CloseWindowStation;
	if (func == pCopyAcceleratorTableA)
		return wine32a_user32_CopyAcceleratorTableA;
	if (func == pCopyAcceleratorTableW)
		return wine32a_user32_CopyAcceleratorTableW;
	if (func == pCopyIcon)
		return wine32a_user32_CopyIcon;
	if (func == pCopyImage)
		return wine32a_user32_CopyImage;
	if (func == pCopyRect)
		return wine32a_user32_CopyRect;
	if (func == pCountClipboardFormats)
		return wine32a_user32_CountClipboardFormats;
	if (func == pCreateAcceleratorTableA)
		return wine32a_user32_CreateAcceleratorTableA;
	if (func == pCreateAcceleratorTableW)
		return wine32a_user32_CreateAcceleratorTableW;
	if (func == pCreateCaret)
		return wine32a_user32_CreateCaret;
	if (func == pCreateCursor)
		return wine32a_user32_CreateCursor;
	if (func == pCreateDesktopA)
		return wine32a_user32_CreateDesktopA;
	if (func == pCreateDesktopW)
		return wine32a_user32_CreateDesktopW;
	if (func == pCreateDialogIndirectParamA)
		return wine32a_user32_CreateDialogIndirectParamA;
	if (func == pCreateDialogIndirectParamAorW)
		return wine32a_user32_CreateDialogIndirectParamAorW;
	if (func == pCreateDialogIndirectParamW)
		return wine32a_user32_CreateDialogIndirectParamW;
	if (func == pCreateDialogParamA)
		return wine32a_user32_CreateDialogParamA;
	if (func == pCreateDialogParamW)
		return wine32a_user32_CreateDialogParamW;
	if (func == pCreateIcon)
		return wine32a_user32_CreateIcon;
	if (func == pCreateIconFromResource)
		return wine32a_user32_CreateIconFromResource;
	if (func == pCreateIconFromResourceEx)
		return wine32a_user32_CreateIconFromResourceEx;
	if (func == pCreateIconIndirect)
		return wine32a_user32_CreateIconIndirect;
	if (func == pCreateMDIWindowA)
		return wine32a_user32_CreateMDIWindowA;
	if (func == pCreateMDIWindowW)
		return wine32a_user32_CreateMDIWindowW;
	if (func == pCreateMenu)
		return wine32a_user32_CreateMenu;
	if (func == pCreatePopupMenu)
		return wine32a_user32_CreatePopupMenu;
	if (func == pCreateWindowExA)
		return wine32a_user32_CreateWindowExA;
	if (func == pCreateWindowExW)
		return wine32a_user32_CreateWindowExW;
	if (func == pCreateWindowStationA)
		return wine32a_user32_CreateWindowStationA;
	if (func == pCreateWindowStationW)
		return wine32a_user32_CreateWindowStationW;
	if (func == pDdeAbandonTransaction)
		return wine32a_user32_DdeAbandonTransaction;
	if (func == pDdeAccessData)
		return wine32a_user32_DdeAccessData;
	if (func == pDdeAddData)
		return wine32a_user32_DdeAddData;
	if (func == pDdeClientTransaction)
		return wine32a_user32_DdeClientTransaction;
	if (func == pDdeCmpStringHandles)
		return wine32a_user32_DdeCmpStringHandles;
	if (func == pDdeConnect)
		return wine32a_user32_DdeConnect;
	if (func == pDdeConnectList)
		return wine32a_user32_DdeConnectList;
	if (func == pDdeCreateDataHandle)
		return wine32a_user32_DdeCreateDataHandle;
	if (func == pDdeCreateStringHandleA)
		return wine32a_user32_DdeCreateStringHandleA;
	if (func == pDdeCreateStringHandleW)
		return wine32a_user32_DdeCreateStringHandleW;
	if (func == pDdeDisconnect)
		return wine32a_user32_DdeDisconnect;
	if (func == pDdeDisconnectList)
		return wine32a_user32_DdeDisconnectList;
	if (func == pDdeEnableCallback)
		return wine32a_user32_DdeEnableCallback;
	if (func == pDdeFreeDataHandle)
		return wine32a_user32_DdeFreeDataHandle;
	if (func == pDdeFreeStringHandle)
		return wine32a_user32_DdeFreeStringHandle;
	if (func == pDdeGetData)
		return wine32a_user32_DdeGetData;
	if (func == pDdeGetLastError)
		return wine32a_user32_DdeGetLastError;
	if (func == pDdeImpersonateClient)
		return wine32a_user32_DdeImpersonateClient;
	if (func == pDdeInitializeA)
		return wine32a_user32_DdeInitializeA;
	if (func == pDdeInitializeW)
		return wine32a_user32_DdeInitializeW;
	if (func == pDdeKeepStringHandle)
		return wine32a_user32_DdeKeepStringHandle;
	if (func == pDdeNameService)
		return wine32a_user32_DdeNameService;
	if (func == pDdePostAdvise)
		return wine32a_user32_DdePostAdvise;
	if (func == pDdeQueryConvInfo)
		return wine32a_user32_DdeQueryConvInfo;
	if (func == pDdeQueryNextServer)
		return wine32a_user32_DdeQueryNextServer;
	if (func == pDdeQueryStringA)
		return wine32a_user32_DdeQueryStringA;
	if (func == pDdeQueryStringW)
		return wine32a_user32_DdeQueryStringW;
	if (func == pDdeReconnect)
		return wine32a_user32_DdeReconnect;
	if (func == pDdeSetQualityOfService)
		return wine32a_user32_DdeSetQualityOfService;
	if (func == pDdeSetUserHandle)
		return wine32a_user32_DdeSetUserHandle;
	if (func == pDdeUnaccessData)
		return wine32a_user32_DdeUnaccessData;
	if (func == pDdeUninitialize)
		return wine32a_user32_DdeUninitialize;
	if (func == pDefDlgProcA)
		return wine32a_user32_DefDlgProcA;
	if (func == pDefDlgProcW)
		return wine32a_user32_DefDlgProcW;
	if (func == pDefFrameProcA)
		return wine32a_user32_DefFrameProcA;
	if (func == pDefFrameProcW)
		return wine32a_user32_DefFrameProcW;
	if (func == pDefMDIChildProcA)
		return wine32a_user32_DefMDIChildProcA;
	if (func == pDefMDIChildProcW)
		return wine32a_user32_DefMDIChildProcW;
	if (func == pDefRawInputProc)
		return wine32a_user32_DefRawInputProc;
	if (func == pDefWindowProcA)
		return wine32a_user32_DefWindowProcA;
	if (func == pDefWindowProcW)
		return wine32a_user32_DefWindowProcW;
	if (func == pDeferWindowPos)
		return wine32a_user32_DeferWindowPos;
	if (func == pDeleteMenu)
		return wine32a_user32_DeleteMenu;
	if (func == pDeregisterShellHookWindow)
		return wine32a_user32_DeregisterShellHookWindow;
	if (func == pDestroyAcceleratorTable)
		return wine32a_user32_DestroyAcceleratorTable;
	if (func == pDestroyCaret)
		return wine32a_user32_DestroyCaret;
	if (func == pDestroyCursor)
		return wine32a_user32_DestroyCursor;
	if (func == pDestroyIcon)
		return wine32a_user32_DestroyIcon;
	if (func == pDestroyMenu)
		return wine32a_user32_DestroyMenu;
	if (func == pDestroyWindow)
		return wine32a_user32_DestroyWindow;
	if (func == pDialogBoxIndirectParamA)
		return wine32a_user32_DialogBoxIndirectParamA;
	if (func == pDialogBoxIndirectParamAorW)
		return wine32a_user32_DialogBoxIndirectParamAorW;
	if (func == pDialogBoxIndirectParamW)
		return wine32a_user32_DialogBoxIndirectParamW;
	if (func == pDialogBoxParamA)
		return wine32a_user32_DialogBoxParamA;
	if (func == pDialogBoxParamW)
		return wine32a_user32_DialogBoxParamW;
	if (func == pDisableProcessWindowsGhosting)
		return wine32a_user32_DisableProcessWindowsGhosting;
	if (func == pDispatchMessageA)
		return wine32a_user32_DispatchMessageA;
	if (func == pDispatchMessageW)
		return wine32a_user32_DispatchMessageW;
	if (func == pDisplayConfigGetDeviceInfo)
		return wine32a_user32_DisplayConfigGetDeviceInfo;
	if (func == pDlgDirListA)
		return wine32a_user32_DlgDirListA;
	if (func == pDlgDirListComboBoxA)
		return wine32a_user32_DlgDirListComboBoxA;
	if (func == pDlgDirListComboBoxW)
		return wine32a_user32_DlgDirListComboBoxW;
	if (func == pDlgDirListW)
		return wine32a_user32_DlgDirListW;
	if (func == pDlgDirSelectComboBoxExA)
		return wine32a_user32_DlgDirSelectComboBoxExA;
	if (func == pDlgDirSelectComboBoxExW)
		return wine32a_user32_DlgDirSelectComboBoxExW;
	if (func == pDlgDirSelectExA)
		return wine32a_user32_DlgDirSelectExA;
	if (func == pDlgDirSelectExW)
		return wine32a_user32_DlgDirSelectExW;
	if (func == pDragDetect)
		return wine32a_user32_DragDetect;
	if (func == pDrawAnimatedRects)
		return wine32a_user32_DrawAnimatedRects;
	if (func == pDrawCaption)
		return wine32a_user32_DrawCaption;
	if (func == pDrawCaptionTempA)
		return wine32a_user32_DrawCaptionTempA;
	if (func == pDrawCaptionTempW)
		return wine32a_user32_DrawCaptionTempW;
	if (func == pDrawEdge)
		return wine32a_user32_DrawEdge;
	if (func == pDrawFocusRect)
		return wine32a_user32_DrawFocusRect;
	if (func == pDrawFrameControl)
		return wine32a_user32_DrawFrameControl;
	if (func == pDrawIcon)
		return wine32a_user32_DrawIcon;
	if (func == pDrawIconEx)
		return wine32a_user32_DrawIconEx;
	if (func == pDrawMenuBar)
		return wine32a_user32_DrawMenuBar;
	if (func == pDrawMenuBarTemp)
		return wine32a_user32_DrawMenuBarTemp;
	if (func == pDrawStateA)
		return wine32a_user32_DrawStateA;
	if (func == pDrawStateW)
		return wine32a_user32_DrawStateW;
	if (func == pDrawTextA)
		return wine32a_user32_DrawTextA;
	if (func == pDrawTextExA)
		return wine32a_user32_DrawTextExA;
	if (func == pDrawTextExW)
		return wine32a_user32_DrawTextExW;
	if (func == pDrawTextW)
		return wine32a_user32_DrawTextW;
	if (func == pEditWndProc)
		return wine32a_user32_EditWndProc;
	if (func == pEmptyClipboard)
		return wine32a_user32_EmptyClipboard;
	if (func == pEnableMenuItem)
		return wine32a_user32_EnableMenuItem;
	if (func == pEnableMouseInPointer)
		return wine32a_user32_EnableMouseInPointer;
	if (func == pEnableScrollBar)
		return wine32a_user32_EnableScrollBar;
	if (func == pEnableWindow)
		return wine32a_user32_EnableWindow;
	if (func == pEndDeferWindowPos)
		return wine32a_user32_EndDeferWindowPos;
	if (func == pEndDialog)
		return wine32a_user32_EndDialog;
	if (func == pEndMenu)
		return wine32a_user32_EndMenu;
	if (func == pEndPaint)
		return wine32a_user32_EndPaint;
	if (func == pEnumChildWindows)
		return wine32a_user32_EnumChildWindows;
	if (func == pEnumClipboardFormats)
		return wine32a_user32_EnumClipboardFormats;
	if (func == pEnumDesktopWindows)
		return wine32a_user32_EnumDesktopWindows;
	if (func == pEnumDesktopsA)
		return wine32a_user32_EnumDesktopsA;
	if (func == pEnumDesktopsW)
		return wine32a_user32_EnumDesktopsW;
	if (func == pEnumDisplayDevicesA)
		return wine32a_user32_EnumDisplayDevicesA;
	if (func == pEnumDisplayDevicesW)
		return wine32a_user32_EnumDisplayDevicesW;
	if (func == pEnumDisplayMonitors)
		return wine32a_user32_EnumDisplayMonitors;
	if (func == pEnumDisplaySettingsA)
		return wine32a_user32_EnumDisplaySettingsA;
	if (func == pEnumDisplaySettingsExA)
		return wine32a_user32_EnumDisplaySettingsExA;
	if (func == pEnumDisplaySettingsExW)
		return wine32a_user32_EnumDisplaySettingsExW;
	if (func == pEnumDisplaySettingsW)
		return wine32a_user32_EnumDisplaySettingsW;
	if (func == pEnumPropsA)
		return wine32a_user32_EnumPropsA;
	if (func == pEnumPropsExA)
		return wine32a_user32_EnumPropsExA;
	if (func == pEnumPropsExW)
		return wine32a_user32_EnumPropsExW;
	if (func == pEnumPropsW)
		return wine32a_user32_EnumPropsW;
	if (func == pEnumThreadWindows)
		return wine32a_user32_EnumThreadWindows;
	if (func == pEnumWindowStationsA)
		return wine32a_user32_EnumWindowStationsA;
	if (func == pEnumWindowStationsW)
		return wine32a_user32_EnumWindowStationsW;
	if (func == pEnumWindows)
		return wine32a_user32_EnumWindows;
	if (func == pEqualRect)
		return wine32a_user32_EqualRect;
	if (func == pExcludeUpdateRgn)
		return wine32a_user32_ExcludeUpdateRgn;
	if (func == pExitWindowsEx)
		return wine32a_user32_ExitWindowsEx;
	if (func == pFillRect)
		return wine32a_user32_FillRect;
	if (func == pFindWindowA)
		return wine32a_user32_FindWindowA;
	if (func == pFindWindowExA)
		return wine32a_user32_FindWindowExA;
	if (func == pFindWindowExW)
		return wine32a_user32_FindWindowExW;
	if (func == pFindWindowW)
		return wine32a_user32_FindWindowW;
	if (func == pFlashWindow)
		return wine32a_user32_FlashWindow;
	if (func == pFlashWindowEx)
		return wine32a_user32_FlashWindowEx;
	if (func == pFrameRect)
		return wine32a_user32_FrameRect;
	if (func == pFreeDDElParam)
		return wine32a_user32_FreeDDElParam;
	if (func == pGetActiveWindow)
		return wine32a_user32_GetActiveWindow;
	if (func == pGetAltTabInfoA)
		return wine32a_user32_GetAltTabInfoA;
	if (func == pGetAltTabInfoW)
		return wine32a_user32_GetAltTabInfoW;
	if (func == pGetAncestor)
		return wine32a_user32_GetAncestor;
	if (func == pGetAppCompatFlags)
		return wine32a_user32_GetAppCompatFlags;
	if (func == pGetAppCompatFlags2)
		return wine32a_user32_GetAppCompatFlags2;
	if (func == pGetAsyncKeyState)
		return wine32a_user32_GetAsyncKeyState;
	if (func == pGetAutoRotationState)
		return wine32a_user32_GetAutoRotationState;
	if (func == pGetAwarenessFromDpiAwarenessContext)
		return wine32a_user32_GetAwarenessFromDpiAwarenessContext;
	if (func == pGetCapture)
		return wine32a_user32_GetCapture;
	if (func == pGetCaretBlinkTime)
		return wine32a_user32_GetCaretBlinkTime;
	if (func == pGetCaretPos)
		return wine32a_user32_GetCaretPos;
	if (func == pGetClassInfoA)
		return wine32a_user32_GetClassInfoA;
	if (func == pGetClassInfoExA)
		return wine32a_user32_GetClassInfoExA;
	if (func == pGetClassInfoExW)
		return wine32a_user32_GetClassInfoExW;
	if (func == pGetClassInfoW)
		return wine32a_user32_GetClassInfoW;
	if (func == pGetClassLongA)
		return wine32a_user32_GetClassLongA;
	if (func == pGetClassLongW)
		return wine32a_user32_GetClassLongW;
	if (func == pGetClassLongPtrA)
		return wine32a_user32_GetClassLongPtrA;
	if (func == pGetClassLongPtrW)
		return wine32a_user32_GetClassLongPtrW;
	if (func == pGetClassNameA)
		return wine32a_user32_GetClassNameA;
	if (func == pGetClassNameW)
		return wine32a_user32_GetClassNameW;
	if (func == pGetClassWord)
		return wine32a_user32_GetClassWord;
	if (func == pGetClientRect)
		return wine32a_user32_GetClientRect;
	if (func == pGetClipCursor)
		return wine32a_user32_GetClipCursor;
	if (func == pGetClipboardData)
		return wine32a_user32_GetClipboardData;
	if (func == pGetClipboardFormatNameA)
		return wine32a_user32_GetClipboardFormatNameA;
	if (func == pGetClipboardFormatNameW)
		return wine32a_user32_GetClipboardFormatNameW;
	if (func == pGetClipboardOwner)
		return wine32a_user32_GetClipboardOwner;
	if (func == pGetClipboardSequenceNumber)
		return wine32a_user32_GetClipboardSequenceNumber;
	if (func == pGetClipboardViewer)
		return wine32a_user32_GetClipboardViewer;
	if (func == pGetComboBoxInfo)
		return wine32a_user32_GetComboBoxInfo;
	if (func == pGetCurrentInputMessageSource)
		return wine32a_user32_GetCurrentInputMessageSource;
	if (func == pGetCursor)
		return wine32a_user32_GetCursor;
	if (func == pGetCursorFrameInfo)
		return wine32a_user32_GetCursorFrameInfo;
	if (func == pGetCursorInfo)
		return wine32a_user32_GetCursorInfo;
	if (func == pGetCursorPos)
		return wine32a_user32_GetCursorPos;
	if (func == pGetDC)
		return wine32a_user32_GetDC;
	if (func == pGetDCEx)
		return wine32a_user32_GetDCEx;
	if (func == pGetDesktopWindow)
		return wine32a_user32_GetDesktopWindow;
	if (func == pGetDialogBaseUnits)
		return wine32a_user32_GetDialogBaseUnits;
	if (func == pGetDisplayAutoRotationPreferences)
		return wine32a_user32_GetDisplayAutoRotationPreferences;
	if (func == pGetDisplayConfigBufferSizes)
		return wine32a_user32_GetDisplayConfigBufferSizes;
	if (func == pGetDlgCtrlID)
		return wine32a_user32_GetDlgCtrlID;
	if (func == pGetDlgItem)
		return wine32a_user32_GetDlgItem;
	if (func == pGetDlgItemInt)
		return wine32a_user32_GetDlgItemInt;
	if (func == pGetDlgItemTextA)
		return wine32a_user32_GetDlgItemTextA;
	if (func == pGetDlgItemTextW)
		return wine32a_user32_GetDlgItemTextW;
	if (func == pGetDoubleClickTime)
		return wine32a_user32_GetDoubleClickTime;
	if (func == pGetDpiForMonitorInternal)
		return wine32a_user32_GetDpiForMonitorInternal;
	if (func == pGetDpiForSystem)
		return wine32a_user32_GetDpiForSystem;
	if (func == pGetDpiForWindow)
		return wine32a_user32_GetDpiForWindow;
	if (func == pGetFocus)
		return wine32a_user32_GetFocus;
	if (func == pGetForegroundWindow)
		return wine32a_user32_GetForegroundWindow;
	if (func == pGetGestureConfig)
		return wine32a_user32_GetGestureConfig;
	if (func == pGetGestureInfo)
		return wine32a_user32_GetGestureInfo;
	if (func == pGetGUIThreadInfo)
		return wine32a_user32_GetGUIThreadInfo;
	if (func == pGetGuiResources)
		return wine32a_user32_GetGuiResources;
	if (func == pGetIconInfo)
		return wine32a_user32_GetIconInfo;
	if (func == pGetIconInfoExA)
		return wine32a_user32_GetIconInfoExA;
	if (func == pGetIconInfoExW)
		return wine32a_user32_GetIconInfoExW;
	if (func == pGetInputState)
		return wine32a_user32_GetInputState;
	if (func == pGetInternalWindowPos)
		return wine32a_user32_GetInternalWindowPos;
	if (func == pGetKBCodePage)
		return wine32a_user32_GetKBCodePage;
	if (func == pGetKeyNameTextA)
		return wine32a_user32_GetKeyNameTextA;
	if (func == pGetKeyNameTextW)
		return wine32a_user32_GetKeyNameTextW;
	if (func == pGetKeyState)
		return wine32a_user32_GetKeyState;
	if (func == pGetKeyboardLayout)
		return wine32a_user32_GetKeyboardLayout;
	if (func == pGetKeyboardLayoutList)
		return wine32a_user32_GetKeyboardLayoutList;
	if (func == pGetKeyboardLayoutNameA)
		return wine32a_user32_GetKeyboardLayoutNameA;
	if (func == pGetKeyboardLayoutNameW)
		return wine32a_user32_GetKeyboardLayoutNameW;
	if (func == pGetKeyboardState)
		return wine32a_user32_GetKeyboardState;
	if (func == pGetKeyboardType)
		return wine32a_user32_GetKeyboardType;
	if (func == pGetLastActivePopup)
		return wine32a_user32_GetLastActivePopup;
	if (func == pGetLastInputInfo)
		return wine32a_user32_GetLastInputInfo;
	if (func == pGetLayeredWindowAttributes)
		return wine32a_user32_GetLayeredWindowAttributes;
	if (func == pGetListBoxInfo)
		return wine32a_user32_GetListBoxInfo;
	if (func == pGetMenu)
		return wine32a_user32_GetMenu;
	if (func == pGetMenuBarInfo)
		return wine32a_user32_GetMenuBarInfo;
	if (func == pGetMenuCheckMarkDimensions)
		return wine32a_user32_GetMenuCheckMarkDimensions;
	if (func == pGetMenuContextHelpId)
		return wine32a_user32_GetMenuContextHelpId;
	if (func == pGetMenuDefaultItem)
		return wine32a_user32_GetMenuDefaultItem;
	if (func == pGetMenuInfo)
		return wine32a_user32_GetMenuInfo;
	if (func == pGetMenuItemCount)
		return wine32a_user32_GetMenuItemCount;
	if (func == pGetMenuItemID)
		return wine32a_user32_GetMenuItemID;
	if (func == pGetMenuItemInfoA)
		return wine32a_user32_GetMenuItemInfoA;
	if (func == pGetMenuItemInfoW)
		return wine32a_user32_GetMenuItemInfoW;
	if (func == pGetMenuItemRect)
		return wine32a_user32_GetMenuItemRect;
	if (func == pGetMenuState)
		return wine32a_user32_GetMenuState;
	if (func == pGetMenuStringA)
		return wine32a_user32_GetMenuStringA;
	if (func == pGetMenuStringW)
		return wine32a_user32_GetMenuStringW;
	if (func == pGetMessageA)
		return wine32a_user32_GetMessageA;
	if (func == pGetMessageExtraInfo)
		return wine32a_user32_GetMessageExtraInfo;
	if (func == pGetMessagePos)
		return wine32a_user32_GetMessagePos;
	if (func == pGetMessageTime)
		return wine32a_user32_GetMessageTime;
	if (func == pGetMessageW)
		return wine32a_user32_GetMessageW;
	if (func == pGetMonitorInfoA)
		return wine32a_user32_GetMonitorInfoA;
	if (func == pGetMonitorInfoW)
		return wine32a_user32_GetMonitorInfoW;
	if (func == pGetMouseMovePointsEx)
		return wine32a_user32_GetMouseMovePointsEx;
	if (func == pGetNextDlgGroupItem)
		return wine32a_user32_GetNextDlgGroupItem;
	if (func == pGetNextDlgTabItem)
		return wine32a_user32_GetNextDlgTabItem;
	if (func == pGetOpenClipboardWindow)
		return wine32a_user32_GetOpenClipboardWindow;
	if (func == pGetParent)
		return wine32a_user32_GetParent;
	if (func == pGetPhysicalCursorPos)
		return wine32a_user32_GetPhysicalCursorPos;
	if (func == pGetPointerDevices)
		return wine32a_user32_GetPointerDevices;
	if (func == pGetPointerType)
		return wine32a_user32_GetPointerType;
	if (func == pGetPriorityClipboardFormat)
		return wine32a_user32_GetPriorityClipboardFormat;
	if (func == pGetProcessDefaultLayout)
		return wine32a_user32_GetProcessDefaultLayout;
	if (func == pGetProcessDpiAwarenessInternal)
		return wine32a_user32_GetProcessDpiAwarenessInternal;
	if (func == pGetProcessWindowStation)
		return wine32a_user32_GetProcessWindowStation;
	if (func == pGetProgmanWindow)
		return wine32a_user32_GetProgmanWindow;
	if (func == pGetPropA)
		return wine32a_user32_GetPropA;
	if (func == pGetPropW)
		return wine32a_user32_GetPropW;
	if (func == pGetQueueStatus)
		return wine32a_user32_GetQueueStatus;
	if (func == pGetRawInputBuffer)
		return wine32a_user32_GetRawInputBuffer;
	if (func == pGetRawInputData)
		return wine32a_user32_GetRawInputData;
	if (func == pGetRawInputDeviceInfoA)
		return wine32a_user32_GetRawInputDeviceInfoA;
	if (func == pGetRawInputDeviceInfoW)
		return wine32a_user32_GetRawInputDeviceInfoW;
	if (func == pGetRawInputDeviceList)
		return wine32a_user32_GetRawInputDeviceList;
	if (func == pGetRegisteredRawInputDevices)
		return wine32a_user32_GetRegisteredRawInputDevices;
	if (func == pGetScrollBarInfo)
		return wine32a_user32_GetScrollBarInfo;
	if (func == pGetScrollInfo)
		return wine32a_user32_GetScrollInfo;
	if (func == pGetScrollPos)
		return wine32a_user32_GetScrollPos;
	if (func == pGetScrollRange)
		return wine32a_user32_GetScrollRange;
	if (func == pGetShellWindow)
		return wine32a_user32_GetShellWindow;
	if (func == pGetSubMenu)
		return wine32a_user32_GetSubMenu;
	if (func == pGetSysColor)
		return wine32a_user32_GetSysColor;
	if (func == pGetSysColorBrush)
		return wine32a_user32_GetSysColorBrush;
	if (func == pGetSystemMenu)
		return wine32a_user32_GetSystemMenu;
	if (func == pGetSystemMetrics)
		return wine32a_user32_GetSystemMetrics;
	if (func == pGetSystemMetricsForDpi)
		return wine32a_user32_GetSystemMetricsForDpi;
	if (func == pGetTabbedTextExtentA)
		return wine32a_user32_GetTabbedTextExtentA;
	if (func == pGetTabbedTextExtentW)
		return wine32a_user32_GetTabbedTextExtentW;
	if (func == pGetTaskmanWindow)
		return wine32a_user32_GetTaskmanWindow;
	if (func == pGetThreadDesktop)
		return wine32a_user32_GetThreadDesktop;
	if (func == pGetThreadDpiAwarenessContext)
		return wine32a_user32_GetThreadDpiAwarenessContext;
	if (func == pGetTitleBarInfo)
		return wine32a_user32_GetTitleBarInfo;
	if (func == pGetTopWindow)
		return wine32a_user32_GetTopWindow;
	if (func == pGetTouchInputInfo)
		return wine32a_user32_GetTouchInputInfo;
	if (func == pGetUpdateRect)
		return wine32a_user32_GetUpdateRect;
	if (func == pGetUpdateRgn)
		return wine32a_user32_GetUpdateRgn;
	if (func == pGetUpdatedClipboardFormats)
		return wine32a_user32_GetUpdatedClipboardFormats;
	if (func == pGetUserObjectInformationA)
		return wine32a_user32_GetUserObjectInformationA;
	if (func == pGetUserObjectInformationW)
		return wine32a_user32_GetUserObjectInformationW;
	if (func == pGetUserObjectSecurity)
		return wine32a_user32_GetUserObjectSecurity;
	if (func == pGetWindow)
		return wine32a_user32_GetWindow;
	if (func == pGetWindowContextHelpId)
		return wine32a_user32_GetWindowContextHelpId;
	if (func == pGetWindowDC)
		return wine32a_user32_GetWindowDC;
	if (func == pGetWindowDisplayAffinity)
		return wine32a_user32_GetWindowDisplayAffinity;
	if (func == pGetWindowDpiAwarenessContext)
		return wine32a_user32_GetWindowDpiAwarenessContext;
	if (func == pGetWindowInfo)
		return wine32a_user32_GetWindowInfo;
	if (func == pGetWindowLongA)
		return wine32a_user32_GetWindowLongA;
	if (func == pGetWindowLongPtrA)
		return wine32a_user32_GetWindowLongPtrA;
	if (func == pGetWindowLongPtrW)
		return wine32a_user32_GetWindowLongPtrW;
	if (func == pGetWindowLongW)
		return wine32a_user32_GetWindowLongW;
	if (func == pGetWindowModuleFileNameA)
		return wine32a_user32_GetWindowModuleFileNameA;
	if (func == pGetWindowModuleFileNameW)
		return wine32a_user32_GetWindowModuleFileNameW;
	if (func == pGetWindowPlacement)
		return wine32a_user32_GetWindowPlacement;
	if (func == pGetWindowRect)
		return wine32a_user32_GetWindowRect;
	if (func == pGetWindowRgn)
		return wine32a_user32_GetWindowRgn;
	if (func == pGetWindowRgnBox)
		return wine32a_user32_GetWindowRgnBox;
	if (func == pGetWindowTextA)
		return wine32a_user32_GetWindowTextA;
	if (func == pGetWindowTextLengthA)
		return wine32a_user32_GetWindowTextLengthA;
	if (func == pGetWindowTextLengthW)
		return wine32a_user32_GetWindowTextLengthW;
	if (func == pGetWindowTextW)
		return wine32a_user32_GetWindowTextW;
	if (func == pGetWindowThreadProcessId)
		return wine32a_user32_GetWindowThreadProcessId;
	if (func == pGetWindowWord)
		return wine32a_user32_GetWindowWord;
	if (func == pGrayStringA)
		return wine32a_user32_GrayStringA;
	if (func == pGrayStringW)
		return wine32a_user32_GrayStringW;
	if (func == pHideCaret)
		return wine32a_user32_HideCaret;
	if (func == pHiliteMenuItem)
		return wine32a_user32_HiliteMenuItem;
	if (func == pImpersonateDdeClientWindow)
		return wine32a_user32_ImpersonateDdeClientWindow;
	if (func == pInSendMessage)
		return wine32a_user32_InSendMessage;
	if (func == pInSendMessageEx)
		return wine32a_user32_InSendMessageEx;
	if (func == pInflateRect)
		return wine32a_user32_InflateRect;
	if (func == pInsertMenuA)
		return wine32a_user32_InsertMenuA;
	if (func == pInsertMenuItemA)
		return wine32a_user32_InsertMenuItemA;
	if (func == pInsertMenuItemW)
		return wine32a_user32_InsertMenuItemW;
	if (func == pInsertMenuW)
		return wine32a_user32_InsertMenuW;
	if (func == pInternalGetWindowText)
		return wine32a_user32_InternalGetWindowText;
	if (func == pIntersectRect)
		return wine32a_user32_IntersectRect;
	if (func == pInvalidateRect)
		return wine32a_user32_InvalidateRect;
	if (func == pInvalidateRgn)
		return wine32a_user32_InvalidateRgn;
	if (func == pInvertRect)
		return wine32a_user32_InvertRect;
	if (func == pIsCharAlphaA)
		return wine32a_user32_IsCharAlphaA;
	if (func == pIsCharAlphaNumericA)
		return wine32a_user32_IsCharAlphaNumericA;
	if (func == pIsCharAlphaNumericW)
		return wine32a_user32_IsCharAlphaNumericW;
	if (func == pIsCharAlphaW)
		return wine32a_user32_IsCharAlphaW;
	if (func == pIsCharLowerA)
		return wine32a_user32_IsCharLowerA;
	if (func == pIsCharLowerW)
		return wine32a_user32_IsCharLowerW;
	if (func == pIsCharUpperA)
		return wine32a_user32_IsCharUpperA;
	if (func == pIsCharUpperW)
		return wine32a_user32_IsCharUpperW;
	if (func == pIsChild)
		return wine32a_user32_IsChild;
	if (func == pIsClipboardFormatAvailable)
		return wine32a_user32_IsClipboardFormatAvailable;
	if (func == pIsDialogMessageA)
		return wine32a_user32_IsDialogMessageA;
	if (func == pIsDialogMessageW)
		return wine32a_user32_IsDialogMessageW;
	if (func == pIsDlgButtonChecked)
		return wine32a_user32_IsDlgButtonChecked;
	if (func == pIsGUIThread)
		return wine32a_user32_IsGUIThread;
	if (func == pIsHungAppWindow)
		return wine32a_user32_IsHungAppWindow;
	if (func == pIsIconic)
		return wine32a_user32_IsIconic;
	if (func == pIsMenu)
		return wine32a_user32_IsMenu;
	if (func == pIsProcessDPIAware)
		return wine32a_user32_IsProcessDPIAware;
	if (func == pIsRectEmpty)
		return wine32a_user32_IsRectEmpty;
	if (func == pIsTouchWindow)
		return wine32a_user32_IsTouchWindow;
	if (func == pIsValidDpiAwarenessContext)
		return wine32a_user32_IsValidDpiAwarenessContext;
	if (func == pIsWinEventHookInstalled)
		return wine32a_user32_IsWinEventHookInstalled;
	if (func == pIsWindow)
		return wine32a_user32_IsWindow;
	if (func == pIsWindowEnabled)
		return wine32a_user32_IsWindowEnabled;
	if (func == pIsWindowRedirectedForPrint)
		return wine32a_user32_IsWindowRedirectedForPrint;
	if (func == pIsWindowUnicode)
		return wine32a_user32_IsWindowUnicode;
	if (func == pIsWindowVisible)
		return wine32a_user32_IsWindowVisible;
	if (func == pIsZoomed)
		return wine32a_user32_IsZoomed;
	if (func == pKillSystemTimer)
		return wine32a_user32_KillSystemTimer;
	if (func == pKillTimer)
		return wine32a_user32_KillTimer;
	if (func == pLoadAcceleratorsA)
		return wine32a_user32_LoadAcceleratorsA;
	if (func == pLoadAcceleratorsW)
		return wine32a_user32_LoadAcceleratorsW;
	if (func == pLoadBitmapA)
		return wine32a_user32_LoadBitmapA;
	if (func == pLoadBitmapW)
		return wine32a_user32_LoadBitmapW;
	if (func == pLoadCursorA)
		return wine32a_user32_LoadCursorA;
	if (func == pLoadCursorFromFileA)
		return wine32a_user32_LoadCursorFromFileA;
	if (func == pLoadCursorFromFileW)
		return wine32a_user32_LoadCursorFromFileW;
	if (func == pLoadCursorW)
		return wine32a_user32_LoadCursorW;
	if (func == pLoadIconA)
		return wine32a_user32_LoadIconA;
	if (func == pLoadIconW)
		return wine32a_user32_LoadIconW;
	if (func == pLoadImageA)
		return wine32a_user32_LoadImageA;
	if (func == pLoadImageW)
		return wine32a_user32_LoadImageW;
	if (func == pLoadKeyboardLayoutA)
		return wine32a_user32_LoadKeyboardLayoutA;
	if (func == pLoadKeyboardLayoutW)
		return wine32a_user32_LoadKeyboardLayoutW;
	if (func == pLoadLocalFonts)
		return wine32a_user32_LoadLocalFonts;
	if (func == pLoadMenuA)
		return wine32a_user32_LoadMenuA;
	if (func == pLoadMenuIndirectA)
		return wine32a_user32_LoadMenuIndirectA;
	if (func == pLoadMenuIndirectW)
		return wine32a_user32_LoadMenuIndirectW;
	if (func == pLoadMenuW)
		return wine32a_user32_LoadMenuW;
	if (func == pLoadStringA)
		return wine32a_user32_LoadStringA;
	if (func == pLoadStringW)
		return wine32a_user32_LoadStringW;
	if (func == pLockSetForegroundWindow)
		return wine32a_user32_LockSetForegroundWindow;
	if (func == pLockWindowUpdate)
		return wine32a_user32_LockWindowUpdate;
	if (func == pLockWorkStation)
		return wine32a_user32_LockWorkStation;
	if (func == pLogicalToPhysicalPoint)
		return wine32a_user32_LogicalToPhysicalPoint;
	if (func == pLogicalToPhysicalPointForPerMonitorDPI)
		return wine32a_user32_LogicalToPhysicalPointForPerMonitorDPI;
	if (func == pLookupIconIdFromDirectory)
		return wine32a_user32_LookupIconIdFromDirectory;
	if (func == pLookupIconIdFromDirectoryEx)
		return wine32a_user32_LookupIconIdFromDirectoryEx;
	if (func == pMapDialogRect)
		return wine32a_user32_MapDialogRect;
	if (func == pMapVirtualKeyA)
		return wine32a_user32_MapVirtualKeyA;
	if (func == pMapVirtualKeyExA)
		return wine32a_user32_MapVirtualKeyExA;
	if (func == pMapVirtualKeyExW)
		return wine32a_user32_MapVirtualKeyExW;
	if (func == pMapVirtualKeyW)
		return wine32a_user32_MapVirtualKeyW;
	if (func == pMapWindowPoints)
		return wine32a_user32_MapWindowPoints;
	if (func == pMenuItemFromPoint)
		return wine32a_user32_MenuItemFromPoint;
	if (func == pMessageBeep)
		return wine32a_user32_MessageBeep;
	if (func == pMessageBoxA)
		return wine32a_user32_MessageBoxA;
	if (func == pMessageBoxExA)
		return wine32a_user32_MessageBoxExA;
	if (func == pMessageBoxExW)
		return wine32a_user32_MessageBoxExW;
	if (func == pMessageBoxIndirectA)
		return wine32a_user32_MessageBoxIndirectA;
	if (func == pMessageBoxIndirectW)
		return wine32a_user32_MessageBoxIndirectW;
	if (func == pMessageBoxTimeoutA)
		return wine32a_user32_MessageBoxTimeoutA;
	if (func == pMessageBoxTimeoutW)
		return wine32a_user32_MessageBoxTimeoutW;
	if (func == pMessageBoxW)
		return wine32a_user32_MessageBoxW;
	if (func == pModifyMenuA)
		return wine32a_user32_ModifyMenuA;
	if (func == pModifyMenuW)
		return wine32a_user32_ModifyMenuW;
	if (func == pMonitorFromPoint)
		return wine32a_user32_MonitorFromPoint;
	if (func == pMonitorFromRect)
		return wine32a_user32_MonitorFromRect;
	if (func == pMonitorFromWindow)
		return wine32a_user32_MonitorFromWindow;
	if (func == pMoveWindow)
		return wine32a_user32_MoveWindow;
	if (func == pMsgWaitForMultipleObjects)
		return wine32a_user32_MsgWaitForMultipleObjects;
	if (func == pMsgWaitForMultipleObjectsEx)
		return wine32a_user32_MsgWaitForMultipleObjectsEx;
	if (func == pNotifyWinEvent)
		return wine32a_user32_NotifyWinEvent;
	if (func == pOemKeyScan)
		return wine32a_user32_OemKeyScan;
	if (func == pOemToCharA)
		return wine32a_user32_OemToCharA;
	if (func == pOemToCharBuffA)
		return wine32a_user32_OemToCharBuffA;
	if (func == pOemToCharBuffW)
		return wine32a_user32_OemToCharBuffW;
	if (func == pOemToCharW)
		return wine32a_user32_OemToCharW;
	if (func == pOffsetRect)
		return wine32a_user32_OffsetRect;
	if (func == pOpenClipboard)
		return wine32a_user32_OpenClipboard;
	if (func == pOpenDesktopA)
		return wine32a_user32_OpenDesktopA;
	if (func == pOpenDesktopW)
		return wine32a_user32_OpenDesktopW;
	if (func == pOpenIcon)
		return wine32a_user32_OpenIcon;
	if (func == pOpenInputDesktop)
		return wine32a_user32_OpenInputDesktop;
	if (func == pOpenWindowStationA)
		return wine32a_user32_OpenWindowStationA;
	if (func == pOpenWindowStationW)
		return wine32a_user32_OpenWindowStationW;
	if (func == pPackDDElParam)
		return wine32a_user32_PackDDElParam;
	if (func == pPaintDesktop)
		return wine32a_user32_PaintDesktop;
	if (func == pPeekMessageA)
		return wine32a_user32_PeekMessageA;
	if (func == pPeekMessageW)
		return wine32a_user32_PeekMessageW;
	if (func == pPhysicalToLogicalPoint)
		return wine32a_user32_PhysicalToLogicalPoint;
	if (func == pPhysicalToLogicalPointForPerMonitorDPI)
		return wine32a_user32_PhysicalToLogicalPointForPerMonitorDPI;
	if (func == pPostMessageA)
		return wine32a_user32_PostMessageA;
	if (func == pPostMessageW)
		return wine32a_user32_PostMessageW;
	if (func == pPostQuitMessage)
		return wine32a_user32_PostQuitMessage;
	if (func == pPostThreadMessageA)
		return wine32a_user32_PostThreadMessageA;
	if (func == pPostThreadMessageW)
		return wine32a_user32_PostThreadMessageW;
	if (func == pPrintWindow)
		return wine32a_user32_PrintWindow;
	if (func == pPrivateExtractIconExA)
		return wine32a_user32_PrivateExtractIconExA;
	if (func == pPrivateExtractIconExW)
		return wine32a_user32_PrivateExtractIconExW;
	if (func == pPrivateExtractIconsA)
		return wine32a_user32_PrivateExtractIconsA;
	if (func == pPrivateExtractIconsW)
		return wine32a_user32_PrivateExtractIconsW;
	if (func == pPtInRect)
		return wine32a_user32_PtInRect;
	if (func == pQueryDisplayConfig)
		return wine32a_user32_QueryDisplayConfig;
	if (func == pRealChildWindowFromPoint)
		return wine32a_user32_RealChildWindowFromPoint;
	if (func == pRealGetWindowClassA)
		return wine32a_user32_RealGetWindowClassA;
	if (func == pRealGetWindowClassW)
		return wine32a_user32_RealGetWindowClassW;
	if (func == pRedrawWindow)
		return wine32a_user32_RedrawWindow;
	if (func == pRegisterClassA)
		return wine32a_user32_RegisterClassA;
	if (func == pRegisterClassExA)
		return wine32a_user32_RegisterClassExA;
	if (func == pRegisterClassExW)
		return wine32a_user32_RegisterClassExW;
	if (func == pRegisterClassW)
		return wine32a_user32_RegisterClassW;
	if (func == pRegisterClipboardFormatA)
		return wine32a_user32_RegisterClipboardFormatA;
	if (func == pRegisterClipboardFormatW)
		return wine32a_user32_RegisterClipboardFormatW;
	if (func == pRegisterDeviceNotificationA)
		return wine32a_user32_RegisterDeviceNotificationA;
	if (func == pRegisterDeviceNotificationW)
		return wine32a_user32_RegisterDeviceNotificationW;
	if (func == pRegisterHotKey)
		return wine32a_user32_RegisterHotKey;
	if (func == pRegisterLogonProcess)
		return wine32a_user32_RegisterLogonProcess;
	if (func == pRegisterPointerDeviceNotifications)
		return wine32a_user32_RegisterPointerDeviceNotifications;
	if (func == pRegisterPowerSettingNotification)
		return wine32a_user32_RegisterPowerSettingNotification;
	if (func == pRegisterRawInputDevices)
		return wine32a_user32_RegisterRawInputDevices;
	if (func == pRegisterServicesProcess)
		return wine32a_user32_RegisterServicesProcess;
	if (func == pRegisterShellHookWindow)
		return wine32a_user32_RegisterShellHookWindow;
	if (func == pRegisterSystemThread)
		return wine32a_user32_RegisterSystemThread;
	if (func == pRegisterTasklist)
		return wine32a_user32_RegisterTasklist;
	if (func == pRegisterTouchHitTestingWindow)
		return wine32a_user32_RegisterTouchHitTestingWindow;
	if (func == pRegisterTouchWindow)
		return wine32a_user32_RegisterTouchWindow;
	if (func == pRegisterWindowMessageA)
		return wine32a_user32_RegisterWindowMessageA;
	if (func == pRegisterWindowMessageW)
		return wine32a_user32_RegisterWindowMessageW;
	if (func == pReleaseCapture)
		return wine32a_user32_ReleaseCapture;
	if (func == pReleaseDC)
		return wine32a_user32_ReleaseDC;
	if (func == pRemoveClipboardFormatListener)
		return wine32a_user32_RemoveClipboardFormatListener;
	if (func == pRemoveMenu)
		return wine32a_user32_RemoveMenu;
	if (func == pRemovePropA)
		return wine32a_user32_RemovePropA;
	if (func == pRemovePropW)
		return wine32a_user32_RemovePropW;
	if (func == pReplyMessage)
		return wine32a_user32_ReplyMessage;
	if (func == pReuseDDElParam)
		return wine32a_user32_ReuseDDElParam;
	if (func == pScreenToClient)
		return wine32a_user32_ScreenToClient;
	if (func == pScrollChildren)
		return wine32a_user32_ScrollChildren;
	if (func == pScrollDC)
		return wine32a_user32_ScrollDC;
	if (func == pScrollWindow)
		return wine32a_user32_ScrollWindow;
	if (func == pScrollWindowEx)
		return wine32a_user32_ScrollWindowEx;
	if (func == pSendDlgItemMessageA)
		return wine32a_user32_SendDlgItemMessageA;
	if (func == pSendDlgItemMessageW)
		return wine32a_user32_SendDlgItemMessageW;
	if (func == pSendIMEMessageExA)
		return wine32a_user32_SendIMEMessageExA;
	if (func == pSendIMEMessageExW)
		return wine32a_user32_SendIMEMessageExW;
	if (func == pSendInput)
		return wine32a_user32_SendInput;
	if (func == pSendMessageA)
		return wine32a_user32_SendMessageA;
	if (func == pSendMessageCallbackA)
		return wine32a_user32_SendMessageCallbackA;
	if (func == pSendMessageCallbackW)
		return wine32a_user32_SendMessageCallbackW;
	if (func == pSendMessageTimeoutA)
		return wine32a_user32_SendMessageTimeoutA;
	if (func == pSendMessageTimeoutW)
		return wine32a_user32_SendMessageTimeoutW;
	if (func == pSendMessageW)
		return wine32a_user32_SendMessageW;
	if (func == pSendNotifyMessageA)
		return wine32a_user32_SendNotifyMessageA;
	if (func == pSendNotifyMessageW)
		return wine32a_user32_SendNotifyMessageW;
	if (func == pSetActiveWindow)
		return wine32a_user32_SetActiveWindow;
	if (func == pSetCapture)
		return wine32a_user32_SetCapture;
	if (func == pSetCaretBlinkTime)
		return wine32a_user32_SetCaretBlinkTime;
	if (func == pSetCaretPos)
		return wine32a_user32_SetCaretPos;
	if (func == pSetClassLongA)
		return wine32a_user32_SetClassLongA;
	if (func == pSetClassLongPtrA)
		return wine32a_user32_SetClassLongPtrA;
	if (func == pSetClassLongPtrW)
		return wine32a_user32_SetClassLongPtrW;
	if (func == pSetClassLongW)
		return wine32a_user32_SetClassLongW;
	if (func == pSetClassWord)
		return wine32a_user32_SetClassWord;
	if (func == pSetClipboardData)
		return wine32a_user32_SetClipboardData;
	if (func == pSetClipboardViewer)
		return wine32a_user32_SetClipboardViewer;
	if (func == pSetCoalescableTimer)
		return wine32a_user32_SetCoalescableTimer;
	if (func == pSetCursor)
		return wine32a_user32_SetCursor;
	if (func == pSetCursorPos)
		return wine32a_user32_SetCursorPos;
	if (func == pSetDebugErrorLevel)
		return wine32a_user32_SetDebugErrorLevel;
	if (func == pSetDeskWallPaper)
		return wine32a_user32_SetDeskWallPaper;
	if (func == pSetDlgItemInt)
		return wine32a_user32_SetDlgItemInt;
	if (func == pSetDlgItemTextA)
		return wine32a_user32_SetDlgItemTextA;
	if (func == pSetDlgItemTextW)
		return wine32a_user32_SetDlgItemTextW;
	if (func == pSetDoubleClickTime)
		return wine32a_user32_SetDoubleClickTime;
	if (func == pSetFocus)
		return wine32a_user32_SetFocus;
	if (func == pSetForegroundWindow)
		return wine32a_user32_SetForegroundWindow;
	if (func == pSetGestureConfig)
		return wine32a_user32_SetGestureConfig;
	if (func == pSetInternalWindowPos)
		return wine32a_user32_SetInternalWindowPos;
	if (func == pSetKeyboardState)
		return wine32a_user32_SetKeyboardState;
	if (func == pSetLastErrorEx)
		return wine32a_user32_SetLastErrorEx;
	if (func == pSetLayeredWindowAttributes)
		return wine32a_user32_SetLayeredWindowAttributes;
	if (func == pSetLogonNotifyWindow)
		return wine32a_user32_SetLogonNotifyWindow;
	if (func == pSetMenu)
		return wine32a_user32_SetMenu;
	if (func == pSetMenuContextHelpId)
		return wine32a_user32_SetMenuContextHelpId;
	if (func == pSetMenuDefaultItem)
		return wine32a_user32_SetMenuDefaultItem;
	if (func == pSetMenuInfo)
		return wine32a_user32_SetMenuInfo;
	if (func == pSetMenuItemBitmaps)
		return wine32a_user32_SetMenuItemBitmaps;
	if (func == pSetMenuItemInfoA)
		return wine32a_user32_SetMenuItemInfoA;
	if (func == pSetMenuItemInfoW)
		return wine32a_user32_SetMenuItemInfoW;
	if (func == pSetMessageExtraInfo)
		return wine32a_user32_SetMessageExtraInfo;
	if (func == pSetMessageQueue)
		return wine32a_user32_SetMessageQueue;
	if (func == pSetParent)
		return wine32a_user32_SetParent;
	if (func == pSetPhysicalCursorPos)
		return wine32a_user32_SetPhysicalCursorPos;
	if (func == pSetProcessDPIAware)
		return wine32a_user32_SetProcessDPIAware;
	if (func == pSetProcessDefaultLayout)
		return wine32a_user32_SetProcessDefaultLayout;
	if (func == pSetProcessDpiAwarenessContext)
		return wine32a_user32_SetProcessDpiAwarenessContext;
	if (func == pSetProcessDpiAwarenessInternal)
		return wine32a_user32_SetProcessDpiAwarenessInternal;
	if (func == pSetProcessWindowStation)
		return wine32a_user32_SetProcessWindowStation;
	if (func == pSetProgmanWindow)
		return wine32a_user32_SetProgmanWindow;
	if (func == pSetPropA)
		return wine32a_user32_SetPropA;
	if (func == pSetPropW)
		return wine32a_user32_SetPropW;
	if (func == pSetRect)
		return wine32a_user32_SetRect;
	if (func == pSetRectEmpty)
		return wine32a_user32_SetRectEmpty;
	if (func == pSetScrollInfo)
		return wine32a_user32_SetScrollInfo;
	if (func == pSetScrollPos)
		return wine32a_user32_SetScrollPos;
	if (func == pSetScrollRange)
		return wine32a_user32_SetScrollRange;
	if (func == pSetShellWindow)
		return wine32a_user32_SetShellWindow;
	if (func == pSetShellWindowEx)
		return wine32a_user32_SetShellWindowEx;
	if (func == pSetSysColors)
		return wine32a_user32_SetSysColors;
	if (func == pSetSysColorsTemp)
		return wine32a_user32_SetSysColorsTemp;
	if (func == pSetSystemCursor)
		return wine32a_user32_SetSystemCursor;
	if (func == pSetSystemMenu)
		return wine32a_user32_SetSystemMenu;
	if (func == pSetSystemTimer)
		return wine32a_user32_SetSystemTimer;
	if (func == pSetTaskmanWindow)
		return wine32a_user32_SetTaskmanWindow;
	if (func == pSetThreadDesktop)
		return wine32a_user32_SetThreadDesktop;
	if (func == pSetThreadDpiAwarenessContext)
		return wine32a_user32_SetThreadDpiAwarenessContext;
	if (func == pSetTimer)
		return wine32a_user32_SetTimer;
	if (func == pSetUserObjectInformationA)
		return wine32a_user32_SetUserObjectInformationA;
	if (func == pSetUserObjectInformationW)
		return wine32a_user32_SetUserObjectInformationW;
	if (func == pSetUserObjectSecurity)
		return wine32a_user32_SetUserObjectSecurity;
	if (func == pSetWinEventHook)
		return wine32a_user32_SetWinEventHook;
	if (func == pSetWindowCompositionAttribute)
		return wine32a_user32_SetWindowCompositionAttribute;
	if (func == pSetWindowContextHelpId)
		return wine32a_user32_SetWindowContextHelpId;
	if (func == pSetWindowDisplayAffinity)
		return wine32a_user32_SetWindowDisplayAffinity;
	if (func == pSetWindowLongA)
		return wine32a_user32_SetWindowLongA;
	if (func == pSetWindowLongPtrA)
		return wine32a_user32_SetWindowLongPtrA;
	if (func == pSetWindowLongPtrW)
		return wine32a_user32_SetWindowLongPtrW;
	if (func == pSetWindowLongW)
		return wine32a_user32_SetWindowLongW;
	if (func == pSetWindowPlacement)
		return wine32a_user32_SetWindowPlacement;
	if (func == pSetWindowPos)
		return wine32a_user32_SetWindowPos;
	if (func == pSetWindowRgn)
		return wine32a_user32_SetWindowRgn;
	if (func == pSetWindowStationUser)
		return wine32a_user32_SetWindowStationUser;
	if (func == pSetWindowTextA)
		return wine32a_user32_SetWindowTextA;
	if (func == pSetWindowTextW)
		return wine32a_user32_SetWindowTextW;
	if (func == pSetWindowWord)
		return wine32a_user32_SetWindowWord;
	if (func == pSetWindowsHookA)
		return wine32a_user32_SetWindowsHookA;
	if (func == pSetWindowsHookExA)
		return wine32a_user32_SetWindowsHookExA;
	if (func == pSetWindowsHookExW)
		return wine32a_user32_SetWindowsHookExW;
	if (func == pSetWindowsHookW)
		return wine32a_user32_SetWindowsHookW;
	if (func == pShowCaret)
		return wine32a_user32_ShowCaret;
	if (func == pShowCursor)
		return wine32a_user32_ShowCursor;
	if (func == pShowOwnedPopups)
		return wine32a_user32_ShowOwnedPopups;
	if (func == pShowScrollBar)
		return wine32a_user32_ShowScrollBar;
	if (func == pShowWindow)
		return wine32a_user32_ShowWindow;
	if (func == pShowWindowAsync)
		return wine32a_user32_ShowWindowAsync;
	if (func == pShutdownBlockReasonCreate)
		return wine32a_user32_ShutdownBlockReasonCreate;
	if (func == pShutdownBlockReasonDestroy)
		return wine32a_user32_ShutdownBlockReasonDestroy;
	if (func == pSubtractRect)
		return wine32a_user32_SubtractRect;
	if (func == pSwapMouseButton)
		return wine32a_user32_SwapMouseButton;
	if (func == pSwitchDesktop)
		return wine32a_user32_SwitchDesktop;
	if (func == pSwitchToThisWindow)
		return wine32a_user32_SwitchToThisWindow;
	if (func == pSystemParametersInfoA)
		return wine32a_user32_SystemParametersInfoA;
	if (func == pSystemParametersInfoForDpi)
		return wine32a_user32_SystemParametersInfoForDpi;
	if (func == pSystemParametersInfoW)
		return wine32a_user32_SystemParametersInfoW;
	if (func == pTabbedTextOutA)
		return wine32a_user32_TabbedTextOutA;
	if (func == pTabbedTextOutW)
		return wine32a_user32_TabbedTextOutW;
	if (func == pTileChildWindows)
		return wine32a_user32_TileChildWindows;
	if (func == pTileWindows)
		return wine32a_user32_TileWindows;
	if (func == pToAscii)
		return wine32a_user32_ToAscii;
	if (func == pToAsciiEx)
		return wine32a_user32_ToAsciiEx;
	if (func == pToUnicode)
		return wine32a_user32_ToUnicode;
	if (func == pToUnicodeEx)
		return wine32a_user32_ToUnicodeEx;
	if (func == pTrackMouseEvent)
		return wine32a_user32_TrackMouseEvent;
	if (func == pTrackPopupMenu)
		return wine32a_user32_TrackPopupMenu;
	if (func == pTrackPopupMenuEx)
		return wine32a_user32_TrackPopupMenuEx;
	if (func == pTranslateAcceleratorA)
		return wine32a_user32_TranslateAcceleratorA;
	if (func == pTranslateAcceleratorW)
		return wine32a_user32_TranslateAcceleratorW;
	if (func == pTranslateMDISysAccel)
		return wine32a_user32_TranslateMDISysAccel;
	if (func == pTranslateMessage)
		return wine32a_user32_TranslateMessage;
	if (func == pUnhookWinEvent)
		return wine32a_user32_UnhookWinEvent;
	if (func == pUnhookWindowsHook)
		return wine32a_user32_UnhookWindowsHook;
	if (func == pUnhookWindowsHookEx)
		return wine32a_user32_UnhookWindowsHookEx;
	if (func == pUnionRect)
		return wine32a_user32_UnionRect;
	if (func == pUnloadKeyboardLayout)
		return wine32a_user32_UnloadKeyboardLayout;
	if (func == pUnpackDDElParam)
		return wine32a_user32_UnpackDDElParam;
	if (func == pUnregisterClassA)
		return wine32a_user32_UnregisterClassA;
	if (func == pUnregisterClassW)
		return wine32a_user32_UnregisterClassW;
	if (func == pUnregisterDeviceNotification)
		return wine32a_user32_UnregisterDeviceNotification;
	if (func == pUnregisterHotKey)
		return wine32a_user32_UnregisterHotKey;
	if (func == pUnregisterPowerSettingNotification)
		return wine32a_user32_UnregisterPowerSettingNotification;
	if (func == pUnregisterTouchWindow)
		return wine32a_user32_UnregisterTouchWindow;
	if (func == pUpdateLayeredWindow)
		return wine32a_user32_UpdateLayeredWindow;
	if (func == pUpdateLayeredWindowIndirect)
		return wine32a_user32_UpdateLayeredWindowIndirect;
	if (func == pUpdateWindow)
		return wine32a_user32_UpdateWindow;
	if (func == pUser32InitializeImmEntryTable)
		return wine32a_user32_User32InitializeImmEntryTable;
	if (func == pUserClientDllInitialize)
		return wine32a_user32_UserClientDllInitialize;
	if (func == pUserHandleGrantAccess)
		return wine32a_user32_UserHandleGrantAccess;
	if (func == pUserRealizePalette)
		return wine32a_user32_UserRealizePalette;
	if (func == pUserRegisterWowHandlers)
		return wine32a_user32_UserRegisterWowHandlers;
	if (func == pUserSignalProc)
		return wine32a_user32_UserSignalProc;
	if (func == pValidateRect)
		return wine32a_user32_ValidateRect;
	if (func == pValidateRgn)
		return wine32a_user32_ValidateRgn;
	if (func == pVkKeyScanA)
		return wine32a_user32_VkKeyScanA;
	if (func == pVkKeyScanExA)
		return wine32a_user32_VkKeyScanExA;
	if (func == pVkKeyScanExW)
		return wine32a_user32_VkKeyScanExW;
	if (func == pVkKeyScanW)
		return wine32a_user32_VkKeyScanW;
	if (func == pWINNLSEnableIME)
		return wine32a_user32_WINNLSEnableIME;
	if (func == pWINNLSGetEnableStatus)
		return wine32a_user32_WINNLSGetEnableStatus;
	if (func == pWINNLSGetIMEHotkey)
		return wine32a_user32_WINNLSGetIMEHotkey;
	if (func == pWaitForInputIdle)
		return wine32a_user32_WaitForInputIdle;
	if (func == pWaitMessage)
		return wine32a_user32_WaitMessage;
	if (func == pWinHelpA)
		return wine32a_user32_WinHelpA;
	if (func == pWinHelpW)
		return wine32a_user32_WinHelpW;
	if (func == pWindowFromDC)
		return wine32a_user32_WindowFromDC;
	if (func == pWindowFromPoint)
		return wine32a_user32_WindowFromPoint;
	if (func == pkeybd_event)
		return wine32a_user32_keybd_event;
	if (func == pmouse_event)
		return wine32a_user32_mouse_event;
	if (func == pwsprintfA)
		return wine32a_user32_wsprintfA;
	if (func == pwsprintfW)
		return wine32a_user32_wsprintfW;
	if (func == pwvsprintfA)
		return wine32a_user32_wvsprintfA;
	if (func == pwvsprintfW)
		return wine32a_user32_wvsprintfW;
	if (func == p__wine_send_input)
		return wine32a_user32___wine_send_input;
	if (func == p__wine_set_pixel_format)
		return wine32a_user32___wine_set_pixel_format;

	return NULL;
}
