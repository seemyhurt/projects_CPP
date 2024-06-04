// vector.cpp
// Демонстрация push_back(), operator[], size()
#include <iostream>
#include <vector>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	vector<int> v; // создать вектор типа int
	v.push_back(10); // внести данные в конец вектора
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v[0] = 20; // заменить новыми значениями
	v[3] = 23;

	for (int j = 0; j < v.size(); j++) // вывести содержимое
		wcout << v[j] << ' '; // 20 11 12 23
	wcout << endl;

	double arr[] = { 1.1, 2.2, 3.3, 4.4 }; // массив типа double
	vector<double> v1(arr, arr + 4); // инициализация вектора
	// массивом
	vector<double> v2(4); // пустой вектор. Размер = 4
	v1.swap(v2); // обменять содержимое v1 и v2
	while (!v2.empty()) // пока вектор не будет пуст,
	{
		wcout << v2.back() << ' '; // вывести последний элемент
		v2.pop_back(); // и удалить его
	} // вывод: 4.4 3.3 2.2 1.1
	wcout << endl;

	int arr1[] = { 100, 110, 120, 130 }; // массив типа int
	vector<int> v3(arr1, arr1 + 4); // инициализировать вектор
	// массивом
	wcout << L"\nПеред вставкой: ";
	for (int j = 0; j < v3.size(); j++) // вывести все элементы
		wcout << v3[j] << ' ';
	v3.insert(v3.begin() + 2, 115); // вставить 115 в позицию 2
	wcout << L"\nПосле вставки: ";
	for (int j = 0; j < v3.size(); j++) // вывести все элементы
		wcout << v3[j] << ' ';
	v3.erase(v3.begin() + 2); // удалить элемент со 2 позиции
	wcout << L"\nПосле удаления: ";
	for (int j = 0; j < v3.size(); j++) // вывести все элементы
		wcout << v3[j] << ' ';
	wcout << endl;
	return 0;
}
