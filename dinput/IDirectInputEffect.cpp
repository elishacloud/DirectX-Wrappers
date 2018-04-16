/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "dinput.h"

HRESULT m_IDirectInputEffect::QueryInterface(REFIID riid, LPVOID * ppvObj)
{
	if ((riid == IID_IDirectInputEffect || riid == IID_IUnknown) && ppvObj)
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	HRESULT hr = ProxyInterface->QueryInterface(riid, ppvObj);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppvObj);
	}

	return hr;
}

ULONG m_IDirectInputEffect::AddRef()
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirectInputEffect::Release()
{
	ULONG x = ProxyInterface->Release();

	if (x == 0)
	{
		delete this;
	}

	return x;
}

HRESULT m_IDirectInputEffect::Initialize(HINSTANCE hinst, DWORD dwVersion, REFGUID rguid)
{
	return ProxyInterface->Initialize(hinst, dwVersion, rguid);
}

HRESULT m_IDirectInputEffect::GetEffectGuid(LPGUID pguid)
{
	return ProxyInterface->GetEffectGuid(pguid);
}

HRESULT m_IDirectInputEffect::GetParameters(LPDIEFFECT peff, DWORD dwFlags)
{
	return ProxyInterface->GetParameters(peff, dwFlags);
}

HRESULT m_IDirectInputEffect::SetParameters(LPCDIEFFECT peff, DWORD dwFlags)
{
	return ProxyInterface->SetParameters(peff, dwFlags);
}

HRESULT m_IDirectInputEffect::Start(DWORD dwIterations, DWORD dwFlags)
{
	return ProxyInterface->Start(dwIterations, dwFlags);
}

HRESULT m_IDirectInputEffect::Stop()
{
	return ProxyInterface->Stop();
}

HRESULT m_IDirectInputEffect::GetEffectStatus(LPDWORD pdwFlags)
{
	return ProxyInterface->GetEffectStatus(pdwFlags);
}

HRESULT m_IDirectInputEffect::Download()
{
	return ProxyInterface->Download();
}

HRESULT m_IDirectInputEffect::Unload()
{
	return ProxyInterface->Unload();
}

HRESULT m_IDirectInputEffect::Escape(LPDIEFFESCAPE pesc)
{
	return ProxyInterface->Escape(pesc);
}
