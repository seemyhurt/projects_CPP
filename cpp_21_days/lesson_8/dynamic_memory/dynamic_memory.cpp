#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    wcout << L"The number of numbers entered? ";
    int numEntries = 0;
    wcin >> numEntries;

    int* pointsToints = new int[numEntries];
    wcout << L"Memory allocated " << endl;
    for (int counter = 0; counter < numEntries; ++counter)
    {
        wcout << L"Enter a number " << counter << " : ";
        wcin >> *(pointsToints + counter);
    }
    wcout << L"Numbers are entered : " << endl;
    for (int counter = 0; counter < numEntries; ++counter)
        wcout << *(pointsToints++) << " ";
    wcout << endl;

    pointsToints -= numEntries;
    delete[] pointsToints;
    return 0;
}

