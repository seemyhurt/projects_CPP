#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wcout << L"Введите два числа: " << endl;
    int num1 = 0, num2 = 0;
    wcin >> num1;
    wcin >> num2;

    int max = (num1 > num2) ? num1 : num2; // ? - условие для true. : - условие для false в переменной max
    wcout << L"Большее из " << num1 << L" и " << num2 << L" это " << max << endl;
    return 0;
}
