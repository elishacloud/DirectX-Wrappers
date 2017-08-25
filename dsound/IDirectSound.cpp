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

HRESULT m_IDirectSound8::QueryInterface(REFIID refIID, LPVOID * pVoid)
{
	*pVoid = nullptr;

	if ((refIID == IID_IDirectSound) || (refIID == IID_IDirectSound8))
	{
		LPVOID pTemp;
		HRESULT hRes = m_lpDirectSound8->QueryInterface(refIID, &pTemp);

		if (hRes != S_OK)
		{
			return hRes;
		}

		m_lpDirectSound8 = (LPDIRECTSOUND8)pTemp;

		*pVoid = (LPVOID) this;

		return S_OK;
	}

	return m_lpDirectSound8->QueryInterface(refIID, pVoid);
}

ULONG m_IDirectSound8::AddRef()
{
	ULONG nRefCnt = m_lpDirectSound8->AddRef();

	return nRefCnt;
}

ULONG m_IDirectSound8::Release()
{
	ULONG nRefCnt = m_lpDirectSound8->Release();

	if (nRefCnt == 0)
	{
		delete this;
		return S_OK;
	}

	return nRefCnt;
}

HRESULT m_IDirectSound8::CreateSoundBuffer(LPCDSBUFFERDESC pcDSBufferDesc, LPDIRECTSOUNDBUFFER *ppDSBuffer, LPUNKNOWN pUnkOuter)
{
	DSBUFFERDESC dsdesc = *pcDSBufferDesc;

	m_IDirectSoundBuffer8* pDSBX = new m_IDirectSoundBuffer8;

	HRESULT hRes = m_lpDirectSound8->CreateSoundBuffer(&dsdesc, (LPDIRECTSOUNDBUFFER*) &(pDSBX->m_lpDirectSoundBuffer8) /*ppDSBuffer*/, pUnkOuter);

	*ppDSBuffer = (LPDIRECTSOUNDBUFFER8)pDSBX;

	if (pcDSBufferDesc->dwFlags & DSBCAPS_PRIMARYBUFFER)
	{
		pDSBX->SetPrimaryBuffer(true);
	}

	return hRes;
}

HRESULT m_IDirectSound8::GetCaps(LPDSCAPS pDSCaps)
{
	HRESULT hRes = m_lpDirectSound8->GetCaps(pDSCaps);

	return hRes;
}

HRESULT m_IDirectSound8::DuplicateSoundBuffer(LPDIRECTSOUNDBUFFER pDSBufferOriginal, LPDIRECTSOUNDBUFFER *ppDSBufferDuplicate)
{
	*ppDSBufferDuplicate = nullptr;

	m_IDirectSoundBuffer8* pDSBX = new m_IDirectSoundBuffer8;

	HRESULT hRes = m_lpDirectSound8->DuplicateSoundBuffer((LPDIRECTSOUNDBUFFER)(((m_IDirectSoundBuffer8*)pDSBufferOriginal)->m_lpDirectSoundBuffer8), (LPDIRECTSOUNDBUFFER*) &(pDSBX->m_lpDirectSoundBuffer8));

	if (hRes != S_OK)
	{
		delete pDSBX;
		return hRes;
	}

	*ppDSBufferDuplicate = (LPDIRECTSOUNDBUFFER8)pDSBX;

	return hRes;
}

HRESULT m_IDirectSound8::SetCooperativeLevel(HWND hwnd, DWORD dwLevel)
{
	return m_lpDirectSound8->SetCooperativeLevel(hwnd, dwLevel);
}

HRESULT m_IDirectSound8::Compact()
{
	return m_lpDirectSound8->Compact();
}

HRESULT m_IDirectSound8::GetSpeakerConfig(LPDWORD pdwSpeakerConfig)
{
	return m_lpDirectSound8->GetSpeakerConfig(pdwSpeakerConfig);
}

HRESULT m_IDirectSound8::SetSpeakerConfig(DWORD dwSpeakerConfig)
{
	return m_lpDirectSound8->SetSpeakerConfig(dwSpeakerConfig);
}

HRESULT m_IDirectSound8::Initialize(LPCGUID pcGuidDevice)
{
	return m_lpDirectSound8->Initialize(pcGuidDevice);
}

HRESULT  m_IDirectSound8::VerifyCertification(LPDWORD pdwCertified)
{
	HRESULT hRes = m_lpDirectSound8->VerifyCertification(pdwCertified);

	return hRes;
}
