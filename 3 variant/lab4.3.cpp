/*
Задание 3. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -10 до 10. 
Удалить столбец, в котором находится максимальный элемент матрицы.
Вывести преобразованную таким образом матрицу.
*/

// Переменные:
// int n | Целый тип | размер для строк в матрице
// int m | Целый тип | размер для столбцов в матрице
// int matrix[n][m] | Целый тип | Срздание матриы размера n x m 
// int i | Целый типа | Счетчик цикла
// int j | Целый типа | Счетчик цикла
// int max_element |Целый тип| Для поиска наибольшего эдемента
// int max_column |Целый тип| Для поиска индекса столбца с наибольшим элементом


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int n, m;
    cout << "Введите количество строк матрицы: ";
    cin >> n;
    cout << "Введите количество столбцов матрицы: ";
    cin >> m;
     
    int matrix[n][m];
    srand(time(0)); // инициализируем генератор случайных чисел
    
    // Заполнение матрицы случайными числами
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            matrix[i][j] = rand() % 21 - 10; // случайное число от -10 до 10
            cout << matrix[i][j] << "\t"; // вывод на экран
        }
        cout << endl;
    }

    // поиск максимального элемента и его позиции
    int max_element = matrix[0][0], max_column = 0;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) 
        {
            if (matrix[i][j] > max_element) 
            {
                max_element = matrix[i][j];
                max_column = j;
            }
        }
    }
    
    cout << endl << "Max el = " << max_element;
    cout << endl << "Max column = " << max_column+1 << endl;
    
    // Удаление столбца с максимальным элементом
    for (int i = 0; i < n; i++) 
    {
        for (int j = max_column; j < m-1; j++) 
        {
            matrix[i][j] = matrix[i][j+1];
        }
    }
    m--;
    
    // Вывод преобразованной матрицы
    cout << "Преобразованная матрица:" << endl;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}