/*
Задание 1. Вводится строка произвольного текста. Вывести на экран все
заглавные буквы. Если заглавных букв нет в строке, вывести -1.
*/

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string text;
    cout << "Введите строку: ";
    getline(cin, text);
    int count = 0;
    for (char str : text) // Проходим по всем символам введенной строки 
    {
        if (isupper(str)) // Если символ - заглавная буква
        {
            cout << str;
            count++;
        }
    }
    
    if(count == 0)
    {
        cout << "-1";
    }
    
    return 0;
}