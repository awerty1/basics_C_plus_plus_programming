/*
Задание 3. Сформировать и вывести квадратную матрицу из n строк и 
столбцов. Элементы матрицы должны быть случайными числами в диапазоне от 
-50 до 50. Удалить строку, в которой находится наибольший отрицательный 
элемент. Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() 
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int n; // Размер квадратной матрицы
    std::cout << "Введите размер квадратной матрицы: ";
    std::cin >> n;

    // Создание и заполнение квадратной матрицы случайными числами
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            matrix[i][j] = std::rand() % 101 - 50; // Числа в диапазоне от -50 до 50
        }
    }

    // Вывод исходной матрицы
    std::cout << "Исходная матрица:" << std::endl;
    for (const auto& row : matrix) 
    {
        for (int num : row) 
        {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }

    int minNegative = 51; // Максимальное значение в диапазоне
    int minNegativeRow = -1;

    // Находим строку с наименьшим отрицательным элементом
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (matrix[i][j] < 0 && matrix[i][j] < minNegative) 
            {
                minNegative = matrix[i][j];
                minNegativeRow = i;
            }
        }
    }

    // Удаляем строку с наименьшим отрицательным элементом
    if (minNegativeRow != -1) 
    {
        matrix.erase(matrix.begin() + minNegativeRow);
        n--; // Уменьшаем размер матрицы
    }

    // Вывод преобразованной матрицы
    std::cout << "Матрица после удаления строки с наименьшим отрицательным элементом:" << std::endl;
    for (const auto& row : matrix) 
    {
        for (int num : row) 
        {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}