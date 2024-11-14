/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от 1 до 10.(-10 to 10)
Подсчитать и вывести дополнительным столбцом количество отрицательных 
чисел в каждой строке. Найти и вывести наибольшее количество отрицательных 
чисел.
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
    int maxNegatives = 0;

    for (int i = 0; i < n; i++)
    {
        int negatives = 0;
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 21 - 10;
            if (matrix[i][j] < 0)
            {
                negatives++;
            }
            std::cout << std::setw(5) << matrix[i][j];
        }
        std::cout << std::setw(5) <<"NEG:" << negatives << std::endl;

        if (negatives > maxNegatives)
        {
            maxNegatives = negatives;
        }
    }

    std::cout << "Наибольшее количество отрицательных чисел: " << maxNegatives << std::endl;

    return 0;
}
