#include "LabelController.h"



LabelController::LabelController(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
}


LabelController::~LabelController()
{
}


// 设置model
void LabelController::set_model(LabelModel *model)
{
	m_model = model;
}


// 设置范围
void LabelController::set_pos(int left, int top, int width, int height)
{
	m_left = left;
	m_top = top;
	m_width = width;
	m_height = height;
}


// 击中测试
bool LabelController::hit_test(int x, int y) const
{
	if (x >= m_left && x <= m_left + m_width
		&& y >= m_top && y <= m_top + m_height)
	{
		return true;
	}

	return false;
}


// 光标移出
void LabelController::mouse_move_out()
{
	//todo
}


// 光标移入
void LabelController::mouse_move_in()
{
	//todo
}


// 光标移动消息
void LabelController::mouse_move_over()
{
	//todo
}


// 鼠标左键按下
void LabelController::left_button_down()
{
	if (m_model->get_state() == LabelModel::State::EDIT)
	{
		// 获取单击时光标位置
		POINT p;
		GetCursorPos(&p);
		HWND hwnd = GetCapture();
		ScreenToClient(hwnd, &p);

		// 计算光标应该出现的位置
		int width = m_view->get_char_width(); // 单个字符宽度

		int pos = (p.x - m_left + width / 2) / width; // 四舍五入
		m_model->set_cursor_pos(pos);
		m_select = true;
	}
}


// 鼠标左键弹起
void LabelController::left_button_up()
{
	// todo
}


// 收到WM_CHAR消息
void LabelController::receive_char(wchar_t c)
{
	// 如果是可见字符就添加到model
	if (iswprint(c))
	{
		m_model->add_char(c);
	}
	else if (c == VK_RETURN)
	{
		// 如果收到回车键就表示编辑完成，转为显示模式
		m_model->turn_to_display();
		m_select = false;
	}
}


// 鼠标左键双击
void LabelController::left_button_double_click()
{
	if (m_model && m_model->get_state() == LabelModel::State::DISPLAY)
	{
		m_model->turn_to_edit();
		left_button_down();
	}
}
