// strplus.cpp
// перегрузка операции + для строк
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class my_string          // наш класс для строк
{
private:
    static const int SZ = 80; // максимальный размер строки
    wchar_t str[SZ];  // массив для строки
public:
    // конструктор без параметров
    my_string()
    {
        wcscpy_s(str, L"");
    }
    // конструктор с одним параметром
    my_string(const wchar_t s[])
    {
        wcscpy_s(str, s);
    }
    // показ строки
    void display() const
    {
        wcout << str << endl;
    }
    // оператор сложения
    my_string operator+ (my_string ss) const
    {
        my_string temp;  // временная переменная
        if (wcslen(str) + wcslen(ss.str) < SZ)
        {
            wcscpy_s(temp.str, str);    // копируем содержимое первой строки
            wcscat_s(temp.str, ss.str); // добавляем содержимое второй строки
        }
        else
        {
            wcout << L"\nПереполнение!";
            exit(1);
        }
        return temp;  // возвращаем результат
    }
    void getdist()
    {
        wcin.get(str, SZ);
    }
    // оператор сравнения
    bool operator==(my_string ss) const
    {
        return (wcscmp(str, ss.str) == 0) ? true : false;
    }
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    my_string s1 = L"\nС Рождеством! "; // используем конструктор с параметром
    my_string s2 = L"С Новым годом!";   // используем конструктор с параметром
    my_string s3;                      // используем конструктор без параметров

    // показываем строки
    s1.display();
    s2.display();
    s3.display();

    s3 = s1 + s2;       // присваиваем строке s3 результат сложения строк s1 и s2

    s3.display();     // показываем результат
    wcout << endl;
    my_string s4 = L"yes";
    my_string s5 = L"no";
    my_string s6;
    wcout << L"\nВведите 'yes' или 'no': ";
    s6.getdist(); // получаем строку от пользователя
    if (s6 == s4) // сравниваем со строкой 'да'
        wcout << L"Вы ввели 'yes'\n";
    else if (s6 == s5) // сравниваем со строкой 'нет'
        wcout << L"Вы ввели 'no'\n";
    else
        wcout << L"Следуйте инструкциям!\n";
    return 0;
}
