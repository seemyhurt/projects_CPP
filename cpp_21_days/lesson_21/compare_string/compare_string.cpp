#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <windows.h>

using namespace std;

class StringNoCase
{
public:
    bool operator () (const wstring& str1, const wstring& str2) const
    {
        wstring str1tolower;
        str1tolower.resize(str1.size());
        transform(str1.begin(), str1.end(), str1tolower.begin(), ::tolower);
        wstring str2tolower;
        str2tolower.resize(str2.size());
        transform(str2.begin(), str2.end(), str2tolower.begin(), ::tolower);
        return(str1tolower < str2tolower);
    }
};

template <typename T>
void DisplayCont(const T& container)
{
    for (auto element = container.cbegin(); element != container.cend(); ++element)
        wcout << *element << endl;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    vector <wstring> vecNames;
    vecNames.push_back(L"Jack");
    vecNames.push_back(L"Artem");
    vecNames.push_back(L"jim");
    vecNames.push_back(L"anna");

    DisplayCont(vecNames);
    wcout << endl;
    sort(vecNames.begin(), vecNames.end());
    DisplayCont(vecNames);
    wcout << endl;
    sort(vecNames.begin(), vecNames.end(), StringNoCase());
    DisplayCont(vecNames);
    return 0;

}
