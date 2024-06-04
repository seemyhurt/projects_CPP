#include <iostream>
using namespace std;
int main()
{
    // Переменная может принимать только те значения, которые есть в списке
    enum RainbowColors
    {
        Violet,
        Indigo,
        Blue,
        Green,
        Yellow,
        Orange,
        Red

    };
    RainbowColors myColor = Orange;
    wcout << myColor;
    return 0;
}
