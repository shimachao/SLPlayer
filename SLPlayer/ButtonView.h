#pragma once
#include <comdef.h>
#include <Gdiplus.h>
#include "ButtonModel.h"

class ButtonView
{
public:
	ButtonView(int left, int top, int width, int height);
	~ButtonView();

	// ����model
	void set_model(ButtonModel *model);

	// ����
	void draw(Gdiplus::Graphics &g);
	// ����ͼƬ
	void set_img(Gdiplus::Image *img);

private:
	// ����״̬����
	void normal_draw(Gdiplus::Graphics &g);
	// ��������
	void highlight_draw(Gdiplus::Graphics &g);
	// ����״̬ʱ����
	void press_down_draw(Gdiplus::Graphics &g);

private:
	int m_left; // ���Ʒ�Χ���
	int m_top; // ����
	int m_width; // ��
	int m_height; // ��
	Gdiplus::Image *m_img; // ����ͼƬ

	ButtonModel *m_model = nullptr; // model����
};

