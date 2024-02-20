/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -10 до 10 (число n вводится с клавиатуры, его значение не больше 20). Найти 
сумму и количество всех элементов с чётными значениями. Сделать проверку на 
корректность ввода n.
*/

#include <iostream>
#include <random>

int main() 
{
    int n;
    int A[20];
    int sumOfEven = 0;
    int countOfEven = 0;

    std::cout << "Введите длину массива (не больше 20): ";
    std::cin >> n;

    if (n <= 0 || n > 20) 
    {
        std::cout << "Недопустимый размер массива!\n";
        return 1;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(-10, 10);

    for (int i = 0; i < n; ++i) 
    {
        A[i] = dis(gen);
        if (A[i] % 2 == 0) 
        {
            sumOfEven += A[i];
            countOfEven++;
        }
    }

    std::cout << "Сгенерированный массив A: ";
    for (int i = 0; i < n; ++i) 
    {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Сумма всех элементов с четными значениями: " << sumOfEven << std::endl;
    std::cout << "Количество элементов с четными значениями: " << countOfEven << std::endl;

    return 0;
}