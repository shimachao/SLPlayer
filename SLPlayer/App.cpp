#include "App.h"
#include "Window.h"


App::App()
{
}


App::~App()
{
}


// ���г���
void App::Run()
{
	Window wnd;

	wnd.Initialize();
	wnd.MoveToScreenCenter();
	wnd.Show();

	// ��Ϣѭ��
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

