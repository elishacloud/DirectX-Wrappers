#pragma once

class myIDirectDrawClipper : public IDirectDrawClipper
{
public:
	myIDirectDrawClipper(IDirectDrawClipper * aOriginal);
	~myIDirectDrawClipper();
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

