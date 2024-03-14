/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Переставить местами строки матрицы так, чтобы её предпоследний столбец
оказался упорядоченным по возрастанию. Вывести преобразованную таким 
образом матрицу.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

int main() 
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int n, m; // Размеры матрицы
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов: ";
    std::cin >> m;

    // Создание и заполнение матрицы случайными числами
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            matrix[i][j] = std::rand() % 101 - 50; // Числа в диапазоне от -50 до 50
        }
    }

    // Вывод исходной матрицы
    std::cout << "Исходная матрица:" << std::endl;
    for (const auto& row : matrix) 
    {
        for (int num : row) 
        {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }

    // Перестановка строк так, чтобы предпоследний столбец был упорядочен по возрастанию
    std::sort(matrix.begin(), matrix.end(), [m](const std::vector<int>& a, const std::vector<int>& b) 
    {
        return a[m-2] < b[m-2];
    });

    // Вывод преобразованной матрицы
    std::cout << "Матрица с упорядоченным предпоследним столбцом:" << std::endl;
    for (const auto& row : matrix) 
    {
        for (int num : row) 
        {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}