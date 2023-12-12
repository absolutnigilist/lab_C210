#include "Shape.h"
#include "Rect.h"
#include <vector>


Rect::Rect() :Shape(RED), m_left(0), m_top(0), m_right(10), m_bottom(10) {
};
Rect::Rect(int left, int right, int top, int bottom, COLOR c):Shape (c){
	RectNorm(left, right, top, bottom);
}
Rect::~Rect() {};
Shape& Rect::operator=(const Rect& other) {
	if (this!=&other)
	{
		m_left = other.m_left;
		m_right = other.m_right;
		m_top = other.m_top;
		m_bottom = other.m_bottom;
		Shape::operator=(other);
	}
	return*this;
}
bool Rect::operator==(const Shape& other)const {
	const Rect* otherRect = dynamic_cast<const Rect*>(&other);
	if (otherRect)
	{
		return Shape::operator==(other) && m_right == otherRect->m_right
			&& m_left == otherRect->m_left
			&& m_bottom == otherRect->m_bottom
			&& m_top == otherRect->m_top;
	}
	return false;
}
double Rect::Scale()const {
	int height = m_right - m_left;
	int width = m_bottom - m_top;
	 int res;
	return res = height * width;
}
Shape::COLOR Rect::GetColor()const {
	return Shape::m_color;
}
Shape* Rect::ShapeCopy()const {
	return new Rect(*this);
}
void Rect::RectNorm(int left, int right, int top, int bottom) {
	if (left < right)
	{
		m_left = left;
		m_right = right;
	}
	else
	{
		m_left = right;
		m_right = left;
	}
	if (top < bottom)
	{
		m_top = top;
		m_bottom = bottom;
	}
	else
	{
		m_top = bottom;
		m_bottom = top;
	}
};
void Rect::PrintData(std::ostream& os) const {
	os << "Rect" << " " << m_left << " " << m_right << " " << m_top << " " << m_bottom << " " << Scale()<<" ";
	Shape::PrintData(os);
}
void Rect::Read(std::istream& is) 
{
	int scale;
	is >> m_left >> m_right >> m_top >> m_bottom>>scale;
	Shape::Read(is);	
}
std::ostream& operator<<(std::ostream& os, const Rect& other) {
	other.PrintData(os);
	return os;
}
std::istream& operator>>(std::istream& is, Rect& other) {
	other.Read(is);
	return is;
}