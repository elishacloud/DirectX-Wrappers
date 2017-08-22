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
#include "IDirect3DExecuteBuffer.h"

myIDirect3DExecuteBuffer::myIDirect3DExecuteBuffer(IDirect3DExecuteBuffer * aOriginal)
{
	logf("IDirect3DExecuteBuffer ctor\n");
	mOriginal = aOriginal;
}

myIDirect3DExecuteBuffer::~myIDirect3DExecuteBuffer()
{
	logf("IDirect3DExecuteBuffer dtor\n");
}

HRESULT __stdcall myIDirect3DExecuteBuffer::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	logf("IDirect3DExecuteBuffer::QueryInterface(REFIID, LPVOID * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirect3DExecuteBuffer::AddRef()
{
	logf("IDirect3DExecuteBuffer::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirect3DExecuteBuffer::Release()
{
	logf("IDirect3DExecuteBuffer::Release();");
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

HRESULT __stdcall myIDirect3DExecuteBuffer::Initialize(LPDIRECT3DDEVICE a, LPD3DEXECUTEBUFFERDESC b)
{
	logf("IDirect3DExecuteBuffer::Initialize(LPDIRECT3DDEVICE 0x%x, LPD3DEXECUTEBUFFERDESC 0x%x);", a, b);
	HRESULT x = mOriginal->Initialize((a) ? ((myIDirect3DDevice *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::Lock(LPD3DEXECUTEBUFFERDESC a)
{
	logf("IDirect3DExecuteBuffer::Lock(LPD3DEXECUTEBUFFERDESC 0x%x);", a);
	HRESULT x = mOriginal->Lock(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::Unlock()
{
	logf("IDirect3DExecuteBuffer::Unlock();");
	HRESULT x = mOriginal->Unlock();
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::SetExecuteData(LPD3DEXECUTEDATA a)
{
	logf("IDirect3DExecuteBuffer::SetExecuteData(LPD3DEXECUTEDATA 0x%x);", a);
	HRESULT x = mOriginal->SetExecuteData(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::GetExecuteData(LPD3DEXECUTEDATA a)
{
	logf("IDirect3DExecuteBuffer::GetExecuteData(LPD3DEXECUTEDATA 0x%x);", a);
	HRESULT x = mOriginal->GetExecuteData(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::Validate(LPDWORD a, LPD3DVALIDATECALLBACK b, LPVOID c, DWORD d)
{
	logf("IDirect3DExecuteBuffer::Validate(LPDWORD 0x%x, LPD3DVALIDATECALLBACK 0x%x, LPVOID 0x%x, DWORD %d);", a, b, c, d);
	HRESULT x = mOriginal->Validate(a, b, c, d);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirect3DExecuteBuffer::Optimize(DWORD a)
{
	logf("IDirect3DExecuteBuffer::Optimize(DWORD %d);", a);
	HRESULT x = mOriginal->Optimize(a);
	logf(" -> return %d\n", x);
	return x;
}
