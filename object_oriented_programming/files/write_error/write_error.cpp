// rewerr.cpp
// Обработка ошибок ввода/вывода
#include <fstream> // для файловых потоков
#include <iostream>
#include <clocale>
#include <windows.h>
#include <process.h> // для exit()

using namespace std;
const int MAX = 1000;
int buff[MAX];
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	for (int j = 0; j < MAX; j++)// заполнить буфер данными
		buff[j] = j;
	wofstream os; // создать выходной поток
	// открыть его
	os.open(L"edata.dat", ios::trunc | ios::binary);
	if (!os)
	{
		cerr << L"Невозможно открыть выходной файл\n"; exit(1);
	}
	wcout << L"Идет запись...\n"; // записать в него содержимое
	// буфера
	os.write(reinterpret_cast<wchar_t*>(buff), MAX * sizeof(int));
	if (!os)
	{
		cerr << L"Запись в файл невозможна\n"; exit(1);
	}
	os.close(); // надо закрыть поток
	for (int j = 0; j < MAX; j++) // очистить буфер
		buff[j] = 0;
	wifstream is; // создать входной поток
	is.open(L"edata.dat", ios::binary);
	if (!is)
	{
		cerr << L"Невозможно открыть входной файл\n"; exit(1);
	}
	wcout << L"Идет чтение...\n"; // чтение файла
	is.read(reinterpret_cast<wchar_t*>(buff), MAX * sizeof(int));
	if (!is)
	{
		cerr << L"Невозможно чтение файла\n"; exit(1);
	}
	for (int j = 0; j < MAX; j++) // проверять данные
		if (buff[j] != j)
		{
			cerr << L"\nДанные некорректны\n"; exit(1);
		}
	wcout << L"Данные в порядке\n";
	return 0;
}
