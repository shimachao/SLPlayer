#include "ButtonModel.h"



ButtonModel::ButtonModel()
{
	m_eventToAction[Event::CLICK] = nullptr;
}


ButtonModel::~ButtonModel()
{
}


// �������
void ButtonModel::mouse_move_in()
{
	m_state = State::HIGHLIGHT;
}


// ����Ƴ�
void ButtonModel::mouse_move_out()
{
	m_state = State::NORMAL;
}


// ����
void ButtonModel::click()
{
	if (m_eventToAction[Event::CLICK])
	{
		m_eventToAction[Event::CLICK]();
	}
}


// �����¼��Ͷ���
void ButtonModel::connect(Event e, std::function<void()> action)
{
	m_eventToAction[Event::CLICK] = action;
}
