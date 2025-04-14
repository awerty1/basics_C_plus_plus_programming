/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -10 до 20.
Найти и вывести значение наибольшего элемента и сумму столбца, в котором
есть этот наибольший элемент (столбцов может быть несколько – необходимо 
выбрать первый из них).
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() 
{
    int n, m;
    std::cout << "Enter the number of rows: ";
    std::cin >> n;
    std::cout << "Enter the number of columns: ";
    std::cin >> m;

    // Initialize random seed
    std::srand(std::time(0));

    // Create and populate the matrix
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) 
        {
            matrix[i][j] = std::rand() % 31 - 10; // Generates random numbers from -10 to 20
        }
    }

    // Print the matrix
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    // Find the maximum element and sum of the column containing it
    int maxElement = matrix[0][0];
    int maxColSum = 0;
    int maxColIndex = 0;
    for (int j = 0; j < m; j++) 
    {
        int colSum = 0;
        for (int i = 0; i < n; i++) 
        {
            colSum += matrix[i][j];
            if (matrix[i][j] > maxElement) 
            {
                maxElement = matrix[i][j];
                maxColSum = colSum;
                maxColIndex = j;
            }
        }
    }

    std::cout << "Maximum element: " << maxElement << std::endl;
    std::cout << "Sum of the column with the maximum element: " << maxColIndex + 1 << ":" << maxColSum << std::endl;
    
    
    // Free the memory
    for (int i = 0; i < n; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}