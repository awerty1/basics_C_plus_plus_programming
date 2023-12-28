/*
Задание 3. Вывести на экран все простые числа, начиная с единицы, 
меньшие n. Число n вводится с клавиатуры. Простые числа не имеют других 
делителей, кроме единицы и самого себя. Сделать проверку на корректность 
ввода n.
*/

#include <iostream>
#include <cmath>

bool isPrime(int number) 
{
    if (number <= 1) 
	{
        return false;
    }

    int sqrtNumber = sqrt(number);
    for (int i = 2; i <= sqrtNumber; i++) 
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

    std::cout << "Введите число n: ";
    std::cin >> n;

    if (std::cin.fail() || n <= 1) 
	{
        std::cout << "Некорректный ввод! Пожалуйста, введите число больше 1." << std::endl;
        return 0;
    }

    std::cout << "Простые числа, меньшие " << n << ":" << std::endl;
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