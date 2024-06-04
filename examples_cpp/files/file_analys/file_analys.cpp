#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    int tot_chars = 0;
    int tot_lines = 0;
    int tot_words = 0;
    int in_space = 1;
    string str;
    char ch;
    setlocale(LC_ALL, "rus");
    wcout << L"Введите путь к файлу: ";
    cin >> str;
    ifstream file(str);
    while (!file.eof()) {
        file.get(ch);
        tot_chars++;
        if (isspace(ch))
        {
            in_space = 1;
            if (ch == '\n')
                tot_lines++;
        }
        else
        {
            tot_words += in_space;
            in_space = 0;
        }
    }
    wcout << L"Строк\tСимволов\tСлов" << endl;
    wcout << tot_lines << '\t' << tot_chars << '\t' << '\t' << tot_words << endl;
}

