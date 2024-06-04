// ptrobjs.cpp
// массив указателей на объекты
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class person // класс человек
{
private:
    wchar_t name[40];      // имя человека
public:
    void setName()       // установка имени
    {
        wcout << L"Введите имя: ";
        wcin >> name;
    }
    void printName()     // показ имени
    {
        wcout << L"\n  Имя: " << name;
    }
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    person* persPtr[100]; // массив указателей
    int n = 0;               // количество элементов в массиве
    wchar_t choice;

    do
    {
        persPtr[n] = new person;       // создаем новый объект
        persPtr[n]->setName();       // вводим имя
        n++;                              // увеличиваем количество
        wcout << L"Продолжаем ввод (y/n)?"; // спрашиваем, закончен ли ввод
        wcin >> choice;
    } while (choice == 'y');
    for (int j = 0; j < n; j++)
    {
        wcout << L"\nИнформация о номере " << j + 1;
        persPtr[j]->printName();
    }
    wcout << endl;

    return 0;
}
