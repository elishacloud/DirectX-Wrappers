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
#include "IDirect3DMaterial.h"

m_IDirect3DMaterial::m_IDirect3DMaterial(IDirect3DMaterial * aOriginal)
{
	logf("IDirect3DMaterial ctor\n");
	mOriginal = aOriginal;
}

m_IDirect3DMaterial::~m_IDirect3DMaterial()
{
	logf("IDirect3DMaterial dtor\n");
}

HRESULT __stdcall m_IDirect3DMaterial::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3DMaterial::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirect3DMaterial::AddRef()
{
	logf("IDirect3DMaterial::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirect3DMaterial::Release()
{
	logf("IDirect3DMaterial::Release();");
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

HRESULT __stdcall m_IDirect3DMaterial::Initialize(LPDIRECT3D a)
{
	logf("IDirect3DMaterial::Initialize(LPDIRECT3D 0x%x);", a);
	HRESULT x = mOriginal->Initialize((a) ? ((m_IDirect3D *)a)->mOriginal : 0);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DMaterial::SetMaterial(LPD3DMATERIAL a)
{
	logf("IDirect3DMaterial::SetMaterial(LPD3DMATERIAL 0x%x);", a);
	HRESULT x = mOriginal->SetMaterial(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DMaterial::GetMaterial(LPD3DMATERIAL a)
{
	logf("IDirect3DMaterial::GetMaterial(LPD3DMATERIAL 0x%x);", a);
	HRESULT x = mOriginal->GetMaterial(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DMaterial::GetHandle(LPDIRECT3DDEVICE a, LPD3DMATERIALHANDLE b)
{
	logf("IDirect3DMaterial::GetHandle(LPDIRECT3DDEVICE 0x%x, LPD3DMATERIALHANDLE 0x%x);", a, b);
	HRESULT x = mOriginal->GetHandle((a) ? ((m_IDirect3DDevice *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DMaterial::Reserve()
{
	logf("IDirect3DMaterial::Reserve();");
	HRESULT x = mOriginal->Reserve();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirect3DMaterial::Unreserve()
{
	logf("IDirect3DMaterial::Unreserve();");
	HRESULT x = mOriginal->Unreserve();
	logf(" -> return %d\n", x);
	return x;
}
