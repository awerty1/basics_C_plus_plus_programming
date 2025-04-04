/*
b) возвратить самое длинное слово строки, которая является параметром
функции. Если таких слов несколько, возвратить самое первое из них. Исходную
строку оставить без изменения;
*/

#include <iostream>
#include <string>
#include <cctype>

std::string findLongestWord(const std::string& input)
{
    std::string longestWord = "";
    std::string currentWord = "";

    for (char c : input)
    {
        if (std::isalnum(c) || std::ispunct(c)) // Проверка на символ, цифру
        {
            currentWord += c;
        }
        else if (!currentWord.empty())
        {
            if (currentWord.length() > longestWord.length())
            {
                longestWord = currentWord;
            }
            currentWord = "";
        }
    }

    if (currentWord.length() > longestWord.length())
    {
        longestWord = currentWord;
    }

    return longestWord;
}

int main()
{
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    std::string longestWord = findLongestWord(input);

    if (!longestWord.empty())
    {
        std::cout << "Самое длинное слово в строке: " << longestWord << std::endl;
    }
    else
    {
        std::cout << "В строке нет слов." << std::endl;
    }

    return 0;
}
