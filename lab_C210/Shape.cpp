#include "Shape.h"

Shape::Shape():m_color (RED) {};
Shape::Shape(COLOR c) :m_color(c) {};
Shape::~Shape() {};
Shape& Shape::operator=(const Shape& other) {
	if (this!=&other)
	{
		m_color = other.m_color;
	}
	return *this;
}
bool Shape::operator==(const Shape& other)const {
	return m_color == other.m_color;
}
Shape::COLOR Shape::GetColor()const {
	return m_color;
}
const char* Shape::GetShapeColor() const {
	static const char* color_names[] = { "RED", "GREEN", "BLUE", "YELLOW", "BLACK", "WHITE" };
	return color_names[m_color];
}
void Shape::PrintData(std::ostream& os) const {
	os << GetShapeColor() <<" "<< std::endl;
}
void Shape::Read(std::istream& is) 
{	
	char arrai[15];
	is >> arrai;
	switch (arrai[0])
	{
	case 'R':
		m_color = Shape::RED;
		break;
	case 'G':
		m_color = Shape::GREEN;
		break;
	case 'B':
		if (arrai[2]=='A')
		{
			m_color = Shape::BLACK;
			break;
		}
		else
		{
			m_color = Shape::BLUE;
			break;
		}
		
	case 'Y':
		m_color = Shape::YELLOW;
		break;
	case 'W':
		m_color = Shape::WHITE;
		break;
	default:
		break;
	}
}

std::ostream& operator<< (std::ostream& os, const Shape& other) {
	const char* color_names[]= { "RED", "GREEN", "BLUE", "YELLOW", "BLACK", "WHITE" };
	os << color_names[other.m_color];
	return os;
}
std::istream& operator>>(std::istream& is, Shape& other) {
	int colorInput;
	if (is>>colorInput)
	{
		other.m_color = static_cast<Shape::COLOR>(colorInput);
	}
	return is;
}
