#include "ddraw.h"

void genericQueryInterface(REFIID a, LPVOID * ptr)
{
#define QUERYINTERFACE(x) \
	if(a==IID_##x) \
		{ \
			*ptr = (void*)new my##x(*(x **)ptr); \
			logf("Wrapped: " #x "\n");\
			wrapstore(orig, *ptr);\
		}

	logf("Interface Query: {%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}\n",
		a.Data1, a.Data2, a.Data3,
		a.Data4[0], a.Data4[1], a.Data4[2], a.Data4[3],
		a.Data4[4], a.Data4[5], a.Data4[6], a.Data4[7]);

	void * orig = *ptr;

	QUERYINTERFACE(IDirect3D);
	QUERYINTERFACE(IDirect3D2);
	QUERYINTERFACE(IDirect3D3);
	QUERYINTERFACE(IDirect3D7);
	QUERYINTERFACE(IDirect3DDevice);
	QUERYINTERFACE(IDirect3DDevice2);
	QUERYINTERFACE(IDirect3DDevice3);
	QUERYINTERFACE(IDirect3DDevice7);
	QUERYINTERFACE(IDirect3DExecuteBuffer);
	QUERYINTERFACE(IDirect3DLight);
	QUERYINTERFACE(IDirect3DMaterial);
	QUERYINTERFACE(IDirect3DMaterial2);
	QUERYINTERFACE(IDirect3DMaterial3);
	QUERYINTERFACE(IDirect3DTexture);
	QUERYINTERFACE(IDirect3DTexture2);
	QUERYINTERFACE(IDirect3DVertexBuffer);
	QUERYINTERFACE(IDirect3DVertexBuffer7);
	QUERYINTERFACE(IDirect3DViewport);
	QUERYINTERFACE(IDirect3DViewport2);
	QUERYINTERFACE(IDirect3DViewport3);
	QUERYINTERFACE(IDirectDraw);
	QUERYINTERFACE(IDirectDraw2);
	QUERYINTERFACE(IDirectDraw4);
	QUERYINTERFACE(IDirectDraw7);
	QUERYINTERFACE(IDirectDrawClipper);
	QUERYINTERFACE(IDirectDrawColorControl);
	QUERYINTERFACE(IDirectDrawFactory);
	QUERYINTERFACE(IDirectDrawGammaControl);
	QUERYINTERFACE(IDirectDrawPalette);
	QUERYINTERFACE(IDirectDrawSurface);
	QUERYINTERFACE(IDirectDrawSurface2);
	QUERYINTERFACE(IDirectDrawSurface3);
	QUERYINTERFACE(IDirectDrawSurface4);
	QUERYINTERFACE(IDirectDrawSurface7);

	if (orig == *ptr)
	{
		logf("**** Unknown interface - not wrapped\n");
	}
}
