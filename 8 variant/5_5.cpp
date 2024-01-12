/*
Задание 5. Вводится строка символов, которые разделены на слова.
Пробелы являются разделителями между словами. «Перевернуть»
предпоследнее слово, т.е. перезаписать его наоборот. Вывести преобразованную
таким образом строку.
*/

#include <iostream>
#include <cstring>

int main() 
{
    int MAX_LENGTH = 100;
    char str[MAX_LENGTH];
    std::cout << "Ввведите строку: ";
    
    // Считываем строку с клавиатуры
    std::cin.getline(str, MAX_LENGTH);
    
    // "Переворачиваем" предпоследнее слово
    int len = strlen(str);
    int last_space = -1; // последняя позиция пробела
    int second_last_space = -1; // предпоследняя позиция пробела
    for (int i = 0; i < len; i++) 
    {
        if (isspace(str[i]))  // если текущий символ - пробел
        {
            second_last_space = last_space; // присваиваем переменной second_last_space значение переменной last_space
            last_space = i; // сохраняем позицию текущего пробела в last_space
        }
    }
    
    if (last_space < 0) // если в строке меньше двух слов
    {
        std::cout << "Ошибка: в строке меньше двух слов." 
                  << last_space 
                  << std::endl;
        return 1;
    }
    
    if (second_last_space < 0) // если второго пробела нет
    {
         // Если второго пробела нет, переворачиваем последнее слово
        for (int i = second_last_space + 1, j = last_space - 1; i < j; i++, j--) 
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
    else
    {
         // Иначе переворачиваем предпоследнее слово
        for (int i = second_last_space + 1, j = last_space - 1; i < j; i++, j--) 
        {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
    
    std::cout << "Преобразованная строка: " << str << std::endl;
    return 0;
}