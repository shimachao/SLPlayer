#pragma once
#include <comdef.h>
#include <Gdiplus.h>
#include "ButtonModel.h"
#include "AbstractView.h"

class ButtonView : public AbstractView
{
public:
	ButtonView(int left, int top, int width, int height);
	~ButtonView();

	// ����model
	void set_model(ButtonModel *model);

	// ���÷�Χ
	void set_pos(int left, int top, int width, int height) override;
	// ����
	void draw(Gdiplus::Graphics &g) override;

	// ��������״̬ʱ�ı���ͼƬ
	void set_normal_img(Gdiplus::Image *img);
	// ���ø���ʱ�ı���ͼƬ
	void set_highlight_img(Gdiplus::Image *img);
	// ���ð���ʱ�ı���ͼƬ
	void set_down_img(Gdiplus::Image *img);

private:
	// ����״̬����
	void normal_draw(Gdiplus::Graphics &g);
	// ��������
	void highlight_draw(Gdiplus::Graphics &g);
	// ����״̬ʱ����
	void down_draw(Gdiplus::Graphics &g);

private:
	int m_left; // ���Ʒ�Χ���
	int m_top; // ����
	int m_width; // ��
	int m_height; // ��
	Gdiplus::Image *m_normal_img = nullptr; // ����״̬ʱ�ı���ͼƬ
	Gdiplus::Image *m_highlight_img = nullptr; // ����ʱ�ı���ͼƬ
	Gdiplus::Image *m_down_img = nullptr; // ����ʱ�ı���ͼƬ

	ButtonModel *m_model = nullptr; // model����
};

