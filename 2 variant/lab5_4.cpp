/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран все слова,
состоящие из четырех букв.
*/

#include <iostream>
#include <string>

using namespace std; 

int main() 
{ 
    setlocale(LC_ALL, "Russian"); 
    
    string str; 
    
    cout << "Введите строку: \n"; 
    getline(cin, str); 
    
    str += ' '; 
    string word = ""; 
    for (int i = 0; i < str.length(); i++) 
    { 
        if (str[i] != ' ') 
        { 
            word += str[i]; 
        } 
        else 
        { 
            if (word.length() == 4) 
            { 
                cout << word << endl; 
            } 
            word = ""; 
        } 
    } 
    return 0; 
}
