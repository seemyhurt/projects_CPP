// salemon.cpp
// показ графика продаж
#include <iostream>
#include <iomanip>
#include <clocale>
#include <windows.h>
using namespace std;

const int DISTRICTS = 4;
const int MONTHS = 3;
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int d, m;
    double sales[DISTRICTS][MONTHS];

    for (d = 0; d < DISTRICTS; d++)
        for (m = 0; m < MONTHS; m++)
        {
            wcout << L"Введите объем продаж для отдела " << d + 1;
            wcout << L", за месяц " << m + 1 << L": ";
            wcin >> sales[d][m];
        }

    wcout << L"\n\n";
    wcout << L"                        Месяц\n";
    wcout << L"                1         2         3";
    for (d = 0; d < DISTRICTS; d++)
    {
        wcout << L"\nОтдел " << d + 1;
        for (m = 0; m < MONTHS; m++)
            // нормальный неэкспоненциальный вид
            // всегда показывать десятичную точку
            // два знака после запятой
            // ширина вывода в 10 символов
            // само число
            wcout << setiosflags(ios::fixed)
            << setiosflags(ios::showpoint)
            << setprecision(2)
            << setw(10)
            << sales[d][m];
    }
    wcout << endl;

    return 0;
}
