/*
Задание 1.Сформировать и вывести на экран квадратную матрицу из n строк 
и столбцов. Элементы матрицы формируются по такой закономерности: на 
главной и побочной диагоналях должны быть единицы, а все остальные 
элементы – нули. Например, при n = 5 должна быть выведена такая матрица:
1 0 0 0 1
0 1 0 1 0
0 0 1 0 0
0 1 0 1 0
1 0 0 0 1
*/

#include <iostream>

using namespace std;

int main() 
{
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;
    
    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) 
    {
		matrix[i] = new int[n];
		
        for (int j = 0; j < n; j++) 
        {
            if (i == j || i + j == n - 1) 
            {
                matrix[i][j] = 1; // заполняем главную и побочную диагонали
            } 
            else 
            {
                matrix[i][j] = 0; // заполняем все остальные элементы нулями
            }
        
            cout << matrix[i][j] << " ";
        }
        
		cout << endl; // переход на новую строку после каждой строки матрицы
    }
	
	for (int i = 0; i < n; i++) 
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}