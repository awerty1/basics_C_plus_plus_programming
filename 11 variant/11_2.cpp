/*
c) функция, которая возвращает исходную строку, дополненную пробелами до 
заданной длины (параметры – исходная строка и длина, до которой строку нужно 
дополнить пробелами, если эта длина не больше длины исходной строки, возвратить 
исходную строку). Пробелы добавляются равномерно между словами, а не в конец и 
начало строки.
*/

#include <iostream>
#include <string>
#include <cmath>

std::string addSpacesToLength(const std::string& str, int length) 
{
    if (length <= static_cast<int>(str.length())) 
    {
        return str; // Возврат исходной строки, если длина не больше длины исходной строки
    }

    std::string result = str;
    int spacesToAdd = length - static_cast<int>(str.length());
    int wordCount = 0;
    for (char c : str) 
    {
        if (std::isspace(c)) 
        {
            ++wordCount;
        }
    }

    int spacesPerWord = spacesToAdd / wordCount;
    int extraSpaces = spacesToAdd % wordCount;

    std::string spaceChunk(spacesPerWord, ' ');

    size_t pos = result.find_first_not_of(" \t\n"); // Находим начало первого слова
    while (pos != std::string::npos) 
    {
        size_t nextPos = result.find_first_of(" \t\n", pos); // Находим конец текущего слова
        if (nextPos == std::string::npos) 
        {
            nextPos = result.length();
        }

        result.insert(nextPos, spaceChunk);
        if (extraSpaces > 0) 
        {
            result.insert(nextPos, " ");
            --extraSpaces;
        }

        pos = result.find_first_not_of(" \t\n", nextPos + spacesPerWord + 1); // Находим начало следующего слова
    }

    return result;
}

int main() 
{
    //std::string str = "This is a sample string.";
    int desiredLength = 30;
    
    std::string str;
    std::cout << "Введите строку с концевыми пробелами: ";
    std::getline(std::cin, str); // Получаем строку от пользователя
    
    

    std::string result = addSpacesToLength(str, desiredLength);

    std::cout << "Original String: " << str << std::endl;
    std::cout << "String with added spaces: " << result << std::endl;

    return 0;
}