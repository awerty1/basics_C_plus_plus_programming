/*
Задание 1. Написать программу вычисления объема цилиндра. Исходные 
данные вводятся с клавиатуры.
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
    double radius, height;

    std::cout << "Введите радиус цилиндра: ";
    std::cin >> radius;
    
    if (radius <= 0)
    {
        std::cout << "Некорректное значение радиуса." << std::endl;
        return 0;
    }

    std::cout << "Введите высоту цилиндра: ";
    std::cin >> height;
    
    if (height <= 0)
    {
        std::cout << "Некорректное значение высоты." << std::endl;
        return 0;
    }

    double volume = M_PI * std::pow(radius, 2) * height;
    
    // Установка точности вывода до двух знаков после запятой
    std::cout << "Объем цилиндра: " << std::fixed << std::setprecision(2) << volume << std::endl;

    return 0;
}