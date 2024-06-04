#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
class Fish
{
public:
    virtual void Swim()
    {
        wcout << L"Рыба плавает в воде" << endl;
    }
    virtual ~Fish() {}
};
class Tuna : public Fish
{
public:
    void Swim()
    {
        wcout << L"Тунец быстро плавает" << endl;
    }
    void Dinner()
    {
        wcout << L"Из тунца готовят суши" << endl;
    }
};

class Carp : public Fish
{
public:
    void Swim()
    {
        wcout << L"Карп плавает медленно" << endl;
    }
    void Lunch()
    {
        wcout << L"Из карпа готовят жаркое" << endl;
    }
};

void DetectType(Fish* objfish)
{
    Tuna* objtuna = dynamic_cast<Tuna*>(objfish);
    if (objtuna)
    {      
        wcout << L"Обнаружен тунец" << endl;
        objtuna->Dinner();
    }

    Carp* objcarp = dynamic_cast<Carp*>(objfish);
    if (objcarp)
    {
        wcout << L"Обнаружен карп" << endl;
        objcarp->Lunch();
    }
    wcout << L"Проверка вызовом Fish::Swim: " << endl;
    objfish->Swim(); // Вызов виртуальной функции Swim
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    Tuna mydinner;
    Carp mylunch;
    DetectType(&mydinner);
    DetectType(&mylunch);

    unsigned int* bytesForAPI = reinterpret_cast<unsigned int*> (&mydinner); //Преобразование несвязных объектов (избегать)
    int *num = (int *)bytesForAPI; //Преобразование с стиле C
    wcout << num;

}

