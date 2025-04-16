/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Отсортировать все строки с нечетными номерами по возрастанию (нумерация 
строк ведется со стороны пользователя, т.е. с единицы). Вывести 
преобразованную таким образом матрицу.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// Функция для генерации случайного числа в заданном диапазоне
int getRandomNumber(int min, int max)
{
    return min + rand() % (max - min + 1);
}

// Функция для вывода матрицы на экран
void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (const auto& row : matrix)
    {
        for (int num : row)
        {
            std::cout << std::setw(5) << num;
        }
        std::cout << std::endl;
    }
}

int main()
{
    // Инициализация генератора случайных чисел
    srand(time(0));
    
    int n, m;
    do
    {
        std::cout << "Введите количество строк (n): ";
        std::cin >> n;
        
        std::cout << "Введите количество столбцов (m): ";
        std::cin >> m;
        
        if (n <= 0 || m <= 0)
        {
            std::cout << "Количество строк и столбцов должно быть больше 0. \
            \nПопробуйте снова." << std::endl;
        }
    }
    while (n <= 0 || m <= 0);
    
    // Создание матрицы и заполнение случайными числами
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            matrix[i][j] = getRandomNumber(-50, 50);
        }
    }
    
    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix);
    
    // Сортировка строк с нечетными номерами
    for (int i = 1; i < n; i += 2)
    {
        if (i < matrix.size())
        {
            std::sort(matrix[i].begin(), matrix[i].end());    
        }
    }
    
    std::cout << "\nПреобразованная матрица:" << std::endl;
    printMatrix(matrix);
    
    return 0;
}
