#include <iostream>
#include <windows.h>

using namespace std;
class MonsterDB
{
private:
    ~MonsterDB() { wcout << L"Объект удален"; }; //Закрытый деструктор для предотвращения создания объектов в стеке
public:
    static void Destroyinstance(MonsterDB* pinstance) //Статическая функция для доступа к закрытому деструктору
    {
        delete pinstance; //Вызов закрытого деструктора
    }
    void DoSomething() {};
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    MonsterDB* myDB = new MonsterDB();
    myDB->DoSomething();
    MonsterDB:: Destroyinstance(myDB);
    return 0;
}

