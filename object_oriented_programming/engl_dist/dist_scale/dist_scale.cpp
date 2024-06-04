﻿// referst.cpp
// передача структурной переменной по ссылке
#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////
struct Distance                    // длина в английской системе
{
	int feet;
	float inches;
};
//////////////////////////////////////////////////////////
void scale(Distance&, float);    // прототипы функций
void engldisp(Distance);
int main()
{
	Distance d1 = { 12, 6.5 };       //инициализация d1 и d2
	Distance d2 = { 10, 5.5 };
	wcout << L"d1 = L"; engldisp(d1); //вывод исходных значений d1 и d2
	wcout << L"\nd2 = L"; engldisp(d2);
	scale(d1, 0.5);                  // масштабирование d1 и d2
	scale(d2, 0.25);
	wcout << L"\nd1 = L"; engldisp(d1); // вывод новых значений d1 и d2
	wcout << L"\nd2 = L"; engldisp(d2);
	wcout << endl;
	return 0;
}
//--------------------------------------------------------
// функция scale()
// масштабирование значения типа Distance
void scale(Distance& dd, float factor)
{
	float inches = (dd.feet * 12 + dd.inches) * factor;
	dd.feet = static_cast<int>(inches / 12);
	dd.inches = inches - dd.feet * 12;
}
//--------------------------------------------------------
// функция engldisp()
// отображает значение типа Distance на экране
void engldisp(Distance dd)       // параметр dd типа Distance
{
	wcout << dd.feet << L"\'-" << dd.inches << L"\"";
}