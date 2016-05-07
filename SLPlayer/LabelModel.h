#pragma once
#include <string>

class LabelModel
{
public:
	LabelModel();
	~LabelModel();

	// �����ı�
	void set_text(std::wstring text);
	// ��ѯ�ַ�
	std::wstring get_text() const;
	// ����ַ����ڹ������λ�����
	void add_char(wchar_t c);

	// תΪ�༭״̬
	void turn_to_edit();
	// תΪ��ʾ״̬
	void turn_to_display();
	// ��ѯ״̬
	enum class State;
	State get_state() const;


	// ���ù��λ��
	void set_cursor_pos(std::wstring::size_type pos);
	// ��ѯ���λ��
	std::wstring::size_type get_cursor_pos() const;

	// ���ñ�ѡ���ַ��ķ�Χ
	void set_selected_range(std::wstring::size_type start, std::wstring::size_type end);
	// ��ѯ��ѡ���ı��ķ�Χ
	void get_selected_range(std::wstring::size_type &start, std::wstring::size_type &end) const;
	// ȡ��ѡ�в���
	void deselect();


	//-----------------����������Ϣ------------------
public:
	// label��״̬����ʾ���༭
	enum class State
	{
		DISPLAY, EDIT
	};

private:
	std::wstring m_text; // label���ı�
	State m_state = State::DISPLAY; // label��״̬��Ĭ�ϴ���display״̬
	std::wstring::size_type m_cursor_pos = 0; // ���λ��
	std::wstring::size_type m_selected_star_pos = 0; // ��ѡ���ı��Ŀ�ʼλ��
	std::wstring::size_type m_selected_end_pos = 0; // ��ѡ���ı��Ľ���λ��
};

