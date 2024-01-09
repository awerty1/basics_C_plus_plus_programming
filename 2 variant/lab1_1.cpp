/*
Задание 1. Вычислить расстояние между двумя точками с координатами (х1, 
у1) и (х2, у2). Координаты точек вводятся с клавиатуры.
*/


#include <iostream>
#include <cmath>

float calculateDistance(float x1, float y1, float x2, float y2) 
{
    float deltaX = x2 - x1;
    float deltaY = y2 - y1;
    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

int main() 
{
    setlocale(LC_ALL, "Russian");

    float x1, y1, x2, y2;

    std::cout << "Введите координаты первой точки:\n";
    std::cin >> x1 >> y1;

    std::cout << "Введите координаты второй точки:\n";
    std::cin >> x2 >> y2;

    if (x1 == x2 && y1 == y2) 
    {
        std::cout << "Координаты точек совпадают.\n";
    } 
    else 
    {
        float distance = calculateDistance(x1, y1, x2, y2);
        std::cout << "Расстояние между двумя точками: " << distance << std::endl;
    }

    return 0;
}
