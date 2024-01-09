/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от 1 до 10. 
Найти и вывести значение наименьшего элемента матрицы и сумму строки, в 
которой есть этот наименьший элемент (строк может быть несколько –
необходимо выбрать первую из них).  С++
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() 
{
    int n, m;
    std::cout << "Введите количество строк (n): ";
    std::cin >> n;
    std::cout << "Введите количество столбцов (m): ";
    std::cin >> m;

    // Создание и заполнение матрицы случайными числами
    int** matrix = new int*[n];
    srand(time(0));
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++) 
        {
            matrix[i][j] = rand() % 10 + 1;
        }
    }
    
    // Вывод матрицы
    std::cout << "Матрица:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    // Поиск наименьшего элемента и суммы строки
    int minElement = matrix[0][0];
    int minRowSum = 0;
    int minRowIndex = 0;
    for (int i = 0; i < n; i++) 
    {
        int rowSum = 0;
        for (int j = 0; j < m; j++) 
        {
            if (matrix[i][j] < minElement) 
            {
                minElement = matrix[i][j];
                minRowIndex = i;
            }
            rowSum += matrix[i][j];
        }
        if (i == minRowIndex) 
        {
            minRowSum = rowSum;
        }
    }
    
    // Вывод наименьшего элемента и суммы строки
    std::cout << "Наименьший элемент матрицы: " << minElement << "\n";
    std::cout << "Сумма строки с наименьшим элементом: " << minRowSum << "\n";
    
    for (int i = 0; i < n; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}
