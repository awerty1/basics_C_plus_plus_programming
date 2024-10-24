/*
Задание 1. Вводится строка произвольного текста. Заменить все заглавные
буквы на единицы. Если в строке нет заглавных букв, оставить строку без
изменений. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>

int main() 
{
    std::string text;
    std::cout << "Введите строку: ";
    getline(std::cin, text); // ввод строки

    bool has_uppercase = false; // флаг, указывающий на наличие заглавных букв

    // проверяем, что строка не пустая и содержит хотя бы одну букву
    if (!text.empty() && std::any_of(text.begin(), text.end(), [](char c) 
    { 
        return std::isalpha(c); 
    })) 
    {
        for (char& c : text) 
        {
            if (isupper(c)) 
            { // если символ является заглавной буквой
                c = '1'; // заменяем его на единицу
                has_uppercase = true; // устанавливаем флаг
            }
        }

        if (has_uppercase) 
        {
            std::cout << "Преобразованная строка: " << text << std::endl;
        } 
        else 
        {
            std::cout << "Строка без изменений: " << text << std::endl;
        }
    }
    else 
    {
        std::cout << "Некорректный ввод. Введите строку, содержащую хотя бы одну букву." << std::endl;
    }

    return 0;
}
