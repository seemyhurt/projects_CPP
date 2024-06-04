// times2.cpp
// преобразование времени с использованием конструктора
#include <iostream>
#include <string>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class time24
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    time24() : hours(0), minutes(0), seconds(0)
    { }
    time24(int h, int m, int s) : hours(h), minutes(m), seconds(s)
    { }
    void display() const
    {
        if (hours < 10) wcout << '0';
        wcout << hours << ':';
        if (minutes < 10) wcout << '0';
        wcout << minutes << ':';
        if (seconds < 10) wcout << '0';
        wcout << seconds;
    }
    int getHrs() const { return hours; }
    int getMins() const { return minutes; }
    int getSecs() const { return seconds; }
};
///////////////////////////////////////////////////////////
class time12
{
private:
    bool pm;
    int hrs;
    int mins;
public:
    time12() : pm(true), hrs(0), mins(0)
    { }
    time12(time24);
    time12(bool ap, int h, int m) : pm(ap), hrs(h), mins(m)
    { }
    void display() const
    {
        wcout << hrs << ':';
        if (mins < 10) wcout << '0';
        wcout << mins << ' ';
        wstring am_pm = pm ? L"p.m." : L"a.m.";
        wcout << am_pm;
    }
};
///////////////////////////////////////////////////////////
time12::time12(time24 t24)
{
    int hrs24 = t24.getHrs();

    pm = t24.getHrs() < 12 ? false : true;

    mins = (t24.getSecs() < 30) ? t24.getMins() : t24.getMins() + 1;
    if (mins == 60)
    {
        mins = 0;
        ++hrs24;
        if (hrs24 == 12 || hrs24 == 24)
            pm = (pm == true) ? false : true;
    }
    hrs = (hrs24 < 13) ? hrs24 : (hrs24 - 12);
    if (hrs == 0)
    {
        hrs = 12; pm = false;
    }
}
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    int h, m, s;

    while (true)
    {
        wcout << L"Введите время в 24-часовом формате: \n";
        wcout << L"  Часы (от 0 до 23): "; wcin >> h;
        if (h > 23)
            return (1);
        wcout << L"  Минуты: "; wcin >> m;
        wcout << L"  Секунды: "; wcin >> s;

        time24 t24(h, m, s);
        wcout << L"Исходное время: ";
        t24.display();

        time12 t12 = t24;
        wcout << L"\nВ 12-часовом формате: ";
        t12.display();
        wcout << L"\n\n";
    }
    return 0;
}

