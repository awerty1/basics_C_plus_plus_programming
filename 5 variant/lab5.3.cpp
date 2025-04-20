/*
Задание 3. Вводится строка произвольного текста. Удалить из заданной
строки текста лишние пробелы между словами (оставить только по одному
пробелу между словами).
*/

#include <iostream>
#include <string>

int main() 
{
    std::string str;
    std::cout << "Введите строку:";
    getline(std::cin, str);

    std::string result;

    for (char c : str) 
    {
        if (std::isspace(c)) 
        {
            if (result.empty() || !std::isspace(result.back()))
            {
                result.append(1, c);
            }
        }
        else 
        {
            result.append(1, c);
        }
    }

    std::cout << "Строка после преобразования:" << result << std::endl;

    return 0;
}