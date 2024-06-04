#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    char sent[1000];
    char c[1000];
    FILE* fptr;
    fptr = fopen("rext.txt", "w");
    if (fptr == NULL)
    {
        wcout << L"Ошибка" << endl;
        exit(1);
    }
    wcout << L"Введите предложение: ";
    cin >> sent;
    fprintf(fptr, "%s", sent);
    fclose(fptr);
    if ((fptr = fopen("rext.txt", "r")) == NULL)
    {
        wcout << L"Ошибка" << endl;
        exit(1);
    }
    fscanf(fptr, "%[^\n]", c);
    wcout << L"Прочитано из файла: " << c << endl;
    fclose(fptr);
    FILE* fp;
    char cr;
    fp = fopen(__FILE__, "r");
    do {
        cr = getc(fp);
        putchar(cr);
    } while (cr != EOF);
    fclose(fp);
    return 0;
}
