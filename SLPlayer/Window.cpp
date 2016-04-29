#include "Window.h"
#include <GdiPlus.h>


Window::Window(int width, int height)
	:m_width(width), m_height(height)
{
	m_r = 0;
	m_g = 0;
	m_b = 0;
}


Window::~Window()
{
}


// 窗口过程函数
LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static Window *pWindow = nullptr;
	PAINTSTRUCT ps;
	HDC dc;

	switch (message)
	{
	case WM_CREATE:
	{
		LPCREATESTRUCT pcs = (LPCREATESTRUCT)lParam;
		pWindow = (Window *)pcs->lpCreateParams;
		break;
	}

	case WM_PAINT:
		if (pWindow != nullptr)
		{
			dc = BeginPaint(hWnd, &ps);

			pWindow->onPaint(dc);

			EndPaint(hWnd, &ps);
		}
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_NCHITTEST:
		return HTCAPTION;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}


// 窗口初始化
bool Window::Initialize()
{
	// 注册窗口类
	WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = Window::WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = sizeof(LONG_PTR);
	wcex.hInstance = HINST_THISCOMPONENT;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	wcex.lpszClassName = L"SLPlayerWnd";

	RegisterClassEx(&wcex);


	// 创建窗口
	m_hWnd = CreateWindow(
		L"SLPlayerWnd",
		L"BIAOTI",
		WS_POPUP,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		m_width,
		m_height,
		NULL,
		NULL,
		HINST_THISCOMPONENT,
		this
		);

	return m_hWnd != NULL;
}


// 显示窗口
void Window::Show()
{
	// 显示窗口
	if (m_hWnd != NULL)
	{
		ShowWindow(m_hWnd, SW_SHOWNORMAL);
		UpdateWindow(m_hWnd);
	}
}


// 将窗口移动到屏幕中间
void Window::MoveToScreenCenter()
{
	int srcWidth = GetSystemMetrics(SM_CXSCREEN);
	int srcHeight = GetSystemMetrics(SM_CYSCREEN);

	int left = (srcWidth - m_width) / 2;
	int top = (srcHeight - m_height) / 2;

	MoveWindow(m_hWnd, left, top, m_width, m_height, false);
}


// 设置窗口背景颜色
void Window::SetBackgroundColor(BYTE r, BYTE g, BYTE b)
{
	m_r = r;
	m_g = g;
	m_b = b;
	//InvalidateRect(m_hWnd, NULL, true);
}


// 响应WM_PAINT消息
void Window::onPaint(HDC dc)
{
	// 创建内存兼容DC，准备双缓冲
	HDC hMemDC = CreateCompatibleDC(dc);
	RECT rc;
	GetClientRect(m_hWnd, &rc);
	HBITMAP hMemBitMap = CreateCompatibleBitmap(dc, rc.right, rc.bottom);
	SelectObject(hMemDC, hMemBitMap);
	// 根据内存DC创建GDI+绘制对象
	Gdiplus::Graphics graphics(hMemDC);
	// 设置反走样
	graphics.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);

	// 清理背景
	Gdiplus::SolidBrush brush(Gdiplus::Color(m_r, m_g, m_b));
	graphics.FillRectangle(&brush, -1, -1, rc.right+1, rc.bottom+1);

	// 绘制控件

	// 复制到目标DC
	BitBlt(dc, 0, 0, rc.right, rc.bottom, hMemDC, 0, 0, SRCCOPY);

	DeleteDC(hMemDC);
}
