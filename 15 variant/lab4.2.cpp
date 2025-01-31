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
    // Установка генератора случайных чисел
    srand(static_cast<unsigned int>(time(nullptr)));

    int n, m;
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов: ";
    std::cin >> m;

    // Создание и заполнение матрицы случайными числами
    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            matrix[i][j] = rand() % 31 - 10;  // Генерация чисел от -10 до 20
        }
    }

     // Поиск наибольшего элемента и суммы строки с этим элементом
    int maxElement = matrix[0][0];
    int sum = 0;
    int rowWithMax = 0;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (matrix[i][j] > maxElement) 
            {
                maxElement = matrix[i][j];
                rowWithMax = i;
            }
        }

        if (i == rowWithMax) 
        {
            for (int j = 0; j < m; ++j) 
            {
                sum += matrix[i][j];
            }
            break; // останавливаемся при первом найденном наибольшем элементе
        }
    }

    // Вывод матрицы
    std::cout << "Матрица:\n";
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    // Вывод значения наибольшего элемента и суммы строки с ним
    std::cout << "\nНаибольший элемент: " << maxElement << '\n';
    std::cout << "Сумма строки с наибольшим элементом: " << sum << " (строка " << rowWithMax + 1 << ")\n";

    return 0;
}
