// set.cpp
#include <iostream>
#include <set>
#include <string>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	// Массив строковых объектов
    wstring names[] = {L"Juanita", L"Robert", L"Mary", L"Amanda", L"Marie" };
	// Инициализировать
   // множество массивом
	set<wstring, less<wstring> > nameSet(names, names + 5);
	// итератор для множества
	set<wstring, less<wstring> >::iterator iter;
	nameSet.insert(L"Yvette"); // вставка элементов
	nameSet.insert(L"Larry");
	nameSet.insert(L"Robert"); // никакого эффекта: такой
	// элемент уже имеется
	nameSet.insert(L"Barry");
	nameSet.erase(L"Mary"); // удаление элемента
	// вывод размера множества
	wcout << L"\nРазмер =" << nameSet.size() << endl;
	iter = nameSet.begin(); // вывод элементов множества
	while (iter != nameSet.end())
		wcout << *iter++ << '\n';
	wstring searchName; // получение искомого имени от
	// пользователя
	wcout << L"\nВведите искомое имя: ";
	wcin >> searchName;
	// поиск соответствующего
   // запросу имени
	iter = nameSet.find(searchName);
	if (iter == nameSet.end())
		wcout << L"Имя " << searchName << L" ОТСУТСТВУЕТ во множестве." << endl;
	else
		wcout << L"Имя " << *iter << L" ПРИСУТСТВУЕТ во множестве." << endl;
	set<wstring, less<wstring> > organic;
	// итератор множества
	set<wstring, less<wstring> >::iterator iter1;
	organic.insert(L"Curine"); // вставка компонентов класса
	// organic
	organic.insert(L"Xanthine");
	organic.insert(L"Curarine");
	organic.insert(L"Melamine");
	organic.insert(L"Cyanimide");
	organic.insert(L"Phenol");
	organic.insert(L"Aphrodine");
	organic.insert(L"Imidazole");
	organic.insert(L"Cinchonine");
	organic.insert(L"Palmitamide");
	organic.insert(L"Cyanimide");
	iter1 = organic.begin(); // вывод множества
	while (iter1 != organic.end())
		wcout << *iter1++ << '\n';
	wstring lower, upper; // вывод значений из диапазона
	wcout << L"\nВведите диапазон (например, C Czz): ";
	wcin >> lower >> upper;
	iter1 = organic.lower_bound(lower);
	while (iter1 != organic.upper_bound(upper))
		wcout << *iter1++ << '\n';
	wcout << endl;
	return 0;
}

