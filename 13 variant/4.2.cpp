/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от 1 до 10. 
Подсчитать и вывести сумму каждого четного столбца. Найти и вывести 
наибольшую среди них сумму.
*/

#include <iostream>
#include <vector>
#include <random>

int main() 
{
    std::size_t n, m;
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов: ";
    std::cin >> m;

    // Генератор случайных чисел для элементов матрицы
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);

    // Создание и заполнение матрицы случайными числами
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (std::size_t i = 0; i < n; ++i) 
    {
        for (std::size_t j = 0; j < m; ++j) 
        {
            matrix[i][j] = dis(gen);
        }
    }

    // Вывод изначальной матрицы
    std::cout << "Исходная матрица:\n";
    for (const auto& row : matrix) 
    {
        for (int el : row) 
        {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

    // Подсчет сумм четных столбцов и поиск наибольшей суммы
    int maxSum = 0;
    for (size_t j = 0; j < m; ++j) 
    {
        if (j % 2 == 1) 
        { // Четные столбцы в C++ индексируются с нуля
            int sum = 0;
            for (size_t i = 0; i < n; ++i) 
            {
                sum += matrix[i][j];
            }
            std::cout << "Сумма четного столбца " << j + 1 << ": " << sum << std::endl;
            if (sum > maxSum) 
            {
                maxSum = sum;
            }
        }
    }

    // Вывод наибольшей суммы
    std::cout << "Наибольшая сумма среди четных столбцов: " << maxSum << std::endl;

    return 0;
}