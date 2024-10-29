/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Определить количество букв
в каждом слове.
*/

#include <iostream>
#include <string>
#include <cctype>  // Для использования isalpha

int main() 
{
    std::string input_string;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input_string);
    
    // Проверяем, если строка состоит только из пробелов, табуляций или пуста
    if (input_string.empty() || input_string.find_first_not_of(" \t") == std::string::npos) 
    {
        std::cout << "Строка не содержит буквенных символов." << std::endl;
        return 0;
    }
    
    size_t letters_in_word = 0;
    size_t word = 0;
    bool inside_word = false; // Флаг, указывающий, что мы внутри слова
    
    // Итерируем по каждому символу в строке
    for (char c : input_string) 
    {
        // Проверяем, является ли символ буквой
        if (std::isalpha(c)) 
        {
            letters_in_word++;
            inside_word = true; // Мы нашли букву, значит, мы внутри слова
        } 
        else if ((c == ' ' || c == '\t') && inside_word) 
        {
            word++;
            // Встретили пробел - выводим количество букв в слове
            std::cout << "Букв в слове " << word << ": " << letters_in_word << std::endl;
            
            // Сбрасываем счетчик букв для следующего слова
            letters_in_word = 0;
            inside_word = false;
        }
    }

    // Проверяем буквы в последнем слове (если оно не завершается пробелом)
    if (inside_word) 
    {
        if (letters_in_word > 0) 
        {
            word++;
            std::cout << "Букв в последнем слове " << word << ": " << letters_in_word << std::endl;
        }
    }
    
    return 0;
}