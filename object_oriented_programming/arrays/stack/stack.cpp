// stakaray.cpp
// класс стек
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Stack
{
private:
    static const int MAX = 10; // немного нестандартный синтаксис
    int st[MAX];    // стек в виде массива
    int top;           // вершина стека
public:
    Stack() // конструктор
    {
        top = 0;
    }
    void push(int var) // поместить в стек
    {
        st[++top] = var;
    }
    int pop() // взять из стека
    {
        return st[top--];
    }
};
///////////////////////////////////////////////////////////
int main()
{
    Stack s1;

    s1.push(11);
    s1.push(22);
    wcout << L"1: " << s1.pop() << endl;
    wcout << L"2: " << s1.pop() << endl;
    s1.push(33);
    s1.push(44);
    s1.push(55);
    s1.push(66);
    wcout << L"3: " << s1.pop() << endl;
    wcout << L"4: " << s1.pop() << endl;
    wcout << L"5: " << s1.pop() << endl;
    wcout << L"6: " << s1.pop() << endl;
    return 0;
}
