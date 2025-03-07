/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
b) поменять местами первое и последнее слово в заданной строке, если в 
строке только одно слово или нет слов, – оставить её без изменения. Тип функции 
– void, замену выполнять в исходной строке;
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

void swapFirstAndLastWord(std::string& sentence) 
{
    // Убираем ведущие и замыкающие пробелы
    auto trim = [](std::string& str) 
    {
        str.erase(0, str.find_first_not_of(" ")); // Убираем ведущие пробелы
        str.erase(str.find_last_not_of(" ") + 1); // Убираем замыкающие пробелы
    };
    
    trim(sentence);
    
    // Проверяем, если строка пуста
    if (sentence.empty()) return;

    std::istringstream iss(sentence);
    std::string word;
    std::vector<std::string> words;

    // Сохраняем все слова в вектор
    while (iss >> word) 
    {
        words.push_back(word);
    }

    // Если строка состоит из одного слова
    if (words.size() <= 1) 
    {
        sentence = words.empty() ? "" : words[0];
        return;
    }

    // Меняем местами первое и последнее слова
    std::swap(words.front(), words.back());

    // Формируем новую строку
    sentence = "";
    for (const auto& w : words) 
    {
        sentence += w + " ";
    }
    
    // Убираем лишний пробел в конце
    if (!sentence.empty()) 
    {
        sentence.pop_back(); // Убираем последний пробел
    }
}

int main() 
{
    // Примеры строк для тестирования
    std::string sentences[] = 
    {
        "Hello World",
        "C++ is great",
        "SingleWord",
        "",
        "   Leading and trailing spaces   "
    };

    // Проверяем каждое предложение
    for (std::string& sentence : sentences) 
    {
        std::cout << "Original sentence: \"" << sentence << "\"" << std::endl;
        swapFirstAndLastWord(sentence);
        std::cout << "Modified sentence: \"" << sentence << "\"" << std::endl << std::endl;
    }

    return 0;
}