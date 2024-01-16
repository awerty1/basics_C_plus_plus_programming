/*
Задание 1. Даны гипотенуза и катет прямоугольного треугольника. Найти 
второй катет. Исходные данные вводятся с клавиатуры.
*/

#include <iostream>
#include <cmath>

int main() 
{
    double hypotenuse, leg, secondLeg;

    do 
    {
        std::cout << "Введите значение гипотенузы: ";
        std::cin >> hypotenuse;

        std::cout << "Введите значение катета: ";
        std::cin >> leg;

        if (hypotenuse <= 0 || leg <= 0) 
        {
            std::cout << "Значения должны быть положительными. Пожалуйста, повторите ввод.\n";
        }
    } 
    while (hypotenuse <= 0 || leg <= 0);

    // Используем теорему Пифагора для нахождения второго катета
    secondLeg = std::sqrt(std::pow(hypotenuse, 2) - std::pow(leg, 2));
    
    if (std::isnan(secondLeg)) 
    {
        std::cout << "Невозможно вычислить второй катет.\n";
    } 
    else 
    {
        std::cout << "Второй катет равен: " << secondLeg << std::endl;
    }

    return 0;
}