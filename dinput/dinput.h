#pragma once

#define INITGUID

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include "..\Common\Wrapper.h"
#include "..\Common\Logging.h"

typedef HRESULT(WINAPI *DirectInputCreateAProc)(HINSTANCE, DWORD, LPDIRECTINPUTA*, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectInputCreateExProc)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectInputCreateWProc)(HINSTANCE, DWORD, LPDIRECTINPUTW*, LPUNKNOWN);
typedef HRESULT(WINAPI *DllCanUnloadNowProc)();
typedef	HRESULT(WINAPI *DllGetClassObjectProc)(REFCLSID, REFIID, LPVOID *);
typedef HRESULT(WINAPI *DllRegisterServerProc)();
typedef HRESULT(WINAPI *DllUnregisterServerProc)();

void genericQueryInterface(REFIID CalledID, LPVOID * ppvObj);
extern AddressLookupTable<void> ProxyAddressLookupTable;

#include "IDirectInputA.h"
#include "IDirectInputW.h"
#include "IDirectInputDeviceA.h"
#include "IDirectInputDeviceW.h"
