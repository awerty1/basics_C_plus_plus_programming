/*
Задание 1. Определить силу притяжения F между телами массы m1 и m2, 
находящимися на расстоянии r друг от друга. Исходные данные вводятся с 
клавиатуры.
*/

#include <iostream>
#include <cmath>

int main()
{
    try
    {
        double m1, m2, r;
        const double G = 6.67430e-11; // Гравитационная постоянная

        std::cout << "Введите массу первого тела (m1): ";
        std::cin >> m1;

        if (std::cin.fail())
        {
            throw std::runtime_error("Ошибка ввода для массы первого тела (m1).");
        }

        std::cout << "Введите массу второго тела (m2): ";
        std::cin >> m2;

        if (std::cin.fail())
        {
            throw std::runtime_error("Ошибка ввода для массы второго тела (m2).");
        }

        std::cout << "Введите расстояние между телами (r): ";
        std::cin >> r;

        if (std::cin.fail())
        {
            throw std::runtime_error("Ошибка ввода для расстояния между телами (r).");
        }

        if (r == 0)
        {
            throw std::runtime_error("Расстояние между телами должно быть больше нуля.");
        }

        // Вычисление силы притяжения по формуле F = G * (m1 * m2) / r^2
        double F = G * (m1 * m2) / std::pow(r, 2);

        std::cout << "Сила притяжения между телами: " << F << " Н" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Произошла ошибка: " << e.what() << std::endl;
    }

    return 0;
}