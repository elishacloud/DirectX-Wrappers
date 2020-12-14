#pragma once

#define INITGUID

#define DIRECTINPUT_VERSION 0x0700
#include <dinput.h>

class m_IDirectInputA;
class m_IDirectInputW;
class m_IDirectInput2A;
class m_IDirectInput2W;
class m_IDirectInput7A;
class m_IDirectInput7W;
class m_IDirectInputDeviceA;
class m_IDirectInputDeviceW;
class m_IDirectInputDevice2A;
class m_IDirectInputDevice2W;
class m_IDirectInputDevice7A;
class m_IDirectInputDevice7W;
class m_IDirectInputEffect;
class m_IDirectInputX;
class m_IDirectInputDeviceX;

#include "AddressLookupTable.h"
#include "..\Common\Logging.h"

#define DDWRAPPER_TYPEX 0x80

typedef HRESULT(WINAPI *DirectInputCreateAProc)(HINSTANCE, DWORD, LPDIRECTINPUTA*, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectInputCreateExProc)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);
typedef HRESULT(WINAPI *DirectInputCreateWProc)(HINSTANCE, DWORD, LPDIRECTINPUTW*, LPUNKNOWN);
typedef HRESULT(WINAPI *DllCanUnloadNowProc)();
typedef	HRESULT(WINAPI *DllGetClassObjectProc)(REFCLSID, REFIID, LPVOID *);
typedef HRESULT(WINAPI *DllRegisterServerProc)();
typedef HRESULT(WINAPI *DllUnregisterServerProc)();

HRESULT ProxyQueryInterface(LPVOID ProxyInterface, REFIID riid, LPVOID * ppvObj, REFIID WrapperID, LPVOID WrapperInterface);
void genericQueryInterface(REFIID CalledID, LPVOID * ppvObj);
extern AddressLookupTable<void> ProxyAddressLookupTable;

#include "Versions\IDirectInputA.h"
#include "Versions\IDirectInputW.h"
#include "Versions\IDirectInput2A.h"
#include "Versions\IDirectInput2W.h"
#include "Versions\IDirectInput7A.h"
#include "Versions\IDirectInput7W.h"
#include "Versions\IDirectInputDeviceA.h"
#include "Versions\IDirectInputDeviceW.h"
#include "Versions\IDirectInputDevice2A.h"
#include "Versions\IDirectInputDevice2W.h"
#include "Versions\IDirectInputDevice7A.h"
#include "Versions\IDirectInputDevice7W.h"
#include "IDirectInputEffect.h"
#include "IDirectInputX.h"
#include "IDirectInputDeviceX.h"
