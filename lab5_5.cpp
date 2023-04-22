/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. В предпоследнем слове
поменять местами первый символ с последним. Если в строке только одно
слово или совсем нет слов – оставить строку без изменения. Вывести
преобразованную таким образом строку.
*/

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string str;
    cout << "Введите строку: "; 
    getline(cin, str); // ввод строки
    
    int n = str.length();
    
    /*
    if (n == 0) 
    { 
        // если строка пуста, ничего не меняем
        cout << "Строка пустая" << str << endl;
        
        return 0;
    }
    */
    
    do
    {
        if(n <= 0)
        {
            cout << "Ошибка! Введите строку длиннее " << n << " символов: ";
            getline(cin, str);
            n = str.length();
        }
    } while (n <= 0); 
    
    // ищем предпоследнее слово
    int last_space = -1;
    int second_last_space = -1;
    for (size_t i = 0; i < n; i++) 
    {
        if (str[i] == ' ') 
        {
            second_last_space = last_space;
            last_space = i;
        }
    }
    
    // если в строке только одно слово или нет пробелов, ничего не меняем
    //if (last_space == -1 || second_last_space == -1) BUG fd fd
    //if (last_space == -1) BUG fd_
    if (last_space == n-1 || last_space == -1) 
    {
        cout << "Строка без перестановки:" << str << endl;
        
        return 0;
    }
    
    // меняем местами первый и последний символ предпоследнего слова
    int start = second_last_space + 1;
    int end = last_space - 1;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    
    cout << "Строка после перестановки:" << str << endl; // выводим преобразованную строку
    
    return 0;
}