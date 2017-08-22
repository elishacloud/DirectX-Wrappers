#pragma once

class myIDirectDrawPalette : public IDirectDrawPalette
{
public:
	myIDirectDrawPalette(IDirectDrawPalette * aOriginal);
	~myIDirectDrawPalette();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall GetCaps(LPDWORD a);
	HRESULT __stdcall GetEntries(DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d);
	HRESULT __stdcall Initialize(LPDIRECTDRAW a, DWORD b, LPPALETTEENTRY c);
	HRESULT __stdcall SetEntries(DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d);
	IDirectDrawPalette * mOriginal;
};

