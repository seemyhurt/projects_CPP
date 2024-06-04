// listpers.cpp
// Использование списка для хранения объектов person
#include <iostream>
#include <list>
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
	person() : // конструктор без аргументов
		lastName(L"пусто"), firstName(L"пусто"), phoneNumber(0L)
	{ }
	// конструктор с тремя аргументами
	person(wstring lana, wstring fina, long pho) :
		lastName(lana), firstName(fina), phoneNumber(pho)
	{ }
	friend bool operator<(const person&, const person&);
	friend bool operator==(const person&, const person&);
	friend bool operator!=(const person&, const person&);
	friend bool operator>(const person&, const person&);
	void display() const // вывод всех данных
	{
		wcout << endl << lastName << L",\t" << firstName
			<< L"\t\tТелефон: " << phoneNumber;
	}
	long get_phone() const // вернуть номер телефона
	{
		return phoneNumber;
	}
};
// перегруженный == для класса person
bool operator==(const person& p1, const person& p2)
{
	return (p1.lastName == p2.lastName &&
		p1.firstName == p2.firstName) ? true : false;
}
// перегруженный < для класса person
bool operator<(const person& p1, const person& p2)
{
	if (p1.lastName == p2.lastName)
		return (p1.firstName < p2.firstName) ? true : false;
	return (p1.lastName < p2.lastName) ? true : false;
}
// перегруженный != для класса person
bool operator!=(const person& p1, const person& p2)
{
	return !(p1 == p2);
}
// перегруженный > для класса person
bool operator>(const person& p1, const person& p2)
{
	return !(p1 < p2) && !(p1 == p2);
}
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	list<person> persList; // список объектов типа person
	// итератор для этого списка
	list<person>::iterator iter1;
	// занести объекты в список
    persList.push_back(person(L"Deauville", L"William", 8435150));
    persList.push_back(person(L"McDonald", L"Stacey", 3327563));
    persList.push_back(person(L"Bartoski", L"Peter", 6946473));
    persList.push_back(person(L"KuangThu", L"Bruce", 4157300));
    persList.push_back(person(L"Wellington", L"John", 9207404));
    persList.push_back(person(L"McDonald", L"Amanda", 8435150));
    persList.push_back(person(L"Fredericks", L"Roger", 7049982));
    persList.push_back(person(L"McDonald", L"Stacey", 7764987));
	wcout << L"\nЧисло записей: " << persList.size();
	iter1 = persList.begin(); // вывод содержимого списка
	while (iter1 != persList.end())
		(*iter1++).display();
	// найти информацию о людях с именами
	// и фамилиями, указанными в запросе
	wstring searchLastName, searchFirstName;
	wcout << L"\n\nВведите фамилию искомого человека: ";
    wcin >> searchLastName;
	wcout << L"Введите имя: ";
    wcin >> searchFirstName;
	// создать персону с таким именем
	person searchPerson(searchLastName, searchFirstName, 0L);
	// поиск по листу первого вхождения искомого значения
	iter1 = find(persList.begin(), persList.end(), searchPerson);
	if (iter1 != persList.end()) // поиск следующих совпадений
	{
		wcout << L"Есть такой человек (такие люди) в списке: ";
		do
		{
			(*iter1).display(); // вывод найденных записей
			++iter1; // продолжение поиска со следующей записи
			iter1 = find(iter1, persList.end(), searchPerson);
		} while (iter1 != persList.end());
	}
	else
		wcout << L"Человек с таким именем отсутствует в списке.";
	// найти человека по номеру телефона
	wcout << L"\n\nВведите номер телефона (формат 1234567): ";
	long sNumber; // получить искомый номер
    wcin >> sNumber;
	// итерация по списку
	bool found_one = false;
	for (iter1 = persList.begin(); iter1 != persList.end(); ++iter1)
	{
		if (sNumber == (*iter1).get_phone()) // сравнить
			// номера
		{
			if (!found_one)
			{
				wcout << L"Есть человек (или несколько) с таким номером телефона.";
				found_one = true;
			}
			(*iter1).display(); // display the match
		}
	} // end for
	if (!found_one)
		wcout << L"Человек с таким номером телефона отсутствует в списке";
	wcout << endl;
	return 0;
} // end main()
