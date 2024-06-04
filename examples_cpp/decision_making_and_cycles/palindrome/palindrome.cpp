#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int num, reverseNum = 0, remainder, originNum, n = 0;
    wcout << L"Введите целое число: ";
    cin >> num;
    originNum = num;
    while (num != 0)
    {
        remainder = num % 10;
        reverseNum = reverseNum * 10 + remainder;
        num /= 10;
        n++;
    }
    wcout << L"Количество разрядов в числе: " << n << endl;
    wcout << L"Обратное число: " << reverseNum << endl;
    if (originNum == reverseNum)
        wcout << L"Число является палиндромом" << endl;
    else
        wcout << L"Число не является палиндромом" << endl;
    bool flag=true;
    for (int i = 2; i <= originNum / 2; i++)
    {
        if (originNum % i == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        wcout << L"Число " << originNum << L" простое" << endl;
    else
        wcout << L"Число " << originNum << L" не является простым" << endl;
    int low = 1;
    wcout << L"Простые числа на интервале от 1 до " << originNum << endl;
    while (low < originNum)
    {
        flag = true;
        for (int i = 2; i <= low / 2; i++)
        {
            if (low % i == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            wcout << low << '\t';
        ++low;
    }
    float result = 0;
    num = originNum;
    while (originNum != 0)
    {
        remainder = originNum % 10;
        result += powf(static_cast<float>(remainder), static_cast<float>(n));
        originNum /= 10;
    }
    if (result == num)
        wcout << endl << L"Число " << num << L" является числом Армстронга" << endl;
    else
        wcout << endl << L"Число " << num << L" не является числом Армстронга" << endl;
    wcout << L"Числа Армстронга на интервале от 1 до " << num << endl;
    low = 1;
    for (int i = low; i <= num; i++)
    {
        n = 0;
        int temp1 = i;
        int temp2 = i;
        while (temp1 != 0)
        {
            temp1 /= 10;
            n++;
        }
        while (temp2 != 0)
        {
            remainder = temp2 % 10;
            result += powf(static_cast<float>(remainder), static_cast<float>(n));
            temp2 /= 10;
        }
        if (result == i)
            wcout << i << '\t' ;
        n = 0;
        result = 0;
    }
    return 0;
}
