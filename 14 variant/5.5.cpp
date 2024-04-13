/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. «Перевернуть» второе слово,
т.е. перезаписать его наоборот. Вывести преобразованную таким образом
строку.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string reverseWord(const std::string& word) 
{
    std::string reversedWord = word;
    std::reverse(reversedWord.begin(), reversedWord.end());
    return reversedWord;
}

int main() 
{
    std::string input;
    std::cout << "Введите строку из слов, разделенных пробелами: ";
    std::getline(std::cin, input);

    std::stringstream ss(input);
    std::vector<std::string> words;
    std::string word;

    while (ss >> word) 
    {
        words.push_back(word);
    }

    if (words.size() < 2) 
    {
        std::cerr << "Недостаточно слов для преобразования. Введите как минимум два слова, разделенных пробелом." << std::endl;
        return 1;
    }

    words[1] = reverseWord(words[1]);

    for (const std::string& w : words) 
    {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    return 0;
}