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
#include "IDirect3D2.h"

m_IDirect3D2::m_IDirect3D2(IDirect3D2 * aOriginal)
{
	logf("IDirect3D2 ctor\n");
	mOriginal = aOriginal;
}

m_IDirect3D2::~m_IDirect3D2()
{
	logf("IDirect3D2 dtor\n");
}

HRESULT __stdcall m_IDirect3D2::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3D2::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirect3D2::AddRef()
{
	logf("IDirect3D2::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirect3D2::Release()
{
	logf("IDirect3D2::Release();");
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

HRESULT __stdcall m_IDirect3D2::EnumDevices(LPD3DENUMDEVICESCALLBACK a, LPVOID b)
{
	logf("IDirect3D2::EnumDevices(LPD3DENUMDEVICESCALLBACK 0x%x, LPVOID 0x%x);", a, b);
	HRESULT x = mOriginal->EnumDevices(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3D2::CreateLight(LPDIRECT3DLIGHT * a, IUnknown * b)
{
	logf("IDirect3D2::CreateLight(LPDIRECT3DLIGHT * 0x%x, IUnknown *);", a);
	HRESULT x = mOriginal->CreateLight(a, b);
	logf(" -> return %d\n", x);
	m_IDirect3DLight * n = (m_IDirect3DLight *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (m_IDirect3DLight *)new m_IDirect3DLight(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirect3D2::CreateMaterial(LPDIRECT3DMATERIAL2 * a, IUnknown * b)
{
	logf("IDirect3D2::CreateMaterial(LPDIRECT3DMATERIAL2 * 0x%x, IUnknown *);", a);
	HRESULT x = mOriginal->CreateMaterial(a, b);
	logf(" -> return %d\n", x);
	m_IDirect3DMaterial2 * n = (m_IDirect3DMaterial2 *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (m_IDirect3DMaterial2 *)new m_IDirect3DMaterial2(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirect3D2::CreateViewport(LPDIRECT3DVIEWPORT2 * a, IUnknown * b)
{
	logf("IDirect3D2::CreateViewport(LPDIRECT3DVIEWPORT2 * 0x%x, IUnknown *);", a);
	HRESULT x = mOriginal->CreateViewport(a, b);
	logf(" -> return %d\n", x);
	m_IDirect3DViewport2 * n = (m_IDirect3DViewport2 *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (m_IDirect3DViewport2 *)new m_IDirect3DViewport2(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirect3D2::FindDevice(LPD3DFINDDEVICESEARCH a, LPD3DFINDDEVICERESULT b)
{
	logf("IDirect3D2::FindDevice(LPD3DFINDDEVICESEARCH 0x%x, LPD3DFINDDEVICERESULT 0x%x);", a, b);
	HRESULT x = mOriginal->FindDevice(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3D2::CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE b, LPDIRECT3DDEVICE2 * c)
{
	logf("IDirect3D2::CreateDevice(REFCLSID, LPDIRECTDRAWSURFACE 0x%x, LPDIRECT3DDEVICE2 * 0x%x);", b, c);
	HRESULT x = mOriginal->CreateDevice(a, (b) ? ((m_IDirectDrawSurface *)b)->mOriginal : 0, c);
	logf(" -> return %d\n", x);
	m_IDirect3DDevice2 * n = (m_IDirect3DDevice2 *)wrapfetch(*c);
	if (n == NULL && *c != NULL)
	{
		n = (m_IDirect3DDevice2 *)new m_IDirect3DDevice2(*c);
		wrapstore(n, *c);
		logf("Wrapped.\n");
	}
	*c = n;
	return x;
}
