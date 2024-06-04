// xofxref.cpp
// конструктор копирования: X(X&)
#include <iostream>
#include <windows.h>
using namespace std;
///////////////////////////////////////////////////////////
class alpha
{
private:
    int data;
public:
    alpha()            //конструктор без аргументов
    { }
    alpha(int d)       //конструктор с одним аргументом
    {
        data = d;
    }
    alpha(alpha& a)    //конструктор копирования
    {
        data = a.data;
        wcout << L"\nЗапущен конструктор копирования";
    }
    void display()     //display
    {
        wcout << data;
    }
    void operator = (alpha& a) //overloaded = operator
    {
        data = a.data;
        wcout << L"\nЗапущен оператор присваивания";
    }
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    alpha a1(37);
    alpha a2;

    a2 = a1;             //запуск перегружаемого =
    wcout << L"\na2="; a2.display();  //вывести a2

    alpha a3(a1);        //запуск конструктора копирования
  // alpha a3 = a1;      //эквивалентное определение a3
    wcout << L"\na3="; a3.display();  //вывести a3
    wcout << endl;
    return 0;
}
