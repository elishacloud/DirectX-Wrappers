# DirectX Wrappers

### Introduction

This is code to wrap most of the main DirectX DLLs.  It allows you to intercept virtually all calls to DirectX and Direct3D interface functions so that you can log API calls or you can add your own code into the game, such as enabling Anti-Aliasing or drawing your own objects to create overlays in the game. Once you have compiled this you can simply copy the DLL into the same folder as the game's executable, and it should load it as if it were the real DLL file. It still forwards all calls to the real one in System32, just allows stuff to happen in between. 

Currently this can wrap the following DLLs:
- ddraw.dll
- d3d9.dll

However I plan to add these DLLs soon:
- d3dim.dll
- d3dim700.dll
- d3d8.dll
- d3d10.dll
- d3d11.dll
- d3d12.dll
- dinput.dll
- dsound.dll
- dsound8.dll

Note: It currently only works with 32bit games, but I may add 64bit support later.

### License

Copyright (C) 2017 Elisha Riedlinger

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
- [Direct3D9 Wrapper DLL](https://gist.github.com/shaunlebron/3854bf4eec5bec297907)

### Development

You will need the [DirectX 8.1 SDK](http://www.tdxlibrary.org/Downloads/Microsoft/dx7sdk.zip) as well as the standalone [DirectX SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812) to compile this.