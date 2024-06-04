#include <iostream>
#include <deque> //Двусторонняя очередь
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    deque <int> intDeque;
    intDeque.push_back(4);
    intDeque.push_back(5);
    intDeque.push_back(6);
    intDeque.push_front(3);
    intDeque.push_front(2);
    intDeque.push_front(1);
    for (size_t count = 0; count < intDeque.size(); ++count)
    {
        wcout << L" Элемент [" << count << "] = L";
        wcout << intDeque[count] << endl;
    }
    intDeque.pop_front();
    intDeque.pop_back();
    // Отображение содержимого с помощью итераторов
    for (auto element = intDeque.begin(); element != intDeque.end(); ++element)
    {
        size_t offset = distance(intDeque.begin(), element);
        wcout << L" Элемент [" << offset << "] = L" << *element << endl;
    }
    return 0;
}
