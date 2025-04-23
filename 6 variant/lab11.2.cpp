/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
b) удалить последнее слово из заданной строки. Тип функции – void, 
удаление выполнять в исходной строке;
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

void removeLastWord(std::string& str) 
{
    // Убираем ведущие пробелы в конце строки
    size_t end = str.find_last_not_of(" ");
    
    if (end == std::string::npos) 
    { 
        str.clear(); // Если строка состоит только из пробелов
        return;
    }

    // Берем строку без пробелов в конце
    str.erase(end + 1); // Удаляем все после последнего слова, включая его пробел
    size_t lastSpace = str.find_last_of(" "); // Находим последний пробел

    if (lastSpace != std::string::npos) 
    {
        str.erase(lastSpace); // Удаляем все после последнего пробела
    } 
    else 
    {
        str.clear(); // Если пробела нет, очищаем строку
    }
}

int main() 
{
    // Примеры строк для тестирования
    std::string testStrings[] = 
    {
        "Hello, world!",
        "C++ programming is awesome",
        "SingleWord",
        "Remove the last word   ",
        "" // Пустая строка
    };

    // Проверяем каждую строку
    for (std::string& testString : testStrings) 
    {
        std::cout << "Original string: \"" << testString << "\"" << std::endl;
        removeLastWord(testString);
        std::cout << "Modified string: \"" << testString << "\"" << std::endl << std::endl;
    }

    return 0;
}

