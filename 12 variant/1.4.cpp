/*
Задание 4. Дано действительное число A. Для функции F(X), график 
которой представлен на рисунке, вычислить F(A) и вывести на экран.
*/

#include <iostream>
#include <cmath>

int main() 
{
    double A;
    std::cout << "Введите значение числа A: ";
    std::cin >> A;
    
    double result;
    
    if (A < 0) 
    {
        result = -A;
    } 
    else if (A >= 0 && A <= 4) 
    {
        result = std::sqrt(A);
    } 
    else 
    {
        result = 2;
    }
    
    std::cout << "Значение функции F(A) = " << result << std::endl;
    
    return 0;
}
