#pragma once
#include <string>

// Label的视图类，负责显示label和接受用户编辑输入

class LabelView
{
public:
	LabelView(unsigned int width, unsigned int height);
	~LabelView();

	// 设置标签文本
	void setText(std::wstring text);
	// 添加字符
	void addCharacter(wchar_t c);

public:
	// 标签的状态：静态状态，编辑状态。静态情况下只显示，编辑状态可以编辑文本
	enum class State :unsigned int
	{
		STATIC, EDIT
	};

private:
	unsigned int m_width; // 标签控件宽度
	unsigned int m_height; // 标签控件高度
	std::wstring m_text; // 用户输入的文本
	State m_state = State::STATIC; // 默认处于静态状态
	std::wstring::size_type m_cursorPos = 0; // 光标的位置
	bool m_selected = false; // 是否有文字被选中
	std::wstring::size_type m_selectedStarPos = 0; // 被选中文字的开始位置
	std::wstring::size_type m_selectedEndPos = 0; // 被选中文字的结束位置
};

