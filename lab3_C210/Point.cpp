#include "Point.h"

Point::Point():m_x(0),m_y(0){}
Point::Point(int x, int y) :m_x(x), m_y(y) {}
Point::~Point() {
	//std::cout << "Called class Point destructor"<<std::endl;
}
int Point::Get_m_x() const
{
	return m_x;
}
int Point::Get_m_y() const
{
	return m_y ;
}

