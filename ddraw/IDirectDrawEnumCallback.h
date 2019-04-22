#pragma once

struct ENUMSURFACE
{
	LPVOID lpContext;
	LPDDENUMSURFACESCALLBACK lpCallback;
	DWORD DirectXVersion;
};

struct ENUMSURFACE2
{
	LPVOID lpContext;
	LPDDENUMSURFACESCALLBACK7 lpCallback;
	DWORD DirectXVersion;
};

class m_IDirectDrawEnumSurface
{
public:
	m_IDirectDrawEnumSurface() {}
	~m_IDirectDrawEnumSurface() {}

	static HRESULT CALLBACK ConvertCallback(LPDIRECTDRAWSURFACE lpDDSurface, LPDDSURFACEDESC lpDDSurfaceDesc, LPVOID lpContext);
	static HRESULT CALLBACK ConvertCallback2(LPDIRECTDRAWSURFACE7 lpDDSurface, LPDDSURFACEDESC2 lpDDSurfaceDesc2, LPVOID lpContext);
};
