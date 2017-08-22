#pragma once

class myIDirectDrawFactory : public IDirectDrawFactory
{
public:
	myIDirectDrawFactory(IDirectDrawFactory * aOriginal);
	~myIDirectDrawFactory();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall CreateDirectDraw(GUID * pGUID, HWND hWnd, DWORD dwCoopLevelFlags, DWORD dwReserved, IUnknown * pUnkOuter, IDirectDraw * * ppDirectDraw);
	HRESULT __stdcall DirectDrawEnumerate(LPDDENUMCALLBACK lpCallback, LPVOID lpContext);
	IDirectDrawFactory * mOriginal;
};

