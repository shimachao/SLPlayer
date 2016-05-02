#pragma once
#include <map>
#include <functional>

class ButtonModel
{
public:
	ButtonModel();
	~ButtonModel();

	// ����
	void click();
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

private:
	std::map<Event, std::function<void()>> m_eventToAction; // �¼�����Ӧ����֮���ӳ��
};

