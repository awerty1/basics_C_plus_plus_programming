/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Отсортировать символы во
втором слове по убыванию. Вывести преобразованную таким образом строку.
*/

#include <iostream>
#include <string>
#include <algorithm>

int main() 
{
    std::string input;
    std::cout << "Введите строку:";
    std::getline(std::cin, input); // Ввод строки символов

    // Поиск второго слова
    size_t start = input.find_first_not_of(' ');
    size_t end = input.find(' ', start);
    size_t secondWordStart = input.find_first_not_of(' ', end);
    size_t secondWordEnd = input.find(' ', secondWordStart);
    if (secondWordEnd == std::string::npos) 
    {
        secondWordEnd = input.length();
    }
    
    // Проверка наличия второго слова
    if (secondWordStart == std::string::npos) 
    {
        std::cout << "Введено только одно слово." << std::endl;
        return 0;
    }
    
    std::cout << "secondWordStart:" << secondWordStart << std::endl;
    std::cout << "secondWordEnd:" << secondWordEnd << std::endl;

    // Проверка, нужно ли выполнять сортировку
    bool needsSorting = false;
    for (size_t i = secondWordStart + 1; i < secondWordEnd; ++i) 
    {
        if (input[i] > input[i - 1]) 
        {
            needsSorting = true;
            break;
        }
    }
    
    // Сортировка символов во втором слове по убыванию
    if (needsSorting) 
    {
        std::sort(input.begin() + secondWordStart, input.begin() + secondWordEnd, std::greater<char>());
    }
    

    // Вывод преобразованной строки
    std::cout << "Преобразованная строка: " << input << std::endl;

    return 0;
}