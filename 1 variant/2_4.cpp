/*
Задание 4. Написать программу для вычисления суммы бесконечного сходящегося ряда. 
Суммирование прекратить при появлении в сумме слагаемых, имеющих абсолютную величину, меньшую заданной 
погрешности вычисления функции d. Другими словами, производить суммирование до тех пор, 
пока текущий член ряда больше погрешности. Значение d задается при помощи оператора ввода, при вводе 
проверить, что d < 1. S = 1 -(1/(3^2))+(1/(5^2)-(1/(7^2))+ ...
*/

#include <iostream>

double calculateSum(double d) 
{
    if (d >= 1) 
    {
        std::cout << "Ошибка: значение погрешности должно быть меньше 1." << std::endl;
        return 0.0;
    }

    double sum = 0.0;
    double sign = 1.0;
    int denominator = 1;

    while (true) 
    {
        double term = sign / (denominator * denominator);
        if (std::abs(term) < d)
            break;

        sum += term;
        sign *= -1;
        denominator += 2;
    }

    return sum;
}

int main() 
{
    double d;
    std::cout << "Введите значение погрешности (d): ";
    std::cin >> d;

    double result = calculateSum(d);

    std::cout << "Сумма ряда с погрешностью " << d << " равна: " << result << std::endl;

    return 0;
}