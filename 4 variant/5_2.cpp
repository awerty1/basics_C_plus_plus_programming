/*
Задание 2. Вводится строка произвольного текста, затем вводится
произвольный символ. Если этот символ есть в строке, удалить его. Вывести
преобразованную таким образом строку.
*/

#include <iostream>
#include <string>
#include <limits>
#include <cctype>

int main() 
{
    std::string text;
    char symbol;

    std::cout << "Введите строку текста: ";
    std::getline(std::cin, text);

    std::cout << "Введите символ для удаления: ";
    std::cin >> symbol;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    // Преобразование строки в нижний регистр
    for (auto& c : text) 
    {
        c = std::tolower(c);
    }

    // Преобразование символа в нижний регистр
    symbol = std::tolower(symbol);

    // Поиск и удаление символа из строки
    size_t pos = text.find(symbol);
    while (pos != std::string::npos) 
    {
        text.erase(pos, 1);
        pos = text.find(symbol);
    }

    if (text.empty()) 
    {
        std::cout << "Строка после удаления пуста." << std::endl;
    } 
    else 
    {
        std::cout << "Преобразованная строка: " << text << std::endl;
    }

    return 0;
}