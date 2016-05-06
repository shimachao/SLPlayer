#include "ProgressController.h"
#include <Windows.h>


ProgressController::ProgressController(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
}


ProgressController::~ProgressController()
{
}


// ����model
void ProgressController::set_model(ProgressModel *model)
{
	m_mode = model;
}


// ���в���
bool ProgressController::hit_test(int x, int y) const
{
	if (x >= m_left && x <= m_left + m_width
		&& y >= m_top && y <= m_top + m_height)
	{
		return true;
	}

	return false;
}


// ����Ƴ�
void ProgressController::mouse_move_out()
{
	if (m_mode)
	{
		m_mode->turn_to_normal();
	}
}


// �������
void ProgressController::mouse_move_in()
{
	// ��ѯ��ǰ���λ�ã��жϹ�����ڻ������ǻ�����
	POINT p;
	GetCursorPos(&p);
	HWND hwnd = GetCapture();
	ScreenToClient(hwnd, &p);

	
	if (m_mode)
	{
		m_mode->turn_to_all_highlight();
	}
}


// ����������
void ProgressController::left_button_down()
{
	// ��ѯ��ǰ���λ�ã��жϹ�����ڻ������ǻ�����
	POINT p;
	GetCursorPos(&p);
	HWND hwnd = GetCapture();
	ScreenToClient(hwnd, &p);

	if (p.x >= m_left && p.x <= m_left + m_width)
	{
		// �������ڻ�����
		GetCursorPos(&m_mouse_pos); // ���¹��λ��
	}
}


// ����������
void ProgressController::left_button_up()
{
}
