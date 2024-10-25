/*
Задание 2. Вводится строка произвольного текста. Удалить все согласные
буквы в этой строке. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

int main() 
{
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    // Проходим по каждому символу в строке
    for (int i = 0; i < str.length(); i++) 
    {
        // Проверяем, является ли символ согласной буквой
        char to_lower = std::tolower(str[i]);
        if (std::isalpha(to_lower) && !std::strchr("aeiou", to_lower)) 
        {
            // Удаляем символ из строки
            str.erase(i, 1);
            i--; // Уменьшаем индекс, чтобы не пропустить следующий символ
        }
    }

    std::cout << "Преобразованная строка: " << str << std::endl;
    return 0;
}