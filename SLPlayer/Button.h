#pragma once
#include "AbstractControl.h"
#include "ButtonView.h"
#include "ButtonController.h"
#include "ButtonModel.h"

class Button :
	public AbstractControl
{
public:
	Button(int left, int top, int width, int height);
	virtual ~Button();

	// ���û��Ʒ�Χ
	void set_pos(int left, int top, int width, int height) override;
	// ����
	void draw(Gdiplus::Graphics &g) override;

	// ���в���
	bool hit_test(int x, int y) const override;
	// ����Ƴ�
	void mouse_move_out() override;
	// �������
	void mouse_move_in() override;
	// ����������
	void left_button_down() override;
	// ����������
	void left_button_up() override;

private:
	ButtonView *m_view = nullptr;
	ButtonController *m_controller = nullptr;
	ButtonModel *m_model = nullptr;
};

