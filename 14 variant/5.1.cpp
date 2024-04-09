/*
Задание 1. Вводится строка произвольного текста. Заменить все буквы на
дефис (-). Если в строке нет букв, оставить строку без изменений. Вывести
преобразованную таким образом строку.
*/

#include <iostream>
#include <string>
#include <algorithm>

int main() 
{
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::replace_if(str.begin(), str.end(), [](char c) 
	{
        return std::not1(std::ptr_fun<int, int>(std::isalpha))(c) &&
               std::not1(std::ptr_fun<int, int>(std::isdigit))(c) &&
               std::not1(std::ptr_fun<int, int>(std::isspace))(c);
    }, '-');

    std::cout << "Modified string: " << str << std::endl;
    return 0;
}