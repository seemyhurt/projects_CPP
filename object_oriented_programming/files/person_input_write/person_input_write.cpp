// diskfun.cpp
// Чтение из файла и запись нескольких объектов
#include <fstream>      // для файловых потоков
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class person            // класс person
{
protected:
    wchar_t name[80];      // имя человека
    int age;            // его возраст
public:
    void getData()      // получить данные о человеке
    {
        wcout << L"\n  Введите имя: "; wcin >> name;
        wcout << L"  Введите возраст: "; wcin >> age;
    }
    void showData()     // вывод данных о человеке
    {
        wcout << L"\n  Имя: " << name;
        wcout << L"\n  Возраст: " << age;
    }
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    wchar_t ch;
    person pers;          // создать объект person
    wfstream file;         // создать входной/выходной файл
                          // открыть для дозаписи
    file.open(L"GROUP.DAT", ios::app | ios::out |
        ios::in | ios::binary);
    do                    // данные от пользователя – в файл
    {
        wcout << L"\nВведите данные о человеке:";
        pers.getData();     // получить данные
                            // записать их в файл
        file.write(reinterpret_cast<wchar_t*>(&pers), sizeof(pers));
        wcout << L"Продолжить ввод (y/n)? ";
        wcin >> ch;
    } while (ch == 'y');       // выход по 'n'
    file.seekg(0);        // поставить указатель на начало файла
                          // считать данные о первом человеке
    file.read(reinterpret_cast<wchar_t*>(&pers), sizeof(pers));
    while (!file.eof())  // Выход по EOF
    {
        wcout << L"\nПерсона:"; //вывести данные
        pers.showData();      //считать данные о следующем
        file.read(reinterpret_cast<wchar_t*>(&pers), sizeof(pers));
    }
    wcout << endl;
    return 0;
}
