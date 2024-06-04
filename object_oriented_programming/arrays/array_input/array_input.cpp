// safetyin.cpp
// избежание переполнения буфера
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

	const int MAX = 20;          // максимальный размер строки
	wchar_t str[MAX];           // сама строка

	wcout << L"\nВведите строку: ";
    wcin >> setw(MAX) >> str; // ввод не более чем MAX символов

	wcout << L"Вы ввели: " << str << endl;

	return 0;
}

