// ochar.cpp
// Посимвольный файловый вывод
#include <fstream> // для файловых функций
#include <iostream>
#include <string>
using namespace std;
int main()
{
    wstring str = L"Время - великий учитель, но, увы, оно убивает своих учеников. Берлиоз";
	wofstream outfile(L"TEST.TXT"); // Создать выходной файл
	for (int j = 0; j < str.size(); j++) // каждый символ
		outfile.put(str[j]); // записывать в файл
	wcout << L"Файл записан\n";
	return 0;
}
