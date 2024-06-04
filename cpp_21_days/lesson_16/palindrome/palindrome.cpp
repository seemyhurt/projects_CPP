#include <iostream>
#include <string>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    setlocale(LC_ALL, "rus");
    wcout << L"Программа проверит, является ли введенное слово полиндромом" << endl;
    wcout << L"Введите слово: ";
    wstring inputString;
    getline(wcin, inputString);
    wstring Copy = inputString;
    reverse(inputString.begin(), inputString.end());
    if (Copy == inputString)
        wcout << endl << L"Строка является полиндромом" << endl;
    else
        wcout << endl << L"Строка не является полиндромом" << endl;
    return 0;

}

