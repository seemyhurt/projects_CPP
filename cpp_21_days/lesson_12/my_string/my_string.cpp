#include <iostream>
#include <string.h>
#include <string>
#include <clocale>
#include <windows.h>

using namespace std;
class MyString
{
private:
    wchar_t* buffer;
    MyString() : buffer(nullptr)//Закрытый конструктор по умолчанию
    {
        wcout << L"Конструктор по умолчанию" << endl;
    }
public:
    MyString(const wchar_t* initString)// Конструктор
    {
        wcout << L"Конструктор : " << initString << endl;
        if (initString != nullptr)
        {
            buffer = new wchar_t[wcslen(initString) + 1];
            wcscpy_s(buffer, wcslen(initString), initString);
        }
        else
            buffer = nullptr;
    }

    MyString(MyString&& moveSrc) // Перемещающий конструктор
    {
        wcout << L"Перемещающий конструктор: " << moveSrc.buffer << endl;
        if (moveSrc.buffer != nullptr)
        {
            buffer = moveSrc.buffer; //Получение владения
            moveSrc.buffer = nullptr; //Освобождение перемещенного ресурса
        }
    }
    MyString& operator= (MyString&& moveSrc) //Перемещающее присваивание
    {
        wcout << L"Перемещающее присваивание: " << moveSrc.buffer << endl;
        if ((moveSrc.buffer != nullptr) && (this != &moveSrc))
        {
            delete [] buffer;
            buffer = moveSrc.buffer;
            moveSrc.buffer = nullptr;
        }
        return *this;
    }
    MyString& operator=(const MyString& copySource) //Оператор копирующего присваивания
    {
        if ((this != &copySource) && (copySource.buffer != nullptr))
        {
            if (buffer != nullptr)
                delete[] buffer;
            // Глубокое копирование в свой буфер
            buffer = new wchar_t[wcslen(copySource.buffer) + 1];
            // Копирование из исходного объекта в локальный буфер
            wcscpy_s(buffer, wcslen(copySource.buffer), copySource.buffer);
        }
        return *this;
    }
    MyString(const MyString& copySource) // Копирующий конструктор
    {
        buffer = nullptr;
        if (copySource.buffer != nullptr)
        {
            buffer = new wchar_t[wcslen(copySource.buffer) + 1];
            wcscpy_s(buffer, wcslen(copySource.buffer), copySource.buffer);
        }
    }

    MyString operator+ (const MyString& addThis)
    {
        wcout << L"operator+ : " << endl;
        MyString newStr;
        if (addThis.buffer != nullptr)
        {
            newStr.buffer = new wchar_t[GetLength() + wcslen(addThis.buffer) + 1];
            wcscpy_s(newStr.buffer, GetLength(), buffer);
            wcscat_s(newStr.buffer, wcslen(addThis.buffer) + 1, addThis.buffer);
        }
        return newStr;

    }
    const wchar_t& operator [] (int index) const
    {
        if (index < GetLength())
            return buffer[index];
        return buffer[0];
    }

    size_t GetLength() const
    {
        return wcslen(buffer);
    }

    operator const wchar_t* ()
    {
        return buffer;
    }

    ~MyString()
    {
        wcout << L"Вызов деструктора " << endl;
        if (buffer != nullptr)
            delete[] buffer;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    MyString string1(L"Hello");
    MyString string2(L"World");
    MyString string3(L" of C++");
    MyString sayHelloAgain(L"overwrite this");
    sayHelloAgain = string1 + string2 + string3;

    wcout << L"До присваивания: " << endl;
    wcout << string1 << string2 << endl;
    string2 = string1;
    wcout << L"После присваивания: " << endl;
    wcout << string1 << string2 << endl;

    wcout << L"Введите предложение : ";
    wstring strinput;
    getline(wcin, strinput);
    MyString youSaid(strinput.c_str());
    wcout << L"Ваш ввод с использованием operator [] : " << endl;
    for (int index = 0; index < youSaid.GetLength(); ++index)
        wcout << youSaid[index] << " ";
    wcout << endl;
    wcout << L"Введите индекс 0 - " << youSaid.GetLength() - 1 << ": ";
    int Inindex = 0;
    wcin >> Inindex;
    wcout << L"Искомый символ в позиции " << Inindex;
    wcout << L" - " << youSaid[Inindex] << endl;


    return 0;
}
