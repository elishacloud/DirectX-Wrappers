#pragma once

class myIDirectDraw7 : public IDirectDraw7
{
public:
	myIDirectDraw7(IDirectDraw7 * aOriginal);
	~myIDirectDraw7();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall Compact();
	HRESULT __stdcall CreateClipper(DWORD a, LPDIRECTDRAWCLIPPER FAR * b, IUnknown FAR * c);
	HRESULT __stdcall CreatePalette(DWORD a, LPPALETTEENTRY b, LPDIRECTDRAWPALETTE FAR * c, IUnknown FAR * d);
	HRESULT __stdcall CreateSurface(LPDDSURFACEDESC2 a, LPDIRECTDRAWSURFACE7 FAR * b, IUnknown FAR * c);
	HRESULT __stdcall DuplicateSurface(LPDIRECTDRAWSURFACE7 a, LPDIRECTDRAWSURFACE7 FAR * b);
	HRESULT __stdcall EnumDisplayModes(DWORD a, LPDDSURFACEDESC2 b, LPVOID c, LPDDENUMMODESCALLBACK2 d);
	HRESULT __stdcall EnumSurfaces(DWORD a, LPDDSURFACEDESC2 b, LPVOID c, LPDDENUMSURFACESCALLBACK7 d);
	HRESULT __stdcall FlipToGDISurface();
	HRESULT __stdcall GetCaps(LPDDCAPS a, LPDDCAPS b);
	HRESULT __stdcall GetDisplayMode(LPDDSURFACEDESC2 a);
	HRESULT __stdcall GetFourCCCodes(LPDWORD a, LPDWORD b);
	HRESULT __stdcall GetGDISurface(LPDIRECTDRAWSURFACE7 FAR * a);
	HRESULT __stdcall GetMonitorFrequency(LPDWORD a);
	HRESULT __stdcall GetScanLine(LPDWORD a);
	HRESULT __stdcall GetVerticalBlankStatus(LPBOOL a);
	HRESULT __stdcall Initialize(GUID FAR * a);
	HRESULT __stdcall RestoreDisplayMode();
	HRESULT __stdcall SetCooperativeLevel(HWND a, DWORD b);
	HRESULT __stdcall SetDisplayMode(DWORD a, DWORD b, DWORD c, DWORD d, DWORD e);
	HRESULT __stdcall WaitForVerticalBlank(DWORD a, HANDLE b);
	HRESULT __stdcall GetAvailableVidMem(LPDDSCAPS2 a, LPDWORD b, LPDWORD c);
	HRESULT __stdcall GetSurfaceFromDC(HDC a, LPDIRECTDRAWSURFACE7 * b);
	HRESULT __stdcall RestoreAllSurfaces();
	HRESULT __stdcall TestCooperativeLevel();
	HRESULT __stdcall GetDeviceIdentifier(LPDDDEVICEIDENTIFIER2 a, DWORD b);
	HRESULT __stdcall StartModeTest(LPSIZE a, DWORD b, DWORD c);
	HRESULT __stdcall EvaluateMode(DWORD a, DWORD * b);
	IDirectDraw7 * mOriginal;
};

