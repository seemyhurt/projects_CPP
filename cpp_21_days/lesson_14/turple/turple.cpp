#include <iostream>
#include <tuple>
#include <string>
#include <windows.h>

using namespace std;
template <typename tupleType>
void DisplayTupleInfo(tupleType& tup)
{
    const int numМemЬers = tuple_size<tupleType>::value;
    wcout << L"Элементов в кортеже : " << numМemЬers << endl;
    wcout << L"Последний элемент : " << get<numМemЬers - 1>(tup) << endl;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    tuple<int, wchar_t, wstring>tupl(make_tuple(101, 's', L"Hello Tuple ! "));
    DisplayTupleInfo(tupl);
    auto tup2(make_tuple(3.14, false)); 
    DisplayTupleInfo(tup2);
    auto concatTup(tuple_cat(tup2, tupl)); // Члены tup2, tupl
    DisplayTupleInfo(concatTup);
    double pi;
    wstring sentence;
    tie(pi, ignore, ignore, ignore, sentence) = concatTup;
    wcout << L" Pi : " << pi << L" и \"" << sentence << L"\"" << endl;
    return 0;



}

