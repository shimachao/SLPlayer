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
	if (m_model->get_state() == LabelModel::State::EDIT)
	{
		// ��ȡ����ʱ���λ��
		POINT p;
		GetCursorPos(&p);
		HWND hwnd = GetCapture();
		ScreenToClient(hwnd, &p);

		// ������Ӧ�ó��ֵ�λ��
		int width = m_view->get_char_width(); // �����ַ����

		int pos = (p.x - m_left + width / 2) / width; // ��������
		m_model->set_cursor_pos(pos);
		m_select = true;
	}
}


// ����������
void LabelController::left_button_up()
{
	// todo
}


// �յ�WM_CHAR��Ϣ
void LabelController::receive_char(wchar_t c)
{
	// ����ǿɼ��ַ�����ӵ�model
	if (iswprint(c))
	{
		m_model->add_char(c);
	}
	else if (c == VK_RETURN)
	{
		// ����յ��س����ͱ�ʾ�༭��ɣ�תΪ��ʾģʽ
		m_model->turn_to_display();
		m_select = false;
	}
}


// ������˫��
void LabelController::left_button_double_click()
{
	if (m_model && m_model->get_state() == LabelModel::State::DISPLAY)
	{
		m_model->turn_to_edit();
		left_button_down();
	}
}
