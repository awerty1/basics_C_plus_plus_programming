/*
Задание 1. Даны катеты прямоугольного треугольника. Найти его 
гипотенузу. Исходные данные вводятся с клавиатуры.
*/

#include <iostream>
#include <cmath>

double getInput(const std::string& prompt) 
{
    double value;
    std::cout << prompt;

    while (!(std::cin >> value)) 
    {
        std::cout << "Ошибка ввода! Введите числовое значение: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return value;
}

int main() 
{
    double cathetus1 = getInput("Введите значение первого катета: ");
    double cathetus2 = getInput("Введите значение второго катета: ");

    double hypotenuse = sqrt(pow(cathetus1, 2) + pow(cathetus2, 2));

    std::cout << "Гипотенуза треугольника: " << hypotenuse << std::endl;

    return 0;
}
