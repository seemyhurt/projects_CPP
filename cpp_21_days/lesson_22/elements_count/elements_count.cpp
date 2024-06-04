#include <iostream>
#include<vector>
#include<list>
#include<algorithm>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    vector <int> numslnVec{101, -4, 500, 21, 42, -1};
    list <wchar_t> wchar_tslnList{L'а', L'h', L'z', L'k', L'1'};
    for_each(numslnVec.cbegin(), numslnVec.cend(), [](const int& element) {wcout << element << ' '; });
    wcout << endl;
    for_each(wchar_tslnList.cbegin(), wchar_tslnList.cend(), [](const wchar_t& element) {wcout << element << ' '; });
    return 0;

}

