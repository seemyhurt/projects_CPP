// persort.cpp
// сортировка объектов через массив указателей на них
#include <iostream>
#include <string>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class person            // некоторый человек
{
protected:
    wstring name;        // имя
public:
    void setName()    // установка имени
    {
        wcout << L"Введите имя: "; wcin >> name;
    }
    void printName()  // показ имени
    {
        wcout << endl << name;
    }
    wstring getName()  // получение имени
    {
        return name;
    }
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    void bsort(person**, int); // прототип функции
    person* persPtr[100];      // массив указателей на person
    int n = 0;                    // количество элементов в массиве
    wchar_t choice;                  // переменная для ввода символа

    do
    {
        persPtr[n] = new person;       // создаем новый объект
        persPtr[n]->setName();       // вводим имя
        n++;                              // увеличиваем количество
        wcout << L"Продолжаем ввод (y/n)?"; // спрашиваем, закончен ли ввод
        wcin >> choice;
    } while (choice == 'y');

    wcout << L"\nНеотсортированный список:";
    for (int j = 0; j < n; j++) // покажем неотсортированный список
        persPtr[j]->printName();

    bsort(persPtr, n);         // отсортируем указатели

    wcout << L"\nОтсортированный список:";
    for (int j = 0; j < n; j++)     // покажем отсортированный список
        persPtr[j]->printName();
    wcout << endl;

    return 0;
}
///////////////////////////////////////////////////////////
void bsort(person** pp, int n)
{
    void order(person**, person**); // прототип функции
    int j, k;                          // переменные для циклов

    for (j = 0; j < n-1; j++)      // внешний цикл
        for (k = j + 1; k < n; k++)    // внутренний цикл
            order(pp + j, pp + k);      // сортируем два элемента
}
///////////////////////////////////////////////////////////
void order(person** pp1, person** pp2)
{
    if ((*pp1)->getName() > (*pp2)->getName()) // если первая строка больше второй,
    {
        person* tempptr = *pp1; // меняем их местами
        *pp1 = *pp2;
        *pp2 = tempptr;
    }
}
