/*
Задание 1. Вводится строка произвольного текста, затем вводится
произвольный символ. Найти все вхождения этого символа в строку (вывести
индексы элементов строки, которые являются этим символом). Если данного
символа нет в строке, вывести -1.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string text;
    char ch;
    
    cout << "Введите строку текста: ";
    getline(cin, text);
    
    cout << "Введите символ для поиска: ";
    cin >> ch;
    
    bool found = false;
    
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] == ch)
        {
            cout << i+1 << " ";
            found = true;
        }
    }
    
    if (!found)
    {
        cout << "-1";
    }
    
    return 0;
}