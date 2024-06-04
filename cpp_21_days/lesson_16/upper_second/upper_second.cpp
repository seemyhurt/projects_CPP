#include <iostream>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wcout << L"Программа преобразует каждый второй символ строки  в верхний регистр." << endl;
    wcout << L"Введите строку: ";
    wstring inputString;
    getline(wcin, inputString);
    wstring:: const_iterator wchar_tLocator;
    bool reverse = true;
    for (auto wchar_tLocator = inputString.cbegin(); wchar_tLocator != inputString.cend(); ++wchar_tLocator)
    {
        if (reverse)
        {
            transform(inputString.begin(), inputString.end(), inputString.begin(), ::toupper); 
            wcout << *wchar_tLocator; 
        }
        else
        {
            transform(inputString.begin(), inputString.end(), inputString.begin(), ::tolower);
            wcout << *wchar_tLocator;
        }
        reverse = !reverse;
    }
    return 0;
}

