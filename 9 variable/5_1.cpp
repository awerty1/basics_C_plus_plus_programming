/*
Задание 1. Вводится строка произвольного текста. Заменить все строчные
буквы на нули. Если в строке нет строчных букв, оставить строку без
изменений. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <ostream>
#include <string>
#include <cstring>

using namespace std;

int main() 
{
    setlocale(LC_ALL, "Russian");
    string str = "";
    cout << "Введите строку ";
    getline(cin, str);
    
    for(int i = 0; i<str.length();i++)
    {
        if(islower(str[i]))
            str[i]='0';
    }
    
    cout << str;
}