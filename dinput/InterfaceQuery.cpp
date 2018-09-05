/**
* Copyright (C) 2018 Elisha Riedlinger
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

#include "dinput.h"

void genericQueryInterface(REFIID riid, LPVOID * ppvObj)
{
#define QUERYINTERFACE(x) \
	if (riid == IID_ ## x) \
		{ \
			*ppvObj = ProxyAddressLookupTable.FindAddress<m_ ## x>(*ppvObj); \
		}

	QUERYINTERFACE(IDirectInput2A);
	QUERYINTERFACE(IDirectInput2W);
	QUERYINTERFACE(IDirectInput7A);
	QUERYINTERFACE(IDirectInput7W);
	QUERYINTERFACE(IDirectInputA);
	QUERYINTERFACE(IDirectInputDevice2A);
	QUERYINTERFACE(IDirectInputDevice2W);
	QUERYINTERFACE(IDirectInputDevice7A);
	QUERYINTERFACE(IDirectInputDevice7W);
	QUERYINTERFACE(IDirectInputDeviceA);
	QUERYINTERFACE(IDirectInputDeviceW);
	QUERYINTERFACE(IDirectInputEffect);
	QUERYINTERFACE(IDirectInputW);
}
