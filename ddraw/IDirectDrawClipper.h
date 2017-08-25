#pragma once

class m_IDirectDrawClipper : public IDirectDrawClipper
{
public:
	m_IDirectDrawClipper(IDirectDrawClipper * aOriginal);
	~m_IDirectDrawClipper();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall GetClipList(LPRECT a, LPRGNDATA b, LPDWORD c);
	HRESULT __stdcall GetHWnd(HWND FAR * a);
	HRESULT __stdcall Initialize(LPDIRECTDRAW a, DWORD b);
	HRESULT __stdcall IsClipListChanged(BOOL FAR * a);
	HRESULT __stdcall SetClipList(LPRGNDATA a, DWORD b);
	HRESULT __stdcall SetHWnd(DWORD a, HWND b);
	IDirectDrawClipper * mOriginal;
};

