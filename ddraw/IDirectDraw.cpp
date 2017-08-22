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
#include "IDirectDraw.h"

myIDirectDraw::myIDirectDraw(IDirectDraw * aOriginal)
{
	logf("IDirectDraw ctor\n");
	mOriginal = aOriginal;
}

myIDirectDraw::~myIDirectDraw()
{
	logf("IDirectDraw dtor\n");
}

HRESULT __stdcall myIDirectDraw::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDraw::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirectDraw::AddRef()
{
	logf("IDirectDraw::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirectDraw::Release()
{
	logf("IDirectDraw::Release();");
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

HRESULT __stdcall myIDirectDraw::Compact()
{
	logf("IDirectDraw::Compact();");
	HRESULT x = mOriginal->Compact();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::CreateClipper(DWORD a, LPDIRECTDRAWCLIPPER FAR * b, IUnknown FAR * c)
{
	logf("IDirectDraw::CreateClipper(DWORD %d, LPDIRECTDRAWCLIPPER FAR * 0x%x, IUnknown FAR *);", a, b);
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

HRESULT __stdcall myIDirectDraw::CreatePalette(DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR * c, IUnknown FAR * d)
{
	logf("IDirectDraw::CreatePalette(DWORD %d, LPPALETTEENTRY 0x%x, LPDIRECTDRAWPALETTE FAR * 0x%x, IUnknown FAR *);", a, b, c);
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

HRESULT __stdcall myIDirectDraw::CreateSurface(LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR * b, IUnknown FAR * c)
{
	logf("IDirectDraw::CreateSurface(LPDDSURFACEDESC 0x%x, LPDIRECTDRAWSURFACE FAR * 0x%x, IUnknown FAR *);", a, b);
	HRESULT x = mOriginal->CreateSurface(a, b, c);
	logf(" -> return %d\n", x);
	IDirectDrawSurface * n = (IDirectDrawSurface *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (IDirectDrawSurface *)new myIDirectDrawSurface(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall myIDirectDraw::DuplicateSurface(LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR * b)
{
	logf("IDirectDraw::DuplicateSurface(LPDIRECTDRAWSURFACE 0x%x, LPDIRECTDRAWSURFACE FAR * 0x%x);", a, b);
	HRESULT x = mOriginal->DuplicateSurface((a) ? ((myIDirectDrawSurface *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	IDirectDrawSurface * n = (IDirectDrawSurface *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (IDirectDrawSurface *)new myIDirectDrawSurface(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall myIDirectDraw::EnumDisplayModes(DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMMODESCALLBACK d)
{
	logf("IDirectDraw::EnumDisplayModes(DWORD %d, LPDDSURFACEDESC 0x%x, LPVOID 0x%x, LPDDENUMMODESCALLBACK 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->EnumDisplayModes(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::EnumSurfaces(DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMSURFACESCALLBACK d)
{
	logf("IDirectDraw::EnumSurfaces(DWORD %d, LPDDSURFACEDESC 0x%x, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->EnumSurfaces(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::FlipToGDISurface()
{
	logf("IDirectDraw::FlipToGDISurface();");
	HRESULT x = mOriginal->FlipToGDISurface();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::GetCaps(LPDDCAPS a, LPDDCAPS b)
{
	logf("IDirectDraw::GetCaps(LPDDCAPS 0x%x, LPDDCAPS 0x%x);", a, b);
	HRESULT x = mOriginal->GetCaps(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::GetDisplayMode(LPDDSURFACEDESC a)
{
	logf("IDirectDraw::GetDisplayMode(LPDDSURFACEDESC 0x%x);", a);
	HRESULT x = mOriginal->GetDisplayMode(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::GetFourCCCodes(LPDWORD a, LPDWORD b)
{
	logf("IDirectDraw::GetFourCCCodes(LPDWORD 0x%x, LPDWORD 0x%x);", a, b);
	HRESULT x = mOriginal->GetFourCCCodes(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::GetGDISurface(LPDIRECTDRAWSURFACE FAR * a)
{
	logf("IDirectDraw::GetGDISurface(LPDIRECTDRAWSURFACE FAR * 0x%x);", a);
	HRESULT x = mOriginal->GetGDISurface(a);
	logf(" -> return %d\n", x);
	IDirectDrawSurface * n = (IDirectDrawSurface *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (IDirectDrawSurface *)new myIDirectDrawSurface(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall myIDirectDraw::GetMonitorFrequency(LPDWORD a)
{
	logf("IDirectDraw::GetMonitorFrequency(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetMonitorFrequency(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::GetScanLine(LPDWORD a)
{
	logf("IDirectDraw::GetScanLine(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetScanLine(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::GetVerticalBlankStatus(LPBOOL a)
{
	logf("IDirectDraw::GetVerticalBlankStatus(LPBOOL 0x%x);", a);
	HRESULT x = mOriginal->GetVerticalBlankStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::Initialize(GUID FAR * a)
{
	logf("IDirectDraw::Initialize(GUID FAR *);");
	HRESULT x = mOriginal->Initialize(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::RestoreDisplayMode()
{
	logf("IDirectDraw::RestoreDisplayMode();");
	HRESULT x = mOriginal->RestoreDisplayMode();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::SetCooperativeLevel(HWND a, DWORD b)
{
	logf("IDirectDraw::SetCooperativeLevel(HWND 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->SetCooperativeLevel(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::SetDisplayMode(DWORD a, DWORD b, DWORD c)
{
	logf("IDirectDraw::SetDisplayMode(DWORD %d, DWORD %d, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->SetDisplayMode(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDraw::WaitForVerticalBlank(DWORD a, HANDLE b)
{
	logf("IDirectDraw::WaitForVerticalBlank(DWORD %d, HANDLE);", a);
	HRESULT x = mOriginal->WaitForVerticalBlank(a, b);
	logf(" -> return %d\n", x);
	return x;
}
