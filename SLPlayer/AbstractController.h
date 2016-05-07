#pragma once
class AbstractController
{
public:
	AbstractController();
	~AbstractController();

	// ������Ч��Χ
	virtual void set_pos(int left, int top, int width, int height) = 0;
	// ���в���
	virtual bool hit_test(int x, int y) const = 0;
	// ����Ƴ�
	virtual void mouse_move_out() = 0;
	// �������
	virtual void mouse_move_in() = 0;
	// ����������
	virtual void left_button_down() = 0;
	// ����������
	virtual void left_button_up() = 0;
};

