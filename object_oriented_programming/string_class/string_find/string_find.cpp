// sstrfind.cpp
// поиск подстрок
#include <iostream>
#include <string>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
    wstring s1 = L"В лесу родилась елочка, в лесу она росла.";
    size_t n;

    n = s1.find(L"елочка");
	wcout << L"Елочка найдена: " << n << endl;

    n = s1.find_first_of(L"умка");
	wcout << L"Первый из умка: " << n << endl;

    n = s1.find_first_not_of(L"абвгдАБВГД");
	wcout << L"Первый не из : " << n << endl;

    wstring s3(L"Все хорошо, прекрасная маркиза.");
    wstring s4(L"принцесса");
    wstring s5(L"Приветствую ");

	s3.erase(0, 12);              // убираем "Все хорошо, "
	s3.replace(11, 7, s4);        // заменяем "маркиза" на "принцесса"
	s3.insert(0, s5);             // вставляем "Приветствую, "
	s3.erase((s3.size() - 1), 1); // убираем '.'
	s3.append(3, '!');            // добавляем '!!!'

    size_t x = s3.find(' ');         // ищем пробелы
	while (x < s3.size())        // цикл по всем пробелам
	{
        s3.replace(x, 1, L"/");      // заменяем пробел на '/'
		x = s3.find(' ');           // ищем следующий пробел
	}

	wcout << L"s3: " << s3 << endl;

    wchar_t charray[80];
    wstring word;

	wcout << L"Введите слово: ";
    wcin >> word;
    size_t wlen = word.length();     // длина строки
	wcout << L"По одному символу: ";
	for (int j = 0; j < wlen; j++)
		wcout << word.at(j) << endl;        // тут будет проверка на выход за пределы строки
		// wcout << word [ j ];        // а тут проверки не будет

	word.copy(charray, wlen, 0); // копируем строку в массив
	charray[wlen] = 0;
	wcout << L"\nМассив содержит: " << charray << endl;

	return 0;
}

