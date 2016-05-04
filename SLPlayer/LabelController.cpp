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

}


// 光标移入
void LabelController::mouse_move_in()
{

}


// 光标移动消息
void LabelController::mouse_move_over()
{

}


// 鼠标左键按下
void LabelController::left_button_down()
{

}


// 鼠标左键弹起
void LabelController::left_button_up()
{

}
