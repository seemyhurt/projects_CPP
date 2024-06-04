#include <iostream>
#include <set>
#include<clocale>
#include <windows.h>

using namespace std;
template <typename T>
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

    set<int> setints{ 202, 151, -999, -1 };
    setints.insert(-1);
    wcout << L"Содержимое множества : " << endl;
    DisplayContents(setints);

    multiset<int> msetints;
    msetints.insert(setints.begin(), setints.end());
    msetints.insert(-1);
    wcout << L"Содержимое мультимножества : " << endl;
    DisplayContents(msetints);

    wcout << L"Количество экземпляров ' - 1' в мультимножестве :" ;
    wcout << msetints.count(-1) << "'" << endl;

    auto elementFound = setints.find(-1);
    if (elementFound != setints.end())
        wcout << L"Элемент " << *elementFound<< L" найден" << endl;
    else
        wcout << L"Элемент не найден" << endl;
    auto anotherFind = setints.find(12345);
    if (anotherFind != setints.end())
        wcout << L"Элемент " << *anotherFind << L" найден" << endl;
    else
        wcout << L"Элемент не найден" << endl;
    wcout << L"multiset содержит " << msetints.size() << L" элементов :";
    DisplayContents(msetints);
    wcout << L"Введите удаляемое число: ";
    int input = 0;
    wcin >> input;

    wcout << L"Удаляем " << msetints.count(input);
    wcout << L" экземпляра значения " << input << endl;
    msetints.erase(input);
    wcout << L"multiset содержит " << msetints.size() << L" элемента : ";
    DisplayContents(msetints);

    return 0;

}

