/*
Задание 2. С клавиатуры вводится четырехзначное число. Вывести сумму 
второй и третьей цифр числа.
*/

#include <iostream>

int main() 
{
    int number;
    int digit1, digit2, digit3, digit4;
    int sum;

    std::cout << "Введите четырехзначное число: ";
    std::cin >> number;

    // Разбиение числа на цифры
    digit1 = number / 1000;
    digit2 = (number / 100) % 10;
    digit3 = (number / 10) % 10;
    digit4 = number % 10;

    // Вычисление суммы второй и третьей цифр
    sum = digit2 + digit3;

    std::cout << "Сумма второй и третьей цифр числа: " << sum << std::endl;

    return 0;
}