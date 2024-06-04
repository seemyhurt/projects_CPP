// adswitch.cpp
// приключенческая игра с использованием switch
#include <iostream>
#include <conio.h>           // для getche()
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wchar_t dir = 'a';
    int x = 10, y = 10;
    while (dir != '\r')
    {
        wcout << L"\nВаши координаты: " << x << L", " << y;
        if (x < 5 || x > 15)
            wcout << endl << L"Осторожно! Драконы!" << endl;
        if (!(x % 7) && !(y % 7)) // если x % 7 равно 0 и у % 7 равно 0
            wcout << endl << L"Здесь находится гриб!" << endl;
        wcout << L"\nВыберите направление (n,s,e,w): ";
        dir = _getche();          // ввод переменной
        switch (dir)              // switch c переменнной dir
        {
        case 'n': y--; break;  // движение на север
        case 's': y++; break;  // движение на юг
        case 'e': x++; break;  // движение на восток
        case 'w': x--; break;  // движение на запад
        case '\r': wcout << L"Выход...\n"; break; // нажатие Enter
        }                        // конец switch
        if (x == 7 && y == 11)
        {
            wcout << endl << L"Вы нашли сокровище!" << endl;
            exit(0);
        }
    }                          // конец while
    return 0;
}                            // конец main()

