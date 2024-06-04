#include <iostream>
#include<list>
#include<vector>
#include<algorithm>
#include <windows.h>

using namespace std;
template<typename elementType>
struct DisplayElement
{
    void operator () (const elementType& element) const
    {
        wcout << element << " ";
    }
};
template<typename elementType>
struct DisplayElementKeepCount
{
    int count;
    DisplayElementKeepCount() : count(0) { }
    void operator () (const elementType& element)
    {
        ++count;
        wcout << element << " ";
    }
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    vector <int> numsVector{ 0, 1, 2, 3, 4, 5 };
    for_each(numsVector.begin(), numsVector.end(), DisplayElement<int>());

    wcout << endl;
    list <wchar_t> wchar_tslnList{ 'a' , 'z', 'k', 'd' };
    for_each(wchar_tslnList.begin(), wchar_tslnList.end(), DisplayElement<wchar_t>());
    wcout << endl;

    vector<int> numsinVec{ 22, 2017, -1, 999, 43, 901 };
    DisplayElementKeepCount<int> result;
    result = for_each(numsinVec.begin(), numsinVec.end(), DisplayElementKeepCount<int>());
    wcout << endl << L"Функтор вызван " << result.count << L" раз . ";
    return 0;

}
