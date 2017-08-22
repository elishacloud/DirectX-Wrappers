#pragma once

class myIDirectDrawGammaControl : public IDirectDrawGammaControl
{
public:
	myIDirectDrawGammaControl(IDirectDrawGammaControl * aOriginal);
	~myIDirectDrawGammaControl();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall GetGammaRamp(DWORD a, LPDDGAMMARAMP b);
	HRESULT __stdcall SetGammaRamp(DWORD a, LPDDGAMMARAMP b);
	IDirectDrawGammaControl * mOriginal;
};

