// showprim.cpp
// изображает распределение простых чисел
#include <iostream>
#include <conio.h>                 // для getche()

using namespace std;
int main()
{
    const unsigned int WHITE = 219; // белый цвет для простых чисел
    const unsigned int GRAY = 176;   // серый цвет для остальных чисел
    unsigned int ch;
    // действия для каждой позиции на экране
    for (int count = 0; count < 80 * 25 - 1; count++)
    {
        ch = WHITE;                    //предполагаем, что число простое
        for (int j = 2; j < count; j++)     // делим на каждое целое, большее 2
            if (count % j == 0)              // если остаток равен 0,
            {
                ch = GRAY;                   // то число не простое
                break;                       // выход из внутреннего цикла
            }
        wcout << ch;                    // вывод символа на экран
    }
    _getch();                         // задержка полученного изображения
    return 0;
}
