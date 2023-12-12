#pragma once
#include "Node.h"

Node::Node():pPrev(nullptr),pNext(nullptr){}
Node::Node(Node* prev, const Shape* shape):m_data(shape->ShapeCopy()){
	pPrev = prev;
	pNext = pPrev->pNext;
	pPrev->pNext = this;
	pNext->pPrev = this;
	//m_data = shape.ShapeCopy();
	
}
Node::~Node(){
	if (pNext)
	{
		pNext->pPrev = pPrev;
	}
	if (pPrev)
	{
		pPrev->pNext = pNext;
	}
}
Node* Node::Get_pPrev()const {
	return pPrev;
}
Node* Node::Get_pNext()const {
	return pNext;
}

Shape* Node::Get_m_Data()const {
	return m_data;
}


