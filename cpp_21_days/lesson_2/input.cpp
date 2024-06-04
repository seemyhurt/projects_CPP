#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

	int inputNumber;
	wcout << L"Print number: ";
    wcin >> inputNumber;
	
	// Текстовые данные
	wcout << L"Print your name: ";
	wstring inputName;
    wcin >> inputName;

	wcout << inputName << " print " << inputNumber << endl;

	return 0;

}

