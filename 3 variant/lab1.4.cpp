/*
Задание 4. Даны действительные положительные числа x, y z. Выяснить 
существует ли треугольник с длинами сторон x, y z. Если треугольник 
существует, то ответить – является ли он остроугольным.
*/

#include <iostream>
#include <cmath>

bool isTriangle(double x, double y, double z) 
{
    return (x + y > z) && (y + z > x) && (z + x > y);
}

bool isAcuteTriangle(double x, double y, double z) 
{
    double a = std::max(std::max(x, y), z);
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
    
    return std::pow(a, 2) < std::pow(b, 2) + std::pow(c, 2);
}

int main() 
{
    double x, y, z;
    
    do 
    {
        std::cout << "Введите длину стороны x: ";
        std::cin >> x;
    } 
    while (x <= 0);
    
    do 
    {
        std::cout << "Введите длину стороны y: ";
        std::cin >> y;
    } 
    while (y <= 0);
    
    do 
    {
        std::cout << "Введите длину стороны z: ";
        std::cin >> z;
    }
    while (z <= 0);
    
    if (isTriangle(x, y, z)) 
    {
        std::cout << "Треугольник существует.";
        
        if (isAcuteTriangle(x, y, z)) 
        {
            std::cout << " Треугольник является остроугольным." << std::endl;
        } 
        else 
        {
            std::cout << " Треугольник не является остроугольным." << std::endl;
        }
    } 
    else 
    {
        std::cout << "Треугольник не существует." << std::endl;
    }
    
    return 0;
}