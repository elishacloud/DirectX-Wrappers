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
#include "IDirectDrawSurface7.h"

m_IDirectDrawSurface7::m_IDirectDrawSurface7(IDirectDrawSurface7 * aOriginal)
{
	logf("IDirectDrawSurface7 ctor\n");
	mOriginal = aOriginal;
}

m_IDirectDrawSurface7::~m_IDirectDrawSurface7()
{
	logf("IDirectDrawSurface7 dtor\n");
}

HRESULT __stdcall m_IDirectDrawSurface7::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDrawSurface7::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirectDrawSurface7::AddRef()
{
	logf("IDirectDrawSurface7::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirectDrawSurface7::Release()
{
	logf("IDirectDrawSurface7::Release();");
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

HRESULT __stdcall m_IDirectDrawSurface7::AddAttachedSurface(LPDIRECTDRAWSURFACE7 a)
{
	logf("IDirectDrawSurface7::AddAttachedSurface(LPDIRECTDRAWSURFACE7 0x%x);", a);
	HRESULT x = mOriginal->AddAttachedSurface((a) ? ((m_IDirectDrawSurface7 *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::AddOverlayDirtyRect(LPRECT a)
{
	logf("IDirectDrawSurface7::AddOverlayDirtyRect(LPRECT 0x%x);", a);
	HRESULT x = mOriginal->AddOverlayDirtyRect(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::Blt(LPRECT a, LPDIRECTDRAWSURFACE7 b, LPRECT c, DWORD d, LPDDBLTFX e)
{
	logf("IDirectDrawSurface7::Blt(LPRECT 0x%x, LPDIRECTDRAWSURFACE7 0x%x, LPRECT 0x%x, DWORD %d, LPDDBLTFX 0x%x);", a, b, c, d, e);
	HRESULT x = mOriginal->Blt(a, (b) ? ((m_IDirectDrawSurface7 *)b)->mOriginal : 0, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c)
{
	logf("IDirectDrawSurface7::BltBatch(LPDDBLTBATCH 0x%x, DWORD %d, DWORD %d);", a, b, c);
	HRESULT x = mOriginal->BltBatch(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE7 c, LPRECT d, DWORD e)
{
	logf("IDirectDrawSurface7::BltFast(DWORD %d, DWORD %d, LPDIRECTDRAWSURFACE7 0x%x, LPRECT 0x%x, DWORD %d);", a, b, c, d, e);
	HRESULT x = mOriginal->BltFast(a, b, (c) ? ((m_IDirectDrawSurface7 *)c)->mOriginal : 0, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE7 b)
{
	logf("IDirectDrawSurface7::DeleteAttachedSurface(DWORD %d, LPDIRECTDRAWSURFACE7 0x%x);", a, b);
	HRESULT x = mOriginal->DeleteAttachedSurface(a, (b) ? ((m_IDirectDrawSurface7 *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK7 b)
{
	logf("IDirectDrawSurface7::EnumAttachedSurfaces(LPVOID 0x%x, LPDDENUMSURFACESCALLBACK7 0x%x);", a, b);
	HRESULT x = mOriginal->EnumAttachedSurfaces(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK7 c)
{
	logf("IDirectDrawSurface7::EnumOverlayZOrders(DWORD %d, LPVOID 0x%x, LPDDENUMSURFACESCALLBACK7 0x%x);", a, b, c);
	HRESULT x = mOriginal->EnumOverlayZOrders(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::Flip(LPDIRECTDRAWSURFACE7 a, DWORD b)
{
	logf("IDirectDrawSurface7::Flip(LPDIRECTDRAWSURFACE7 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->Flip((a) ? ((m_IDirectDrawSurface7 *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetAttachedSurface(LPDDSCAPS2 a, LPDIRECTDRAWSURFACE7 FAR * b)
{
	logf("IDirectDrawSurface7::GetAttachedSurface(LPDDSCAPS2 0x%x, LPDIRECTDRAWSURFACE7 FAR * 0x%x);", a, b);
	HRESULT x = mOriginal->GetAttachedSurface(a, b);
	logf(" -> return %d\n", x);
	m_IDirectDrawSurface7 * n = (m_IDirectDrawSurface7 *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (m_IDirectDrawSurface7 *)new m_IDirectDrawSurface7(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetBltStatus(DWORD a)
{
	logf("IDirectDrawSurface7::GetBltStatus(DWORD %d);", a);
	HRESULT x = mOriginal->GetBltStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetCaps(LPDDSCAPS2 a)
{
	logf("IDirectDrawSurface7::GetCaps(LPDDSCAPS2 0x%x);", a);
	HRESULT x = mOriginal->GetCaps(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetClipper(LPDIRECTDRAWCLIPPER FAR * a)
{
	logf("IDirectDrawSurface7::GetClipper(LPDIRECTDRAWCLIPPER FAR * 0x%x);", a);
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

HRESULT __stdcall m_IDirectDrawSurface7::GetColorKey(DWORD a, LPDDCOLORKEY b)
{
	logf("IDirectDrawSurface7::GetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
	HRESULT x = mOriginal->GetColorKey(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetDC(HDC FAR * a)
{
	logf("IDirectDrawSurface7::GetDC(HDC FAR *);");
	HRESULT x = mOriginal->GetDC(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetFlipStatus(DWORD a)
{
	logf("IDirectDrawSurface7::GetFlipStatus(DWORD %d);", a);
	HRESULT x = mOriginal->GetFlipStatus(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetOverlayPosition(LPLONG a, LPLONG b)
{
	logf("IDirectDrawSurface7::GetOverlayPosition(LPLONG 0x%x, LPLONG 0x%x);", a, b);
	HRESULT x = mOriginal->GetOverlayPosition(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetPalette(LPDIRECTDRAWPALETTE FAR * a)
{
	logf("IDirectDrawSurface7::GetPalette(LPDIRECTDRAWPALETTE FAR * 0x%x);", a);
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

HRESULT __stdcall m_IDirectDrawSurface7::GetPixelFormat(LPDDPIXELFORMAT a)
{
	logf("IDirectDrawSurface7::GetPixelFormat(LPDDPIXELFORMAT 0x%x);", a);
	HRESULT x = mOriginal->GetPixelFormat(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetSurfaceDesc(LPDDSURFACEDESC2 a)
{
	logf("IDirectDrawSurface7::GetSurfaceDesc(LPDDSURFACEDESC2 0x%x);", a);
	HRESULT x = mOriginal->GetSurfaceDesc(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC2 b)
{
	logf("IDirectDrawSurface7::Initialize(LPDIRECTDRAW 0x%x, LPDDSURFACEDESC2 0x%x);", a, b);
	HRESULT x = mOriginal->Initialize((a) ? ((m_IDirectDraw *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::IsLost()
{
	logf("IDirectDrawSurface7::IsLost();");
	HRESULT x = mOriginal->IsLost();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::Lock(LPRECT a, LPDDSURFACEDESC2 b, DWORD c, HANDLE d)
{
	logf("IDirectDrawSurface7::Lock(LPRECT 0x%x, LPDDSURFACEDESC2 0x%x, DWORD %d, HANDLE);", a, b, c);
	HRESULT x = mOriginal->Lock(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::ReleaseDC(HDC a)
{
	logf("IDirectDrawSurface7::ReleaseDC(HDC);");
	HRESULT x = mOriginal->ReleaseDC(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::Restore()
{
	logf("IDirectDrawSurface7::Restore();");
	HRESULT x = mOriginal->Restore();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::SetClipper(LPDIRECTDRAWCLIPPER a)
{
	logf("IDirectDrawSurface7::SetClipper(LPDIRECTDRAWCLIPPER 0x%x);", a);
	HRESULT x = mOriginal->SetClipper((a) ? ((m_IDirectDrawClipper *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::SetColorKey(DWORD a, LPDDCOLORKEY b)
{
	logf("IDirectDrawSurface7::SetColorKey(DWORD %d, LPDDCOLORKEY 0x%x);", a, b);
	HRESULT x = mOriginal->SetColorKey(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::SetOverlayPosition(LONG a, LONG b)
{
	logf("IDirectDrawSurface7::SetOverlayPosition(LONG, LONG);");
	HRESULT x = mOriginal->SetOverlayPosition(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::SetPalette(LPDIRECTDRAWPALETTE a)
{
	logf("IDirectDrawSurface7::SetPalette(LPDIRECTDRAWPALETTE 0x%x);", a);
	HRESULT x = mOriginal->SetPalette((a) ? ((m_IDirectDrawPalette *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::Unlock(LPRECT a)
{
	logf("IDirectDrawSurface7::Unlock(LPRECT 0x%x);", a);
	HRESULT x = mOriginal->Unlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE7 b, LPRECT c, DWORD d, LPDDOVERLAYFX e)
{
	logf("IDirectDrawSurface7::UpdateOverlay(LPRECT 0x%x, LPDIRECTDRAWSURFACE7 0x%x, LPRECT 0x%x, DWORD %d, LPDDOVERLAYFX 0x%x);", a, b, c, d, e);
	HRESULT x = mOriginal->UpdateOverlay(a, (b) ? ((m_IDirectDrawSurface7 *)b)->mOriginal : 0, c, d, e);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::UpdateOverlayDisplay(DWORD a)
{
	logf("IDirectDrawSurface7::UpdateOverlayDisplay(DWORD %d);", a);
	HRESULT x = mOriginal->UpdateOverlayDisplay(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE7 b)
{
	logf("IDirectDrawSurface7::UpdateOverlayZOrder(DWORD %d, LPDIRECTDRAWSURFACE7 0x%x);", a, b);
	HRESULT x = mOriginal->UpdateOverlayZOrder(a, (b) ? ((m_IDirectDrawSurface7 *)b)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetDDInterface(LPVOID FAR * a)
{
	logf("IDirectDrawSurface7::GetDDInterface(LPVOID FAR * 0x%x);", a);
	HRESULT x = mOriginal->GetDDInterface(a);
	logf(" -> return %d\n", x);
	LPVOID n = (LPVOID)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (LPVOID)new m_IDirectDraw7((IDirectDraw7 *)*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::PageLock(DWORD a)
{
	logf("IDirectDrawSurface7::PageLock(DWORD %d);", a);
	HRESULT x = mOriginal->PageLock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::PageUnlock(DWORD a)
{
	logf("IDirectDrawSurface7::PageUnlock(DWORD %d);", a);
	HRESULT x = mOriginal->PageUnlock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::SetSurfaceDesc(LPDDSURFACEDESC2 a, DWORD b)
{
	logf("IDirectDrawSurface7::SetSurfaceDesc(LPDDSURFACEDESC2 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->SetSurfaceDesc(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::SetPrivateData(REFGUID a, LPVOID b, DWORD c, DWORD d)
{
	logf("IDirectDrawSurface7::SetPrivateData(REFGUID, LPVOID 0x%x, DWORD %d, DWORD %d);", b, c, d);
	HRESULT x = mOriginal->SetPrivateData(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetPrivateData(REFGUID a, LPVOID b, LPDWORD c)
{
	logf("IDirectDrawSurface7::GetPrivateData(REFGUID, LPVOID 0x%x, LPDWORD 0x%x);", b, c);
	HRESULT x = mOriginal->GetPrivateData(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::FreePrivateData(REFGUID a)
{
	logf("IDirectDrawSurface7::FreePrivateData(REFGUID);");
	HRESULT x = mOriginal->FreePrivateData(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetUniquenessValue(LPDWORD a)
{
	logf("IDirectDrawSurface7::GetUniquenessValue(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetUniquenessValue(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::ChangeUniquenessValue()
{
	logf("IDirectDrawSurface7::ChangeUniquenessValue();");
	HRESULT x = mOriginal->ChangeUniquenessValue();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::SetPriority(DWORD a)
{
	logf("IDirectDrawSurface7::SetPriority(DWORD %d);", a);
	HRESULT x = mOriginal->SetPriority(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetPriority(LPDWORD a)
{
	logf("IDirectDrawSurface7::GetPriority(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetPriority(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::SetLOD(DWORD a)
{
	logf("IDirectDrawSurface7::SetLOD(DWORD %d);", a);
	HRESULT x = mOriginal->SetLOD(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawSurface7::GetLOD(LPDWORD a)
{
	logf("IDirectDrawSurface7::GetLOD(LPDWORD 0x%x);", a);
	HRESULT x = mOriginal->GetLOD(a);
	logf(" -> return %d\n", x);
	return x;
}
