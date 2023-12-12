#pragma once
#include "MyString.h"
#include "MyStack.h"
#include"MyStack2.h"

template<typename T> void Swap(T& a, T& b) {
	T tmp =std::move(a);
	a = std::move(b);
	b = std::move(tmp);
}
