#pragma once

class m_IDirectSound3DListener8 : public IDirectSound3DListener8
{
public:
	virtual HRESULT __stdcall QueryInterface(REFIID, LPVOID *);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	// IDirectSound3DListener methods
	virtual HRESULT __stdcall GetAllParameters(LPDS3DLISTENER pListener);
	virtual HRESULT __stdcall GetDistanceFactor(D3DVALUE* pflDistanceFactor);
	virtual HRESULT __stdcall GetDopplerFactor(D3DVALUE* pflDopplerFactor);
	virtual HRESULT __stdcall GetOrientation(D3DVECTOR* pvOrientFront, D3DVECTOR* pvOrientTop);
	virtual HRESULT __stdcall GetPosition(D3DVECTOR* pvPosition);
	virtual HRESULT __stdcall GetRolloffFactor(D3DVALUE* pflRolloffFactor);
	virtual HRESULT __stdcall GetVelocity(D3DVECTOR* pvVelocity);
	virtual HRESULT __stdcall SetAllParameters(LPCDS3DLISTENER pcListener, DWORD dwApply);
	virtual HRESULT __stdcall SetDistanceFactor(D3DVALUE flDistanceFactor, DWORD dwApply);
	virtual HRESULT __stdcall SetDopplerFactor(D3DVALUE flDopplerFactor, DWORD dwApply);
	virtual HRESULT __stdcall SetOrientation(D3DVALUE xFront, D3DVALUE yFront, D3DVALUE zFront, D3DVALUE xTop, D3DVALUE yTop, D3DVALUE zTop, DWORD dwApply);
	virtual HRESULT __stdcall SetPosition(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);
	virtual HRESULT __stdcall SetRolloffFactor(D3DVALUE flRolloffFactor, DWORD dwApply);
	virtual HRESULT __stdcall SetVelocity(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);
	virtual HRESULT __stdcall CommitDeferredSettings();

	LPDIRECTSOUND3DLISTENER8 m_lpDirectSound3DListener8 = nullptr;
};
