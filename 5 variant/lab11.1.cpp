/*
a) определить, есть ли в заданной строке слова, состоящие из одного или 
двух символов (слова в строке разделены пробелами, но в конце слова может 
быть ещё знак препинания, его не считать частью слова) – логическая функция;
*/

#include <iostream>
#include <string>
#include <cctype>

// Функция isShortWord проверяет, является ли заданное слово коротким:
// - Слово считается коротким, если его длина меньше или равна 2 символам
//   и последний символ слова не является знаком пунктуации.
bool isShortWord(const std::string& word) 
{
    return word.size() <= 2 && !std::ispunct(word.back());
}

// Функция hasShortWords определяет, есть ли в заданной строке слова,
// состоящие из одного или двух символов.
bool hasShortWords(const std::string& input) 
{
    std::string word = "";
    for (char c : input) 
    {
        if (std::isspace(c)) 
        {
            // Если встречается пробел, проверяем текущее слово на короткое
            if (!word.empty() && isShortWord(word)) 
            {
                return true; // Возвращаем true, если найдено короткое слово
            }
            word = ""; // Сбрасываем текущее слово
        } 
        else 
        {
            word += c; // Добавляем символ к текущему слову
        }
    }

    // Проверяем последнее слово в строке
    if (!word.empty() && isShortWord(word)) 
    {
        return true;
    }

    return false; // Возвращаем false, если не найдено короткое слово
}

int main() 
{
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    if (hasShortWords(input)) 
    {
        std::cout << "В строке есть слова из одного или двух символов." << std::endl;
    } 
    else 
    {
        std::cout << "В строке нет слов из одного или двух символов." << std::endl;
    }

    return 0;
}