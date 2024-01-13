/*
Задание 1. С клавиатуры вводятся действительные числа x и y. Вывести на 
экран результат вычисления: |𝑥| − |𝑦| ∗ (1 + |𝑥𝑦|).
*/

#include <iostream>
#include <cmath>

double readNumber(const std::string& prompt) 
{
    double number;
    bool validInput = false;

    do 
    {
        std::cout << prompt;
        if (!(std::cin >> number)) 
        {
            std::cout << "Неверный ввод. Пожалуйста, введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else 
        {
            validInput = true;
        }
    } 
    while (!validInput);

    return number;
}

int main() 
{
    double x = readNumber("Введите число x: ");
    double y = readNumber("Введите число y: ");

    double result = std::abs(x) - std::abs(y) * (1 + std::abs(x * y));

    std::cout << "Результат: " << result << std::endl;

    return 0;
}