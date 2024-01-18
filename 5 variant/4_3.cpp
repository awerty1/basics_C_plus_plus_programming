/*
Задание 3. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Поменять местами элементы главной и побочной диагоналей матрицы по 
строкам. Вывести преобразованную таким образом матрицу
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

int main() 
{
	int n, m;
	std::cout << "Введите количество строк: ";
	std::cin >> n;
	std::cout << "Введите количество столбцов: ";
	std::cin >> m;
	
	do 
	{
		std::cout << "Введите количество строк: ";
		std::cin >> n;
		std::cout << "Введите количество столбцов: ";
		std::cin >> m;
	} 
	while (n < 0 || m < 0);


	// Создание и заполнение матрицы случайными числами
	int** matrix = new int*[n];
	srand(time(0));
	for (int i = 0; i < n; i++) 
	{
		matrix[i] = new int[m]
		for (int j = 0; j < m; j++) 
		{
			matrix[i][j] = rand() % 101 - 50;
		}
	}

	// Вывод исходной матрицы
	std::cout << "Исходная матрица:\n";
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << "\n";
	}

	// Обмен элементов главной и побочной диагоналей
	for (int i = 0; i < n; i++) 
	{
		int temp = matrix[i][i];
		matrix[i][i] = matrix[i][m-i-1];
		matrix[i][m-i-1] = temp;
	}

	// Вывод преобразованной матрицы
	std::cout << "Преобразованная матрица:\n";
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << "\n";
	}
	
	for (int i = 0; i < n; i++) 
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	
	return 0;
}