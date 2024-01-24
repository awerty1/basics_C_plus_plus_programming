/*
Задание 2. Вывести на экран все простые числа, начиная с единицы, 
меньшие n. Число n вводится с клавиатуры. Простые числа не имеют других 
делителей, кроме единицы и самого себя. Сделать проверку на корректность 
ввода n
*/

#include <iostream>
#include <cmath>
#include <limits>
#include <algorithm>

bool isNumber(const std::string& str) 
{
    return std::ranges::all_of(str, [](char ch) { return std::isdigit(ch); });
}

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }

    int sqrtNum = static_cast<int>(std::sqrt(num));
    for (int i = 2; i <= sqrtNum; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int n;
    std::string input;

    do
    {
        std::cout << "Введите число n: ";
        std::cin >> input;

        if (!isNumber(input))
        {
            std::cout << "Ошибка ввода! Пожалуйста, введите целое число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        n = std::stoi(input);

        // Проверка на отрицательное число
        if (n <= 0)
        {
            std::cout << "Ошибка ввода! Пожалуйста, введите положительное целое число." << std::endl;
            continue;
        }

        break;
    }
    while (true);

    std::cout << "Простые числа, меньшие " << n << ": ";

    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            std::cout << i << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}
