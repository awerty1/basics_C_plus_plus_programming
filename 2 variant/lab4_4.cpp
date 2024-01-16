/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Переставить местами столбцы матрицы так, чтобы её первая строка оказалась 
упорядоченной по возрастанию. Вывести преобразованную таким образом 
матрицу.
*/

#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int m, n, a[30][30];
	cout << "Введите количество строк и столбцов \n";
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = rand() % 100 - 50;
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	
	for (int i = 0; i < m-1; i++)
	{
		for (int j = 0; j < m-i-1; j++)
		{
			if (a[0][j] > a[0][j + 1])
			{
				for (int p = 0; p < n; p++)
				{
					int t = a[p][j];
					a[p][j] = a[p][j + 1];
					a[p][j + 1] = t;
				}
			}
		}
	}

	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}
