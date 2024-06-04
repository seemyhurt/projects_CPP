// empl_io.cpp
// Файловый ввод/вывод объектов employee
// Поддержка объектов неодинаковых размеров
#include <fstream>      // для потоковых файловых функций
#include <iostream>
#include <clocale> 
#include <process.h>    // для exit()
#include <windows.h>

using namespace std;

const int LEN = 32;     // Максимальная длина фамилий
const int MAXEM = 100;  // максимальное число работников

enum employee_type { tmanager, tscientist, tlaborer };
///////////////////////////////////////////////////////////
class employee                // класс employee 
{
private:
    wchar_t name[LEN];           // фамилия работника
    unsigned long number;     // номер работника
    static int n;             // текущее число работников
    static employee* arrap[]; //массив указателей на
                              // класс работников
public:
    virtual void getdata()
    {
        wcin.ignore(10, '\n');
        wcout << L"  Введите фамилию: "; wcin >> name;
        wcout << L"  Введите номер: ";    wcin >> number;
    }
    virtual void putdata()
    {
        wcout << L"\n  Фамилия: " << name;
        wcout << L"\n  Номер: " << number;
    }
    virtual employee_type get_type(); // получить тип
    static void add();                // добавить работника
    static void display();            // вывести данные обо всех
    static void read();               // чтение из файла
    static void write();              // запись в файл
};
//---------------------------------------------------------
//статические переменные
int employee::n;                  // текущее число работников
employee* employee::arrap[MAXEM]; // массив указателей на
                                  // класс работников
