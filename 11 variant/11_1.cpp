/*
a) функция удаления концевых пробелов из строки, которая задаётся как параметр 
функции (всех пробелов в начале и конце строки) – исходную строку оставляют без 
изменения, но возвращают новую строку с удалёнными пробелами;
*/

#include <iostream>
#include <string>

// Функция для удаления концевых пробелов из строки
std::string removeLeadingTrailingSpaces(const std::string& input)
{
    std::string result = input; // Создаем копию исходной строки

    // Удаляем пробелы в начале строки
    size_t start = result.find_first_not_of(" \t\n");
    result = (start == std::string::npos) ? "" : result.substr(start);

    // Удаляем пробелы в конце строки
    size_t end = result.find_last_not_of(" \t\n");
    result = (end == std::string::npos) ? "" : result.substr(0, end + 1);

    return result;
}

int main()
{
    std::string input;
    std::cout << "Введите строку с концевыми пробелами: ";
    std::getline(std::cin, input); // Получаем строку от пользователя

    std::string result = removeLeadingTrailingSpaces(input); // Удаляем концевые пробелы из строки

    std::cout << "Исходная строка: " << input << std::endl;
    std::cout << "Строка без концевых пробелов: " << result << std::endl;

    return 0;
}