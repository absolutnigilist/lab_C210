#pragma once
#include "Point.h"
#include "Rect.h"

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
		return ((pr_n <= point.Get_m_x() && pr_m >= point.Get_m_x()) && (pr_n <= point.Get_m_y() && pr_m >= point.Get_m_y()));
	}

};

bool compareRec(Rect& other1, Rect& other2){
		int distance1 = std::sqrt(other1.Get_m_x() * other1.Get_m_y() + other1.Get_m_y() * other1.Get_m_y());
		int distance2 = std::sqrt(other2.Get_m_x() * other2.Get_m_y() + other2.Get_m_y() * other2.Get_m_y());
		return distance1 < distance2;
	};

struct FirstLetter
{
	char letter;
	FirstLetter(char c) :letter(c) {};
	bool operator()(std::string& string) {
	
	return string[0]==letter||string[0]==letter+32; }
};

bool isOdd(std::pair<const std::string, int>& pair) {
	return pair.second & 1;
}

bool isHonest(std::pair<const std::string, int>& pair) {
	return !(pair.second & 1);
}