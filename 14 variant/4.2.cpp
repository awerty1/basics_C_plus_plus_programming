/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -10 до 20.
Найти и вывести значение наибольшего элемента и сумму строки, в которой есть 
этот наибольший элемент (строк может быть несколько – необходимо выбрать 
первую из них).

*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() 
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    int n = 5; // Количество строк
    int m = 4; // Количество столбцов

    // Создание и заполнение матрицы с случайными числами
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            matrix[i][j] = std::rand() % 31 - 10; // Числа в диапазоне от -10 до 20
        }
    }

    // Вывод матрицы
    std::cout << "Исходная матрица: \n";
    for (const auto& row : matrix) 
    {
        for (int num : row) 
        {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }

    int maxElement = -11; // Минимальное значение в диапазоне
    int maxRowIndex = 0;

    // Нахождение строки с максимальным элементом и значения самого элемента
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (matrix[i][j] > maxElement) 
            {
                maxElement = matrix[i][j];
                maxRowIndex = i;
            }
        }
    }

    // Вывод строки с первым найденным максимальным элементом
    std::cout << "Первая строка с максимальным элементом: ";
    for (int num : matrix[maxRowIndex]) 
    {
        std::cout << num << ' ';
    }
    std::cout << std::endl;

    // Вывод значения максимального элемента
    std::cout << "Наибольший элемент в матрице: " << maxElement << std::endl;

    return 0;
}