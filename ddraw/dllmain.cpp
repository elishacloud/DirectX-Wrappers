/*
* Copyright 2013 Jari Komppa http://iki.fi/sol/
*
* This software is provided 'as-is', without any express or implied
* warranty. In no event will the authors be held liable for any damages
* arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
*
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
*
* 3. This notice may not be removed or altered from any source
* distribution.
*
* Taken from code found here: https://github.com/jarikomppa/dxwrapper
*
* Updated 2017 by Elisha Riedlinger
*/

#include "ddraw.h"

std::ofstream LOG;

typedef HRESULT(_stdcall *DDrawCreateProc)(void* a, void* b, void* c);
typedef HRESULT(_stdcall *DDrawEnumerateProc)(void* callback, void* context);
typedef void(_stdcall *DDrawMiscProc)();
typedef HRESULT(_stdcall *DDrawCreateExProc)(GUID FAR *lpGUID, LPVOID *lplpDD, REFIID iid, IUnknown FAR *pUnkOuter);

static DDrawCreateProc DDrawCreate = 0;
static DDrawEnumerateProc DDrawEnumerate = 0;
static DDrawMiscProc AcquireLock;
static DDrawMiscProc ParseUnknown;
static DDrawMiscProc InternalLock;
static DDrawMiscProc InternalUnlock;
static DDrawMiscProc ReleaseLock;
static DDrawCreateExProc DDrawCreateEx;

bool _stdcall SetWindowPosHook(HWND, HWND, int, int, int, int, int) { return true; }
bool _stdcall SetWindowLongHook(HWND, int, int) { return true; }
bool _stdcall ShowWindowHook(HWND, int) { return true; }

bool _stdcall DllMain(HANDLE, DWORD dwReason, LPVOID)
{
	static HMODULE ddrawdll = nullptr;
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		LOG.open("ddraw.log", std::ios::trunc);
		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat_s(path, "\\ddraw.dll");
		LOG << "Loading " << path << "\n";
		ddrawdll = LoadLibraryA(path);
		DDrawCreate = (DDrawCreateProc)GetProcAddress(ddrawdll, "DirectDrawCreate");
		DDrawEnumerate = (DDrawEnumerateProc)GetProcAddress(ddrawdll, "DirectDrawEnumerateA");
		DDrawCreateEx = (DDrawCreateExProc)GetProcAddress(ddrawdll, "DirectDrawCreateEx");
		AcquireLock = (DDrawMiscProc)GetProcAddress(ddrawdll, "AcquireDDThreadLock");
		ParseUnknown = (DDrawMiscProc)GetProcAddress(ddrawdll, "D3DParseUnknownCommand");
		InternalLock = (DDrawMiscProc)GetProcAddress(ddrawdll, "DDInternalLock");
		InternalUnlock = (DDrawMiscProc)GetProcAddress(ddrawdll, "DDInternalUnlock");
		ReleaseLock = (DDrawMiscProc)GetProcAddress(ddrawdll, "ReleaseDDThreadLock");
		break;

	case DLL_PROCESS_DETACH:
		FreeLibrary(ddrawdll);
		LOG.flush();
		break;
	}
	return true;
}

void logf(char * fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	static constexpr DWORD BuffSize = 250;
	static char buffer[BuffSize];
	sprintf_s(buffer, fmt, ap);
	LOG << buffer;
}

struct WrapPair
{
	void * mOriginal;
	void * mWrapper;
};

#define MAX_PAIRS 65536
WrapPair gWrapPair[MAX_PAIRS];
int gWrapPairs = 0;

void * do_wrapfetch(void * aOriginal)
{
	int i;
	for (i = 0; i < gWrapPairs; i++)
	{
		if (gWrapPair[i].mOriginal == aOriginal)
		{
			return gWrapPair[i].mWrapper;
		}
	}
	return nullptr;
}

void wrapstore(void * aOriginal, void * aWrapper)
{
	if (do_wrapfetch(aOriginal) == NULL)
	{
		gWrapPair[gWrapPairs].mOriginal = aOriginal;
		gWrapPair[gWrapPairs].mWrapper = aWrapper;
		gWrapPairs++;
	}
	else
	{
		int i;
		for (i = 0; i < gWrapPairs; i++)
		{
			if (gWrapPair[i].mOriginal == aOriginal)
			{
				gWrapPair[i].mWrapper = aWrapper;
				return;
			}
		}
	}

	if (gWrapPairs >= MAX_PAIRS)
	{
		logf("**** Max number of wrappers exceeded - adjust and recompile\n");
	}
}

void * wrapfetch(void * aOriginal)
{
	void * ret = do_wrapfetch(aOriginal);
	if (!ret)
	{
		logf("Pre-wrapped object not found - returning null\n");
	}
	return ret;
}

extern "C" void __declspec(naked) myAcquireLock()
{
	logf(__FUNCTION__ "\n");
	_asm jmp AcquireLock;
}
extern "C" void __declspec(naked) myParseUnknown()
{
	logf(__FUNCTION__ "\n");
	_asm jmp ParseUnknown;
}
extern "C" void __declspec(naked) myInternalLock()
{
	logf(__FUNCTION__ "\n");
	_asm jmp InternalLock;
}
extern "C" void __declspec(naked) myInternalUnlock()
{
	logf(__FUNCTION__ "\n");
	_asm jmp InternalUnlock;
}
extern "C" void __declspec(naked) myReleaseLock()
{
	logf(__FUNCTION__ "\n");
	_asm jmp ReleaseLock;
}

extern "C" HRESULT _stdcall myDirectDrawCreate(GUID* a, IDirectDraw** b, IUnknown* c)
{
	logf(__FUNCTION__ "\n");
	HRESULT hr = DDrawCreate(a, b, c);
	if (FAILED(hr)) return hr;
	*b = (IDirectDraw*)new myIDirectDraw(*b);
	return 0;
}

extern "C" HRESULT _stdcall myDirectDrawCreateEx(GUID FAR *lpGUID, LPVOID *lplpDD, REFIID iid, IUnknown FAR *pUnkOuter)
{
	logf(__FUNCTION__ "\n");
	HRESULT hr = DDrawCreateEx(lpGUID, lplpDD, iid, pUnkOuter);
	genericQueryInterface(iid, lplpDD);
	return hr;
}

extern "C" HRESULT _stdcall myDirectDrawEnumerate(void* lpCallback, void* lpContext)
{
	logf(__FUNCTION__ "\n");
	return DDrawEnumerate(lpCallback, lpContext);
}
