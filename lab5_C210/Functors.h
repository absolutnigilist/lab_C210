#pragma once
#include "Point.h"
template<typename T>
class ChangeElements {
	T pr_x, pr_y;
public:
	ChangeElements(T x, T y) :pr_x(x), pr_y(y) {};
	void operator()(Point& point) {
		point.Set_coord(pr_x, pr_y);
	}
};

template<typename T>
class SurcheElements {
	T pr_n, pr_m;
public:
	SurcheElements(T x, T y) :pr_n(x), pr_m(y) {};
	const bool operator()(const Point& point) const {
		return ((pr_n <= point.m_x && pr_m >= point.m_x) && (pr_n <= point.m_y && pr_m >= point.m_y));
	}

};