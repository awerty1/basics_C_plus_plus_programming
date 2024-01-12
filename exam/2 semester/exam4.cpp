/*
В квадратной матрице порядка n найти наибольший по модулю элемент. Получить квадратную матрицу 
порядка n-1 путем выбрасывания из исходной матрицы строки и столбца на пересечении которых 
расположен элемент с найденным значением.
*/

#include <iostream>
#include <cmath>

const int MAX_SIZE = 100;

int main() 
{
    int n, maxElementRow, maxElementCol;
    double matrix[MAX_SIZE][MAX_SIZE]; 
    double maxElementValue = 0;
    
    std::cout << "Enter the size of the square matrix: ";
    std::cin >> n;
    
    // Input matrix elements
    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            std::cin >> matrix[i][j];
            if (std::abs(matrix[i][j]) > maxElementValue) 
            {
                maxElementValue = std::abs(matrix[i][j]);
                maxElementRow = i;
                maxElementCol = j;
            }
        }
    }
    
    // Find the element with the maximum absolute value
    std::cout << "The maximum absolute value is " << maxElementValue << std::endl;
    std::cout << "It is located at row " << maxElementRow + 1 << " and column " << maxElementCol + 1 << std::endl;

    // Create a new matrix of size n-1 by removing the row and column of the maximum element
    double newMatrix[MAX_SIZE-1][MAX_SIZE-1];
    int newRow = 0;
    for (int i = 0; i < n; i++) 
    {
        if (i == maxElementRow) 
        {
            continue;
        }
        int newCol = 0;
        for (int j = 0; j < n; j++) 
        {
            if (j == maxElementCol) 
            {
                continue;
            }
            newMatrix[newRow][newCol] = matrix[i][j];
            newCol++;
        }
        newRow++;
    }
    
    // Output the new matrix
    std::cout << "The new matrix is:" << std::endl;
    for (int i = 0; i < n-1; i++) 
    {
        for (int j = 0; j < n-1; j++) 
        {
            std::cout << newMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
