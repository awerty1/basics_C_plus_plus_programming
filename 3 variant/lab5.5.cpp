/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами, причем слова могут
разделяться более чем одним пробелом, в начале и конце строки пробелы также
допускаются. Удвоить гласные буквы в предпоследнем слове введенной строки.
Если в строке только одно слово или совсем нет слов – оставить строку без
изменения. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_vowel(char c) 
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

string double_vowels(string word) 
{
    string res;
    
    for (char c : word) 
    {
        if (is_vowel(c)) 
        {
            res += c;
        }
        
        res += c;
    }
    
    return res;
}
    
int main() 
{
    string s;
    getline(cin, s);
    
    vector<string> words;
    string word;
    
    for (char c : s) 
    {
        if (isspace(c)) 
        {
            if (!word.empty()) 
            {
                words.push_back(word);
            }
            word = "";
        } 
        else 
        {
            word += c;
        }
    }
    
    if (!word.empty()) 
    {
        words.push_back(word);
    }
    
    if (words.size() <= 1) 
    {
        cout << s << endl;
        return 0;
    }
    
    words[words.size() - 2] = double_vowels(words[words.size() - 2]);
    
    string res;
    for (string word : words) 
    {
        res += word + " ";
    }
    
    res.pop_back();
    
    cout << res << endl;
    
    return 0;
}