/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
c) удалить слово с заданным номером (параметры – строка, из которой надо 
удалить слово, и номер слова – если слова с таким номером нет, оставить строку 
без изменения). Тип функции – void.
*/

#include <iostream>
#include <sstream>
#include <vector>

void removeWordByIndex(std::string& inputString, int index) 
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
    if (index > 0 && index <= words.size()) 
	{
        words.erase(words.begin() + (index - 1)); // Удаляем слово по индексу
    }
    
    // Обновляем строку с оставшимися словами
    inputString = "";
    for (const auto& w : words) 
	{
        inputString += w + " ";
    }

    // Удаляем последний пробел
    if (!inputString.empty()) 
	{
        inputString.pop_back();
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
    std::cout << "Введите индекс слова (начиная с 1): ";
    std::cin >> testIndex;

    // Удаление слова по индексу
    removeWordByIndex(inputString, testIndex);

    // Вывод измененной строки
    std::cout << "Измененная строка: '" << inputString << "'" << std::endl;

    return 0;
}