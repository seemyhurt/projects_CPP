#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int rows;
    wcout << L"Введите количество строк: ";
    cin >> rows;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            wcout << L"* ";
        }
        wcout << endl;
    }
    char oper;
    int firstNum, secondNum;
    wcout << L"Введите два числа: ";
    cin >> firstNum >> secondNum;
    wcout << L"Введите действие (+, -, /, *) ";
    cin >> oper;
    switch (oper)
    {
    case('+'):
        wcout << firstNum << L" + " << secondNum << L" = " << firstNum + secondNum << endl;
        break;
    case('-'):
        wcout << firstNum << L" - " << secondNum << L" = " << firstNum - secondNum << endl;
        break;
    case('/'):
        wcout << firstNum << L" / " << secondNum << L" = " << firstNum / secondNum << endl;
        break;
    case('*'):
        wcout << firstNum << L" * " << secondNum << L" = " << firstNum * secondNum << endl;
        break;
    default:
        wcout << L"Оператор неизвестен!" << endl;
    }
    return 0;
}
