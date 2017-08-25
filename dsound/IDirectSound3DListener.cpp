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
*
* Code taken from code found here: https://github.com/elishacloud/DirectSoundControl
*/

#include "dsound.h"

HRESULT m_IDirectSound3DListener8::QueryInterface(REFIID refIID, LPVOID * pVoid)
{
	*pVoid = (LPVOID) nullptr;
	HRESULT hRes;

	if ((refIID == IID_IDirectSound3DListener) || (refIID == IID_IDirectSound3DListener8))
	{
		LPVOID pTemp;
		hRes = m_lpDirectSound3DListener8->QueryInterface(refIID, &pTemp);

		if (hRes == S_OK)
		{
			m_lpDirectSound3DListener8 = (LPDIRECTSOUND3DLISTENER8)pTemp;
			*pVoid = (LPVOID) this;
		}

		return hRes;
	}

	// Unknown interface, let DX handle this...
	hRes = m_lpDirectSound3DListener8->QueryInterface(refIID, pVoid);

	return hRes;
}

ULONG m_IDirectSound3DListener8::AddRef()
{
	ULONG nRefCnt = m_lpDirectSound3DListener8->AddRef();

	return nRefCnt;
}

ULONG m_IDirectSound3DListener8::Release()
{
	ULONG nRefCnt = m_lpDirectSound3DListener8->Release();

	if (nRefCnt == 0)
	{
		delete this;
		return S_OK;
	}

	return nRefCnt;
}

// IDirectSound3DListener methods
HRESULT m_IDirectSound3DListener8::GetAllParameters(LPDS3DLISTENER pListener)
{
	return m_lpDirectSound3DListener8->GetAllParameters(pListener);
}

HRESULT m_IDirectSound3DListener8::GetDistanceFactor(D3DVALUE* pflDistanceFactor)
{
	return m_lpDirectSound3DListener8->GetDistanceFactor(pflDistanceFactor);
}

HRESULT m_IDirectSound3DListener8::GetDopplerFactor(D3DVALUE* pflDopplerFactor)
{
	return m_lpDirectSound3DListener8->GetDopplerFactor(pflDopplerFactor);
}

HRESULT m_IDirectSound3DListener8::GetOrientation(D3DVECTOR* pvOrientFront, D3DVECTOR* pvOrientTop)
{
	return m_lpDirectSound3DListener8->GetOrientation(pvOrientFront, pvOrientTop);
}

HRESULT m_IDirectSound3DListener8::GetPosition(D3DVECTOR* pvPosition)
{
	return m_lpDirectSound3DListener8->GetPosition(pvPosition);
}

HRESULT m_IDirectSound3DListener8::GetRolloffFactor(D3DVALUE* pflRolloffFactor)
{
	return m_lpDirectSound3DListener8->GetRolloffFactor(pflRolloffFactor);
}

HRESULT m_IDirectSound3DListener8::GetVelocity(D3DVECTOR* pvVelocity)
{
	return m_lpDirectSound3DListener8->GetVelocity(pvVelocity);
}

HRESULT m_IDirectSound3DListener8::SetAllParameters(LPCDS3DLISTENER pcListener, DWORD dwApply)
{
	return m_lpDirectSound3DListener8->SetAllParameters(pcListener, dwApply);
}

HRESULT m_IDirectSound3DListener8::SetDistanceFactor(D3DVALUE flDistanceFactor, DWORD dwApply)
{
	return m_lpDirectSound3DListener8->SetDistanceFactor(flDistanceFactor, dwApply);
}

HRESULT m_IDirectSound3DListener8::SetDopplerFactor(D3DVALUE flDopplerFactor, DWORD dwApply)
{
	return m_lpDirectSound3DListener8->SetDopplerFactor(flDopplerFactor, dwApply);
}

HRESULT m_IDirectSound3DListener8::SetOrientation(D3DVALUE xFront, D3DVALUE yFront, D3DVALUE zFront, D3DVALUE xTop, D3DVALUE yTop, D3DVALUE zTop, DWORD dwApply)
{
	return m_lpDirectSound3DListener8->SetOrientation(xFront, yFront, zFront, xTop, yTop, zTop, dwApply);
}

HRESULT m_IDirectSound3DListener8::SetPosition(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
	return m_lpDirectSound3DListener8->SetPosition(x, y, z, dwApply);
}

HRESULT m_IDirectSound3DListener8::SetRolloffFactor(D3DVALUE flRolloffFactor, DWORD dwApply)
{
	return m_lpDirectSound3DListener8->SetRolloffFactor(flRolloffFactor, dwApply);
}

HRESULT m_IDirectSound3DListener8::SetVelocity(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
	return m_lpDirectSound3DListener8->SetVelocity(x, y, z, dwApply);
}

HRESULT m_IDirectSound3DListener8::CommitDeferredSettings()
{
	return m_lpDirectSound3DListener8->CommitDeferredSettings();
}
