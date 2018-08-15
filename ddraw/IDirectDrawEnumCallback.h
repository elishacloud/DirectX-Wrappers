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

	template <typename T, typename D>
	static HRESULT CALLBACK ConvertCallback(T lpDDSurface, D lpDDSurfaceDesc, LPVOID lpContext);
};
