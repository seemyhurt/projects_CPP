#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
typedef struct complex
{
    float real;
    float image;
}complex;
complex add(complex n1, complex n2)
{
    complex temp;
    temp.real = n1.real + n2.real;
    temp.image = n1.image + n2.image;
    return (temp);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    complex n1, n2, temp;
    wcout << L"Первое комплексное число" << endl;
    wcout << L"Введите действительную часть: ";
    cin >> n1.real;
    wcout << L"Введите мнимую часть: ";
    cin >> n1.image;
    wcout << endl << L"Второе комплексное число" << endl;
    wcout << L"Введите действительную часть: ";
    cin >> n2.real;
    wcout << L"Введите мнимую часть: ";
    cin >> n2.image;
    temp = add(n1, n2);
    wcout << L"Сумма двух чисел: " << temp.real << L" + " << temp.image << L"i" << endl;
    return 0;
}

