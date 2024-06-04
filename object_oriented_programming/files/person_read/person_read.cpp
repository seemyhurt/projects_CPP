// ipers.cpp
// Чтение объекта из файла
#include <fstream> // для файловых потоков
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class person // класс person
{
protected:
	wchar_t name[80]; // Имя человека
	short age; // его возраст
public:
	void showData() // вывести данные
	{
		wcout << L"Имя: " << name << endl;
		wcout << L"Возраст: " << age << endl;
	}
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	person pers; // переменная типа person
	wifstream infile(L"PERSON.DAT", ios::binary);// создать поток
	// чтение потока
	infile.read(reinterpret_cast<wchar_t*>(&pers), sizeof(pers));
	pers.showData(); // вывести данные
	return 0;
}
