/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -5 до 5.
Подсчитать и вывести дополнительным столбцом сумму каждой строки. Найти 
и вывести наименьший элемент этого столбца.
*/

#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime> // for generating random numbers

int main() 
{
    int n, m;
    
    do
    {
        std::cout << "Enter the number of rows (n): ";
        if (!(std::cin >> n) || n <= 0) 
        {
            std::cout << "Invalid input for n. Please enter a positive integer."
                    << std::endl;
        }
    }
    while (n <= 0);
    
    do
    {
        std::cout << "Enter the number of columns (m): ";
        if (!(std::cin >> m) || m <= 0)
        {
            std::cout << "Invalid input for m. Please enter a positive integer."
                        << std::endl;
        }
    }
    while (m <= 0);
    
    // Create a dynamic 2D array for the matrix
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
    }
    
    // Generate random numbers and calculate sum for each row
    srand(time(0)); // Seed the random number generator with current time
    int* sum_array = new int[n]; // Array to store the sums
    int min_sum = 0; // Variable to store the minimum sum

    // Fill the matrix with random numbers and calculate sum for each row
    for (int i = 0; i < n; i++)
    {
        int row_sum = 0; // Sum for current row
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = std::rand() % 11 - 5; // Random number in range -5 to 5
            row_sum += matrix[i][j];
        }
        sum_array[i] = row_sum;
        if (row_sum < min_sum) 
        {
            min_sum = row_sum;
        }
    }
    
    // Display the matrix
    std::cout << "Matrix:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << "  AVG: " << sum_array[i] << std::endl;
    }
    
    // Display the minimum element in the sum column
    std::cout << "Minimum element in the sum column: " << min_sum << std::endl;
    
    // Deallocate memory
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    
    delete[] matrix;
    delete[] sum_array;
    
    return 0;
}
