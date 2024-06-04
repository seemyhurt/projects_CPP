#include <iostream>
#include <windows.h>

using namespace std;
template <typename T1 = int, typename T2 = double> //Шаблон с двумя параметрами по умолчанию
class HoldsPair
{
private:
    T1 value1;
    T2 value2;
public:
    HoldsPair(const T1& val1, const T2& val2) :
        value1(val1), value2(val2) {}
    const T1 & GetFirstValue() const
    {
        return value1;
    }
    const T2 & GetSecondValue() const
    {
        return value2;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    HoldsPair<> pairintDЬ1(300, 10.09);
    HoldsPair<short, const wchar_t*>pairShortStr(25, L"Шаблон ");

    wcout << L"Первый объект содержит :" << endl;
    wcout << L"value1 : " << pairintDЬ1.GetFirstValue() << endl;
    wcout << L"value2 : " << pairintDЬ1.GetSecondValue() << endl;

    wcout << L"Второй объект содержит :" << endl;
    wcout << L"value1 : " << pairShortStr.GetFirstValue() << endl;
    wcout << L"value2 : " << pairShortStr.GetSecondValue() << endl;
    return 0;
}

