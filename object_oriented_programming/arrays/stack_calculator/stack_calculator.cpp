// parse.cpp
// программа разбора арифметических выражений
#include <iostream>
#include <clocale>
#include <windows.h>
using namespace std;
const int LEN = 80;       // максимальная длина выражения
const int MAX = 40;       //
///////////////////////////////////////////////////////////
class Stack
{
private:
    wchar_t st[MAX];      // массив данных
    int top;              // количество сохраненных данных
public:
    Stack()              // конструктор
    {
        top = 0;
    }
    void push(wchar_t var) // поместить в стек
    {
        st[++top] = var;
    }
    wchar_t pop()           // взять из стека
    {
        return st[top--];
    }
    int gettop()         // узнать количество элементов
    {
        return top;
    }
};
///////////////////////////////////////////////////////////
class express
{
private:
    Stack s;                   // стек данных
    wchar_t* pStr;                // строка для ввода
    size_t len;                   // длина строки
public:
    express(wchar_t* ptr)      // конструктор
    {
        pStr = ptr;            // запоминаем указатель на строку
        len = wcslen(pStr); // устанавливаем длину
    }
    void parse();            // разбор выражения
    int solve();             // получение результата
};
///////////////////////////////////////////////////////////
void express::parse() // добавляем данные в стек
{
    wchar_t ch;              // символ из строки
    wchar_t lastval;         // последнее значение
    wchar_t lastop;          // последний оператор

    for (int j = 0; j < len; j++) // для всех символов в строке
    {
        ch = pStr[j];    // получаем символ

        if (ch >= '0' && ch <= '9') // если это цифра,
            s.push(ch - '0');        // то сохраняем ее значение
        else
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            {
                if (s.gettop() == 1) // если это первый оператор,
                    s.push(ch);         // помещаем его в стек
                else // иначе
                {
                    lastval = s.pop(); // получаем предыдущее число
                    lastop = s.pop();  // получаем предыдущий оператор
                    // если это * или /, а предыдущий был + или -, то
                    if ((ch == '*' || ch == '/') && (lastop == '+' || lastop == '-'))
                    {
                        s.push(lastop); // отменяем последние два взятия из стека
                        s.push(lastval);
                    }
                    else
                    {
                        // помещаем в стек результат операции
                        switch (lastop)
                        {
                        case '+': s.push(s.pop() + lastval); break;
                        case '-': s.push(s.pop() - lastval); break;
                        case '*': s.push(s.pop() * lastval); break;
                        case '/': s.push(s.pop() / lastval); break;
                        default: wcout << L"\nНеизвестный оператор"; exit(1);
                        }
                    }
                    s.push(ch); // помещаем в стек текущий оператор
                }
            }
            else               // какая-то ерунда...
            {
                wcout << L"\nНеизвестный символ";
                exit(1);
            }
    }
}
///////////////////////////////////////////////////////////
int express::solve() // убираем данные из стека
{
    wchar_t lastval;        // предыдущее значение

    while (s.gettop() > 1)
    {
        lastval = s.pop(); // получаем предыдущее значение
        switch (s.pop()) // получаем предыдущий оператор
        {
        case '+': s.push(s.pop() + lastval); break;
        case '-': s.push(s.pop() - lastval); break;
        case '*': s.push(s.pop() * lastval); break;
        case '/': s.push(s.pop() / lastval); break;
        default: wcout << L"\nНеизвестный оператор"; exit(1);
        }
    }
    return int(s.pop()); // последний оператор в стеке – это результат
}
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wchar_t ans;            // 'д' или 'н'
    wchar_t wstring[LEN]; // строка для разбора

    wcout << L"\nВведите арифметическое выражение в виде 2+3*4/3-2"
          << L"\nЧисла должны быть из одной цифры"
          << L"\nНе используйте пробелы и скобки";

    do
    {
        wcout << L"\nВыражение: ";
        wcin >> wstring;                          // вводим строку
        express* eptr = new express(wstring); // создаем объект для разбора
        eptr->parse();                        // разбираем
        wcout << L"\nРезультат: "
            << eptr->solve();                // решаем
        delete eptr;                            // удаляем объект
        wcout << endl << L"Еще одно выражение (y/n)? ";
        wcin >> ans;
    } while (ans == 'y');
    return 0;
}
