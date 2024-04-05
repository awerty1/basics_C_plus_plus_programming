/*
Даны значения а и б, посчитать их произведение. Сделать отдельной функцией.
*/

#include <iostream>
#include <stdexcept>
#include <string>

double multiply(double a, double b)
{
    return a * b;
}

bool readValue(double &value, const std::string &message)
{
    std::cout << message;
    if (!(std::cin >> value))
    {
        std::cerr << "Ошибка: Введено неверное значение." << std::endl;
        return false;
    }
    return true;
}

int main()
{
    double a, b;
    
    if (!readValue(a, "Введите a: "))
    {
        return 1;
    }

    if (!readValue(b, "Введите b: "))
    {
        return 1;
    }

    std::cout << "a * b = " << multiply(a, b) << std::endl;

	return 0;
}