/*
Задание 2. С клавиатуры вводится четырехзначное число. Найти
произведение первой и третьей его цифр.
*/

#include <iostream>
#include <limits>

int main()
{
    int number;
    
    do
    {
        std::cout << "Введите четырехзначное число: ";
        if (!(std::cin >> number))
        {
            std::cout << "Ошибка ввода символов!" << std::endl;
            
            // Очищаем входной буфер
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (number < 1000 || number > 9999)
        {
            std::cout << "Ошибка, вы введи не четырехзначное число!" << std::endl;
        }
    }
    while(number < 1000 || number > 9999 || std::cin.fail());
    
    int digit1 = number / 1000;   // первая цифра
    int digit3 = (number / 10) % 10;   // третья цифра
    
    int product = digit1 * digit3;   // произведение цифр
    
    std::cout << "Произведение первой и третьей цифр: " << product << std::endl;
    
    return 0;
}
