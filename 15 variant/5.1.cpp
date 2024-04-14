/*
Задание 1. Вводится строка произвольного текста. Заменить все пробелы
на дефис (-). Если в строке нет пробелов, оставить строку без изменений.
Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>

int main() 
{
    std::string str;
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    for (int i = 0; i < str.length(); ++i) 
    {
        if (str[i] == ' ') 
        {
            str[i] = '-';
        }
    }

    std::cout << "Преобразованная строка: " << str << std::endl;
    return 0;
}
