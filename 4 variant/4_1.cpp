/*
Задание 1. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -10 до 10.
Переставить местами первый столбец с последним (т.е. каждый элемент первого 
столбца должен поменяться значением с соответствующим элементом 
последнего столбца). Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <random>
#include <iomanip>

// Функция для генерации случайного числа в диапазоне от -10 до 10
int generateRandomNumber() 
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-10, 10);
    return dis(gen);
}

// Функция для вывода матрицы на экран
void printMatrix(int**& matrix, int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() 
{
    int n, m;
    
    do 
    {
        std::cout << "Введите количество строк: ";
        std::cin >> n;
        std::cout << "Введите количество столбцов: ";
        std::cin >> m;

        if (n <= 0 || m <= 0) 
        {
            std::cout << "Некорректные размеры матрицы." << std::endl;
        }
    } 
    while (n <= 0 || m <= 0);
    

    // Создание заполнение матрицы случайными числами
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) 
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; ++j) 
        {
            matrix[i][j] = generateRandomNumber();
        }
    }

    std::cout << "Исходная матрица:" << std::endl;
    printMatrix(matrix, n, m);

    // Перестановка первого столбца с последним
    for (int i = 0; i < n; ++i) 
    {
        int temp = matrix[i][0];
        matrix[i][0] = matrix[i][m - 1];
        matrix[i][m - 1] = temp;
    }

    std::cout << "Преобразованная матрица:" << std::endl;
    printMatrix(matrix, n, m);

    // Освобождение памяти
    for (int i = 0; i < n; ++i) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
