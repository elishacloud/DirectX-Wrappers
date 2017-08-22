#pragma once

#define STRICT
#define WIN32_LEAN_AND_MEAN
#define INITGUID
#define DIRECTDRAW_VERSION 0x0700
#define DIRECT3D_VERSION   0x0700

#include <Windows.h>
#include <fstream>
#include <ddraw.h>
#include <ddrawex.h>
#include <d3d.h>

#include "IDirect3D.h"
#include "IDirect3D2.h"
#include "IDirect3D3.h"
#include "IDirect3D7.h"
#include "IDirect3DDevice.h"
#include "IDirect3DDevice2.h"
#include "IDirect3DDevice3.h"
#include "IDirect3DDevice7.h"
#include "IDirect3DExecuteBuffer.h"
#include "IDirect3DLight.h"
#include "IDirect3DMaterial.h"
#include "IDirect3DMaterial2.h"
#include "IDirect3DMaterial3.h"
#include "IDirect3DTexture.h"
#include "IDirect3DTexture2.h"
#include "IDirect3DVertexBuffer.h"
#include "IDirect3DVertexBuffer7.h"
#include "IDirect3DViewport.h"
#include "IDirect3DViewport2.h"
#include "IDirect3DViewport3.h"
#include "IDirectDraw.h"
#include "IDirectDraw2.h"
#include "IDirectDraw3.h"
#include "IDirectDraw4.h"
#include "IDirectDraw7.h"
#include "IDirectDrawClipper.h"
#include "IDirectDrawColorControl.h"
#include "IDirectDrawFactory.h"
#include "IDirectDrawGammaControl.h"
#include "IDirectDrawPalette.h"
#include "IDirectDrawSurface.h"
#include "IDirectDrawSurface2.h"
#include "IDirectDrawSurface3.h"
#include "IDirectDrawSurface4.h"
#include "IDirectDrawSurface7.h"

// Very simple logging for the purpose of debugging only.
extern std::ofstream LOG;

void logf(char * format, ...);
void genericQueryInterface(REFIID riid, LPVOID * ppvObj);
void wrapstore(void * aOriginal, void * aWrapper);
void *wrapfetch(void * aOriginal);
#ifdef _DEBUG
#define DEBUGMESS(a) OutputDebugStringA(a)
#else
#define DEBUGMESS(a);
#endif

#define STRINGIFY(x) STRINGIFY_INNER(x)
#define STRINGIFY_INNER(x) #x

//#define WARNMODE_NONE
//#define WARNMODE_MESSAGE
#define WARNMODE_BREAK

#if defined(WARNMODE_NONE)
#define UNDEFINED return E_FAIL;
#define UNDEFINED_(x) return (x);
#define UNDEFINED_void return;
#define UNDEFINED_WARN
#elif defined(WARNMODE_BREAK)
#define UNDEFINED_WARN DEBUGMESS(__FILE__ "(" STRINGIFY(__LINE__) "): Undefined function called: " __FUNCTION__ "\r\n"); DebugBreak(); 
#define UNDEFINED { UNDEFINED_WARN; return 0; }
#define UNDEFINED_(x) { UNDEFINED_WARN; return (x); }
#define UNDEFINED_void { UNDEFINED_WARN; return; }
#else // WARNMODE_MESSAGE
#define UNDEFINED_WARN DEBUGMESS(__FILE__ "(" STRINGIFY(__LINE__) "): Undefined function called: " __FUNCTION__ "\r\n");
#define UNDEFINED { UNDEFINED_WARN; return 0; }
#define UNDEFINED_(x) { UNDEFINED_WARN; return (x); }
#define UNDEFINED_void { UNDEFINED_WARN; return; }
#endif

#define DEFINED_NOTE DEBUGMESS(__FILE__ "(" STRINGIFY(__LINE__) "): Defined function called: " __FUNCTION__ "\r\n");
