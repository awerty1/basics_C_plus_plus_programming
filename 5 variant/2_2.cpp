/*
Задание 2. Вывести на экран n первых простых чисел, начиная с единицы. n
вводится с клавиатуры. Простые числа не имеют других делителей, кроме 
единицы и самого себя. Сделать проверку на корректность ввода количества 
чисел.
*/

#include <iostream>
#include <cmath>

bool isPrime(int number) 
{
    if (number < 2) 
    {
        return false;
    }

    for (int i = 2; i <= std::sqrt(number); i++) 
    {
        if (number % i == 0) 
        {
            return false;
        }
    }

    return true;
}

int main() 
{
    int n;

    std::cout << "Введите количество простых чисел для вывода: ";
    if (std::cin >> n && n > 0) 
    {
        int count = 0;
        int number = 1;

        std::cout << "Первые " << n << " простых чисел:" << std::endl;

        while (count < n) 
        {
            if (isPrime(number)) 
            {
                std::cout << number << " ";
                count++;
            }
            number++;
        }
    } 
    else 
    {
        std::cout << "Ошибка ввода! Пожалуйста, введите положительное целое число." << std::endl;
    }

    return 0;
}