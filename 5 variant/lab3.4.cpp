/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с
клавиатуры, его значение не больше 20). Определить, есть ли в массиве все числа
из диапазона [-2..1].
*/

#include <iostream>
#include <array>
#include <random>
#include <algorithm>

int main()
{
    int n;
    do
    {
        std::cout << "Введите количество элементов в массиве (не более 20): ";
        std::cin >> n;
        
        if (n <= 0 || n > 20)
        {
            std::cerr << "Ошибка: некорректное количество элементов. Пожалуйста, введите число от 1 до 20." << std::endl;
        }
    }
    while (n <= 0 || n > 20);
    
    std::array<int, 20> numbers{};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(-2, 1);
    
    std::generate(numbers.begin(), numbers.begin() + n, [&]()
    {
        return distrib(gen);
    });
    
    std::cout << "Сгенерированный массив чисел:" << std::endl;
    for (int i = 0; i < n; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    bool containsAll = std::all_of(numbers.begin(), numbers.begin() + n, [](int num)
    {
        return (num >= -2 && num <= 1);
    });
    
    if (containsAll)
    {
        std::cout << "В массиве содержатся все числа из диапазона [-2, 1]." << std::endl;
    }
    else
    {
        std::cout << "В массиве отсутствуют все числа из диапазона [-2, 1]." << std::endl;
    }
    
    return 0;
}
