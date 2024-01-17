/*
Задание 1. Написать программу для нахождения максимального из десяти 
произвольных чисел, вводимых с клавиатуры. 
*/

#include <iostream>

int main() 
{
    int numbers[10]; // Массив для хранения 10 чисел
    int maxNumber;   // Переменная для хранения максимального числа

    // Ввод чисел с клавиатуры
    std::cout << "Введите 10 чисел:" << std::endl;
    for (int i = 0; i < 10; i++) 
    {
        std::cout << "Число " << i + 1 << ": ";
        std::cin >> numbers[i];
    }

    // Поиск максимального числа
    maxNumber = numbers[0]; // Пусть первое число будет максимальным
    for (int i = 1; i < 10; i++) 
    {
        if (numbers[i] > maxNumber) 
        {
            maxNumber = numbers[i];
        }
    }

    // Вывод результата
    std::cout << "Максимальное число: " << maxNumber << std::endl;

    return 0;
}