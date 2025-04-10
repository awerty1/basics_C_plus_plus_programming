/*
Задание 4. Составить программу, определяющую, проходит ли кирпич с 
размерами a*b*c через круглое отверстие диаметром d (a, b, c, d задаются 
оператором ввода). Сделать проверку на корректность ввода.
*/

#include <iostream>
#include <cmath>

int main()
{
    double a, b, c, d;
    std::cout << "Введите размеры кирпича (a, b, c): ";
    std::cin >> a >> b >> c;
    std::cout << "Введите диаметр отверстия (d): ";
    std::cin >> d;
    
    if (std::cin.fail() || a <= 0 || b <= 0 || c <= 0 || d <= 0)
    {
        std::cout << "Ошибка ввода!\n";
        return 0;
    }
    
    double diagonal = sqrt(a * a + b * b + c * c); // находим диагональную длину кирпича
    
    if (diagonal <= d)
    {
        std::cout << "Кирпич проходит через отверстие.\n";
    }
    else
    {
        std::cout << "Кирпич не проходит через отверстие.\n";
    }
    
    return 0;
}
