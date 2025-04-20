/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
a) возвратить первое слово из заданной строки (параметр функции) без 
пробелов в начале и конце и возможных знаков препинания в конце;
*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

std::string getFirstWord(const std::string& str) 
{
    size_t start = 0;
    
    // Найти первое ненулевое (не пробельное) слово
    while (start < str.length() && std::isspace(str[start])) 
    {
        ++start; // Пропуск пробелов в начале
    }

    size_t end = start;

    // Найти конец первого слова
    while (end < str.length() && !std::isspace(str[end]) && 
            str[end] != '.' && str[end] != ',' && str[end] != '!' && 
            str[end] != '?' && str[end] != ';' && str[end] != ':') 
    {
        ++end; // Пропуск символов, пока не встречаем пробел или знак препинания
    }

    // Получаем первое слово и возвращаем его
    return (start < str.length()) ? str.substr(start, end - start) : ""; // Если строка была пустой
}

int main() 
{
    // Примеры строк для тестирования
    std::string testStrings[] = 
    {
        "   Hello, world!  ",
        "   C++ programming.  ",
        "SingleWord",
        "   After the storm... ",
        "   " // Пустая строка
    };

    // Проверяем каждую строку
    for (const std::string& testString : testStrings)
    {
        std::cout << "Original string: \"" << testString << "\"" << std::endl;
        std::string firstWord = getFirstWord(testString);
        std::cout << "First word: \"" << firstWord << "\"" << std::endl << std::endl;
    }

    return 0;
}
