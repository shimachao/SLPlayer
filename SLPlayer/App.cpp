#include "App.h"
#include "Window.h"


App::App()
{
}


App::~App()
{
}


// 运行程序
void App::Run()
{
	Window wnd;

	wnd.Initialize();
	wnd.MoveToScreenCenter();
	wnd.Show();

	// 消息循环
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

