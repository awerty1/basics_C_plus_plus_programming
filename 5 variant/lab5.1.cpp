/*
Задание 1. Вводится строка произвольного текста. Вывести на экран все
строчные буквы из этой строки. Если таких букв нет, вывести -1.
*/

#include <iostream>
#include <string>
#include <iomanip>

int main() 
{
    std::string text;
    std::cout << "Введите текст: ";
    std::getline(std::cin, text);
    
    bool hasLowerCase = false;
    
    std::cout << "Строчные буквы: ";
    for (char c : text) 
    {
        if (std::islower(c)) 
        {
            std::cout << c << std::setw(2);
            hasLowerCase = true;
        }
    }
    
    if (!hasLowerCase) 
    {
        std::cout << -1;
    }
    
    return 0;
}