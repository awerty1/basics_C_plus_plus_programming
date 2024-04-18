/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран все слова,
состоящие из больше, чем n-букв (n вводится с клавиатуры). Например, n = 3,
тогда необходимо вывести все слова из четырех, пяти и т.д. букв.
*/

#include <iostream>
#include <string>
#include <sstream>

int main() 
{
    std::string input;
    std::cout << "Введите строку из слов: ";
    std::getline(std::cin, input);

    int n;
    std::cout << "Введите число n: ";
    std::cin >> n;

    std::stringstream ss(input);
    std::string word;
    
    std::cout << "Слова из " << n + 1 << " и более букв:" << std::endl;
    while (ss >> word) 
    {
        if (word.length() > n) 
        {
            std::cout << word << std::endl;
        }
    }

    return 0;
}