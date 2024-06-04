// plusair.cpp
// использование алгоритма accumulate() и функционального объекта plus()
#include <iostream>
#include <clocale>
#include <list>
#include <numeric> // для accumulate()
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class airtime
{
private:
	int hours; // от 0 до 23
	int minutes; // от 0 до 59
public:
	// конструктор по умолчанию
	airtime() : hours(0), minutes(0)
	{ }
	// конструктор с двумя аргументами
	airtime(int h, int m) : hours(h), minutes(m)
	{ }
	void display() const // вывод на экран
	{
		wcout << hours << ':' << minutes;
	}
	void get() // ввод данных пользователем
	{
		wchar_t dummy;
		wcout << L"\nВведите время (формат 12:59): ";
		wcin >> hours >> dummy >> minutes;
	}
	// перегружаемая операция +
	airtime operator+(const airtime right) const
	{ // добавить компоненты
		int temph = hours + right.hours;
		int tempm = minutes + right.minutes;
		if (tempm >= 60) // проверка наличия переноса
		{
			temph++; tempm -= 60;
		}
		return airtime(temph, tempm); // возврат суммы
	}
	// перегруженный оператор ==
	bool operator==(const airtime& at2) const
	{
		return (hours == at2.hours) &&
			(minutes == at2.minutes);
	}
	// перегруженный оператор <
	bool operator<(const airtime& at2) const
	{
		return (hours < at2.hours) ||
			(hours == at2.hours && minutes < at2.minutes);
	}
	// перегружаемая операция !=
	bool operator!=(const airtime& at2) const
	{
		return !(*this == at2);
	}
	// перегружаемая операция >
	bool operator>(const airtime& at2) const
	{
		return !(*this < at2) && !(*this == at2);
	}
}; // конец класса airtime
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	wchar_t answer;
	airtime temp, sum;
	list<airtime> airlist; // список типа airtime
	do { // получить значения от пользователя
		temp.get();
		airlist.push_back(temp);
		wcout << L"Продолжить (y/n)? ";
		wcin >> answer;
	} while (answer != 'n');
	// суммировать все элементы
	sum = accumulate(airlist.begin(), airlist.end(),
		airtime(0, 0), plus<airtime>());
	wcout << L"\nСумма = L";
	sum.display(); // вывод суммы на экран
	wcout << endl;
	return 0;
}
