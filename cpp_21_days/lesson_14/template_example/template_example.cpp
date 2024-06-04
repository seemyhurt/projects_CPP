#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
template < typename Туре>
const Туре& GetMax(const Туре& value1, const Туре& value2)
{
    if (value1 > value2)
        return value1;
    else
        return value2;
}
template <typename Туре>
void DisplayComparison(const Туре& value1, const Туре& value2)
{
    wcout << L"GetMax (L" << value1 << ", " << value2 << " ) = L";
    wcout << GetMax(value1, value2) << endl;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int numl = -101, num2 = 2011;
    DisplayComparison(numl, num2);
    double d1 = 3.14, d2 = 3.1416;
    DisplayComparison(d1, d2);
    wstring name1(L"Jack"), name2(L"John");
    DisplayComparison(name1, name2);
    return 0;

}

