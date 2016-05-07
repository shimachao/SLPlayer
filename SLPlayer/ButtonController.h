#pragma once
#include "ButtonModel.h"
#include "AbstractController.h"

class ButtonController:public AbstractController
{
public:
	ButtonController(int left, int top, int width, int height);
	~ButtonController();
	// ����model
	void set_model(ButtonModel *model);

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
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	ButtonModel *m_model = nullptr;
};

