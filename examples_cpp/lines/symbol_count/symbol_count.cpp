#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    char str[1000], ch;
    int freq = 0;
    int total=0, digit=0, space=0;
    wcout << L"Введите строку: ";
    cin.getline(str, 256);
    wcout << L"Введите символ: ";
    cin >> ch;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ch)
            ++freq;
        if (str[i] >= '0' && str[i] <= '9')
            ++digit;
        else if (str[i] == ' ')
            ++space;
        ++total;
    }
    wcout << L"Символ \"" << ch << L"\" встречается " << freq << L" раз" << endl;
    wcout << L"Всего символов в строке: " << total << endl;
    wcout << L"Всего пробелов в строке: " << space << endl;
    wcout << L"Всего цифр в строке: " << digit << endl;
    return 0;

}
