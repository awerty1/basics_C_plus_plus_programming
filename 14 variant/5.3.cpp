/*
Задание 3. Вводится строка символов. Определить количество букв в
последнем слове. Предусмотреть вариант, когда в конце строки есть пробелы.
*/

#include <iostream>
#include <string>

int main() 
{
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    int last_word_length = 0;
    std::string last_word = "";

    for (char c : str) 
    {
        if (c != ' ') 
        {
            last_word += c;
        } 
        else 
        {
            if (!last_word.empty()) 
            {
                last_word_length = last_word.length();
                last_word.clear();
            }
        }
    }

    if (!last_word.empty()) 
    {
        last_word_length = last_word.length();
    }

    std::cout << "The last word has " << last_word_length << " letters." << std::endl;

    return 0;
}