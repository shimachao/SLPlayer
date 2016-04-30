#include "RoundButton.h"



RoundButton::RoundButton()
{
	m_eventToAction[Event::PRESS_DOWN] = nullptr;
	m_eventToAction[Event::POP_UP] = nullptr;
	m_eventToAction[Event::CLICK] = nullptr;
}


RoundButton::~RoundButton()
{
}


// ����ƶ�������ť��
void RoundButton::mouseMoveIn()
{
	m_state = State::UP_HIGHLIGHT;
}


// ����ƶ�������ť��
void RoundButton::mouseMoveOut()
{
	m_state = State::UP;
}


// ��ť������
void RoundButton::pressDown()
{
	m_state = State::DOWN;
}


// ��ť����
void RoundButton::up()
{
	m_state = State::UP_HIGHLIGHT;
	
	if (m_eventToAction[Event::CLICK] != nullptr)
	{
		(m_eventToAction[Event::CLICK])();
	}
}


// �����¼�����Ӧ����
void RoundButton::connect(Event event, std::function<void()> action)
{
	m_eventToAction[event] = action;
}
