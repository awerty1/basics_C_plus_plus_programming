/*
Задание 3. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Поменять местами элементы главной и побочной диагоналей матрицы по 
столбцам. Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

const int MIN_VALUE = -50;
const int MAX_VALUE = 50;

void generateMatrix(int** matrix, int rows, int columns) 
{
    srand(time(NULL));
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
        }
    }
}

void swapDiagonals(int** matrix, int size) 
{
    for (int i = 0; i < size; i++)
    {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[i][size - i - 1];
        matrix[i][size - i - 1] = temp;
    }
}

void printMatrix(int** matrix, int rows, int columns) 
{
    int maxElementWidth = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            int elementWidth = std::to_string(matrix[i][j]).length();
            if (elementWidth > maxElementWidth) {
                maxElementWidth = elementWidth;
            }
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) 
        {
            std::cout << std::setw(maxElementWidth) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() 
{
    int n, m;
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов: ";
    std::cin >> m;

    // Создание матрицы
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new int[m];
    }

    // Генерация и вывод исходной матрицы
    generateMatrix(matrix, n, m);
    std::cout << "Исходная матрица:\n";
    printMatrix(matrix, n, m);

    // Перестановка диагоналей и вывод преобразованной матрицы
    swapDiagonals(matrix, std::min(n, m));
    std::cout << "Преобразованная матрица:\n";
    printMatrix(matrix, n, m);

    // Освобождение памяти
    for (int i = 0; i < n; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}