#pragma once
#include <map>
#include <functional>

class ButtonModel
{
public:
	ButtonModel();
	~ButtonModel();

	// ״̬תΪ����
	void turn_to_highlight();
	// ״̬תΪ����
	void turn_to_normal();
	// ״̬תΪ����
	void turn_to_down();
	// ��������
	void click();

	// ��ѯ״̬
	enum class State;
	State get_state() const;

	// �����¼��Ͷ���
	enum class Event;
	void connect(Event e, std::function<void()> action);

	// --------------------���Ͷ���----------------------------
public:
	// ��ť�¼�������
	enum class Event
	{
		CLICK
	};

	// ��ť��״̬������������������
	enum class State
	{
		NORMAL, HIGHLIGHT, DOWN
	};

private:
	std::map<Event, std::function<void()>> m_eventToAction; // �¼�����Ӧ����֮���ӳ��
	State m_state = State::NORMAL;
};

