/*
Задание 2. Вводится строка произвольного текста, затем вводится
произвольный символ. Если этот символ есть в строке, удвоить его. Вывести
преобразованную таким образом строку
*/

#include <iostream>
#include <string>

int main() 
{
    std::string inputString;
    char characterToDouble;
    
    std::cout << "Введите строку текста: ";
    std::getline(std::cin, inputString);
    
    std::cout << "Введите символ для удвоения: ";
    std::cin >> characterToDouble;
    std::cin.ignore(); // Очистка символа новой строки
    
    for (char& c : inputString) 
	{
        if (c == characterToDouble) 
		{
            c = c * 2;
        }
    }
    
    std::cout << "Преобразованная строка: " << inputString << std::endl;
    
    return 0;
}