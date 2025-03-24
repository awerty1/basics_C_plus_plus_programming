/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Переставить местами столбцы матрицы так, чтобы её последняя строка оказалась 
упорядоченной по убыванию. Вывести преобразованную таким образом 
матрицу.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <random>

const int MIN_VALUE = -50;
const int MAX_VALUE = 50;

void generateMatrix(int** matrix, int rows, int cols) 
{
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(MIN_VALUE, MAX_VALUE);
    
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            matrix[i][j] = distribution(generator);;
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void swapColumns(int** matrix, int col1, int col2, int rows) 
{
    for (int i = 0; i < rows; i++) 
    {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

void sortLastRow(int** matrix, int cols) 
{
    for (int i = 0; i < cols; i++) 
    {
        bool swapped = false;
        for (int j = 0; j < cols - i - 1; j++) 
        {
            if (matrix[cols - 1][j] < matrix[cols - 1][j + 1]) 
            {
                swapColumns(matrix, j, j + 1, cols);
                swapped = true;
            }
        }
        if (!swapped) 
        {
            break;
        }
    }
}

int main() 
{
    int n, m;

     do 
     {
        std::cout << "Введите количество строк (n): ";
        std::cin >> n;

        if (n <= 0) 
        {
            std::cout << "Некорректное значение. Пожалуйста, введите положительное число.\n";
        }
    } 
    while (n <= 0);

    do 
    {
        std::cout << "Введите количество столбцов (m): ";
        std::cin >> m;

        if (m <= 0) 
        {
            std::cout << "Некорректное значение. Пожалуйста, введите положительное число.\n";
        }
    } 
    while (m <= 0);

    // Выделение памяти под матрицу
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new int[m];
    }

    // Генерация и вывод исходной матрицы
    generateMatrix(matrix, n, m);
    std::cout << "Исходная матрица:\n";
    printMatrix(matrix, n, m);

    // Сортировка последней строки матрицы
    sortLastRow(matrix, m);

    // Вывод преобразованной матрицы
    std::cout << "\nМатрица после перестановки столбцов:\n";
    printMatrix(matrix, n, m);

    // Освобождение памяти
    for (int i = 0; i < n; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}