// класс игральных карт
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
// от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;
/////////////////////////////////////////////////////////////
class card
{
private:
    int number;
    Suit suit;
public:
    card() // конструктор
    { }
    void set(int n, Suit s) // установка значения
    {
        suit = s; number = n;
    }
    void display();          // показ карты
};
/////////////////////////////////////////////////////////////
void card::display()
{
    if (number >= 2 && number <= 10)
        wcout << number;
    else
    {
        switch (number)
        {
        case jack: wcout << 'J'; break;
        case queen: wcout << 'Q'; break;
        case king: wcout << 'K'; break;
        case ace: wcout << 'A'; break;
        }
    }
    switch (suit)
    {
    case clubs: wcout << static_cast<wchar_t>(5); break;
    case diamonds: wcout << static_cast<wchar_t>(4); break;
    case hearts: wcout << static_cast<wchar_t>(3); break;
    case spades: wcout << static_cast<wchar_t>(6); break;
    }
}
/////////////////////////////////////////////////////////////
int main()
{
    card deck[52];
    int j;

    wcout << endl;
    for (j = 0; j < 52; j++)   // создаем упорядоченную колоду карт
    {
        int num = (j % 13) + 2;
        Suit su = Suit(j / 13);
        deck[j].set(num, su);
    }
    // показываем исходную колоду
    wcout << L"Исходная колода:\n";
    for (j = 0; j < 52; j++)
    {
        deck[j].display();
        wcout << L"  ";
        if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
            wcout << endl;
    }
    srand(static_cast<unsigned int>(time(NULL)));     // инициализируем генератор случайных чисел
    for (j = 0; j < 52; j++)
    {
        int k = rand() % 52;     // выбираем случайную карту
        card temp = deck[j];    // и меняем ее с текущей
        deck[j] = deck[k];
        deck[k] = temp;
    }
    // показываем перемешанную колоду
    wcout << L"\nПеремешанная колода:\n";
    for (j = 0; j < 52; j++)
    {
        deck[j].display();
        wcout << L"  ";
        if (!((j + 1) % 13)) // начинаем новую строку после каждой 13-й карты
            wcout << endl;
    }
    return 0;
}

