/*
Задание 4. Даны действительные положительные числа x, y z. Выяснить 
существует ли треугольник с длинами сторон x, y z. Если треугольник 
существует, то ответить – является ли он прямоугольным
*/

#include <iostream>
#include <cmath>
#include <limits>
#include <cassert>

bool isTriangle(double x, double y, double z) 
{
    return (x + y > z) && (y + z > x) && (x + z > y);
}

bool isRightTriangle(double x, double y, double z) 
{
    double a = std::max({x, y, z});
    double b, c;

    if (a == x) 
    {
        b = y;
        c = z;
    } 
    else if (a == y) 
    {
        b = x;
        c = z;
    } 
    else 
    {
        b = x;
        c = y;
    }

    return std::pow(a, 2) == std::pow(b, 2) + std::pow(c, 2);
}

double getValidInput(const std::string& prompt) 
{
    double value;
    std::cout << prompt;
    std::cin >> value;

    while (std::cin.fail() || value <= 0) 
    {
        std::cout << "Некорректный ввод. Пожалуйста, введите положительное число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> value;
    }

    return value;
}

void runTests() 
{
    // Тест 1: Треугольник 3-4-5
    assert(isTriangle(3, 4, 5));
    assert(isRightTriangle(3, 4, 5));
    std::cout << "Тест 1 пройден." << std::endl;

    // Тест 2: Несуществующий треугольник 4-5-9
    assert(!isTriangle(4, 5, 9));
    std::cout << "Тест 2 пройден." << std::endl;

    // Тест 3: Треугольник 5-5-5
    assert(isTriangle(5, 5, 5));
    assert(!isRightTriangle(5, 5, 5));
    std::cout << "Тест 3 пройден." << std::endl;
}


int main() 
{
    runTests();
    
    double x = getValidInput("Введите длину стороны треугольника x: ");
    double y = getValidInput("Введите длину стороны треугольника y: ");
    double z = getValidInput("Введите длину стороны треугольника z: ");

    if (isTriangle(x, y, z)) 
    {
        std::cout << "Треугольник существует." << std::endl;
        if (isRightTriangle(x, y, z)) 
        {
            std::cout << "Треугольник является прямоугольным." << std::endl;
        } 
        else 
        {
            std::cout << "Треугольник не является прямоугольным." << std::endl;
        }
    } 
    else 
    {
        std::cout << "Треугольник не существует." << std::endl;
    }

    return 0;
}