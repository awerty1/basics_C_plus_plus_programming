/*
Задание 3. Вводятся два произвольных числа a и b. Вывести на экран, 
делится ли большее из них на меньшее без остатка или нет.
*/

#include <iostream>
#include <limits>

// Функция для ввода числа с обработкой неправильного ввода
int inputNumber(const std::string& prompt) 
{
    int number;
    bool validInput = false;

    do 
    {
        std::cout << prompt;
        if (std::cin >> number) 
        {
            validInput = true;
        } 
        else 
        {
            std::cout << "Неправильный ввод, попробуйте еще раз." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } 
    while (!validInput);

    return number;
}

int main() 
{
    int a = inputNumber("Введите первое число: ");
    int b = inputNumber("Введите второе число: ");

    if (a > b) 
    {
        if (a % b == 0) 
        {
            std::cout << a << " делится на " << b << " без остатка." << std::endl;
        } 
        else 
        {
            std::cout << a << " не делится на " << b << " без остатка." << std::endl;
        }
    } 
    else if (b > a) 
    {
        if (b % a == 0) 
        {
            std::cout << b << " делится на " << a << " без остатка." << std::endl;
        } 
        else 
        {
            std::cout << b << " не делится на " << a << " без остатка." << std::endl;
        }
    } 
    else 
    {
        std::cout << "Числа равны." << std::endl;
    }

    return 0;
}
