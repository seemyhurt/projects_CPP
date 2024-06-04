#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wstring st1String(L"Hello wstring");
    wcout << L"Синтаксис обращения к массиву :" << endl;
    for (size_t wchar_tCounter = 0; wchar_tCounter < st1String.length(); ++wchar_tCounter)
    {
        wcout << L" Символ [" << wchar_tCounter << "] = L";
        wcout << st1String[wchar_tCounter] << endl;
    }
    wcout << endl;

    wcout << L"Вывод с использованием итератора : " << endl;
    int wchar_tOffset = 0;
    wstring::const_iterator wchar_tLocator;
    for (auto wchar_tLocator = st1String.cbegin(); wchar_tLocator != st1String.cend(); ++wchar_tLocator)
    {
        wcout << L"Символ [" << wchar_tOffset++ << "] = L";
        wcout << *wchar_tLocator << endl;
    }
    wcout << endl;
    wcout << L" Представление строки как wchar_t* = L";
    wcout << st1String.c_str() << endl;

    return 0;

}

