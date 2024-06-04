// ferrors.cpp
// Проверка ошибок открытия файла
#include <fstream> // для файловых функций
#include <iostream>
using namespace std;
int main()
{
	wifstream file;
	file.open(L"a:test.dat");
	if (!file)
		wcout << L"\nНевозможно открыть GROUP.DAT";
	else
		wcout << L"\nФайл открыт без ошибок.";
	wcout << L"\nfile = L" << &file;
	wcout << L"\nКод ошибки = L" << file.rdstate();
	wcout << L"\ngood() = L" << file.good();
	wcout << L"\neof() = L" << file.eof();
	wcout << L"\nfail() = L" << file.fail();
	wcout << L"\nbad() = L" << file.bad() << endl;
	file.close();
	return 0;
}
