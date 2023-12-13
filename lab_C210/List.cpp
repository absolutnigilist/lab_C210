#include "Shape.h"
#include "List.h"
#include "Rect.h"
#include "Circle.h"
#include < sstream >
#include <vector>


List::List() :m_size(0) {
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}
List::~List() {
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
}
List::List(const List& other) :m_size(other.m_size) {
	Head.pNext = &Tail;
	Tail.pPrev = &Head;

	Node* pThis = &Head;
	Node* pOther = other.Head.pNext;

	while (pOther != &other.Tail)
	{
		pThis->pNext = new Node(pThis, pOther->m_data);
		pOther = pOther->pNext;
		pThis = pThis->pNext;
	}
}
List::List(List&& other) :m_size(other.m_size) {
	if (m_size == 0)
	{
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
	}
	else
	{
		Head.pNext = other.Head.pNext;
		Head.pNext->pPrev = &Head;
		Tail.pPrev = other.Tail.pPrev;
		Tail.pPrev->pNext = &Tail;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
}

List& List::operator=(const List& other) {
	if (this != &other)
	{
		size_t size = (m_size < other.m_size) ? m_size : other.m_size;
		Node* pThis = Head.pNext;
		Node* pOther = other.Head.pNext;

		for (size_t i = 0; i < size; i++)
		{
			try {
				*pThis->m_data = *pOther->m_data;
			}
			catch (std::bad_cast&) {
				delete pThis->m_data;
				pThis->m_data = pOther->m_data->ShapeCopy();
			}
			pThis = pThis->pNext;
			pOther = pOther->pNext;
		}
		for (size_t i = other.m_size; i < m_size; i++)
		{
			delete Tail.pPrev;
		}
		for (size_t i = m_size; i < other.m_size; i++)
		{
			AddToTail(*pOther->m_data);
			pOther = pOther->pNext;
		}
		m_size = other.m_size;
	}
	return *this;

}
List& List::operator=(List&& other) {
	if (this != &other) 
	{
		MakeEmpty();
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;
		m_size = other.m_size;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;	
	}
	return *this;
}
void List::AddToHead(const Shape& data) {
	
	Node* newNode = new Node(&Head, &data);
	m_size++;
}
void List::AddToTail(const Shape& data) {
	Node* newNode = new Node(Tail.pPrev, &data);
	m_size++;
}
bool List::Remove(const Shape& data) {
	Node* current = Head.pNext;
	while (current!=&Tail)
	{
		if (*current->m_data == data)
		{
			m_size--;
			delete current;
			return true;
		}
		current = current->pNext;
	}
	return false;	
}

void List::MakeEmpty() {
	Node* current = Head.pNext;
	while (current!=&Tail)
	{
		Node* tmp = current->pNext;
		delete current;
		current = tmp;
	}
	m_size = 0;
}

std::ostream& operator<<(std::ostream& os, const List& other) {	
	Node* current = other.Head.Get_pNext();
	while (current != &other.Tail) 
	{
		current->Get_m_Data()->PrintData(os);
		current = current->Get_pNext();
	}
	return os;

}
std::istream& operator>>(std::istream& is, List& other) {
	other.MakeEmpty();
	const int maxTypeLenght=50;
	char type[maxTypeLenght];
	Shape* tmp = nullptr;
		
	while (is >> type)
	{

		if (std::strncmp(type, "Rect", maxTypeLenght) == 0)
		{
			tmp = new Rect();
			break;
		}
		else if(std::strncmp(type, "Circle", maxTypeLenght) == 0)
		{
			tmp = new Circle();
			break;
		}
	}
	
	if (tmp)
	{
		tmp->Read(is);
		other.AddToHead(*tmp);
	}
		
	
	return is;
}

void List::SortList(SortType st) {
	if (m_size<=1)
	{

		return;
	}
	switch (st)
	{
	case AREA:
		for (Node* current = Head.pNext; current != &Tail; current = current->pNext)
		{
			for (Node* next = current->pNext; next != &Tail; next = next->pNext)
			{
				if (current->m_data->Scale() > next->m_data->Scale())
				{
					Shape* tmp = current->m_data;
					current->m_data = next->m_data;
					next->m_data = tmp;
				}
			}
		}
		break;
	case COLOR:
		for (Node* current = Head.pNext; current != &Tail; current = current->pNext)
		{
			for (Node* next = current->pNext; next != &Tail; next = next->pNext)
			{
				if (current->m_data->GetColor() > next->m_data->GetColor())
				{
					Shape* tmp = current->m_data;
					current->m_data = next->m_data;
					next->m_data = tmp;
				}
			}
		}
		break;
	default:
		break;
	}
	
}


