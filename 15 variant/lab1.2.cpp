/*
Задание 2. Написать программу пересчета величины временного интервала, 
заданного в минутах, в величину, выраженную в часах и минутах. Количество 
минут вводится с клавиатуры.
*/

#include <iostream>
#include <limits>

bool convertMinutes(int minutes, int& hours, int& remainingMinutes) 
{
    if (minutes < 0) 
    {
        // Обработка некорректного ввода: отрицательное значение
        return false;
    }

    hours = minutes / 60;           // Переводим минуты в часы
    remainingMinutes = minutes % 60; // Вычисляем оставшиеся минуты
    return true;
}

int main() 
{
    int minutes;
    bool validInput = false;
    while (!validInput) 
    {
        std::cout << "Введите количество минут: ";
        if(std::cin >> minutes)
        {
            int hours, remainingMinutes;
            if (convertMinutes(minutes, hours, remainingMinutes)) 
            {
                std::cout << "Эквивалентное время: " << hours << " часов и " << remainingMinutes << " минут." << std::endl;
                validInput = true;
            } 
            else 
            {
                std::cout << "Ошибка! Введите корректное количество минут (неотрицательное число)." << std::endl;
            }
        }
        else
        {
            std::cout << "Ошибка! Введите числовое значение." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}