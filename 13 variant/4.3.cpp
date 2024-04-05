/*
Задание 3. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -10 до 10. 
Вставить столбец нулей перед строкой, в которой находится минимальный 
элемент матрицы. Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int main() 
{
	std::size_t n, m;
	std::cout << "Введите количество строк: ";
	std::cin >> n;
	std::cout << "Введите количество столбцов: ";
	std::cin >> m;

	// Генератор случайных чисел для элементов матрицы
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(-10, 10);

	// Создание и заполнение матрицы случайными числами
	std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
	for (std::size_t i = 0; i < n; ++i) 
	{
		for (std::size_t j = 0; j < m; ++j) 
		{
			matrix[i][j] = dis(gen);
		}
	}

	// Поиск минимального элемента в матрице
	int minElement = matrix[0][0];
	size_t minRowIndex = 0;
	for (size_t i = 0; i < n; ++i) 
	{
		for (size_t j = 0; j < m; ++j) 
		{
			if (matrix[i][j] < minElement) 
			{
				minElement = matrix[i][j];
				minRowIndex = i;
			}
		}
	}

	// Вставка столбца нулей перед строкой с минимальным элементом
	matrix.insert(matrix.begin() + minRowIndex, std::vector<int>(m, 0)); 

	// Вывод преобразованной матрицы
	std::cout << "Преобразованная матрица:\n";
	for (const auto& row : matrix) 
	{
		for (int el : row) 
		{
			std::cout << el << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}