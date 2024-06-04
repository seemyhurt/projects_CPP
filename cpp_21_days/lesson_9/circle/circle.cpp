#include <iostream>
#include <windows.h>

using namespace std;
class Circle
{
private:
    double PI = 3.1415926;
    int radius = 0;
public:
    Circle(int inputRadius) : radius(inputRadius){}
    double perimetr()
    {
        return 2 * PI * radius;
    }
    double area()
    {
        return PI * radius * radius;
    }
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wcout << L"Вычисление длины окружности и площади круга по радиусу" << endl;
    wcout << L"Введите радиус";
    int inputRadius = 0;
    wcin >> inputRadius;
    Circle mycircle(inputRadius);
    wcout << endl << L"Длина окружности: " << mycircle.perimetr();
    wcout << endl << L"Площадь круга: " << mycircle.area();
    return 0;
}
