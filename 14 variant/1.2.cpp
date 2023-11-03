/*
Задание 2. Вводятся два целых трехзначных числа. Вывести произведение 
центральных цифр этих чисел. Например, для 657 и 421 произведение будет 
равно 10.
*/

#include <iostream>

int getCentralDigit(int number) 
{
    return (number / 10) % 10;
}

int main() 
{
    int number1, number2;
    int digit1, digit2;

    std::cout << "Введите два трехзначных числа:\n";

    // Ввод первого числа и проверка на корректность
    do 
    {
        std::cout << "Число 1: ";
        std::cin >> number1;

        if (number1 < 100 || number1 > 999) 
        {
            std::cout << "Некорректный ввод. Число должно быть трехзначным.\n";
        }
    } 
    while (number1 < 100 || number1 > 999);

    // Ввод второго числа и проверка на корректность
    do 
    {
        std::cout << "Число 2: ";
        std::cin >> number2;

        if (number2 < 100 || number2 > 999) 
        {
            std::cout << "Некорректный ввод. Число должно быть трехзначным.\n";
        }
    }
    while (number2 < 100 || number2 > 999);

    // Получение центральной цифры первого числа
    digit1 = getCentralDigit(number1);

    // Получение центральной цифры второго числа
    digit2 = getCentralDigit(number2);

    // Вычисление произведения центральных цифр
    int product = digit1 * digit2;

    std::cout << "Произведение центральных цифр: " << product << std::endl;

    return 0;
}