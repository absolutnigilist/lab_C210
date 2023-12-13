#pragma once
#include "Point.h"

template<typename T>
void PrintVectorInfo(const T & a) {
	std::cout << "Size " << a.size() << " ";
	std::cout << "Capacity " << a.capacity() << " ";
	std::cout << "Max_size " << a.max_size() << " ";
	std::cout << "Added element " << a.back() << " " << std::endl;
}
template<>
void PrintVectorInfo(const std::vector <Point*>& a) {
	std::cout << "Size " << a.size() << " ";
	std::cout << "Capacity " << a.capacity() << " ";
	std::cout << "Max_size " << a.max_size() << " "<<std::endl;
	for (size_t i = 0; i < a.size(); i++)
	{
		std::cout << "m_x: " << a[i]->Get_m_x() << " " << "m_y: " << a[i]->Get_m_y() << std::endl;
	}
}
template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vv) {
	for (typename std::vector<T>::size_type i= 0; i < vv.size(); ++i)
	{
		os << vv[i] << " ";
	}
	std::cout << std::endl;
	
	return os;
}


bool InsertElementChar(std::vector<char>& v, const char ch) {
	
	bool flag = true;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i]==ch)
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		v.insert(v.begin(), ch);
	}
	
	return flag;
}
void InsertElementW(std::vector<char>& v) {
	if (!v.empty())
	{
		std::vector<char>::iterator it = v.begin();
		while (it != v.end())
		{
			it++;
			it = v.insert(it, 'W');
			++it;
		}
	}
	
}
void EraseRepeat(std::vector<char>& v) {
	std::vector<char>::iterator it = v.begin();
	while (it!=v.end())
	{
		std::vector<char>::iterator runner = it + 1;
		while (runner!=v.end())
		{
			if (*runner==*it)
			{
				runner = v.erase(runner);
			}
			else
			{
				++runner;
			}
		}
		++it;
	}

}
void RemoveDuplicateSequences(std::vector<char>& v) {
	std::vector<char>::iterator it = v.begin();
	

	while (it != v.end() && (it+1) != v.end())
	{
		int count = 1;
		if (*it == *(it+1))
		{
			while ((it+count)!=v.end()&&*it == *(it+count))
			{
				++count;
			}
			it = v.erase(it, it+count);
		}
		else
		{
			++it;
		}

	}

}
template<typename T>
void PrintContainer(const T& a) {
	std::cout << "Container type: " << typeid(a).name() << std::endl;
	if (a.empty())
	{
		std::cout << "Container is empty"<<std::endl;
	}
	else
	{
		typename T::const_iterator it = a.begin();
		while (it != a.end())
		{
			std::cout << *it << " ";
			std::cout << std::endl;
			++it;
		}
	}
}
bool isAnyCoordinateNegative(const Point& other){
	return (other.m_x < 0 || other.m_y < 0);
}

template <typename T>
void Erase_A_a(T& a) {
	if (a.empty())
	{
		std::cout << "Container is empty" << std::endl;
	}
	else
	{
		typename T::iterator it = a.begin();
		while (it != a.end())
		{
			if (it->operator[](0)=='A'||it->operator[](0)=='a')
			{
				it = a.erase(it);
			}
			else
			{
				++it;
			}
			
		}
	}
}