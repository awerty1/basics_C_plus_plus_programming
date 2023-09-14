/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -20 до 20.
Найти и вывести значение наименьшего элемента и среднее арифметическое 
столбца, в котором есть этот наименьший элемент (столбцов может быть 
несколько – необходимо выбрать первый из них).
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <iomanip>

int main() 
{
    try 
    {
        std::srand(std::time(0)); // Инициализация генератора случайных чисел

        int n, m;
        std::cout << "Введите количество строк (n): ";
        std::cin >> n;
        if (n <= 0) 
        {
            throw std::invalid_argument("Количество строк должно быть больше 0");
        }
        std::cout << "Введите количество столбцов (m): ";
        std::cin >> m;
        if (m <= 0) 
        {
            throw std::invalid_argument("Количество столбцов должно быть больше 0");
        }

        int matrix[n][m];

        // Заполнение матрицы случайными числами
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < m; ++j) 
            {
                matrix[i][j] = std::rand() % 41 - 20; // Генерация чисел от -20 до 20
            }
        }

        // Вывод матрицы
        std::cout << "Матрица:\n";
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < m; ++j) 
            {
                std::cout << std::setw(5) << matrix[i][j];
            }
            std::cout << '\n';
        }

        // Поиск наименьшего элемента и среднего арифметического столбца
        int smallest = matrix[0][0];
        double sum = 0;
        int colIndex = 0;

        for (int j = 0; j < m; ++j) 
        {
            sum = 0;
            for (int i = 0; i < n; ++i) 
            {
                sum += matrix[i][j];

                if (matrix[i][j] < smallest) 
                {
                    smallest = matrix[i][j];
                    colIndex = j;
                }
            }
        }

        if (colIndex == 0) 
        {
            throw std::logic_error("Матрица пуста");
        }

        double average = sum / n;

        std::cout << "Наименьший элемент: " << smallest << '\n';
        std::cout << "Среднее арифметическое столбца " << colIndex << ": " << average << '\n';
    } 
    catch (const std::exception& e) 
    {
        std::cout << "Ошибка: " << e.what() << '\n';
    }

    return 0;
}