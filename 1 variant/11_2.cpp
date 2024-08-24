/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
b) функция для удаления лишних пробелов между словами (оставить по одному 
пробелу, удалить концевые пробелы) – функция должна удалить пробелы в исходной 
строке, её тип – void;
*/

#include <iostream>
#include <string>
#include <sstream>

void removeExtraSpaces(std::string& str) 
{
    // Удаляем концевые пробелы
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos) 
    {
        str = ""; // Если строка состоит только из пробелов и табуляций
        return;
    }

    str = str.substr(start, end - start + 1); // Оставляем строку без концевых пробелов

    std::istringstream iss(str);
    std::string word;
    std::string result;

    // Читаем слова и собираем их с одним пробелом между
    while (iss >> word) 
    {
        if (!result.empty()) 
        {
            result += ' '; // Добавляем пробел перед следующим словом
        }
        result += word; // Добавляем слово к результату
    }

    str = result; // Обновляем исходную строку
}

int main() 
{
    std::string input;

    // Ввод строки
    std::cout << "Введите строку с лишними пробелами: ";
    std::getline(std::cin, input);

    // Вызываем функцию для удаления лишних пробелов
    removeExtraSpaces(input);

    // Вывод результата
    std::cout << "Строка без лишних пробелов: '" << input << "'" << std::endl;

    return 0;
}