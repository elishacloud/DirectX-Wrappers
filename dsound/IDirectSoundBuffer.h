#pragma once

class m_IDirectSoundBuffer8 : public IDirectSoundBuffer8
{
public:
	virtual HRESULT __stdcall QueryInterface(REFIID, LPVOID *);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	// IDirectSoundBuffer methods
	virtual HRESULT __stdcall GetCaps(LPDSBCAPS pDSBufferCaps);
	virtual HRESULT __stdcall GetCurrentPosition(LPDWORD pdwCurrentPlayCursor, LPDWORD pdwCurrentWriteCursor);
	virtual HRESULT __stdcall GetFormat(LPWAVEFORMATEX pwfxFormat, DWORD dwSizeAllocated, LPDWORD pdwSizeWritten);
	virtual HRESULT __stdcall GetVolume(LPLONG plVolume);
	virtual HRESULT __stdcall GetPan(LPLONG plPan);
	virtual HRESULT __stdcall GetFrequency(LPDWORD pdwFrequency);
	virtual HRESULT __stdcall GetStatus(LPDWORD pdwStatus);
	virtual HRESULT __stdcall Initialize(LPDIRECTSOUND pDirectSound, LPCDSBUFFERDESC pcDSBufferDesc);
	virtual HRESULT __stdcall Lock(DWORD dwOffset, DWORD dwBytes, LPVOID *ppvAudioPtr1, LPDWORD pdwAudioBytes1, LPVOID *ppvAudioPtr2, LPDWORD pdwAudioBytes2, DWORD dwFlags);
	virtual HRESULT __stdcall Play(DWORD dwReserved1, DWORD dwPriority, DWORD dwFlags);
	virtual HRESULT __stdcall SetCurrentPosition(DWORD dwNewPosition);
	virtual HRESULT __stdcall SetFormat(LPCWAVEFORMATEX pcfxFormat);
	virtual HRESULT __stdcall SetVolume(LONG lVolume);
	virtual HRESULT __stdcall SetPan(LONG lPan);
	virtual HRESULT __stdcall SetFrequency(DWORD dwFrequency);
	virtual HRESULT __stdcall Stop();
	virtual HRESULT __stdcall Unlock(LPVOID pvAudioPtr1, DWORD dwAudioBytes1, LPVOID pvAudioPtr2, DWORD dwAudioBytes2);
	virtual HRESULT __stdcall Restore();

	// IDirectSoundBuffer8 methods
	virtual HRESULT __stdcall SetFX(DWORD dwEffectsCount, LPDSEFFECTDESC pDSFXDesc, LPDWORD pdwResultCodes);
	virtual HRESULT __stdcall AcquireResources(DWORD dwFlags, DWORD dwEffectsCount, LPDWORD pdwResultCodes);
	virtual HRESULT __stdcall GetObjectInPath(REFGUID rguidObject, DWORD dwIndex, REFGUID rguidInterface, LPVOID *ppObject);

	bool GetPrimaryBuffer()
	{
		return m_bIsPrimary;
	};
	void SetPrimaryBuffer(bool bIsPrimary)
	{
		m_bIsPrimary = bIsPrimary;
	};

	LPDIRECTSOUNDBUFFER8 m_lpDirectSoundBuffer8 = nullptr;

protected:
	DWORD m_dwOldWriteCursorPos = 0;
	BYTE m_nWriteCursorIdent = 0;

	bool m_bIsPrimary = false;
};
