/*
Задание 1. С клавиатуры вводятся длина основания и высота треугольника. 
Вычислить площадь треугольника.
*/

#include <iostream>

int main() 
{
    double base, height;
    
    // Ввод длины основания
    std::cout << "Введите длину основания треугольника: ";
    std::cin >> base;
    
    // Ввод высоты треугольника
    std::cout << "Введите высоту треугольника: ";
    std::cin >> height;
    
    // Вычисление площади треугольника
    double area = 0.5 * base * height;
    
    // Вывод результата
    std::cout << "Площадь треугольника: " << area << std::endl;
    
    return 0;
}