/*
Задание 3. Сформировать и вывести квадратную матрицу из n строк и 
столбцов. Элементы матрицы должны быть случайными числами в диапазоне от 
-50 до 50. Удалить строку, в которой находится наибольший элемент матрицы.
Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()
#include <iomanip>

const int MIN_VALUE = -50;
const int MAX_VALUE = 50;

int main()
{
    int n;

    do
    {
        std::cout << "Введите размер квадратной матрицы: ";
        std::cin >> n;

        if (n <= 0)
        {
            std::cout << "Размер матрицы должен быть положительным числом." << std::endl;
        }
    }
    while (n <= 0);

    int matrix[n][n];

    // Генерация случайных чисел
    srand(time(0));

    // Заполнение матрицы случайными числами
    std::cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = MIN_VALUE + rand() % (MAX_VALUE - MIN_VALUE + 1);
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // Нахождение индекса строки с наибольшим элементом
    int maxRow = 0;
    int maxElement = matrix[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > maxElement)
            {
                maxElement = matrix[i][j];
                maxRow = i;
            }
        }
    }

    // Удаление строки с наибольшим элементом
    for (int i = maxRow; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = matrix[i + 1][j];
        }
    }

    n--; // уменьшение размера матрицы после удаления строки

    // Вывод преобразованной матрицы
    std::cout << "Преобразованная матрица:" << std::endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}