#include <iostream>
#include<vector>
#include<algorithm>
#include <windows.h>

using namespace std;
template <typename elementType>
class Multiply
{
public:
    elementType operator () (const elementType& num1, const elementType& num2)
    {
        return(num1 * num2);
    }
};
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");

    vector <int> multiplicands{0, 1, 2, 3, 4, 5};
    vector <int> multipliers{100, 101, 104, 109, 110, 111};
    vector <int> vecResult;
    vecResult.resize(multipliers.size());
    transform(multiplicands.begin(), multiplicands.end(), multipliers.begin(), vecResult.begin(), Multiply <int>());
    for (size_t index = 0; index < multiplicands.size(); ++index)
        wcout << multiplicands[index] << ' ';
    wcout << endl;
    for (size_t index = 0; index < multipliers.size(); ++index)
        wcout << multipliers[index] << ' ';
    wcout << endl;
    for (size_t index = 0; index < vecResult.size(); ++index)
        wcout << vecResult[index] << ' ';
    wcout << endl;
    return 0;
}

