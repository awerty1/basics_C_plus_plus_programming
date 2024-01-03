/*
Задание 1. С клавиатуры вводятся десять целых чисел. Определить, сколько 
среди них положительных, отрицательных и равных нулю. 
*/

#include <iostream>

int main() 
{
    int num;
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;

    std::cout << "Введите 10 целых чисел:\n";

    for (int i = 0; i < 10; ++i) 
    {
        std::cout << "Число " << i+1 << ":"; 
        std::cin >> num;

        if (num > 0) 
        {
            positiveCount++;
        } 
        else if (num < 0) 
        {
            negativeCount++;
        } 
        else 
        {
            zeroCount++;
        }
    }

    std::cout << "Количество положительных чисел: " << positiveCount << "\n";
    std::cout << "Количество отрицательных чисел: " << negativeCount << "\n";
    std::cout << "Количество нулевых чисел: " << zeroCount << "\n";

    return 0;
}