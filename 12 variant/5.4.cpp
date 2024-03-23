/*
Задание 4. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Вывести на экран все слова,
состоящие из меньше, чем n-букв (n вводится с клавиатуры). Например, n = 4,
тогда необходимо вывести все слова из одной, двух и трех букв.
*/

#include <iostream>
#include <string>
#include <sstream>

int main() 
{
    std::string inputString;
    int n;
    
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);
    
    std::cout << "Введите значение n: ";
    std::cin >> n;
    
    // Разделение введенной строки на слова
    std::stringstream ss(inputString);
    std::string word;
    
    while (ss >> word) 
	{
        // Проверка длины слова и вывод на экран, если количество букв меньше n
        if (word.length() < n) 
		{
            std::cout << word << std::endl;
        }
    }
    
    return 0;
}