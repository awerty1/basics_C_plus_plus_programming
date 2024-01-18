/*
Задание 1. Написать программу пересчета веса из фунтов в килограммы (1 
российский фунт равен 409,5 г). Исходные данные вводятся с клавиатуры.
*/

#include<iostream>

int main() 
{
    float pounds, kilograms;
    std::cout << "Enter weight in pounds: ";
    std::cin >> pounds;

    kilograms = pounds * 409.5 / 1000;

    std::cout << "Weight in kilograms: " << kilograms << std::endl;

    return 0;
}