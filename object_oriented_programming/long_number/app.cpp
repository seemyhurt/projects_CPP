#include "long_number.h"        //заголовочный файл дл€ verylong
#include <clocale>
#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    unsigned long numb, j;
    verylong fact = 1; // инициализировать verylong
    cout << "\n\n¬ведите число: ";
    cin >> numb; // ввод числа типа long int
    for (j = numb; j > 0; j--)// факториал Ч это numb *
        fact = fact * j; // numb-1 * numb-2 *
    cout << "‘акториал = "; // numb-3 и т. д.
    fact.putvl(); // вывести значение факториала
    cout << endl;
    return 0;
}
