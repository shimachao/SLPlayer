#pragma once
#include <map>
#include <functional>

class ProgressBar
{
public:
	ProgressBar(unsigned int min, unsigned int max, unsigned int pos = 0, unsigned int step = 1);
	~ProgressBar();

	// ��ѯ��Χ
	void getRange(unsigned int &min, unsigned int &max) const;
	// ���÷�Χ
	bool setRange(unsigned int min, unsigned int max);

	// ��ѯ��ǰ����ֵ
	unsigned int getPos() const;
	// ���õ�ǰ����ֵ
	bool setPos(unsigned int pos);

	// ��ѯ����
	unsigned int getStep() const;
	// ���ò���
	bool setStep(unsigned int step);
	
	// ���������ӽ���
	void increaseByStep();
	// ������ֵ���ӽ���
	void increaseBy(unsigned int increment);

	// �����¼��Ͷ���
	enum class Event:unsigned int;
	void connect(Event event, std::function<void()> action);

public:
	// �¼����Ͷ��壺���������
	enum class Event:unsigned int
	{
		COMPLETED
	};
	
private:
	unsigned int m_min; // ��Χ����Сֵ
	unsigned int m_max; // ��Χ�����ֵ����Χ��[min, max]
	unsigned int m_step; // ����
	unsigned int m_pos; // ��ǰ����ֵ
	std::map<Event, std::function<void()>> m_eventToAction; // �¼�����Ӧ����֮���ӳ�䣬��ʱֻ��һ��COMPLETED�¼�
};

