/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -50 до 50 (число n вводится с клавиатуры, его значение не больше 20). Найти 
количество положительных элементов и определить минимальный среди них. 
Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <iomanip>
#include <climits>
#include <random>

int main()
{
    const int MAX_SIZE = 20;
    const int MIN_RANGE = -50;
    const int MAX_RANGE = 50;

    int SIZE;
    std::cout << "Введите размер массива:";
    std::cin >> SIZE;

    // Проверка корректности ввода
    while (SIZE <= 0 || SIZE > MAX_SIZE)
    {
        std::cout << "\nРазмер массива должен быть в диапазоне от 1 до " << MAX_SIZE;
        std::cout << "\nВведите размер массива:";
        std::cin >> SIZE;
    }

    // Создание генератора случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(MIN_RANGE, MAX_RANGE);

    int* arrayA = new int[SIZE];
    std::cout << "\nИсходный массив:" << std::endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        arrayA[i] = dis(gen);
        std::cout << arrayA[i] << std::setw(4);
    }
    std::cout << std::endl;

    int count_positive = 0;
    int min_positive = INT_MAX;
    bool has_positive = false;

    for (size_t i = 0; i < SIZE; i++)
    {
        if (arrayA[i] > 0)
        {
            has_positive = true;
            count_positive++;

            if (arrayA[i] < min_positive)
            {
                min_positive = arrayA[i];
            }
        }
    }
    
     // Вывод массива после преобразований, если есть положительные числа
    if (has_positive)
    {
        std::cout << "\nМассив после преобразований:" << std::endl;
        for (size_t i = 0; i < SIZE; i++)
        {
            if (arrayA[i] > 0)
            {
                std::cout << arrayA[i] << std::setw(4);
            }
        }
    }
    
    // Вывод количества положительных чисел и минимального положительного числа
    std::cout << std::endl << "\nКоличество положительных чисел: " << count_positive;
    if (count_positive)
    {
        std::cout << "\nМинимальное положительное число: " << min_positive;
    }
    else
    {
        std::cout << "\nМинимальное положительное число отсутствует";
    }
    
    delete[] arrayA;

    return 0;
}