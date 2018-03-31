#pragma once

#define INITGUID

#define DIRECTINPUT_VERSION 0x0700
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

#include "IDirectInput2A.h"
#include "IDirectInput2W.h"
#include "IDirectInput7A.h"
#include "IDirectInput7W.h"
#include "IDirectInputA.h"
#include "IDirectInputDevice2A.h"
#include "IDirectInputDevice2W.h"
#include "IDirectInputDevice7A.h"
#include "IDirectInputDevice7W.h"
#include "IDirectInputDeviceA.h"
#include "IDirectInputDeviceW.h"
#include "IDirectInputEffect.h"
#include "IDirectInputEnumEffect.h"
#include "IDirectInputW.h"
