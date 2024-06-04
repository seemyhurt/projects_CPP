// arrover1.cpp
// демонстрация создания безопасного массива, проверяющего
// свои индексы при использовании
// используются отдельные функции для установки и получения значения
#include <iostream>
using namespace std;
#include <process.h>    // для функции exit
const int LIMIT = 100;  // размер массива
///////////////////////////////////////////////////////////
class safearray
{
private:
    int arr[LIMIT];
public:
    // установка значения элемента массива
    void putel(int n, int elvalue)
    {
        if (n < 0 || n >= LIMIT)
        {
            wcout << L"\nОшибочный индекс!"; exit(1);
        }
        arr[n] = elvalue;
    }
    // получение значения элемента массива
    int getel(int n) const
    {
        if (n < 0 || n >= LIMIT)
        {
            wcout << L"\nОшибочный индекс!"; exit(1);
        }
        return arr[n];
    }
    int& access(int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            wcout << L"\nОшибочный индекс!"; exit(1);
        }
        return arr[n];
    }
    int& operator[](int n)
    {
        if (n < 0 || n >= LIMIT)
        {
            wcout << L"\nОшибочный индекс!"; exit(1);
        }
        return arr[n];
    }

};
///////////////////////////////////////////////////////////
int main()
{
    safearray sa1;

    // задаем значения элементов
    for (int j = 0; j < LIMIT; j++)
        sa1.putel(j, j * 10);

    // показываем элементы
    for (int j = 0; j < LIMIT; j++)
    {
        int temp = sa1.getel(j);
        wcout << L"Элемент " << j << L" равен " << temp << endl;
    };

    safearray sa2;
    // задаем значения элементов
    for (int j = 0; j < LIMIT; j++)
        sa2.access(j) = j * 10; // используем функцию слева от знака =
        // показываем элементы
    for (int j = 0; j < LIMIT; j++)
    {
        int temp = sa2.access(j); // используем функцию справа от знака =
        wcout << L"Элемент " << j << L" равен " << temp << endl;
    }

    safearray sa3;
    // задаем значения элементов
    for (int j = 0; j < LIMIT; j++)
        sa3[j] = j * 10; // используем функцию слева от знака =
        // показываем элементы
    for (int j = 0; j < LIMIT; j++)
    {
        int temp = sa3[j]; // используем функцию справа от знака =
        wcout << L"Элемент " << j << L" равен " << temp << endl;
    }
    return 0;
}
