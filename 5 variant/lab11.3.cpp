/*
c) удалить из заданной строки все самые длинные слова. Тип функции –
void, все изменения выполнять в исходной строке.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>

// Функция для удаления всех самых длинных слов из строки
void removeLongestWords(std::string& input)
{
    // Создаем поток для чтения из строки
    std::istringstream iss(input);
    // Создаем поток для записи в новую строку без самых длинных слов
    std::ostringstream oss;

    std::string longestWord;
    size_t maxLength = 0;
    
    // Ищем самое длинное слово в строке
    std::string word;
    while (iss >> word)
    {
        if (word.length() > maxLength)
        {
            maxLength = word.length();
            longestWord = word;
        }
    }
    
    // Сбрасываем состояние потока чтения и перемещаем курсор на начало строки
    iss.clear(); // Сбрасываем состояние потока
    iss.seekg(0); // Перемещаем курсор на начало строки

    // Формируем новую строку без самых длинных слов
    while (iss >> word)
    {
        if (word.length() != maxLength)
        {
            oss << word << " ";
        }
    }

    // Замещаем исходную строку новой строкой без самых длинных слов
    input = oss.str();
}

int main()
{
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input); // Получаем строку от пользователя

    removeLongestWords(input); // Удаляем самые длинные слова из строки

    std::cout << "Строка после удаления самых длинных слов: " << input << std::endl; // Выводим обновленную строку

    return 0;
}