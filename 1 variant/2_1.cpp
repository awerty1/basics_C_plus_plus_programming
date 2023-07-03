/*
Задание 1. Составить программу, проверяющую, является ли 
последовательность из десяти целых чисел, вводимых с клавиатуры, 
возрастающей. 
*/

#include <iostream>
#include <limits>

int main()
{
    const int sequenceLength = 10;
    int numbers[sequenceLength];

    std::cout << "Введите последовательность из " << sequenceLength << " целых чисел: ";

    // Ввод чисел
    for (int i = 0; i < sequenceLength; ++i)
    {
        while (!(std::cin >> numbers[i])) {
            std::cout << "Ошибка ввода. Пожалуйста, введите целое число: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    bool isIncreasing = true;

    // Проверка на возрастание
    for (int i = 1; i < sequenceLength; ++i)
    {
        if (numbers[i] <= numbers[i - 1])
        {
            isIncreasing = false;
            break;
        }
    }

    // Вывод результата
    if (isIncreasing)
    {
        std::cout << "Последовательность является возрастающей." << std::endl;
    }
    else
    {
        std::cout << "Последовательность не является возрастающей." << std::endl;
    }

    return 0;
}
