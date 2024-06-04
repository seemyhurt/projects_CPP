#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
struct student
{
	char name[50];
	int roll;
	int group;
}s;
struct Distance
{
	int feet;
	float m;
}d1, d2, sum;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wcout << L"Введите информацию: " << endl;
    wcout << L"Имя: ";
	cin >> s.name;
    wcout << L"Номер билета: ";
	cin >> s.roll;
    wcout << L"Номер группы: ";
	cin >> s.group;
    wcout << L"Выводим информацию: " << endl;
    wcout << L"Имя: " << s.name << endl;
    wcout << L"Номер билета: " << s.roll << endl;
    wcout << L"Номер группы: " << s.group << endl;

    wcout << L"Заполняем первую структуру: " << endl;
    wcout << L"Количество шагов: ";
	cin >> d1.feet;
    wcout << L"Количество метров: ";
	cin >> d1.m;
    wcout << L"Заполняем вторую стркуктуру: " << endl;
    wcout << L"Количество шагов: ";
	cin >> d2.feet;
    wcout << L"Количество метров: ";
	cin >> d2.m;
	sum.feet = d1.feet + d2.feet;
	sum.m = d1.m + d2.m;
    wcout << L"Результат" << endl;
    wcout << L"Шаги: " << sum.feet << endl;
    wcout << L"Метры: " << sum.m << endl;
	return 0;
}

