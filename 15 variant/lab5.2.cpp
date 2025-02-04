/*
Задание 2. Вводится строка произвольного текста. Удвоить все буквы в
этой строке. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>

int main() 
{
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    std::string result = "";
    for (int i = 0; i < str.length(); ++i) 
	{
        result += str[i];
        result += str[i];
    }

    std::cout << "Преобразованная строка: " << result << std::endl;
    return 0;
}

/*
version 2

#include <iostream>
#include <string>

int main() 
{
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    std::string result;
    for (char c : str) 
    {
        result += c;
        result += c;
    }

    std::cout << "Преобразованная строка: " << result << std::endl;
    return 0;
}
*/