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
#include "IDirectDrawSurface.h"

m_IDirectDrawSurface::m_IDirectDrawSurface(IDirectDrawSurface * aOriginal)
{
	logf("IDirectDrawSurface ctor\n");
	mOriginal = aOriginal;
}

m_IDirectDrawSurface::~m_IDirectDrawSurface()
{
	logf("IDirectDrawSurface dtor\n");
}

HRESULT __stdcall m_IDirectDrawSurface::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDrawSurface::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirectDrawSurface::AddRef()
{
	logf("IDirectDrawSurface::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirectDrawSurface::Release()
{
	logf("IDirectDrawSurface::Release();");
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

HRESULT __stdcall m_IDirectDrawSurface::AddAttachedSurface(LPDIRECTDRAWSURFACE a)
{
	logf("IDirectDrawSurface::AddAttachedSurface(LPDIRECTDRAWSURFACE 0x%x);", a);
	HRESULT x = mOriginal->AddAttachedSurface((a) ? ((m_IDirectDrawSurface *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::AddOverlayDirtyRect(LPRECT a)
{
	logf("IDirectDrawSurface::AddOverlayDirtyRect(LPRECT 0x%x);", a);
	HRESULT x = mOriginal->AddOverlayDirtyRect(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::Blt(LPRECT a, LPDIRECTDRAWSURFACE b, LPRECT c, DWORD d, LPDDBLTFX e)
{
	logf("IDirectDrawSurface::Blt(LPRECT 0x%x, LPDIRECTDRAWSURFACE 0x%x, LPRECT 0x%x, DWORD %d, LPDDBLTFX 0x%x);", a, b, c, d, e);
	HRESULT x = mOriginal->Blt(a, (b) ? ((m_IDirectDrawSurface *)b)->mOriginal : 0, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
	logf("IDirectDrawSurface::BltBatch(LPDDBLTBATCH 0x%x, DWORD %d, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->BltBatch(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE c, LPRECT d, DWORD e)
{
	logf("IDirectDrawSurface::BltFast(DWORD %d, DWORD %d, LPDIRECTDRAWSURFACE 0x%x, LPRECT 0x%x, DWORD %d);", a, b, c, d, e);
	HRESULT x = mOriginal->BltFast(a, b, (c) ? ((m_IDirectDrawSurface *)c)->mOriginal : 0, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE b)
{
	logf("IDirectDrawSurface::DeleteAttachedSurface(DWORD %d, LPDIRECTDRAWSURFACE 0x%x);", a, b);
	HRESULT x = mOriginal->DeleteAttachedSurface(a, (b) ? ((m_IDirectDrawSurface *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK b)
{
	logf("IDirectDrawSurface::EnumAttachedSurfaces(LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b);
	HRESULT x = mOriginal->EnumAttachedSurfaces(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK c)
{
	logf("IDirectDrawSurface::EnumOverlayZOrders(DWORD %d, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b, c);
	HRESULT x = mOriginal->EnumOverlayZOrders(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::Flip(LPDIRECTDRAWSURFACE a, DWORD b)
{
	logf("IDirectDrawSurface::Flip(LPDIRECTDRAWSURFACE 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->Flip((a) ? ((m_IDirectDrawSurface *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetAttachedSurface(LPDDSCAPS a, LPDIRECTDRAWSURFACE FAR * b)
{
	logf("IDirectDrawSurface::GetAttachedSurface(LPDDSCAPS 0x%x, LPDIRECTDRAWSURFACE FAR * 0x%x);", a, b);
	HRESULT x = mOriginal->GetAttachedSurface(a, b);
	logf(" -> return %d\n", x);
	m_IDirectDrawSurface * n = (m_IDirectDrawSurface *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (m_IDirectDrawSurface *)new m_IDirectDrawSurface(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetBltStatus(DWORD a)
{
	logf("IDirectDrawSurface::GetBltStatus(DWORD %d);", a);
	HRESULT x = mOriginal->GetBltStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetCaps(LPDDSCAPS a)
{
	logf("IDirectDrawSurface::GetCaps(LPDDSCAPS 0x%x);", a);
	HRESULT x = mOriginal->GetCaps(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
	logf("IDirectDrawSurface::GetClipper(LPDIRECTDRAWCLIPPER FAR * 0x%x);", a);
	HRESULT x = mOriginal->GetClipper(a);
	logf(" -> return %d\n", x);
	m_IDirectDrawClipper * n = (m_IDirectDrawClipper *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (m_IDirectDrawClipper *)new m_IDirectDrawClipper(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
	logf("IDirectDrawSurface::GetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
	HRESULT x = mOriginal->GetColorKey(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetDC(HDC FAR * a)
{
	logf("IDirectDrawSurface::GetDC(HDC FAR *);");
	HRESULT x = mOriginal->GetDC(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetFlipStatus(DWORD a)
{
	logf("IDirectDrawSurface::GetFlipStatus(DWORD %d);", a);
	HRESULT x = mOriginal->GetFlipStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetOverlayPosition(LPLONG a, LPLONG b)
{
	logf("IDirectDrawSurface::GetOverlayPosition(LPLONG 0x%x, LPLONG 0x%x);", a, b);
	HRESULT x = mOriginal->GetOverlayPosition(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
	logf("IDirectDrawSurface::GetPalette(LPDIRECTDRAWPALETTE FAR * 0x%x);", a);
	HRESULT x = mOriginal->GetPalette(a);
	logf(" -> return %d\n", x);
	m_IDirectDrawPalette * n = (m_IDirectDrawPalette *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (m_IDirectDrawPalette *)new m_IDirectDrawPalette(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetPixelFormat(LPDDPIXELFORMAT a)
{
	logf("IDirectDrawSurface::GetPixelFormat(LPDDPIXELFORMAT 0x%x);", a);
	HRESULT x = mOriginal->GetPixelFormat(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::GetSurfaceDesc(LPDDSURFACEDESC a)
{
	logf("IDirectDrawSurface::GetSurfaceDesc(LPDDSURFACEDESC 0x%x);", a);
	HRESULT x = mOriginal->GetSurfaceDesc(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC b)
{
	logf("IDirectDrawSurface::Initialize(LPDIRECTDRAW 0x%x, LPDDSURFACEDESC 0x%x);", a, b);
	HRESULT x = mOriginal->Initialize((a) ? ((m_IDirectDraw *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::IsLost()
{
	logf("IDirectDrawSurface::IsLost();");
	HRESULT x = mOriginal->IsLost();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::Lock(LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d)
{
	logf("IDirectDrawSurface::Lock(LPRECT 0x%x, LPDDSURFACEDESC 0x%x, DWORD %d, HANDLE);", a, b, c);
	HRESULT x = mOriginal->Lock(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::ReleaseDC(HDC a)
{
	logf("IDirectDrawSurface::ReleaseDC(HDC);");
	HRESULT x = mOriginal->ReleaseDC(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::Restore()
{
	logf("IDirectDrawSurface::Restore();");
	HRESULT x = mOriginal->Restore();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::SetClipper(LPDIRECTDRAWCLIPPER a)
{
	logf("IDirectDrawSurface::SetClipper(LPDIRECTDRAWCLIPPER 0x%x);", a);
	HRESULT x = mOriginal->SetClipper((a) ? ((m_IDirectDrawClipper *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
	logf("IDirectDrawSurface::SetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
	HRESULT x = mOriginal->SetColorKey(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::SetOverlayPosition(LONG a, LONG b)
{
	logf("IDirectDrawSurface::SetOverlayPosition(LONG, LONG);");
	HRESULT x = mOriginal->SetOverlayPosition(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::SetPalette(LPDIRECTDRAWPALETTE a)
{
	logf("IDirectDrawSurface::SetPalette(LPDIRECTDRAWPALETTE 0x%x);", a);
	HRESULT x = mOriginal->SetPalette((a) ? ((m_IDirectDrawPalette *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::Unlock(LPVOID a)
{
	logf("IDirectDrawSurface::Unlock(LPVOID 0x%x);", a);
	HRESULT x = mOriginal->Unlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
	logf("IDirectDrawSurface::UpdateOverlay(LPRECT 0x%x, LPDIRECTDRAWSURFACE 0x%x, LPRECT 0x%x, DWORD %d, LPDDOVERLAYFX 0x%x);", a, b, c, d, e);
	HRESULT x = mOriginal->UpdateOverlay(a, (b) ? ((m_IDirectDrawSurface *)b)->mOriginal : 0, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::UpdateOverlayDisplay(DWORD a)
{
	logf("IDirectDrawSurface::UpdateOverlayDisplay(DWORD %d);", a);
	HRESULT x = mOriginal->UpdateOverlayDisplay(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE b)
{
	logf("IDirectDrawSurface::UpdateOverlayZOrder(DWORD %d, LPDIRECTDRAWSURFACE 0x%x);", a, b);
	HRESULT x = mOriginal->UpdateOverlayZOrder(a, (b) ? ((m_IDirectDrawSurface *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}
