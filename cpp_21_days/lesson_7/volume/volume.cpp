#include <iostream>
#include <windows.h>

using namespace std;
double PI = 3.1415926;
double Volume(double radius)
{
    return (4 * PI * radius * radius * radius) / 3;
}
double Volume(double radius, double heigth)
{
    return PI * radius * radius * heigth;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wcout << L"Calculate the volume of a sphere(s) or the volume of a cylinder(other): ";
    wchar_t answer = 's';
    wcin >> answer;

    if (answer == 's')
    {
        wcout << endl << "Enter the radius : ";
        double radius = 0;
        wcin >> radius;
        wcout << endl << "Volume of a sphere: " << Volume(radius);
    }
    else
    {
        wcout << endl << "Enter the radius and heigth : " << endl;
        double radius = 0;
        double heigth = 0;
        wcin >> radius;
        wcin >> heigth;
        wcout << endl << "Cylinder volume: " << Volume(radius, heigth);
    }
    return 0;
}

