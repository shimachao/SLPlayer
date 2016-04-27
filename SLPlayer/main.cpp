#include "Window.h"

int WINAPI WinMain(__in HINSTANCE hInstance, __in_opt HINSTANCE hPrevInstance, __in LPSTR lpCmdLine, __in int nShowCmd)
{

	Window wnd(600, 400);
	wnd.Initialize();
	wnd.MoveToScreenCenter();
	wnd.Show();
	// ÏûÏ¢Ñ­»·
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
