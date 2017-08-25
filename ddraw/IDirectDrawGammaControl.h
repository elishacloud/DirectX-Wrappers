#pragma once

class m_IDirectDrawGammaControl : public IDirectDrawGammaControl
{
public:
	m_IDirectDrawGammaControl(IDirectDrawGammaControl * aOriginal);
	~m_IDirectDrawGammaControl();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall GetGammaRamp(DWORD a, LPDDGAMMARAMP b);
	HRESULT __stdcall SetGammaRamp(DWORD a, LPDDGAMMARAMP b);
	IDirectDrawGammaControl * mOriginal;
};

