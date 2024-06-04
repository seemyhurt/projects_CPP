// opers.cpp
// Сохранение объекта в файле
#include <fstream> // для файловых потоков
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class person // класс person
{
protected:
	wchar_t name[80]; // имя человека
	short age; // возраст
public:
	void getdata() // получить данные о человеке
	{
		wcout << L"Введите имя: "; wcin >> name;
		wcout << L"Введите возраст: "; wcin >> age;
	}
};
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	person pers; // создать объект
	pers.getdata(); // получить данные
    // создать объект wofstream
    wofstream outfile(L"PERSON.DAT", ios::binary);
	// записать в него
	outfile.write(reinterpret_cast<wchar_t*>(&pers), sizeof(pers));
	return 0;
}

