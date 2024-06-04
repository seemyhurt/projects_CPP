#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
float calculateSD(float data[]);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

	float data[10];
    wcout << L"Введите 10 элементов массива: " << endl;
	for (int i = 0; i < 10; i++)
	{
        wcout << L"Введите элемент [" << i << L"]: ";
		cin >> data[i];
	}
    wcout << L"Среднеквадратичное отклонение = " << calculateSD(data) << endl;
}

float calculateSD(float data[])
{
	float sum = 0.0, mean, SD = 0.0;
	for (int i = 0; i < 10; i++)
	{
		sum += data[i];
	}
	mean = sum / 10;
	for (int i = 0; i < 10; i++)
	{
        SD += powf(data[i]-mean, 2.0);
	}
	return sqrt(SD / 10);
}
