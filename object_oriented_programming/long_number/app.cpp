#include "long_number.h"        //������������ ���� ��� verylong
#include <clocale>
#include <iostream>
#include <windows.h>

using namespace std;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    unsigned long numb, j;
    verylong fact = 1; // ���������������� verylong
    cout << "\n\n������� �����: ";
    cin >> numb; // ���� ����� ���� long int
    for (j = numb; j > 0; j--)// ��������� � ��� numb *
        fact = fact * j; // numb-1 * numb-2 *
    cout << "��������� = "; // numb-3 � �. �.
    fact.putvl(); // ������� �������� ����������
    cout << endl;
    return 0;
}
