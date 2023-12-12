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
	Shape();																		//конструктор по умолчанию
	Shape(COLOR c);																	//конструткор с параметрами
	virtual ~Shape();																//виртуальный деструктор
	virtual Shape& operator=(const Shape& other);											//оператор присваивания
	virtual bool operator==(const Shape& other)const;								//перегруженный оператор сравнения на равенство
	virtual double Scale() const = 0;												//чисто виртуальная функция расчета площади
	virtual COLOR GetColor()const;													//гетр для получения цвета
	virtual Shape* ShapeCopy() const = 0;											//чисто вирутальная функция для получения копии нужной фигуры
	const char* GetShapeColor() const;												//гетр для полчуения цвета в текстовом формате
	virtual void PrintData(std::ostream& os) const;									//метод для вывода данных класса в поток
	virtual void Read(std::istream& is);											//метод для чтения данных из потока
	friend std::ostream& operator<< (std::ostream & os, const Shape & oter);		//перегруженная функция вывода в поток
	friend std::istream& operator>>(std::istream& in, Shape& other);				//перегруженная функция чтения из потока

};
