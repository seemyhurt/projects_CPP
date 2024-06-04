// retstrc.cpp
// демонстрирует возвращение функцией структурной переменной 
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
//////////////////////////////////////////////////////////
struct Distance                   // длина в английской системе
{
    int feet;
    float inches;
};
//////////////////////////////////////////////////////////
Distance addengl(Distance, Distance); // прототипы
void engldisp(Distance);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    Distance d1, d2, d3;            // три структурные переменные
    // ввод значения d1
    wcout << L"Введите число футов: "; wcin >> d1.feet;
    wcout << L"Введите число дюймов: "; wcin >> d1.inches;
    // ввод значения d2
    wcout << L"\nВведите число футов: "; wcin >> d2.feet;
    wcout << L"Введите число дюймов: "; wcin >> d2.inches;
    d3 = addengl(d1, d2);           // d3 равно сумме d1 и d2
    wcout << endl;
    engldisp(d1); wcout << L" + ";    // вывод всех длин
    engldisp(d2); wcout << L" = L";
    engldisp(d3); wcout << endl;
    return 0;
}
//--------------------------------------------------------
// функция addengl()
// складывает два значения типа Distance и возвращает сумму
Distance addengl(Distance dd1, Distance dd2)
{
    Distance dd3;                 // переменная для хранения будущей суммы
    dd3.inches = dd1.inches + dd2.inches; // сложение дюймов
    dd3.feet = 0;                 // с заемом;
    if (dd3.inches >= 12.0)        // если число дюймов больше 12.0,
    {                             // то уменьшаем число дюймов 
        dd3.inches -= 12.0;         // на 12.0 и увеличиваем
        dd3.feet++;                 // число футов на 1
    }
    dd3.feet += dd1.feet + dd2.feet; // сложение футов
    return dd3;                   // возврат значения
}
//--------------------------------------------------------
// функция engldisp()
// отображает поля структурной переменной Distance
void engldisp(Distance dd)
{
    wcout << dd.feet << L"\'-" << dd.inches << L"\"";
}
