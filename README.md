# DirectX Wrappers

### Introduction

Wraps the main DirectX and Direct3D DLLs.  It allows you to intercept calls to DirectX and Direct3D interface functions so that you can log API calls or you can add your own code into the game, such as enabling Anti-Aliasing or creating overlays in the game. Once you have compiled this you can simply copy the DLL into the same folder as the game's executable and it should load it as if it were the real DLL file. It still forwards all calls to the real one in System32, it just allows stuff to happen in between. 

Wraps the following versions of DirectX:
- DirectX 1-7, DirectDraw and Direct3D (ddraw.dll)
- DirectX 8, Direct3D (d3d8.dll)
- DirectX 9, Direct3D (d3d9.dll)
- DirectSound and DirectSound8 (dsound.dll)
- DirectInput (dinput.dll)
- DirectInput8 (dinput8.dll)

I plan to add these DLLs later:
- d2d1.dll
- d3d10.dll
- d3d10core.dll
- d3d11.dll
- d3d12.dll

Note: It currently only works with 32bit games, but I might add 64bit support at some point.

### License

Copyright (C) 2020 Elisha Riedlinger

This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
authors be held liable for any damages arising from the use of this software.
Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
applications, and to alter it and redistribute it freely, subject to the following restrictions:

   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
      original  software. If you use this  software  in a product, an  acknowledgment in the product
      documentation would be appreciated but is not required.
   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
      being the original software.
   3. This notice may not be removed or altered from any source distribution.

Code in this project is taken from:
- [Jari Komppa's dxwrapper](https://github.com/jarikomppa/dxwrapper)
- [d3d8to9](https://github.com/crosire/d3d8to9)
- [Direct3D9 Wrapper DLL](https://gist.github.com/shaunlebron/3854bf4eec5bec297907)
- [DirectSoundControl](https://github.com/nRaecheR/DirectSoundControl)
- [XWA hooks](https://github.com/JeremyAnsel/xwa_hooks/tree/master/DInputLogger)

### Development

Development was done in C++ using Microsoft Visual Studio Community 2017.
