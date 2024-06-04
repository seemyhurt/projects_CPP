#include <iostream>
#include <string>
#include <list>
#include <windows.h>

using namespace std;
template<typename T>
void DisplayContents(const T& container)
{
    for (auto element = container.cbegin(); element != container.cend(); ++element)
        wcout << *element << endl;
    wcout << endl;
}
struct Contactitem
{
    wstring name;
    wstring phone;
    wstring displayAs;
    Contactitem(const wstring& conName, const wstring& conNum)
    {
        name = conName;
        phone = conNum;
        displayAs = (name + L": " + phone);
    }
    //Используется в remove
    bool operator == (const Contactitem& itemToCompare) const
    {
        return (itemToCompare.name == this->name);
    }
    //Используется в sort
    bool operator < (const Contactitem& itemToCompare) const
    {
        return (this->name < itemToCompare.name);
    }
    //Использутся для вывода в wcout
    operator const wchar_t* () const
    {
        return displayAs.c_str();
    }
};
bool SortOnphoneNumЬer(const Contactitem& item1, const Contactitem& item2)
{
    return (item1.phone < item2.phone);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    list <Contactitem> contact;
    contact.push_back(Contactitem(L"Jack Welsch",   L"89432731843"));
    contact.push_back(Contactitem(L"Peter Griffin", L"89214564756"));
    contact.push_back(Contactitem(L"Mikle Scott",   L"89345678797"));
    contact.push_back(Contactitem(L"Josh Afford",   L"89453247565"));
    contact.push_back(Contactitem(L"Artem Sobakin", L"89252277019"));
    wcout << L"Список в исходном порядке : " << endl;
    DisplayContents(contact);

    wcout << L"Сортировка с помощью оператора <:" << endl;
    contact.sort();
    DisplayContents(contact);

    contact.sort(SortOnphoneNumЬer);
    wcout << L"Сортировка с помощью предиката :" << endl;
    DisplayContents(contact);

    wcout << L"Убираем из списка: " << endl;
    contact.remove(Contactitem(L"Artem Sobakin", L""));
    DisplayContents(contact);
    return 0;


}

