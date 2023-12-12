#pragma once
#include <iostream>
#include <fstream>

//enum COLOR{ RED, GREEN, BLUE, YELLOW, BLACK, WHITE }; //

class Shape{
public:
	enum COLOR { RED, GREEN, BLUE, YELLOW, BLACK, WHITE };
protected:
	
	COLOR m_color;

public:
	Shape();																		//����������� �� ���������
	Shape(COLOR c);																	//����������� � �����������
	virtual ~Shape();																//����������� ����������
	virtual Shape& operator=(const Shape& other);											//�������� ������������
	virtual bool operator==(const Shape& other)const;								//������������� �������� ��������� �� ���������
	virtual double Scale() const = 0;												//����� ����������� ������� ������� �������
	virtual COLOR GetColor()const;													//���� ��� ��������� �����
	virtual Shape* ShapeCopy() const = 0;											//����� ����������� ������� ��� ��������� ����� ������ ������
	const char* GetShapeColor() const;												//���� ��� ��������� ����� � ��������� �������
	virtual void PrintData(std::ostream& os) const;									//����� ��� ������ ������ ������ � �����
	virtual void Read(std::istream& is);											//����� ��� ������ ������ �� ������
	friend std::ostream& operator<< (std::ostream & os, const Shape & oter);		//������������� ������� ������ � �����
	friend std::istream& operator>>(std::istream& in, Shape& other);				//������������� ������� ������ �� ������

};
