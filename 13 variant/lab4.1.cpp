/*
Задание 1. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -10 до 10.
Переставить местами вторую строку с последней (т.е. каждый элемент второй
строки должен поменяться значением с соответствующим элементом последней 
строки). Вывести преобразованную таким образом матрицу
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
    std::uniform_int_distribution<> dis(-10, 10);

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

    // Перестановка второй и последней строки
    if (n >= 2) 
    {
        std::swap(matrix[1], matrix[n - 1]);
    }

    // Вывод матрицы после перестановки строк
    std::cout << "Матрица после перестановки строк:\n";
    for (const auto& row : matrix) 
    {
        for (int el : row) 
        {
            std::cout << el << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}