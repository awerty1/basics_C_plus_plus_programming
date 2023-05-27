/*
Задание 2. Вводится строка произвольного текста. Удвоить все гласные
буквы в этой строке. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <ostream>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string strinG, symboL;
    getline(cin, strinG);
    for (int i = 0; i < strinG.length(); i++)
    {
        if ('a' == tolower(strinG[i]) || 'e' == tolower(strinG[i]) || 'i' == tolower(strinG[i]) || 'o' == tolower(strinG[i]) 
            || 'u' == tolower(strinG[i]) || 'y' == tolower(strinG[i]))
        {
            symboL = strinG[i];
            strinG.insert(i + 1, symboL);
            i++;
        }
    }
    cout << strinG;
}
