/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от 1 до 10. 
Подсчитать и вывести дополнительной строкой среднее арифметическое 
каждого столбца. Найти и вывести наибольший элемент этой строки.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");
	int n, m;
	cout << "Введите количество строк и столбцов матрицы: \n";
	cin >> n;
	cin >> m;

	int a[30][30];

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			a[i][j] = rand() % 10 + 1;
			cout << a[i][j]<< " ";
		}
		cout << endl;
	}
	cout <<"Среднее арифметическое столбов: \n";
	double sum[30] = { 0 };
	for (int j = 0; j < m; j++) 
	{
		for (int i = 0; i < n; i++) 
		{
			sum[j] += a[i][j];
		}
		sum[j] /= n;
		printf_s("%5.2f",sum[j]);
		//cout << sum[j]<<"  ";
	}
	double max_sum = sum[0];
	for (int j = 0; j < m; j++) 
	{
		if (sum[j] > max_sum) 
		{
			max_sum = sum[j];
		}
	}
	cout << "\n Наибольший элемент из средних арифметических: " << max_sum << endl;
}
