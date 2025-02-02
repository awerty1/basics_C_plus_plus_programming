/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Переставить местами строки матрицы так, чтобы её предпоследний столбец
оказался упорядоченным по возрастанию. Вывести преобразованную таким 
образом матрицу.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main() 
{
    // Установка генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    int n, m;
    std::cout << "Введите количество строк матрицы: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов матрицы: ";
    std::cin >> m;

    // Создание и заполнение матрицы случайными числами
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) 
	{
        for (int j = 0; j < m; ++j) 
		{
            matrix[i][j] = rand() % 101 - 50;  // Генерация чисел от -50 до 50
        }
    }

    // Вывод исходной матрицы
    std::cout << "Исходная матрица:\n";
    for (const auto& row : matrix)
	{
        for (int val : row) 
		{
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }

    // Перестановка строк матрицы так, чтобы предпоследний столбец был упорядочен по возрастанию
    std::sort(matrix.begin(), matrix.end(), [m](const std::vector<int>& a, const std::vector<int>& b) 
	{
        return a[m-2] < b[m-2];
    });

    // Вывод преобразованной матрицы
    std::cout << "Преобразованная матрица:\n";
    for (const auto& row : matrix) 
	{
        for (int val : row) 
		{
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}