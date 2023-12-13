#pragma once
#include <iostream>
#include <vector>
class Point
{
	int m_x, m_y;
public:
	Point();
	Point(int x, int y);
	~Point();
	int Get_m_x() const;
	int Get_m_y()const;
	bool operator<(const Point& other)const;
	bool operator==(const Point& other) const;
	friend bool isAnyCoordinateNegative(const Point& other);
	friend std::ostream& operator<<(std::ostream& os, const Point& other) {
		os << "m_x: " << other.m_x << " " << "m_y: " << other.m_y << std::endl;
		return os;
	};
	friend std::ostream& operator<<(std::ostream& os, const Point* other) {
		os << *other;
		return os;
	};
	friend std::ostream& operator<<(std::ostream& os, const std::vector<Point*>& vpPoint) {
		for (size_t i = 0; i < vpPoint.size(); i++)
		{
			os << *vpPoint[i] << std::endl;
		}

		return os;

	};
};
