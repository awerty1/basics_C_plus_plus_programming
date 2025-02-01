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
    // Установка генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    int n;
    std::cout << "Введите размер квадратной матрицы (n x n): ";
    std::cin >> n;

    // Создание и заполнение квадратной матрицы случайными числами
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) 
	{
        for (int j = 0; j < n; ++j) 
		{
            matrix[i][j] = rand() % 101 - 50;  // Генерация чисел от -50 до 50
        }
    }
    
     // Вывод исходной матрицы
    std::cout << "Исходная матрица:\n";
    for (const auto& row : matrix)
	{
        for (int val : row) 
		{
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }

    // Поиск строки с наибольшим отрицательным элементом
    int maxNegativeElement = 0; // инициализируем максимальный отрицательный элемент значением, которого нет в диапазоне
    int rowWithMaxNeg = 0;

    for (int i = 0; i < n; ++i) 
	{
        for (int j = 0; j < n; ++j) 
		{
            if (matrix[i][j] < 0 && matrix[i][j] > maxNegativeElement) 
			{
                maxNegativeElement = matrix[i][j];
                rowWithMaxNeg = i;
            }
        }
    }

    if (rowWithMaxNeg != -1) 
	{
        // Удаление строки с наибольшим отрицательным элементом
        matrix.erase(matrix.begin() + rowWithMaxNeg);
    }

    // Вывод преобразованной матрицы
    std::cout << "Преобразованная матрица:\n";
    for (const auto& row : matrix) 
	{
        for (int val : row)
		{
            std::cout << val << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}