#include <iostream>
#include <windows.h>

using namespace std;
// Объявление и определение функции 
void DemoConsoleOutput() // Тип void не возвращает значения, int возвращает число
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wcout << L"Простой строковый литерал" << endl;
    wcout << L"Запись числа пять: " << 5 << endl;
    wcout << L"Выполнение деления 10/5: " << 10 / 5 << endl;
    wcout << L"ПИ примерно равно 22/7: " << 22 / 7 << endl;
    wcout << L"Более точно ПИ равно 22/7: " << 22.0 / 7 << endl;
}

int main()
{
    // Вызов функции и возврат результата
    DemoConsoleOutput();
    return 0;
}
