#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wstring sampleStr(L"Good day wstring! Today is beautiful!") ;
    wcout << L"Исходная строка :" << "\n" << sampleStr << "\n\n";
    
    size_t wchar_tPos = sampleStr.find(L"day", 0) ;
    if (wchar_tPos != wstring::npos)
        wcout << L"\"day\" найдено в позиции " << wchar_tPos << endl;
    else
        wcout << L"Подстрока не найдена." << endl;

    wcout << L" Поиск всех подстрок \"day\"" << endl;
    size_t subStrPos = sampleStr.find(L"day", 0);
    while (subStrPos != wstring::npos)
    {
        wcout << L" Найден \"day\" в позиции " << subStrPos << endl;
        size_t searchOffset = subStrPos + 1; //Поиск со следующего символа
        subStrPos = sampleStr.find(L"day", searchOffset);
    }
    return 0;
}

