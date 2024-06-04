// countpp3.cpp
// префиксная и постфиксная операции ++ для нашего класса
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Counter
{
private:
    unsigned int count;
public:
    Counter() : count(0)
    { }
    Counter(int c) : count(c)
    { }
    unsigned int get_count()
    {
        return count;
    }
    Counter operator++ ()
    {
        return Counter(++count);
    }
    Counter operator++ (int)
    {
        return Counter(count++);
    }
};
///////////////////////////////////////////////////////////
int main()
{
    Counter c1, c2;                        // определяем переменные

    wcout << L"\nc1 = L" << c1.get_count(); // выводим на экран
    wcout << L"\nc2 = L" << c2.get_count();

    ++c1;                                  // увеличиваем c1
    c2 = ++c1;                             // c1=2, c2=2

    wcout << L"\nc1 = L" << c1.get_count(); // снова показываем значения
    wcout << L"\nc2 = L" << c2.get_count();

    c2 = c1++;

    wcout << L"\nc1 = L" << c1.get_count(); // и снова
    wcout << L"\nc2 = L" << c2.get_count() << endl;

    return 0;
}
