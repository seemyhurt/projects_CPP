// copystr.cpp
// копирует одну строку в другую
#include <iostream>
using namespace std;

void copystr(wchar_t*, const wchar_t*); // прототип функции

int main()
{

    const wchar_t* str1 = L"Поспешишь - людей насмешишь!";
    wchar_t str2[80]; // пустая строка
	copystr(str2, str1); // копируем строку str1 в str2
	wcout << str2 << endl; // и показываем результат
	return 0;
}
///////////////////////////////////////////////////////////
void copystr(wchar_t* dest, const wchar_t* src)
{
	while (*src) // пока не встретим конец строки
		*dest++ = *src++; // копируем ее
	*dest = '\0'; // заканчиваем строку
}
