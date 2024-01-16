/*
Задание 1. Написать программу вычисления объема куба. Сторона куба 
вводится с клавиатуры. 
*/

#include <iostream>
#include <limits>

int main() 
{
    double side;
    double volume;
    bool is_correct;

    do
    {
        std::cout << "Введите длину стороны куба: ";
        std::cin >> side; 
        
        if (std::cin.fail()) 
        {
            std::cout << "Ошибка: введено некорректное значение.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            is_correct = false;
        }
        else
        {
            is_correct = true;
        }
    }
    while (!is_correct);
    
    volume = side * side * side;

    std::cout << "Объем куба равен: " << volume << std::endl;

    return 0;
}