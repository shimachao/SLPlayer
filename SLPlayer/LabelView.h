#pragma once
#include <string>

// Label����ͼ�࣬������ʾlabel�ͽ����û��༭����

class LabelView
{
public:
	LabelView(unsigned int width, unsigned int height);
	~LabelView();

	// ���ñ�ǩ�ı�
	void setText(std::wstring text);
	// ����ַ�
	void addCharacter(wchar_t c);

public:
	// ��ǩ��״̬����̬״̬���༭״̬����̬�����ֻ��ʾ���༭״̬���Ա༭�ı�
	enum class State :unsigned int
	{
		STATIC, EDIT
	};

private:
	unsigned int m_width; // ��ǩ�ؼ����
	unsigned int m_height; // ��ǩ�ؼ��߶�
	std::wstring m_text; // �û�������ı�
	State m_state = State::STATIC; // Ĭ�ϴ��ھ�̬״̬
	std::wstring::size_type m_cursorPos = 0; // ����λ��
	bool m_selected = false; // �Ƿ������ֱ�ѡ��
	std::wstring::size_type m_selectedStarPos = 0; // ��ѡ�����ֵĿ�ʼλ��
	std::wstring::size_type m_selectedEndPos = 0; // ��ѡ�����ֵĽ���λ��
};

