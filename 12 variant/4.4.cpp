/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Переставить местами строки матрицы так, чтобы её последний столбец оказался 
упорядоченным по возрастанию. Вывести преобразованную таким образом 
матрицу.

*/

#include <iostream>
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()
#include <algorithm> // для std::sort
#include <iomanip>

const int MIN_VALUE = -50;
const int MAX_VALUE = 50;

int main()
{
    int n, m;
    
    do 
    {
        std::cout << "Введите количество строк: ";
        std::cin >> n;

        if (n <= 0 ) 
        {
            std::cout << "Количество строк должно быть положительным числом." << std::endl;
        }
    } 
    while (n <= 0);
    
    do 
    {
        std::cout << "Введите количество столбцов: ";
        std::cin >> m;

        if (m <= 0) 
        {
            std::cout << "Количество столбцов должно быть положительным числом." << std::endl;
        }
    } 
    while (m <= 0);
    
    
    int matrix[n][m];

    // Генерация случайных чисел
    srand(time(0));

    // Заполнение матрицы случайными числами
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
        }
    }

    // Вывод исходной матрицы
    std::cout << "Исходная матрица:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // Перестановка строк матрицы
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (matrix[i][m - 1] > matrix[i + 1][m - 1])
            {
                std::swap_ranges(matrix[i], matrix[i] + m, matrix[i + 1]);
                swapped = true;
            }
        }
    }
    while (swapped);

    // Вывод преобразованной матрицы
    std::cout << "Преобразованная матрица:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}