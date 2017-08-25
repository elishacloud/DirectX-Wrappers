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

HRESULT m_IDirectSoundBuffer8::QueryInterface(REFIID refIID, LPVOID * pVoid)
{
	*pVoid = (LPVOID) nullptr;
	HRESULT hRes;

	if ((refIID == IID_IDirectSoundBuffer) || (refIID == IID_IDirectSoundBuffer8))
	{
		LPVOID pTemp;
		hRes = m_lpDirectSoundBuffer8->QueryInterface(refIID, &pTemp);

		if (hRes == S_OK)
		{
			m_lpDirectSoundBuffer8 = (LPDIRECTSOUNDBUFFER8)pTemp;
			*pVoid = (LPVOID) this;
		}

		return hRes;
	}

	if ((refIID == IID_IDirectSound3DBuffer) || (refIID == IID_IDirectSound3DBuffer8))
	{
		m_IDirectSound3DBuffer8* pDS3DBX = new m_IDirectSound3DBuffer8;

		hRes = m_lpDirectSoundBuffer8->QueryInterface(refIID, (LPVOID*) &(pDS3DBX->m_lpDirectSound3DBuffer8));

		if (hRes == S_OK)
		{
			*pVoid = (LPVOID)pDS3DBX;
		}

		return hRes;
	}

	if ((refIID == IID_IDirectSound3DListener8) || (refIID == IID_IDirectSound3DListener8))
	{
		m_IDirectSound3DListener8* pDS3DLX = new m_IDirectSound3DListener8;

		hRes = m_lpDirectSoundBuffer8->QueryInterface(refIID, (LPVOID*) &(pDS3DLX->m_lpDirectSound3DListener8));

		if (hRes == S_OK)
		{
			*pVoid = (LPVOID)pDS3DLX;
		}

		return hRes;
	}

	// Unknown interface, let DX handle this...
	hRes = m_lpDirectSoundBuffer8->QueryInterface(refIID, pVoid);

	return hRes;
}

ULONG m_IDirectSoundBuffer8::AddRef()
{
	ULONG nRefCnt = m_lpDirectSoundBuffer8->AddRef();

	return nRefCnt;
}

ULONG m_IDirectSoundBuffer8::Release()
{
	ULONG nRefCnt = m_lpDirectSoundBuffer8->Release();

	if (nRefCnt == 0)
	{
		delete this;
		return S_OK;
	}

	return nRefCnt;
}

HRESULT m_IDirectSoundBuffer8::GetCaps(LPDSBCAPS pDSBufferCaps)
{
	return m_lpDirectSoundBuffer8->GetCaps(pDSBufferCaps);
}

HRESULT m_IDirectSoundBuffer8::GetCurrentPosition(LPDWORD pdwCurrentPlayCursor, LPDWORD pdwCurrentWriteCursor)
{
	HRESULT hRes = m_lpDirectSoundBuffer8->GetCurrentPosition(pdwCurrentPlayCursor, pdwCurrentWriteCursor);

	return hRes;
}

HRESULT m_IDirectSoundBuffer8::GetFormat(LPWAVEFORMATEX pwfxFormat, DWORD dwSizeAllocated, LPDWORD pdwSizeWritten)
{
	return m_lpDirectSoundBuffer8->GetFormat(pwfxFormat, dwSizeAllocated, pdwSizeWritten);
}

HRESULT m_IDirectSoundBuffer8::GetVolume(LPLONG plVolume)
{
	return m_lpDirectSoundBuffer8->GetVolume(plVolume);
}

HRESULT m_IDirectSoundBuffer8::GetPan(LPLONG plPan)
{
	return m_lpDirectSoundBuffer8->GetPan(plPan);
}

HRESULT m_IDirectSoundBuffer8::GetFrequency(LPDWORD pdwFrequency)
{
	return m_lpDirectSoundBuffer8->GetFrequency(pdwFrequency);
}

