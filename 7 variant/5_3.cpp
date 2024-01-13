/*
Задание 3. Вводится строка произвольного текста. Определить количество
слов (слова разделяются одним пробелом; в начале и конце строки допускаются
пробелы).
*/

#include <iostream>
#include <string>
#include <cctype>
#include <exception>


int countWords(const std::string& str)
{
    int wordCount = 0;
    bool isWord = false;

    std::string modifiedStr = ' ' + str + ' '; // Добавляем пробелы в начало и конец строки

    // Перебираем каждый символ строки
    for (char c : modifiedStr) 
    {
        if (!isWord && isalpha(c)) 
        { // Изменили условие
            wordCount++;
            isWord = true;
        }
        else if (std::isspace(c)) 
        {
            isWord = false;
        }
		
    }

    return wordCount;
}

int main() 
{
    try
    {
        std::string str;
        std::cout << "Введите строку текста: ";
        getline(std::cin, str);
        
        int wordCount = countWords(str);
        std::cout << "Количество слов: " << wordCount << std::endl;  
    }
    catch (const std::exception& e)
    {
        std::cout << "Произошла ошибка: " << e.what() << std::endl;
    }
    catch (...) 
    {
        std::cout << "Произошла неизвестная ошибка." << std::endl;
    }

    return 0;
}