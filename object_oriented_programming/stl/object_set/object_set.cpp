// setpers.cpp
#include <iostream>
#include <set>
#include <string>
#include <clocale>
#include <windows.h>

using namespace std;

class person
{
private:
	wstring lastName;
	wstring firstName;
	long phoneNumber;
public: // конструктор по умолчанию
	person() : lastName(L"пусто"),
		firstName(L"пусто"), phoneNumber(0)
	{ }
	// конструктор с тремя параметрами
	person(wstring lana, wstring fina, long pho) :
		lastName(lana), firstName(fina), phoneNumber(pho)
	{ }
	friend bool operator<(const person&, const person&);
	friend bool operator==(const person&, const person&);
	void display() const // вывод данных о людях
	{
		wcout << endl << lastName << L",\t" << firstName
			<< L"\t\tТелефон: " << phoneNumber;
	}
};
// оператор < для класса person
bool operator<(const person& p1, const person& p2)
{
	if (p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}
// оператор == для класса person
bool operator==(const person& p1, const person& p2)
{
	return (p1.lastName == p2.lastName &&
		p1.firstName == p2.firstName) ? true : false;
}
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	// создание объектов person
    person pers1(L"Deauville", L"William", 8435150);
    person pers2(L"McDonald", L"Stacey", 3327563);
    person pers3(L"Bartoski", L"Peter", 6946473);
    person pers4(L"KuangThu", L"Bruce", 4157300);
    person pers5(L"Wellington", L"John", 9207404);
    person pers6(L"McDonald", L"Amanda", 8435150);
    person pers7(L"Fredericks", L"Roger", 7049982);
    person pers8(L"McDonald", L"Stacey", 7764987);
	// мультимножество класса person
	multiset< person, less<person> > persSet;
	// итератор этого мультимножества
	multiset<person, less<person> >::iterator iter;
	// занести объекты person в мультимножество
	persSet.insert(pers1);
	persSet.insert(pers2);
	persSet.insert(pers3);
	persSet.insert(pers4);
	persSet.insert(pers5);
	persSet.insert(pers6);
	persSet.insert(pers7);
	persSet.insert(pers8);
	wcout << L"\nЧисло записей: " << persSet.size();
	iter = persSet.begin(); // Вывод содержимого мультимножества
	while (iter != persSet.end())
		(*iter++).display();
	// получение имени и фамилии
	wstring searchLastName, searchFirstName;
	wcout << L"\n\nВведите фамилию искомого человека: ";
	wcin >> searchLastName;
	wcout << L"Введите имя: ";
	wcin >> searchFirstName;
	// создание объекта с заданными значениями атрибутов
	person searchPerson(searchLastName, searchFirstName, 0);
	// сосчитать количество людей с таким именем
    auto cntPersons = persSet.count(searchPerson);
	wcout << L"Число людей с таким именем: " << cntPersons;
	// вывести все записи, отвечающие запросу
	iter = persSet.lower_bound(searchPerson);
	while (iter != persSet.upper_bound(searchPerson))
		(*iter++).display();
	wcout << endl;
	return 0;
} // end main()
