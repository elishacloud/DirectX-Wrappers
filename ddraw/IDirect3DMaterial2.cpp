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
#include "IDirect3DMaterial2.h"

myIDirect3DMaterial2::myIDirect3DMaterial2(IDirect3DMaterial2 * aOriginal)
{
	logf("IDirect3DMaterial2 ctor\n");
	mOriginal = aOriginal;
}

myIDirect3DMaterial2::~myIDirect3DMaterial2()
{
	logf("IDirect3DMaterial2 dtor\n");
}

HRESULT __stdcall myIDirect3DMaterial2::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3DMaterial2::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirect3DMaterial2::AddRef()
{
	logf("IDirect3DMaterial2::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirect3DMaterial2::Release()
{
	logf("IDirect3DMaterial2::Release();");
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

HRESULT __stdcall myIDirect3DMaterial2::SetMaterial(LPD3DMATERIAL a)
{
	logf("IDirect3DMaterial2::SetMaterial(LPD3DMATERIAL 0x%x);", a);
	HRESULT x = mOriginal->SetMaterial(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DMaterial2::GetMaterial(LPD3DMATERIAL a)
{
	logf("IDirect3DMaterial2::GetMaterial(LPD3DMATERIAL 0x%x);", a);
	HRESULT x = mOriginal->GetMaterial(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DMaterial2::GetHandle(LPDIRECT3DDEVICE2 a, LPD3DMATERIALHANDLE b)
{
	logf("IDirect3DMaterial2::GetHandle(LPDIRECT3DDEVICE2 0x%x, LPD3DMATERIALHANDLE 0x%x);", a, b);
	HRESULT x = mOriginal->GetHandle((a) ? ((myIDirect3DDevice2 *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}
