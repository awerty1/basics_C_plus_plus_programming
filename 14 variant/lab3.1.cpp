/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -10 до 10 (число n вводится с клавиатуры, его значение не больше 20). Найти 
среднее арифметическое всех элементов с нечетными номерами. Сделать 
проверку на корректность ввода n.
*/

#include <iostream>
#include <cstdlib>

int main() 
{
    int n, sum = 0, count = 0;

    std::cout << "Введите количество элементов массива (не больше 20): ";
    std::cin >> n;

    if (n <= 0 || n > 20) 
    {
        std::cout << "Ошибка: введено некорректное значение n\n";
        return 1;
    }

    int A[n];
    for (int i = 0; i < n; ++i) 
    {
        A[i] = rand() % 21 - 10; // генерация случайного числа от -10 до 10
        if (i % 2 == 1) 
        {
            sum += A[i];
            count++;
        }
    }

    if (count > 0) 
    {
        double average = static_cast<double>(sum) / count;
        std::cout << "Массив A: ";
        for (int i = 0; i < n; ++i) 
        {
            std::cout << A[i] << " ";
        }
        std::cout << "\nСреднее арифметическое всех элементов с нечетными номерами: " << average << std::endl;
    } 
    else 
    {
        std::cout << "В массиве нет элементов с нечетными номерами\n";
    }

    return 0;
}