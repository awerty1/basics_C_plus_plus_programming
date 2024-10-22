/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от 1 до 10. 
Подсчитать и вывести среднее арифметическое каждого нечетного столбца. 
Найти и вывести наибольшее среди них среднее арифметическое.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>


int main()
{
    srand(time(NULL)); // инициализация генератора случайных чисел

    int n, m;
    do 
    {
        std::cout << "Введите количество строк матрицы: ";
        std::cin >> n;
    }
    while (n <= 0);

    do 
    {
        std::cout << "Введите количество столбцов матрицы: ";
        std::cin >> m;
    } 
    while (m <= 0);

    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new int[m];
    }

    // заполнение матрицы случайными числами
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            matrix[i][j] = rand() % 10 + 1;
        }
    }

    // вывод матрицы
    std::cout << "Матрица:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            std::cout << std::setw(3) << matrix[i][j];
        }
        std::cout << std::endl;
    }

    // подсчет среднего арифметического каждого нечетного столбца
    double sum, avg, max_avg = 0;
    int count;
    for (int j = 0; j < m; j++) 
    {
        if (j % 2 == 0)
        {
            sum = 0;
            count = 0;
            for (int i = 0; i < n; i++) 
            {
                sum += matrix[i][j];
                count++;
            }
            if (count > 0) 
            {
                avg = sum / count;
                std::cout << "Среднее арифметическое " << j << "-го нечетного столбца: " << avg << std::endl;
                if (avg > max_avg) 
                {
                    max_avg = avg;
                }
            }
        }
    }

    // вывод наибольшего среднего арифметического
    std::cout << "Наибольшее среднее арифметическое: " << max_avg << std::endl;
    
    // освобождение памяти
    for (int i = 0; i < n; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}