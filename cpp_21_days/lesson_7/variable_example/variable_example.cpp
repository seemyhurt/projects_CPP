#include <iostream>
#include <windows.h>

using namespace std;

/*Объявление глобальных переменных*/
int firstNumber = 0, secondNumber = 0, multiplication = 0;
void multiply()
{
    // Область видимости переменной - функция
    wcout << L"Введите первое число: ";
    firstNumber = 0;
    wcin >> firstNumber;

    wcout << L"Введите второе число: ";
    secondNumber = 0;
    wcin >> secondNumber;

    multiplication = firstNumber * secondNumber;
    wcout << L"Вывод из функции" << endl;
    wcout << firstNumber << " x " << secondNumber;
    wcout << L" = L" << multiplication << endl;

}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wcout << L"Программа для умножения двух чисел" << endl;
    multiply();

    wcout << L"Вывод из main()" << endl;
    wcout << firstNumber << " x " << secondNumber;
    wcout << L" = L" << multiplication << endl;

    return 0;

}

