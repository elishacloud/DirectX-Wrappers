/**
* Copyright (C) 2017 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "d3d9.h"

std::ofstream Log::LOG("d3d9.log");

Direct3DShaderValidatorCreate9Proc m_pDirect3DShaderValidatorCreate9;
PSGPErrorProc m_pPSGPError;
PSGPSampleTextureProc m_pPSGPSampleTexture;
D3DPERF_BeginEventProc m_pD3DPERF_BeginEvent;
D3DPERF_EndEventProc m_pD3DPERF_EndEvent;
D3DPERF_GetStatusProc m_pD3DPERF_GetStatus;
D3DPERF_QueryRepeatFrameProc m_pD3DPERF_QueryRepeatFrame;
D3DPERF_SetMarkerProc m_pD3DPERF_SetMarker;
D3DPERF_SetOptionsProc m_pD3DPERF_SetOptions;
D3DPERF_SetRegionProc m_pD3DPERF_SetRegion;
DebugSetLevelProc m_pDebugSetLevel;
DebugSetMuteProc m_pDebugSetMute;
FARPROC m_pDirect3D9EnableMaximizedWindowedModeShim;
Direct3DCreate9Proc m_pDirect3DCreate9;
Direct3DCreate9ExProc m_pDirect3DCreate9Ex;

bool WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	static HMODULE d3d9dll = nullptr;

	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		// Load dll
		char path[MAX_PATH];
		GetSystemDirectoryA(path, MAX_PATH);
		strcat_s(path, "\\d3d9.dll");
		Log() << "Loading " << path;
		d3d9dll = LoadLibraryA(path);

		// Get function addresses
		m_pDirect3DShaderValidatorCreate9 = (Direct3DShaderValidatorCreate9Proc)GetProcAddress(d3d9dll, "Direct3DShaderValidatorCreate9");
		m_pPSGPError = (PSGPErrorProc)GetProcAddress(d3d9dll, "PSGPError");
		m_pPSGPSampleTexture = (PSGPSampleTextureProc)GetProcAddress(d3d9dll, "PSGPSampleTexture");
		m_pD3DPERF_BeginEvent = (D3DPERF_BeginEventProc)GetProcAddress(d3d9dll, "D3DPERF_BeginEvent");
		m_pD3DPERF_EndEvent = (D3DPERF_EndEventProc)GetProcAddress(d3d9dll, "D3DPERF_EndEvent");
		m_pD3DPERF_GetStatus = (D3DPERF_GetStatusProc)GetProcAddress(d3d9dll, "D3DPERF_GetStatus");
		m_pD3DPERF_QueryRepeatFrame = (D3DPERF_QueryRepeatFrameProc)GetProcAddress(d3d9dll, "D3DPERF_QueryRepeatFrame");
		m_pD3DPERF_SetMarker = (D3DPERF_SetMarkerProc)GetProcAddress(d3d9dll, "D3DPERF_SetMarker");
		m_pD3DPERF_SetOptions = (D3DPERF_SetOptionsProc)GetProcAddress(d3d9dll, "D3DPERF_SetOptions");
		m_pD3DPERF_SetRegion = (D3DPERF_SetRegionProc)GetProcAddress(d3d9dll, "D3DPERF_SetRegion");
		m_pDebugSetLevel = (DebugSetLevelProc)GetProcAddress(d3d9dll, "DebugSetLevel");
		m_pDebugSetMute = (DebugSetMuteProc)GetProcAddress(d3d9dll, "DebugSetMute");
		m_pDirect3D9EnableMaximizedWindowedModeShim = GetProcAddress(d3d9dll, "Direct3D9EnableMaximizedWindowedModeShim");
		m_pDirect3DCreate9 = (Direct3DCreate9Proc)GetProcAddress(d3d9dll, "Direct3DCreate9");
		m_pDirect3DCreate9Ex = (Direct3DCreate9ExProc)GetProcAddress(d3d9dll, "Direct3DCreate9Ex");
		break;

	case DLL_PROCESS_DETACH:
		FreeLibrary(d3d9dll);
		break;
	}

	return true;
}

void logf(char * fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	auto size = vsnprintf(nullptr, 0, fmt, ap);
	std::string output(size + 1, '\0');
	vsprintf_s(&output[0], size + 1, fmt, ap);
	Log() << output.c_str();
	va_end(ap);
}

HRESULT WINAPI Direct3DShaderValidatorCreate9()
{
	HRESULT hr = m_pDirect3DShaderValidatorCreate9();
	Log() << __FUNCTION__ << " " << hr;
	return hr;
}

HRESULT WINAPI PSGPError()
{
	HRESULT hr = m_pPSGPError();
	Log() << __FUNCTION__ << " " << hr;
	return hr;
}

HRESULT WINAPI PSGPSampleTexture()
{
	HRESULT hr = m_pPSGPSampleTexture();
	Log() << __FUNCTION__ << " " << hr;
	return hr;
}

int WINAPI D3DPERF_BeginEvent(D3DCOLOR col, LPCWSTR wszName)
{
	int rt = m_pD3DPERF_BeginEvent(col, wszName);
	Log() << __FUNCTION__ << " " << rt;
	return rt;
}

int WINAPI D3DPERF_EndEvent()
{
	int rt = m_pD3DPERF_EndEvent();
	Log() << __FUNCTION__ << " " << rt;
	return rt;
}

DWORD WINAPI D3DPERF_GetStatus()
{
	DWORD rt = m_pD3DPERF_GetStatus();
	Log() << __FUNCTION__ << " " << rt;
	return rt;
}

BOOL WINAPI D3DPERF_QueryRepeatFrame()
{
	BOOL rt = m_pD3DPERF_QueryRepeatFrame();
	Log() << __FUNCTION__ << " " << rt;
	return rt;
}

void WINAPI D3DPERF_SetMarker(D3DCOLOR col, LPCWSTR wszName)
{
	Log() << __FUNCTION__;
	m_pD3DPERF_SetMarker(col, wszName);
}

void WINAPI D3DPERF_SetOptions(DWORD dwOptions)
{
	Log() << __FUNCTION__;
	m_pD3DPERF_SetOptions(dwOptions);
}

void WINAPI D3DPERF_SetRegion(D3DCOLOR col, LPCWSTR wszName)
{
	Log() << __FUNCTION__;
	m_pD3DPERF_SetRegion(col, wszName);
}

HRESULT WINAPI DebugSetLevel(DWORD dw1)
{
	HRESULT hr = m_pDebugSetLevel(dw1);
	Log() << __FUNCTION__ << " " << hr;
	return hr;
}

void WINAPI DebugSetMute()
{
	Log() << __FUNCTION__;
	m_pDebugSetMute();
}

void __declspec(naked) Direct3D9EnableMaximizedWindowedModeShim()
{
	logf(__FUNCTION__ "\n");
	_asm jmp m_pDirect3D9EnableMaximizedWindowedModeShim;
}

IDirect3D9 *WINAPI Direct3DCreate9(UINT SDKVersion)
{
	Log() << __FUNCTION__ << " " << SDKVersion;
	return new m_IDirect3D9(m_pDirect3DCreate9(SDKVersion));
}

HRESULT WINAPI Direct3DCreate9Ex(UINT SDKVersion, IDirect3D9Ex **ppD3D)
{
	HRESULT hr = m_pDirect3DCreate9Ex(SDKVersion, ppD3D);
	Log() << __FUNCTION__ << " " << SDKVersion << " " << hr;
	if (SUCCEEDED(hr))
	{
		//TODO: Add wrappers
	}
	return hr;
}
