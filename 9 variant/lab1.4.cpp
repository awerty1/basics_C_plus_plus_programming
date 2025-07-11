/*
Задание 4. Дано действительное число А. Вычислить F(А), если
F(x) = при x<=0 - 0 ; при 0<x<=1 - x^2-x; при других x - x^2-sin(PI*x^2)
*/

#include <iostream>
#include <cmath>

double calculateF(double x) 
{
    if (x <= 0) 
    {
        return 0;
    } 
    else if (x <= 1) 
    {
        return x * x - x;
    } 
    else 
    {
        return x * x - sin(M_PI * x * x);
    }
}

int main() 
{
    double A;

    std::cout << "Введите значение A: ";
    std::cin >> A;

    double result = calculateF(A);

    std::cout << "F(A) = " << result << std::endl;

    return 0;
}