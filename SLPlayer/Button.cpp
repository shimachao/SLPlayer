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


// 设置绘制范围
void Button::set_pos(int left, int top, int width, int height)
{
	m_view->set_pos(left, top, width, height);
	m_controller->set_pos(left, top, width, height);
}


// 绘制
void Button::draw(Gdiplus::Graphics &g)
{
	m_view->draw(g);
}

// 击中测试
bool Button::hit_test(int x, int y) const
{
	return m_controller->hit_test(x, y);
}


// 光标移出
void Button::mouse_move_out()
{
	m_controller->mouse_move_out();
}


// 光标移入
void Button::mouse_move_in()
{
	m_controller->mouse_move_in();
}


// 鼠标左键按下
void Button::left_button_down()
{
	m_controller->left_button_down();
}


// 鼠标左键弹起
void Button::left_button_up()
{
	m_controller->left_button_up();
}
