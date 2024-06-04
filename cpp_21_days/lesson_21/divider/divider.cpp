#include <iostream>
#include<vector>
#include<algorithm>
#include<clocale>
#include <windows.h>

using namespace std;
template <typename numbertype>
struct isMultiply
{
    numbertype Divisior;
    isMultiply(const numbertype& divisor)
    {
        Divisior = divisor;
    }
    bool operator () (const numbertype& element) const
    {
        return ((element % Divisior) == 0);
    }

};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    vector < int> numsinVec{ 25, 26, 27, 28, 29, 30, 31 };
    wcout << L"Вектор содержит: 25, 26, 27, 28, 29, 30, 31" << endl; 
    wcout << L"Введите делитель ( > 0): ";
    int divisor = 2;
    wcin >> divisor;

    auto element = find_if(numsinVec.begin(), numsinVec.end(), isMultiply<int> (divisor));
    if (element != numsinVec.end())
    {
        wcout << L"Первый кратный " << divisor;
        wcout << L" элемент " << *element << endl;
    }
    return 0;



}
