// iline.cpp
// Файловый ввод (извлечение из файла) строк
#include <fstream>             // для файловых функций
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    const int MAX = 80;          // размер буфера
    wchar_t buffer[MAX];            // буфер символов 
    wifstream infile(L"TEST.TXT"); // создать входной файл
    while (infile.good())       // цикл до EOF
    {
        infile.getline(buffer, MAX); // читает строку текста
        wcout << buffer << endl;      // и выводит ее
    }
    return 0;
}

