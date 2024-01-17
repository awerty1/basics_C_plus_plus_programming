/*
Задание 2. Вывести на экран все трехзначные натуральные числа, в записи 
которых нет двух одинаковых цифр
*/

#include <iostream>

bool HasDuplicateDigits(int number) 
{
    int hundreds = number / 100;
    int tens = (number / 10) % 10;
    int units = number % 10;

    return (hundreds == tens) || (hundreds == units) || (tens == units);
}

int main() 
{
    std::cout << "Трехзначные натуральные числа без повторяющихся цифр:\n";

    for (int i = 100; i < 1000; ++i) 
    {
        if (!HasDuplicateDigits(i)) 
        {
            std::cout << i << std::endl;
        }
    }

    return 0;
}