#pragma once

class myIDirectDrawSurface4 : public IDirectDrawSurface4
{
public:
	myIDirectDrawSurface4(IDirectDrawSurface4 * aOriginal);
	~myIDirectDrawSurface4();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall AddAttachedSurface(LPDIRECTDRAWSURFACE4 a);
	HRESULT __stdcall AddOverlayDirtyRect(LPRECT a);
	HRESULT __stdcall Blt(LPRECT a, LPDIRECTDRAWSURFACE4 b, LPRECT c, DWORD d, LPDDBLTFX e);
	HRESULT __stdcall BltBatch(LPDDBLTBATCH a, DWORD b, DWORD c);
	HRESULT __stdcall BltFast(DWORD a, DWORD b, LPDIRECTDRAWSURFACE4 c, LPRECT d, DWORD e);
	HRESULT __stdcall DeleteAttachedSurface(DWORD a, LPDIRECTDRAWSURFACE4 b);
	HRESULT __stdcall EnumAttachedSurfaces(LPVOID a, LPDDENUMSURFACESCALLBACK2 b);
	HRESULT __stdcall EnumOverlayZOrders(DWORD a, LPVOID b, LPDDENUMSURFACESCALLBACK2 c);
	HRESULT __stdcall Flip(LPDIRECTDRAWSURFACE4 a, DWORD b);
	HRESULT __stdcall GetAttachedSurface(LPDDSCAPS2 a, LPDIRECTDRAWSURFACE4 FAR * b);
	HRESULT __stdcall GetBltStatus(DWORD a);
	HRESULT __stdcall GetCaps(LPDDSCAPS2 a);
	HRESULT __stdcall GetClipper(LPDIRECTDRAWCLIPPER FAR * a);
	HRESULT __stdcall GetColorKey(DWORD a, LPDDCOLORKEY b);
	HRESULT __stdcall GetDC(HDC FAR * a);
	HRESULT __stdcall GetFlipStatus(DWORD a);
	HRESULT __stdcall GetOverlayPosition(LPLONG a, LPLONG b);
	HRESULT __stdcall GetPalette(LPDIRECTDRAWPALETTE FAR * a);
	HRESULT __stdcall GetPixelFormat(LPDDPIXELFORMAT a);
	HRESULT __stdcall GetSurfaceDesc(LPDDSURFACEDESC2 a);
	HRESULT __stdcall Initialize(LPDIRECTDRAW a, LPDDSURFACEDESC2 b);
	HRESULT __stdcall IsLost();
	HRESULT __stdcall Lock(LPRECT a, LPDDSURFACEDESC2 b, DWORD c, HANDLE d);
	HRESULT __stdcall ReleaseDC(HDC a);
	HRESULT __stdcall Restore();
	HRESULT __stdcall SetClipper(LPDIRECTDRAWCLIPPER a);
	HRESULT __stdcall SetColorKey(DWORD a, LPDDCOLORKEY b);
	HRESULT __stdcall SetOverlayPosition(LONG a, LONG b);
	HRESULT __stdcall SetPalette(LPDIRECTDRAWPALETTE a);
	HRESULT __stdcall Unlock(LPRECT a);
	HRESULT __stdcall UpdateOverlay(LPRECT a, LPDIRECTDRAWSURFACE4 b, LPRECT c, DWORD d, LPDDOVERLAYFX e);
	HRESULT __stdcall UpdateOverlayDisplay(DWORD a);
	HRESULT __stdcall UpdateOverlayZOrder(DWORD a, LPDIRECTDRAWSURFACE4 b);
	HRESULT __stdcall GetDDInterface(LPVOID FAR * a);
	HRESULT __stdcall PageLock(DWORD a);
	HRESULT __stdcall PageUnlock(DWORD a);
	HRESULT __stdcall SetSurfaceDesc(LPDDSURFACEDESC2 a, DWORD b);
	HRESULT __stdcall SetPrivateData(REFGUID a, LPVOID b, DWORD c, DWORD d);
	HRESULT __stdcall GetPrivateData(REFGUID a, LPVOID b, LPDWORD c);
	HRESULT __stdcall FreePrivateData(REFGUID a);
	HRESULT __stdcall GetUniquenessValue(LPDWORD a);
	HRESULT __stdcall ChangeUniquenessValue();
	IDirectDrawSurface4 * mOriginal;
};

