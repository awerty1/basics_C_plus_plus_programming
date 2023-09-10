/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Поменять местами первое и
последнее слова. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::string swapFirstAndLastWord(const std::string& input) 
{
    std::stringstream ss(input);
    std::vector<std::string> words;

    std::string word;
    while (ss >> word) 
    {
        words.push_back(word);
    }

    if (words.size() < 2) 
    {
        // Если введено меньше двух слов, просто возвращаем исходную строку
        std::cout << "Введено 1 слово " << input << std::endl;
        return input;
    }

    std::swap(words.front(), words.back());

    std::string result;
    for (const std::string& word : words) 
    {
        result += word + " ";
    }
    // Удаляем лишний пробел в конце строки
    result.pop_back();

    return result;
}

int main() 
{
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    std::string swapped = swapFirstAndLastWord(input);
    std::cout << "Преобразованная строка: " << swapped << std::endl;

    return 0;
}
