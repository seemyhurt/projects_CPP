#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    char str[5][100], temp[100];
    wcout << L"Введите 5 слов: ";
    for (int i = 0; i < 5; i++)
        cin >> str[i];
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 5; j++)
        {
            if (strcmp(str[i], str[j]) > 0)
            {
                strcpy_s(temp, str[i]);
                strcpy_s(str[i], str[j]);
                strcpy_s(str[j], temp);
            }
        }
    wcout << L"В лексикографическом порядке: " << endl;
    for (int i = 0; i < 5; i++)
        puts(str[i]);
    return 0;

}
