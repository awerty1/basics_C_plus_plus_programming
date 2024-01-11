/*
Задание 3. Вводится строка символов. Удалить все пробелы в начале и
конце строки, если они там есть. Предусмотреть вариант, когда в начале и (или)
конце строки пробелы отсутствуют. Вывести преобразованную таким образом
строку.
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
   
    int s = 0, e = str.length() - 1; 
    for (int i = 0; i < str.length(); i++) 
    { 
        if (str[i] != ' ') 
        { 
            s = i; 
            break; 
        } 
    } 
    for (int i = str.length() - 1; i >= 0; i--) 
    { 
        if (str[i] != ' ') 
        { 
            e = i; 
            break; 
        } 
    } 
    
    string result = str.substr(s, e - s + 1); 
    cout << "Преобразованная строка: \n" << result ; 

    return 0; 
}
