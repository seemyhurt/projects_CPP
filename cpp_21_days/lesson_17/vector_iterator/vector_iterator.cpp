#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    vector <int> integers{ 50, 1, 987, 1001 };
    vector <int>:: const_iterator element = integers.cbegin();
    while (element != integers.end())
    {
        size_t index = distance(integers.cbegin(), element);
        wcout << L" Элемент в позиции ";
        wcout << index << L" равен " << *element << endl;
        ++element;
    }
    return 0;
}
