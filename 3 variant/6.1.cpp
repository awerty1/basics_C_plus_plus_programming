/*
Задание 1. С клавиатуры вводятся координаты вершин двух треугольников. 
Определить, какой из них имеет большую площадь.
*/

#include <iostream>
#include <cmath>

// Функция для вычисления площади треугольника по координатам его вершин
double calculateTriangleArea(double x1, double y1, double x2, double y2, double x3, double y3) 
{
    return 0.5 * std::abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

int main() 
{
    double x1, y1, x2, y2, x3, y3;
    double area1, area2;

    // Ввод координат вершин первого треугольника
    std::cout << "Введите координаты вершин первого треугольника:\n";
    std::cout << "Вершина 1 (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Вершина 2 (x2 y2): ";
    std::cin >> x2 >> y2;
    std::cout << "Вершина 3 (x3 y3): ";
    std::cin >> x3 >> y3;

    // Вычисление площади первого треугольника
    area1 = calculateTriangleArea(x1, y1, x2, y2, x3, y3);

    // Ввод координат вершин второго треугольника
    std::cout << "Введите координаты вершин второго треугольника:\n";
    std::cout << "Вершина 1 (x1 y1): ";
    std::cin >> x1 >> y1;
    std::cout << "Вершина 2 (x2 y2): ";
    std::cin >> x2 >> y2;
    std::cout << "Вершина 3 (x3 y3): ";
    std::cin >> x3 >> y3;

    // Вычисление площади второго треугольника
    area2 = calculateTriangleArea(x1, y1, x2, y2, x3, y3);

    // Сравнение площадей и вывод результата
    if (area1 > area2) 
    {
        std::cout << "Первый треугольник имеет большую площадь.\n";
    } 
    else if (area1 < area2) 
    {
        std::cout << "Второй треугольник имеет большую площадь.\n";
    } 
    else 
    {
        std::cout << "Площади треугольников равны.\n";
    }

    return 0;
}