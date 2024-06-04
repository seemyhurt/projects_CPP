#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    const int numsToCalculate = 5;
    wcout << L"Вычисление по" << numsToCalculate << L"чисел Фибоначчи" << endl;
    int num1 = 0, num2 = 1;
    wchar_t wantmore = {'\0'};
    do
    {
        for (int counter = 0; counter < numsToCalculate; ++counter)
        {
            wcout << num1 + num2 << " ";
            int num2Temp = num2;
            num2 = num1 + num2;
            num1 = num2Temp;
        }
        wcout << endl << L"Продолжать? (y/n) ";
        wcin >> wantmore;

    } while (wantmore == 'y');

    wcout << L"До свидания! " << endl;
    return 0;
}

