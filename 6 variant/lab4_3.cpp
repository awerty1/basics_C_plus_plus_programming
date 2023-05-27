/*
Задание 3. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -10 до 10. 
Вставить строку нулей после строки, в которой находится максимальный 
элемент матрицы. Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <iomanip>
#include <limits>
//#include <cstdlib> // для функции rand

using namespace std;

int main() 
{
    srand(time(0));
    
    int ROW; // n 
    int COL; // m
    // cout << "Введите количество строк: ";
    // cin >> ROW;
    // cout << "Введите количество столбцов: ";
    // cin >> COL;
    
    // создаем двумерный массив
    
    
    // запрашиваем количество строк и столбцов еще раз
    do
    {
        cout << "Введите количество строк: ";
        cin >> ROW;
        
        cout << "Введите количество столбцов: ";
        cin >> COL;
        
        
        
        if (cin.fail() || ROW <= 0 || COL <= 0) 
        {
            cout << endl 
                << "Ошибочный ввод!\
                \nКоличество строк и столбцов не может быть нулевым,\
				символом или спецсимволом!\n" 
                << endl;
        }
        cin.clear(); // очищаем флаги ошибок ввода
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // игнорируем символы до конца строки
    } while (cin.fail() || ROW <= 0 || COL <= 0);
    
    int matrix[ROW][COL];
    

    // заполняем массив случайными числами
    // выводим исходную матрицу на экран
    cout << "Исходная матрица:" << endl;
    for (size_t i = 0; i < ROW; ++i) 
    {
        for (size_t j = 0; j < COL; ++j) 
        {
            matrix[i][j] = rand() % 101 - 50;
            cout << setw(3) << matrix[i][j] << setw(3) << " ";
        }
        cout << endl;
    }
    
    // находим максимальный элемент и его позицию в матрице
    int max_elem = matrix[0][0];
    size_t max_row = 0;
    for (size_t i = 0; i < ROW; ++i) 
    {
        for (size_t j = 0; j < COL; ++j) 
        {
            if (matrix[i][j] > max_elem) 
            {
                max_elem = matrix[i][j];
                max_row = i;
            }
        }
    }
    
    

    cout <<"\nMax elem: " << max_elem << endl;
    cout << "Max row: " << max_row+1 << endl;
    
    // вставляем строку нулей после строки с максимальным элементом
    for (size_t i = ROW - 1; i > max_row; --i) 
    {
        for (size_t j = 0; j < COL; ++j) 
        {
            matrix[i+1][j] = matrix[i][j];
        }
    }
    // увеличиваем, т.к. вставляем строку
    ROW++;
       
    for (size_t j = 0; j < COL; ++j) 
    {
        matrix[max_row + 1][j] = 0;
    }
    
    
    
    // выводим преобразованную матрицу на экран
    cout << "\nПреобразованная матрица:" << endl;
    for (size_t i = 0; i < ROW; ++i) 
    {
        for (size_t j = 0; j < COL; ++j) 
        {
            //cout << matrix[i][j] << " ";
            cout << setw(3) << matrix[i][j] << setw(3) << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}
