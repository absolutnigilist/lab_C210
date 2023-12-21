// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <tchar.h>
#include "Point.h"
#include "sdafxh.h"
#include "Functors.h"



const char* sep = "------------------------------------\n";
#define sep std::cout << std::endl; std::cout<<sep; std::cout << std::endl;


#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	
///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию

	std::set<Point> setPoint{ Point(1, 2), Point(4, 3), Point(2, 2), Point(5, 4) };		//создаем контейнер
	
	PrintContainer(setPoint);															//выводим в консоль
	sep
	
	std::vector<Point> vecPoint(setPoint.rbegin(), setPoint.rend());					//на основе set создаем вектор, в качестве начала вектора rbegin 

	PrintContainer(vecPoint);
	sep


	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.
	std::cout << "outputting a set using ostream_iterator" << std::endl;
	std::copy(setPoint.begin(), setPoint.end(), std::ostream_iterator<Point>(std::cout, " "));
	sep
	
	std::cout << "outputting a vector using ostream_iterator" << std::endl;
	std::copy(vecPoint.begin(), vecPoint.end(), std::ostream_iterator<Point>(std::cout, " "));
	sep


	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.

	//back_inserter(),front_inserter не используется для множества

	std::insert_iterator<std::set<Point>> it_insert_set (setPoint, setPoint.begin());
	*it_insert_set = Point(20, 20);
	PrintContainer(setPoint);
	sep

	
	//front_inserter не используется для вектора
	std::back_insert_iterator<std::vector<Point>> it_back_vec = std::back_inserter(vecPoint);
	*it_back_vec = Point(30, 30);
	PrintContainer(setPoint);
	sep

	std::insert_iterator<std::vector<Point>> it_insert_vec(vecPoint, vecPoint.begin());
	*it_insert_vec = Point(40, 40);
	PrintContainer(setPoint);
	sep

		///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон

	int ar[] = { 1,2,3,4,5 };
	std::vector<int> int_vector(ar, ar+sizeof(ar) / sizeof(ar[0]));
	std::list<int> int_list(ar, ar + sizeof(ar) / sizeof(ar[0]));

	
	std::for_each(ar, ar+sizeof(ar)/sizeof(ar[0]),print<int>);
	sep
	std::for_each(int_vector.begin(), int_vector.end(), print<int>);
	sep
	std::for_each(int_list.begin(), int_list.end(), print<int>);
	sep
	{
	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката
	std::vector<Point> vecPoint{ {1, 2}, { 2,3 }, { 3,4 }};

	std::for_each(vecPoint.begin(), vecPoint.end(), ChangeElements<int>(10,10));
	std::for_each(vecPoint.begin(), vecPoint.end(), print<Point>);
 	sep
	}

	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
	{
		std::list<Point> list;																		//контейнер для хранения совпадающих элементов
		std::vector<Point> vecPoint{ {1, 2}, { 2,3 }, { 1,2 },{3,4} };								//искомый вектор типа Point
		std::vector<Point>::iterator it = std::find(vecPoint.begin(), vecPoint.end(), Point(1, 2));	//с помощью find() находим итератор с совпадающим элементом
		while (it != vecPoint.end())																//пробегаем до конца вектора если find() вернул не 0
		{	
			list.push_back(*it);																	//добавляем элемент в лист
			it = std::find(++it, vecPoint.end(), Point(1, 2));										//смещаем итератор и ищем совпадения
		}
		stop

	}
	
	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	{
		Point ar[] = { {1, 2}, { 2,3 }, { 1,2 },{3,4} };											//массив элементов типа Point									
		std::vector<Point> vecPoint{ {1, 2}, { 2,3 }, { 1,2 },{3,4} };								//контейнер для хранения совпадающих элементов
		
		std::sort(ar, ar + sizeof(ar) / sizeof(ar[0]));
		std::sort(vecPoint.begin(), vecPoint.end());
		stop
	}

	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].
	/* {
		std::list<Point> list;																		//контейнер для хранения совпадающих элементов
		std::vector<Point> vecPoint{ {1, 2}, { 2,3 }, { 1,2 },{3,4} };
		std::vector<Point>::iterator it = std::find_if(vecPoint.begin(), vecPoint.end(), SurсheElements(2,3));	//с помощью find() находим итератор с совпадающим элементом
		while (it != vecPoint.end())																//пробегаем до конца вектора если find() вернул не 0
		{
			list.push_back(*it);																	//добавляем элемент в лист
			it = std::find(++it, vecPoint.end(), Point(1, 2));										//смещаем итератор и ищем совпадения
		}
		stop
	
	}*/


	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	






	//{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()


		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
	



		stop
//	}
	
	//{//copy_if
		//Дан вектор с элементами типа string. С помощью copy_if() требуется
		//вывести сначала строки, начинающиеся с буквы "А" или "а", затем с "Б"...
		//При этом порядок строк в исходном векторе менять не нужно!



		stop

		//Дан multimap, содержаций пары: "месяц - количество денй в месяце"
		//pair<string, int>. С помощью copy_if сформируйте ДВА map-а: первый -
		//с парами, содержащими четное количество дней, 2-ой - нечетное.
		//std::multimap<string, int> month {
			//{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			//{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			//{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		//};



		stop

		//Распечатайте multimap и map-ы, используя написанный вами ранее шаблон
		//функции, выводящей элементы ЛЮБОГО контейнера на печать.
		//Что нужно сделать дополнительно для вывода пары?


	
		stop
	//}

	return 0;
}

