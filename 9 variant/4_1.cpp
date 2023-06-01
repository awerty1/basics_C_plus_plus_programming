/*
Задание 1.Сформировать и вывести на экран квадратную матрицу из n строк 
и столбцов. Элементы матрицы формируются по такой закономерности: на
главной диагонали должны быть последовательные натуральные числа, начиная 
с единицы, а все остальные элементы – нули. Например, при n = 4 должна быть 
выведена такая матрица:
1 0 0 0 
0 2 0 0 
0 0 3 0 
0 0 0 4 
*/

#include <iostream>
#include <ostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число n больше 0:";
    int n = 0; 
    int m = 0;
    do
	{
        cin >> n;
        if (n <= 0)
            cout << "Число n должно быть больше 0:";
    } 
	while (n <= 0);
    
    int** array = new int*[n];
    for(int i = 0; i < n; i++)
    {
        array[i] = new int[n];
        
        for(int j = 0; j < n; j++)
        {
            if(i == j)
            {
                array[i][j] = i+1;
            }
            else
            {
                array[i][j] = 0;
            }
            cout << setw(4) << array[i][j]; // выравнивание по 4 символа
        }
        cout << "\n";
    }
	
	for(int i = 0; i < n; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}