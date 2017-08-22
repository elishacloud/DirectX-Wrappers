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
#include "IDirectDraw4.h"

myIDirectDraw4::myIDirectDraw4(IDirectDraw4 * aOriginal)
{
	logf("IDirectDraw4 ctor\n");
	mOriginal = aOriginal;
}

myIDirectDraw4::~myIDirectDraw4()
{
	logf("IDirectDraw4 dtor\n");
}

HRESULT __stdcall myIDirectDraw4::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDraw4::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirectDraw4::AddRef()
{
	logf("IDirectDraw4::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirectDraw4::Release()
{
	logf("IDirectDraw4::Release();");
	ULONG x = mOriginal->Release();
	logf(" -> return %d\n", x);
	if (x == 0)
	{
		wrapstore(mOriginal, 0);
		mOriginal = NULL;
		delete this;
	}
	return x;
}

HRESULT __stdcall myIDirectDraw4::Compact()
{
	logf("IDirectDraw4::Compact();");
	HRESULT x = mOriginal->Compact();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::CreateClipper(DWORD a, LPDIRECTDRAWCLIPPER FAR * b, IUnknown FAR * c)
{
	logf("IDirectDraw4::CreateClipper(DWORD %d, LPDIRECTDRAWCLIPPER FAR * 0x%x, IUnknown FAR *);", a, b);
	HRESULT x = mOriginal->CreateClipper(a, b, c);
	logf(" -> return %d\n", x);
	myIDirectDrawClipper * n = (myIDirectDrawClipper *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (myIDirectDrawClipper *)new myIDirectDrawClipper(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall myIDirectDraw4::CreatePalette(DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR * c, IUnknown FAR * d)
{
	logf("IDirectDraw4::CreatePalette(DWORD %d, LPPALETTEENTRY 0x%x, LPDIRECTDRAWPALETTE FAR * 0x%x, IUnknown FAR *);", a, b, c);
	HRESULT x = mOriginal->CreatePalette(a, b, c, d);
	logf(" -> return %d\n", x);
	myIDirectDrawPalette * n = (myIDirectDrawPalette *)wrapfetch(*c);
	if (n == NULL && *c != NULL)
	{
		n = (myIDirectDrawPalette *)new myIDirectDrawPalette(*c);
		wrapstore(n, *c);
		logf("Wrapped.\n");
	}
	*c = n;
	return x;
}

HRESULT __stdcall myIDirectDraw4::CreateSurface(LPDDSURFACEDESC2 a, LPDIRECTDRAWSURFACE4 FAR * b, IUnknown FAR * c)
{
	logf("IDirectDraw4::CreateSurface(LPDDSURFACEDESC2 0x%x, LPDIRECTDRAWSURFACE4 FAR * 0x%x, IUnknown FAR *);", a, b);
	HRESULT x = mOriginal->CreateSurface(a, b, c);
	logf(" -> return %d\n", x);
	IDirectDrawSurface4 * n = (IDirectDrawSurface4 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (IDirectDrawSurface4 *)new myIDirectDrawSurface4(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall myIDirectDraw4::DuplicateSurface(LPDIRECTDRAWSURFACE4 a, LPDIRECTDRAWSURFACE4 FAR * b)
{
	logf("IDirectDraw4::DuplicateSurface(LPDIRECTDRAWSURFACE4 0x%x, LPDIRECTDRAWSURFACE4 FAR * 0x%x);", a, b);
	HRESULT x = mOriginal->DuplicateSurface((a) ? ((myIDirectDrawSurface4 *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	IDirectDrawSurface4 * n = (IDirectDrawSurface4 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (IDirectDrawSurface4 *)new myIDirectDrawSurface4(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall myIDirectDraw4::EnumDisplayModes(DWORD a, LPDDSURFACEDESC2 b, LPVOID c, LPDDENUMMODESCALLBACK2 d)
{
	logf("IDirectDraw4::EnumDisplayModes(DWORD %d, LPDDSURFACEDESC2 0x%x, LPVOID 0x%x, LPDDENUMMODESCALLBACK2 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->EnumDisplayModes(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::EnumSurfaces(DWORD a, LPDDSURFACEDESC2 b, LPVOID c, LPDDENUMSURFACESCALLBACK2 d)
{
	logf("IDirectDraw4::EnumSurfaces(DWORD %d, LPDDSURFACEDESC2 0x%x, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK2 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->EnumSurfaces(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::FlipToGDISurface()
{
	logf("IDirectDraw4::FlipToGDISurface();");
	HRESULT x = mOriginal->FlipToGDISurface();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::GetCaps(LPDDCAPS a, LPDDCAPS b)
{
	logf("IDirectDraw4::GetCaps(LPDDCAPS 0x%x, LPDDCAPS 0x%x);", a, b);
	HRESULT x = mOriginal->GetCaps(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::GetDisplayMode(LPDDSURFACEDESC2 a)
{
	logf("IDirectDraw4::GetDisplayMode(LPDDSURFACEDESC2 0x%x);", a);
	HRESULT x = mOriginal->GetDisplayMode(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::GetFourCCCodes(LPDWORD a, LPDWORD b)
{
	logf("IDirectDraw4::GetFourCCCodes(LPDWORD 0x%x, LPDWORD 0x%x);", a, b);
	HRESULT x = mOriginal->GetFourCCCodes(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::GetGDISurface(LPDIRECTDRAWSURFACE4 FAR * a)
{
	logf("IDirectDraw4::GetGDISurface(LPDIRECTDRAWSURFACE4 FAR * 0x%x);", a);
	HRESULT x = mOriginal->GetGDISurface(a);
	logf(" -> return %d\n", x);
	IDirectDrawSurface4 * n = (IDirectDrawSurface4 *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (IDirectDrawSurface4 *)new myIDirectDrawSurface4(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall myIDirectDraw4::GetMonitorFrequency(LPDWORD a)
{
	logf("IDirectDraw4::GetMonitorFrequency(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetMonitorFrequency(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::GetScanLine(LPDWORD a)
{
	logf("IDirectDraw4::GetScanLine(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetScanLine(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::GetVerticalBlankStatus(LPBOOL a)
{
	logf("IDirectDraw4::GetVerticalBlankStatus(LPBOOL 0x%x);", a);
	HRESULT x = mOriginal->GetVerticalBlankStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::Initialize(GUID FAR * a)
{
	logf("IDirectDraw4::Initialize(GUID FAR *);");
	HRESULT x = mOriginal->Initialize(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::RestoreDisplayMode()
{
	logf("IDirectDraw4::RestoreDisplayMode();");
	HRESULT x = mOriginal->RestoreDisplayMode();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::SetCooperativeLevel(HWND a, DWORD b)
{
	logf("IDirectDraw4::SetCooperativeLevel(HWND 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->SetCooperativeLevel(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::SetDisplayMode(DWORD a, DWORD b, DWORD c, DWORD d, DWORD e)
{
	logf("IDirectDraw4::SetDisplayMode(DWORD %d, DWORD %d, DWORD %d, DWORD %d, DWORD %d);", a, b, c, d, e);
	HRESULT x = mOriginal->SetDisplayMode(a, b, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::WaitForVerticalBlank(DWORD a, HANDLE b)
{
	logf("IDirectDraw4::WaitForVerticalBlank(DWORD %d, HANDLE);", a);
	HRESULT x = mOriginal->WaitForVerticalBlank(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::GetAvailableVidMem(LPDDSCAPS2 a, LPDWORD b, LPDWORD c)
{
	logf("IDirectDraw4::GetAvailableVidMem(LPDDSCAPS2 0x%x, LPDWORD 0x%x, LPDWORD 0x%x);", a, b, c);
	HRESULT x = mOriginal->GetAvailableVidMem(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::GetSurfaceFromDC(HDC a, LPDIRECTDRAWSURFACE4 * b)
{
	logf("IDirectDraw4::GetSurfaceFromDC(HDC, LPDIRECTDRAWSURFACE4 * 0x%x);", b);
	HRESULT x = mOriginal->GetSurfaceFromDC(a, b);
	logf(" -> return %d\n", x);
	IDirectDrawSurface4 * n = (IDirectDrawSurface4 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (IDirectDrawSurface4 *)new myIDirectDrawSurface4(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall myIDirectDraw4::RestoreAllSurfaces()
{
	logf("IDirectDraw4::RestoreAllSurfaces();");
	HRESULT x = mOriginal->RestoreAllSurfaces();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::TestCooperativeLevel()
{
	logf("IDirectDraw4::TestCooperativeLevel();");
	HRESULT x = mOriginal->TestCooperativeLevel();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw4::GetDeviceIdentifier(LPDDDEVICEIDENTIFIER a, DWORD b)
{
	logf("IDirectDraw4::GetDeviceIdentifier(LPDDDEVICEIDENTIFIER 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->GetDeviceIdentifier(a, b);
	logf(" -> return %d\n", x);
	return x;
}
