#include "App.h"
#include <Windows.h>

int WINAPI WinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd)
{
	App app;
	app.Run();
	
	return 0;
}
