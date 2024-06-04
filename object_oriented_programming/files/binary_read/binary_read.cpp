// binio.cpp
// Двоичный ввод/вывод целочисленных данных
#include <fstream>         // для файловых потоков
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
const int MAX = 100;       // размер буфера
int buff[MAX];             // буфер для целых чисел

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    for (int j = 0; j < MAX; j++) // заполнить буфер данными
        buff[j] = j;           // (0, 1, 2, ...)
                               // создать выходной поток
    wofstream os(L"edata.dat", ios::binary);
    // записать в него
    os.write(reinterpret_cast<wchar_t*>(buff), MAX * sizeof(int));
    os.close();              // должен закрыть его

    for (int j = 0; j < MAX; j++)     // стереть буфер
        buff[j] = 0;
    // создать входной поток
    wifstream is(L"edata.dat", ios::binary);
    // читать из него
    is.read(reinterpret_cast<wchar_t*>(buff), MAX * sizeof(int));

    for (int j = 0; j < MAX; j++)     // проверка данных
    {
        if (buff[j] != j)
        {
            cerr << L"Некорректные данные!\n"; return 1;
        }
    }
    wcout << L"Данные корректны\n";
    return 0;
}
