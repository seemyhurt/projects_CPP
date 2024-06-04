#include <iostream>
#include <vector>
#include <algorithm>
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
public:
	person() : // конструктор по умолчанию
        lastName(L"пусто"), firstName(L"пусто"), phoneNumber(0L)
	{ }
	// конструктор с тремя аргументами
    person(wstring lana, wstring fina, long pho) :
		lastName(lana), firstName(fina), phoneNumber(pho)
	{ }
	friend bool operator<(const person&, const person&);
	friend bool operator==(const person&, const person&);
	void display() const // вывод персональных данных
	{
        wcout << endl << lastName << L",\t" << firstName
            << L"\t\tТелефон: " << phoneNumber;
	}
    long get_phone() const // вернуть телефонный номер
	{
		return phoneNumber;
	}
}; // end class person
//---------------------------------------------------------
// перегруженный < для класса person
bool operator<(const person& p1, const person& p2)
{
	if (p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}
//---------------------------------------------------------
// перегруженный == для класса person
bool operator==(const person& p1, const person& p2)
{
	return (p1.lastName == p2.lastName &&
		p1.firstName == p2.firstName) ? true : false;
}
//---------------------------------------------------------
// функциональный объект для сравнивания содержимого
// указателей на объекты person
class comparePersons
{
public:
	bool operator()(const person* ptrP1,
		const person* ptrP2) const
	{
		return *ptrP1 < *ptrP2;
	}
};
//---------------------------------------------------------
// функциональный объект для вывода персональных данных,
// хранимых в указателях
class displayPerson
{
public:
	void operator()(const person* ptrP) const
	{
		ptrP->display();
	}
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    // вектор указателей на объекты person
	vector<person*> vectPtrsPers;
	// создание персональных данных
    person* ptrP1 = new person(L"KuangThu", L"Bruce", 4157300);
    person* ptrP2 = new person(L"Deauville", L"William", 8435150);
    person* ptrP3 = new person(L"Wellington", L"John", 9207404);
    person* ptrP4 = new person(L"Bartoski", L"Peter", 6946473);
    person* ptrP5 = new person(L"Fredericks", L"Roger", 7049982);
    person* ptrP6 = new person(L"McDonald", L"Stacey", 7764987);
	vectPtrsPers.push_back(ptrP1); // внесение данных во
	// множество
	vectPtrsPers.push_back(ptrP2);
	vectPtrsPers.push_back(ptrP3);
	vectPtrsPers.push_back(ptrP4);
	vectPtrsPers.push_back(ptrP5);
	vectPtrsPers.push_back(ptrP6);
	for_each(vectPtrsPers.begin(),// вывод вектора
		vectPtrsPers.end(), displayPerson());
	// сортировка указателей
	sort(vectPtrsPers.begin(), vectPtrsPers.end());
    wcout << L"\n\nУпорядочены указатели:";
	for_each(vectPtrsPers.begin(),// вывод вектора
		vectPtrsPers.end(), displayPerson());
	sort(vectPtrsPers.begin(), // сортировка реальных данных
		vectPtrsPers.end(), comparePersons());
    wcout << L"\n\nУпорядочены персональные данные:";
	for_each(vectPtrsPers.begin(),// вывод вектора
		vectPtrsPers.end(), displayPerson());
	while (!vectPtrsPers.empty())
	{
		delete vectPtrsPers.back();// удаление персоны
		vectPtrsPers.pop_back(); // выталкивание указателя
	}
	wcout << endl;
	return 0;
} // конец main()
