#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wstring firstString(L"Hello C++ Strings!");
    wcout << firstString << endl;

    wcout << L"Введите текстовую строку : " << endl;
    wstring firstLine;
    getline(wcin, firstLine);

    wcout << L"Введите другую строку : " << endl;
    wstring secondLine;
    getline(wcin, secondLine);

    wcout << L"Результат конкатенации : " << endl;
    wstring concatString = firstLine + L" " + secondLine;
    wcout << concatString << endl;

    wcout << L"Копия строки: " << endl;
    wstring aCopy;
    aCopy = concatString;
    wcout << aCopy << endl;

    wcout << L"Длина строки : " << concatString.length() << endl;

    return 0;
}
