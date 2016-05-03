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

	if (p.x >= m_slider_left && p.x <= m_slider_left+m_slider_width)
	{
		// �������ڻ�����
		if (m_mode)
		{
			m_mode->turn_to_all_highlight();
		}
	}
	else
	{
		// �������ڻ�����
		m_mode->turn_to_slide_highlight();
	}
}


// ����ƶ���Ϣ
void ProgressController::mouse_move_over()
{
	if (m_track_mouse_move)
	{
		// ��ѯ��ǰ���λ��
		POINT p;
		GetCursorPos(&p);
		// ���ݹ����x�����ϵ��ƶ������ƶ�����
		m_slider_left += p.x - m_mouse_pos.x;
		// ��֤�����ڻ�����Χ��
		if (m_slider_left <= m_left)
		{
			m_slider_left = m_left;
		}
		else if (m_slider_left + m_slider_width > m_left + m_width)
		{
			m_slider_left = m_left + m_width - m_slider_width;
		}

		m_mouse_pos = p;
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

	if (p.x >= m_slider_left && p.x <= m_slider_left + m_slider_width)
	{
		// �������ڻ����ϣ� ��ʼ������ƶ����ƶ�����
		m_track_mouse_move = true;
		GetCursorPos(&m_mouse_pos); // ���¹��λ��
	}
	else
	{
		// �������ڻ�����
		// todo �����ý���
	}
}


// ����������
void ProgressController::left_button_up()
{
	if (m_track_mouse_move)
	{
		m_track_mouse_move = false;
		// todo�����ý���

		// ��ѯ��ǰ���λ�ã��жϹ�����ڻ������ǻ�����
		POINT p;
		GetCursorPos(&p);
		HWND hwnd = GetCapture();
		ScreenToClient(hwnd, &p);

		if (p.x >= m_slider_left && p.x <= m_slider_left + m_slider_width
			&& p.y >= m_slider_top && p.y <= m_slider_top + m_slider_height )
		{
			// �������ڻ�����
			if (m_mode)
			{
				m_mode->turn_to_all_highlight();
			}
		}
		else if (p.x >= m_left && p.x <= m_left + m_width
			     && p.y >= m_top && p.y <= m_top + m_height)
		{
			// �������ڻ�����
			m_mode->turn_to_slide_highlight();
		}
		else
		{
			// ������ڽ�������
			m_mode->turn_to_normal();
		}
	}
}


// ��ѯ�Ƿ��������ƶ�
bool ProgressController::track_mouse_move()
{
	return m_track_mouse_move;
}
