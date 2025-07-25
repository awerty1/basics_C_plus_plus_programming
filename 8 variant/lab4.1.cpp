/*
Задание 1.Сформировать и вывести на экран квадратную матрицу из n строк 
и столбцов. Элементы матрицы формируются по такой закономерности: на 
главной и побочной диагоналях должны быть нули, а все остальные элементы –
единицы. Например, при n = 5 должна быть выведена такая матрица:
0 1 1 1 0
1 0 1 0 1
1 1 0 1 1
1 0 1 0 1
0 1 1 1 0
*/

#include <iostream>

using namespace std;

const int MAX_SIZE = 10;

int main()
{
    int n;
    int matrix[MAX_SIZE][MAX_SIZE];

    cout << "Введите размер квадратной матрицы: ";
    cin >> n;

    // заполнение матрицы
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || i + j == n - 1)
            {
                matrix[i][j] = 0;
            } 
            else 
            {
                matrix[i][j] = 1;
            }
        }
    }
    
    // вывод матрицы на экран
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
