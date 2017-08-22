#pragma once

#include <fstream>
#include <d3d9.h>
#include "IDirect3D9.h"
#include "IDirect3DDevice9.h"

// Very simple logging for the purpose of debugging only.
extern std::ofstream LOG;

typedef IDirect3D9 *(WINAPI *D3DC9)(UINT);
extern D3DC9 orig_Direct3DCreate9;

void logf(char * format, ...);
