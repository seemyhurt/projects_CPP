#include <iostream>
#include <windows.h>

using namespace std;
class Fish
{
public:
    Fish()
    {
        wcout << L"Sozdaem ribu" << endl;
    }
    virtual ~Fish()
    {
        wcout << L"Ydaliaem ribu" << endl;
    }
};
class Tuna : public Fish
{
public:
    Tuna()
    {
        wcout << L"Sozdaem tunca" << endl;
    }
    ~Tuna()
    {
        wcout << L"Ydaliaem tunca" << endl;
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

    wcout << L"Videlenie dynamichesloy pamiati dlia Tuna: " << endl;
    Tuna* pTuna = new Tuna;
    wcout << L"ydalenie Tuna: " << endl;
    // Если бы не было виртуального деструктора, вызывался бы только деструктор класса Fish
    deletMemory(pTuna);
    
    wcout << L"Sozdanie Tuna v steke: " << endl;
    Tuna myDinner;
    wcout << L"Vihod iz oblasti vidimosti : " << endl;
    return 0;
}
