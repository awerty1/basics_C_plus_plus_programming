/*
Даны действительные числа a1,...,1n, действительная матрица порядка n(n>=6).
Получисть действительную матрицу размера n*(n+1), вставив в исходную матрицу между пятым и шестым столбцами новый столбец с элементами a1,...an.
*/

#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

int main()
{

    srand(time(0));

    int n;
    double a[MAX_SIZE], matrix[MAX_SIZE][MAX_SIZE];
    //newColumn[MAX_SIZE];

    cout << "Введите размер квадратной матрицы n (n >= 6): ";
    cin >> n;

    // Ввод элементов матрицы и массива a
    cout << "Исходная матрица:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            //cin >> matrix[i][j];
            matrix[i][j] = rand() % 10; // генерация числа от 1 до 15
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Введите элементы массива a для вставки между 5 и 6 столбцом:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Построение новой матрицы
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            if(j < 5)
            {
                cout << matrix[i][j] << " ";
            }
            else if (j == 5)
            {
                cout << a[i] << " ";
            }
            else
            {
                cout << matrix[i][j-1] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}
