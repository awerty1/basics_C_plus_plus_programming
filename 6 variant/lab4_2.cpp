/*
Задание 2. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от 1 до 15.
Подсчитать и вывести дополнительной строкой сумму каждого столбца. Найти
и вывести наименьший элемент этой строки.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    
    srand(time(0));
    
    int ROW; // количество строк
    int COL; // количество столбцов
    
    
    cout<<"Введите количество столбцов:";
    cin>>COL;
    cout<<"Введите количество строк:";
    cin>>ROW;
    
    
    
    int matrix[ROW][COL];
    
    // заполнение матрицы случайными числами и вывод матрицы
    for (size_t i = 0; i < ROW; i++)
    {
        for (size_t j = 0; j < COL; j++)
        {
            matrix[i][j] = rand() % 16; // генерация числа от 1 до 15
            cout << setw(2) <<matrix[i][j] << setw(2) << " ";
            
        }
        cout << endl;
    }
    
    
    // подсчет сумм столбцов
    int column_sum[COL] = {0};
    for (size_t j = 0; j < COL; j++)
    {
        for (size_t i = 0; i < ROW; i++)
        {
            column_sum[j] += matrix[i][j];
        }
    }
    
    // вывод сумм столбцов
    if (COL != 0)
    {
        cout << "Сумма каждого столбца:" << endl;
        for (size_t j = 0; j < COL; j++)
        {
            cout << setw(2) <<column_sum[j] << setw(2) << " ";
        }
        
        cout << endl;
        
        // нахождение наименьшего элемента
        int min_sum = column_sum[0];
        for (size_t j = 1; j < COL; j++)
        {
                if (column_sum[j] < min_sum)
                {
                    min_sum = column_sum[j];
                }
        }
        cout << "Наименьший элемент в строке с суммами столбцов: " << min_sum << endl;
    }
    else
    {
        cout << "Простите, в массиве 0 элементов" << endl;
    }

return 0;
}
