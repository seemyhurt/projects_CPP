#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
struct course
{
    int mark;
    char subj[30];
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    struct course* ptr;
    int noRecord;
    wcout << L"Количество записей: ";
    cin >> noRecord;
    ptr = (struct course*)malloc(noRecord * sizeof(struct course));
    for (int i = 0; i < noRecord; i++)
    {
        wcout << L"Введите название предмета и оценку: " << endl;
        cin >> (ptr + i)->subj >> (ptr + i)->mark;
    }
    wcout << endl << L"Результат" << endl;
    for (int i = 0; i < noRecord; i++)
    {
        wcout << (ptr + i)->subj << L"\t" << (ptr + i)->mark << endl;
    }
    return 0;
}

