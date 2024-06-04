#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

	int num1, num2, NOK;
    wcout << L"Введите два числа: ";
	cin >> num1 >> num2;
	NOK = (num1 > num2) ? num1 : num2;
	while (1)
	{
		if (NOK % num1 == 0 && NOK % num2 == 0)
		{
            wcout << L"Наименьшее общее кратное " << NOK << endl;
			break;
		}
		++NOK;
	}
	long num3;
	int count=0;
    wcout << L"Введите число: ";
	cin >> num3;
	while (num3 != 0)
	{
		num3 /= 10;
		count++;
	}
    wcout << L"Количество цифр в числе: " << count << endl;
	return 0;
}
