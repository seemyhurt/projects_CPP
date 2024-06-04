#include <clocale>
#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int n, t1 = 0, t2 = 1, nextTerm = 0;
    wcout << L"Введите количество элементов последовательности: ";
    cin >> n;
    wcout << L"Последовательность Фибоначчи: " << endl;
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
        {
            wcout << t1 << '\t';
            continue;
        }
        if (i == 2)
        {
            wcout << t2 << '\t';
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        wcout << nextTerm << '\t';
    }

    int num1, num2, gcd=1;
    wcout << endl << L"Введите два числа: ";
    cin >> num1 >> num2;
    num1 = (num1 > 0) ? num1 : -num1;
    num2 = (num2 > 0) ? num2 : -num2;
    for (int i = 1; i <= num1 && i <= num2; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
            gcd = i;
    }
    wcout << L"НОД двух чисел равен " << gcd << endl;
    while (num1 != num2)
    {
        if (num1 > num2)
            num1 -= num2;
        else
            num2 -= num1;
    }
    wcout << L"НОД двух чисел равен " << num1 << endl;
    return 0;
}

