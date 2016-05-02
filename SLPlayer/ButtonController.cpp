#include "ButtonController.h"



ButtonController::ButtonController(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height)
{
}


ButtonController::~ButtonController()
{
}


// ����model
void ButtonController::set_model(ButtonModel *model)
{
	m_model = model;
}


// ���в���
bool ButtonController::hit_test(int x, int y) const
{
	if (x >= m_left && x <= m_left + m_width
		&& y >= m_top && y <= m_top + m_height)
	{
		return true;
	}

	return false;
}


// ����Ƴ�
void ButtonController::mouse_move_out()
{
	if (m_model)
	{
		m_model->turn_to_normal();
	}
}


// �������
void ButtonController::mouse_move_in()
{
	if (m_model)
	{
		m_model->turn_to_highlight();
	}
}


// ����������
void ButtonController::left_button_down()
{
	if (m_model)
	{
		m_model->turn_to_down();
	}
}


// ����������
void ButtonController::left_button_up()
{
	if (m_model)
	{
		m_model->turn_to_highlight();
		m_model->click();
	}
}
