/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
b) возвратить последнюю букву латинского алфавита в первом слове 
исходной строки. Если в строке вообще нет слов, возвратить пробел;
*/

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

char getLastLatinLetterOfFirstWord(const std::string& str) 
{
    std::istringstream iss(str);
    std::string firstWord;

    // Получаем первое слово
    iss >> firstWord;

    // Проверяем, пустое ли первое слово
    if (firstWord.empty()) 
    {
        return ' '; // Возвращаем пробел, если нет слов
    }

    // Находим последнюю букву в первом слове
    for (auto it = firstWord.rbegin(); it != firstWord.rend(); ++it) 
    {
        if (std::isalpha(*it) && isascii(*it)) 
        { // Проверяем, латинская ли буква
            return *it; // Возвращаем последнюю латинскую букву
        }
    }

    return ' '; // Возвращаем пробел, если в слове нет латинских букв
}

int main() 
{
    // Примеры строк для тестирования
    std::string testStrings[] = 
    {
        "Hello, World!",
        "Привет, мир!", // Нет латинских букв
        "C++ programming.",
        "1234567890", // Нет слов
        "abcXYZabc" // Только латинские буквы
    };

    // Проверяем каждую строку
    for (const std::string& testString : testStrings) 
    {
        std::cout << "Original string: \"" << testString << "\"" << std::endl;
        char lastLetter = getLastLatinLetterOfFirstWord(testString);
        if (lastLetter == ' ') 
        {
            std::cout << "Last Latin letter: ' '" << std::endl << std::endl;
        } 
        else 
        {
            std::cout << "Last Latin letter: '" << lastLetter << "'" << std::endl << std::endl;
        }
    }

    return 0;
}