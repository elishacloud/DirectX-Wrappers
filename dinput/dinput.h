#pragma once

#define DIRECTINPUT_VERSION 0x0800
#include <fstream>
#include <dinput.h>
#include "DirectInputA.h"
#include "DirectInputW.h"
#include "DirectInputDeviceA.h"
#include "DirectInputDeviceW.h"

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

typedef HRESULT (WINAPI *DirectInputCreateAProc)(HINSTANCE, DWORD, LPDIRECTINPUTA*, LPUNKNOWN);
typedef HRESULT (WINAPI *DirectInputCreateExProc)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);
typedef HRESULT (WINAPI *DirectInputCreateWProc)(HINSTANCE, DWORD, LPDIRECTINPUTW*, LPUNKNOWN);
