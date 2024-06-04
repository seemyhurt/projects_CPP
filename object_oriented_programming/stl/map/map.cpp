// asso_arr.cpp

#include <iostream>
#include <string>
#include <map>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	wstring name;
	int pop;
    wstring states[] = { L"Wyoming", L"Colorado", L"Nevada", L"Montana", L"Arizona", L"Idaho" };
	int pops[] = { 470, 2890, 800, 787, 2718, 944 };
	map<wstring, int, less<wstring> > mapStates; // отображение
	map<wstring, int, less<wstring> >::iterator iter; // итератор
	for (int j = 0; j < 6; j++)
	{
		name = states[j]; // получение данных из массивов
		pop = pops[j];
		mapStates[name] = pop; // занесение их в отображение
	}
	wcout << L"Введите название штата: "; // получение имени штата
    wcin >> name;
	pop = mapStates[name]; // найти население штата
	wcout << L"Население: " << pop << L"000\n";
	wcout << endl; // вывод всего отображения
	for (iter = mapStates.begin(); iter != mapStates.end(); iter++)
		wcout << (*iter).first << ' ' << (*iter).second << L"000\n";
	return 0;
}
