#pragma once
#include <string>

class LabelModel
{
public:
	LabelModel();
	~LabelModel();

	// 设置文本
	void set_text(std::wstring text);
	// 查询字符
	std::wstring get_text() const;
	// 添加字符，在光标所在位置添加
	void add_char(wchar_t c);

	// 转为编辑状态
	void turn_to_edit();
	// 转为显示状态
	void turn_to_display();
	// 查询状态
	enum class State;
	State get_state() const;


	// 设置光标位置
	void set_cursor_pos(std::wstring::size_type pos);
	// 查询光标位置
	std::wstring::size_type get_cursor_pos() const;

	// 设置被选中字符的范围
	void set_selected_range(std::wstring::size_type start, std::wstring::size_type end);
	// 查询被选中文本的范围
	void get_selected_range(std::wstring::size_type &start, std::wstring::size_type &end) const;
	// 取消选中操作
	void deselect();


	//-----------------定义类型信息------------------
public:
	// label的状态：显示、编辑
	enum class State
	{
		DISPLAY, EDIT
	};

private:
	std::wstring m_text; // label的文本
	State m_state = State::DISPLAY; // label的状态，默认处于display状态
	std::wstring::size_type m_cursor_pos = 0; // 光标位置
	std::wstring::size_type m_selected_star_pos = 0; // 被选中文本的开始位置
	std::wstring::size_type m_selected_end_pos = 0; // 被选中文本的结束位置
};

