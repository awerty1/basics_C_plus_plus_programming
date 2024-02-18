/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Определить, есть ли в массиве все числа 
из диапазона [0..3]
*/

#include <iostream>
#include <random>
#include <algorithm>

bool containsAllNumbersInRange(int arr[], int size) 
{
    return std::all_of(arr, arr + size, [](int num) 
    {
        return num >= 0 && num <= 3;
    });
}

int main() 
{
    int n;
    std::cout << "Введите длину массива (не больше 20): ";
    std::cin >> n;

    if (n <= 0 || n > 20) 
    {
        std::cout << "Недопустимый размер массива!\n";
        return 1;
    }

    int arr[20];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 10);

    for (int i = 0; i < n; ++i)
    {
        arr[i] = dis(gen);
    }

    std::cout << "Сгенерированный массив: ";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    if (containsAllNumbersInRange(arr, n)) 
    {
        std::cout << "В массиве содержатся все числа из диапазона [0..3]\n";
    }
    else 
    {
        std::cout << "В массиве отсутствуют все числа из диапазона [0..3]\n";
    }

    return 0;
}