// oline.cpp
// файловый вывод строк с пробелами
#include <fstream> // для операций
 // файлового ввода/вывода
using namespace std;
int main()
{
	wofstream outfile(L"TEST.TXT"); // создать выходной файл
	// отправить текст в файл
	outfile << L"Приходит март. Я сызнова служу.\n";
	outfile << L"В несчастливом кружении событий \n";
	outfile << L"изменчивую прелесть нахожу \n";
	outfile << L"в смешеньи незначительных наитий.\n";
	return 0;
}

