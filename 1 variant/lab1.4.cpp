/*
Задание 4. Написать программу решения квадратного уравнения a𝑥^2 + 𝑏𝑥 +𝑐 = 0. 
В случае, когда коэффициент при первой степени неизвестного равен 
нулю, решать уравнение 𝑏𝑥 + 𝑐 = 0 и выводить результат. Считать, что 
коэффициенты b и c в любом случае не равны 0.
*/

#include <iostream>
#include <cmath>

int main()
{
    double a, b, c;

    std::cout << "Введите коэффициенты a, b и c: ";
    std::cin >> a >> b >> c;

    if (a != 0) 
    {
        // Квадратное уравнение
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) 
        {
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);

            std::cout << "Уравнение имеет два действительных корня:" << std::endl;
            std::cout << "x1 = " << x1 << std::endl;
            std::cout << "x2 = " << x2 << std::endl;
        } 
        else if (discriminant == 0) 
        {
            double x = -b / (2 * a);

            std::cout << "Уравнение имеет один действительный корень:" << std::endl;
            std::cout << "x = " << x << std::endl;
        } 
        else 
        {
             // Дискриминант меньше нуля, вывод комплексных корней
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);

            std::cout << "Уравнение имеет два комплексных корня:" << std::endl;
            std::cout << "x1 = " << realPart << " + " << imaginaryPart << "i" << std::endl;
            std::cout << "x2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
        }
    } 
    else if (b != 0)
    {
        // Линейное уравнение bx + c = 0
        double x = -c / b;

        std::cout << "Уравнение является линейным." << std::endl;
        std::cout << "x = " << x << std::endl;
    }
     else if (c != 0)
    {
        std::cout << "Уравнение не имеет решений." << std::endl;
    }
    else
    {
        std::cout << "Уравнение имеет бесконечное множество решений." << std::endl;
    }

    return 0;
}

