/*
Задание 2. Вводится строка произвольного текста, затем вводится
произвольный символ. Если этот символ есть в строке, удалить его. Вывести
преобразованную таким образом строку
*/

#include <iostream>
#include <string>
#include <algorithm>

int main() 
{
    std::string str;
    char delim;

    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::cout << "Enter a character to delete: ";
    std::cin >> delim;

    str.erase(std::remove(str.begin(), str.end(), delim), str.end());

    std::cout << "Modified string: " << str << std::endl;
    return 0;
}
