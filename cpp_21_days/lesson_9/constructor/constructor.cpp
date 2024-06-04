#include <iostream>
#include <windows.h>

using namespace std;
class MyString
{
private:
    wchar_t* buffer;
public:
    MyString(const wchar_t* initString)
    {
        buffer = nullptr;
        wcout << L"Вызов конструктора по умолчанию" << endl;
        if (initString != nullptr)
        {
            buffer = new wchar_t[wcslen(initString) + 1];
            wcscpy_s(buffer, wcslen(initString) + 1, initString);
            wcout << L"buffer указывает на : Ox" << hex;
            wcout << (unsigned int*)buffer << endl;
        }
    }
    MyString(const MyString& copySource)
    {
        buffer = nullptr;
        wcout << L"Вызов копирующего конструктора" << endl;
        if (copySource.buffer != nullptr)
        {
            buffer = new wchar_t[wcslen(copySource.buffer) + 1];
            wcscpy_s(buffer, wcslen(copySource.buffer) + 1, copySource.buffer);
            wcout << L"buffer указывает на : Ox" << hex;
            wcout << (unsigned int*)buffer << endl;
        }
    }
    ~MyString()
    {
        wcout << L"Вызов деструктора" << endl;
        delete[] buffer;
    }
    size_t getLength()
    {
        return wcslen(buffer);
    }
    const wchar_t* GetString()
    {
        return buffer;
    }
};
void UseMyString(MyString str)
{
    wcout << L"Длина buffer в MyString равна ";
    wcout << str.getLength() << L" символам" << endl;
    wcout << L"buffer содержит : " << str.GetString() << endl;
    return;
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    MyString sayHello(L"Hello from wstring Class");
    UseMyString(sayHello);
    return 0;
}
