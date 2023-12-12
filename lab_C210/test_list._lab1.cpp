//------------------------------------------------------------------------------
// ��������� ������������� ������
//------------------------------------------------------------------------------
#include "Rect.h"
#include "Circle.h"
#include "List.h"
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

const char* sep = "------------------------------------\n";

//enum SortType {AREA,COLOR};

int _tmain(int argc, TCHAR* argv[])
{
	//
	// 1. ������� ������
	//
	List ls1;
	
	ls1.AddToTail(Circle(1, 1, 1, Shape::WHITE));	//��������� �������� � ������
	ls1.AddToTail(Circle(5, 5, 5, Shape::RED));
	ls1.AddToTail(Rect(2, 3, 4, 5, Shape::RED));
	ls1.AddToTail(Rect(4, 6, 8, 10, Shape::GREEN));
	ls1.AddToTail(Circle(2, 2, 2, Shape::WHITE));
	ls1.AddToTail(Rect(3, 5, 6, 7, Shape::GREEN));
	std::cout << ls1 << sep;	
	//������� ������	

	ls1.Remove(Circle(5, 5, 5, Shape::RED));		// ������� ������ �������, ������ ���������
	std::cout << ls1 << sep; 
	ls1.Remove(Rect(4, 6, 8, 10, Shape::GREEN));
	std::cout << ls1 << sep;
	
	
	//
	// 2. ����������� ���� ��� ������ ����������� ���������	
	//
	List ls2 = ls1;	
	List ls3 = ls2;
	std::cout << ls2 << sep; 

	ls2.AddToHead(Circle(5, 5, 5, Shape::RED));
	ls2.AddToHead(Rect(5, 7, 9, 11, Shape::WHITE));
	
	std::cout << ls2 << sep;	
	ls1 = ls2;			// �� "��������" ������ � "���������"
	std::cout << ls1 << sep;	
	
	ls1 = ls3;			// �� "����������" ������ � "�������"
	std::cout << ls1 << sep;	
	
	//
	// 3. ���������� ��� ��������� �����������	
	//
	List ls4 = std::move(ls2);
	std::cout << ls4 << sep; 
	std::cout << ls2 << sep; 	

	ls3 = std::move(ls4);
	std::cout << ls3 << sep; 
	std::cout << ls4 << sep;

	
	//
	//4.  ���������� �� ����������� ������� ������
	//
	std::cout << ls3 << sep;
	ls3.SortList(AREA);
	std::cout << ls3 << sep;

	ls3.SortList(COLOR);
	std::cout << ls3 << sep;

	
	//
	// 5. �������� ����/�����
	//
		
	
	
	std::ofstream fout("list.txt");
	fout << ls3 << sep;	// ������� ������ � ����
	fout.close();
	std::ifstream fin("list.txt", std::ios_base::in);
	List ls5;
	if (fin.is_open())
	{
		std::string line;
		while (getline(fin, line))
		{
			std::stringstream in(line);			
			in >> ls5;
		}
			fin.close();
	}
	std::cout << ls5;


	// 
	// 6. �������������� ��������
	//
	// ...
	
	return 0;
}