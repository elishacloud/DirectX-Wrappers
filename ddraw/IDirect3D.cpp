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
#include "IDirect3D.h"

myIDirect3D::myIDirect3D(IDirect3D * aOriginal)
{
	logf("IDirect3D ctor\n");
	mOriginal = aOriginal;
}

myIDirect3D::~myIDirect3D()
{
	logf("IDirect3D dtor\n");
}

HRESULT __stdcall myIDirect3D::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3D::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirect3D::AddRef()
{
	logf("IDirect3D::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirect3D::Release()
{
	logf("IDirect3D::Release();");
	ULONG x = mOriginal->Release();
	logf(" -> return %d\n", x);
	if (x == 0)
	{
		wrapstore(mOriginal, 0);
		mOriginal = nullptr;
		delete this;
	}
	return x;
}

HRESULT __stdcall myIDirect3D::Initialize(REFCLSID a)
{
	logf("IDirect3D::Initialize(REFCLSID);");
	HRESULT x = mOriginal->Initialize(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3D::EnumDevices(LPD3DENUMDEVICESCALLBACK a, LPVOID b)
{
	logf("IDirect3D::EnumDevices(LPD3DENUMDEVICESCALLBACK 0x%x, LPVOID 0x%x);", a, b);
	HRESULT x = mOriginal->EnumDevices(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3D::CreateLight(LPDIRECT3DLIGHT * a, IUnknown * b)
{
	logf("IDirect3D::CreateLight(LPDIRECT3DLIGHT * 0x%x, IUnknown *);", a);
	HRESULT x = mOriginal->CreateLight(a, b);
	logf(" -> return %d\n", x);
	myIDirect3DLight * n = (myIDirect3DLight *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (myIDirect3DLight *)new myIDirect3DLight(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall myIDirect3D::CreateMaterial(LPDIRECT3DMATERIAL * a, IUnknown * b)
{
	logf("IDirect3D::CreateMaterial(LPDIRECT3DMATERIAL * 0x%x, IUnknown *);", a);
	HRESULT x = mOriginal->CreateMaterial(a, b);
	logf(" -> return %d\n", x);
	myIDirect3DMaterial * n = (myIDirect3DMaterial *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (myIDirect3DMaterial *)new myIDirect3DMaterial(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall myIDirect3D::CreateViewport(LPDIRECT3DVIEWPORT * a, IUnknown * b)
{
	logf("IDirect3D::CreateViewport(LPDIRECT3DVIEWPORT * 0x%x, IUnknown *);", a);
	HRESULT x = mOriginal->CreateViewport(a, b);
	logf(" -> return %d\n", x);
	myIDirect3DViewport * n = (myIDirect3DViewport *)wrapfetch(*a);
	if (n == NULL && *a != NULL)
	{
		n = (myIDirect3DViewport *)new myIDirect3DViewport(*a);
		wrapstore(n, *a);
		logf("Wrapped.\n");
	}
	*a = n;
	return x;
}

HRESULT __stdcall myIDirect3D::FindDevice(LPD3DFINDDEVICESEARCH a, LPD3DFINDDEVICERESULT b)
{
	logf("IDirect3D::FindDevice(LPD3DFINDDEVICESEARCH 0x%x, LPD3DFINDDEVICERESULT 0x%x);", a, b);
	HRESULT x = mOriginal->FindDevice(a, b);
	logf(" -> return %d\n", x);
	return x;
}
