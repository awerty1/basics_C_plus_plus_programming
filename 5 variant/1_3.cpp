/*
Задание 3. Вводятся два произвольных числа a и b. Вывести на экран, 
одинаковые у них знаки или разные. Отдельно рассмотреть случай ввода 
нулевых значений.
*/

#include <iostream>

int main() 
{
    int a, b;
    
    // Ввод чисел a и b
    std::cout << "Введите число a: ";
    std::cin >> a;
    
    std::cout << "Введите число b: ";
    std::cin >> b;
    
    // Проверка знаков чисел
    if (a == 0 && b == 0) 
    {
        std::cout << "Оба числа равны нулю." << std::endl;
    } 
    else if ((a > 0 && b > 0) || (a < 0 && b < 0)) 
    {
        std::cout << "Числа имеют одинаковые знаки." << std::endl;
    } 
    else 
    {
        std::cout << "Числа имеют разные знаки." << std::endl;
    }
    
    return 0;
}
