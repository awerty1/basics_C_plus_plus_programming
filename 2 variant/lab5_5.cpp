#include <iostream>
/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Во втором слове, если оно
есть, поменять местами первый символ с последним. Вывести преобразованную
таким образом строку.
*/

#include <string>

using namespace std; 

int main() { 
setlocale(LC_ALL, "Russian"); 
string str; 
 cout << "Введите строку: \n"; 
 getline(cin, str); 
string word; 
 cout << "Преобразованная строка: \n"; 
int k = 0; 
for (int i = 0; i < str.length(); i++) 
 { 
 if (str[i] == ' '); 
 { 
 if (k == 1) 
 { 
 swap(word[0], word[word.length() - 1]); 
 } 
 cout << word << " "; 
 word = ""; 
 k++; 
 } 
 else { 
 if (k == 1) 
 { 
 word += str[i]; 
 } 
 else { 
 cout << str[i]; 
 } 
 } 
 } 
if (k == 1) { 
 swap(word[0], word[word.length() - 1]); 
 } 
 cout << word; 
 
}