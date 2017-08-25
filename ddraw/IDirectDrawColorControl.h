#pragma once

class m_IDirectDrawColorControl : public IDirectDrawColorControl
{
public:
	m_IDirectDrawColorControl(IDirectDrawColorControl * aOriginal);
	~m_IDirectDrawColorControl();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall GetColorControls(LPDDCOLORCONTROL a);
	HRESULT __stdcall SetColorControls(LPDDCOLORCONTROL a);
	IDirectDrawColorControl * mOriginal;
};

