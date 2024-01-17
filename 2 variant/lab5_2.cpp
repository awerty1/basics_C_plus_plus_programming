/*
Задание 2. Вводится строка произвольного текста, затем вводится
произвольный символ. Если этот символ есть в строке, удвоить его. Вывести
преобразованную таким образом строку.
*/

#include <iostream>
#include <string>

using namespace std; 

int main() 
{ 
    setlocale(LC_ALL, "Russian");
     
    string str; 
    char s; 
    cout << "Введите строку \n"; 
    getline(cin, str); 
    
    cout << "Введите символ \n"; 
    cin >> s; 
    
    for (int i = 0; i<str.length(); i++) 
    { 
        if (str[i] == s) 
        {
            str.insert(i, 1, s); 
            i++; 
        }
    } 
    
    cout << "Преобразованная строка: " << str; 
}
