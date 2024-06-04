#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int year;
    wcout << L"Введите год: ";
    cin >> year;
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                wcout << year << L" - високосный год" << endl;
            else
                wcout << year << L" - невисокосный год" << endl;
        }
        else
            wcout << year << L" - високосный год" << endl;
    }
    else
        wcout << year << L" - невисокосный год" << endl;

    int number;
    wcout << L"Введите число: ";
    cin >> number;
    if (number > 0)
        wcout << L"Вы ввели положительное число" << endl;
    else if(number<0)
        wcout << L"Вы ввели отрицательное число" << endl;
    else
        wcout << L"Вы ввели 0" << endl;

    int n, sum=0;
    wcout << L"Введите число: ";
    cin >> n;
    for (int i = 1; i <= n; ++i)
        sum += i;
    wcout << L"Сумма натуральных чисел от 1 до " << n << L" равна " << sum << endl;

    char sim;
    wcout << L"Введите символ: ";
    cin >> sim;
    if (sim >= 'a' && sim <= 'z' || sim >= 'A' && sim <= 'Z')
        wcout << L"Символ алфавитный" << endl;
    else
        wcout << L"Символ не алфавитный" << endl;
    return 0;
}

