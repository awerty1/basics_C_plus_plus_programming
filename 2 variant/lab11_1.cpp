/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
a) подсчитать количество слов в строке, которая является параметром 
функции – исходную строку оставить без изменения;
*/

#include <iostream>
#include <sstream>
#include <string>

size_t countWords(const std::string& str) 
{
    std::istringstream iss(str);
    std::string word;
    size_t wordCount = 0;

    // Счетчик слов
    while (iss >> word) 
    {
        wordCount++; // Увеличиваем счетчик за каждое найденное слово
    }

    return wordCount;
}

int main() 
{
    std::string input;

    // Ввод строки
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    // Вызываем функцию для подсчета слов
    size_t numWords = countWords(input);

    // Вывод результата
    std::cout << "Количество слов в строке: " << numWords << std::endl;

    return 0;
}