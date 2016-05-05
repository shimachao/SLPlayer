#pragma once
#include "LabelModel.h"
#include "LabelView.h"

class LabelController
{
public:
	LabelController(int left, int top, int width, int height);
	~LabelController();

	// 设置model
	void set_model(LabelModel *model);

	// 击中测试
	bool hit_test(int x, int y) const;
	// 光标移出
	void mouse_move_out();
	// 光标移入
	void mouse_move_in();
	// 光标移动消息
	void mouse_move_over();
	// 鼠标左键按下
	void left_button_down();
	// 鼠标左键弹起
	void left_button_up();
	// 收到WM_CHAR消息
	void receive_char(wchar_t c);

private:
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	LabelModel *m_model = nullptr; // model引用
	LabelView *m_view = nullptr; // view引用
};

