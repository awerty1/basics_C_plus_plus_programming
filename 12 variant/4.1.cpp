/*
Задание 1.Сформировать и вывести на экран квадратную матрицу из n строк 
и столбцов. Элементы матрицы формируются по такой закономерности: на 
главной и побочной диагоналях должны быть случайные числа в диапазоне от 1 
до 9, а все остальные элементы – нули. Например, при n = 5 может быть выведена 
такая матрица:
4 0 0 0 7
0 6 0 2 0
0 0 5 0 0
0 8 0 1 0
2 0 0 0 3
*/

#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include <iomanip>


int main()
{
    int n;
    do
    {
        std::cout << "Введите размерность матрицы: ";
        std::cin >> n; 
        
        if(n <= 0)
        {
            std::cout << "Размерность матрицы должна быть положительным числом!\n";
        }
    }
    while(n <= 0);
    
    
    int matrix[n][n];
    
    // Generate random numbers
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) // Main diagonal
            {
                matrix[i][j] = 1 + rand() % 9; // Random number between 1 and 9
            }
            else if ((i + j) == (n - 1)) // Secondary diagonal
            {
                matrix[i][j] = 1 + rand() % 9; // Random number between 1 and 9
            }
            else
            {
                matrix[i][j] = 0;
            }

            std::cout << std::setw(3) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}
