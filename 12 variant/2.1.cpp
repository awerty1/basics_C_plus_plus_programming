/*
Задание 1. Составить программу, печатающую все делители целого числа в 
порядке убывания. Предусмотреть задание исходных данных оператором ввода
*/

#include <iostream>
#include <vector>
#include <limits>

std::vector<int> findDivisors(int number)
{
    std::vector<int> divisors;

    for (int i = number; i >= 1; --i)
    {
        if (number % i == 0)
        {
            divisors.push_back(i);
        }
    }

    return divisors;
}

int main()
{
    int number;
    bool isValidInput = false;

    do
    {
        std::cout << "Enter an integer number: ";

        if (!(std::cin >> number))
        {
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            isValidInput = true;
        }
    }
    while (!isValidInput);

    std::vector<int> divisors = findDivisors(number);

    std::cout << "Divisors of " << number << " in descending order: ";
    for (int divisor : divisors)
    {
        std::cout << divisor << " ";
    }
    std::cout << std::endl;

    return 0;
}