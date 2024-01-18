/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран все слова,
заканчивающиеся на букву, введенную с клавиатуры.
*/

#include <iostream>
#include <string>
#include <cctype> // Добавляем заголовочный файл для std::tolower

int main() 
{
    std::string inputString;
    char targetLetter;

    // Ввод строки символов
    std::cout << "Введите строку символов: ";
    std::getline(std::cin, inputString);
    
    // Проверка на пустую строку
    if (inputString.empty()) 
    {
        std::cout << "Ошибка: Входная строка пустая." << std::endl;
        return 0;
    }

    // Ввод целевой буквы
    std::cout << "Введите букву: ";
    std::cin >> targetLetter;
    
    // Проверка на отсутствие буквы для поиска
    if (!std::isalpha(targetLetter)) 
    {
        std::cout << "Ошибка: Буква для поиска отсутствует." << std::endl;
        return 0;
    }

    std::string word;
    std::size_t startPos = 0;
    std::size_t endPos = inputString.find(' ');

    std::cout << "Слова, заканчивающиеся на букву '" << targetLetter << "':\n";

    // Извлечение слов из строки
    while (endPos != std::string::npos) 
    {
        word = inputString.substr(startPos, endPos - startPos);
        startPos = endPos + 1;
        endPos = inputString.find(' ', startPos);

        // Проверка, заканчивается ли слово на целевую букву (учитывая регистр)
        if (!word.empty() && std::tolower(word.back()) == std::tolower(targetLetter)) 
        {
            std::cout << word << std::endl;
        }
    }

    // Обработка последнего слова
    word = inputString.substr(startPos);
    if (!word.empty() && std::tolower(word.back()) == std::tolower(targetLetter)) 
    {
        std::cout << word << std::endl;
    }

    return 0;
}