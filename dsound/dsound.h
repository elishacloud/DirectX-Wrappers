#pragma once

#include <fstream>
#include <dsound.h>
#include "IDirectSound.h"
#include "IDirectSoundBuffer.h"
#include "IDirectSound3DBuffer.h"
#include "IDirectSound3DListener.h"
#include "IDirectSoundClassFactory.h"

typedef HRESULT(WINAPI *DirectSoundCreate8Proc)(LPCGUID, LPDIRECTSOUND8*, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectSoundCreateProc)(LPCGUID, LPDIRECTSOUND*, LPUNKNOWN);
typedef HRESULT(WINAPI *GetDeviceIDProc)(LPCGUID, LPGUID);
typedef HRESULT(WINAPI *DirectSoundEnumerateAProc)(LPDSENUMCALLBACKA, LPVOID);
typedef HRESULT(WINAPI *DirectSoundEnumerateWProc)(LPDSENUMCALLBACKW, LPVOID);
typedef HRESULT(WINAPI *DirectSoundCaptureCreateProc)(LPCGUID, LPDIRECTSOUNDCAPTURE*, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectSoundCaptureEnumerateAProc)(LPDSENUMCALLBACKA, LPVOID);
typedef HRESULT(WINAPI *DirectSoundCaptureEnumerateWProc)(LPDSENUMCALLBACKW, LPVOID);
typedef HRESULT(WINAPI *DirectSoundCaptureCreate8Proc)(LPCGUID, LPDIRECTSOUNDCAPTURE8*, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectSoundFullDuplexCreateProc)(LPCGUID, LPCGUID, LPCDSCBUFFERDESC, LPCDSBUFFERDESC, HWND, DWORD, LPDIRECTSOUNDFULLDUPLEX*, LPDIRECTSOUNDCAPTUREBUFFER8 *, LPDIRECTSOUNDBUFFER8 *, LPUNKNOWN);
typedef	HRESULT(WINAPI *DllGetClassObjectProc)(REFCLSID, REFIID, LPVOID *);
typedef HRESULT(WINAPI *DllCanUnloadNowProc)(void);

// Very simple logging for the purpose of debugging only.
class Log
{
public:
	Log() {}
	~Log()
	{
		LOG << std::endl;
	}

	template <typename T>
	Log& operator<<(const T& t)
	{
		LOG << t;
		return *this;
	}

private:
	static std::ofstream LOG;
};

void logf(char * format, ...);
