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