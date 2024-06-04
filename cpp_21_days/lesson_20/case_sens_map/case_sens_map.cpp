#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <clocale>
#include <windows.h>

using namespace std;
template<typename T>
void DisplayContents(const T& cont)
{
    for (auto element = cont.cbegin(); element != cont.cend(); ++element)
        wcout << element->first << " -> " << element->second << endl;
    wcout << endl;
}
struct PredignoreCase
{
    bool operator () (const wstring& str1, const wstring& str2) const
    {
        wstring str1NoCase(str1), str2NoCase(str2);
        transform(str1.begin(), str1.end(), str1NoCase.begin(), ::tolower);
        transform(str2.begin(), str2.end(), str2NoCase.begin(), ::tolower);
        return (str1NoCase < str2NoCase);
    }
};
typedef map<wstring, wstring> DIR_WITH_CASE;
typedef map<wstring, wstring, PredignoreCase> DIR_NOCASE;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    //Чувствительное к регистру отображение
    DIR_WITH_CASE dirWithCase;
    dirWithCase.insert(make_pair(L"Pavel", L"2345764"));
    dirWithCase.insert(make_pair(L"Artem", L"2365761"));
    dirWithCase.insert(make_pair(L"PAVEL", L"3213421"));
    dirWithCase.insert(make_pair(L"Sara", L"456754"));
    wcout << L"Вывод чувствительного к регистру map:" << endl;
    DisplayContents(dirWithCase);

    // Нечувствительное к регистру отображение
    DIR_NOCASE dirNoCase(dirWithCase.begin(), dirWithCase.end());
    wcout << L"Вывод нечувствительного к регистру map: " << endl;
    DisplayContents(dirNoCase);
    
    wcout << L" Введите имя для поиска :" << endl << "> ";
    wstring name;
    wcin >> name;

    auto pairWithCase = dirWithCase.find(name);
    if (pairWithCase != dirWithCase.end())
        wcout << L"Номер при чувствительности к регистру : " << pairWithCase->second << endl;
    else
        wcout << L"Контакт не найден" << endl;
    
    auto pairNoCase = dirNoCase.find(name);
    if (pairNoCase != dirNoCase.end())
        wcout << L"Номер при отсутствии чувствительности к регистру : " << pairNoCase->second << endl;
    else
        wcout << L"Контакт не найден" << endl;
    return 0;
}

