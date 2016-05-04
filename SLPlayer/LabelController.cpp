#include "LabelController.h"



LabelController::LabelController(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
}


LabelController::~LabelController()
{
}


// ����model
void LabelController::set_model(LabelModel *model)
{
	m_model = model;
}


// ���в���
bool LabelController::hit_test(int x, int y) const
{
	if (x >= m_left && x <= m_left + m_width
		&& y >= m_top && y <= m_top + m_height)
	{
		return true;
	}

	return false;
}


// ����Ƴ�
void LabelController::mouse_move_out()
{

}


// �������
void LabelController::mouse_move_in()
{

}


// ����ƶ���Ϣ
void LabelController::mouse_move_over()
{

}


// ����������
void LabelController::left_button_down()
{

}


// ����������
void LabelController::left_button_up()
{

}
