/*
Задание 2. Вводится строка произвольного текста. Удвоить все цифры в
этой строке. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>

std::string doubleDigits(const std::string& str) 
{
    std::string result;
    for (char c : str) 
    {
        if (std::isdigit(c)) 
        {
            result += c;
            result += c;
        } 
        else 
        {
            result += c;
        }
    }
    return result;
}

int main() 
{
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    
    std::string doubledString = doubleDigits(input);
    std::cout << "Преобразованная строка: " << doubledString << std::endl;
    
    return 0;
}
