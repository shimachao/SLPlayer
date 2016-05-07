#include "Button.h"



Button::Button(int left, int top, int width, int height)
{
	m_view = new ButtonView(left, top, width, height);
	m_controller = new ButtonController(left, top, width, height);
	m_model = new ButtonModel();

	m_view->set_model(m_model);
	m_controller->set_model(m_model);
}


Button::~Button()
{
	if (m_view)
	{
		delete m_view;
		m_view = nullptr;
	}

	if (m_controller)
	{
		delete m_controller;
		m_controller = nullptr;
	}

	if (m_model)
	{
		delete m_model;
		m_model = nullptr;
	}
}


// ���û��Ʒ�Χ
void Button::set_pos(int left, int top, int width, int height)
{
	m_view->set_pos(left, top, width, height);
	m_controller->set_pos(left, top, width, height);
}


// ����
void Button::draw(Gdiplus::Graphics &g)
{
	m_view->draw(g);
}

// ���в���
bool Button::hit_test(int x, int y) const
{
	return m_controller->hit_test(x, y);
}


// ����Ƴ�
void Button::mouse_move_out()
{
	m_controller->mouse_move_out();
}


// �������
void Button::mouse_move_in()
{
	m_controller->mouse_move_in();
}


// ����������
void Button::left_button_down()
{
	m_controller->left_button_down();
}


// ����������
void Button::left_button_up()
{
	m_controller->left_button_up();
}
