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


// ���÷�Χ
void LabelController::set_pos(int left, int top, int width, int height)
{
	m_left = left;
	m_top = top;
	m_width = width;
	m_height = height;
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
	//todo
}


// �������
void LabelController::mouse_move_in()
{
	//todo
}


// ����ƶ���Ϣ
void LabelController::mouse_move_over()
{
	//todo
}


// ����������
void LabelController::left_button_down()
{
	//todo
}


// ����������
void LabelController::left_button_up()
{
	// todo
}


// �յ�WM_CHAR��Ϣ
void LabelController::receive_char(wchar_t c)
{
	// todo
}


// ������˫��
void LabelController::left_button_double_click()
{
	if (m_model && m_model->get_state() == LabelModel::State::DISPLAY)
	{
		m_model->turn_to_edit();
	}
}
