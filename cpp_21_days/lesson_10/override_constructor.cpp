#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
class Fish
{
protected:
    bool isFreshWaterFish;
public:
    // Перегруженный конструктор класса Fish
    Fish(bool isFreshWater) : isFreshWaterFish(isFreshWater) {}
    void Swim()
    {
        if (isFreshWaterFish)
            wcout << L"Пресноводный" << endl;
        else
            wcout << L"Морской" << endl;
    }
};
class Tuna : public Fish
{
public:
    Tuna() : Fish(false) {}
    //Переопределение функции Swim
    void Swim()
    {
        wcout << L" Тунец быстро плавает" << endl;
        Fish::Swim();//Реализация метода swim из класса fish расширение области видимости
    }       
};
class Carp : public Fish
{
public:
    Carp() : Fish(true) {}
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    Carp myLunch;
    Tuna myDinner;
    wcout << L"Моя еда:" << endl;
    wcout << L"Обед: ";
    myLunch.Swim();

    wcout << L"Ужин: ";
    myDinner.Swim();
    return 0;

}
