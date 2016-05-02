#include "ButtonView.h"



ButtonView::ButtonView(int left, int top, int width, int height)
	:m_left(left), m_top(top), m_width(width), m_height(height), m_img(nullptr)
{
}


ButtonView::~ButtonView()
{
}


// 绘制
void ButtonView::draw(Gdiplus::Graphics &g)
{

}


// 设置图片
void ButtonView::set_img(Gdiplus::Image *img)
{
	m_img = img;
}


// 正常状态绘制
void ButtonView::normal_draw(Gdiplus::Graphics &g)
{

}


// 高亮绘制
void ButtonView::highlight_draw(Gdiplus::Graphics &g)
{

}


// 按下状态时绘制
void ButtonView::press_down_draw(Gdiplus::Graphics &g)
{

}
