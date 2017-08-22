#pragma once

#include <fstream>
#include <d3d8.h>
#include "IDirect3D8.h"
#include "IDirect3DDevice8.h"

// Very simple logging for the purpose of debugging only.
extern std::ofstream LOG;

typedef IDirect3D8 *(WINAPI *D3DC8)(UINT);
extern D3DC8 orig_Direct3DCreate8;

void logf(char * format, ...);