HRESULT m_IDirectSoundBuffer8::GetStatus(LPDWORD pdwStatus)
{
	HRESULT hRes = m_lpDirectSoundBuffer8->GetStatus(pdwStatus);

	return hRes;
}

HRESULT m_IDirectSoundBuffer8::Initialize(LPDIRECTSOUND pDirectSound, LPCDSBUFFERDESC pcDSBufferDesc)
{
	return m_lpDirectSoundBuffer8->Initialize(((m_IDirectSound8*)pDirectSound)->m_lpDirectSound8, pcDSBufferDesc);
}

HRESULT m_IDirectSoundBuffer8::Lock(DWORD dwOffset, DWORD dwBytes, LPVOID *ppvAudioPtr1, LPDWORD pdwAudioBytes1, LPVOID *ppvAudioPtr2, LPDWORD pdwAudioBytes2, DWORD dwFlags)
{
	HRESULT hRes = m_lpDirectSoundBuffer8->Lock(dwOffset, dwBytes, ppvAudioPtr1, pdwAudioBytes1, ppvAudioPtr2, pdwAudioBytes2, dwFlags);

	return hRes;
}

HRESULT m_IDirectSoundBuffer8::Play(DWORD dwReserved1, DWORD dwPriority, DWORD dwFlags)
{

	return m_lpDirectSoundBuffer8->Play(dwReserved1, dwPriority, dwFlags);
}

HRESULT m_IDirectSoundBuffer8::SetCurrentPosition(DWORD dwNewPosition)
{
	return m_lpDirectSoundBuffer8->SetCurrentPosition(dwNewPosition);
}

HRESULT m_IDirectSoundBuffer8::SetFormat(LPCWAVEFORMATEX pcfxFormat)
{
	return m_lpDirectSoundBuffer8->SetFormat(pcfxFormat);
}

HRESULT m_IDirectSoundBuffer8::SetVolume(LONG lVolume)
{
	return m_lpDirectSoundBuffer8->SetVolume(lVolume);
}

HRESULT m_IDirectSoundBuffer8::SetPan(LONG lPan)
{
	return m_lpDirectSoundBuffer8->SetPan(lPan);
}

HRESULT m_IDirectSoundBuffer8::SetFrequency(DWORD dwFrequency)
{
	return m_lpDirectSoundBuffer8->SetFrequency(dwFrequency);
}

HRESULT m_IDirectSoundBuffer8::Stop()
{
	return m_lpDirectSoundBuffer8->Stop();
}

HRESULT m_IDirectSoundBuffer8::Unlock(LPVOID pvAudioPtr1, DWORD dwAudioBytes1, LPVOID pvAudioPtr2, DWORD dwAudioBytes2)
{
	HRESULT hRes = m_lpDirectSoundBuffer8->Unlock(pvAudioPtr1, dwAudioBytes1, pvAudioPtr2, dwAudioBytes2);

	return hRes;
}

HRESULT m_IDirectSoundBuffer8::Restore()
{
	return m_lpDirectSoundBuffer8->Restore();
}

// IDirectSoundBuffer8 methods
HRESULT m_IDirectSoundBuffer8::SetFX(DWORD dwEffectsCount, LPDSEFFECTDESC pDSFXDesc, LPDWORD pdwResultCodes)
{
	return m_lpDirectSoundBuffer8->SetFX(dwEffectsCount, pDSFXDesc, pdwResultCodes);
}

HRESULT m_IDirectSoundBuffer8::AcquireResources(DWORD dwFlags, DWORD dwEffectsCount, LPDWORD pdwResultCodes)
{
	return m_lpDirectSoundBuffer8->AcquireResources(dwFlags, dwEffectsCount, pdwResultCodes);
}

HRESULT m_IDirectSoundBuffer8::GetObjectInPath(REFGUID rguidObject, DWORD dwIndex, REFGUID rguidInterface, LPVOID *ppObject)
{
	return m_lpDirectSoundBuffer8->GetObjectInPath(rguidObject, dwIndex, rguidInterface, ppObject);
}
