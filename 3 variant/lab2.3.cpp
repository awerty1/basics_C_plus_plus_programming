/*
Задание 3. Вывести на экран n первых простых чисел, начиная с единицы. n
вводится с клавиатуры. Простые числа не имеют других делителей, кроме 
единицы и самого себя. Сделать проверку на корректность ввода количества 
чисел.
*/

#include <iostream>

bool IsPrime(int number) 
{
    if (number <= 1) 
    {
        return false;
    }

    for (int i = 2; i*i <= number; ++i) 
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
    std::cin >> n;

    if (n <= 0) 
    {
        std::cout << "Некорректное количество чисел.\n";
        return 0;
    }

    std::cout << "Первые " << n << " простых чисел:\n";

    int count = 0;
    int number = 1;

    while (count < n) 
    {
        if (IsPrime(number)) 
        {
            std::cout << number << std::endl;
            ++count;
        }
        ++number;
    }

    return 0;
}