#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
void enterData(int mantix[][10], int size);
void multiply(int fmatrix[][10], int smatrix[][10], int multy[][10], int size);
void display(int matrix[][10], int size);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int str, a[10][10], b[10][10], sum[10][10], multy[10][10], transponse[10][10];
    wcout << L"Введите размер матрицы(от 1 до 100): ";
    cin >> str;
    wcout << L"Введите элементы первой матрицы: " << endl;
    enterData(a, str);
    wcout << L"Введите элементы второй матрицы: " << endl;
    enterData(b, str);
    wcout << L"Сумма двух матриц: " << endl;
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < str; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    display(sum, str);
    wcout << L"Произведение двух матриц: " << endl;
    multiply(a, b, multy, str);
    display(multy, str);
    wcout << L"Транспонированная матрица a: " << endl;
    for (int i = 0; i < str; i++)
    {
        for (int j = 0; j < str; j++)
        {
            transponse[j][i] = a[i][j];
        }
    }
    display(transponse, str);
    return 0;
}

void enterData(int mantix[][10], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            wcout << L"Элемент [" << i + 1 << L"] [" << j + 1 << L"]: ";
            cin >> mantix[i][j];
        }
    }
}

void multiply(int fmatrix[][10], int smatrix[][10], int multy[][10], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            multy[i][j] = 0;
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
                multy[i][j] += fmatrix[i][k] * smatrix[k][j];
            }
        }
    }
}

void display(int matrix[][10], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            wcout << matrix[i][j] << '\t';
            if (j == size - 1)
                wcout << endl << endl;
        }
    }
}
