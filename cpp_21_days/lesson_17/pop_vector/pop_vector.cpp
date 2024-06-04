#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;
template <typename T>
void DisplayVector(const vector<T>& inVec)
{
    for (auto element = inVec.cbegin(); element != inVec.cend(); ++element)
        wcout << *element << ' ';
    wcout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    vector <int> integers;
    integers.push_back(50);
    integers.push_back(23);
    integers.push_back(44210);
    integers.push_back(421);
    wcout << L"Вектор содержит " << integers.size() << L" элемента : ";
    DisplayVector(integers);

    integers.pop_back();
    wcout << L"После вызова pop_back ( ) " << endl;
    wcout << L"Вектор содержит " << integers.size() << L" элемента : ";
    DisplayVector(integers);
    return 0;



}

