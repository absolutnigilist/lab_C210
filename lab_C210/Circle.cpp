#include "Circle.h"

Circle::Circle() :Shape(RED) {};
Circle::Circle(int x, int y, int radius, COLOR c) :Shape(c), m_x(x), m_y(y), m_radius(radius) {
};
Circle::~Circle() {};
Shape& Circle::operator = (const Shape& other) {
	if (this != &other)
	{
		const Circle& r = dynamic_cast<const Circle&>(other);
		m_x = r.m_x;
		m_y = r.m_y;
		m_radius = r.m_radius;
		Shape::operator=(other);
	}
	return *this;
}
bool Circle::operator==(const Shape& other) const {
	const Circle* otherCircle = dynamic_cast<const Circle*>(&other);
	if (otherCircle)
	{
		return Shape::operator==(other) && m_x == otherCircle->m_x
			&& m_y == otherCircle->m_y
			&& m_radius == otherCircle->m_radius;
	}
	return false;

}
double Circle::Scale()const {
	int res = 3.14 * (m_radius * m_radius);
	return res;
};
Shape::COLOR Circle::GetColor()const {
	return Shape::m_color;

}
Shape* Circle::ShapeCopy()const {
	return new Circle(*this);
}
void Circle::PrintData(std::ostream& os) const {
	
	os << "Circle" <<" "<< m_x << " " << m_y << " " << m_radius << " " << Scale()<<" ";
	Shape::PrintData(os);
}
void Circle::Read(std::istream& is) 
{
	int scale;
	is >> m_x >> m_y >> m_radius>>scale;
	Shape::Read(is); 
};
std::ostream& operator<<(std::ostream& os, const Circle& other) {
	
	other.PrintData(os);
	return os;
}
std::istream& operator>>(std::istream& is, Circle& other) {
	other.Read(is);
	return is;
}
 