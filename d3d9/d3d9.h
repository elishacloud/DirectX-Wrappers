#pragma once

#include <fstream>
#include <d3d9.h>
#include "IDirect3D9.h"
#include "IDirect3DDevice9.h"

// Very simple logging for the purpose of debugging only.
extern std::ofstream LOG;

typedef IDirect3D9 *(WINAPI *Direct3DCreate9Proc)(UINT);
extern Direct3DCreate9Proc m_pDirect3DCreate9;

void logf(char * format, ...);
