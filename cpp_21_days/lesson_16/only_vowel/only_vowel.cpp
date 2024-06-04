#include <iostream>
#include <clocale>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    setlocale(LC_ALL, "rus");
    wcout << L"Программа подсчитает количество гласных в строке." << endl;
    wcout << L"Введите строку: ";
    wstring inputString;
    getline(wcin, inputString);
    wstring vowel = (L"qeyuioa");
    int index = 0;
    wstring:: const_iterator wchar_tLocator;
    for (wchar_tLocator = inputString.cbegin(); wchar_tLocator != inputString.cend(); ++wchar_tLocator)
    {
        size_t pos = vowel.find(*wchar_tLocator, 0);
        if (pos != wstring::npos)
            index += 1;
    }
    wcout << L"Найдено " << index << L" гласных букв" << endl;

}
