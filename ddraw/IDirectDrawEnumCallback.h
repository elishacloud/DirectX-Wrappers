#pragma once

struct ENUMSURFACE
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

	static HRESULT CALLBACK ConvertCallback(LPDIRECTDRAWSURFACE7 lpDDSurface, LPDDSURFACEDESC2 lpDDSurfaceDesc2, LPVOID lpContext);
};
