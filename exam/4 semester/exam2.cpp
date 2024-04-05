/*
Даны координаты вершин двух треугольников. Определить, какой из них имеет большую площадь c++ решить с помощью функции
*/

#include <iostream>
#include <cmath> // Для доступа к функциям sin, cos, sqrt

// Функция для вычисления площади треугольника по координатам вершин
double triangleArea(double x1, double y1, double x2, double y2, double x3, double y3) 
{
    // Векторное произведение для вычисления площади
    return std::abs((x1  *  (y2 - y3) + x2  *  (y3 - y1) + x3  *  (y1 - y2)) / 2.0);
}

int main() 
{
	// Координаты вершин первого треугольника
	double x1 = 0, y1 = 0;
	double x2 = 1, y2 = 0;
	double x3 = 0, y3 = 1;

	// Координаты вершин второго треугольника
	double x4 = 0, y4 = 0;
	double x5 = 1, y5 = 1;
	double x6 = 1, y6 = 0;

	// Вычисляем площади обоих треугольников
	double area1 = triangleArea(x1, y1, x2, y2, x3, y3);
	double area2 = triangleArea(x4, y4, x5, y5, x6, y6);

	// Сравниваем площади и выводим результат
	if (area1 > area2)
	{
        std::cout << "Площадь первого треугольника больше." << std::endl;
	} 
	else if (area1 < area2)
	{
        std::cout << "Площадь второго треугольника больше." << std::endl;
	} 
	else 
	{
        std::cout << "Площади треугольников равны." << std::endl;
	}
	
	return 0;
}