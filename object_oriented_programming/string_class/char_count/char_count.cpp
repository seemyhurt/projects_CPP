// chcnt2.cpp
// подсчет числа слов и символов в строке
#include <iostream>
using namespace std;
#include <conio.h>           // для getche()
int main()
{
    int chcount = 0;
    int wdcount = 1;           // пробел между двумя словами
    wchar_t ch;
    while ((ch = _getche()) != '\r') // цикл, пока не нажата клавиша Enter
    {
        if (ch == ' ')           // если введен пробел,
            wdcount++;               // инкрементировать счетчик слов
        else                     // иначе
            chcount++;               // инкрементировать число символов
    }                          // вывод результатов
    wcout << L"\nСлов: " << wdcount << endl
        << L"Букв: " << chcount << endl;
    return 0;
}
