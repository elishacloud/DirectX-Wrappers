#pragma once

class m_IDirectDrawFactory : public IDirectDrawFactory
{
public:
	m_IDirectDrawFactory(IDirectDrawFactory * aOriginal);
	~m_IDirectDrawFactory();
	HRESULT __stdcall QueryInterface(REFIID riid, LPVOID FAR * ppvObj);
	ULONG __stdcall AddRef();
	ULONG __stdcall Release();
	HRESULT __stdcall CreateDirectDraw(GUID * pGUID, HWND hWnd, DWORD dwCoopLevelFlags, DWORD dwReserved, IUnknown * pUnkOuter, IDirectDraw * * ppDirectDraw);
	HRESULT __stdcall DirectDrawEnumerate(LPDDENUMCALLBACK lpCallback, LPVOID lpContext);
	IDirectDrawFactory * mOriginal;
};

