//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

#include "Header.h"
#include "MyString.h"
#include "Point.h"
#include <list>
#include <deque>


#pragma warning(disable: 4786)


using namespace std;	

#define	  stop __asm nop
const char* sep = "------------------------------------\n";


int main()
{
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 
	vector<int> vInt;
	std::cout << vInt.size() << std::endl;

	//���������������� ��������� ��������, ��������� - ��� �� ���������
	//���� ���� ��������������, - ���������

	if (!vInt.empty())
	{
		vInt.front() = 1;
	}
	else
	{
		std::cout << "Trying to access the first element of an empty vector" << std::endl;
	}
	std::cout << sep << std::endl;


	//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
	//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
	//size(), capacity(), max_size() � �������� �������� ���������. 
	//
	//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
	//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
	//������� ��� "���������" � �������� ��������� �� �������.
	for (size_t i = 0; i < 20; i++)
	{
		vInt.push_back(i);
		PrintVectorInfo(vInt);
	}
	std::cout << sep << std::endl;

	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?

	vector<double> vDouble1(5); //�������� ������� ������������������� ������������� �� ���������, �� ���� 0.0
	PrintVectorInfo(vDouble1);
	std::cout << sep << std::endl;
	double Val = 1.1;
	for (size_t i = 0; i < 5; i++)
	{
		vDouble1.push_back(Val);
		PrintVectorInfo(vDouble1);
		Val += 1.1;
	}
	std::cout << sep << std::endl;

	//������ �������� ���� MyString � ��������� �������� - 5 ���������
	//� �������������� ������� �������� ������� "A"
	//C ������� ������� at() � ����� � ������� ���������
	//�������������� []  �������� �������� �����-���� ���������.
	//���������� "�����" �� ������� ������� � ������� at() �
	//� ������� []. 
	vector<MyString> vMyString(5, MyString("A"));
	PrintVectorInfo(vMyString);
	
	vMyString.at(0) = MyString("B");
	vMyString[0] = MyString("C");
	try
	{
		vMyString.at(5) = MyString("D");
	}
	catch (const std::out_of_range& e)
	{
		std::cout << "Exception caught (at()): "<< e.what() << std::endl;
	}
	std::cout << sep << std::endl;


	//������ ������������ - vDouble3, ������� �������� ������ ���������
	// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
	//����� ������� � �������������������!

	{
		double dMas[] = { 1.5,2.5,3.5,4.5,5.5,6.5 };
		int size = sizeof(dMas) / sizeof(dMas[0]);
		vector<double> vDouble3(dMas, dMas + 5);

		for (size_t i = 0; i < vDouble3.size(); i++)
		{
			std::cout << vDouble3[i] << " ";
		}
		std::cout << sep << std::endl;
	}
	
		double dMas[] = { 1.5,2.5,3.5,4.5,5.5,6.5 };
		vector<double> vDouble3 = { &dMas[0], &dMas[5] };
		for (size_t i = 0; i < vDouble3.size(); i++)
		{
			std::cout << vDouble3[i] << " ";
		}
		std::cout << std::endl;
		std::cout << sep << std::endl;

	
	//������ ������������ - vDouble4, ������� �������� ������ ���������
	// [2,5) ������� vDouble3. 
	//vDouble3.resize(5);
	vector<double> vDouble4 = { vDouble3.begin() + 2, vDouble3.begin() + 5 };
	
	for (size_t i = 0; i < vDouble4.size(); i++)
	{
		std::cout << vDouble4[i] << " ";
	}
	std::cout << std::endl;
	std::cout << sep << std::endl;

	//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
	//����� ������ ��� ������� ��������?
	//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).
	
	vector<Point> vPoint1(3);												//��� ������� �������� ������ ����������� �� ���������
	vector<Point> vPoint2(5, Point(1, 1));									//������� ����� ����� ����������� � �����������, ��������� ������ �������� ������������ ��������������� ������������� ������������ ������������ �����������
	
	//������ ���������� �� Point - vpPoint � ��������� �������� 5
	//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
	{
		vector<Point*>vpPoint1(5);
		for (size_t i = 0; i < vpPoint1.size(); i++)
		{
			vpPoint1[i] = &vPoint2[i];
		}
		vector<Point*>vpPoint2(5);
		for (size_t i = 0; i < vpPoint1.size(); i++)
		{
			vpPoint2[i] = new Point(1, 1);
		}
		
	//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
		//�) ������������� ����� ��������� �������
		//�) ��� ���������� operator<< ��� Point*
		std::cout << vpPoint1[0];											//������� �� ������� ������ ������� �������
		std::cout << sep << std::endl;					
		
		std::cout << vpPoint1;												//������� � ������� ���� ������ � ������� �������������� ���������<<
		std::cout << sep << std::endl;										//������� � ������� ���� ������ � ������� ������������������� ������� �������

		PrintVectorInfo(vpPoint2);

		for (size_t i = 0; i < vpPoint2.size(); i++)
		{
			delete vpPoint2[i];												//��� vpPoint2 ����������� ������
		}
	}																		//�� ����������� ������ ������������� ��������� ���������� ��� vpPoint1
	//����� �������������� �������� ����� ����������� ��� ������ �������?


	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
		
		{
		size_t n = 5;
		vector<int> v(n);								//������� ������ ����� � �������� 5 ���������
		v.resize(n/2);									//�������� ������ �������
			if (v.capacity() == n)  //true?				//��� ��� n/2<capacity, ����������������� ������ �� ����������, ������� true
			{
				std::cout << "#1 " << std::endl;
			}
			
		}
		

		
		{
		int n = 20;										
		size_t m = 10;
		vector<int> v(n);								//������� ������ ����� � �������� 5 ���������
		v.reserve(m);									//����������� ������ ��� 10 ���������, ����������� ������ �� ��������
		if(v.capacity() == m) //true?					//������� ������ true, ���� ���� n>m
			{
				std::cout << "#2 " << std::endl;
			}
		}
		

		
		{
		vector<int> v(3,5);								//������� ������ ����� � �������� 3 � �������������� �������� 5-����							[5,5,5]
		v.resize(4,10); //��������?						//�������� ������ ������� �� 4-� � �������������� ��������� ������� 10							[5,5,5,10]
		v.resize(5); //��������?						//�������� ������ ������� �� 5-� � �������������� ��������� ������� ���������� �������������	[5,5,5,10,0]
	
		}
		

	//�������� ��� "������" ������� � ����������
	//������ (�� ������ � ���� �� ����) ����. 
		{
			vector<int> vInt1;
			vector<int>vInt2;


		//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
		//��� ���������� � ������� push_back.
		vInt1.reserve(5);														//size=0;capacity=5;
		for (size_t i = 0; i < vInt1.capacity(); i++)
		{
			vInt1.push_back(i);													//� ����� ��������� ������, size1>>2>>3>>4>>5;capacity=5;
			PrintVectorInfo(vInt1);
		}
		std::cout << sep << std::endl;
		//������ ������ ������ ��������� ���������� ����������� push_back.
		for (size_t i = 0; i < 5; i++)											//size=0;capacity=0;
		{
			vInt2.push_back(i);													//� ����� ��������� ������ � ������������������ ������ 
			PrintVectorInfo(vInt2);												//size1>>2>>3>>4>>4; capacity1>>2>>3>>4>>6
		}
		std::cout << sep << std::endl;
		//�������� ������, ������� �������� � �������� ���������


		//!!! shrink_to_fit - ���������� ������� �������.
		//��� ������ ������� �� ����������� ������� ��������� ��������� �������
		//�� size.
		vInt1.shrink_to_fit();
		vInt2.shrink_to_fit();

		}
	//�������� "����������� �������" - ������� ��������
	//����� ���������� ������ int ar[] = {11,2,4,3,5};
	//�������� ������ �������� ��������� �������:
	//������ vv[0] - �������� 11 ��������� �� ��������� 11
	//vv[1] - �������� 2,2
	//vv[2] - �������� 4,4,4,4
	//...
		int ar[] = { 11,2,4,3,5 };
		vector<vector<int>> vv(5);
		for (size_t i = 0; i < sizeof(ar)/sizeof(ar[0]); i++)
		{
			vv[i].assign(ar[i], ar[i]);
		}
	//������������ ���������� ������ ����������� ������� �� �������
	//� �������:
	
	std::cout<<vv<<std::endl;
	std::cout << sep << std::endl;
	stop

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//������� �������� ������������������ insert().
	//���������� �������, ������� ������ ��������� ����� �������
	//� ������ ������� ������ ��� �������, ��� � ������� ������
	//�������� ��� ���.
	//��������� ����������������� ������� - � ������ vChar2 �������� � ������ ������� ������ ������ ���
	//�������, ��� � ������� ������ ������� ��� ���.
	//��������: vChar2 - abc 
	//��� ������� �������� 'a' ������� ������ ���� ���������������
	//��� ������� �������� 'q' vChar2 - qabc 

	vector<char> vChar2 = { 'a','b','c' };
	bool pruf=InsertElementChar(vChar2, 'd');
	
	
	//���������� �������, ������� ������ ��������� ����� �������
	//����� ������ ��������� �������
	//��������� ����������������� ������� - �������� ����� ������ ��������� ������� vChar2 ����� 'W'
	
	InsertElementW(vChar2);

	///////////////////////////////////////////////////////////////////
	//�������� �������, ������� ������ ������� ������ ������������� ������������������.
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"

	vector<char> vChar3 = { 'q','q','w','e','r','r','r','r','t','y','1','2','2','2','2','r','3','3'};
	RemoveDuplicateSequences(vChar3);										

	stop

	///////////////////////////////////////////////////////////////////

	//�������� �������� ������������������ erase()
	//�������� ������� �������� �� ������ ������� ���� ������ 
		 //��������: ���� - "qwerrrrty12222r3", ����� - "qwerty123"

	vector<char> vChar4 = { 'q','w','e','r','r','r','r','t','y','1','2','2','2','2','r','3' };
	EraseRepeat(vChar4);	

	stop

	///////////////////////////////////////////////////////////////////
	//�������� ����� ������ ����� �������, ����� ��� �������� �����
	//������� ��������� ������ �� ��������� ����� ��������, �� �����������
	//���� �� � �������� �������
		
	vector<char>revercsed_vChar4(vChar4.rbegin(), vChar4.rend());
	stop

	///////////////////////////////////////////////////////////////////

	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()
	
	std::list<Point> ptList1;
	ptList1.push_back(Point(3, 3));
	ptList1.push_front(Point(2, 2));
	ptList1.insert(ptList1.begin(), Point(1, 1));

	stop
	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.
	
	PrintContainer(ptList1);
	std::cout << sep << std::endl;

	stop
	//�������� ����� �� ������� "�����������" - reverse()

	ptList1.reverse();
	
	PrintContainer(ptList1);
	std::cout << sep << std::endl;
	
	stop

	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� 
	
	vector<Point> original_vector1 = {Point(1,1), Point(2,2), Point(3,3)};
	list<Point> ptList2(original_vector1.rbegin(),original_vector1.rend());
	
	PrintContainer(ptList2);
	std::cout << sep << std::endl;

	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������

	ptList1.sort();
	ptList2.sort();
	
	PrintContainer(ptList1);
	PrintContainer(ptList2);
	std::cout << sep << std::endl;
	stop

		//���������� ��������������� ������ - merge(). ����������: ���
		//��� ���� ���������� � ������ �������.

	ptList1.merge(ptList2);											//���������� ptList2 ����������� � ptList1, ������ ���������� ������
	
	PrintContainer(ptList1);
	PrintContainer(ptList2);
	std::cout << sep << std::endl;
	stop

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ������ ���� ����������� � ������ Point?

	ptList1.remove(Point(3, 3));
	
	stop
	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if(). 
	
	list<Point>ptList3 = { Point(1,1),Point(-1,-1) };
	
	PrintContainer(ptList3);
	std::cout << sep << std::endl;

	ptList3.remove_if(isAnyCoordinateNegative);
	
	PrintContainer(ptList3);
	std::cout << sep << std::endl;

	//���������� �� ������ ������ ������������� ������ - unique(). 
	
	PrintContainer(ptList1);
	std::cout << sep << std::endl;

	ptList1.unique();
	PrintContainer(ptList1);
	std::cout << sep << std::endl;

	stop

	///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������
	
	vector<Point> original_vector2 = { Point(1,1), Point(2,2), Point(3,3) };
	deque<Point> ptDeque;
	ptDeque.assign(original_vector2.begin(),original_vector2.end());
	
	PrintContainer(ptDeque);
	std::cout << sep << std::endl;


	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'

	deque<MyString>msDeque;
	msDeque.push_back("Apple");
	msDeque.push_front("Banana");
	msDeque.insert(msDeque.begin(), "apricot");

	Erase_A_a(msDeque);
	PrintContainer(msDeque);
	std::cout << sep << std::endl;

stop


	return 0;
}