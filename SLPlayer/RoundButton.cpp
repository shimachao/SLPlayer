#include "RoundButton.h"



RoundButton::RoundButton()
{
	m_eventToAction[PRESS_DOWN] = nullptr;
	m_eventToAction[POP_UP] = nullptr;
	m_eventToAction[CLICK] = nullptr;
}


RoundButton::~RoundButton()
{
}


// ����ƶ�������ť��
void RoundButton::mouseMoveIn()
{
	m_state = UP_HIGHLIGHT;
}


// ����ƶ�������ť��
void RoundButton::mouseMoveOut()
{
	m_state = UP;
}


// ��ť������
void RoundButton::pressDown()
{
	m_state = DOWN;
}


// ��ť����
void RoundButton::up()
{
	m_state = UP_HIGHLIGHT;
	
	if (m_eventToAction[CLICK] != nullptr)
	{
		(m_eventToAction[CLICK])();
	}
}
