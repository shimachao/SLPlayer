#include "Progress.h"



Progress::Progress(int left, int top, int width, int height, int start, int end)
{
	m_view = new ProgressView(left, top, width, height);
	m_controller = new ProgressController(left, top, width, height);
	m_model = new ProgressModel(start, end);

	m_view->set_model(m_model);
	m_controller->set_model(m_model);
}


Progress::~Progress()
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


// ����
void Progress::draw(Gdiplus::Graphics &g)
{
	m_view->draw(g);
}


// ���в���
bool Progress::hit_test(int x, int y) const
{
	return m_controller->hit_test(x, y);
}


// ����Ƴ�
void Progress::mouse_move_out()
{
	m_controller->mouse_move_out();
}


// �������
void Progress::mouse_move_in()
{
	m_controller->mouse_move_in();
}


// ����������
void Progress::Progress::left_button_down()
{
	m_controller->left_button_down();
}


// ����������
void Progress::left_button_up()
{
	m_controller->left_button_up();
}


// ����ƶ���Ϣ
void Progress::mouse_move_over()
{
	
}
