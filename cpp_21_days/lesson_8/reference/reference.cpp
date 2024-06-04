#include <iostream>
#include <windows.h>

using namespace std;
void GetSquare(int& numЬer)
{
    numЬer *= numЬer;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int original = 30;
    wcout << L" original = L" << original << endl;
    wcout << L"Адрес original : " << hex << &original << endl;

    int& ref = original; // Ссылка на original 
    wcout << L"Адрес ref : " << hex << &ref<< endl;
    
    int& ref2 = ref; // Ссылка на original 
    wcout << L"Адрес ref : " << hex << &ref << endl;
    original = 15;
    wcout << L" ref2 = L" << dec << ref2 << endl;
    GetSquare(original);
    wcout << original<< endl;
    wcout << L" ref2 = L" << dec << ref2 << endl;
    return 0;

}
