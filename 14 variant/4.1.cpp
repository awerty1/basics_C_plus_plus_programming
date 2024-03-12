/*
Задание 1.Сформировать и вывести на экран квадратную матрицу из n строк 
и столбцов (n – начетное натуральное число). Элементы матрицы формируются 
по такой закономерности: центральные строка и столбец должны быть 
единицами, а все остальные элементы – нули. Например, при n = 5 может быть 
выведена такая матрица (внутри случайные числа):
0 0 1 0 0
0 0 1 0 0
1 1 1 1 1
0 0 1 0 0
0 0 1 0 0
*/

#include <iostream>
#include <vector>

void printMatrix(const std::vector<std::vector<int>>& matrix) 
{
    for (const auto& row : matrix) 
    {
        for (int num : row) 
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() 
{
    int n;
    std::cout << "Введите значение n (нечетное натуральное число): ";
    std::cin >> n;

    if (n % 2 == 0 || n < 1) 
    {
        std::cout << "Ошибка! Введите нечетное натуральное число." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    // Заполнение центральной строки и столбца единицами
    for (int i = 0; i < n; ++i) 
    {
        matrix[i][n / 2] = 1; // Центральный столбец
        matrix[n / 2][i] = 1; // Центральная строка
    }

    printMatrix(matrix);

    return 0;
}
