/*
Задание 2. Написать программу, которая преобразует введенное с 
клавиатуры действительное число в денежный формат. Например, число 12.5 
должно быть преобразовано к виду 12 руб. 50 коп., а 0.57 к виду 0 руб. 57 коп.
*/

#include <iostream>
#include <iomanip>
#include <locale>

int main()
{
    double amount;

    std::cout << "Введите сумму: ";
    std::cin >> amount;

    if (amount < 0)
    {
        std::cout << "Некорректное значение суммы." << std::endl;
        return 0;
    }

    int rubles = static_cast<int>(amount);
    int cents = static_cast<int>((amount - rubles) * 100 + 0.5);

    std::cout.imbue(std::locale("")); // Использование текущей локали для форматирования
    std::cout << std::fixed << std::setprecision(2);
    
    if (cents == 0)
    {
        std::cout << rubles << " руб." << std::endl;
    }
    else
    {
        std::cout << rubles << " руб. " << cents << " коп." << std::endl;
    }

    return 0;
}