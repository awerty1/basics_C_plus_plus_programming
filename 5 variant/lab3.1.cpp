/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне
от -10 до 10 (число n вводится с клавиатуры, его значение не больше 20). Найти
сумму и количество всех элементов с нечётными значениями. Сделать проверку
на корректность ввода n.
*/

#include <iostream>
#include <vector>
#include <random>

int main() 
{
    int n;
    
    do 
    {
        std::cout << "Введите значение n (не больше 20): ";
        std::cin >> n;

        if (n <= 0 || n > 20) 
        {
            std::cerr << "Ошибка: некорректный ввод n. Повторите попытку." << std::endl;
        }
    } 
    while (n <= 0 || n > 20);

    std::vector<int> A(n);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-10, 10);

    int sum_odd = 0;
    int count_odd = 0;

    for (int i = 0; i < n; ++i) 
    {
        
        A[i] = dis(gen);
        if (A[i] % 2 != 0) 
        {
            
            sum_odd += A[i];
            count_odd++;
        }
    }

    std::cout << "Сформированный массив A: ";
    for (int num : A) 
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Сумма всех элементов с нечётными значениями: " << sum_odd << std::endl;
    std::cout << "Количество всех элементов с нечётными значениями: " << count_odd << std::endl;

    return 0;
}


