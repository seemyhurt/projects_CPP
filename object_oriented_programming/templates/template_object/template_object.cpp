// temlist2.cpp
// связный список с использованием шаблона
// список, умеющий работать с классом employee
#include <iostream>
using namespace std;

const int LEN = 80;       //Максимальная длина имен
///////////////////////////////////////////////////////////
class employee            //класс employee
{
private:
    wchar_t name[LEN];       //имя работника
    unsigned long number; //номер работника
public:
    friend wistream& operator >> (wistream& s, employee& e);
    friend wostream& operator << (wostream& s, const employee& e);
};
//---------------------------------------------------------
wistream& operator >> (wistream& s, employee& e)
{
    wcout << L"\n  Введите фамилию: "; wcin >> e.name;
    wcout << L"  Введите номер: ";    wcin >> e.number;
    return s;
}
//---------------------------------------------------------
wostream& operator << (wostream& s, const employee& e)
{
    wcout << L"\n  Имя: " << e.name;
    wcout << L"\n  Номер: " << e.number;
    return s;
}
///////////////////////////////////////////////////////////
template<class TYPE>      //структура "link<TYPE>"
struct link               //один элемент списка
{
    TYPE data;              //элемент данных
    link* next;             //указатель на следующую ссылку
};
///////////////////////////////////////////////////////////
template<class TYPE>      //класс "linklist<TYPE>"
class linklist            //список ссылок
{
private:
    link<TYPE>* first;    //указатель на первую ссылку
public:
    linklist()            //конструктор без аргументов
    {
        first = NULL;
    }   //первой ссылки нет
    void additem(TYPE d); //добавить данные (одну ссылку)
    void display();       //показать все ссылки
};
//---------------------------------------------------------
template<class TYPE>
void linklist<TYPE>::additem(TYPE d) //добавить данные
{
    link<TYPE>* newlink = new link<TYPE>;//создать новую ссылку
    newlink->data = d;                 //внести в нее данные
    newlink->next = first;             //указывающие на следующую ссылку
    first = newlink;  //теперь первая ссылка указывает на эту
}
//---------------------------------------------------------
template<class TYPE>
void linklist<TYPE>::display()  //вывод всех ссылок
{
    link<TYPE>* current = first;  //установить указатель на
    //первую ссылку
    while (current != NULL)      //выйти после последней ссылки
    {
        wcout << endl << current->data; //вывести данные
        current = current->next;       //перейти на следующую ссылку
    }
}
///////////////////////////////////////////////////////////
int main()
{                          //lemp – объект класса
    linklist<employee> lemp;   //"linklist<employee>"
    employee emptemp;          //временное хранилище объектов
    wchar_t ans;                  //ответ пользователя ('y' или 'n')

    do
    {
        wcin >> emptemp;         //получить данные от пользователя
        lemp.additem(emptemp);  //добавить в emptemp
        wcout << L"\nПродолжать (y/n)? ";
        wcin >> ans;
    } while (ans != 'n');    //при окончании ввода 
    lemp.display();           //вывести весь связный список
    wcout << endl;
    return 0;
}

