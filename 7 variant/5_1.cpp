/*
Задание 1. Вводится строка произвольного текста. Найти все пробелы
(вывести их индексы). Если пробелов нет в строке, вывести -1.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() 
{
    string text;
    cout << "Введите строку с пробелами:"; 
    getline(cin, text); // вводим строку с пробелами
    
    if (text.empty())
    {
        cout << "Строка пустая: -1";
        return 0;
    }

    bool found_spaces = false; // флаг, который показывает, найдены ли пробелы
    int spaces_count  = 0;
    cout << "Индексы пробелов:";
    for (int i = 0; i < text.length(); i++) 
    {
        if (text[i] == ' ') 
        {
            spaces_count ++;
            if (i != text.length()-1)
            {
                cout << setw(2) << i << ", "; // выводим индекс с запятой
                found_spaces = true;
            }
            else if (i == text.length()-1)
            {
                cout << setw(2) << i << "."; // выводим последний индекс с точкой
                found_spaces = true;
            }
        }
        
    }
    cout << "\nКоличество пробелов в строке:" << spaces_count;

    if (!found_spaces) 
    {
        cout << "\nПробелов нет в строке: ";
        cout << "-1"; // если пробелов нет, выводим -1
    }

    return 0;
}