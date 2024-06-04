#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
struct TIME
{
    int second;
    int minute;
    int hour;
};
void diffTime(struct TIME s1, struct TIME s2, struct TIME *diff);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    struct TIME startTime, stopTime, diff;
    wcout << L"Начальное время" << endl;
    wcout << L"Введите часы, минуты секунды: ";
    cin >> startTime.hour >> startTime.minute >> startTime.second;
    wcout << endl << L"Конечное время" << endl;
    wcout << L"Введите часы, минуты секунды: ";
    cin >> stopTime.hour >> stopTime.minute >> stopTime.second;
    diffTime(startTime, stopTime, &diff);
    wcout << L"Разница: " << diff.hour << L" : " << diff.minute << L" : " << diff.second << endl;
    return 0;

}

void diffTime(TIME s1, TIME s2, TIME* dif)
{
    if (s2.second < s1.second)
    {
        --s2.minute;
        s2.second += 60;
    }
    else if (s2.second == s1.second)
        --s2.minute;
    dif->second = s2.second - s1.second;
    if (s2.minute < s1.minute)
    {
        --s2.hour;
        s2.minute += 60;
    }
    else if (s2.minute == s1.minute)
        --s2.hour;
    dif->minute = s2.minute - s1.minute;
    dif->hour = s2.hour - s1.hour;
}
