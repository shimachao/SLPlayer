#include "GdiPlusHost.h"
#include <GdiPlus.h>
#pragma comment(lib, "Gidplus.lib")

using Gdiplus::GdiplusStartupInput;
using Gdiplus::GdiplusShutdown;

GdiPlusHost::GdiPlusHost()
{
	GdiplusStartupInput input;
	GdiplusStartup(&m_gidplusToken, &input, NULL);
}


GdiPlusHost::~GdiPlusHost()
{
	GdiplusShutdown(m_gidplusToken);
}

