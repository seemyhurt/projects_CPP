#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int n;
    unsigned long long factorial = 1;
    wcout << L"Введите число: ";
    cin >> n;
    if (n <= 0)
        wcout << L"Для данного числа нет факториала" << endl;
    else
    {
        for (int i = 1; i <= n; ++i)
            factorial = factorial * i;
        wcout << n << L"! = " << factorial << endl;
    }

    for (int i = 1; i <= 10; ++i)
    {
        for (int j = 1; j <= 10; ++j)
            wcout << j * i << '\t';
        wcout << endl;
    }
    return 0;
}

