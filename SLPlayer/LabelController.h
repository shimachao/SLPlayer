#pragma once
#include "LabelModel.h"
#include "LabelView.h"
#include "AbstractController.h"

class LabelController : public AbstractController
{
public:
	LabelController(int left, int top, int width, int height);
	~LabelController();

	// 设置model
	void set_model(LabelModel *model);
	// 设置范围
	void set_pos(int left, int top, int width, int height) override;
	// 击中测试
	bool hit_test(int x, int y) const override;
	// 光标移出
	void mouse_move_out() override;
	// 光标移入
	void mouse_move_in() override;
	// 光标移动消息
	void mouse_move_over();
	// 鼠标左键按下
	void left_button_down() override;
	// 鼠标左键弹起
	void left_button_up() override;
	// 鼠标左键双击
	void left_button_double_click();
	// 收到WM_CHAR消息
	void receive_char(wchar_t c);
	// 失去焦点
	void lost_focus();

private:
	int m_left;
	int m_top;
	int m_width;
	int m_height;
	bool m_select = false; // 是否正在选中文本

	LabelModel *m_model = nullptr; // model引用
	LabelView *m_view = nullptr; // view引用
};

