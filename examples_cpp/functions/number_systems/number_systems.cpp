#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
long long binToDec(long long num);
long long decToBin(long long n);
long long octToDec(long long num);
long long decToOct(long long n);
long long octToBin(long long n);
long long binToOct(long long num);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    long long num;
    wcout << L"Введите двоичное число: ";
    cin >> num;
    wcout << L"Число " << num << L" в десятичной: " << binToDec(num) << endl;
    wcout << L"Число " << num << L" в восьмеричной: " << binToOct(num) << endl;
    wcout << L"Введите восьмеричное число: ";
    cin >> num;
    wcout << L"Число " << num << L" в десятичной: " << octToDec(num) << endl;
    wcout << L"Число " << num << L" в двоичной: " << octToBin(num) << endl;
    wcout << L"Введите десятичное число: ";
    cin >> num;
    wcout << L"Число " << num << L" в двоичной: " << decToBin(num) << endl;
    wcout << L"Число " << num << L" в восьмеричной: " << decToOct(num) << endl;
}

long long binToDec(long long num)
{
    long long decNum = 0, remainder, i = 0;
    while (num != 0)
    {
        remainder = num % 10;
        num /= 10;
        decNum += remainder * static_cast<long long>(pow(2, i));
        ++i;
    }
    return decNum;
}

long long decToBin(long long n)
{
    long long binNum = 0;
    int i = 1, remainder, step = 1;
    while (n != 0)
    {
        remainder = n % 2;
        wcout << L"Шаг " << step << L": Делитель = " << n << L" Остаток = " << remainder << endl;
        n /= 2;
        binNum += remainder * i;
        i *= 10;
        ++step;
    }
    return binNum;
}
long long octToDec(long long num)
{
    long long decNum = 0, remainder, i = 0;
    while (num != 0)
    {
        remainder = num % 10;
        num /= 10;
        decNum += remainder * static_cast<long long>(pow(8, i));
        ++i;
    }
    return decNum;
}

long long decToOct(long long n)
{
    int octNum = 0;
    int i = 1, remainder, step = 1;
    while (n != 0)
    {
        remainder = n % 8;
        wcout << L"Шаг " << step << L": Делитель = " << n << L" Остаток = " << remainder << endl;
        n /= 8;
        octNum += remainder * i;
        i *= 10;
        ++step;
    }
    return octNum;
}

long long octToBin(long long n)
{
    long long decNum = 0, remainder, i = 0;
    long long binNum = 0;
    while (n != 0)
    {
        remainder = n % 10;
        n /= 10;
        decNum += remainder * static_cast<long long>(pow(8, i));
        ++i;
    }
    i = 1;
    while (decNum != 0)
    {
        remainder = decNum % 2;
        decNum /= 2;
        binNum += remainder * i;
        i *= 10;
    }
    return binNum;
}

long long binToOct(long long num)
{
    long long decNum = 0, remainder, i = 0;
    while (num != 0)
    {
        remainder = num % 10;
        num /= 10;
        decNum += remainder * static_cast<long long>(pow(2, i));
        ++i;
    }
    long long octNum = 0;
    i = 1;
    while (decNum != 0)
    {
        remainder = decNum % 8;
        decNum /= 8;
        octNum += remainder * i;
        i *= 10;
    }
    return octNum;
}
