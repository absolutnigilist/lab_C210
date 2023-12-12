#pragma once
#include "Shape.h"

class Node {
	Node* pPrev;
	Node* pNext;
	Shape* m_data;
public:
	Node();
	Node(Node* prev, const Shape* shape);
	~Node();
	Node* Get_pPrev()const;
	Node* Get_pNext()const;
	Shape* Get_m_Data()const;

	friend class List;
};