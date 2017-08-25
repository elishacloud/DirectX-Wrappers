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
#include "IDirectDrawColorControl.h"

m_IDirectDrawColorControl::m_IDirectDrawColorControl(IDirectDrawColorControl * aOriginal)
{
	logf("IDirectDrawColorControl ctor\n");
	mOriginal = aOriginal;
}

m_IDirectDrawColorControl::~m_IDirectDrawColorControl()
{
	logf("IDirectDrawColorControl dtor\n");
}

HRESULT __stdcall m_IDirectDrawColorControl::QueryInterface(REFIID riid, LPVOID FAR * ppvObj)
{
	logf("IDirectDrawColorControl::QueryInterface(REFIID, LPVOID FAR * 0x%x);", ppvObj);
	HRESULT x = mOriginal->QueryInterface(riid, ppvObj);
	logf(" -> return %d\n", x);
	if (x == 0) genericQueryInterface(riid, ppvObj);
	return x;
}

ULONG __stdcall m_IDirectDrawColorControl::AddRef()
{
	logf("IDirectDrawColorControl::AddRef();");
	ULONG x = mOriginal->AddRef();
	logf(" -> return %d\n", x);
	return x;
}

ULONG __stdcall m_IDirectDrawColorControl::Release()
{
	logf("IDirectDrawColorControl::Release();");
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

HRESULT __stdcall m_IDirectDrawColorControl::GetColorControls(LPDDCOLORCONTROL a)
{
	logf("IDirectDrawColorControl::GetColorControls(LPDDCOLORCONTROL 0x%x);", a);
	HRESULT x = mOriginal->GetColorControls(a);
	logf(" -> return %d\n", x);
	return x;
}

HRESULT __stdcall m_IDirectDrawColorControl::SetColorControls(LPDDCOLORCONTROL a)
{
	logf("IDirectDrawColorControl::SetColorControls(LPDDCOLORCONTROL 0x%x);", a);
	HRESULT x = mOriginal->SetColorControls(a);
	logf(" -> return %d\n", x);
	return x;
}
