#pragma once
#include "ProgressModel.h"
#include <Windows.h>
#include "AbstractController.h"

class ProgressController : public AbstractController
{
public:
	ProgressController(int left, int top, int width, int height);
	~ProgressController();

	// ����model
	void set_model(ProgressModel *model);
	// ���÷�Χ
	void set_pos(int left, int top, int width, int height) override;
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
	// ����������
	int m_left;
	int m_top;
	int m_width;
	int m_height;

	ProgressModel *m_mode = nullptr; // model������
};

