/*
Задание 1.Сформировать и вывести на экран квадратную матрицу из n строк 
и столбцов. Элементы матрицы формируются по такой закономерности: на 
главной и побочной диагоналях должны быть нули, а все остальные элементы –
случайные числа в диапазоне от 1 до 9. Например, при n = 5 может быть выведена 
такая матрица (внутри случайные числа):
0 4 7 2 0
2 0 3 0 9
7 5 0 8 6
3 0 8 0 1
0 7 3 5 0
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
            matrix[i][j] = rand() % 10; // генерация числа от 1 до 9
            cout << setw(2) <<matrix[i][j] << setw(2) << " ";
            
        }
        cout << endl;
    }
    
    for (size_t i = 0; i < ROW; i++)
    {
        for (size_t j = 0; j < COL; j++)
        {
            if (i == j)
            {
                matrix[i][j] = 0;
                matrix[i][COL - j - 1] = 0;
            }
        }
        cout << endl;
    }
    
    if (COL == 0 && ROW == 0)
        cout << "Сегодня без матрицы ^^" << endl;
    else
    {
        cout << "Матрица после преобразования:" << endl;
        for (size_t i = 0; i < ROW; i++)
        {
            for (size_t j = 0; j < COL; j++)
            {
                cout << setw(2) <<matrix[i][j] << setw(2) << " ";
                
            }
            
            cout << endl;
        }
        
    }
    
    
    return 0;
}
