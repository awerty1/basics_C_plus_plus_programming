/*
Задание 3. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -10 до 10. 
Вставить столбец нулей перед столбцом, в котором находится максимальный 
элемент матрицы. Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

const int MIN_VALUE = -10;
const int MAX_VALUE = 10;

int main()
{
    int n, m;
    
    do 
    {
        std::cout << "Введите количество строк: ";
        std::cin >> n;
        if (n <= 0) 
        {
            std::cout << "Количество строк должно быть положительным!\n";
        }
    } 
    while (n <= 0);

    do 
    {
        std::cout << "Введите количество столбцов: ";
        std::cin >> m;
        if (m <= 0) 
        {
            std::cout << "Количество столбцов должно быть положительным!\n";
        }
    } 
    while (m <= 0);

    // Создаем двумерный массив и инициализируем его случайными числами
    int matrix[n][m];
    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // Находим столбец с максимальным элементом
    int maxColumn = 0;
    int maxElement = matrix[0][0];

    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][j] > maxElement)
            {
                maxElement = matrix[i][j];
                maxColumn = j;
            }
        }
    }

    // Вставляем столбец нулей перед столбцом с максимальным элементом
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j > maxColumn; j--)
        {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][maxColumn] = 0;
    }

    std::cout << "\nМатрица после вставки столбца нулей:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}