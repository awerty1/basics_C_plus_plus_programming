/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Отсортировать символы в
предпоследнем слове по убыванию. Вывести преобразованную таким образом
строку.
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() 
{
    string str;
    getline(cin, str); // вводим строку с пробелами
    
    int pos = str.rfind(' '); // находим позицию последнего пробела
    int prev_pos = str.rfind(' ', pos - 1); // находим позицию предпоследнего пробела
    string prev_word = str.substr(prev_pos + 1, pos - prev_pos - 1); // получаем предпоследнее слово
    
    sort(prev_word.rbegin(), prev_word.rend()); // сортируем символы по убыванию
    
    str.replace(prev_pos + 1, pos - prev_pos - 1, prev_word); // заменяем предпоследнее слово на отсортированную версию
    
    cout << str << endl; // выводим преобразованную строку
    
    return 0;
}