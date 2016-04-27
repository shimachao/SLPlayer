#pragma once
#include <Windows.h>

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif

// 窗口类
class Window
{
public:
	Window(int width = 600, int height = 400);
	~Window();

	// 窗口初始化
	bool Initialize();
	// 将窗口移动到屏幕中间
	void MoveToScreenCenter();
	// 显示窗口
	void Show();


private:
	// 窗口过程函数
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	int	m_width;
	int m_height;
	HWND m_hWnd; // 窗口句柄
};

