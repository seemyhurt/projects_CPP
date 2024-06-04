// list.cpp
// демонстрация методов push_front(), front(), pop_front()
#include <iostream>
#include <list>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	list<int> ilist;
	ilist.push_back(30); // вставка элементов в конец
	ilist.push_back(40);
	ilist.push_front(20); // вставка элементов в начало
	ilist.push_front(10);
    auto size = ilist.size(); // число элементов
	for (int j = 0; j < size; j++)
	{
		wcout << ilist.front() << ' '; // читать данные
		// из начала
		ilist.pop_front(); // извлечение данных из начала
	}
	wcout << endl;

	int j;
	list<int> list1, list2;
	int arr1[] = { 40, 30, 20, 10 };
	int arr2[] = { 15, 20, 25, 30, 35 };
	for (j = 0; j < 4; j++)
		list1.push_back(arr1[j]); // list1: 40, 30, 20, 10
	for (j = 0; j < 5; j++)
		list2.push_back(arr2[j]); // list2: 15, 20, 25, 30, 35
	list1.reverse(); // перевернуть list1: 10 20 30 40
	list1.merge(list2); // объединить list2 с list1
	list1.unique(); // удалить повторяющиеся элементы 20 и 30

	while (!list1.empty())
	{
		wcout << list1.front() << ' '; // читать элемент из начала
		list1.pop_front(); // вытолкнуть элемент из начала
	}
	wcout << endl;
	return 0;
}
