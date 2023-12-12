#pragma once
#include"Shape.h"

class Circle:public Shape {
	int m_x;
	int m_y;
	int m_radius;

public:
	Circle();
	Circle(int m_x, int m_y, int m_radius, COLOR c);
	virtual ~Circle();
	virtual Shape& operator = (const Circle & other);
	virtual bool operator==(const Shape& other)const override;
	virtual double Scale()const override;
	virtual COLOR GetColor()const override;
	virtual Shape* ShapeCopy()const override;
	virtual void PrintData(std::ostream& os) const override;
	virtual void Read(std::istream& is) override;
	friend std::ostream& operator<<(std::ostream& os, const Circle& other);
	friend std::istream& operator>>(std::istream& is, Circle& other);
};
