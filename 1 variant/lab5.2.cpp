/*
Задание 2. Вводится строка символов. Удвоить все пробелы. Вывести
преобразованную таким образом строку
*/

#include <iostream>
#include <string>

std::string doubleSpaces(const std::string& inputString) 
{
    if (inputString.empty()) 
    {
        // Если введенная строка пустая, возвращаем пустую строку
        return "String is empty!";
    }
    
    std::string result;
    
    // Проходим по каждому символу в исходной строке
    for (char c : inputString) 
    {
        // Если текущий символ - пробел, добавляем два пробела к результату
        if (c == ' ') 
        {
            result += "  ";
        } 
        else 
        {
            // Иначе, добавляем символ как есть
            result += c;
        }
    }
    
    return result;
}

int main() 
{
    std::string inputString;
    
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);
    
    std::string transformedString = doubleSpaces(inputString);
    if (transformedString != "String is empty!")
    {
        std::cout << "Преобразованная строка: " << transformedString << std::endl;
    }
    else
    {
        std::cout << transformedString;
    }
    
    return 0;
}
