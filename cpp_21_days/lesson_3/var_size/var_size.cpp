#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wcout << L"Размеры встроенных типов C++" << endl;
    wcout << L"bool :" << sizeof(bool) << endl;
    wcout << L"wchar_t :" << sizeof(wchar_t) << endl;
    wcout << L"unsigned short int :" << sizeof(unsigned short int) << endl;
    wcout << L"short int  :" << sizeof(short int) << endl;
    wcout << L"unsigned long int  :" << sizeof(unsigned long int) << endl;
    wcout << L"long  :" << sizeof(long) << endl;
    wcout << L"int  :" << sizeof(int) << endl;
    wcout << L"unsigned long long  :" << sizeof(unsigned long long) << endl;
    wcout << L"long long  :" << sizeof(long long) << endl;
    wcout << L"unsigned int  :" << sizeof(unsigned int) << endl;
    wcout << L"float  :" << sizeof(float) << endl;
    wcout << L"double  :" << sizeof(double) << endl;

    return 0;
}

