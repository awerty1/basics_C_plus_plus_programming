/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Отсортировать все столбцы с нечетными номерами по убыванию (нумерация 
строк ведется со стороны пользователя, т.е. с единицы). Вывести 
преобразованную таким образом матрицу.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

const int MIN_VALUE = -50;
const int MAX_VALUE = 50;

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

    // Сортируем столбцы с нечетными номерами по убыванию
    for (int j = 1; j < m; j += 2)
    {
        int column[n];
        
        // Заполняем временный массив значениями из столбца
        for (int i = 0; i < n; i++)
        {
            column[i] = matrix[i][j];
        }
        
        // Сортируем временный массив
        std::sort(column, column + n, std::greater<int>());
        
        // Записываем отсортированные значения обратно в столбец
        for (int i = 0; i < n; i++)
        {
            matrix[i][j] = column[i];
        }
    }

    std::cout << "\nМатрица после сортировки столбцов с нечетными номерами:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}