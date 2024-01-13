/*
Задание 2. С клавиатуры вводится четырехзначное число. Найти разность 
его цифр.
*/

#include <iostream>
#include <cmath>

int main() 
{
    int number;
    bool validInput = false;
    
    do
    {
        std::cout << "Введите четырехзначное число: ";
        if (!(std::cin >> number)) 
        {
            std::cout << "Неверный ввод. Пожалуйста, введите число." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else 
        {
            validInput = true;
        }
    }
    while(!validInput);
    
    
    // Разбиваем число на отдельные цифры
    int thousands = number / 1000;
    int hundreds = (number % 1000) / 100;
    int tens = (number % 100) / 10;
    int ones = number % 10;
    
    // Вычисляем разницу цифр
    int difference = std::abs(thousands - hundreds) - std::abs(tens - ones);
    
    std::cout << "Разность цифр: " << difference << std::endl;
    
    return 0;
}