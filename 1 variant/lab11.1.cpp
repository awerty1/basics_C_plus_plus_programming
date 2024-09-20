/*
Следующие задания оформить в виде функций. Отдельно разработать 
демонстрационную программу для проверки работоспособности функций.
a) функция удаления концевых пробелов из строки, которая задаётся как параметр
функции (всех пробелов в начале и конце строки) – исходную строку оставляют без 
изменения, но возвращают новую строку с удалёнными пробелами;
*/

#include <iostream>
#include <string>
#include <algorithm>

// Функция, которая удаляет концевые пробелы и табы из строки
std::string trim(const std::string& str) 
{
    size_t start = str.find_first_not_of("  \t" ); // Находим первый не пробел и не таб символ
    size_t end = str.find_last_not_of(" \t");   // Находим последний не пробел и не таб символ

    // Если строка состоит только из пробелов и табуляций
    if (start == std::string::npos) 
    {
        return ""; // Возвращаем пустую строку
    }
    
    // Возвращаем новую строку без концевых пробелов и табуляций
    return str.substr(start, end - start + 1);
}

int main() 
{
    std::string input;

    // Ввод строки
    std::cout << "Введите строку с пробелами и табуляциями: ";
    std::getline(std::cin, input);

    // Вызываем функцию для удаления концевых пробелов  и табуляций
    std::string trimmedString = trim(input);

    // Вывод результата
    std::cout << "Строка без концевых пробелов и табуляций: '" << trimmedString << "'" << std::endl;

    return 0;
}