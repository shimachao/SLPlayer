#include "Window.h"



Window::Window(int width, int height)
{
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
		
		break;

	case WM_SIZE:
		break;

	case WM_MOUSEMOVE:
		
		break;

		/*case WM_NCHITTEST:
		if (pWindow != nullptr)
		{
		int xPos = GET_X_LPARAM(lParam);
		int yPos = GET_Y_LPARAM(lParam);
		POINT p;
		p.x = xPos;
		p.y = yPos;
		::ScreenToClient(hWnd, &p);
		if (pWindow->ifMouseOnControl(p.x, p.y))
		{
		return HTCLIENT;
		}
		else
		{
		return HTCAPTION;
		}
		}
		return HTCAPTION;*/

	case WM_LBUTTONDOWN:
		break;

	case WM_LBUTTONUP:
		break;

	case WM_NCLBUTTONDOWN:
		break;

	case WM_NCLBUTTONUP:
		break;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DISPLAYCHANGE:
		InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;


	}

	return DefWindowProc(hWnd, message, wParam, lParam);;
}
