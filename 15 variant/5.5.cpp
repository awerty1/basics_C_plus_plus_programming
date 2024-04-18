/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Поменять местами
последний символ первого слова и первый символ последнего слова. Вывести
преобразованную таким образом строку. Например, было «мама мыла раму»,
должно получиться «мамр мыла ааму».
*/

#include <iostream>
#include <string>
#include <sstream>

int main() 
{
    std::string input;
    std::cout << "Введите строку из слов: ";
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::string word;
    std::string firstWord, lastWord;

    while (ss >> word) 
    {
        if (firstWord.empty()) 
        {
            firstWord = word;
        }
        lastWord = word;
    }

    if (!firstWord.empty() && !lastWord.empty()) 
    {
        std::string modifiedFirstWord = firstWord;
        modifiedFirstWord.back() = lastWord.front();

        std::string modifiedLastWord = lastWord;
        modifiedLastWord.front() = firstWord.back();

        std::cout << "Преобразованная строка: ";
        
        ss.clear();
        ss.seekg(0);  // Сброс stringstream для повторного использования
        while (ss >> word) 
        {
            if (word == firstWord) 
            {
                std::cout << modifiedFirstWord << " ";
            } 
            else if (word == lastWord) 
            {
                std::cout << modifiedLastWord << " ";
            } 
            else 
            {
                std::cout << word << " ";
            }
        }

        std::cout << std::endl;
    } 
    else 
    {
        std::cerr << "Ошибка: Недостаточно слов для преобразования." << std::endl;
    }

    return 0;
}