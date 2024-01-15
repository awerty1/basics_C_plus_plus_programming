/*
Задание 1. Написать программу вычисления площади поверхности шара. 
Исходные данные вводятся с клавиатуры.
*/

#include <iostream>
#include <cmath>

int main() 
{
    float radius;
    const float pi = 3.14159;
    float surfaceArea;

    std::cout << "Введите радиус шара: ";
    std::cin >> radius;

    // Вычисление площади поверхности шара
    surfaceArea = 4 * pi * pow(radius, 2);

    std::cout << "Площадь поверхности шара: " << surfaceArea << std::endl;

    return 0;
}