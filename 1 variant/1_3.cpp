/*
Задание 3. Вводится произвольное число х. Вывести на экран, четное оно 
или нечетное. Нуль не является ни четным, ни нечетным.
*/

#include <iostream>
#include <limits>

std::string getParity(int num) 
{
    if (num == 0) 
    {
        return "Ноль";
    } 
    else if (num % 2 == 0) 
    {
        return "Четное число";
    } 
    else 
    {
        return "Нечетное число";
    }
}

int main() 
{
    int x;

    std::cout << "Введите число: ";
    std::cin >> x;
    
    bool validInput = false;
    while (!validInput) 
    {
        std::cout << "Введите число: ";
        if (!(std::cin >> x)) 
        {
            std::cout << "Ошибка при вводе числа." << std::endl;
            std::cin.clear(); // Сброс состояния потока ввода
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
        } 
        else 
        {
            validInput = true;
        }
    }
    
    // Вывод результата
    std::cout << getParity(x) << std::endl;

    return 0;
}