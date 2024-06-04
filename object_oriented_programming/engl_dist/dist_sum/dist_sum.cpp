// englcon.cpp
// constructors,adds objects using member function
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////
class Distance               // длина в английской системе
{
private:
    int feet;
    float inches;
public:                    // конструктор без аргументов
    Distance() : feet(0), inches(0.0)
    { }
    // конструктор с двумя аргументами
    Distance(int ft, float in) : feet(ft), inches(in)
    { }
    void getdist()           // ввод длины пользователем
    {
        wcout << L"\nВведите число футов: "; wcin >> feet;
        wcout << L"Введите число дюймов: "; wcin >> inches;
    }
    void showdist()          // вывод длины на экран
    {
        wcout << feet << L"\'-" << inches << '\"';
    }
    void add_dist(Distance, Distance); // прототип
};
//--------------------------------------------------------
// сложение длин d2 и d3
void Distance::add_dist(Distance d2, Distance d3)
{
    inches = d2.inches + d3.inches;        // сложение дюймов
    feet = 0;                              // с возможным заемом
    if (inches >= 12.0)                     // если число дюймов больше 12.0,
    {                                      // то уменьшаем число дюймов
        inches -= 12.0;                      // на 12.0 и увеличиваем
        feet++;                              // число футов на 1
    }
    feet += d2.feet + d3.feet;             // сложение футов
}
//////////////////////////////////////////////////////////
int main()
{
    Distance dist1, dist3;        // две длины
    Distance dist2(11, 6.25);     // определение и инициализация
    dist1.getdist();              // ввод dist1
    dist3.add_dist(dist1, dist2);  // dist3 = dist1 + dist2
    // вывод всех длин
    wcout << L"\ndist1 = L"; dist1.showdist();
    wcout << L"\ndist2 = L"; dist2.showdist();
    wcout << L"\ndist3 = L"; dist3.showdist();
    wcout << endl;
    return 0;
}

