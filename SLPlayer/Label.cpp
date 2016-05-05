#include "Label.h"



Label::Label(int left, int top, int width, int height)
{
	m_view = new LabelView(left, top, width, height);
	m_controller = new LabelController(left, top, width, height);
	m_model = new LabelModel();

	m_view->set_model(m_model);
	m_controller->set_model(m_model);
}


Label::~Label()
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


// 绘制
void Label::draw(Gdiplus::Graphics &g)
{
	m_view->draw(g);
}


// 击中测试
bool Label::Label::hit_test(int x, int y) const
{
	return m_controller->hit_test(x, y);
}


// 光标移出
void Label::mouse_move_out()
{
	m_controller->mouse_move_out();
}


// 光标移入
void Label::mouse_move_in()
{
	m_controller->mouse_move_in();
}


// 鼠标左键按下
void Label::left_button_down()
{
	m_controller->left_button_down();
}


// 鼠标左键弹起
void Label::left_button_up()
{
	m_controller->left_button_up();
}


// 光标移动消息
void Label::mouse_move_over()
{
	m_controller->mouse_move_over();
}


// 鼠标左键双击
void Label::left_button_double_click()
{
	m_controller->left_button_double_click();
}


// 收到WM_CHAR消息
void Label::receive_char(wchar_t c)
{
	m_controller->receive_char(c);
}
