#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    char str[100], str2[100];
    int i;
    wcout << L"Первая строка: ";
    cin.getline(str, 100);
    wcout << L"Вторая строка: ";
    cin.getline(str2, 100);
    for (i = 0; str[i] != '\0'; i++);
    for (int j = 0; str2[j] != '\0'; j++, i++)
    {
        str[i] = str2[j];
    }
    str[i] = '\0';
    wcout << L"Строка 2 добавлена к строке 1: " << str << endl;
    for (i = 0; str[i] != '\0'; i++)
        str2[i] = str[i];
    str2[i] = '\0';
    wcout << L"Строка 1 скопирована в строку 2: " << str2 << endl;
    return 0;
}
