/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50.
Переставить местами строки матрицы так, чтобы её первый столбец оказался
упорядоченным по убыванию. Вывести преобразованную таким образом
матрицу.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Функция для генерации случайного числа в заданном диапазоне
int generateRandomNumber(int min, int max) 
{
    return min + (rand() % (max - min + 1));
}

// Функция для вывода матрицы на экран
void printMatrix(int** matrix, int n, int m) 
{
    int maxNumWidth = 3;
    for (int i = 0; i < n; ++i) 
	{
        for (int j = 0; j < m; ++j) 
		{
            std::cout << std::setw(maxNumWidth) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для перестановки строк матрицы
void rearrangeRows(int** matrix, int n, int m) 
{
    std::sort(matrix, matrix + n, [](int* row1, int* row2) 
	{
        return *row1 > *row2; // Сортировка по убыванию первого элемента в строке
    });
}

int main() {
    // Инициализация генератора случайных чисел
    srand(time(0));

    int n, m;
    std::cout << "Введите количество строк (n): ";
    std::cin >> n;
    std::cout << "Введите количество столбцов (m): ";
    std::cin >> m;

    // Создание и заполнение матрицы случайными числами
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) 
	{
        matrix[i] = new int[m];
        for (int j = 0; j < m; ++j) 
		{
            matrix[i][j] = generateRandomNumber(-50, 50);
        }
    }

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix, n, m);

    // Перестановка строк матрицы
    rearrangeRows(matrix, n, m);

    std::cout << "Преобразованная матрица:" << std::endl;
    printMatrix(matrix, n, m);

    // Освобождение памяти
    for (int i = 0; i < n; ++i) 
	{
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}