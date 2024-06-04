// statfunc.cpp
// Статические функции и ID объектов
#include <iostream>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class gamma
{
private:
    static int total;       //всего объектов класса
                            //(только объявление)
    int id;                 //ID текущего объекта
public:
    gamma()                 //конструктор без аргументов
    {
        total++;              //добавить объект
        id = total;           //id равен текущему значению total
    }
    ~gamma()                //деструктор
    {
        total--;
        wcout << L"Удаление ID " << id << endl;
    }
    static void showtotal() // статическая функция
    {
        wcout << L"Всего: " << total << endl;
    }
    void showid()           // Нестатическая функция
    {
        wcout << L"ID: " << id << endl;
    }
};
//---------------------------------------------------------
int gamma::total = 0;       // определение total
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    gamma g1;
    gamma::showtotal();

    gamma g2, g3;
    gamma::showtotal();

    g1.showid();
    g2.showid();
    g3.showid();
    wcout << L"----------конец программы----------\n";
    return 0;
}

