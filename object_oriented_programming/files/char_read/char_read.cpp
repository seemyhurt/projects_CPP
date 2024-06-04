#include <fstream> // для файловых функций
#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	wchar_t ch; // символ для считывания
    wifstream infile(L"TEST.TXT"); // входной файл
	while (infile.good()) // читать до EOF или ошибки
	{
		infile.get(ch); // считать символ
		wcout << ch; // и вывести его
	}
	wcout << endl;
    wifstream infile1(L"TEST.TXT"); // создать входной файл
	wcout << infile1.rdbuf(); // передать его буфер в wcout
	wcout << endl;
	return 0;
}
