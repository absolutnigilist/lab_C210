#pragma once
#include "Node.h"


enum SortType { AREA, COLOR };

class List{
	Node Head;
	Node Tail;
	size_t m_size;

public:
	List();
	~List();
	List(const List& other);
	List(List&& other);
	List& operator=(const List& other);
	List& operator=(List&& other);
	void AddToHead(const Shape& data);
	void AddToTail(const Shape& data);
	bool Remove(const Shape& data);
	void MakeEmpty();
	friend std::ostream& operator<<(std::ostream& os, const List& other);
	friend std::istream& operator>>(std::istream& in, List& other);
	void SortList(SortType st);
	
};