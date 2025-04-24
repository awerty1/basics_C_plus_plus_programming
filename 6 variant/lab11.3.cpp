/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
c) удвоить заданный символ (задается в качестве параметра) в заданной 
строке (тоже параметр) во всех местах, где он встречается. Тип функции – void, 
удвоение символов выполнять в исходной строке
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

#include <iostream>
#include <string>

void doubleCharacter(std::string& str, char character) 
{
    std::string result; // Создаем новую строку для хранения результата
    for (char ch : str) 
    {
        result += ch; // Добавляем текущий символ
        if (ch == character) 
        {
            result += character; // Удваиваем символ, если он совпадает с заданным
        }
    }
    str = result; // Обновляем исходную строку
}

int main() 
{
    // Примеры строк для тестирования
    std::string sentences[] = 
    {
        "Hello, World!",
        "C++ programming is fun!",
        "Repeating characters: aaa, bbb, ccc",
        "No match here",
        "Single character: x"
    };
    
    char characterToDouble = 'a'; // Символ для удвоения

    // Проверяем каждую строку
    for (std::string& sentence : sentences) 
    {
        std::cout << "Original string: \"" << sentence << "\"" << std::endl;
        doubleCharacter(sentence, characterToDouble);
        std::cout << "Modified string: \"" << sentence << "\"" << std::endl << std::endl;
    }

    return 0;
}