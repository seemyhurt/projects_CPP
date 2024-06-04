#include <iostream>
#include <list>
#include <algorithm>
#include <clocale>
#include <vector>
#include <deque>
#include <fstream>
#include <Windows.h>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
	list<int> iList1; // пустой список
	wifstream infile(L"ITER.DAT"); // создать входной файловый объект

    // (файл ITER.DAT должен уже существовать)
	// итераторы istream
    istream_iterator<wchar_t, wchar_t> file_iter(infile); // файл
    istream_iterator<wchar_t, wchar_t> end_of_stream1; // eos (конец потока)

    // копировать данные из входного файла в iList
	copy(file_iter, end_of_stream1, back_inserter(iList1));
	wcout << endl; // вывести iList
    ostream_iterator<wchar_t, wchar_t> ositer4(wcout, L"--");
	copy(iList1.begin(), iList1.end(), ositer4);
	wcout << endl;

	int arr3[] = { 1, 3, 5, 7, 9 }; // инициализация d1
	int arr4[] = { 2, 4, 6 }; // инициализация d2
	deque<int> d1;
	deque<int> d2;
	for (int i = 0; i < 5; i++) // перенести данные из массивов в
		// очереди с двусторонним доступом
		d1.push_back(arr3[i]);
	for (int j = 0; j < 3; j++)
		d2.push_back(arr4[j]);
	copy(d1.begin(), d1.end(), back_inserter(d2));
	wcout << L"\nd2: "; // вывести d2
	for (int k = 0; k < d2.size(); k++)
		wcout << d2[k] << ' ';
	wcout << endl;

	int beginRange, endRange;
	int arr[] = { 11, 13, 15, 17, 19, 21, 23, 25, 27, 29 };
	vector<int> v1(arr, arr + 10); // инициализированный вектор
	vector<int> v2(10); // неинициализированный вектор
	wcout << L"Введите диапазон копирования (пример: 2 5): ";
	wcin >> beginRange >> endRange;
	vector<int>::iterator iter1 = v1.begin() + beginRange;
	vector<int>::iterator iter2 = v1.begin() + endRange;
	vector<int>::iterator iter3;
	// копировать диапазон из v1 в v2
	iter3 = copy(iter1, iter2, v2.begin());
	// (it3 -> последний скопированный элемент)
	iter1 = v2.begin(); // итерация по диапазону
	while (iter1 != iter3) // вывести значения из v2
		wcout << *iter1++ << ' ';
	wcout << endl;

	int arr1[] = { 2, 4, 6, 8 };
	list<int> theList;
	for (int k = 0; k < 4; k++) // заполнить список элементами массива
		theList.push_back(arr1[k]);
	list<int>::iterator iter; // итератор для целочисленного списка
	for (iter = theList.begin(); iter != theList.end(); iter++)
		wcout << *iter << ' '; // вывести список
	wcout << endl;

	list<int> iList(5); // пустой список для хранения 5
	// значений типа int
	list<int>::iterator it; // итератор
	int data = 0;
	// заполнение списка данными
	for (it = iList.begin(); it != iList.end(); it++)
		*it = data += 2;
	// вывод списка
	for (it = iList.begin(); it != iList.end(); it++)
		wcout << *it << ' ';
	wcout << endl;

	iter = find(theList.begin(), theList.end(), 8);
	if (iter != theList.end())
		wcout << L"\nНайдено число 8.\n";
	else
		wcout << L"\nЧисло 8 не найдено.\n";

	int arr5[] = { 2, 4, 6, 8, 10 }; // массив типа int
	list<int> theList1;
	for (int j = 0; j < 5; j++) // перенести содержимое массива
		theList1.push_back(arr5[j]); // в список
	list<int>::reverse_iterator revit; // обратный итератор
	revit = theList1.rbegin(); // реверсная итерация
	while (revit != theList1.rend()) // по списку
		wcout << *revit++ << ' '; // с выводом на экран
	wcout << endl;

	int arr6[] = { 10, 20, 30, 40, 50 };
	list<int> theList3;
	for (int j = 0; j < 5; j++) // перенести массив в список
		theList3.push_back(arr6[j]);
    ostream_iterator<int, wchar_t> ositer(wcout, L", "); // итератор ostream
	wcout << L"\nСодержимое списка: ";
	copy(theList3.begin(), theList3.end(), ositer); // вывод списка
	wcout << endl;

	wofstream outfile(L"ITER.DAT"); // создание файлового объекта
    ostream_iterator<wchar_t, wchar_t> ositer1(outfile, L" "); // итератор
	// записать список в файл
    copy(theList3.begin(), theList3.end(), ositer1);

    list<float> fList; // неинициализированный список
	wcout << L"\nВведите 5 чисел (типа float): ";
	// итераторы istream
    istream_iterator<float, wchar_t> cin_iter(wcin);// wcin
    istream_iterator<float, wchar_t> end_of_stream; // eos (конец потока)
	// копировать из wcin в fList
    copy(cin_iter, end_of_stream, back_inserter(fList));
	wcout << endl; // вывести fList
    ostream_iterator<float, wchar_t> ositer3(wcout, L"--");
	copy(fList.begin(), fList.end(), ositer3);
	wcout << endl;


	return 0; 
}
