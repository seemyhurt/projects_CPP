#include <iostream>
#include <list>
#include <clocale>
#include <windows.h>

using namespace std;
bool SortPredicate_Descending(const int& lhs, const int& rhs)
{
    //Определение критерия сортировки
    return (lhs > rhs);
}

template<typename T>
void DisplayContents(const T& container)
{
    for (auto element = container.cbegin(); element != container.cend(); ++element)
        wcout << *element << ' ';
    wcout << endl;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    list <int> linkints{ -101, 42 };
    linkints.push_front(10);
    linkints.push_front(223);
    linkints.push_back(4213);
    linkints.push_back(3212);
    DisplayContents(linkints);
    //Вставка в начало и конец функцией insert
    linkints.insert(linkints.begin(), 2);
    linkints.insert(linkints.begin(), 1);
    linkints.insert(linkints.end(), 3);
    //Вставка четырех значений 0 в начало
    linkints.insert(linkints.begin(), 4, 0);
    wcout << L"Список содержит ";
    wcout << linkints.size() << L" элементов :" << endl;
    DisplayContents(linkints);

    list <int> linkintsЗ;
    //Вставка одного списка в другой(первый аргумент - начало списка 3. Можно использовать .end для вставки в конец)
    linkintsЗ.insert(linkintsЗ.begin(), linkints.begin(), linkints.end());
    wcout << L"Список 3: " << endl;
    DisplayContents(linkintsЗ);

    //Получение итератора после вставки 2 в начало списка
    auto val2 = linkints.insert(linkints.begin(), 2);
    wcout << L"После вставки элемента " << *val2 << " : " << endl;
    DisplayContents(linkints);
    wcout << L"После удаления элемента " << *val2 << " : " << endl;
    linkints.erase(val2);
    DisplayContents(linkints);

    //Обращение списка
    linkints.reverse();
    wcout << L"После переворачивания списка: " << endl;
    DisplayContents(linkints);

    //Сортировка по возрастанию
    linkints.sort();
    wcout << L"Сортировка по возрастанию: " << endl;
    DisplayContents(linkints);

    linkints.sort(SortPredicate_Descending);
    wcout << L"Содержимое после sort () с предикатом: " << endl;
    DisplayContents(linkints);

    //Удаление всех элементов(можно использовать clear)
    linkints.erase(linkints.begin(), linkints.end());
    wcout << L"Количество элементов после удаления диапазона : ";
    wcout << linkints.size() << endl;

    return 0;

}

