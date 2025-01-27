/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -10 до 10 (число n вводится с клавиатуры, его значение не больше 20). Найти 
разность сумм положительных и отрицательных элементов. Сделать проверку на 
корректность ввода n.
*/

#include <iostream>
#include <ctime>    // Для работы со временем
#include <cstdlib>  // Для генерации случайных чисел

int main() 
{
    int n;
    std::cout << "Введите число n (не более 20): ";
    std::cin >> n;

    if (n <= 0 || n > 20) 
    {
        std::cout << "Ошибка: введено некорректное значение n." << std::endl;
        return 1;
    }

    // Инициализация генератора случайных чисел
    srand(time(nullptr));

    int A[n];  // Объявляем массив A размера n
    int sumPositive = 0;
    int sumNegative = 0;

    // Заполняем массив случайными числами от -10 до 10 и считаем суммы положительных и отрицательных элементов
    for (int i = 0; i < n; ++i) 
    {
        A[i] = rand() % 21 - 10;  // Генерация числа от -10 до 10
        if (A[i] > 0) 
        {
            sumPositive += A[i];
        } 
        else 
        {
            sumNegative += A[i];
        }
    }

    int difference = sumPositive - sumNegative;

    // Вывод результатов
    std::cout << "Массив A из " << n << " случайных чисел:" << std::endl;
    for (int i = 0; i < n; ++i) 
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Сумма положительных элементов: " << sumPositive << std::endl;
    std::cout << "Сумма отрицательных элементов: " << sumNegative << std::endl;
    std::cout << "Разность сумм: " << difference << std::endl;

    return 0;
}


