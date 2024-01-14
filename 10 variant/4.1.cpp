/*
Задание 1.Сформировать и вывести на экран квадратную матрицу из n строк 
и столбцов. Элементы матрицы формируются по такой закономерности: все 
окаймляющие элементы должны быть случайными числами в диапазоне от 1 до 
9, а все остальные элементы – нулями. Например, при n = 4 может быть выведена 
такая матрица (внутри случайные числа):
9 3 4 8
1 0 0 6
7 0 0 6
1 4 5 8
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

int main()
{
    int n;
    do 
    {
        std::cout << "Введите размер квадратной матрицы: ";
        std::cin >> n;
        if (std::cin.fail()) 
        {
            std::cin.clear(); // Сброс флага ошибки
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
            std::cout << "Ошибка ввода. Попробуйте еще раз." << std::endl;
            continue;
        }
    } 
    while (n <= 0);

    // Инициализация генератора случайных чисел
    srand(time(nullptr));

    // Создание и заполнение матрицы
    int **matrix = new int*[n]();
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new int[n]();
        for (int j = 0; j < n; j++) 
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) 
            {
                // Окаймляющие элементы
                matrix[i][j] = rand() % 9 + 1;
            } 
            else 
            {
                // Остальные элементы
                matrix[i][j] = 0;
            }
        }
    }

    // Вывод матрицы на экран
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    // Освобождение памяти
    for (int i = 0; i < n; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}