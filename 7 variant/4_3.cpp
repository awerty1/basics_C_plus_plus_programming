/*
Задание 3. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -10 до 10.
Вставить строку нулей после k-строки (нумерация строк ведется со стороны 
пользователя, т.е. с единицы). Сделать проверку на корректность ввода k: 1 ≤ k ≤ 
n. Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iomanip>

int main() 
{
    std::srand(std::time(0)); // Инициализация генератора случайных чисел

    int n, m;
    do
    {
        std::cout << "Введите количество строк (n): ";
        std::cin >> n;
        if (n <= 0)
        {
            std::cout << "Количество строк должно быть положительным. Пожалуйста, попробуйте снова.\n";
        }
    } 
    while (n <= 0);
    
    do
    {
        std::cout << "Введите количество столбцов (m): ";
        std::cin >> m;
        if (m <= 0)
        {
            std::cout << "Количество столбцов должно быть положительным. Пожалуйста, попробуйте снова.\n";
        }
    } 
    while (m <= 0);
    

    int matrix[n][m];

    // Заполнение матрицы случайными числами
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            matrix[i][j] = std::rand() % 21 - 10; // Генерация чисел от -10 до 10
        }
    }

    // Вывод исходной матрицы
    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << '\n';
    }

    int k;
    do
    {
        std::cout << "Введите номер строки, после которой нужно вставить строку нулей (1 <= k <= n): ";
        std::cin >> k;
        if (k < 1 || k > n) 
        {
            std::cout << "Некорректный ввод k. Пожалуйста, попробуйте снова.\n";
        }
    }
    while(k < 1 || k > n);
    
    // Вставка строки нулей
    int newMatrix[n + 1][m];
    int rowInsert = k; // Индекс k-строки в новой матрице
    for (int i = 0; i < n + 1; ++i) 
    {
        if (i < rowInsert) 
        {
            for (int j = 0; j < m; ++j) 
            {
                newMatrix[i][j] = matrix[i][j];
            }
        }
        else if (i == rowInsert) 
        {
            for (int j = 0; j < m; ++j) 
            {
                newMatrix[i][j] = 0; // Строка нулей
            }
        }
        else 
        {
            for (int j = 0; j < m; ++j) 
            {
                newMatrix[i][j] = matrix[i - 1][j]; // Сдвиг остальных строк
            }
        }
    }

    // Вывод преобразованной матрицы
    std::cout << "Преобразованная матрица:\n";
    for (int i = 0; i < n + 1; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            std::cout << std::setw(4) << newMatrix[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}