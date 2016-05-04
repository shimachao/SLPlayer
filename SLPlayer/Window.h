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
	// 设置窗口背景颜色
	void SetBackgroundColor(BYTE r, BYTE g, BYTE b);
	// 响应WM_PAINT消息
	void onPaint(HDC dc);
	// 响应鼠标移动消息
	void onMouseMove();
	// 响应鼠标左键单击消息
	void onLeftButtonDown();
	// 响应鼠标左键弹起消息
	void onLeftButtonUp();
	// 响应鼠标左键双击消息
	void onLeftButtonDoubleClick();
	// 响应NCHITTEST消息
	LRESULT onNcHitTest();

private:
	// 窗口过程函数
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	int	m_width;
	int m_height;
	HWND m_hWnd; // 窗口句柄
	BYTE m_r; // 背景颜色的r分量
	BYTE m_g; // 背景颜色的g分量
	BYTE m_b; // 背景颜色的b分量
};

