#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
bool checkSimpleNum(int num);
bool checkArmNum(int num);
void separator();
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int num;
    bool flag = false;
    wcout << L"Введите целое число: ";
    cin >> num;
    flag = checkSimpleNum(num);
    if (flag)
        wcout << L"Число " << num << L" простое" << endl;
    else
        wcout << L"Число " << num << L" не является простым" << endl;
    flag = checkArmNum(num);
    if (flag)
        wcout << L"Число " << num << L" является числом Армстронга" << endl;
    else
        wcout << L"Число " << num << L" не является числом Армстронга" << endl;
    flag = true;
    for (int i = 0; i <= num/2; i++)
        if (checkSimpleNum(i))
            if (checkSimpleNum(num - i))
            {
                wcout << L"Число может быть выражено как сумма двух простых чисел " << i << L" и " << num - i << endl;
                flag = false;
            }
    if (flag)
        wcout << L"Число не может быть выражено как сумма двух простых чисел " << endl;
    wcout << L"Простые числа на интервале от 0 до " << num << endl;
    separator();
    for (int i = 1; i <= num + 1; i++)
    {
        flag = checkSimpleNum(i);
        if (flag)
            wcout << i << L" ";
    }
    separator();
    return 0;

}
void separator()
{
    wcout << endl;
    for (int i = 1; i <= 120; i++)
        wcout << L"=";
    wcout << endl;
}
bool checkSimpleNum(int num)
{
    bool flag = true;
    for (int i = 2; i <= num/2; i++)
        if (num % i == 0)
        {
            flag = false;
            break;
        }
    return flag;
}

bool checkArmNum(int num)
{
    bool flag = false;
    int originNum, remainder = 0, result = 0, n = 0;
    originNum = num;
    while (originNum != 0)
    {
        originNum /= 10;
        ++n;
    }
    originNum = num;
    while (originNum != 0)
    {
        remainder = originNum % 10;
        result += static_cast<int>(pow(remainder, n));
        originNum /= 10;
    }
    if (result == num)
        flag = true;
    return flag;
}
