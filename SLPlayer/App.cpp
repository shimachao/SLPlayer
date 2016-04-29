#include "App.h"
#include "Window.h"
#include "GdiPlusHost.h"


App::App()
{
}


App::~App()
{
}


// 运行程序
void App::Run()
{
	GdiPlusHost gHost; // 局部变量，用于管理GDI+资源的初始化和释放

	Window wnd;

	wnd.Initialize();
	wnd.SetBackgroundColor(30, 30, 30);
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

