#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
class Aggregatel
{
public:
    int age;
    double pi;
};
struct Aggregate2
{
    wchar_t hello[6];
    int impYears[3];
    wstring world;
};


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    Aggregatel al{ 2017, 3.14 };
    wcout << L"Pi приближенно равно : " << al.pi << endl;
    Aggregate2 a2{ { 'h','e','l','l','o' }, { 2011, 2014, 2017 }, L"world" };
    wcout << a2.hello << ' ' << a2.world << endl;
    wcout << L"Новый стандарт С++ будет принят в "
          << a2.impYears[2] << L" году" << endl;
    return 0;

}
