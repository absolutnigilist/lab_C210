// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

#include "sdafxh.h"
#include "Point.h"
#include "Comparator.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <iostream>
#include <tchar.h>

const char* sep = "------------------------------------\n";
#define sep std::cout << std::endl; std::cout<<sep; std::cout << std::endl;
#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	{
		std::stack<int> myStack;					//������� ������ ������ ����
		myStack.push(1);							//������ ��������
		myStack.push(2);
		myStack.push(3);
		std::cout << "Stack: ";

		printAdapterContainer(myStack);				//�� ������� 3 2 1
		sep

			std::queue<int> myQueue;					//������� ������ ������ �������
		myQueue.push(1);							//������ ��������
		myQueue.push(2);
		myQueue.push(3);
		std::cout << "Queue: ";

		printAdapterContainer(myQueue);				//�� ������� 1 2 3
		sep

			std::priority_queue<int> myPriorityQueue;
		myPriorityQueue.push(3);
		myPriorityQueue.push(2);
		myPriorityQueue.push(1);
		std::cout << "Priority Queue: ";

		printAdapterContainer(myPriorityQueue);		//�� ������� 3 2 1
		sep
	}
	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
	//��������� ��������

	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 

	std::vector<int> vVector = { 1,2,3,4,5 };							//������� � �������������� ������ int
	std::stack<int, std::vector<int>> vStack(vector_inverse(vVector));	//������� ������ ����, �������� � ���� ������ ������������ �� ������� 
	//vector_inverse  ������������� ������� ������������� �����

	PrintContainer(vVector);											//�� ������� 1 2 3 4 5 
	sep
		printAdapterContainer(vStack);										//�� ������� 1 2 3 4 5
	sep

		////////////////////////////////////////////////////////////////////////////////////
		//queue

		//�������� �������, ������� �������� ��������� �� ������� ���� Point,
		//��� ���� ���� ������� ������� ���������.
		//�������� �������� ������� � ���������� ��������� ����������� front() � back()
		//���������, ��� ��������� ������� ��� ����������� ����� �������?

		std::deque<Point*> vpPoint(5);										//������� deque ���������� �� Point �������� ���� ���������
	for (size_t i = 0; i < vpPoint.size(); i++)
	{
		vpPoint[i] = new Point(i, i);									//����������� ������� �������
	}
	std::queue<Point*, std::deque<Point*>> vQueue(vpPoint);				//������� ������� ���������� �� Point � ������� ������� deque

	printAdapterContainer(vQueue);
	sep

	vQueue.front()->Set_coord(10, 10);									//������������ �������� ������� �������
	vQueue.back()->Set_coord(20, 20);									//������������ �������� ���������� �������

	printAdapterContainer(vQueue);										//�� ������� 
	sep																	//m_x:10 m_y 20
																		//m_x...	
																		//m_x: 20 m_y: 20 

	while (vQueue.empty())
	{
		delete vQueue.front();											//������� ������� Point �� ������� ��������� ���������
		vQueue.pop();													//������� ���� ��������� �������
	}


	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?

	const char* ar[] = { "A","B","C","D","E" };
	std::priority_queue<const char*> vPrQueue1(ar, ar + sizeof(ar) / sizeof(ar[0]));
	printAdapterContainer(vPrQueue1);									//�� ������� E D C A B
	sep																	//������������ ������������ ������� ������������, ��� ����������� ���������� less ���������� ������

	std::priority_queue<const char*, std::vector<const char*>, StringComparator> vPrQueue2(ar, ar + sizeof(ar) / sizeof(ar[0]));
	printAdapterContainer(vPrQueue2);									//�� ������� A B C D E
	sep																	//������������ ������� � ������� ����������������� �����������


	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	std::set<Point> vSet1;												//������� ���������
	for (size_t i = 0; i < 5; i++)										//� ����� ��������� ��������� ���� 	Point,
	{																	//��� ���������� ������ � ������ Point ���������� �������� <
		vSet1.insert(Point(i, i));
	}
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������

	PrintContainer(vSet1);
	sep

	//�) ���������� �������� ����� ��������...

	std::set<Point>::iterator it = vSet1.find(Point(0, 0));				//���� � ��������� ������ �� ���������� 1,1, ���� �������, �������� �������� �� ��������� �������
	if (it != vSet1.end())												//� ��������� ������ �� �����
	{
		vSet1.erase(it);												//� ��������� ������ �������� ��������, ��������� ������� ����������
		vSet1.insert(Point(10, 10));									//����������� ������ � ����������� ������
	}

	PrintContainer(vSet1);												//�� ������� m_x: 1 m_y: 1
	sep																	//m_x:...
																		//m_x: 10 m_y: 10                                                                                                                      

	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������

	std::set<int> vSet2 = { 1,2,3,4,5 };
	std::set<int>vSet3 = { 5,4,3,2,1 };
	if (vSet2 == vSet3)
	{
		std::cout << "Objects are equal";
	}
	sep

	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)
	int arInt[] = { 5,4,3,0,-1 };
	vSet2.insert(arInt, arInt + sizeof(arInt) / sizeof(arInt[0]));		//� ��������� ����� �������� �������� -1, 0, ��������� ��������������� ��� ��� �������� �������

	PrintContainer(vSet2);
	sep


	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������
	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")

	std::map<const char*, int> employees;
	employees["Ivanova"] = 50000;
	employees["Petrova"] = 60000;
	employees.insert(std::pair<const char*, int>("Sidorova", 70000));
	employees.insert(std::pair<const char*, int>("Makhankova", 80000));

	PrintAdapterContainer(employees);
	sep

	//�) ����������� ����� �������� ������ � ���������� ���� string.
	//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
	//��������� ������������� �� �������� ������ �
	//���������� ���������� ������ ������ � �������

	std::vector<std::string> vString = { "Aleksei","Boris","Aleksei","Boris","Aleksei","Dmitrii" };	//������� ������ <string>
	std::map<std::string, int> countMap1;															//������� ������������� ���������
	
	for (size_t i = 0; i < vString.size(); i++)
	{
		countMap1[vString[i]]++;																	//�� ������ �������� ��������� ����(vString[i]), ���� ���������� �� ������� �������� 0
	}																								//���� ���������� ������� ������������ 1, �������� �� ���������, �������������� ��� ��������
																									//����������� �����
	PrintAdapterContainer(countMap1);
	sep
	
	//�) 
	//����� ������:
	//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
	//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
	//��������������� ������������� ����, ������������ � ���� �����. 
	//���������: �� ����� ������� ����� ����� � ��� �� ������
	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"  ...
	//...
	{
	const char* words[] = { "Abba", "Alfa", "Beta", "Beauty"};				//������ �����
	std::map<char,std::vector<std::string>> mapWords1;						//������������� ��������� � ������ char � ������� ����������� vector<string>
	for (size_t i = 0; i < sizeof(words)/sizeof(words[0]); i++)				//� ����� ��������� �� �������
	{
		std::string str(words[i]);											//������� ������ � �������� i-� ������� �������
		if (mapWords1.find(str[0])==mapWords1.end())						//���� ������ ����� �� �����
		{
			mapWords1[str[0]] = std::vector<std::string>{ str };			//������������ ������
		}
		else																//���� ���� ���� ��������� �� ����� � �������
		{
			bool isDuplicate = false;										//���� �� �����
			std::vector<std::string>& tmp = mapWords1[str[0]];				//��������� �� ������ �� �����
			std::vector<std::string>::iterator itStr = tmp.begin();			//��������
			for (; itStr != tmp.end(); ++itStr)								//� ����� ���������� �������� �������
			{
				if (*itStr==str)											//���� ����� ������
				{
					isDuplicate = true;										//��������� ����
					break;													//������� �� �����
				}
				else if (*itStr>str)										//���� ����� ��� � �������� ������
				{
					tmp.insert(itStr, str);									//��������� ��������
					isDuplicate = true;										//��������� ����
					break;													//������� �� �����
				}
			}
			if (!isDuplicate)												//���� ���� �� ������, ������ ��� � �������� ���� ������ �������
			{
				tmp.push_back(str);											//��������� �������� � �����
			}
		}
		
	}
	PrintAdapterContainer(mapWords1);
	sep
	}
	{
		const char* words[] = { "Abba", "Alfa", "Beta", "Beauty" };
		std::map<char, std::set<std::string>> mapWords2;
		for (size_t i = 0; i < sizeof(words)/sizeof(words[0]); i++)
		{
			std::string str(words[i]);
			mapWords2[str[0]].insert(words[i]);
		}
		PrintAdapterContainer(mapWords2);
		sep
	}


	//�)
	//�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
	//��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
	//������� ����� �������������
	//���� ������ ���� ������ ���� ����������� �� ������
	//
	//������ 
		struct MyStruct	{
		
		std::map<size_t, std::multiset<std::string>> groups;

		void addStudent(int groupNumber, const std::string& studentName) {
			groups[groupNumber].insert(studentName);
		}
	};

	MyStruct myData;
	myData.addStudent(1, "Ivanov");
	myData.addStudent(1, "Petrov");
	myData.addStudent(1, "Ivanov");
	myData.addStudent(2, "Sidorov");
	myData.addStudent(2, "Nazarov");

	PrintAdapterContainer(myData.groups);
	sep

	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()






			stop

			return 0;
	}

