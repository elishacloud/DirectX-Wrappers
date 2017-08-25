#pragma once

class m_IDirectSound8 : public IDirectSound8
{
public:
	virtual HRESULT __stdcall QueryInterface(REFIID, LPVOID *);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();
	virtual HRESULT __stdcall CreateSoundBuffer(LPCDSBUFFERDESC pcDSBufferDesc, LPDIRECTSOUNDBUFFER *ppDSBuffer, LPUNKNOWN pUnkOuter);
	virtual HRESULT __stdcall GetCaps(LPDSCAPS pDSCaps);
	virtual HRESULT __stdcall DuplicateSoundBuffer(LPDIRECTSOUNDBUFFER pDSBufferOriginal, LPDIRECTSOUNDBUFFER *ppDSBufferDuplicate);
	virtual HRESULT __stdcall SetCooperativeLevel(HWND hwnd, DWORD dwLevel);
	virtual HRESULT __stdcall Compact();
	virtual HRESULT __stdcall GetSpeakerConfig(LPDWORD pdwSpeakerConfig);
	virtual HRESULT __stdcall SetSpeakerConfig(DWORD dwSpeakerConfig);
	virtual HRESULT __stdcall Initialize(LPCGUID pcGuidDevice);
	virtual HRESULT __stdcall VerifyCertification(LPDWORD pdwCertified);

	LPDIRECTSOUND8 m_lpDirectSound8 = nullptr;

protected:
	const char* m_cszClassName;
};
