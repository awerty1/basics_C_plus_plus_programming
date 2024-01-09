/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран все слова,
состоящие из больше, чем n-букв (n вводится с клавиатуры). Например, n = 3,
тогда необходимо вывести все слова из четырех, пяти и т.д. букв.
*/

#include <iostream>
#include <string>

int main()
{
    std::cout << "Введите строку: ";
    std::string input;
    std::getline(std::cin, input);
    
    std::cout << "Введите число n: ";
    int n;
    std::cin >> n;
    if (std::cin.fail())
    {
        std::cout << "Ошибка при вводе числа." << std::endl;
        return 1; // или другой код ошибки
    }
    
    std::string inputCopy = input;
    std::string word;
    std::string delimiter = " ";
    size_t pos = 0;
    std::cout << "Слова, состоящие из больше, чем " << n << " букв:\n";
    try
    {
        while ((pos = inputCopy.find(delimiter)) != std::string::npos)
        {
            word = inputCopy.substr(0, pos);
            if (word.size() > n)
            {
                std::cout << word << "\n";
            }
            inputCopy.erase(0, pos + delimiter.length());
        }
        while (pos != std::string::npos)
        {
            word = inputCopy.substr(pos + delimiter.length());
            if (word.size() > n)
            {
                std::cout << word << "\n";
            }
            pos = inputCopy.find(delimiter, pos + delimiter.length());
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Ошибка: " << e.what() << std::endl;
        return 1; // или какой-то другой код ошибки
    }
    
    return 0;
}
