// Директива препроцессора - заголовочный файл
#include <iostream>
#include <windows.h>

// Начало программы
int main()
{
	using namespace std;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	// Вывод на экран
    wcout << L"Привет, мир!" << endl;
	// Возврат значения операционной системе
	return 0;
}
