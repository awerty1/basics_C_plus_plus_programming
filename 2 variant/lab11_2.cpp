/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
b) возвратить слово с заданным номером (если такого слова нет, возвратить 
пустую строку) – исходную строку оставить без изменения;
*/

#include <iostream>
#include <sstream>
#include <vector>

std::string getWordByIndex(const std::string& inputString, int index) 
{
    std::istringstream iss(inputString);
    std::string word;
    std::vector<std::string> words;

    // Разбиваем строку на слова
    while (iss >> word) 
	{
        words.push_back(word);
    }

    // Проверяем, существует ли слово с заданным индексом
    if (index >= 0 && index < words.size()) 
    {
        return words[index];
    } 
    else 
    {
        return "";
    }
}

// Демонстрационная программа
int main() 
{
    std::string inputString;
    int testIndex;
    
    // Ввод строки с клавиатуры
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);
    
    // Вывод самой строки
    std::cout << "Вводимая строка: '" << inputString << "'" << std::endl;
    
    // Ввод индекса
    std::cout << "Введите индекс слова (начиная с 0): ";
    std::cin >> testIndex;
    
    // Получение слова по индексу
    std::string result = getWordByIndex(inputString, testIndex);
    if (!result.empty()) 
    {
        std::cout << "Слово с индексом " << testIndex << ": '" << result << "'" << std::endl;
    } 
    else 
    {
        std::cout << "Слово с индексом " << testIndex << " не найдено." << std::endl;
    }

    return 0;
}