#include "App.h"
#include "Window.h"
#include "GdiPlusHost.h"


App::App()
{
}


App::~App()
{
}


// ���г���
void App::Run()
{
	GdiPlusHost gHost; // �ֲ����������ڹ���GDI+��Դ�ĳ�ʼ�����ͷ�

	Window wnd;

	wnd.Initialize();
	wnd.SetBackgroundColor(30, 30, 30);
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

