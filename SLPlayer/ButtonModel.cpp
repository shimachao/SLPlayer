#include "ButtonModel.h"



ButtonModel::ButtonModel()
{
	m_eventToAction[Event::CLICK] = nullptr;
}


ButtonModel::~ButtonModel()
{
}


// 光标移入
void ButtonModel::mouse_move_in()
{
	m_state = State::HIGHLIGHT;
}


// 光标移出
void ButtonModel::mouse_move_out()
{
	m_state = State::NORMAL;
}


// 单击
void ButtonModel::click()
{
	if (m_eventToAction[Event::CLICK])
	{
		m_eventToAction[Event::CLICK]();
	}
}


// 连接事件和动作
void ButtonModel::connect(Event e, std::function<void()> action)
{
	m_eventToAction[Event::CLICK] = action;
}
