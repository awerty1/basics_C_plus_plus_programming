/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Отсортировать все столбцы с четными номерами по убыванию (нумерация строк 
ведется со стороны пользователя, т.е. с единицы). Вывести преобразованную 
таким образом матрицу.
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
    /*
    cout << "Введите количество строк: ";
    cin >> ROW;
    cout << "Введите количество столбцов: ";
    cin >> COL;
    */
    
    do {
        cout << "Введите количество строк: ";
        if (cin >> ROW && ROW > 0) 
        {
            break; // выходим из цикла, если ввод корректен
        } 
        else 
        {
            cout << "Неверный ввод. Попробуйте еще раз." << endl;
            cin.clear(); // сбрасываем флаг ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем буфер ввода
        }
    } 
    while (true);
        
    do 
    {
        cout << "Введите количество столбцов: ";
        if (cin >> COL && COL > 0) 
        {
            break; // выходим из цикла, если ввод корректен
        } 
        else 
        {
            cout << "Неверный ввод. Попробуйте еще раз." << endl;
            cin.clear(); // сбрасываем флаг ошибки ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищаем буфер ввода
        }
    } while (true);

    // создаем двумерный массив и заполняем его случайными числами
     // выводим исходную матрицу на экран
    int matrix[ROW][COL];
    cout << "Исходная матрица:" << endl;
    for (size_t i = 0; i < ROW; ++i) 
    {
        for (size_t j = 0; j < COL; ++j) 
        {
            matrix[i][j] = rand() % 101 - 50;
            cout << setw(3) << matrix[i][j] << setw(3) << " ";
        }
        
        cout<< endl;
    }
    
    // вывод информации по матрице
    cout << endl << "Матрица размером " << ROW << " x " << COL << endl;
    cout << "Будут отсортированы столбцы(по убыванию): ";
    for (size_t i = 0; i < COL ; ++i)
    {
        if(i % 2)
        {
            cout << i+1;
            
            if (i != COL-1)
            {
               cout << ","; 
            }
        }
    }
    
    // сортировка обменом(bable sort)
    // сортируем четные столбцы
    for (size_t j = 1; j < COL; j += 2) 
    {
        for (size_t i = 0; i < ROW; i++) 
        {
            for (size_t k = i + 1; k < ROW; k++) 
            {
                if (matrix[i][j] < matrix[k][j]) 
                {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = temp;
                }
            }
        }
    }
    
    
    // выводим преобразованную матрицу на экран
    cout << endl << "\nПреобразованная матрица:" << endl;
    for (size_t i = 0; i < ROW; ++i) 
    {
        for (size_t j = 0; j < COL; ++j) 
        {
            cout << setw(3) << matrix[i][j] << setw(3) << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
