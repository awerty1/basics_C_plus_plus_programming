/*
Задание 1. Вводится строка произвольного текста. Найти все пробелы
(вывести их индексы). Если пробелов нет в строке, вывести -1.
*/

#include <iostream>
#include <string>
#include <iomanip>


int main() 
{
    std::string text;
    std::cout << "Введите строку с пробелами:"; 
    getline(std::cin, text); // вводим строку с пробелами
    
    if (text.empty())
    {
        std::cout << "Строка пустая: -1";
        return 0;
    }

    bool found_spaces = false; // флаг, который показывает, найдены ли пробелы
    int spaces_count  = 0;
    std::cout << "Индексы пробелов:";
    for (int i = 0; i < text.length(); i++) 
    {
        if (text[i] == ' ') 
        {
            spaces_count ++;
            if (i != text.length()-1)
            {
                std::cout << std::setw(2) << i << ", "; // выводим индекс с запятой
                found_spaces = true;
            }
            else if (i == text.length()-1)
            {
                std::cout << std::setw(2) << i << "."; // выводим последний индекс с точкой
                found_spaces = true;
            }
        }
        
    }
    std::cout << "\nКоличество пробелов в строке:" << spaces_count;

    if (!found_spaces) 
    {
        std::cout << "\nПробелов нет в строке: ";
        std::cout << "-1"; // если пробелов нет, выводим -1
    }

    return 0;
}