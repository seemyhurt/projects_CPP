// counten2.cpp
// конструкторы в производных классах
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Counter
{
protected: // заметьте, что тут не следует использовать private
	unsigned int count; // счетчик
public:
	Counter() : count() // конструктор без параметров
	{ }
	Counter(int c) : count(c) // конструктор с одним параметром
	{ }
	unsigned int get_count() const // получение значения
	{
		return count;
	}
	Counter operator++() // оператор увеличения
	{
		return Counter(++count);
	}
};
///////////////////////////////////////////////////////////
class CountDn : public Counter
{
public:
	CountDn() : Counter() // конструктор без параметров
	{ }
	CountDn(int c) : Counter(c) // конструктор с одним параметром
	{ }
	CountDn operator--() // оператор уменьшения
	{
		return CountDn(--count);
	}
};
///////////////////////////////////////////////////////////
int main()
{
	CountDn c1; // переменные класса CountDn
	CountDn c2(100);
	wcout << L"\nc1 = L" << c1.get_count();// выводим значения на экран
	wcout << L"\nc2 = L" << c2.get_count();
	++c1; ++c1; ++c1; // увеличиваем c1
	wcout << L"\nc1 = L" << c1.get_count();// показываем результат
	--c2; --c2; // уменьшаем c2
	wcout << L"\nc2 = L" << c2.get_count(); // показываем результат
	CountDn c3 = --c2; // создаем переменную c3 на основе c2
	wcout << L"\nc3 = L" << c3.get_count();// показываем значение
	wcout << endl;
	return 0;
}
