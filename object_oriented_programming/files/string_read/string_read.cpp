// formati.cpp
// форматированное чтение из файла с помощью >>
#include <fstream> // для файлового ввода/вывода
#include <iostream>
#include <string>
using namespace std;
int main()
{
    wchar_t ch;
	int j;
	double d;
    wstring str1;
    wstring str2;
    wifstream infile(L"fdata.txt"); // создать объект wifstream
	// извлечь (прочесть) из него данные
	infile >> ch >> j >> d >> str1 >> str2;
	wcout << ch << endl // вывести данные
		<< j << endl
		<< d << endl
		<< str1 << endl
		<< str2 << endl;
	return 0;
}
