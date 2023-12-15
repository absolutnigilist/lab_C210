#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <map>


template<typename T>
std::vector<T> vector_inverse(const std::vector<T>& a) {					//������ ������ ��� �������� ������� ��������
	return std::vector<T> (a.rbegin(), a.rend());
}

template<typename T>														//������ ��� ������ ����� �� �������
void printAdapterContainer(T a) {
	std::cout << "Container type: " << typeid(a).name() << std::endl;
	if (a.empty())
	{
		std::cout << "Container is empty" << std::endl;
	}
	while (!a.empty())
	{
		std::cout << a.top() << " ";
		a.pop();
	}

}
template<typename T>														//������������� ������ ��� ������ ������� � ������������� ������� �� �������
void printAdapterContainer(std::queue<T> a) {
	std::cout << "Container type: " << typeid(a).name() << std::endl;
	if (a.empty())
	{
		std::cout << "Container is empty" << std::endl;
	}
	while (!a.empty())
	{
		std::cout << a.front()<<" ";
		a.pop();
	}

}

template<typename T, typename U>										//������������� ������ ��� ������ �������������� ���������� � �������
void PrintAdapterContainer(std::map<T, U>& a) {
	std::cout << "Container type: " << typeid(a).name() << std::endl;
	if (a.empty())
	{
		std::cout << "Container is empty" << std::endl;
	}
	else
	{
		typename std::map<T, U>::iterator it = a.begin();
		while (it != a.end())
		{
			std::cout << "First_val: " << it->first << ", " << " Second_val: " << it->second << std::endl;
			++it;
		}
	}
}

template<>																	//������������� ������ ��� ������ �������������� ���������� � �������
void PrintAdapterContainer(std::map<char, std::vector<std::string>>& a) {
	std::cout << "Container type: " << typeid(a).name() << std::endl;
	if (a.empty())
	{
		std::cout << "Container is empty" << std::endl;
	}
	else
	{
		typename std::map<char, std::vector<std::string>>::iterator itMap = a.begin();
		while (itMap != a.end())
		{
			std::cout << "First_val: " << itMap->first << ", " << " Second_val: ";
			std::vector<std::string>& tmp_vector = itMap->second;
			std::vector<std::string>::iterator it_temp_vector= tmp_vector.begin();
			while (it_temp_vector!=tmp_vector.end())
			{
				std::cout << *it_temp_vector << " ";
				++it_temp_vector;
			}
			std::cout << std::endl;
			++itMap;
		}
	}
}

template<typename T>														//������ ������ ���������� �� �������
void PrintContainer(const T& a) {
	std::cout << "Container type: " << typeid(a).name() << std::endl;
	if (a.empty())
	{
		std::cout << "Container is empty" << std::endl;
	}
	else
	{
		typename T::const_iterator it = a.begin();
		while (it != a.end())
		{
			std::cout << *it << " ";
			++it;
		}
	}
}
