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
#include "IDirectDrawClipper.h"

myIDirectDrawClipper::myIDirectDrawClipper(IDirectDrawClipper * aOriginal)
{
	logf("IDirectDrawClipper ctor\n");
	mOriginal = aOriginal;
}

myIDirectDrawClipper::~myIDirectDrawClipper()
{
	logf("IDirectDrawClipper dtor\n");
}

HRESULT __stdcall myIDirectDrawClipper::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDrawClipper::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall myIDirectDrawClipper::AddRef()
{
	logf("IDirectDrawClipper::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall myIDirectDrawClipper::Release()
{
	logf("IDirectDrawClipper::Release();");
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

HRESULT __stdcall myIDirectDrawClipper::GetClipList(LPRECT a, LPRGNDATA b, LPDWORD c)
{
	logf("IDirectDrawClipper::GetClipList(LPRECT 0x%x, LPRGNDATA 0x%x, LPDWORD 0x%x);", a, b, c);
	HRESULT x = mOriginal->GetClipList(a, b, c);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDrawClipper::GetHWnd(HWND FAR * a)
{
	logf("IDirectDrawClipper::GetHWnd(HWND FAR *);");
	HRESULT x = mOriginal->GetHWnd(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDrawClipper::Initialize(LPDIRECTDRAW a, DWORD b)
{
	logf("IDirectDrawClipper::Initialize(LPDIRECTDRAW 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->Initialize((a) ? ((myIDirectDraw *)a)->mOriginal : 0, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDrawClipper::IsClipListChanged(BOOL FAR * a)
{
	logf("IDirectDrawClipper::IsClipListChanged(BOOL FAR *);");
	HRESULT x = mOriginal->IsClipListChanged(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDrawClipper::SetClipList(LPRGNDATA a, DWORD b)
{
	logf("IDirectDrawClipper::SetClipList(LPRGNDATA 0x%x, DWORD %d);", a, b);
	HRESULT x = mOriginal->SetClipList(a, b);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall myIDirectDrawClipper::SetHWnd(DWORD a, HWND b)
{
	logf("IDirectDrawClipper::SetHWnd(DWORD %d, HWND 0x%x);", a, b);
	HRESULT x = mOriginal->SetHWnd(a, b);
	logf(" -> return %d\n", x);
	return x;
}
