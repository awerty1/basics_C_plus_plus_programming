/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Переставить местами строки матрицы так, чтобы её последний столбец оказался 
упорядоченным по возрастанию. Вывести преобразованную таким образом 
матрицу.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() 
{
    srand(time(NULL));  // инициализация генератора случайных чисел

    int n, m;
    cout << "Введите количество строк n: ";
    cin >> n;
    cout << "Введите количество столбцов m: ";
    cin >> m;

    // выделение памяти под матрицу
    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new int[m];
    }

    // заполнение матрицы случайными числами в диапазоне от -50 до 50
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            matrix[i][j] = rand() % 101 - 50;
        }
    }

    // вывод исходной матрицы
    cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // сортировка последнего столбца матрицы по возрастанию
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (matrix[i][m-1] > matrix[j][m-1]) 
            {
                // обмен значений в строках i и j
                for (int k = 0; k < m; k++) 
                {
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[j][k];
                    matrix[j][k] = temp;
                }
            }
        }
    }

    // вывод преобразованной матрицы
    cout << "Преобразованная матрица:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << setw(3) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // освобождение памяти
    for (int i = 0; i < n; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}