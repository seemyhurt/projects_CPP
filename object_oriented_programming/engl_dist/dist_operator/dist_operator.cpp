// engplus.cpp
// перегрузка операции + для сложения переменных типа Distances
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class Distance  // класс английских мер длины
{
private:
    int feet;
    float inches;
public:
    // конструктор без параметров
    Distance() : feet(0), inches(0.0)
    { }
    // конструктор с двумя параметрами
    Distance(int ft, float in) : feet(ft), inches(in)
    { }
    // получение информации от пользователя
    void getdist()
    {
        wcout << L"\nВведите футы: "; wcin >> feet;
        wcout << L"Введите дюймы: ";  wcin >> inches;
    }
    // показ информации
    void showdist()
    {
        wcout << feet << L"\'-" << inches << '\"';
    }
    // сложение двух длин
    Distance operator+ (Distance) const;
    bool operator< (Distance) const;
    void operator+= (Distance);
};
///////////////////////////////////////////////////////////
// сложение двух длин
Distance Distance::operator+ (Distance d2) const
{
    int f = feet + d2.feet;       // складываем футы
    float i = inches + d2.inches; // складываем дюймы
    if (i >= 12.0)              // если дюймов стало больше 12
    {
        i -= 12.0;                  // то уменьшаем дюймы на 12
        f++;                        // и увеличиваем футы на 1
    }
    return Distance(f, i);     // создаем и возвращаем временную переменную
}
bool Distance::operator<(Distance d2) const
{
    float bf1 = feet + inches / 12;
    float bf2 = d2.feet + d2.inches / 12;
    return (bf1 < bf2) ? true : false;
}
void Distance::operator+=(Distance d2)
{
    feet += d2.feet; // складываем футы
    inches += d2.inches; // складываем дюймы
    if (inches >= 12.0) // если дюймов больше 12
    {
        inches -= 12.0; // то уменьшаем дюймы на 12
        feet++; // увеличиваем футы на 1
    };
}
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    Distance dist1, dist3, dist4;  // определяем переменные
    dist1.getdist();             // получаем информацию

    Distance dist2(11, 6.25);   // определяем переменную с конкретным значением

    dist3 = dist1 + dist2;         // складываем две переменные

    dist4 = dist1 + dist2 + dist3; // складываем несколько переменных

    // показываем, что же у нас получилось
    wcout << L"dist1 = L"; dist1.showdist(); wcout << endl;
    wcout << L"dist2 = L"; dist2.showdist(); wcout << endl;
    wcout << L"dist3 = L"; dist3.showdist(); wcout << endl;
    wcout << L"dist4 = L"; dist4.showdist(); wcout << endl;
    if (dist1 < dist2)
        wcout << L"\ndist1 меньше dist2";
    else
        wcout << L"\ndist1 больше или равно dist2";
    wcout << endl;
    dist1 += dist2; // dist1 = dist1 + dist2
    wcout << L"\nПосле добавления:";
    wcout << L"\ndist1 = L"; dist1.showdist();
    wcout << endl;

    return 0;
}
