/*
Задание 3. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Удалить строку, в которой находится наибольший элемент главной диагонали.
Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <cstdlib> // Для использования функций rand() и srand()
#include <ctime> // Для инициализации генератора случайных чисел
#include <iomanip>
#include <exception>

void generateMatrix(int** matrix, int rows, int cols) 
{
    srand(time(0)); // Инициализация генератора случайных чисел
    
    for (int i = 0; i < rows; i++) 
    {
        try
        {
            matrix[i] = new int[cols]; // Выделение памяти для строки матрицы
        } 
        catch (const std::bad_alloc& ex) 
        {
            // Возникла ошибка выделения памяти
            // Освобождаем ранее выделенную память
            for (int j = 0; j < i; j++) 
            {
                delete[] matrix[j];
            }
            delete[] matrix;
            matrix = nullptr;
            
            // Бросаем исключение дальше
            throw ex;
        }
        
        for (int j = 0; j < cols; j++) 
        {
            matrix[i][j] = rand() % 101 - 50; // Генерация случайного числа в диапазоне [-50, 50]
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

void deleteRowWithMaxDiagonalElement(int** matrix, int& rows, int cols) 
{
    int maxElement = matrix[0][0];
    int maxRowIndex = 0;
    
    for (int i = 1; i < rows; i++) 
    {
        if (matrix[i][i] > maxElement) 
        {
            maxElement = matrix[i][i];
            maxRowIndex = i;
        }
    }
    
    delete[] matrix[maxRowIndex]; // Освобождение памяти, выделенной для строки
    matrix[maxRowIndex] = nullptr;
    
    for (int i = maxRowIndex + 1; i < rows; i++) 
    {
        matrix[i - 1] = matrix[i]; // Сдвиг строк выше удаленной строки
    }
    
    matrix[rows - 1] = nullptr;
    rows--; // Уменьшение количества строк на 1
}

int main()
{
    int n, m;
    
    do
    {
        std::cout << "Введите количество строк: ";
        std::cin >> n;
    }
    while (n <= 0);
    
    do
    {
        std::cout << "Введите количество столбцов: ";
        std::cin >> m;
    }
    while (m <= 0);
    
    int** matrix = new int*[n]; // Выделение памяти для матрицы
    
    generateMatrix(matrix, n, m);
    
    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix, n, m);
    
    deleteRowWithMaxDiagonalElement(matrix, n, m);
    
    std::cout << "Преобразованная матрица:" << std::endl;
    printMatrix(matrix, n, m);
    
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i]; // Освобождение памяти, выделенной для строк
    }
    delete[] matrix; // Освобождение памяти, выделенной для указателей на строки
    
    return 0;
}
