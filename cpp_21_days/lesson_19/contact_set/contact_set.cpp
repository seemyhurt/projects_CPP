#include <iostream>
#include <string>
#include <set>
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

    set <Contactitem> contact;
    contact.insert(Contactitem(L"Jack Welsch", L"89432731843"));
    contact.insert(Contactitem(L"Peter Griffin", L"89214564756"));
    contact.insert(Contactitem(L"Mikle Scott", L"89345678797"));
    contact.insert(Contactitem(L"Josh Afford", L"89453247565"));
    contact.insert(Contactitem(L"Artem Sobakin", L"89252277019"));
    DisplayContents(contact);

    wcout << L"Введите имя для удаления:";
    wstring inputName;
    getline(wcin, inputName);
    auto contactFound = contact.find(Contactitem(inputName, L""));
    if (contactFound != contact.end())
    {
        contact.erase(contactFound);
        wcout << L"После удаления " << inputName << endl;
        DisplayContents(contact);
    }
    else
        wcout << L"Контакт не найден" << endl;

    return 0;


}
