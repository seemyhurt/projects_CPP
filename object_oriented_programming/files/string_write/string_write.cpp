// formato.cpp
// Форматированный вывод в файл с использованием <<
#include <fstream> // для файлового ввода/вывода
#include <iostream>
#include <string>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	wchar_t ch = 'x';
	int j = 77;
	double d = 6.02;
	wstring str1 = L"Kafka"; // строки без
	wstring str2 = L"Proust"; // пробелов
	wofstream outfile(L"fdata.txt"); // создать объект wofstream
	outfile << ch // вставить (записать) данные
		<< ' '
		<< j
		<< ' ' // пробелы между числами
		<< d
		<< ' '
		<< str1
		<< ' ' // пробелы между строками
		<< str2;
	wcout << L"Файл записан\n";
	return 0;
}
