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
#include "IDirectDraw2.h"

m_IDirectDraw2::m_IDirectDraw2(IDirectDraw2 * aOriginal)
{
	logf("IDirectDraw2 ctor\n");
	mOriginal = aOriginal;
}

m_IDirectDraw2::~m_IDirectDraw2()
{
	logf("IDirectDraw2 dtor\n");
}

HRESULT __stdcall m_IDirectDraw2::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDraw2::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirectDraw2::AddRef()
{
	logf("IDirectDraw2::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirectDraw2::Release()
{
	logf("IDirectDraw2::Release();");
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

HRESULT __stdcall m_IDirectDraw2::Compact()
{
	logf("IDirectDraw2::Compact();");
	HRESULT x = mOriginal->Compact();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::CreateClipper(DWORD a, LPDIRECTDRAWCLIPPER FAR * b, IUnknown FAR * c)
{
	logf("IDirectDraw2::CreateClipper(DWORD %d, LPDIRECTDRAWCLIPPER FAR * 0x%x, IUnknown FAR *);", a, b);
	HRESULT x = mOriginal->CreateClipper(a, b, c);
	logf(" -> return %d\n", x);
	m_IDirectDrawClipper * n = (m_IDirectDrawClipper *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (m_IDirectDrawClipper *)new m_IDirectDrawClipper(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall m_IDirectDraw2::CreatePalette(DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR * c, IUnknown FAR * d)
{
	logf("IDirectDraw2::CreatePalette(DWORD %d, LPPALETTEENTRY 0x%x, LPDIRECTDRAWPALETTE FAR * 0x%x, IUnknown FAR *);", a, b, c);
	HRESULT x = mOriginal->CreatePalette(a, b, c, d);
	logf(" -> return %d\n", x);
	m_IDirectDrawPalette * n = (m_IDirectDrawPalette *)wrapfetch(*c);
	if (n == NULL && *c != NULL)
	{
		n = (m_IDirectDrawPalette *)new m_IDirectDrawPalette(*c);
		wrapstore(n, *c);
		logf("Wrapped.\n");
	}
	*c = n;
	return x;
}

HRESULT __stdcall m_IDirectDraw2::CreateSurface(LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR * b, IUnknown FAR * c)
{
	logf("IDirectDraw2::CreateSurface(LPDDSURFACEDESC 0x%x, LPDIRECTDRAWSURFACE FAR * 0x%x, IUnknown FAR *);", a, b);
	HRESULT x = mOriginal->CreateSurface(a, b, c);
	logf(" -> return %d\n", x);
	IDirectDrawSurface * n = (IDirectDrawSurface *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (IDirectDrawSurface *)new m_IDirectDrawSurface(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall m_IDirectDraw2::DuplicateSurface(LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR * b)
{
	logf("IDirectDraw2::DuplicateSurface(LPDIRECTDRAWSURFACE 0x%x, LPDIRECTDRAWSURFACE FAR * 0x%x);", a, b);
	HRESULT x = mOriginal->DuplicateSurface((a) ? ((m_IDirectDrawSurface *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	IDirectDrawSurface * n = (IDirectDrawSurface *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (IDirectDrawSurface *)new m_IDirectDrawSurface(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall m_IDirectDraw2::EnumDisplayModes(DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMMODESCALLBACK d)
{
	logf("IDirectDraw2::EnumDisplayModes(DWORD %d, LPDDSURFACEDESC 0x%x, LPVOID 0x%x, LPDDENUMMODESCALLBACK 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->EnumDisplayModes(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::EnumSurfaces(DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMSURFACESCALLBACK d)
{
	logf("IDirectDraw2::EnumSurfaces(DWORD %d, LPDDSURFACEDESC 0x%x, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->EnumSurfaces(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::FlipToGDISurface()
{
	logf("IDirectDraw2::FlipToGDISurface();");
	HRESULT x = mOriginal->FlipToGDISurface();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::GetCaps(LPDDCAPS a, LPDDCAPS b)
{
	logf("IDirectDraw2::GetCaps(LPDDCAPS 0x%x, LPDDCAPS 0x%x);", a, b);
	HRESULT x = mOriginal->GetCaps(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::GetDisplayMode(LPDDSURFACEDESC a)
{
	logf("IDirectDraw2::GetDisplayMode(LPDDSURFACEDESC 0x%x);", a);
	HRESULT x = mOriginal->GetDisplayMode(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::GetFourCCCodes(LPDWORD a, LPDWORD b)
{
	logf("IDirectDraw2::GetFourCCCodes(LPDWORD 0x%x, LPDWORD 0x%x);", a, b);
	HRESULT x = mOriginal->GetFourCCCodes(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::GetGDISurface(LPDIRECTDRAWSURFACE FAR * a)
{
	logf("IDirectDraw2::GetGDISurface(LPDIRECTDRAWSURFACE FAR * 0x%x);", a);
	HRESULT x = mOriginal->GetGDISurface(a);
	logf(" -> return %d\n", x);
	IDirectDrawSurface * n = (IDirectDrawSurface *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (IDirectDrawSurface *)new m_IDirectDrawSurface(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirectDraw2::GetMonitorFrequency(LPDWORD a)
{
	logf("IDirectDraw2::GetMonitorFrequency(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetMonitorFrequency(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::GetScanLine(LPDWORD a)
{
	logf("IDirectDraw2::GetScanLine(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetScanLine(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::GetVerticalBlankStatus(LPBOOL a)
{
	logf("IDirectDraw2::GetVerticalBlankStatus(LPBOOL 0x%x);", a);
	HRESULT x = mOriginal->GetVerticalBlankStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::Initialize(GUID FAR * a)
{
	logf("IDirectDraw2::Initialize(GUID FAR *);");
	HRESULT x = mOriginal->Initialize(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::RestoreDisplayMode()
{
	logf("IDirectDraw2::RestoreDisplayMode();");
	HRESULT x = mOriginal->RestoreDisplayMode();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::SetCooperativeLevel(HWND a, DWORD b)
{
	logf("IDirectDraw2::SetCooperativeLevel(HWND 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->SetCooperativeLevel(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::SetDisplayMode(DWORD a, DWORD b, DWORD c, DWORD d, DWORD e)
{
	logf("IDirectDraw2::SetDisplayMode(DWORD %d, DWORD %d, DWORD %d, DWORD %d, DWORD %d);", a, b, c, d, e);
	HRESULT x = mOriginal->SetDisplayMode(a, b, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::WaitForVerticalBlank(DWORD a, HANDLE b)
{
	logf("IDirectDraw2::WaitForVerticalBlank(DWORD %d, HANDLE);", a);
	HRESULT x = mOriginal->WaitForVerticalBlank(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDraw2::GetAvailableVidMem(LPDDSCAPS a, LPDWORD b, LPDWORD c)
{
	logf("IDirectDraw2::GetAvailableVidMem(LPDDSCAPS 0x%x, LPDWORD 0x%x, LPDWORD 0x%x);", a, b, c);
	HRESULT x = mOriginal->GetAvailableVidMem(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}
