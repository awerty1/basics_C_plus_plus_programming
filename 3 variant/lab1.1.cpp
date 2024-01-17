/*
 * Задание 1. Написать программу вычисления объема параллелепипеда. 
 * Исходные данные вводятся с клавиатуры.
*/

#include <iostream>

double calculate_volume(double length, double width, double height)
{
    if (length <= 0 || width <= 0 || height <= 0) 
    {
        throw std::runtime_error("Все параметры параллелепипеда должны быть положительными числами.");
    }
    return length * width * height;
}

int main() 
{
    double length, width, height;
    bool isValidInput = false;
    
    do 
    {
        std::cout << "Введите длину параллелепипеда: ";
        std::cin >> length;
        
        std::cout << "Введите ширину параллелепипеда: ";
        std::cin >> width;
        
        std::cout << "Введите высоту параллелепипеда: ";
        std::cin >> height;
        
        try 
        {
            double volume = calculate_volume(length, width, height);
            std::cout << "Объем параллелепипеда: " << volume << std::endl;
            isValidInput = true;
        } 
        catch (const std::exception& ex) 
        {
            std::cout << "Ошибка: " << ex.what() << std::endl;
        }
    } 
    while(!isValidInput);
    
    return 0;
}
