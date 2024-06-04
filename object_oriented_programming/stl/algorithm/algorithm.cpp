#include <iostream>
#include <algorithm> // для find()
#include <clocale>
#include <functional>
#include <string>
#include <windows.h>

using namespace std;
int arr[] = { 11, 22, 33, 44, 33, 15, 18, 2 };
int pattern[] = { 11, 22, 33 };
int src1[] = { 2, 3, 4, 6, 8 };
int src2[] = { 1, 3, 5 };
int dest[8];
double fdata[] = { 19.2, 87.4, 33.6, 55.0, 11.5, 42.2 };
const wchar_t* names[] = { L"Сергей", L"Татьяна", L"Елена", L"Дмитрий", L"Михаил", L"Владимир" };
bool alpha_comp(const wchar_t*, const wchar_t*);
bool isDon(wstring); // возвращает true, если name == L"Дмитрий"
wstring name[] = {L"Сергей", L"Татьяна", L"Елена", L"Дмитрий", L"Михаил", L"Владимир" };
void in_to_cm(double); // объявление
double centi[5];
double in_to_sm(double);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
	int* ptr;
	ptr = find(arr, arr + 8, 33); // найти первое вхождение 33
	wcout << L"Первый объект со значением 33 найден в позиции "
		<< (ptr - arr) << endl;
	
    auto n = count(arr, arr + 8, 33);// считать, сколько раз
	// встречается 33
	wcout << L"Число 33 встречается " << n << L" раз(а) в массиве." << endl;
	
	int* ptr1;
	ptr1 = search(arr, arr + 8, pattern, pattern + 3);
	if (ptr1 == arr + 8) // если после последнего
		wcout << L"Совпадений не найдено\n";
	else
		wcout << L"Совпадение в позиции " << (ptr1 - arr) << endl;
	
	sort(arr, arr + 8); // сортировка
	for (int j = 0; j < 8; j++) // вывести отсортированный
		wcout << arr[j] << ' '; // массив
	wcout << endl;
	merge(src1, src1 + 5, src2, src2 + 3, dest);
	
	for (int j = 0; j < 8; j++) // вывести dest
		wcout << dest[j] << ' ';
	wcout << endl;
	
	sort(fdata, fdata + 6, greater<double>());
	for (int j = 0; j < 6; j++) // вывести отсортированный массив
		wcout << fdata[j] << ' ';
	wcout << endl;
	sort(names, names + 6, alpha_comp);// сортировка строк
	for (int j = 0; j < 6; j++) // вывод отсортированных строк
		wcout << names[j] << endl;

	wstring* ptr2;
	ptr2 = find_if(name, name + 5, isDon);
	if (ptr2 == name + 5)
		wcout << L"Дмитрия нет в списке.\n";
	else
		wcout << L"Дмитрий записан в позиции "
		<< (ptr2 - name)
		<< L" в списке.\n";
	
	double inches[] = { 3.5, 6.2, 1.0, 12.75, 4.33 };
	// вывод в виде сантиметров
	for_each(inches, inches + 5, in_to_cm);
	wcout << endl;

	transform(inches, inches + 5, centi, in_to_sm);
	for (int j = 0; j < 5; j++) // вывод массива centi[]
		wcout << centi[j] << ' ';
	wcout << endl;
	return 0;
	
	
	return 0;
}
bool alpha_comp(const wchar_t* s1, const wchar_t* s2) // возвращает true если s1 < s2
{
    return (wcscmp(s1, s2) < 0) ? true : false;
}
void in_to_cm(double in) // перевод и вывод в сантиметрах
{
	wcout << (in * 2.54) << ' ';
}
bool isDon(wstring name) // возвращает true, если name == L"Дмитрий"
{
	return name == L"Дмитрий";
}
double in_to_sm(double in) // перевод дюймов в сантиметры
{
	return (in * 2.54); // вернуть результат
}
