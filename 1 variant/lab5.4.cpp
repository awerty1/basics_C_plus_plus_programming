/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран самое
короткое слово. Если таких слов несколько, вывести одно из них.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <limits>

std::string find_shortest_word(const std::string& input) 
{
    std::istringstream iss(input);
    std::string word;
    std::string shortestWord;
    int shortestLength = std::numeric_limits<int>::max();

    while (iss >> word) 
    {
        int length = word.length();
        if (length < shortestLength) 
        {
            shortestLength = length;
            shortestWord = word;
        }
    }

    return shortestWord;
}

int main() 
{
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    
     // Проверяем наустой ввод или пробелы
    if (input.empty() || input.find_first_not_of(" \t\n") == std::string::npos)
    {
        std::cout << "Некорректный ввод." << std::endl;
        return 0;
    }
    
    std::string shortestWord = find_shortest_word(input);
    std::cout << "Самое короткое слово: " << shortestWord << std::endl;

    return 0;
}
