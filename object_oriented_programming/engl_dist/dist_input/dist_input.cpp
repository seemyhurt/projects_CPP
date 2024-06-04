// englen.cpp
// наследование в программе перевода английских мер длины
#include <iostream>
using namespace std;
enum posneg { pos, neg };
///////////////////////////////////////////////////////////
class Distance // класс для английских мер длины
{
protected:   // заметьте, что private использовать нельзя
    int feet;
    float inches;
public:
    // конструктор без параметров
    Distance() : feet(0), inches(0.0)
    { }
    // конструктор с двумя параметрами
    Distance(int ft, float in) : feet(ft), inches(in)
    { }
    // получение значений от пользователя
    void getdist()
    {
        wcout << L"\nВведите футы: "; wcin >> feet;
        wcout << L"Введите дюймы: "; wcin >> inches;
    }
    // вывод значений на экран
    void showdist() const
    {
        wcout << feet << L"\'" << inches << '\"';
    }
};
///////////////////////////////////////////////////////////
class DistSign : public Distance // добавление знака к длине
{
private:
    posneg sign; // значение может быть pos или neg
public:
    // конструктор без параметров
    DistSign() : Distance()
    {
        sign = pos;
    }
    // конструктор с двумя или тремя параметрами
    DistSign(int ft, float in, posneg sg = pos) :
        Distance(ft, in) // вызов конструктора базового класса
    {
        sign = sg;
    } // начальная установка знака
    void getdist() // ввод пользователем длины
    {
        Distance::getdist(); // вызов функции getdist из базового класса
        wchar_t ch; // запрос знака
        wcout << L"Введите знак (+ или -): "; wcin >> ch;
        sign = (ch == '+') ? pos : neg;
    }
    void showdist() const // вывод расстояния
    {
        // вывод всей информации, включая знак
        wcout << ((sign == pos) ? "(+)" : "(-)");
        Distance::showdist();
    }
};
///////////////////////////////////////////////////////////
int main()
{
    DistSign alpha; // используем конструктор по умолчанию
    alpha.getdist(); // получаем данные от пользователя

    DistSign beta(11, 6.25); // конструктор с двумя аргументами

    DistSign gamma(100, 5.5, neg); // конструктор с тремя аргументами

    // выводим данные для всех переменных
    wcout << L"\nA = L"; alpha.showdist();
    wcout << L"\nB = L"; beta.showdist();
    wcout << L"\nC = L"; gamma.showdist();
    wcout << endl;
    return 0;
}

