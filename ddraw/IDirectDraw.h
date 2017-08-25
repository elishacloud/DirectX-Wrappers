#pragma once

class m_IDirectDraw : public IDirectDraw
{
public:
	m_IDirectDraw(IDirectDraw * aOriginal);
	~m_IDirectDraw();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Compact();
	HRESULT __stdcall CreateClipper(DWORD a, LPDIRECTDRAWCLIPPER FAR * b, IUnknown FAR * c);
	HRESULT __stdcall CreatePalette(DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR * c, IUnknown FAR * d);
	HRESULT __stdcall CreateSurface(LPDDSURFACEDESC a, LPDIRECTDRAWSURFACE FAR * b, IUnknown FAR * c);
	HRESULT __stdcall DuplicateSurface(LPDIRECTDRAWSURFACE a, LPDIRECTDRAWSURFACE FAR * b);
	HRESULT __stdcall EnumDisplayModes(DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMMODESCALLBACK d);
	HRESULT __stdcall EnumSurfaces(DWORD a, LPDDSURFACEDESC b, LPVOID c, LPDDENUMSURFACESCALLBACK d);
	HRESULT __stdcall FlipToGDISurface();
	HRESULT __stdcall GetCaps(LPDDCAPS a, LPDDCAPS b);
	HRESULT __stdcall GetDisplayMode(LPDDSURFACEDESC a);
	HRESULT __stdcall GetFourCCCodes(LPDWORD a, LPDWORD b);
	HRESULT __stdcall GetGDISurface(LPDIRECTDRAWSURFACE FAR * a);
	HRESULT __stdcall GetMonitorFrequency(LPDWORD a);
	HRESULT __stdcall GetScanLine(LPDWORD a);
	HRESULT __stdcall GetVerticalBlankStatus(LPBOOL a);
	HRESULT __stdcall Initialize(GUID FAR * a);
	HRESULT __stdcall RestoreDisplayMode();
	HRESULT __stdcall SetCooperativeLevel(HWND a, DWORD b);
	HRESULT __stdcall SetDisplayMode(DWORD a, DWORD b, DWORD c);
	HRESULT __stdcall WaitForVerticalBlank(DWORD a, HANDLE b);
	IDirectDraw * mOriginal;
};

