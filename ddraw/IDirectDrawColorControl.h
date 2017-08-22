#pragma once

class myIDirectDrawColorControl : public IDirectDrawColorControl
{
public:
	myIDirectDrawColorControl(IDirectDrawColorControl * aOriginal);
	~myIDirectDrawColorControl();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall GetColorControls(LPDDCOLORCONTROL a);
	HRESULT __stdcall SetColorControls(LPDDCOLORCONTROL a);
	IDirectDrawColorControl * mOriginal;
};

