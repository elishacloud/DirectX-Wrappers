#pragma once

#include <fstream>
#include <d3d8.h>
#include "IDirect3D8.h"
#include "IDirect3DDevice8.h"

// Very simple logging for the purpose of debugging only.
extern std::ofstream LOG;

typedef IDirect3D8 *(WINAPI *Direct3DCreate8Proc)(UINT);
extern Direct3DCreate8Proc m_pDirect3DCreate8;

void logf(char * format, ...);
