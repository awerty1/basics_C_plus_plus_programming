/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Переставить местами строки матрицы так, чтобы её второй столбец (нумерация 
столбцов ведется со стороны пользователя, т.е. с единицы) оказался
упорядоченным по возрастанию. Вывести преобразованную таким образом 
матрицу.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main() 
{
    int n, m;
    
    do 
    {
        std::cout << "Введите количество строк: ";
        std::cin >> n;
        if (n <= 0) 
        {
            std::cout << "Количество строк должно быть положительным числом. Пожалуйста, повторите ввод.\n";
        }
    } 
    while (n <= 0);
    
    do
    {
        std::cout << "Введите количество столбцов: ";
        std::cin >> m;
        if (m <= 0) 
        {
            std::cout << "Количество столбцов должно быть положительным числом. Пожалуйста, повторите ввод.\n";
        }
    }
    while (m <= 0);

    // Создаем двумерный динамический массив размером n x m
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) 
    {
        matrix[i] = new int[m];
    }

    // Заполняем матрицу случайными числами от -50 до 50
    std::srand(std::time(nullptr));
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            matrix[i][j] = std::rand() % 101 - 50;
        }
    }

    // Выводим исходную матрицу
    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            std::cout << std::setw(5)<< matrix[i][j];
        }
        std::cout << std::endl;
    }

    // Переставляем строки матрицы так, чтобы второй столбец был упорядочен по возрастанию
    for (int i = 0; i < n - 1; ++i) 
    {
        for (int j = i + 1; j < n; ++j) 
        {
            if (matrix[i][1] > matrix[j][1]) 
            {
                int temp = matrix[i][1];
                matrix[i][1] = matrix[j][1];
                matrix[j][1] = temp;
            }
        }
    }

    // Выводим преобразованную матрицу
    std::cout << "Преобразованная матрица:\n";
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // Освобождаем память, выделенную для матрицы
    for (int i = 0; i < n; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}