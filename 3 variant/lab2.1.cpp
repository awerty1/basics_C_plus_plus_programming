/*
Задание 1. Написать программу для вычисления суммы квадратов десяти 
произвольных чисел, вводимых с клавиатуры
*/

#include <iostream>

int main() 
{
    int sum = 0;

    std::cout << "Введите десять чисел:\n";
    for (int i = 0; i < 10; ++i) 
    {
        int number;
        std::cout << "Число " << i + 1 << ": ";
        std::cin >> number;

        sum += number * number;
    }

    std::cout << "Сумма квадратов: " << sum << std::endl;

    return 0;
}