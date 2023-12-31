#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <set>


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
	//std::cout << "Container type: " << typeid(a).name() << std::endl;
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
void PrintAdapterContainer(std::map<char, std::set<std::string>>& a) {
	//std::cout << "Container type: " << typeid(a).name() << std::endl;
	if (a.empty())
	{
		std::cout << "Container is empty" << std::endl;
	}
	else
	{
		typename std::map<char, std::set<std::string>>::iterator itMap = a.begin();
		while (itMap != a.end())
		{
			std::cout << "First_val: " << itMap->first << ", " << " Second_val: ";
			std::set<std::string>& tmp_set = itMap->second;
			std::set<std::string>::iterator it_tmp_set = tmp_set.begin();
			while (it_tmp_set != tmp_set.end())
			{
				std::cout << *it_tmp_set << " ";
				++it_tmp_set;
			}
			std::cout << std::endl;
			++itMap;
		}
	}
}

template<>																	//������������� ������ ��� ������ �������������� ���������� � �������
void PrintAdapterContainer(std::map<size_t, std::multiset<std::string>>& a) {
	//std::cout << "Container type: " << typeid(a).name() << std::endl;
	if (a.empty())
	{
		std::cout << "Container is empty" << std::endl;
	}
	else
	{
		typename std::map<size_t, std::multiset<std::string>>::iterator itMap = a.begin();
		while (itMap != a.end())
		{
			std::cout << "First_val: " << itMap->first << ", " << " Second_val: ";
			std::multiset<std::string>& tmp_multiset = itMap->second;
			std::multiset<std::string>::iterator it_tmp_multiset = tmp_multiset.begin();
			while (it_tmp_multiset != tmp_multiset.end())
			{
				std::cout << *it_tmp_multiset << " ";
				++it_tmp_multiset;
			}
			std::cout << std::endl;
			++itMap;
		}
	}
}

template<>																	//������������� ������ ��� ������ �������������� ���������� � �������
void PrintAdapterContainer(std::map<char, std::vector<std::string>>& a) {
	//std::cout << "Container type: " << typeid(a).name() << std::endl;
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
template<typename T, typename U>
void PrintAdapterContainer(std::multimap<T, std::pair<U, U>>& a) {
	//std::cout << "Container type: " << typeid(a).name() << std::endl;
	if (a.empty())
	{
		std::cout << "Container is empty" << std::endl;
	}
	else
	{
		typename std::multimap<T, std::pair<U, U>>::iterator itMap = a.begin();
		while (itMap != a.end())
		{
			std::cout << "First_val: " << itMap->first << ", " << " Second_val: " << itMap->second.first << ", " << itMap->second.second << std::endl;
			++itMap;
		}
	}
}

template<typename T, typename U>
void PrintAdapterContainer(std::multimap<T,U>& a) {
	//std::cout << "Container type: " << typeid(a).name() << std::endl;
	if (a.empty())
	{
		std::cout << "Container is empty" << std::endl;
	}
	else
	{
		typename std::multimap<T,U>::iterator itMap = a.begin();
		while (itMap != a.end())
		{
			std::cout << "First_val: " << itMap->first << ", " << " Second_val: " << itMap->second << std::endl;
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


void WordSearch(std::multimap<std::string, std::pair<std::string, std::string>>& map, const std::string& str) {
	std::multimap < std::string, std::pair < std::string, std::string>>::iterator iter = map.begin();
	bool flag = false;
	while (iter!=map.end())
	{
		
		if (iter->first==str)
		{
			std::cout << "word: " << iter->first << ", " << "translation: " << iter->second.first << "," << iter->second.second << std::endl;
			flag = true;
			break;
		}
		++iter;
	}
	if (!flag)
	{
		std::cout << "Word not found" << std::endl;
	}


}
template <typename T>
void print(const T& item) {
	std::cout << item << " ";
}

char toLower(char c) {
	return std::tolower(static_cast<unsigned char>(c));
}
void toLowerCase(std::string& string) {
	std::transform(string.begin(), string.end(),string.begin(), toLower);
}
std::string toLowerCaseSet(std::string string) {
	std::transform(string.begin(), string.end(), string.begin(), toLower);
	return string;
}