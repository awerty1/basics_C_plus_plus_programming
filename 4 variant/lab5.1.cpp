/*
Задание 1. Вводится строка произвольного текста. Вывести на экран все
гласные буквы из этой строки. Если таких букв нет, вывести -1.
*/

#include <iostream>
#include <string>

bool isVowel(char c) 
{
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 10; i++) 
    {
        if (c == vowels[i]) 
        {
            return true;
        }
    }
    return false;
}

void findVowels(const std::string& text) 
{
    bool found = false;
    std::string unique_vowels;
    for (int i = 0; i < text.size(); i++)
    {
        char c = tolower(text[i]);
        if (isVowel(c) && unique_vowels.find(c) == std::string::npos)
        {
            unique_vowels += c;
            found = true;
        }
    }

    if (found)
    {
        for (int i = 0; i < unique_vowels.size(); i++)
        {
            std::cout << unique_vowels[i];
            if (i != unique_vowels.size() - 1)
            {
                std::cout << ", "; // comma between elements
            }
            else
            {
                std::cout << "."; // dot after last element
            }
        }
    }
    else
    {
        std::cout << -1;
    }

    std::cout << std::endl;
}

int main() 
{
    std::string input_text;
    std::cout << "Введите строку текста: ";
    std::getline(std::cin, input_text);

    std::cout << "Гласные буквы в строке: ";
    findVowels(input_text);

    return 0;
}