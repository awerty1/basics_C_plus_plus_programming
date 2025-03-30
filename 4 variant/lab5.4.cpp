/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран самое
длинное слово. Если таких слов несколько, вывести одно из них.
*/

#include <iostream>
#include <string>

std::string findLongestWord(const std::string& sentence) 
{
    std::string longestWord;
    std::string word;
    
    for (char c : sentence) 
    {
        if (c != ' ') 
        {
            word.push_back(c);
        } 
        else 
        {
            if (word.length() > longestWord.length()) 
            {
                longestWord = word;
            }
            
            word.clear();
        }
    }
    
    // Проверяем последнее слово в предложении
    if (!word.empty() && word.length() > longestWord.length()) 
    {
        longestWord = word;
    }
    
    return longestWord;
}

int main() 
{
    std::string sentence;
    std::cout << "Введите строку: ";
    std::getline(std::cin, sentence);
    
    std::string longestWord = findLongestWord(sentence);
    
    if (longestWord.empty()) 
    {
        std::cout << "Строка не содержит слов." << std::endl;
    } 
    else 
    {
        std::cout << "Самое длинное слово: " << longestWord << std::endl;
    }
    
    return 0;
}