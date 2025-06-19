/*
Задание 4. Даны действительные положительные числа x, y z. Выяснить 
существует ли треугольник с длинами сторон x, y z. Если треугольник 
существует, то ответить – является ли он тупоугольным.
*/

#include <iostream>

bool isTriangleExist(double x, double y, double z)
{
    return (x + y > z) && (y + z > x) && (z + x > y);
}

bool isTriangleObtuse(double x, double y, double z)
{
    double xSquare = x * x;
    double ySquare = y * y;
    double zSquare = z * z;
    
    return (xSquare + ySquare < zSquare) || (ySquare + zSquare < xSquare) || (zSquare + xSquare < ySquare);
}

void inputTriangleSides(double& x, double& y, double& z)
{
    do 
    {
        std::cout << "Введите длину первой стороны: ";
        std::cin >> x;
        std::cout << "Введите длину второй стороны: ";
        std::cin >> y;
        std::cout << "Введите длину третьей стороны: ";
        std::cin >> z;
        
        if (!isTriangleExist(x, y, z)) 
        {
            std::cout << "Треугольник не существует. Повторите ввод." << std::endl;
        }
    } 
    while (!isTriangleExist(x, y, z));
}

int main()
{
    double x, y, z;
    
    // Ввод длин сторон треугольника
    inputTriangleSides(x, y, z);
    
    // Проверка на тупоугольность
    if (isTriangleObtuse(x, y, z))
    {
        std::cout << "Треугольник является тупоугольным." << std::endl;
    } 
    else 
    {
        std::cout << "Треугольник не является тупоугольным." << std::endl;
    }
    
    return 0;
}
