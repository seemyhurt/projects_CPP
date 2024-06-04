#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int addNumbers(int num);
long int factor(int num);
int nod(int num1, int num2);
void revrseStr();
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int num;
    wcout << L"Введите число: ";
	cin >> num;
    wcout << L"Сумма " << num << L" натуральных чисел: " << addNumbers(num) << endl;
    wcout << L"Факториал " << num << L": " << factor(num) << endl;
	int num2;
    wcout << L"Введите второе число: ";
	cin >> num2;
    wcout << L"Наибольший общий делитель чисел " << num << L" и " << num2 << L": " << nod(num, num2) << endl;
    wcout << L"Введите строку: ";
	revrseStr();
    wcout << '\n';
	return 0;
}

int addNumbers(int num)
{
	if (num != 0)
		return num + addNumbers(num - 1);
	else
		return num;
}

long int factor(int num)
{
	if (num >= 1)
		return num * factor(num - 1);
	else
		return 1;
}

int nod(int num1, int num2)
{
	if (num2 != 0)
		return nod(num2, num1 % num2);
	else
		return num1;
}

void revrseStr()
{
	char c;
	cin >> c;
	if (c != '\n')
	{
		revrseStr();
        wcout << c;
	}
}