///////////////////////////////////////////////////////////
//класс manager (менеджеры)
class manager : public employee
{
private:
    wchar_t title[LEN];  // титул (L"вице-президент" и т. п.)
    double dues;      // Налоги гольф-клуба
public:
    void getdata()
    {
        employee::getdata();
        wcout << L"  Введите титул: ";       wcin >> title;
        wcout << L"  Введите налоги: "; wcin >> dues;
    }
    void putdata()
    {
        employee::putdata();
        wcout << L"\n  Титул: " << title;
        wcout << L"\n  Налоги гольф-клуба: " << dues;
    }
};
///////////////////////////////////////////////////////////
//класс scientist (ученые)
class scientist : public employee
{
private:
    int pubs;              // число публикаций
public:
    void getdata()
    {
        employee::getdata();
        wcout << L"  Введите число публикаций: "; wcin >> pubs;
    }
    void putdata()
    {
        employee::putdata();
        wcout << L"\n  Число публикаций: " << pubs;
    }
};
///////////////////////////////////////////////////////////
//класс laborer (рабочие)
class laborer : public employee
{
};
///////////////////////////////////////////////////////////
//добавить работника в список (хранится в ОП)
void employee::add()
{
    wchar_t ch;
    wcout << L"'m' для добавления менеджера"
          << L"\n's' для добавления ученого"
          << L"\n'l' для добавления рабочего"
          << L"\nВаш выбор: ";
    wcin >> ch;
    switch (ch)
    {          //создать объект указанного типа
    case 'm': arrap[n] = new manager;  break;
    case 's': arrap[n] = new scientist; break;
    case 'l': arrap[n] = new laborer;  break;
    default: wcout << L"\nНеизвестный тип работника\n"; return;
    }
    arrap[n++]->getdata();  //Получить данные от пользователя
}
//---------------------------------------------------------
//Вывести данные обо всех работниках
void employee::display()
{
    for (int j = 0; j < n; j++)
    {
        wcout << (j + 1);                // вывести номер
        switch (arrap[j]->get_type()) //вывести тип 
        {
        case tmanager:  wcout << L". Тип: Менеджер";  break;
        case tscientist: wcout << L". Тип: Ученый"; break;
        case tlaborer:   wcout << L". Тип: Рабочий";  break;
        default: wcout << L". Неизвестный тип";
        }
        arrap[j]->putdata();           // Вывод данных
        wcout << endl;
    }
}
//---------------------------------------------------------
//Возврат типа объекта
employee_type employee::get_type()
{
    if (typeid(*this) == typeid(manager))
        return tmanager;
    else if (typeid(*this) == typeid(scientist))
        return tscientist;
    else if (typeid(*this) == typeid(laborer))
        return tlaborer;
    else
    {
        cerr << L"\nНеправильный тип работника"; exit(1);
    }
    return tmanager;
}
//---------------------------------------------------------
//Записать все объекты, хранящиеся в памяти, в файл
void employee::write()
{
    int size;
    wcout << L"Идет запись " << n << L" работников.\n";
    wofstream ouf;           // открыть wofstream в двоичном виде
    employee_type etype;   // тип каждого объекта employee

    ouf.open(L"EMPLOY.DAT", ios::trunc | ios::binary);
    if (!ouf)
    {
        wcout << L"\nНевозможно открыть файл\n"; return;
    }
    for (int j = 0; j < n; j++)  // Для каждого объекта
    {                     // получить его тип
        etype = arrap[j]->get_type();
        // записать данные в файл
        ouf.write((wchar_t*)&etype, sizeof(etype));
        switch (etype)         // find its size
        {
        case tmanager:  size = sizeof(manager); break;
        case tscientist: size = sizeof(scientist); break;
        case tlaborer:  size = sizeof(laborer); break;
        }      //запись объекта employee в файл    
        ouf.write( (wchar_t*)(arrap[j]), size );
        if (!ouf)
        {
            wcout << L"\nЗапись в файл невозможна\n"; return;
        }
    }
}
//---------------------------------------------------------
//чтение всех данных из файла в память
void employee::read()
{
    int size;               // размер объекта employee 
    employee_type etype;    // тип работника
    wifstream inf;           // открыть wifstream в двоичном виде
    inf.open(L"EMPLOY.DAT", ios::binary);
    if (!inf)
    {
        wcout << L"\nНевозможно открыть файл\n"; return;
    }
    n = 0;                  // В памяти работников нет
    while (true)
    {                     // чтение типа следующего работника
        inf.read((wchar_t*)&etype, sizeof(etype));
        if (inf.eof())       // выход из цикла по EOF
            break;
        if (!inf)              // ошибка чтения типа
        {
            wcout << L"\nНевозможно чтение типа\n"; return;
        }
        switch (etype)
        {                   // создать нового работника
        case tmanager:      // корректного типа
            arrap[n] = new manager;
            size = sizeof(manager);
            break;
        case tscientist:
            arrap[n] = new scientist;
            size = sizeof(scientist);
            break;
        case tlaborer:
            arrap[n] = new laborer;
            size = sizeof(laborer);
            break;
        default: wcout << L"\nНеизвестный тип в файле\n"; return;
        }                   // чтение данных из файла
        inf.read((wchar_t*)arrap[n], size);
        if (!inf)              // ошибка, но не EOF
        {
            wcout << L"\nЧтение данных из файла невозможно\n"; return;
        }
        n++;                  // счетчик работников увеличить
    }  //end while
    wcout << L"Идет чтение " << n << L" работников\n";
}
///////////////////////////////////////////////////////////
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    wchar_t ch;
    while (true)
    {
        wcout << L"'a' – добавление сведений о работнике"
              << L"\n'd' - вывести сведения обо всех работниках"
              << L"\n'w' – записать все данные в файл"
              << L"\n'r' – прочитать все данные из файла"
              << L"\n'x' - выход"
              << L"\nВаш выбор: ";
        wcin >> ch;
        switch (ch)
        {
        case 'a':           // добавить работника
            employee::add(); break;
        case 'd':           // вывести все сведения
            employee::display(); break;
        case 'w':           // запись в файл
            employee::write(); break;
        case 'r':           // чтение всех данных из файла
            employee::read(); break;
        case 'x': exit(0);  // выход
        default: wcout << L"\nНеизвестная команда";
        }  //end switch
    }  //end while
    return 0;
}  //end main()
