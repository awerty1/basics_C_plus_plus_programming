/*
Задание 3. Вывести на экран все простые числа, начиная с единицы, 
меньшие n. Число n вводится с клавиатуры. Простые числа не имеют других 
делителей, кроме единицы и самого себя. Сделать проверку на корректность 
ввода n.
*/

#include <iostream>
#include <limits>

bool isPrime(int number)
{
    if (number < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= number; i++)
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

    do
    {
        std::cout << "Введите число n: ";
        std::cin >> n;

        if (std::cin.fail() || n < 2)
        {
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число больше 1." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while (std::cin.fail() || n < 2);

    std::cout << "Простые числа меньше " << n << ": " << std::endl;
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