/*
Задание 3. Вводятся две строки произвольного текста. Найти позицию
первого несовпадающего символа. Предусмотреть случай, когда
несовпадающих символов нет.
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
    string strinG, strinGG;
    getline(cin, strinG);
    getline(cin, strinGG);
    int i = 0;
    for (; i < strinG.length(); i++)
    {
        if (strinG[i]!=strinGG[i])
        {
            break;
        }
    }
    if (strinG.empty() || strinGG.empty())
    {
        cout << "Вы не ввели строку!";
    }
    if (i==strinG.length() && strinGG.length() == strinG.length())
    {
        cout << "Несовпадающих нет";
    }
    else
    {
        cout << "Символ в позиции " << i+1 << " не совпадает";
    }
}
