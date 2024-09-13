/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
a) удалить из заданной строки все символы, которые не являются буквами 
латинского алфавита. Тип функции – void, удаление выполнять в исходной 
строке, которая является параметром функции;
*/

#include <iostream>
#include <string>
#include <cctype>

void removeNonLatinCharacters(std::string& str) 
{
    std::string result; // Создаем строку для хранения результата

    // Проходим по каждому символу в строке
    for (char ch : str) 
	{
        // Проверяем, является ли символ латинской буквой (верхнего или нижнего регистра)
        if (std::isalpha(ch) && (isascii(ch))) 
		{
            result += ch; // Добавляем к результату, если буква
        }
    }

    str = result; // Обновляем исходную строку
}


int main() 
{
    // Примеры строк для тестирования
    std::string testStrings[] = 
	{
        "Hello, World! 2024",
        "Привет, мир!", // Не латинские символы
        "C++ programming!!!",
        "1234567890", // Только цифры
        "abcXYZabc" // Только латинские буквы
    };

    // Проверяем каждую строку
    for (std::string& testString : testStrings) 
	{
        std::cout << "Original string: \"" << testString << "\"" << std::endl;
        removeNonLatinCharacters(testString);
        std::cout << "Modified string: \"" << testString << "\"" << std::endl << std::endl;
    }

    return 0;
}
