#pragma once

template<typename T>class Node {
public:
	T m_data;
	Node<T>* pNext;
public:
	Node(const T& value, Node<T>* next = nullptr) : m_data(value), pNext(next) {}
};
