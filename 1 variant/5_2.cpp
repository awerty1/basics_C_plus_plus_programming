/*
Задание 2. Вводится строка символов. Удвоить все пробелы. Вывести
преобразованную таким образом строку
*/

#include <iostream>
#include <string>

std::string doubleSpaces(const std::string& inputString) 
{
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
    std::cout << "Преобразованная строка: " << transformedString << std::endl;

    return 0;
}
