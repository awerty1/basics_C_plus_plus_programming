/*
Задание 4. С клавиатуры вводятся x, y, x1, y1. Определить, принадлежит ли 
точка с координатами (x,y) заштрихованной части плоскости: квадрат
*/

#include <iostream>
#include <limits>

bool isValidInput(int& value, const std::string& message) 
{
    while (!(std::cin >> value)) 
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Ошибка ввода! " << message;
    }
    
    return true;
}

bool isPointInShadedArea(int x, int y, int x1, int y1) 
{
    bool isInsideSquare = x >= 0 && x <= x1 && y >= 0 && y <= y1;
    bool isInsideTriangle = x >= 0 && y >= x1 && y <= y1;

    return isInsideSquare || isInsideTriangle;
}

int main() 
{
    int x, y, x1, y1;

    std::cout << "Введите координаты точки (x): ";
    isValidInput(x, "Введите корректное значение для x: ");
    
    std::cout << "Введите координаты точки (y): ";
    isValidInput(y, "Введите корректное значение для y: ");

    std::cout << "Введите размеры сторон квадрата (x1): ";
    isValidInput(x1, "Введите корректное значение для x1: ");
    
    std::cout << "Введите размеры сторон квадрата (y1): ";
    isValidInput(y1, "Введите корректное значение для y1: ");

    if (isPointInShadedArea(x, y, x1, y1)) 
    {
        std::cout << "Точка принадлежит заштрихованной части плоскости. 🎯" << std::endl;
    } 
    else 
    {
        std::cout << "Точка не принадлежит заштрихованной части плоскости. ❌" << std::endl;
    }

    return 0;
}