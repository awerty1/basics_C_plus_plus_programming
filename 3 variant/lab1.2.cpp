/*
Задание 2. Написать программу пересчета величины временного интервала, 
заданного в секундах, в величину, выраженную в часах, минутах и секундах. 
Интервал в секундах вводится, например, 3725.Тогда программа должна вывести 
1 ч. 2 м. 5 сек
*/

#include <iostream>

int main() 
{
    int seconds;
    do 
    {
        std::cout << "Введите интервал в секундах: ";
        std::cin >> seconds;
        
        if (seconds < 0) 
        {
            std::cout << "Ошибка! Введите положительное число." << std::endl;
        }
    } 
    while (seconds < 0);
    
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int remainingSeconds = (seconds % 3600) % 60;
    
    std::cout << hours << " ч. " << minutes << " м. " << remainingSeconds << " сек." << std::endl;
    
    return 0;
}
