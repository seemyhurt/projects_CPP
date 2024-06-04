#include <iostream>
#include <windows.h>
#include <clocale>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    char str[100];
    int j;
    wcout << L"Введите строку: ";
    cin.getline(str, 100);
    for (int i =0; str[i] != '\0'; i++)
        while (!(str[i] >= '0' && str[i] <= '9') || str[i] == '\0')
        {
            for (j = i; str[j] != '\0'; j++)
                str[j] = str[j + 1];
            str[j] = '\0';
        }
    wcout << L"Строка только с цифрами: ";
    puts(str);
    return 0;
}
