#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;
void DisplayVector(const vector<int>& inVec)
{
    for (auto element = inVec.cbegin(); element != inVec.cend(); ++element)
    {
        wcout << *element << ' ';
    }
    wcout << endl;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    //Вектор с четырьмя значениями 90
    vector <int> integers(4, 90);
    //Начальное содержимое
    DisplayVector(integers);
    //Вставить 25 в начало
    integers.insert(integers.begin(), 25);
    //Вставить два числа 45 в конец
    integers.insert(integers.end(), 2, 45);
    DisplayVector(integers);
    //Вектор с двумя числами 30
    vector <int> another(2, 30);
    //Вставить вектор в позицию 1
    integers.insert(integers.begin() + 1, another.begin(), another.end());
    DisplayVector(integers);
    return 0;
}
