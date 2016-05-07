#pragma once
#include "AbstractControl.h"
#include "ProgressView.h"
#include "ProgressController.h"
#include "ProgressModel.h"

class Progress :
	public AbstractControl
{
public:
	Progress(int left, int top, int width, int height, int start = 0, int end = 100);
	virtual ~Progress();

	// ���÷�Χ
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

	// ����ƶ���Ϣ
	void mouse_move_over();

private:
	ProgressView *m_view = nullptr;
	ProgressController *m_controller = nullptr;
	ProgressModel *m_model = nullptr;
};

