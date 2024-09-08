/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
c) удалить все знаки препинания из заданной строки. Функция должна 
возвратить количество удалённых символов и выполнить удаление в исходной 
строке.
*/

#include <iostream>
#include <string>
#include <cctype>

int removePunctuation(std::string& str) 
{
    int count = 0;
    std::string result;

    // Проходим по всем символам строки
    for (char ch : str) 
    {
        if (std::ispunct(ch)) 
        {
            count++; // Увеличиваем счетчик удаленных символов
        } 
        else 
        {
            result += ch; // Добавляем не знаковую часть в результат
        }
    }

    // Обновляем исходную строку
    str = result;
    return count; // Возвращаем количество удаленных символов
}

int main() 
{
    // Примеры строк для тестирования
    std::string sentences[] = 
    {
        "Hello, world!",
        "C++ is great; isn't it?",
        "Тестовое предложение: удаляем знаки препинания!",
        "Не надо удалять пробелы...",
        ""
    };

    // Проверяем каждое предложение
    for (std::string& sentence : sentences) 
    {
        std::cout << "Original sentence: \"" << sentence << "\"" << std::endl;

        int removedCount = removePunctuation(sentence);

        std::cout << "Modified sentence: \"" << sentence << "\"" << std::endl;
        std::cout << "Number of removed punctuation marks: " << removedCount << std::endl << std::endl;
    }

    return 0;
}