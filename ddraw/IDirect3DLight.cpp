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
#include "IDirect3DLight.h"

myIDirect3DLight::myIDirect3DLight(IDirect3DLight * aOriginal)
{
	logf("IDirect3DLight ctor\n");
	mOriginal = aOriginal;
}

myIDirect3DLight::~myIDirect3DLight()
{
	logf("IDirect3DLight dtor\n");
}

HRESULT __stdcall myIDirect3DLight::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3DLight::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirect3DLight::AddRef()
{
	logf("IDirect3DLight::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirect3DLight::Release()
{
	logf("IDirect3DLight::Release();");
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

HRESULT __stdcall myIDirect3DLight::Initialize(LPDIRECT3D a)
{
	logf("IDirect3DLight::Initialize(LPDIRECT3D 0x%x);", a);
	HRESULT x = mOriginal->Initialize((a) ? ((myIDirect3D *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DLight::SetLight(LPD3DLIGHT a)
{
	logf("IDirect3DLight::SetLight(LPD3DLIGHT 0x%x);", a);
	HRESULT x = mOriginal->SetLight(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DLight::GetLight(LPD3DLIGHT a)
{
	logf("IDirect3DLight::GetLight(LPD3DLIGHT 0x%x);", a);
	HRESULT x = mOriginal->GetLight(a);
	logf(" -> return %d\n", x);
	return x;
}
