// strconv.cpp
// перевод обычных строк в класс wstring
#include <iostream>
#include <string.h>          // для функций str*
using namespace std;
///////////////////////////////////////////////////////////
class my_string
{
private:
    const static int SZ = 80;        // размер массива
    wchar_t str[SZ];         // массив для хранения строки
public:
    // конструктор без параметров
    my_string()
    {
        str[0] = '\x0';
    }
    // конструктор с одним параметром
    my_string(const wchar_t s[])
    {
        wcscpy_s(str, s);
    } // сохраняем строку в массиве
// показ строки
    void display() const
    {
        wcout << str;
    }
    // перевод строки к обычному типу
    operator wchar_t* ()
    {
        return str;
    }
};
///////////////////////////////////////////////////////////
int main()
{
    my_string s1;                 // используем конструктор без параметров

    wchar_t xstr[] = L"Ура, товарищи! "; // создаем обычную строку

    s1 = xstr;                 // неявно используем конструктор с одним параметром

    s1.display();            // показываем строку

    my_string s2 = L"Мы победим!"; // снова используем конструктор с параметром

    wcout << static_cast<wchar_t*>(s2); // используем оператор перевода типа
    wcout << endl;

    return 0;
}
