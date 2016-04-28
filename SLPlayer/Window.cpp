#include "Window.h"



Window::Window(int width, int height)
	:m_width(width), m_height(height)
{
}


Window::~Window()
{
}


// ���ڹ��̺���
LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_NCHITTEST:
		return HTCAPTION;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}


// ���ڳ�ʼ��
bool Window::Initialize()
{
	// ע�ᴰ����
	WNDCLASSEX wcex = { sizeof(WNDCLASSEX) };
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = Window::WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = HINST_THISCOMPONENT;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	wcex.lpszClassName = L"SLPlayerWnd";

	RegisterClassEx(&wcex);


	// ��������
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


// ��ʾ����
void Window::Show()
{
	// ��ʾ����
	if (m_hWnd != NULL)
	{
		ShowWindow(m_hWnd, SW_SHOWNORMAL);
		UpdateWindow(m_hWnd);
	}
}


// �������ƶ�����Ļ�м�
void Window::MoveToScreenCenter()
{
	int srcWidth = GetSystemMetrics(SM_CXSCREEN);
	int srcHeight = GetSystemMetrics(SM_CYSCREEN);

	int left = (srcWidth - m_width) / 2;
	int top = (srcHeight - m_height) / 2;

	MoveWindow(m_hWnd, left, top, m_width, m_height, false);
}

