#pragma once
#include "AbstractControl.h"
#include "LabelView.h"
#include "LabelController.h"
#include "LabelModel.h"

class Label :
	public AbstractControl
{
public:
	Label(int left, int top, int width, int height);
	virtual ~Label();

	// 绘制
	void draw(Gdiplus::Graphics &g) override;

	// 击中测试
	bool hit_test(int x, int y) const override;
	// 光标移出
	void mouse_move_out() override;
	// 光标移入
	void mouse_move_in() override;
	// 鼠标左键按下
	void left_button_down() override;
	// 鼠标左键弹起
	void left_button_up() override;

	// 光标移动消息
	void mouse_move_over();
	// 鼠标左键双击
	void left_button_double_click();
	// 收到WM_CHAR消息
	void receive_char(wchar_t c);


private:
	LabelView *m_view = nullptr;
	LabelController *m_controller = nullptr;
	LabelModel *m_model = nullptr;
};

