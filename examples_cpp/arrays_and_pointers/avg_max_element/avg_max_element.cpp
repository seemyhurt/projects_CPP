#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int n;
    float num[100], sum = 0.0, average;
    wcout << L"Введите количество элементов массива (не больше 100): ";
    cin >> n;
    while (n > 100 || n <= 0)
    {
        wcout << L"Количество элементов должно быть в диапазоне от 0 до 100" << endl;
        wcout << L"Введите количество элементов массива (не больше 100): ";
        cin >> n;
    }
    for (int i = 0; i < n; i++)
    {
        wcout << L"Введите элемент [" << i << L"]: ";
        cin >> num[i];
        sum += num[i]; 
    }
    average = sum / n;
    for (int i = 1; i < n; i++)
    {
        if (num[0] < num[i])
            num[0] = num[i];
    }
    wcout << L"Среднее арифметическое элементов массива: " << average << endl;
    wcout << L"Наибольший элемент массива: " << num[0] << endl;
    return 0;
}
