/*
Задание 2. Задан массив из n случайных целых чисел (число n вводится с
клавиатуры, его значение не больше 20). Определить максимальное количество
следующих подряд отрицательных элементов. В массиве могут быть все
элементы положительные, и такой вариант должен отрабатываться корректно.
Сделать проверку на корректность ввода n
*/

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>


const int MAX_SIZE = 20; // Максимально допустимый размер массива

int getUserInput() 
{
    bool validInputReceived{false};
    int input{};
    do 
    {
        std::cout << "Введите размер массива (от 1 до " << MAX_SIZE << "): ";
        if (!(std::cin >> input) || input <= 0 || input > MAX_SIZE) 
        {
            std::cerr << "Некорректный ввод! Пожалуйста, повторите.\n";
        }
        else
        {
            validInputReceived = true;
        }
    } 
    while (!validInputReceived);
    
    return input;
}

void fillRandomArray(std::vector<int>& arr, size_t size) 
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(-100, 100);
    
    std::cout << "Введите " << size << " целых чисел:" << std::endl;
    for (size_t i = 0; i < size; ++i) 
    {
        std::cout << "Введите ARR[" << i << "]:";
        std::cin >> arr[i];
        //arr[i] = distribution(generator);
    }
}

int findNegativeSequenceLength(const std::vector<int>& arr) 
{
    int max_negatives{0};
    int current_negatives{0};
    
     for (size_t i = 0; i < arr.size(); ++i) 
     {
        if (arr[i] < 0) 
        {
            current_negatives++;
        } 
        else 
        {
            max_negatives = std::max(max_negatives, current_negatives);
            current_negatives = 0;
        }
    }
    max_negatives = std::max(max_negatives, current_negatives);

    return max_negatives;
}

int main() 
{
    const auto n = getUserInput();
    if (n == -1) 
    {
        return EXIT_FAILURE;
    }

    std::vector<int> array(n);
    fillRandomArray(array, n);

    std::cout << "\nМассив:\n";
    for (auto& num : array) 
    {
        std::cout << num << ' ';
    }
    std::cout << '\n';

    std::cout << "Максимальная длина последовательности отрицательных элементов: " << findNegativeSequenceLength(array) << '\n';

    return EXIT_SUCCESS;
}
