#include <iostream>
#include <windows.h>

using namespace std;
class Fish
{
public:
    virtual void Swim() 
    {
        wcout << L"riba plavaet" << endl;
    }
};
class Tuna : public Fish
{
    //Перекрытие метода Swim
    void Swim()
    {
        wcout << L"tunec plavaet bistro" << endl;
    }
};
class Carp : public Fish
{
    //Перекрытие метода Swim
    void Swim()
    {
        wcout << L"carp plavaet medlenno" << endl;
    }
};
void MakeFishSwim(Fish& InputFish)
{
    InputFish.Swim();
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    Tuna mydinner;
    Carp mylunch;
    // Если бы не было виртуальной функции, в обоих случаях напечаталось бы "рыба плавает"
    MakeFishSwim(mydinner);
    MakeFishSwim(mylunch); 
    return 0;
}
