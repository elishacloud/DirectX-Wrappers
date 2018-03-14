#pragma once

struct ENUMSURFACE
{
	LPVOID lpContext;
	LPDDENUMSURFACESCALLBACK lpCallback;
};

class m_IDirectDrawEnumSurface
{
public:
	m_IDirectDrawEnumSurface() {}
	~m_IDirectDrawEnumSurface() {}

	static HRESULT CALLBACK EnumSurfaceCallback(LPDIRECTDRAWSURFACE, LPDDSURFACEDESC, LPVOID);
};

struct ENUMSURFACE2
{
	LPVOID lpContext;
	LPDDENUMSURFACESCALLBACK2 lpCallback;
};

class m_IDirectDrawEnumSurface2
{
public:
	m_IDirectDrawEnumSurface2() {}
	~m_IDirectDrawEnumSurface2() {}

	static HRESULT CALLBACK EnumSurface2Callback(LPDIRECTDRAWSURFACE4, LPDDSURFACEDESC2, LPVOID);
};

struct ENUMSURFACE7
{
	LPVOID lpContext;
	LPDDENUMSURFACESCALLBACK7 lpCallback;
};

class m_IDirectDrawEnumSurface7
{
public:
	m_IDirectDrawEnumSurface7() {}
	~m_IDirectDrawEnumSurface7() {}

	static HRESULT CALLBACK EnumSurface7Callback(LPDIRECTDRAWSURFACE7, LPDDSURFACEDESC2, LPVOID);
};
