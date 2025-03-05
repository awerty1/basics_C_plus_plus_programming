/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
a) возвратить позицию первого несовпадающего символа двух строк (два 
параметра функции), если несовпадающих символов нет, возвратить -1;
*/

#include <iostream>
#include <string>

int findFirstMismatch(const std::string& str1, const std::string& str2) 
{
    size_t minLength = std::min(str1.length(), str2.length());

    // Проходим по символам обеих строк до минимальной длины
    for (size_t i = 0; i < minLength; ++i) 
    {
        if (str1[i] != str2[i]) 
        {
            return static_cast<int>(i); // Возвращаем позицию (с 0)
        }
    }

    // Если строки совпадают до минимальной длины, проверяем на неравенство длины
    if (str1.length() != str2.length()) 
    {
        return static_cast<int>(minLength); // Возвращаем позицию в строке, где длины различаются
    }

    return -1; // Если несовпадающих символов нет
}

int main() 
{
    // Примеры строк для тестирования
    std::pair<std::string, std::string> stringPairs[] = 
	{
        {"hello", "hello"},
        {"hello", "hella"},
        {"hello world", "hello there"},
        {"short", "shorter"},
        {"same", "same"}
    };

    // Проверяем каждую пару строк
    for (const auto& pair : stringPairs) 
	{
        const std::string& str1 = pair.first;
        const std::string& str2 = pair.second;

        std::cout << "Comparing: \"" << str1 << "\" and \"" 
                  << str2 << "\"." << std::endl;
        int position = findFirstMismatch(str1, str2);
        
        if (position != -1) 
        {
            std::cout << "First mismatch found at position: " 
                      << position << std::endl;
        } 
        else 
        {
            std::cout << "No mismatches found." << std::endl;
            std::cout << "Returned: " << position << std::endl;
        }

        std::cout << std::endl; // Пустая строка для разделения результатов
    }

    return 0;
}