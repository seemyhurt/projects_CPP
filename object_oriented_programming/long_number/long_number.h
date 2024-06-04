// verylong.h
// описатель класса сверхбольших целых чисел

#include <cwchar>

const int SZ = 1000;           //максимальное число разрядов

class verylong
{
private:
    wchar_t vlstr[SZ];            //число как строка
    size_t vlen;                  //длина строки verylong
public:

    verylong() : vlen(0)       //конструктор без аргументов
    {
        vlstr[0] = '\0';
    }
    verylong(const wchar_t s[SZ]) //конструктор (1 аргумент)
    {
        wcscpy_s(vlstr, s);
        vlen = wcslen(s);
    } //для строки
    verylong(const unsigned long n) //конструктор (1 арг.)
    {                             //для long int
        _ltow_s(n, vlstr, 10);           //перевести в строку
        _wcsrev(vlstr);                //перевернуть ее
        vlen = wcslen(vlstr);           //найти длину
    }
    void putvl() const;              //вывести число
    void getvl();       //получить число от пользователя
    verylong operator + (const verylong); //сложить числа
    verylong operator * (const verylong); //умножить
    verylong multdigit(const int) const; //прототипы
    verylong mult10(const verylong) const;// скрытых
    // функций
};
int main();
