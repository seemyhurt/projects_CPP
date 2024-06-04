#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    //Динамический массив целых чисел
    vector <int> intArray;
    intArray.push_back(50);
    intArray.push_back(246);
    intArray.push_back(2421);
    intArray.push_back(24);
    wcout << L"Содержимое вектора : " << endl;
    // Обход вектора и чтение значений с помощью итератора
    vector <int>::iterator arriterator = intArray.begin();
    while (arriterator != intArray.end())
    {
        wcout << *arriterator << endl;
        ++arriterator;
    }
    vector <int>:: iterator elFound = find(intArray.begin(), intArray.end(), 24);
    // Проверить, найдено ли значение
    if (elFound != intArray.end())
    {
        auto elPos = distance(intArray.begin(), elFound);
        wcout << L"Значение " << *elFound;
        wcout << L" находится в позиции " << elPos << endl;
    }
    return 0;
}

