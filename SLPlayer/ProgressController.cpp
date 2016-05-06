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

	
	if (m_mode)
	{
		m_mode->turn_to_all_highlight();
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

	if (p.x >= m_left && p.x <= m_left + m_width)
	{
		// 如果光标在滑道上
		GetCursorPos(&m_mouse_pos); // 记下光标位置
	}
}


// 鼠标左键弹起
void ProgressController::left_button_up()
{
}
