#include <fstream>           // Для файловых потоков
#include <iostream>
#include <clocale>
#include <windows.h>

using namespace std;
///////////////////////////////////////////////////////////
class person                 // класс person
{
protected:
    wchar_t name[40];           // имя человека
    int age;                 // его возраст
public:
    void getData(void)       // получить данные
    {
        wcout << L"\n  Введите фамилию: "; wcin >> name;
        wcout << L"  Введите возраст: "; wcin >> age;
    }
    void showData(void)      // Вывод данных
    {
        wcout << L"\n  Имя: " << name;
        wcout << L"\n  Возраст: " << age;
    }
    void diskIn(int);        // чтение из файла
    void diskOut();          // запись в файл
    static int diskCount();  // Число человек в файле
};
//---------------------------------------------------------
void person::diskIn(int pn)  // Чтение данных о числе
                             // человек pn из файла
{
    wifstream infile;           // создать поток
    infile.open(L"PERSFILE.DAT", ios::binary);  // открыть его
    infile.seekg(pn * sizeof(person));         // сдвиг
                                               // файлового указателя
    infile.read((wchar_t*)this, sizeof(*this)); // чтение данных
                                               // об одном человеке
}
//---------------------------------------------------------
void person::diskOut()       // запись в конец файла 
{
    wofstream outfile;          // создать поток
                               // открыть его
    outfile.open(L"PERSFILE.DAT", ios::app | ios::binary);
    outfile.write((wchar_t*)this, sizeof(*this)); //записать в него
}
//---------------------------------------------------------
int person::diskCount()      // число людей в файле
{
    wifstream infile;
    infile.open(L"PERSFILE.DAT", ios::binary);
    infile.seekg(0, ios::end); // перейти на позицию «0 байт
                               // от конца файла»
                               // вычислить количество людей
    return (int)infile.tellg() / sizeof(person);
}
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    person p;                  // создать пустую запись
    wchar_t ch;

    do {                       // сохранение данных на диск
        wcout << L"Введите данные о человеке: ";
        p.getData();             // Получить данные
        p.diskOut();             // записать на диск
        wcout << L"Продолжить (y/n)? ";
        wcin >> ch;
    } while (ch == 'y');       // цикл до 'n'

    int n = person::diskCount(); // сколько людей в файле?
    wcout << L"В файле " << n << L" человек(а)\n";
    for (int j = 0; j < n; j++)       // для каждого
    {
        wcout << L"\nПерсона " << j+1;
        p.diskIn(j);               // считать с диска
        p.showData();              // вывести данные
    }
    wcout << endl;
    return 0;
}
