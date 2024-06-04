#include <iostream>
#include <algorithm>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wstring sampleStr(L"Hello wstring! Wake up to а beautiful day!");
    wcout << L"Исходная строка: " << endl;
    wcout << sampleStr << endl << endl;
    
    wcout << L"Удаление второго предложения: " << endl;
    sampleStr.erase(13, 28);
    wcout << sampleStr << endl << endl;
    wstring::iterator iwchar_tS = find(sampleStr.begin(), sampleStr.end(), 'S');
    wcout << L"Удаление 'S' из исходной строки:" << endl;
    if (iwchar_tS != sampleStr.end())
        sampleStr.erase(iwchar_tS);
    wcout << sampleStr << endl << endl;

    reverse(sampleStr.begin(), sampleStr.end());
    wcout << L"После применения алгоритма std::reverse: " << endl;
    wcout << sampleStr << endl;

    transform(sampleStr.begin(), sampleStr.end(), sampleStr.begin(), :: toupper);
    wcout << L" Преобразованная в верхний регистр строка :" << endl;
    wcout << sampleStr << endl << endl;

    transform(sampleStr.begin(), sampleStr.end(), sampleStr.begin(), ::tolower);
    wcout << L" Преобразованная в нижний регистр строка :" << endl;
    wcout << sampleStr << endl << endl;

    wcout << L"Удаление символов от begin () до end () : " << endl;
    sampleStr.erase(sampleStr.begin(), sampleStr.end());
    if (sampleStr.length() == 0)
        wcout << L"Строка пуста" << endl;
    return 0;


}
