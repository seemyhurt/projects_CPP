#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    vector<int> dynMas(3); //Динамический массив элементов типа int
    dynMas[0] = 256;
    dynMas[1] = 234;
    dynMas[2] = 414;

    wcout << L"Чисел в массиве : " << dynMas.size() << endl;
    wcout << L"Введите новое число для вставки в массив: ";
    int newCout = 0;
    wcin >> newCout;
    dynMas.push_back(newCout);

    wcout << L"Чисел в массиве : " << dynMas.size() << endl;
    wcout << L"Последний элемент массива : " << dynMas[dynMas.size() - 1] << endl;

    return 0;
}
