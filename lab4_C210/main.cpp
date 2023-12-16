// Контейнеры STL: 
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
		std::stack<int> myStack;					//создаем пустой объект стэк
		myStack.push(1);							//задаем значения
		myStack.push(2);
		myStack.push(3);
		std::cout << "Stack: ";

		printAdapterContainer(myStack);				//на консоль 3 2 1
		sep

			std::queue<int> myQueue;					//создаем пустой объект очередь
		myQueue.push(1);							//задаем значения
		myQueue.push(2);
		myQueue.push(3);
		std::cout << "Queue: ";

		printAdapterContainer(myQueue);				//на консоль 1 2 3
		sep

			std::priority_queue<int> myPriorityQueue;
		myPriorityQueue.push(3);
		myPriorityQueue.push(2);
		myPriorityQueue.push(1);
		std::cout << "Priority Queue: ";

		printAdapterContainer(myPriorityQueue);		//на консоль 3 2 1
		sep
	}
	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений

	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 

	std::vector<int> vVector = { 1,2,3,4,5 };							//создаем и инициализируем вектор int
	std::stack<int, std::vector<int>> vStack(vector_inverse(vVector));	//создаем объект стэк, передаем в него вектор возвращенный из функции 
	//vector_inverse  инвертирующий порядок оригинального стэка

	PrintContainer(vVector);											//на консоль 1 2 3 4 5 
	sep
		printAdapterContainer(vStack);										//на консоль 1 2 3 4 5
	sep

		////////////////////////////////////////////////////////////////////////////////////
		//queue

		//Создайте очередь, которая содержит указатели на объекты типа Point,
		//при этом явно задайте базовый контейнер.
		//Измените значения первого и последнего элементов посредством front() и back()
		//Подумайте, что требуется сделать при уничтожении такой очереди?

		std::deque<Point*> vpPoint(5);										//создаем deque эказателей на Point размером пять элементов
	for (size_t i = 0; i < vpPoint.size(); i++)
	{
		vpPoint[i] = new Point(i, i);									//динамически создаем объекты
	}
	std::queue<Point*, std::deque<Point*>> vQueue(vpPoint);				//создаем очередь указателей на Point с базовым классом deque

	printAdapterContainer(vQueue);
	sep

	vQueue.front()->Set_coord(10, 10);									//модифицируем значение первого объекта
	vQueue.back()->Set_coord(20, 20);									//модифицируем значение последнего объекта

	printAdapterContainer(vQueue);										//на консоль 
	sep																	//m_x:10 m_y 20
																		//m_x...	
																		//m_x: 20 m_y: 20 

	while (vQueue.empty())
	{
		delete vQueue.front();											//удаляем объекты Point на которые указывают указатели
		vQueue.pop();													//удаляем сами указатели очереди
	}


	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
	//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
	//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
	//		что сравнивается при вставке?

	const char* ar[] = { "A","B","C","D","E" };
	std::priority_queue<const char*> vPrQueue1(ar, ar + sizeof(ar) / sizeof(ar[0]));
	printAdapterContainer(vPrQueue1);									//на консоль E D C A B
	sep																	//формирование приоритетной очереди некорректное, так стандартный компаратор less сравнивает адреса

	std::priority_queue<const char*, std::vector<const char*>, StringComparator> vPrQueue2(ar, ar + sizeof(ar) / sizeof(ar[0]));
	printAdapterContainer(vPrQueue2);									//на консоль A B C D E
	sep																	//формирование очереди с помощью пользовательского компаратора


	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
	//		в классе Point (и каким образом)
	std::set<Point> vSet1;												//создаем множество
	for (size_t i = 0; i < 5; i++)										//в цикле заполняем объектами типа 	Point,
	{																	//для корректной работы в лкассе Point перегружен оператор <
		vSet1.insert(Point(i, i));
	}
	//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе

	PrintContainer(vSet1);
	sep

	//в) попробуйте изменить любое значение...

	std::set<Point>::iterator it = vSet1.find(Point(0, 0));				//ищем в множестве объект со значениями 1,1, если находим, итератор ставится на найденный элемент
	if (it != vSet1.end())												//в противном случае на конец
	{
		vSet1.erase(it);												//в множестве нельзя изменить значение, найденный элемент вырезается
		vSet1.insert(Point(10, 10));									//вставляется нужный и сортируется заново
	}

	PrintContainer(vSet1);												//на консоль m_x: 1 m_y: 1
	sep																	//m_x:...
																		//m_x: 10 m_y: 10                                                                                                                      

	//г) Создайте два множества, которые будут содержать одинаковые значения
	//		типа int, но занесенные в разном порядке

	std::set<int> vSet2 = { 1,2,3,4,5 };
	std::set<int>vSet3 = { 5,4,3,2,1 };
	if (vSet2 == vSet3)
	{
		std::cout << "Objects are equal";
	}
	sep

	//д) Вставьте в любое множество диапазон элементов из любого другого
	//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?)
	int arInt[] = { 5,4,3,0,-1 };
	vSet2.insert(arInt, arInt + sizeof(arInt) / sizeof(arInt[0]));		//в множество будут занесены значения -1, 0, остальные проигнорированы так как являются дублями

	PrintContainer(vSet2);
	sep


	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое
	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

	std::map<const char*, int> employees;
	employees["Ivanova"] = 50000;
	employees["Petrova"] = 60000;
	employees.insert(std::pair<const char*, int>("Sidorova", 70000));
	employees.insert(std::pair<const char*, int>("Makhankova", 80000));

	PrintAdapterContainer(employees);
	sep

	//д) Сформируйте любым способом вектор с элементами типа string.
	//Создайте (и распечатайте для проверки) map<string, int>, который будет
	//содержать упорядоченные по алфавиту строки и
	//количество повторений каждой строки в векторе

	std::vector<std::string> vString = { "Aleksei","Boris","Aleksei","Boris","Aleksei","Dmitrii" };	//создаем вектор <string>
	std::map<std::string, int> countMap1;															//создаем ассоциативный контейнер
	
	for (size_t i = 0; i < vString.size(); i++)
	{
		countMap1[vString[i]]++;																	//на каждой итерации проверяем ключ(vString[i]), если совпадений не найдено вернется 0
	}																								//если совпадение найдено возвращается 1, значение не заносится, инкрементируем для подсчета
																									//совпадающих строк
	PrintAdapterContainer(countMap1);
	sep
	
	//е) 
	//задан массив:
	//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
	//создайте map, в котором каждой букве будет соответствовать совокупность 
	//лексиграфически упорядоченных слов, начинающихся с этой буквы. 
	//Подсказка: не стоит хранить дубли одной и той же строки
	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"  ...
	//...
	{
	const char* words[] = { "Abba", "Alfa", "Beta", "Beauty"};				//массив строк
	std::map<char,std::vector<std::string>> mapWords1;						//ассоциативный контейнер с ключом char и базовым контейнером vector<string>
	for (size_t i = 0; i < sizeof(words)/sizeof(words[0]); i++)				//в цикле пробегаем по массиву
	{
		std::string str(words[i]);											//создаем строку и передаем i-й элемент массива
		if (mapWords1.find(str[0])==mapWords1.end())						//если такого ключа не нашли
		{
			mapWords1[str[0]] = std::vector<std::string>{ str };			//инстанцируем объект
		}
		else																//если ключ есть проверяем на дубли в векторе
		{
			bool isDuplicate = false;										//флаг на дубли
			std::vector<std::string>& tmp = mapWords1[str[0]];				//указатель на вектор по ключу
			std::vector<std::string>::iterator itStr = tmp.begin();			//итератор
			for (; itStr != tmp.end(); ++itStr)								//в цикле перебираем значения вектора
			{
				if (*itStr==str)											//если дубль найден
				{
					isDuplicate = true;										//поднимаем флаг
					break;													//выходим из цикла
				}
				else if (*itStr>str)										//если дубля нет и значение меньше
				{
					tmp.insert(itStr, str);									//вставляем значение
					isDuplicate = true;										//поднимаем флаг
					break;													//выходим из цикла
				}
			}
			if (!isDuplicate)												//если флаг не поднят, дублей нет и значение было больше искомых
			{
				tmp.push_back(str);											//вставляем значение в конец
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


	//ж)
	//создайте структуру данных, которая будет хранить информацию о студенческих группах.
	//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
	//фамилии могут дублироваться
	//Сами группы тоже должны быть упорядочены по номеру
	//
	//номера 
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
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()






			stop

			return 0;
	}

