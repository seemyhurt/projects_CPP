﻿// strimem.cpp
// Класс wstring с экономией памяти
// Перегружаемая операция присваивания и конструктор 	      // копирования
#include <iostream>             // для strcpy() и т. д.
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////

class strCount                  // Класс-счетчик уникальных строк
{
private:
    int count;                  // собственно счетчик
    wchar_t* str;                  // указатель на строку
    friend class my_string;        // сделаем себя доступными
    //методы скрыты          
//---------------------------------------------------------
    strCount(wchar_t* s)           // конструктор с одним аргументом
    {
        auto length = wcslen(s);   // длина строкового
                                  // аргумента
        str = new wchar_t[length + 1]; // занять память
                                  // под строку
        wcscpy_s(str, wcslen(s) + 1, s);          // копировать в нее аргументы
        count = 1;                  // считать с единицы
    }
    //---------------------------------------------------------
    //---------------------------------------------------------
    strCount(const wchar_t* s)           // конструктор с одним аргументом
    {
        size_t length = wcslen(s);   // длина строкового
                                  // аргумента
        str = new wchar_t[length + 1]; // занять память
                                  // под строку
        wcscpy_s(str, wcslen(s)+1, s);     // копировать в нее аргументы
        count = 1;                  // считать с единицы
    }
    //---------------------------------------------------------
    ~strCount()                 // деструктор
    {
        delete[] str;
    }         // удалить строку
};
///////////////////////////////////////////////////////////
class my_string                    // класс wstring
{
private:
    strCount* psc;              // указатель на strCount
public:
    my_string()                    // конструктор без аргументов
    {
        psc = new strCount(L"NULL");
    }
    //---------------------------------------------------------
    my_string(wchar_t* s)             // конструктор с одним аргументом
    {
        psc = new strCount(s);
    }
    //---------------------------------------------------------
    my_string(const wchar_t* s)             // конструктор с одним аргументом
    {
        psc = new strCount(s);
    }
    //---------------------------------------------------------
    my_string(my_string& S)           // конструктор копирования
    {
        psc = S.psc;
        (psc->count)++;
    }
    //---------------------------------------------------------
    ~my_string()                   // деструктор
    {
        if (psc->count == 1)         // если последний
                                  // пользователь,
            delete psc;             // удалить strCount
        else                      // иначе  
            (psc->count)--;         // уменьшить счетчик
    }
    //---------------------------------------------------------
    void display()              // вывод wstring
    {
        wcout << psc->str;         // вывести строку
        wcout << L" (addr=" << psc << L")";  // вывести адрес
    }
    //---------------------------------------------------------
    my_string& operator = (my_string& S) // присвоение wstring
    {
        if (this == &S)
            return *this;
        if (psc->count == 1)         // если последний
                                  // пользователь, 
            delete psc;             // удалить strCount
        else                      // иначе
            (psc->count)--;         // уменьшить счетчик
        psc = S.psc;              //использовать strCount
                                  //аргумента
        (psc->count)++;           //увеличить счетчик
        return *this;
    }
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    my_string s3 = L"Муха по полю пошла, муха денежку нашла";
    wcout << L"\ns3="; s3.display(); //вывести s3

    my_string s1;                     //определить объект wstring
    s1 = s3;                       //присвоить его другому объекту
    wcout << L"\ns1="; s1.display(); //вывести его

    my_string s2(s3);                 //инициализация
    wcout << L"\ns2="; s2.display(); //вывести
                                   //инициализированное
    wcout << endl;
    return 0;
}
