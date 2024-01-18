/*
Задание 1. Написать программу для вычисления среднего арифметического 
десяти произвольных чисел, вводимых с клавиатуры. 
*/

#include <iostream>
#include <limits>

int main() 
{
    double sum = 0;
    double number;
    int count = 0;

    std::cout << "Введите десять чисел:\n";

    for (int i = 0; i < 10; i++) 
    {
        std::cout << "Число " << (i + 1) << ": ";
        
        if(std::cin >> number)
        {
            sum += number;
            count++;
        }
        else
        {
            std::cout << "Ошибка ввода! Пожалуйста, введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
        }
    }

    double average = static_cast<double>(sum) / count;

    std::cout << "Среднее арифметическое: " << average << std::endl;

    return 0;
}