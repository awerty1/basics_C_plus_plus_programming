/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. Отсортировать символы в
предпоследнем слове по возрастанию. Вывести преобразованную таким
образом строку.
*/

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::cout << "Введите строку: ";
    std::string input;
    std::getline(std::cin, input);

    // Находим первую позицию символа, отличного от пробела или табуляции
    size_t firstNonSpacePos = input.find_first_not_of(" \t");

    // Если в строке только пробелы и табуляции, выводим сообщение
    if (firstNonSpacePos == std::string::npos)
    {
        std::cout << "Строка состоит только из пробелов и табуляций." << std::endl;
        return 0;
    }

    // Находим последнюю позицию символа, отличного от пробела или табуляции
    size_t lastNonSpacePos = input.find_last_not_of(" \t");

    // Извлекаем подстроку без начальных и конечных пробелов и табуляции
    std::string trimmedInput = input.substr(firstNonSpacePos, lastNonSpacePos - firstNonSpacePos + 1);

    // Находим позиции пробелов и табуляции
    size_t lastSpacePos = trimmedInput.find_last_of(" \t");
    size_t secondLastSpacePos = trimmedInput.find_last_of(" \t", lastSpacePos - 1);

    if (secondLastSpacePos != std::string::npos && lastSpacePos != std::string::npos)
    {
        // Извлекаем предпоследнее слово
        std::string secondLastWord = trimmedInput.substr(secondLastSpacePos + 1, lastSpacePos - secondLastSpacePos - 1);

        // Сортируем символы в предпоследнем слове
        std::sort(secondLastWord.begin(), secondLastWord.end());

        // Заменяем предпоследнее слово в подстроке
        trimmedInput.replace(secondLastSpacePos + 1, lastSpacePos - secondLastSpacePos - 1, secondLastWord);

        // Обновляем исходную строку с учетом обрезанных пробелов и табуляции
        input.replace(firstNonSpacePos, lastNonSpacePos - firstNonSpacePos + 1, trimmedInput);
        std::cout << "Преобразованная строка: " << input << std::endl;
    }
    else
    {
        std::cout << "Введенная строка некорректна." << std::endl;
    }

    return 0;
}