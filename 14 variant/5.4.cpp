/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран самое
короткое слово. Если таких слов несколько, вывести одно из них.
*/

#include <iostream>
#include <string>
#include <algorithm>

int main() 
{
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::string shortest_word = "";
    std::string current_word = "";
    std::string::iterator it = str.begin();
    
    while (it != str.end()) 
    {
        if (*it != ' ') 
        {
            current_word += *it;
        } 
        else 
        {
            if (!current_word.empty() && (shortest_word.empty() || current_word.length() < shortest_word.length())) 
            {
                shortest_word = current_word;
            }
            current_word.clear();
        }
        it++;
    }

    // Check the last word
    if (!current_word.empty() && (shortest_word.empty() || current_word.length() < shortest_word.length())) 
    {
        shortest_word = current_word;
    }

    std::cout << "The shortest word is: " << shortest_word << std::endl;

    return 0;
}