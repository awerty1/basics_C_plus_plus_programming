/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
c) удвоить слово с заданным номером (параметры – строка, в которой надо 
удвоить слово, и номер слова – если слова с таким номером нет, оставить строку 
без изменения). Тип функции – void.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void doubleWordAtIndex(std::string& str, int index) 
{
    std::istringstream iss(str);
    std::vector<std::string> words;
    std::string word;

    // Считываем все слова в вектор
    while (iss >> word) 
    {
        words.push_back(word);
    }

    // Проверяем корректность индекса
    if (index < 1 || index > words.size()) 
    {
        return; // Если индекса нет, ничего не меняем
    }

    // Увеличиваем строку с удвоенным словом
    std::string wordToDouble = words[index - 1]; // Индексы начинаются с 0
    std::string updatedString;

    // Собираем строку заново
    for (size_t i = 0; i < words.size(); ++i) 
    {
        // И если индекс совпадает, удваиваем слово
        if (i == index - 1) 
        {
            updatedString += wordToDouble + " " + wordToDouble + " ";
        } 
        else 
        {
            updatedString += words[i] + " ";
        }
    }

    // Убираем лишний пробел в конце
    updatedString.erase(updatedString.size() - 1);

    str = updatedString; // Обновляем исходную строку
}

int main() {
    // Примеры строк для тестирования
    std::string testStrings[] = 
    {
        "Hello World from C++!",
        "This is a test.",
        "Just one word",
        "Another example with multiple words",
        ""
    };

    // Номера слов для удвоения
    int indices[] = {2, 4, 6, 1, 1}; // Для первых двух примеров
    int numberOfTests = sizeof(testStrings) / sizeof(testStrings[0]);

    // Проверяем каждую строку
    for (int i = 0; i < numberOfTests; ++i) 
    {
        std::cout << "Original string: \"" << testStrings[i] << "\"" << std::endl;

        doubleWordAtIndex(testStrings[i], indices[i]);
        
        std::cout << "Modified string: \"" << testStrings[i] << "\"" << std::endl << std::endl;
    }

    return 0;
}