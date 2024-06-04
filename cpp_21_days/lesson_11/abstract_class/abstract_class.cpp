#include <iostream>
#include <windows.h>

using namespace std;
class Fish
{
public:
    virtual void Swim() = 0;
};
//В подклассе обязательно нужно переопределить чисто виртуальную функцию
class Tuna : public Fish
{
public:
    void Swim()
    {
        wcout << L"tunec plavaet bystro" << endl;
    }
};
class Carp : public Fish
{
public:
    void Swim()
    {
        wcout << L"carp plavaet medlenno" << endl;
    }
};

void deletMemory(Fish* InputFish)
{
    delete InputFish;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    //Fish myfish - так как класс абстрактный с чисто виртуальной функцией;
    Tuna mydinner;
    Carp mylunch;
    mydinner.Swim();
    mylunch.Swim();
    return 0;
}

