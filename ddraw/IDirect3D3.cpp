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
#include "IDirect3D3.h"

m_IDirect3D3::m_IDirect3D3(IDirect3D3 * aOriginal)
{
	logf("IDirect3D3 ctor\n");
	mOriginal = aOriginal;
}

m_IDirect3D3::~m_IDirect3D3()
{
	logf("IDirect3D3 dtor\n");
}

HRESULT __stdcall m_IDirect3D3::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3D3::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirect3D3::AddRef()
{
	logf("IDirect3D3::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirect3D3::Release()
{
	logf("IDirect3D3::Release();");
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

HRESULT __stdcall m_IDirect3D3::EnumDevices(LPD3DENUMDEVICESCALLBACK a, LPVOID b)
{
	logf("IDirect3D3::EnumDevices(LPD3DENUMDEVICESCALLBACK 0x%x, LPVOID 0x%x);", a, b);
	HRESULT x = mOriginal->EnumDevices(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3D3::CreateLight(LPDIRECT3DLIGHT * a, LPUNKNOWN b)
{
	logf("IDirect3D3::CreateLight(LPDIRECT3DLIGHT * 0x%x, LPUNKNOWN 0x%x);", a, b);
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

HRESULT __stdcall m_IDirect3D3::CreateMaterial(LPDIRECT3DMATERIAL3 * a, LPUNKNOWN b)
{
	logf("IDirect3D3::CreateMaterial(LPDIRECT3DMATERIAL3 * 0x%x, LPUNKNOWN 0x%x);", a, b);
	HRESULT x = mOriginal->CreateMaterial(a, b);
	logf(" -> return %d\n", x);
	m_IDirect3DMaterial3 * n = (m_IDirect3DMaterial3 *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (m_IDirect3DMaterial3 *)new m_IDirect3DMaterial3(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirect3D3::CreateViewport(LPDIRECT3DVIEWPORT3 * a, LPUNKNOWN b)
{
	logf("IDirect3D3::CreateViewport(LPDIRECT3DVIEWPORT3 * 0x%x, LPUNKNOWN 0x%x);", a, b);
	HRESULT x = mOriginal->CreateViewport(a, b);
	logf(" -> return %d\n", x);
	m_IDirect3DViewport3 * n = (m_IDirect3DViewport3 *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (m_IDirect3DViewport3 *)new m_IDirect3DViewport3(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall m_IDirect3D3::FindDevice(LPD3DFINDDEVICESEARCH a, LPD3DFINDDEVICERESULT b)
{
	logf("IDirect3D3::FindDevice(LPD3DFINDDEVICESEARCH 0x%x, LPD3DFINDDEVICERESULT 0x%x);", a, b);
	HRESULT x = mOriginal->FindDevice(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3D3::CreateDevice(REFCLSID a, LPDIRECTDRAWSURFACE4 b, LPDIRECT3DDEVICE3 * c, LPUNKNOWN d)
{
	logf("IDirect3D3::CreateDevice(REFCLSID, LPDIRECTDRAWSURFACE4 0x%x, LPDIRECT3DDEVICE3 * 0x%x, LPUNKNOWN 0x%x);", b, c, d);
	HRESULT x = mOriginal->CreateDevice(a, (b) ? ((m_IDirectDrawSurface4 *)b)->mOriginal : 0, c, d);
	logf(" -> return %d\n", x);
	m_IDirect3DDevice3 * n = (m_IDirect3DDevice3 *)wrapfetch(*c);
	if (n == NULL && *c != NULL)
	{
		n = (m_IDirect3DDevice3 *)new m_IDirect3DDevice3(*c);
		wrapstore(n, *c);
		logf("Wrapped.\n");
	}
	*c = n;
	return x;
}

HRESULT __stdcall m_IDirect3D3::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC a, LPDIRECT3DVERTEXBUFFER * b, DWORD c, LPUNKNOWN d)
{
	logf("IDirect3D3::CreateVertexBuffer(LPD3DVERTEXBUFFERDESC 0x%x, LPDIRECT3DVERTEXBUFFER * 0x%x, DWORD %d, LPUNKNOWN 0x%x);", a, b, c, d);
	HRESULT x = mOriginal->CreateVertexBuffer(a, b, c, d);
	logf(" -> return %d\n", x);
	m_IDirect3DVertexBuffer * n = (m_IDirect3DVertexBuffer *)wrapfetch(*b);
	if (n == NULL && *b != NULL)
	{
		n = (m_IDirect3DVertexBuffer *)new m_IDirect3DVertexBuffer(*b);
		wrapstore(n, *b);
		logf("Wrapped.\n");
	}
	*b = n;
	return x;
}

HRESULT __stdcall m_IDirect3D3::EnumZBufferFormats(REFCLSID a, LPD3DENUMPIXELFORMATSCALLBACK b, LPVOID c)
{
	logf("IDirect3D3::EnumZBufferFormats(REFCLSID, LPD3DENUMPIXELFORMATSCALLBACK 0x%x, LPVOID 0x%x);", b, c);
	HRESULT x = mOriginal->EnumZBufferFormats(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3D3::EvictManagedTextures()
{
	logf("IDirect3D3::EvictManagedTextures();");
	HRESULT x = mOriginal->EvictManagedTextures();
	logf(" -> return %d\n", x);
	return x;
}
