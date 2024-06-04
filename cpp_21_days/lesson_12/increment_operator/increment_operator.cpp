#include <iostream>
#include <sstream>
#include <string>
#include <clocale>
#include <memory> // Включение для использования unique_ptr
#include <windows.h>

using namespace std;
class Date
{
private:
    int day, month, year;
    wstring dateinString;
public:
    Date(int inMonth, int inDay, int inYear):
        day(inDay), month(inMonth), year(inYear) { };
    Date& operator ++ ()// Префиксный инкремент
    {
        ++day;
        return *this;
    }
    Date& operator --()// Префиксный декремент
    {
        --day;
        return *this;

    }

    operator const wchar_t* () //Оператор преобразования для печати
    {
        wostringstream formattedDate; //Создание строки
        formattedDate << day << "." << month << " " << year;
        dateinString = formattedDate.str();
        return dateinString.c_str();
    }

    Date operator + (int daysToAdd) // Сложение
    {
        Date newDate(month, day + daysToAdd, year);
        return newDate;
    }
   
    Date operator - (int daysToSub) // Вычитание
    {
        Date newDate(month, day - daysToSub, year);
        return newDate;
    }
    void operator+= (int daysToAdd) // Присваивающее сложение
    {
        day += daysToAdd;
    }

    void operator-= (int daysToSub) // Присваивающее вычитание
    {
        day -= daysToSub;
    }

    bool operator== (const Date& cornpareTo) //Операторы сравнения
    {
        return ((day == cornpareTo.day)
            && (month == cornpareTo.month)
            && (year == cornpareTo.year));
    }

    bool operator !=(const Date& cornpareTo)
    {
        return !(this ->operator== (cornpareTo));
    }

    bool operator< (const Date& compareTo)
    {
        if (year < compareTo.year)
            return true;
        else if ((month < compareTo.month)&&(year == compareTo.year))
            return true;
        else if ((day < compareTo.day) && (year == compareTo.year)&&(month < compareTo.month))
            return true;
        else
            return false;
    }

    bool operator<= (const Date& compareTo)
    {
        if (this ->operator== (compareTo))
            return true;
        else
            return this->operator< (compareTo);
    }

    void DisplayDate()
    {
        wcout << day << '.' << month << "." << year << endl;
    }

};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    Date holiday(1, 7, 2017);
    Date holiday2(12, 31, 2016);
    wcout << L"Дата инициализирована значением : ";
    holiday.DisplayDate();

    ++holiday; // Вперед на один день
    wcout << L"Дата после префиксного инкремента : ";
    holiday.DisplayDate();

    --holiday; // Назад на один день
    wcout << L"Дата после префиксного декремента : ";
    holiday.DisplayDate();

    wcout << L"Рождество: " << holiday << endl;

    Date PreviousHoliday(holiday - 6);
    wcout << L"Новый год : ";
    PreviousHoliday.DisplayDate();

    wcout << L"holiday += 6: ";
    holiday += 6;
    holiday.DisplayDate();

    if (holiday == holiday2)
        wcout << L"Равенство : даты совпадают " << endl;
    else
        wcout << L"Равенство : даты не совпадают " << endl;

    if (holiday != holiday2)
        wcout << L"Неравенство : даты не совпадают " << endl;
    else
        wcout << L"Неравенство : даты совпадают " << endl;

    if (holiday < holiday2)
        wcout << L"Дата 1 раньше" << endl;
    else
        wcout << L"Дата 2 раньше" << endl;


    unique_ptr<int> smartintPtr(new int); //Интелектуальный указатель
    *smartintPtr = 42;
    // Использование интеллектуального указателя как int*
    wcout << L"Целое число равно : " << *smartintPtr << endl;
    unique_ptr<Date> smartHoliday(new Date(1, 1, 2017));
    // Использование интеллектуального указателя как Date*
    wcout << L"Новый экземпляр даты : ";
    smartHoliday->DisplayDate();


    return 0;
}

