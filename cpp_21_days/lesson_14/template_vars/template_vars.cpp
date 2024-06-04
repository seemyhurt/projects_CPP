#include <iostream>
#include <windows.h>

using namespace std;
template <typename Res, typename ValType>
void Sum(Res& result, ValType& val)
{
    result = result + val;
}
template <typename Res, typename First, typename ... Rest>
void Sum(Res& result, First vall, Rest ... valN)
{
    result = result + vall;
    return Sum(result, valN ...);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    double dResult = 0;
    Sum(dResult, 3.14, 4.56, 1.1111);
    wcout << L"dResult = L" << dResult << endl;

    wstring strResult;
    Sum(strResult, L"Hello", L"World");
    wcout << L"strResult = L" << strResult.c_str() << endl;
    return 0;
}

