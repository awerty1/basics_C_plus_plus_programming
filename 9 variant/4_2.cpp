/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от 1 до 10. 
Подсчитать и вывести сумму каждой четной строки. Найти и вывести 
наименьшую среди них сумму.
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
    int sum = 0; 
    int min = 0;
    
    srand(time(NULL));
    
    do
    {
        cin >> n;
        if(n <= 0)
            cout << "Число n должно быть больше 0:";
    }
    while(n <= 0);
    
    cout << "Введите число m больше 0:";
    do
    {
        cin >> m;
        if(m <= 0)
            cout << "Число m должно быть больше 0:";
    }
    while(m <= 0);
    
    int** array = new int*[n];
    for(int i = 0; i < n; i++)
    {
        array[i]=new int[m];
    }
        
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            array[i][j] = rand() % 10+1;
            cout << setw(4) << array[i][j];
            sum += array[i][j];
        }
        
        if(i == 1)
        {
            min = sum;
        }
        
        if(i % 2 != 0)
        {
            if(sum < min && min != 0)
            {
                min = sum;
            }
            cout << " Сумма элементов = " << sum << "\n";
        }
        else
        {
            cout << "\n";
        }
        sum = 0;
    }
    cout << "Наименьшая сумма элементов четных строк = " << min << "\n";
	
	for(int i = 0; i < n ; i++)
	{
		delete[] array[i];
	}
    delete[] array;
	
	return 0;
}