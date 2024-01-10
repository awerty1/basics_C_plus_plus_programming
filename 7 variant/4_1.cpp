/*
Задание 1.Сформировать и вывести на экран квадратную матрицу из n строк 
и столбцов. Элементы матрицы формируются по такой закономерности: на 
главной диагонали должны быть единицы, на побочной диагонали (за 
исключением центрального элемента (пересечения диагоналей), если таковой 
имеется) – двойки, а все остальные элементы – нули. Например, при n = 5 может 
быть выведена такая матрица:
1 0 0 0 2
0 1 0 2 0
0 0 1 0 0
0 2 0 1 0
2 0 0 0 1
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

std::vector<std::vector<int>> generateMatrix(int n) 
{
    if (n <= 0) 
    {
        throw std::invalid_argument("Размер матрицы должен быть положительным");
    }
    
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) 
    {
        matrix[i][i] = 1;  // Заполняем главную диагональ единицами
        
        if (i != n / 2) 
        {
            matrix[i][n - i - 1] = 2;  // Заполняем побочную диагональ (за исключением центрального элемента) двойками
        }
    }
    
    return matrix;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) 
{
    for (const auto& row : matrix) 
    {
        for (int num : row) 
        {
            std::cout << std::setw(2) << num;
        }
        std::cout << std::endl;
    }
}

int main() 
{
    try 
    {
        int n;
        std::cout << "Введите размер матрицы (n): ";
        std::cin >> n;
        
        std::vector<std::vector<int>> matrix = generateMatrix(n);
        
        std::cout << "Сформированная матрица:" << std::endl;
        printMatrix(matrix);
    } 
    catch (const std::exception& ex) 
    {
        std::cout << "Ошибка: " << ex.what() << std::endl;
    }
    
    return 0;
}
