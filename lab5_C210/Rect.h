#pragma once
class Rect {
	int m_x;
	int m_y;
	int m_height;
	int m_width;

public:
	Rect();
	Rect(int x, int y, int h, int w) :m_x(x), m_y(y), m_height(h), m_width(w) {};
	~Rect() {};
	int Get_m_x() { return m_x; };
	int Get_m_y() { return m_y; }
	int Get_m_height() { return m_height;}
	int Get_m_width() { return m_width; }
};