// Iter_Alg.cpp : Defines the entry point for the console application.
//
//���������. ����������� ���������. ���������.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <tchar.h>
#include "Point.h"
#include "sdafxh.h"

//using namespace std;	
#define	  stop __asm nop
const char* sep = "------------------------------------\n";
#define sep std::cout << std::endl; std::cout<<sep; std::cout << std::endl;

int _tmain(int argc, _TCHAR* argv[])
{
	
///////////////////////////////////////////////////////////////////

	//������� 1. ���������

	//����������� ���������. ����������� set<Point>. ���������, ���
	//����� ����������� � ������ Point. �������� ������, �������� �������� 
	//�������� ������� ��������� set, �� ����������� �� ��������

	std::set<Point> setPoint{ Point(1, 2), Point(4, 3), Point(2, 2), Point(5, 4) };		//������� ���������
	
	PrintContainer(setPoint);															//������� � �������
	sep
	
	std::vector<Point> vecPoint(setPoint.rbegin(), setPoint.rend());					//�� ������ set ������� ������, � �������� ������ ������� rbegin 

	PrintContainer(vecPoint);
	sep


	//��������� ���������. � ������� ostream_iterator �������� ����������
	//vector � set �� ����������� ������� �� �����.
	std::cout << "outputting a set using ostream_iterator" << std::endl;
	std::copy(setPoint.begin(), setPoint.end(), std::ostream_iterator<Point>(std::cout, " "));
	sep
	
	std::cout << "outputting a vector using ostream_iterator" << std::endl;
	std::copy(vecPoint.begin(), vecPoint.end(), std::ostream_iterator<Point>(std::cout, " "));
	sep


		//��������� �������. � ������� ������������ ���������:
		//back_inserter()
		//front_inserter()
		//inserter()
		//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
		//����� �� ���������� ������� ����� ������������ � ������ �����������.

	//back_inserter(),front_inserter �� ������������ ��� ���������

	std::insert_iterator<std::set<Point>> it_insert_set (setPoint, setPoint.begin());
	*it_insert_set = Point(20, 20);
	PrintContainer(setPoint);
	sep

	
	//front_inserter �� ������������ ��� �������
	std::back_insert_iterator<std::vector<Point>> it_back_vec = std::back_inserter(vecPoint);
	*it_back_vec = Point(30, 30);
	PrintContainer(setPoint);
	sep

	std::insert_iterator<std::vector<Point>> it_insert_vec(vecPoint, vecPoint.begin());
	*it_insert_vec = Point(40, 40);
	PrintContainer(setPoint);
	sep
///////////////////////////////////////////////////////////////////

	//������� 2. ���������� ��������� (������������ ���� <algorithm>). ���������.

	// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
	//(������, vector, list...)
	//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
	//������������ �������� ���������
	//��������� : ������� ���������� ������� ���������� ��� ������



	stop

	//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
	//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
	//��� ������) � �������� ��������� � ������� ����������� ���������




	//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
	//��� ��������� �� ������� Point � ��������� ���������.



	
	
	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
	////�� ��������� �������� ��������� ������������������ �� �����������.
	//��� ������ ���� ���������� � ������ Point?
	// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
	//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!
	



	
	//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
	//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
	//[-n, +m].



	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
	//���������� �������������� �� �������� ������ �� ������ ���������.
	






	//{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()


		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
	



		stop
//	}
	
	//{//copy_if
		//��� ������ � ���������� ���� string. � ������� copy_if() ���������
		//������� ������� ������, ������������ � ����� "�" ��� "�", ����� � "�"...
		//��� ���� ������� ����� � �������� ������� ������ �� �����!



		stop

		//��� multimap, ���������� ����: "����� - ���������� ���� � ������"
		//pair<string, int>. � ������� copy_if ����������� ��� map-�: ������ -
		//� ������, ����������� ������ ���������� ����, 2-�� - ��������.
		//std::multimap<string, int> month {
			//{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			//{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			//{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		//};



		stop

		//������������ multimap � map-�, ��������� ���������� ���� ����� ������
		//�������, ��������� �������� ������ ���������� �� ������.
		//��� ����� ������� ������������� ��� ������ ����?


	
		stop
	//}

	return 0;
}

