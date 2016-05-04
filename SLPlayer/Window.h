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

	// ���ڳ�ʼ��
	bool Initialize();
	// �������ƶ�����Ļ�м�
	void MoveToScreenCenter();
	// ��ʾ����
	void Show();
	// ���ô��ڱ�����ɫ
	void SetBackgroundColor(BYTE r, BYTE g, BYTE b);
	// ��ӦWM_PAINT��Ϣ
	void onPaint(HDC dc);
	// ��Ӧ����ƶ���Ϣ
	void onMouseMove();
	// ��Ӧ������������Ϣ
	void onLeftButtonDown();
	// ��Ӧ������������Ϣ
	void onLeftButtonUp();
	// ��Ӧ������˫����Ϣ
	void onLeftButtonDoubleClick();
	// ��ӦNCHITTEST��Ϣ
	LRESULT onNcHitTest();

private:
	// ���ڹ��̺���
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	int	m_width;
	int m_height;
	HWND m_hWnd; // ���ھ��
	BYTE m_r; // ������ɫ��r����
	BYTE m_g; // ������ɫ��g����
	BYTE m_b; // ������ɫ��b����
};

