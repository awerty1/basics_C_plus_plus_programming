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
    std::cout << "Введите строку: ";
    std::getline(std::cin, str);

    std::string result = "";
    bool isWord = false;
    for (int i = 0; i < str.length(); ++i) 
    {
        if (str[i] == ' ') 
        {
            if (!isWord) 
            {
                result += ' ';
                isWord = true;
            }
        } 
        else 
        {
            result += str[i];
            isWord = false;
        }
    }

    std::cout << "Преобразованная строка: " << result << std::endl;
    return 0;
}