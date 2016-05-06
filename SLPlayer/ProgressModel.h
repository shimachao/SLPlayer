#pragma once
#include <map>
#include <functional>

class ProgressModel
{
public:
	ProgressModel(int start, int end, int pos = 0);
	~ProgressModel();

	// תΪ����
	void turn_to_normal();
	// תΪ����
	void turn_to_highlight();
	
	// ���÷�Χ
	void set_range(int start, int end);
	// ���ý���λ��
	void set_pos(int pos);
	// ��ѯ��Χ�ͽ���
	void get_range_pos(int &start, int &end, int &pos) const;

	// ��ѯ״̬
	enum class State;
	State get_state() const;

	// --------------------���Ͷ���----------------------------
public:
	// ���ȵ�״̬������������
	enum class State
	{
		NORMAL, HIGHLIGHT
	};

	// �������¼�������λ�ã��������
	enum class Event
	{
		SET_POS, COMPLETE
	};


private:
	int m_start = 0; // ���ȷ�Χ��Сֵ
	int m_end = 10; // ���ȷ�Χ���ֵ
	int m_pos = 0; // ���ȵĵ�ǰλ��
	std::map<Event, std::function<void()>> m_eventToAction; // �¼�����Ӧ����֮���ӳ��
	State m_state = State::NORMAL;
};

