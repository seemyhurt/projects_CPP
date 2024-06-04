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

    wstring str1 = L"I", str2 = L"Love", str3 = L"STL", str4 = L"Strings";
    wcout << str1 + L" " + str2 + L" " + str3 + L" " + str4 + L" " << endl;
    return 0;
}

