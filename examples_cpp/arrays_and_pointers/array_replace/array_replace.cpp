#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
void swap(int* a, int* b, int* c)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = *c;
    *c = temp;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int data[5];
    wcout << L"Введите 5 элементов массива: ";
    for (int i = 0; i < 5; i++)
        cin >> *(data+i);
    wcout << L"Содержимое массива: " << endl;
    for (int i = 0; i < 5; i++)
        wcout << *(data + i) << endl;
    int a, b, c;
    wcout << L"Введите три числа: ";
    cin >> a >> b >>c;
    wcout << L"До перестановки: a = " << a << L" b = " << b << L" c = " << c << endl;
    swap(&a, &b, &c);
    wcout << L"После перестановки перестановки: a = " << a << L" b = " << b << L" c = " << c << endl;
    int num;
    float* mass;
    wcout << L"Введите количество элементов массива: ";
    cin >> num;
    mass = new float[num];
    for (int i = 0; i < num; i++)
    {
        wcout << L"Введите элемент [" << i << L"] : ";
        cin >> *(mass + i);
    }
    for (int i = 0; i < num; i++)
    {
        if (*mass < *(mass + i))
            *mass = *(mass + i);
    }
    wcout << L"Максимальный элемент: " << *mass << endl;
    delete[]mass;
    return 0;
}

