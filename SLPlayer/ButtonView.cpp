#include "ButtonView.h"



ButtonView::ButtonView(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height), m_normal_img(nullptr)
{
}


ButtonView::~ButtonView()
{
}


// ����model
void ButtonView::set_model(ButtonModel *model)
{
	m_model = model;
}


// ����
void ButtonView::draw(Gdiplus::Graphics &g)
{

}


// ��������״̬ʱ�ı���ͼƬ
void ButtonView::set_normal_img(Gdiplus::Image *img)
{
	m_normal_img = img;
}


// ���ø���ʱ�ı���ͼƬ
void ButtonView::set_highlight_img(Gdiplus::Image *img)
{
	m_highlight_img = img;
}


// ���ð���ʱ�ı���ͼƬ
void ButtonView::set_down_img(Gdiplus::Image *img)
{
	m_down_img = img;
}


// ����״̬����
void ButtonView::normal_draw(Gdiplus::Graphics &g)
{

}


// ��������
void ButtonView::highlight_draw(Gdiplus::Graphics &g)
{

}


// ����״̬ʱ����
void ButtonView::down_draw(Gdiplus::Graphics &g)
{

}
