#pragma once
#include <Windows.h>

#ifndef HINST_THISCOMPONENT
EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
#endif

// ������
class Window
{
public:
	Window(int width = 600, int height = 400);
	~Window();


private:
	// ���ڹ��̺���
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	int	m_width;
	int height;
	HWND m_hWnd; // ���ھ��
};

