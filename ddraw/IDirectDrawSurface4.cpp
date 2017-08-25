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
#include "IDirectDrawSurface4.h"

m_IDirectDrawSurface4::m_IDirectDrawSurface4(IDirectDrawSurface4 * aOriginal)
{
	logf("IDirectDrawSurface4 ctor\n");
	mOriginal = aOriginal;
}

m_IDirectDrawSurface4::~m_IDirectDrawSurface4()
{
	logf("IDirectDrawSurface4 dtor\n");
}

HRESULT __stdcall m_IDirectDrawSurface4::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDrawSurface4::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirectDrawSurface4::AddRef()
{
	logf("IDirectDrawSurface4::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirectDrawSurface4::Release()
{
	logf("IDirectDrawSurface4::Release();");
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

HRESULT __stdcall m_IDirectDrawSurface4::AddAttachedSurface(LPDIRECTDRAWSURFACE4 a)
{
	logf("IDirectDrawSurface4::AddAttachedSurface(LPDIRECTDRAWSURFACE4 0x%x);", a);
	HRESULT x = mOriginal->AddAttachedSurface((a) ? ((m_IDirectDrawSurface4 *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::AddOverlayDirtyRect(LPRECT a)
{
	logf("IDirectDrawSurface4::AddOverlayDirtyRect(LPRECT 0x%x);", a);
	HRESULT x = mOriginal->AddOverlayDirtyRect(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::Blt(LPRECT a, LPDIRECTDRAWSURFACE4 b, LPRECT c, DWORD d, LPDDBLTFX e)
{
	logf("IDirectDrawSurface4::Blt(LPRECT 0x%x, LPDIRECTDRAWSURFACE4 0x%x, LPRECT 0x%x, DWORD %d, LPDDBLTFX 0x%x);", a, b, c, d, e);
	HRESULT x = mOriginal->Blt(a, (b) ? ((m_IDirectDrawSurface4 *)b)->mOriginal : 0, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
	logf("IDirectDrawSurface4::BltBatch(LPDDBLTBATCH 0x%x, DWORD %d, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->BltBatch(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE4 c, LPRECT d, DWORD e)
{
	logf("IDirectDrawSurface4::BltFast(DWORD %d, DWORD %d, LPDIRECTDRAWSURFACE4 0x%x, LPRECT 0x%x, DWORD %d);", a, b, c, d, e);
	HRESULT x = mOriginal->BltFast(a, b, (c) ? ((m_IDirectDrawSurface4 *)c)->mOriginal : 0, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE4 b)
{
	logf("IDirectDrawSurface4::DeleteAttachedSurface(DWORD %d, LPDIRECTDRAWSURFACE4 0x%x);", a, b);
	HRESULT x = mOriginal->DeleteAttachedSurface(a, (b) ? ((m_IDirectDrawSurface4 *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK2 b)
{
	logf("IDirectDrawSurface4::EnumAttachedSurfaces(LPVOID 0x%x, LPDDENUMSURFACESCALLBACK2 0x%x);", a, b);
	HRESULT x = mOriginal->EnumAttachedSurfaces(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK2 c)
{
	logf("IDirectDrawSurface4::EnumOverlayZOrders(DWORD %d, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK2 0x%x);", a, b, c);
	HRESULT x = mOriginal->EnumOverlayZOrders(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::Flip(LPDIRECTDRAWSURFACE4 a, DWORD b)
{
	logf("IDirectDrawSurface4::Flip(LPDIRECTDRAWSURFACE4 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->Flip((a) ? ((m_IDirectDrawSurface4 *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetAttachedSurface(LPDDSCAPS2 a, LPDIRECTDRAWSURFACE4 FAR * b)
{
	logf("IDirectDrawSurface4::GetAttachedSurface(LPDDSCAPS2 0x%x, LPDIRECTDRAWSURFACE4 FAR * 0x%x);", a, b);
	HRESULT x = mOriginal->GetAttachedSurface(a, b);
	logf(" -> return %d\n", x);
	m_IDirectDrawSurface4 * n = (m_IDirectDrawSurface4 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (m_IDirectDrawSurface4 *)new m_IDirectDrawSurface4(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetBltStatus(DWORD a)
{
	logf("IDirectDrawSurface4::GetBltStatus(DWORD %d);", a);
	HRESULT x = mOriginal->GetBltStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetCaps(LPDDSCAPS2 a)
{
	logf("IDirectDrawSurface4::GetCaps(LPDDSCAPS2 0x%x);", a);
	HRESULT x = mOriginal->GetCaps(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
	logf("IDirectDrawSurface4::GetClipper(LPDIRECTDRAWCLIPPER FAR * 0x%x);", a);
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

HRESULT __stdcall m_IDirectDrawSurface4::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
	logf("IDirectDrawSurface4::GetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
	HRESULT x = mOriginal->GetColorKey(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetDC(HDC FAR * a)
{
	logf("IDirectDrawSurface4::GetDC(HDC FAR *);");
	HRESULT x = mOriginal->GetDC(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetFlipStatus(DWORD a)
{
	logf("IDirectDrawSurface4::GetFlipStatus(DWORD %d);", a);
	HRESULT x = mOriginal->GetFlipStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetOverlayPosition(LPLONG a, LPLONG b)
{
	logf("IDirectDrawSurface4::GetOverlayPosition(LPLONG 0x%x, LPLONG 0x%x);", a, b);
	HRESULT x = mOriginal->GetOverlayPosition(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
	logf("IDirectDrawSurface4::GetPalette(LPDIRECTDRAWPALETTE FAR * 0x%x);", a);
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

HRESULT __stdcall m_IDirectDrawSurface4::GetPixelFormat(LPDDPIXELFORMAT a)
{
	logf("IDirectDrawSurface4::GetPixelFormat(LPDDPIXELFORMAT 0x%x);", a);
	HRESULT x = mOriginal->GetPixelFormat(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetSurfaceDesc(LPDDSURFACEDESC2 a)
{
	logf("IDirectDrawSurface4::GetSurfaceDesc(LPDDSURFACEDESC2 0x%x);", a);
	HRESULT x = mOriginal->GetSurfaceDesc(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC2 b)
{
	logf("IDirectDrawSurface4::Initialize(LPDIRECTDRAW 0x%x, LPDDSURFACEDESC2 0x%x);", a, b);
	HRESULT x = mOriginal->Initialize((a) ? ((m_IDirectDraw *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::IsLost()
{
	logf("IDirectDrawSurface4::IsLost();");
	HRESULT x = mOriginal->IsLost();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::Lock(LPRECT a, LPDDSURFACEDESC2 b, DWORD c, HANDLE d)
{
	logf("IDirectDrawSurface4::Lock(LPRECT 0x%x, LPDDSURFACEDESC2 0x%x, DWORD %d, HANDLE);", a, b, c);
	HRESULT x = mOriginal->Lock(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::ReleaseDC(HDC a)
{
	logf("IDirectDrawSurface4::ReleaseDC(HDC);");
	HRESULT x = mOriginal->ReleaseDC(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::Restore()
{
	logf("IDirectDrawSurface4::Restore();");
	HRESULT x = mOriginal->Restore();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::SetClipper(LPDIRECTDRAWCLIPPER a)
{
	logf("IDirectDrawSurface4::SetClipper(LPDIRECTDRAWCLIPPER 0x%x);", a);
	HRESULT x = mOriginal->SetClipper((a) ? ((m_IDirectDrawClipper *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
	logf("IDirectDrawSurface4::SetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
	HRESULT x = mOriginal->SetColorKey(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::SetOverlayPosition(LONG a, LONG b)
{
	logf("IDirectDrawSurface4::SetOverlayPosition(LONG, LONG);");
	HRESULT x = mOriginal->SetOverlayPosition(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::SetPalette(LPDIRECTDRAWPALETTE a)
{
	logf("IDirectDrawSurface4::SetPalette(LPDIRECTDRAWPALETTE 0x%x);", a);
	HRESULT x = mOriginal->SetPalette((a) ? ((m_IDirectDrawPalette *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::Unlock(LPRECT a)
{
	logf("IDirectDrawSurface4::Unlock(LPRECT 0x%x);", a);
	HRESULT x = mOriginal->Unlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE4 b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
	logf("IDirectDrawSurface4::UpdateOverlay(LPRECT 0x%x, LPDIRECTDRAWSURFACE4 0x%x, LPRECT 0x%x, DWORD %d, LPDDOVERLAYFX 0x%x);", a, b, c, d, e);
	HRESULT x = mOriginal->UpdateOverlay(a, (b) ? ((m_IDirectDrawSurface4 *)b)->mOriginal : 0, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::UpdateOverlayDisplay(DWORD a)
{
	logf("IDirectDrawSurface4::UpdateOverlayDisplay(DWORD %d);", a);
	HRESULT x = mOriginal->UpdateOverlayDisplay(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE4 b)
{
	logf("IDirectDrawSurface4::UpdateOverlayZOrder(DWORD %d, LPDIRECTDRAWSURFACE4 0x%x);", a, b);
	HRESULT x = mOriginal->UpdateOverlayZOrder(a, (b) ? ((m_IDirectDrawSurface4 *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetDDInterface(LPVOID FAR * a)
{
	logf("IDirectDrawSurface4::GetDDInterface(LPVOID FAR * 0x%x);", a);
	HRESULT x = mOriginal->GetDDInterface(a);
	logf(" -> return %d\n", x);
	LPVOID n = (LPVOID)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (LPVOID)new m_IDirectDraw4((IDirectDraw4 *)*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::PageLock(DWORD a)
{
	logf("IDirectDrawSurface4::PageLock(DWORD %d);", a);
	HRESULT x = mOriginal->PageLock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::PageUnlock(DWORD a)
{
	logf("IDirectDrawSurface4::PageUnlock(DWORD %d);", a);
	HRESULT x = mOriginal->PageUnlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::SetSurfaceDesc(LPDDSURFACEDESC2 a, DWORD b)
{
	logf("IDirectDrawSurface4::SetSurfaceDesc(LPDDSURFACEDESC2 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->SetSurfaceDesc(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::SetPrivateData(REFGUID a, LPVOID b, DWORD c, DWORD d)
{
	logf("IDirectDrawSurface4::SetPrivateData(REFGUID, LPVOID 0x%x, DWORD %d, DWORD %d);", b, c, d);
	HRESULT x = mOriginal->SetPrivateData(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetPrivateData(REFGUID a, LPVOID b, LPDWORD c)
{
	logf("IDirectDrawSurface4::GetPrivateData(REFGUID, LPVOID 0x%x, LPDWORD 0x%x);", b, c);
	HRESULT x = mOriginal->GetPrivateData(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::FreePrivateData(REFGUID a)
{
	logf("IDirectDrawSurface4::FreePrivateData(REFGUID);");
	HRESULT x = mOriginal->FreePrivateData(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::GetUniquenessValue(LPDWORD a)
{
	logf("IDirectDrawSurface4::GetUniquenessValue(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetUniquenessValue(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface4::ChangeUniquenessValue()
{
	logf("IDirectDrawSurface4::ChangeUniquenessValue();");
	HRESULT x = mOriginal->ChangeUniquenessValue();
	logf(" -> return %d\n", x);
	return x;
}
