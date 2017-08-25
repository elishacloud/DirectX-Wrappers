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

HRESULT m_IDirectSound3DBuffer8::QueryInterface(REFIID refIID, LPVOID * pVoid)
{

	*pVoid = (LPVOID) nullptr;
	HRESULT hRes;

	if ((refIID == IID_IDirectSound3DBuffer) || (refIID == IID_IDirectSound3DBuffer8))
	{
		LPVOID pTemp;
		hRes = m_lpDirectSound3DBuffer8->QueryInterface(refIID, &pTemp);

		if (hRes == S_OK)
		{
			m_lpDirectSound3DBuffer8 = (LPDIRECTSOUND3DBUFFER8)pTemp;
			*pVoid = (LPVOID) this;
		}

		return hRes;
	}

	// Unknown interface, let DX handle this...
	hRes = m_lpDirectSound3DBuffer8->QueryInterface(refIID, pVoid);

	return hRes;
}

ULONG m_IDirectSound3DBuffer8::AddRef()
{
	ULONG nRefCnt = m_lpDirectSound3DBuffer8->AddRef();

	return nRefCnt;
}

ULONG m_IDirectSound3DBuffer8::Release()
{
	ULONG nRefCnt = m_lpDirectSound3DBuffer8->Release();

	if (nRefCnt == 0)
	{
		delete this;
		return S_OK;
	}

	return nRefCnt;
}

HRESULT m_IDirectSound3DBuffer8::GetAllParameters(LPDS3DBUFFER pDs3dBuffer)
{
	return m_lpDirectSound3DBuffer8->GetAllParameters(pDs3dBuffer);
}

HRESULT m_IDirectSound3DBuffer8::GetConeAngles(LPDWORD pdwInsideConeAngle, LPDWORD pdwOutsideConeAngle)
{
	return m_lpDirectSound3DBuffer8->GetConeAngles(pdwInsideConeAngle, pdwOutsideConeAngle);
}

HRESULT m_IDirectSound3DBuffer8::GetConeOrientation(D3DVECTOR* pvOrientation)
{
	return m_lpDirectSound3DBuffer8->GetConeOrientation(pvOrientation);
}

HRESULT m_IDirectSound3DBuffer8::GetConeOutsideVolume(LPLONG plConeOutsideVolume)
{
	return m_lpDirectSound3DBuffer8->GetConeOutsideVolume(plConeOutsideVolume);
}

HRESULT m_IDirectSound3DBuffer8::GetMaxDistance(D3DVALUE* pflMaxDistance)
{
	return m_lpDirectSound3DBuffer8->GetMaxDistance(pflMaxDistance);
}

HRESULT m_IDirectSound3DBuffer8::GetMinDistance(D3DVALUE* pflMinDistance)
{
	return m_lpDirectSound3DBuffer8->GetMinDistance(pflMinDistance);
}

HRESULT m_IDirectSound3DBuffer8::GetMode(LPDWORD pdwMode)
{
	return m_lpDirectSound3DBuffer8->GetMode(pdwMode);
}

HRESULT m_IDirectSound3DBuffer8::GetPosition(D3DVECTOR* pvPosition)
{
	return m_lpDirectSound3DBuffer8->GetPosition(pvPosition);
}

HRESULT m_IDirectSound3DBuffer8::GetVelocity(D3DVECTOR* pvVelocity)
{
	return m_lpDirectSound3DBuffer8->GetVelocity(pvVelocity);
}

HRESULT m_IDirectSound3DBuffer8::SetAllParameters(LPCDS3DBUFFER pcDs3dBuffer, DWORD dwApply)
{
	return m_lpDirectSound3DBuffer8->SetAllParameters(pcDs3dBuffer, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetConeAngles(DWORD dwInsideConeAngle, DWORD dwOutsideConeAngle, DWORD dwApply)
{
	return m_lpDirectSound3DBuffer8->SetConeAngles(dwInsideConeAngle, dwOutsideConeAngle, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetConeOrientation(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
	return m_lpDirectSound3DBuffer8->SetConeOrientation(x, y, z, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetConeOutsideVolume(LONG lConeOutsideVolume, DWORD dwApply)
{
	return m_lpDirectSound3DBuffer8->SetConeOutsideVolume(lConeOutsideVolume, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetMaxDistance(D3DVALUE flMaxDistance, DWORD dwApply)
{
	return m_lpDirectSound3DBuffer8->SetMaxDistance(flMaxDistance, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetMinDistance(D3DVALUE flMinDistance, DWORD dwApply)
{
	return m_lpDirectSound3DBuffer8->SetMinDistance(flMinDistance, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetMode(DWORD dwMode, DWORD dwApply)
{
	return m_lpDirectSound3DBuffer8->SetMode(dwMode, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetPosition(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
	return m_lpDirectSound3DBuffer8->SetPosition(x, y, z, dwApply);
}

HRESULT m_IDirectSound3DBuffer8::SetVelocity(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply)
{
	return m_lpDirectSound3DBuffer8->SetVelocity(x, y, z, dwApply);
}
