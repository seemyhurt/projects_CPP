// wdcount.cpp
// подсчет числа слов в предложении с использованием перечислений
#include <iostream>
#include <clocale>
#include <conio.h> // для getche()
#include <windows.h>

using namespace std;
enum itsaWord { NO, YES }; // NO = 0, YES = 1

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	itsaWord isWord = NO; // isWord равно YES, когда
	// вводится слово, и NO, когда вводятся пробелы
	wchar_t ch = 'a'; // считывание символа с клавиатуры
	int wordcount = 0; // число слов
	wcout << L"Введите предложение: \n";
	do {
		ch = _getche(); // ввод символа
		if (ch == ' ' || ch == '\r')// если введен пробел,
		{
			if (isWord == YES) // а до этого вводилось слово,
			{ // значит, слово закончилось
				wordcount++; // учет слова
				isWord = NO; // сброс флага
			}
		} // в противном случае
		else // ввод слова продолжается
			if (isWord == NO) // если начался ввод слова,
				isWord = YES; // то устанавливаем флаг
	} while (ch != '\r'); // выход по нажатию Enter
	wcout << L"\n---Число слов: " << wordcount << L"---\n";
	return 0;
}

