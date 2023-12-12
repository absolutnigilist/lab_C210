#pragma once
#include <iostream>

template<typename T, size_t size> class MyStack {
	T array[size];
	int top_index;
public:
	MyStack();
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	MyStack& operator<<(const T& value);
	MyStack& operator<<(T&& value);
	MyStack& operator>>(T& value);
	template<typename U, size_t s>friend std::ostream& operator<<(std::ostream& os,const MyStack <U,s> &other);
	bool isEmpty()const;
	bool isFull()const;

};

template<typename T, size_t size> 
MyStack <T, size>::MyStack() :top_index(-1) {
	for (size_t i = 0; i < size; i++)
	{
		array[i] = T();
	}
}
template <typename T, size_t size> 
MyStack <T, size>& MyStack<T,size>::operator<<(const T& value)
{
	if (isFull())
	{
		throw std::out_of_range("Stack overflow");
	}
	array[++top_index] = value;
	return*this;
}

template <typename T, size_t size>
MyStack <T, size>& MyStack<T, size>::operator<<(T&& value)
{
	if (isFull())
	{
		throw std::out_of_range("Stack overflow");
	}
	array[++top_index] = std::move(value);
	return*this;
}

template<typename T, size_t size> 
MyStack<T, size>& MyStack<T, size>::operator>>(T& value) {
	if (isEmpty())
	{
		throw std::out_of_range("Stack underflow");
	}
	value = std::move(array[top_index]);
	top_index--;
	return *this;
}
template<typename T, size_t size> 
std::ostream& operator<<(std::ostream& os, const MyStack<T, size>& other)
{
	
	if (other.isEmpty())
	{
		for (size_t i = 0; i <size; ++i)
		{
			os << other.array[i] << (i <size-1 ? ", " : "");
		}
	}
	else
	{
		for (size_t i = 0; i <= other.top_index; ++i)
		{
			os << other.array[i] << (i == other.top_index ? "" : ", ");
		}
	}
	return os;
}
template<typename T, size_t size> 
bool MyStack<T, size>::isEmpty()const {
	return top_index == -1;
}
template<typename T, size_t size>
bool MyStack<T, size>::isFull()const {
	return top_index == static_cast<int>(size) - 1;
}
template<typename T, size_t size> 
T& MyStack<T, size>::operator[](size_t index) {
	if (index >= 0 && index < size)
	{
		return array[index];
	}
	throw std::out_of_range("Index out of range");

}
template<typename T, size_t size> 
const T& MyStack<T, size>::operator[](size_t index)const {
	if (index >= 0 && index < size)
	{
		return array[index];
	}
	throw std::out_of_range("Index out of range");
}
