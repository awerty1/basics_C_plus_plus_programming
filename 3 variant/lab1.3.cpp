/*
Задание 3. Вводятся два произвольных числа a и b. В зависимости от их 
значений вывести на экран «a > b», «a < b» или «a = b».
*/

#include <iostream>
#include <limits>

int requestValue(const std::string& prompt) 
{
    int value;
    while (true) 
    {
        std::cout << prompt;
        if (std::cin >> value) 
        {
            break;
        } 
        else 
        {
            std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return value;
}

int main() 
{
    int a = requestValue("Введите значение a: ");
    int b = requestValue("Введите значение b: ");

    if (a > b) 
    {
        std::cout << "a > b" << std::endl;
    } 
    else if (a < b) 
    {
        std::cout << "a < b" << std::endl;
    } 
    else 
    {
        std::cout << "a = b" << std::endl;
    }

    return 0;
}