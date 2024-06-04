#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

	const double PI = 3.1415926535;
	double radius = 0;
	wcout << L"Программа для вычисления площади и периметра круга" << endl;
	wcout << L"Введите радиус: ";
	wcin >> radius;
	double square = PI * radius* radius;
	double perimeter = 2 * PI * radius;
	wcout << L"Длина окружности: " << perimeter << endl;
	wcout << L"Площадь круга: " << square << endl;
	return 0;
}
