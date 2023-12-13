#pragma once
#include "Shape.h"
 
class Rect:public Shape {
	int m_left;
	int m_right;
	int m_top;
	int m_bottom;

public:
	Rect();
	Rect(int left, int right, int top, int bottom, COLOR c);
	virtual ~Rect();
	virtual Shape& operator=(const Shape& other);
	virtual bool operator==(const Shape& other) const override;
	virtual double Scale()const override;
	virtual COLOR GetColor()const override;
	virtual Shape* ShapeCopy() const override;
	void RectNorm(int left, int right, int top, int bottom);
	virtual void PrintData(std::ostream& os) const override;
	virtual void Read(std::istream& is) override;
	friend std::ostream& operator<<(std::ostream& os, const Rect& other);
	friend std::istream& operator>>(std::istream& is, Rect& other);
};
