#pragma once

class m_IDirectDrawPalette : public IDirectDrawPalette
{
public:
	m_IDirectDrawPalette(IDirectDrawPalette * aOriginal);
	~m_IDirectDrawPalette();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall GetCaps(LPDWORD a);
	HRESULT __stdcall GetEntries(DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d);
	HRESULT __stdcall Initialize(LPDIRECTDRAW a, DWORD b, LPPALETTEENTRY c);
	HRESULT __stdcall SetEntries(DWORD a, DWORD b, DWORD c, LPPALETTEENTRY d);
	IDirectDrawPalette * mOriginal;
};

