#include "ButtonView.h"



ButtonView::ButtonView(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height), m_img(nullptr)
{
}


ButtonView::~ButtonView()
{
}


// ����
void ButtonView::draw(Gdiplus::Graphics &g)
{

}


// ����ͼƬ
void ButtonView::set_img(Gdiplus::Image *img)
{
	m_img = img;
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
void ButtonView::press_down_draw(Gdiplus::Graphics &g)
{

}
