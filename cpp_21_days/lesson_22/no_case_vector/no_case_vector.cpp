#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <windows.h>

using namespace std;
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

    vector <wstring> nameslnVec{ L"jim", L"Jack", L"Artem", L"anna" };
    DisplayCont(nameslnVec);
    sort(nameslnVec.begin(), nameslnVec.end()); 
    DisplayCont(nameslnVec);
    sort(nameslnVec.begin(), nameslnVec.end(), [](const wstring& str1, const wstring& str2) -> bool
        {
            wstring str1LC;
            str1LC.resize(str1.size());
            transform(str1.begin(), str1.end(), str1LC.begin(), ::tolower);

            wstring str2LC;
            str2LC.resize(str2.size());
            transform(str2.begin(), str2.end(), str2LC.begin(), ::tolower);
            return (str1LC < str2LC);
        });
    DisplayCont(nameslnVec);
}

