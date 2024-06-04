#include <iostream>
#include <algorithm>
#include <vector>
#include<clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    vector<int> numsinVec{ 25, 101, 2017, -50 };
    auto evenNum = find_if(numsinVec.cbegin(), numsinVec.cend(), [](const int& num) {return((num % 2) == 0);});
    if (evenNum != numsinVec.end())
        wcout << L"Четный эемент найден: " << *evenNum << endl;
    else
        wcout << L"Четный элемент не найден" << endl;

    vector <int> numsinVec2{ 25, 26, 27, 28, 29, 30, 31 };
    wcout << L"Вектор : { 25, 26, 27, 28, 29, 30, 31 )";
    wcout << endl << L"Введите делитель (> 0 ): " ;
    int divisor = 2;
    wcin >> divisor;
    vector <int>::iterator element;
    //Лямбда-выражение с списком захвата и аргументом состояния divisior, полученный из ввода пользователя
    element = find_if(numsinVec2.begin(), numsinVec2.end(), [divisor] (int num) {return((num % divisor) == 0); });
    if (element != numsinVec2.end())
    {
        wcout << L" Первый элемент, делящийся на " << divisor;
        wcout << L" : " << *element << endl;
    }


    return 0;


}
