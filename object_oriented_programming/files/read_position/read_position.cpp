// seekg.cpp
// Поиск конкретного объекта в файле
#include <fstream>        // для файловых потоков
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class person              // класс person
{
protected:
    wchar_t name[80];        // имя человека
    int age;              // его возраст
public:
    void getData()        // получить данные о человеке
    {
        wcout << L"\n  Введите имя: "; wcin >> name;
        wcout << L"  Введите возраст: "; wcin >> age;
    }
    void showData(void)   // вывод данных о человеке
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
    person pers;                  // создать объект person 
    wifstream infile;              // создать входной файл
    infile.open(L"GROUP.DAT", ios::in | ios::binary); // открыть
                                                  // файл
    infile.seekg(0, ios::end);    // установить указатель на 0
                                  // байт от конца файла
    auto endposition = infile.tellg();      // найти позицию
    auto n = endposition / sizeof(person);  // число человек
    wcout << L"\nВ файле " << n << L" человек(а)";

    wcout << L"\nВведите номер персоны: ";
    wcin >> n;
    auto position = (n - 1) * sizeof(person); // умножить размер
                           // данных под персону на число персон
    infile.seekg(position);               // число байт от начала
                           // прочитать одну персону
    infile.read(reinterpret_cast<wchar_t*>(&pers), sizeof(pers));
    pers.showData();                      //вывести одну персону
    wcout << endl;
    return 0;
}
