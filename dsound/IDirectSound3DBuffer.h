#pragma once

class m_IDirectSound3DBuffer8 : public IDirectSound3DBuffer8
{
public:
	virtual HRESULT __stdcall QueryInterface(REFIID, LPVOID *);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	// IDirectSound3DBuffer methods
	virtual HRESULT __stdcall GetAllParameters(LPDS3DBUFFER pDs3dBuffer);
	virtual HRESULT __stdcall GetConeAngles(LPDWORD pdwInsideConeAngle, LPDWORD pdwOutsideConeAngle);
	virtual HRESULT __stdcall GetConeOrientation(D3DVECTOR* pvOrientation);
	virtual HRESULT __stdcall GetConeOutsideVolume(LPLONG plConeOutsideVolume);
	virtual HRESULT __stdcall GetMaxDistance(D3DVALUE* pflMaxDistance);
	virtual HRESULT __stdcall GetMinDistance(D3DVALUE* pflMinDistance);
	virtual HRESULT __stdcall GetMode(LPDWORD pdwMode);
	virtual HRESULT __stdcall GetPosition(D3DVECTOR* pvPosition);
	virtual HRESULT __stdcall GetVelocity(D3DVECTOR* pvVelocity);
	virtual HRESULT __stdcall SetAllParameters(LPCDS3DBUFFER pcDs3dBuffer, DWORD dwApply);
	virtual HRESULT __stdcall SetConeAngles(DWORD dwInsideConeAngle, DWORD dwOutsideConeAngle, DWORD dwApply);
	virtual HRESULT __stdcall SetConeOrientation(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);
	virtual HRESULT __stdcall SetConeOutsideVolume(LONG lConeOutsideVolume, DWORD dwApply);
	virtual HRESULT __stdcall SetMaxDistance(D3DVALUE flMaxDistance, DWORD dwApply);
	virtual HRESULT __stdcall SetMinDistance(D3DVALUE flMinDistance, DWORD dwApply);
	virtual HRESULT __stdcall SetMode(DWORD dwMode, DWORD dwApply);
	virtual HRESULT __stdcall SetPosition(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);
	virtual HRESULT __stdcall SetVelocity(D3DVALUE x, D3DVALUE y, D3DVALUE z, DWORD dwApply);

	LPDIRECTSOUND3DBUFFER8 m_lpDirectSound3DBuffer8 = nullptr;
};
