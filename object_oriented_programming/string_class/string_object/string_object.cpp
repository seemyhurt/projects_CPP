// strobj.cpp
// строка как класс
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class my_string
{
private:
    enum { SZ = 80 };        // максимальный размер строки
    wchar_t str[SZ];          // сама строка
public:
    my_string() // конструктор без параметров
    {
        str[0] = '\0';
    }
    my_string(const wchar_t s[])     // конструктор с одним параметром
    {
        wcscpy_s(str, s);
    }
    void display()          // показ строки
    {
        wcout << str;
    }
    void concat(const my_string &s2) // сложение строк
    {
        if (wcslen(str) + wcslen(s2.str) < SZ)
            wcscat_s(str, s2.str);
        else
            wcout << L"\nПереполнение!";
    }
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    my_string s1(L"С Новым годом!  "); // конструктор с одним параметром
    my_string s2 = L"С новым счастьем!";  // аналогично, но в другой форме
    my_string s3;                        // конструктор без параметров

    wcout << L"\ns1="; s1.display();  // показываем все строки
    wcout << L"\ns2="; s2.display();
    wcout << L"\ns3="; s3.display();

    s3 = s1;                          // присвоение
    wcout << L"\ns3="; s3.display();

    s3.concat(s2);                 // сложение
    wcout << L"\ns3="; s3.display();
    wcout << endl;

    return 0;
}
