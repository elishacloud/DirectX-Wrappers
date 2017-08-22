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
#include "IDirectDraw7.h"

myIDirectDraw7::myIDirectDraw7(IDirectDraw7 * aOriginal)
{
	logf("IDirectDraw7 ctor\n");
	mOriginal = aOriginal;
}

myIDirectDraw7::~myIDirectDraw7()
{
	logf("IDirectDraw7 dtor\n");
}

HRESULT __stdcall myIDirectDraw7::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDraw7::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirectDraw7::AddRef()
{
	logf("IDirectDraw7::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirectDraw7::Release()
{
	logf("IDirectDraw7::Release();");
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

HRESULT __stdcall myIDirectDraw7::Compact()
{
	logf("IDirectDraw7::Compact();");
	HRESULT x = mOriginal->Compact();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::CreateClipper(DWORD a, LPDIRECTDRAWCLIPPER FAR * b, IUnknown FAR * c)
{
	logf("IDirectDraw7::CreateClipper(DWORD %d, LPDIRECTDRAWCLIPPER FAR * 0x%x, IUnknown FAR *);", a, b);
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

HRESULT __stdcall myIDirectDraw7::CreatePalette(DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR * c, IUnknown FAR * d)
{
	logf("IDirectDraw7::CreatePalette(DWORD %d, LPPALETTEENTRY 0x%x, LPDIRECTDRAWPALETTE FAR * 0x%x, IUnknown FAR *);", a, b, c);
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

HRESULT __stdcall myIDirectDraw7::CreateSurface(LPDDSURFACEDESC2 a, LPDIRECTDRAWSURFACE7 FAR * b, IUnknown FAR * c)
{
	logf("IDirectDraw7::CreateSurface(LPDDSURFACEDESC2 0x%x, LPDIRECTDRAWSURFACE7 FAR * 0x%x, IUnknown FAR *);", a, b);
	HRESULT x = mOriginal->CreateSurface(a, b, c);
	logf(" -> return %d\n", x);
	IDirectDrawSurface7 * n = (IDirectDrawSurface7 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (IDirectDrawSurface7 *)new myIDirectDrawSurface7(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall myIDirectDraw7::DuplicateSurface(LPDIRECTDRAWSURFACE7 a, LPDIRECTDRAWSURFACE7 FAR * b)
{
	logf("IDirectDraw7::DuplicateSurface(LPDIRECTDRAWSURFACE7 0x%x, LPDIRECTDRAWSURFACE7 FAR * 0x%x);", a, b);
	HRESULT x = mOriginal->DuplicateSurface((a) ? ((myIDirectDrawSurface7 *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	IDirectDrawSurface7 * n = (IDirectDrawSurface7 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (IDirectDrawSurface7 *)new myIDirectDrawSurface7(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall myIDirectDraw7::EnumDisplayModes(DWORD a, LPDDSURFACEDESC2 b, LPVOID c, LPDDENUMMODESCALLBACK2 d)
{
	logf("IDirectDraw7::EnumDisplayModes(DWORD %d, LPDDSURFACEDESC2 0x%x, LPVOID 0x%x, LPDDENUMMODESCALLBACK2 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->EnumDisplayModes(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::EnumSurfaces(DWORD a, LPDDSURFACEDESC2 b, LPVOID c, LPDDENUMSURFACESCALLBACK7 d)
{
	logf("IDirectDraw7::EnumSurfaces(DWORD %d, LPDDSURFACEDESC2 0x%x, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK7 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->EnumSurfaces(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::FlipToGDISurface()
{
	logf("IDirectDraw7::FlipToGDISurface();");
	HRESULT x = mOriginal->FlipToGDISurface();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::GetCaps(LPDDCAPS a, LPDDCAPS b)
{
	logf("IDirectDraw7::GetCaps(LPDDCAPS 0x%x, LPDDCAPS 0x%x);", a, b);
	HRESULT x = mOriginal->GetCaps(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::GetDisplayMode(LPDDSURFACEDESC2 a)
{
	logf("IDirectDraw7::GetDisplayMode(LPDDSURFACEDESC2 0x%x);", a);
	HRESULT x = mOriginal->GetDisplayMode(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::GetFourCCCodes(LPDWORD a, LPDWORD b)
{
	logf("IDirectDraw7::GetFourCCCodes(LPDWORD 0x%x, LPDWORD 0x%x);", a, b);
	HRESULT x = mOriginal->GetFourCCCodes(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::GetGDISurface(LPDIRECTDRAWSURFACE7 FAR * a)
{
	logf("IDirectDraw7::GetGDISurface(LPDIRECTDRAWSURFACE7 FAR * 0x%x);", a);
	HRESULT x = mOriginal->GetGDISurface(a);
	logf(" -> return %d\n", x);
	IDirectDrawSurface7 * n = (IDirectDrawSurface7 *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (IDirectDrawSurface7 *)new myIDirectDrawSurface7(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall myIDirectDraw7::GetMonitorFrequency(LPDWORD a)
{
	logf("IDirectDraw7::GetMonitorFrequency(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetMonitorFrequency(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::GetScanLine(LPDWORD a)
{
	logf("IDirectDraw7::GetScanLine(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetScanLine(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::GetVerticalBlankStatus(LPBOOL a)
{
	logf("IDirectDraw7::GetVerticalBlankStatus(LPBOOL 0x%x);", a);
	HRESULT x = mOriginal->GetVerticalBlankStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::Initialize(GUID FAR * a)
{
	logf("IDirectDraw7::Initialize(GUID FAR *);");
	HRESULT x = mOriginal->Initialize(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::RestoreDisplayMode()
{
	logf("IDirectDraw7::RestoreDisplayMode();");
	HRESULT x = mOriginal->RestoreDisplayMode();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::SetCooperativeLevel(HWND a, DWORD b)
{
	logf("IDirectDraw7::SetCooperativeLevel(HWND 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->SetCooperativeLevel(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::SetDisplayMode(DWORD a, DWORD b, DWORD c, DWORD d, DWORD e)
{
	logf("IDirectDraw7::SetDisplayMode(DWORD %d, DWORD %d, DWORD %d, DWORD %d, DWORD %d);", a, b, c, d, e);
	HRESULT x = mOriginal->SetDisplayMode(a, b, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::WaitForVerticalBlank(DWORD a, HANDLE b)
{
	logf("IDirectDraw7::WaitForVerticalBlank(DWORD %d, HANDLE);", a);
	HRESULT x = mOriginal->WaitForVerticalBlank(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::GetAvailableVidMem(LPDDSCAPS2 a, LPDWORD b, LPDWORD c)
{
	logf("IDirectDraw7::GetAvailableVidMem(LPDDSCAPS2 0x%x, LPDWORD 0x%x, LPDWORD 0x%x);", a, b, c);
	HRESULT x = mOriginal->GetAvailableVidMem(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::GetSurfaceFromDC(HDC a, LPDIRECTDRAWSURFACE7 * b)
{
	logf("IDirectDraw7::GetSurfaceFromDC(HDC, LPDIRECTDRAWSURFACE7 * 0x%x);", b);
	HRESULT x = mOriginal->GetSurfaceFromDC(a, b);
	logf(" -> return %d\n", x);
	IDirectDrawSurface7 * n = (IDirectDrawSurface7 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (IDirectDrawSurface7 *)new myIDirectDrawSurface7(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall myIDirectDraw7::RestoreAllSurfaces()
{
	logf("IDirectDraw7::RestoreAllSurfaces();");
	HRESULT x = mOriginal->RestoreAllSurfaces();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::TestCooperativeLevel()
{
	logf("IDirectDraw7::TestCooperativeLevel();");
	HRESULT x = mOriginal->TestCooperativeLevel();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::GetDeviceIdentifier(LPDDDEVICEIDENTIFIER2 a, DWORD b)
{
	logf("IDirectDraw7::GetDeviceIdentifier(LPDDDEVICEIDENTIFIER2 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->GetDeviceIdentifier(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::StartModeTest(LPSIZE a, DWORD b, DWORD c)
{
	logf("IDirectDraw7::StartModeTest(LPSIZE 0x%x, DWORD %d, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->StartModeTest(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw7::EvaluateMode(DWORD a, DWORD * b)
{
	logf("IDirectDraw7::EvaluateMode(DWORD %d, DWORD *);", a);
	HRESULT x = mOriginal->EvaluateMode(a, b);
	logf(" -> return %d\n", x);
	return x;
}
