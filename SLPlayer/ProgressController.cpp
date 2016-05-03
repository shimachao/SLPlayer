#include "ProgressController.h"
#include <Windows.h>


ProgressController::ProgressController(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
}


ProgressController::~ProgressController()
{
}


// 设置model
void ProgressController::set_model(ProgressModel *model)
{
	m_mode = model;
}


// 击中测试
bool ProgressController::hit_test(int x, int y) const
{
	if (x >= m_left && x <= m_left + m_width
		&& y >= m_top && y <= m_top + m_height)
	{
		return true;
	}

	return false;
}


// 光标移出
void ProgressController::mouse_move_out()
{
	if (m_mode)
	{
		m_mode->turn_to_normal();
	}
}


// 光标移入
void ProgressController::mouse_move_in()
{
	// 查询当前光标位置，判断光标是在滑道还是滑块上
	POINT p;
	GetCursorPos(&p);
	HWND hwnd = GetCapture();
	ScreenToClient(hwnd, &p);

	if (p.x >= m_slider_left && p.x <= m_slider_left+m_slider_width)
	{
		// 如果光标在滑块上
		if (m_mode)
		{
			m_mode->turn_to_all_highlight();
		}
	}
	else
	{
		// 如果光标在滑道上
		m_mode->turn_to_slide_highlight();
	}
}


// 光标移动消息
void ProgressController::mouse_move_over()
{
	if (m_track_mouse_move)
	{
		// 查询当前光标位置
		POINT p;
		GetCursorPos(&p);
		// 根据光标在x方向上的移动距离移动滑块
		m_slider_left += p.x - m_mouse_pos.x;
		// 保证滑块在滑道范围内
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


// 鼠标左键按下
void ProgressController::left_button_down()
{
	// 查询当前光标位置，判断光标是在滑道还是滑块上
	POINT p;
	GetCursorPos(&p);
	HWND hwnd = GetCapture();
	ScreenToClient(hwnd, &p);

	if (p.x >= m_slider_left && p.x <= m_slider_left + m_slider_width)
	{
		// 如果光标在滑块上， 开始随光标的移动来移动滑块
		m_track_mouse_move = true;
		GetCursorPos(&m_mouse_pos); // 记下光标位置
	}
	else
	{
		// 如果光标在滑道上
		// todo ：设置进度
	}
}


// 鼠标左键弹起
void ProgressController::left_button_up()
{
	if (m_track_mouse_move)
	{
		m_track_mouse_move = false;
		// todo：设置进度

		// 查询当前光标位置，判断光标是在滑道还是滑块上
		POINT p;
		GetCursorPos(&p);
		HWND hwnd = GetCapture();
		ScreenToClient(hwnd, &p);

		if (p.x >= m_slider_left && p.x <= m_slider_left + m_slider_width
			&& p.y >= m_slider_top && p.y <= m_slider_top + m_slider_height )
		{
			// 如果光标在滑块上
			if (m_mode)
			{
				m_mode->turn_to_all_highlight();
			}
		}
		else if (p.x >= m_left && p.x <= m_left + m_width
			     && p.y >= m_top && p.y <= m_top + m_height)
		{
			// 如果光标在滑道上
			m_mode->turn_to_slide_highlight();
		}
		else
		{
			// 如果不在进度条上
			m_mode->turn_to_normal();
		}
	}
}


// 查询是否跟踪鼠标移动
bool ProgressController::track_mouse_move()
{
	return m_track_mouse_move;
}
