// empmult.cpp
// множественное наследование
#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;
const int LEN = 80;       // максимальная длина имени
///////////////////////////////////////////////////////////
class student             // сведения об образовании
{
private:
    wchar_t school[LEN];   // название учебного заведения
    wchar_t degree[LEN];   // уровень образования
public:
    void getedu()
    {
        wcout << L"  Введите название учебного заведения: ";
        wcin >> school;
        wcout << L"  Введите степень высшего образования\n";
        wcout << L"  (неполное высшее, бакалавр, магистр, кандидат наук): ";
        wcin >> degree;
    }
    void putedu() const
    {
        wcout << L"\n  Учебное заведение: " << school;
        wcout << L"\n  Степень: " << degree;
    }
};
///////////////////////////////////////////////////////////
class employee            // некий сотрудник
{
private:
    wchar_t name[LEN];     // имя сотрудника
    unsigned long number; // номер сотрудника
public:
    void getdata()
    {
        wcout << L"\n  Введите фамилию: "; wcin >> name;
        wcout << L"  Введите номер: ";     wcin >> number;
    }
    void putdata() const
    {
        wcout << L"\n  Фамилия: " << name;
        wcout << L"\n  Номер: " << number;
    }
};
///////////////////////////////////////////////////////////
class manager : private employee, private student // менеджер
{
private:
    wchar_t title[LEN];    // должность сотрудника
    double dues;          // сумма взносов в гольф-клуб
public:
    void getdata()
    {
        employee::getdata();
        wcout << L"  Введите должность: "; wcin >> title;
        wcout << L"  Введите сумму взносов в гольф-клуб: "; wcin >> dues;
        student::getedu();
    }
    void putdata() const
    {
        employee::putdata();
        wcout << L"\n  Должность: " << title;
        wcout << L"\n  Сумма взносов в гольф-клуб: " << dues;
        student::putedu();
    }
};
///////////////////////////////////////////////////////////
class scientist : private employee, private student // ученый
{
private:
    int pubs;             // количество публикаций
public:
    void getdata()
    {
        employee::getdata();
        wcout << L"  Введите количество публикаций: "; wcin >> pubs;
        student::getedu();
    }
    void putdata() const
    {
        employee::putdata();
        wcout << L"\n  Количество публикаций: " << pubs;
        student::putedu();
    }
};
///////////////////////////////////////////////////////////
class laborer : public employee // рабочий
{
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    manager m1;
    scientist s1, s2;
    laborer l1;

    // введем информацию о нескольких сотрудниках
    wcout << endl;
    wcout << L"\nВвод информации о первом менеджере";
    m1.getdata();

    wcout << L"\nВвод информации о первом ученом";
    s1.getdata();

    wcout << L"\nВвод информации о втором ученом";
    s2.getdata();

    wcout << L"\nВвод информации о первом рабочем";
    l1.getdata();

    // выведем полученную информацию на экран
    wcout << L"\nИнформация о первом менеджере";
    m1.putdata();

    wcout << L"\nИнформация о первом ученом";
    s1.putdata();

    wcout << L"\nИнформация о втором ученом";
    s2.putdata();

    wcout << L"\nИнформация о первом рабочем";
    l1.putdata();

    wcout << endl;
    return 0;
}
