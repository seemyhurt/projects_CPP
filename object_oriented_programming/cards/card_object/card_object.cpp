// cardobj.cpp
// игральные карты в качестве объектов
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
const int jack = 11;         // именованные достоинства карт
const int queen = 12;
const int king = 13;
const int ace = 14;
//////////////////////////////////////////////////////////
class card
{
private:
    int number;              // достоинство карты
    Suit suit;               // масть
public:
    card()                  // конструктор без аргументов
    { }
    // конструктор с двумя аргументами
    card(int n, Suit s) : number(n), suit(s)
    { }
    void display();          // вывод карты на экран
    bool isEqual(card);      // результат сравнения карт
};
//--------------------------------------------------------
void card::display()         // вывод карты на экран
{
    if (number >= 2 && number <= 10)
        wcout << number << L" ";
    else
        switch (number)
        {
        case jack:   wcout << L"Валет ";  break;
        case queen:  wcout << L"Дама ";   break;
        case king:   wcout << L"Король "; break;
        case ace:    wcout << L"Туз ";    break;
        }
    switch (suit)
    {
    case clubs:     wcout << L"треф "; break;
    case diamonds:  wcout << L"бубен "; break;
    case hearts:    wcout << L"червей "; break;
    case spades:    wcout << L"пик "; break;
    }
}
//--------------------------------------------------------
bool card::isEqual(card c2)  // сравнение двух карт
{
    return (number == c2.number && suit == c2.suit) ? true : false;
}
//////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    card temp, chosen, prize;  // 3 карты
    int position;
    card card1(7, clubs);      // определение и инициализация card1
    wcout << L"\nКарта 1: ";
    card1.display();           // вывод card1
    card card2(jack, hearts);  // определение и инициализация card2
    wcout << L"\nКарта 2: ";
    card2.display();           // вывод card2
    card card3(ace, spades);   // определение и инициализация card3
    wcout << L"\nКарта 3: ";
    card3.display();           // вывод card3
    prize = card3;             // карту prize будет необходимо угадать
    wcout << L"\nМеняем местами карты 1 и 3...";
    temp = card3; card3 = card1; card1 = temp;
    wcout << L"\nМеняем местами карты 2 и 3...";
    temp = card3; card3 = card2; card2 = temp;
    wcout << L"\nМеняем местами карты 1 и 2...";
    temp = card2; card2 = card1; card1 = temp;
    wcout << L"\nНа какой позиции (1,2 или 3) теперь ";
    prize.display();           // угадываемая карта
    wcout << L"?";
    wcin >> position;           // ввод позиции игроком
    switch (position)
    {                          // chosen – карта на позиции,
    case 1:chosen = card1; break; // выбранной игроком
    case 2:chosen = card2; break;
    case 3:chosen = card3; break;
    }
    if (chosen.isEqual(prize))       // сравнение карт
        wcout << L"Правильно! Вы выиграли!";
    else
        wcout << L"Неверно. Вы проиграли.";
    wcout << L" Вы выбрали карту ";
    chosen.display();               // вывод выбранной карты
    wcout << endl;
    return 0;
}

