/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
c) функция, которая возвращает исходную строку, дополненную пробелами до 
заданной длины (параметры – исходная строка и длина, до которой строку нужно 
дополнить пробелами, если эта длина не больше длины исходной строки, возвратить 
исходную строку). Пробелы добавляются равномерно между словами, а не в конец и 
начало строки.
*/

#include <iostream>
#include <sstream>
#include <vector>

std::string padStringWithSpaces(const std::string& str, size_t totalLength) 
{
    if (str.length() >= totalLength) 
	{
        return str; // Возвращаем исходную строку, если она длиннее или равна заданной длине
    }
    
    std::istringstream iss(str);
    std::vector<std::string> words;
    std::string word;

    // Разбиваем строку на слова
    while (iss >> word) 
	{
        words.push_back(word);
    }

    // Считаем количество пробелов, которые нужно добавить
    size_t currentLength = str.length();
    size_t spacesToAdd = totalLength - currentLength;
    
    if (words.size() <= 1) 
	{
        return str; // Нельзя равномерно распределить пробелы между словами, если меньше 2 слов
    }

    // Считаем количество пробелов между словами
    size_t gaps = words.size() - 1;
    size_t spacesPerGap = spacesToAdd / gaps; // Количество пробелов между каждым пробелом
    size_t extraSpaces = spacesToAdd % gaps;  // Остаток пробелов, которые нужно распределить

    std::string result;
    for (size_t i = 0; i < words.size(); ++i) 
	{
        if (i > 0) 
		{
            result += std::string(spacesPerGap + (i <= extraSpaces ? 1 : 0), ' '); // Добавляем пробелы
        }
        result += words[i]; // Добавляем слово
    }

    return result;
}

int main() 
{
    std::string input;
    size_t targetLength;

    // Ввод строки
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    
    // Ввод целевой длины
    std::cout << "Введите целевую длину строки: ";
    std::cin >> targetLength;

    // Вызываем функцию для дополнения строки пробелами
    std::string paddedString = padStringWithSpaces(input, targetLength);

    // Вывод результата
    std::cout << "Результат: '" << paddedString << "'" << std::endl;

    return 0;
}