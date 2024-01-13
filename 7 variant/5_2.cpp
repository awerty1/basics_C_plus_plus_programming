/*
Задание 2. Вводится строка произвольного текста. Удвоить все согласные в
этой строке. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>
#include <cstring>

bool is_consonant(char c) 
{
    // Функция, которая проверяет, является ли символ согласной буквой
    return !isspace(c) && !isdigit(c) && !strchr("AEIOUaeiou", c);
}

int main() 
{
    std::string input_str, output_str;
    std::cout << "Ввведите строку:";
    getline(std::cin, input_str); // Вводим строку
    
	if (input_str.empty()) 
	{
		std::cout << "Строка пуста" << std::endl;
		return 0;
	}

    bool has_consonants = false;
    for (char c : input_str) 
    {
        if (is_consonant(c)) 
        {
            has_consonants = true;
            output_str += c;
        }
        output_str += c;
    }
    
    if (!has_consonants)
    {
        std::cout << "В строке нет согласных букв" << std::endl;
    } 
    else 
    {
        std::cout << "Удвоенные согласные в этой строке:";
        std::cout << output_str << std::endl; // Выводим преобразованную строку
    }
    
    return 0;
}