#include <iostream>
#include <map>
#include <string>
#include <clocale>
#include <windows.h>

using namespace std;
typedef map <int, wstring> МAP_INT_STRING;
typedef multimap <int, wstring> ММАР_INТ_STRING;
template <typename T>

void DisplayContents(const T& cont)
{
    for (auto element = cont.cbegin(); element != cont.cend(); ++element)
    {
        wcout << element->first << " -> " << element->second << endl;
    }
    wcout << endl;

}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    МAP_INT_STRING mapintToStr; 
    // Вставка пары с исполь зованием ключевого слова value type
    mapintToStr.insert(МAP_INT_STRING::value_type(3, L"Three" ) );
    // Вставка пары с исполь зованием функции make_pair()
    mapintToStr.insert(make_pair(-1, L"Minus One"));
    // Вставка объекта пары непосредственно
    mapintToStr.insert(pair<int, wstring>(1000, L"0ne Thousand" ) ) ;
    // Вставка пары с использованием синтаксиса массива
    mapintToStr[1000000] = L"0ne Million" ; 
    wcout << L"map содержит " << mapintToStr.size () ;
    wcout << L" пары \"ключ-значение\". Это: " << endl;
    DisplayContents(mapintToStr);
    
    // Создание мультиотображения , являющегося копией отображения
    ММАР_INТ_STRING mmapintToStr(mapintToStr.cbegin(), mapintToStr.cend());
    mmapintToStr.insert(make_pair(1000, L" Thousand"));
    wcout << L"mmap содержит " << mmapintToStr.size();
    wcout << L" пары \"ключ-значение\". Это: " << endl;
    DisplayContents(mmapintToStr);
    //Число пар с одинаковым ключом
    wcout << L"Пар в multimap с ключом 1000: " << mmapintToStr.count(1000) << endl;

    wcout << L"Введите ключ для поиска: ";
    int Key = 0;
    wcin >> Key;
    //mult imap<int,wstring>::const_iterator pairFound = mapintToStr.find(Key);
    auto pairFound = mapintToStr.find(Key);
    if (pairFound != mapintToStr.end())
    {
        wcout << L"Ключ " << pairFound->first << L" указывает на ";
        wcout << L"значение " << pairFound->second << endl;
    }
    else
        wcout << L"Ключ " << Key << L" не найден" << endl;

    wcout << L"Введите ключ для поиска: ";
    wcin >> Key;
    auto ppairFound = mmapintToStr.find(Key);
    if (ppairFound != mmapintToStr.end())
    {
        //Количество пар с одинаковым ключом
        size_t numPairsinМap = mmapintToStr.count(1000);
        for (size_t counter = 0; counter < numPairsinМap; ++counter)
        {
            wcout << L"Ключ " << ppairFound->first << L" указывает на ";
            wcout << L"значение["<<counter<<"] " << ppairFound->second << endl;
            ++ppairFound;
        }
    }
    else
        wcout << L"Элемент в multimap не найден" << endl;

    //Возвращает сколько элементов было удалено
    auto nPrErsd = mmapintToStr.erase(-1);
    wcout << L"Удалено " << nPrErsd << L" пары с ключом -1 ." << endl;

    auto iPair = mmapintToStr.find(3);
    if (iPair != mmapintToStr.end())
    {
        mmapintToStr.erase(iPair);
        wcout << L"Удалена пара с ключом 3." << endl;
    }
    wcout << L"Удаление пар с кпючом 1000 ." << endl;
    mmapintToStr.erase(mmapintToStr.lower_bound(1000), mmapintToStr.upper_bound(1000));
    
    DisplayContents(mmapintToStr);
    return 0;
}

