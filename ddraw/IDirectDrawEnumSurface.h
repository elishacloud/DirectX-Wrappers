#pragma once

class m_IDirectDrawEnumSurface
{
private:
	static LPDDENUMSURFACESCALLBACK lpCallback;

public:
	m_IDirectDrawEnumSurface() {}
	~m_IDirectDrawEnumSurface() {}

	static void SetCallback(LPDDENUMSURFACESCALLBACK);
	static void ReleaseCallback();
	static HRESULT CALLBACK EnumSurfaceCallback(LPDIRECTDRAWSURFACE, LPDDSURFACEDESC, LPVOID);
};

class m_IDirectDrawEnumSurface2
{
private:
	static LPDDENUMSURFACESCALLBACK2 lpCallback;

public:
	m_IDirectDrawEnumSurface2() {}
	~m_IDirectDrawEnumSurface2() {}

	static void SetCallback(LPDDENUMSURFACESCALLBACK2);
	static void ReleaseCallback();
	static HRESULT CALLBACK EnumSurface2Callback(LPDIRECTDRAWSURFACE4, LPDDSURFACEDESC2, LPVOID);
};

class m_IDirectDrawEnumSurface7
{
private:
	static LPDDENUMSURFACESCALLBACK7 lpCallback;

public:
	m_IDirectDrawEnumSurface7() {}
	~m_IDirectDrawEnumSurface7() {}

	static void SetCallback(LPDDENUMSURFACESCALLBACK7);
	static void ReleaseCallback();
	static HRESULT CALLBACK EnumSurface7Callback(LPDIRECTDRAWSURFACE7, LPDDSURFACEDESC2, LPVOID);
};
