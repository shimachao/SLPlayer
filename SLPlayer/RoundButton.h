#pragma once
#include <string>
#include <map>
#include <functional>

class RoundButton
{
public:
	RoundButton();
	~RoundButton();

	// ����ƶ�������ť��
	void mouseMoveIn();
	// ����ƶ�������ť��
	void mouseMoveOut();

	// ��ť������
	void pressDown();

	// ��ť����
	void up();

	// �����¼�����Ӧ����

public:
	// ��ť�¼������¡����𡢵��
	enum Event
	{
		PRESS_DOWN, POP_UP, CLICK
	};
	// ��ť��״̬�����𣬵���+������룬����
	enum State
	{
		UP, UP_HIGHLIGHT, DOWN
	};

private:
	State m_state = UP; // ��ť��״̬
	std::map<Event, std::function<void()>> m_eventToAction; // �¼�����Ӧ����֮���ӳ��
};

