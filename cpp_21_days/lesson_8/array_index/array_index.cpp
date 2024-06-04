#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    const int ARRAY_LEN = 5;
    //Инициализация массива из 5 чисел
    int myNumЬers[ARRAY_LEN] = { 24, -1, 365, -999, 2011 };
    // Указатель, инициализированный первым элементом массива
    int* pointToNums = myNumЬers;
    wcout << L"Указатель и оператор *:" << endl;
    for (int index = 0; index < ARRAY_LEN; ++index)
        wcout << L" Элемент " << index << " = L" << *(pointToNums + index) << endl;
    wcout << L"Указатель и оператор []" << endl;
    for (int index = 0; index < ARRAY_LEN; ++index)
        wcout << L" Элемент " << index << " = L" << myNumЬers[index] << endl;
    return 0;
}

