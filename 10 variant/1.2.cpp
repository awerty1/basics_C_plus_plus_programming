/*
Задание 2. С клавиатуры вводится четырехзначное число. Найти 
произведение второй и четвертой его цифр. 
*/

#include <iostream>

int main()
{
    int number;
    std::cout << "Введите четырехзначное число: ";
    std::cin >> number;

    // Проверяем, является ли введенное число четырехзначным
    if (number < 1000 || number > 9999)
    {
        std::cout << "Ошибка! Введенное число не является четырехзначным." << std::endl;
        return 0;
    }

    int secondDigit = (number / 10) % 10;
    int fourthDigit = number % 10;

    int product = secondDigit * fourthDigit;

    std::cout << "Произведение второй и четвертой цифр числа: " << product << std::endl;

    return 0;
}