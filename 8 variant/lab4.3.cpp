/*
Задание 3. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -10 до 10. 
Вставить столбец нулей после столбца, в котором находится минимальный
элемент матрицы. Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() 
{
    // Инициализация генератора случайных чисел
    srand(time(NULL));

    int n, m;
    cout << "Введите количество строк: ";
    cin >> n ;
    cout << "Введите количество столбцов: ";
    cin >> m;

    // Выделение памяти под матрицу
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++) 
    {
        matrix[i] = new int[m];
    }

    // Заполнение матрицы случайными числами в диапазоне от -10 до 10
    cout << "Исходная матрица:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            matrix[i][j] = rand() % 21 - 10;
            cout << setw(4) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Поиск минимального элемента и его столбца
    int min_element = matrix[0][0];
    int min_j = 0;
    for (int j = 0; j < m; j++) 
    {
        for (int i = 0; i < n; i++) 
        {
            if (matrix[i][j] < min_element) 
            {
                min_element = matrix[i][j];
                min_j = j;
            }
        }
    }
    
    cout << "Минимальный элемент равен: " << min_element << endl;
    cout << "Его позиция равна: " << min_j << endl;

    // Добавление столбца нулей после столбца с минимальным элементом
    m++;
    for (int i = 0; i < n; i++) 
    {
        for (int j = m - 1; j > min_j + 1; j--) 
        {
            matrix[i][j] = matrix[i][j - 1];
        }
        matrix[i][min_j + 1] = 0;
    }

    // Вывод преобразованной матрицы
    cout << "Матрица с добавленным столбом нулей:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++) 
    {
        delete [] matrix[i];
    }
    delete [] matrix;

    return 0;
}