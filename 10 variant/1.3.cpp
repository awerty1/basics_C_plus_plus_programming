/*
Задание 3. Вводятся три произвольных числа. Проверить, не является ли 
одно из них суммой двух других.
*/

#include <iostream>
#include <limits>
#include <string>

void validateInput(int& number, const std::string& message)
{
    while (true)
    {
        std::cout << message;
        std::cin >> number;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода. Пожалуйста, введите число." << std::endl;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int number1, number2, number3;

    validateInput(number1, "Введите число 1: ");
    validateInput(number2, "Введите число 2: ");
    validateInput(number3, "Введите число 3: ");

    bool isSum = (number1 == number2 + number3) || (number2 == number1 + number3) || (number3 == number1 + number2);

    if (isSum)
    {
        std::cout << "Одно из чисел является суммой двух других чисел." << std::endl;
    }
    else
    {
        std::cout << "Ни одно из чисел не является суммой двух других чисел." << std::endl;
    }

    return 0;
}