/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Отсортировать все столбцы с нечетными номерами по убыванию (нумерация 
строк ведется со стороны пользователя, т.е. с единицы). Вывести 
преобразованную таким образом матрицу.
*/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

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
    std::uniform_int_distribution<> dis(-50, 50);

    // Создание и заполнение матрицы случайными числами
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    std::cout << "Исходная матрица:\n";
    for (std::size_t i = 0; i < n; ++i) 
    {
        for (std::size_t j = 0; j < m; ++j) 
        {
            matrix[i][j] = dis(gen);
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Сортировка столбцов с нечетными номерами по убыванию
    for (std::size_t j = 0; j < m; j += 2) 
    {
        std::vector<int> columnValues(n);
        for (std::size_t i = 0; i < n; ++i) 
        {
            columnValues[i] = matrix[i][j];
        }
        std::sort(columnValues.rbegin(), columnValues.rend()); // Сортировка в обратном порядке
        for (std::size_t i = 0; i < n; ++i) 
        {
            matrix[i][j] = columnValues[i];
        }
    }

    // Вывод преобразованной матрицы
    std::cout << "Преобразованная матрица:\n";
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