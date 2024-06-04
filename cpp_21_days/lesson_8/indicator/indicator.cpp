#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int age = 30;
    int dogAge = 10;

    wcout << L"age =" << age << endl;
    wcout << L"dogAge = L" << dogAge << endl;

    int* pointsInt = &age;
    wcout << L"pointsInt indicate age " << endl;
    wcout << L"pointsInt = 0x" << hex << pointsInt << endl;
    wcout << L"*pointsInt = L" << dec << *pointsInt << endl;
    
    pointsInt = &dogAge;
    wcout << L"pointsInt indicate dogAge " << endl;
    wcout << L"pointsInt = 0x" << hex << pointsInt << endl;
    wcout << L"*pointsInt = L" << dec << *pointsInt << endl;

    return 0;

}

