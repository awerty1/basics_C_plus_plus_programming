/*
Задание 1.Сформировать и вывести на экран квадратную матрицу из n строк 
и столбцов. Элементы матрицы – это нули и единицы, расположенные в 
шахматном порядке. Первая строка должна начинаться с единицы. Например, 
при n = 5 должна быть выведена такая матрица:
1 0 1 0 1
0 1 0 1 0
1 0 1 0 1
0 1 0 1 0
*/

// Переменные:
// int n | целый тип | Разер матрицы
// int matr[n][n] | целый тип | Срздание матриы размера n x n 
// int i | целый типа | Счетчик цикла
// int j | целый типа | Счетчик цикла

#include <iostream>

using namespace std;

int main() 
{
    int n; // Размер матрицы
    cout << "Введите размер матрицы: ";
    cin >> n;
    
    int matr[n][n]; // Объявление матрицы
    
    // Заполнение матрицы нулями и единицами в шахматном порядке
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            matr[i][j] = (i + j) % 2;
        }
    }
    
    // Вывод матрицы на экран
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << matr[i][j] << " ";
        }
        
        cout << endl;
    }

    return 0;
}