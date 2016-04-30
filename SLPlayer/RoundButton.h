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
	enum class Event :unsigned int;
	void connect(Event event, std::function<void()> action);

	// --------------------���Ͷ���----------------------------
public:
	// ��ť�¼������¡����𡢵��
	enum class Event :unsigned int
	{
		PRESS_DOWN, POP_UP, CLICK
	};

	// ��ť��״̬�����𣬵���+������룬����
	enum class State :unsigned int
	{
		UP, UP_HIGHLIGHT, DOWN
	};

private:
	State m_state = State::UP; // ��ť��״̬
	std::map<Event, std::function<void()>> m_eventToAction; // �¼�����Ӧ����֮���ӳ��
};

