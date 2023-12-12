#pragma once
//#include "MyNode.h"
#include <iostream>

template<typename T> 
class MyStack2 {
	class Node {
	public:
		T m_data;
		Node* pNext;
		Node(const T& value, Node* next = nullptr) : m_data(value), pNext(next) {}
		friend class MyStack2;
	};
	Node* m_pHead;
	size_t size;

public:
	MyStack2();
	~MyStack2();
	MyStack2(const MyStack2& other);
	MyStack2(MyStack2&& other)noexcept;
	MyStack2& operator=(const MyStack2& other);
	MyStack2& operator=(MyStack2&& other)noexcept;
	void push(const T& value);
	T pop();
	template<typename T> friend std::ostream& operator<<(std::ostream& os, const MyStack2<T>& other);
	void clear();
	bool isEmpty() const;
private:
	void copyFrom(const MyStack2& other);
};

template <typename T>
MyStack2<T>::MyStack2():m_pHead(nullptr), size(0) {}

template<typename T>
MyStack2<T>::~MyStack2() {
	clear();
}
template<typename T>
MyStack2<T>::MyStack2(const MyStack2& other):m_pHead(nullptr),size(other.size){
	copyFrom(other);
}
template<typename T>
MyStack2<T>::MyStack2(MyStack2&& other)noexcept {
	m_pHead = other.m_pHead;
	size = other.size;
	other.m_pHead = nullptr;
	other.size = 0;
}
template<typename T>
MyStack2<T>& MyStack2<T>::operator=(const MyStack2& other) {
	if (this!=&other)
	{
		clear();
		copyFrom(other);
	}
	return *this;
}
template<typename T>
MyStack2<T>& MyStack2<T>::operator=(MyStack2&& other) noexcept{
	if (this!=&other)
	{
		clear();
		m_pHead = other.m_pHead;
		other.m_pHead = nullptr;
	}
	return *this;

}

template<typename T>
inline void MyStack2<T>::push(const T& value) {
	m_pHead = new Node(value, m_pHead);
}

template<typename T>
T MyStack2<T>::pop() {
	if (isEmpty())
	{
		throw std::runtime_error("Stack is empty"); 
	}
	Node* node = m_pHead;
	T value = node->m_data;
	m_pHead = m_pHead->pNext;
	delete node;
	return value;
}

template<typename T> 
std::ostream& operator<<(std::ostream& os, const MyStack2<T>& other) {
	typename MyStack2<T>::Node* current = other.m_pHead;
	while (current!=nullptr)
	{
		os << current->m_data << " ";
		current = current->pNext;
	}
	return os;
}

template<typename T>
void MyStack2<T>::clear() {
	while (!isEmpty())
	{
		pop();
	}
}

template<typename T>
bool MyStack2<T>::isEmpty()const {
	return m_pHead == nullptr;
}

template<typename T>
inline void MyStack2<T>::copyFrom(const MyStack2& other)
{
	if (other.m_pHead==nullptr)
	{
		return;
	}
	Node* current_other = other.m_pHead;
	m_pHead = new Node(current_other->m_data);
	Node* current = m_pHead;
	while (current_other->pNext!=nullptr)
	{
		current_other = current_other->pNext;
		current->pNext = new Node(current_other->m_data);
		current = current-> pNext;
	}
}
