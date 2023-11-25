/*
Задание 2. С клавиатуры вводится четырехзначное число. Найти 
произведение первой и третьей его цифр.
*/

#include <iostream>

int main() 
{
    int number;
    std::cout << "Введите четырехзначное число: ";
    std::cin >> number;
    
    int digit1 = number / 1000;   // первая цифра
    int digit3 = (number / 10) % 10;   // третья цифра
    
    int product = digit1 * digit3;   // произведение цифр
    
    std::cout << "Произведение первой и третьей цифр: " << product << std::endl;
    
    return 0;
}