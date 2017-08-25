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
#include "IDirectDrawSurface3.h"

m_IDirectDrawSurface3::m_IDirectDrawSurface3(IDirectDrawSurface3 * aOriginal)
{
	logf("IDirectDrawSurface3 ctor\n");
	mOriginal = aOriginal;
}

m_IDirectDrawSurface3::~m_IDirectDrawSurface3()
{
	logf("IDirectDrawSurface3 dtor\n");
}

HRESULT __stdcall m_IDirectDrawSurface3::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDrawSurface3::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirectDrawSurface3::AddRef()
{
	logf("IDirectDrawSurface3::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirectDrawSurface3::Release()
{
	logf("IDirectDrawSurface3::Release();");
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

HRESULT __stdcall m_IDirectDrawSurface3::AddAttachedSurface(LPDIRECTDRAWSURFACE3 a)
{
	logf("IDirectDrawSurface3::AddAttachedSurface(LPDIRECTDRAWSURFACE3 0x%x);", a);
	HRESULT x = mOriginal->AddAttachedSurface((a) ? ((m_IDirectDrawSurface3 *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::AddOverlayDirtyRect(LPRECT a)
{
	logf("IDirectDrawSurface3::AddOverlayDirtyRect(LPRECT 0x%x);", a);
	HRESULT x = mOriginal->AddOverlayDirtyRect(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::Blt(LPRECT a, LPDIRECTDRAWSURFACE3 b, LPRECT c, DWORD d, LPDDBLTFX e)
{
	logf("IDirectDrawSurface3::Blt(LPRECT 0x%x, LPDIRECTDRAWSURFACE3 0x%x, LPRECT 0x%x, DWORD %d, LPDDBLTFX 0x%x);", a, b, c, d, e);
	HRESULT x = mOriginal->Blt(a, (b) ? ((m_IDirectDrawSurface3 *)b)->mOriginal : 0, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
	logf("IDirectDrawSurface3::BltBatch(LPDDBLTBATCH 0x%x, DWORD %d, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->BltBatch(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE3 c, LPRECT d, DWORD e)
{
	logf("IDirectDrawSurface3::BltFast(DWORD %d, DWORD %d, LPDIRECTDRAWSURFACE3 0x%x, LPRECT 0x%x, DWORD %d);", a, b, c, d, e);
	HRESULT x = mOriginal->BltFast(a, b, (c) ? ((m_IDirectDrawSurface3 *)c)->mOriginal : 0, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE3 b)
{
	logf("IDirectDrawSurface3::DeleteAttachedSurface(DWORD %d, LPDIRECTDRAWSURFACE3 0x%x);", a, b);
	HRESULT x = mOriginal->DeleteAttachedSurface(a, (b) ? ((m_IDirectDrawSurface3 *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK b)
{
	logf("IDirectDrawSurface3::EnumAttachedSurfaces(LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b);
	HRESULT x = mOriginal->EnumAttachedSurfaces(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK c)
{
	logf("IDirectDrawSurface3::EnumOverlayZOrders(DWORD %d, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK 0x%x);", a, b, c);
	HRESULT x = mOriginal->EnumOverlayZOrders(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::Flip(LPDIRECTDRAWSURFACE3 a, DWORD b)
{
	logf("IDirectDrawSurface3::Flip(LPDIRECTDRAWSURFACE3 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->Flip((a) ? ((m_IDirectDrawSurface3 *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::GetAttachedSurface(LPDDSCAPS a, LPDIRECTDRAWSURFACE3 FAR * b)
{
	logf("IDirectDrawSurface3::GetAttachedSurface(LPDDSCAPS 0x%x, LPDIRECTDRAWSURFACE3 FAR * 0x%x);", a, b);
	HRESULT x = mOriginal->GetAttachedSurface(a, b);
	logf(" -> return %d\n", x);
	m_IDirectDrawSurface3 * n = (m_IDirectDrawSurface3 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (m_IDirectDrawSurface3 *)new m_IDirectDrawSurface3(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::GetBltStatus(DWORD a)
{
	logf("IDirectDrawSurface3::GetBltStatus(DWORD %d);", a);
	HRESULT x = mOriginal->GetBltStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::GetCaps(LPDDSCAPS a)
{
	logf("IDirectDrawSurface3::GetCaps(LPDDSCAPS 0x%x);", a);
	HRESULT x = mOriginal->GetCaps(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
	logf("IDirectDrawSurface3::GetClipper(LPDIRECTDRAWCLIPPER FAR * 0x%x);", a);
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

HRESULT __stdcall m_IDirectDrawSurface3::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
	logf("IDirectDrawSurface3::GetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
	HRESULT x = mOriginal->GetColorKey(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::GetDC(HDC FAR * a)
{
	logf("IDirectDrawSurface3::GetDC(HDC FAR *);");
	HRESULT x = mOriginal->GetDC(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::GetFlipStatus(DWORD a)
{
	logf("IDirectDrawSurface3::GetFlipStatus(DWORD %d);", a);
	HRESULT x = mOriginal->GetFlipStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::GetOverlayPosition(LPLONG a, LPLONG b)
{
	logf("IDirectDrawSurface3::GetOverlayPosition(LPLONG 0x%x, LPLONG 0x%x);", a, b);
	HRESULT x = mOriginal->GetOverlayPosition(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
	logf("IDirectDrawSurface3::GetPalette(LPDIRECTDRAWPALETTE FAR * 0x%x);", a);
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

HRESULT __stdcall m_IDirectDrawSurface3::GetPixelFormat(LPDDPIXELFORMAT a)
{
	logf("IDirectDrawSurface3::GetPixelFormat(LPDDPIXELFORMAT 0x%x);", a);
	HRESULT x = mOriginal->GetPixelFormat(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::GetSurfaceDesc(LPDDSURFACEDESC a)
{
	logf("IDirectDrawSurface3::GetSurfaceDesc(LPDDSURFACEDESC 0x%x);", a);
	HRESULT x = mOriginal->GetSurfaceDesc(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC b)
{
	logf("IDirectDrawSurface3::Initialize(LPDIRECTDRAW 0x%x, LPDDSURFACEDESC 0x%x);", a, b);
	HRESULT x = mOriginal->Initialize((a) ? ((m_IDirectDraw *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::IsLost()
{
	logf("IDirectDrawSurface3::IsLost();");
	HRESULT x = mOriginal->IsLost();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::Lock(LPRECT a, LPDDSURFACEDESC b, DWORD c, HANDLE d)
{
	logf("IDirectDrawSurface3::Lock(LPRECT 0x%x, LPDDSURFACEDESC 0x%x, DWORD %d, HANDLE);", a, b, c);
	HRESULT x = mOriginal->Lock(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::ReleaseDC(HDC a)
{
	logf("IDirectDrawSurface3::ReleaseDC(HDC);");
	HRESULT x = mOriginal->ReleaseDC(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::Restore()
{
	logf("IDirectDrawSurface3::Restore();");
	HRESULT x = mOriginal->Restore();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::SetClipper(LPDIRECTDRAWCLIPPER a)
{
	logf("IDirectDrawSurface3::SetClipper(LPDIRECTDRAWCLIPPER 0x%x);", a);
	HRESULT x = mOriginal->SetClipper((a) ? ((m_IDirectDrawClipper *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
	logf("IDirectDrawSurface3::SetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
	HRESULT x = mOriginal->SetColorKey(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::SetOverlayPosition(LONG a, LONG b)
{
	logf("IDirectDrawSurface3::SetOverlayPosition(LONG, LONG);");
	HRESULT x = mOriginal->SetOverlayPosition(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::SetPalette(LPDIRECTDRAWPALETTE a)
{
	logf("IDirectDrawSurface3::SetPalette(LPDIRECTDRAWPALETTE 0x%x);", a);
	HRESULT x = mOriginal->SetPalette((a) ? ((m_IDirectDrawPalette *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::Unlock(LPVOID a)
{
	logf("IDirectDrawSurface3::Unlock(LPVOID 0x%x);", a);
	HRESULT x = mOriginal->Unlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE3 b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
	logf("IDirectDrawSurface3::UpdateOverlay(LPRECT 0x%x, LPDIRECTDRAWSURFACE3 0x%x, LPRECT 0x%x, DWORD %d, LPDDOVERLAYFX 0x%x);", a, b, c, d, e);
	HRESULT x = mOriginal->UpdateOverlay(a, (b) ? ((m_IDirectDrawSurface3 *)b)->mOriginal : 0, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::UpdateOverlayDisplay(DWORD a)
{
	logf("IDirectDrawSurface3::UpdateOverlayDisplay(DWORD %d);", a);
	HRESULT x = mOriginal->UpdateOverlayDisplay(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE3 b)
{
	logf("IDirectDrawSurface3::UpdateOverlayZOrder(DWORD %d, LPDIRECTDRAWSURFACE3 0x%x);", a, b);
	HRESULT x = mOriginal->UpdateOverlayZOrder(a, (b) ? ((m_IDirectDrawSurface3 *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::GetDDInterface(LPVOID FAR * a)
{
	logf("IDirectDrawSurface3::GetDDInterface(LPVOID FAR * 0x%x);", a);
	HRESULT x = mOriginal->GetDDInterface(a);
	logf(" -> return %d\n", x);
	LPVOID n = (LPVOID)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (LPVOID)new m_IDirectDraw3((IDirectDraw3 *)*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::PageLock(DWORD a)
{
	logf("IDirectDrawSurface3::PageLock(DWORD %d);", a);
	HRESULT x = mOriginal->PageLock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::PageUnlock(DWORD a)
{
	logf("IDirectDrawSurface3::PageUnlock(DWORD %d);", a);
	HRESULT x = mOriginal->PageUnlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface3::SetSurfaceDesc(LPDDSURFACEDESC a, DWORD b)
{
	logf("IDirectDrawSurface3::SetSurfaceDesc(LPDDSURFACEDESC 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->SetSurfaceDesc(a, b);
	logf(" -> return %d\n", x);
	return x;
}
