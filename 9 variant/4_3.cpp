/*
Задание 3. Сформировать и вывести матрицу из n строк и m столбцов. 
Элементы матрицы должны быть случайными числами в диапазоне от -100 до 
100. Удалить k-столбец двумерного массива целых чисел (нумерация столбцов 
ведется со стороны пользователя, т.е. с единицы). Сделать проверку на 
корректность ввода k: 1 ≤ k ≤ m. Вывести преобразованную таким образом 
матрицу.
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
    int k = 0;
    
    srand(time(NULL));
    
    do
    {
        cin >> n;
        if(n <= 0)
            cout << "Число n должно быть больше 0:";
    } while(n <= 0);

    
    cout << "Введите число m больше 0:";
    
    do
    {
        cin >> m;
        if(m <= 0)
            cout << "Число m должно быть больше 0:";
    } while(m <= 0);

    
    int** array = new int*[n];
    for(int i = 0; i < n; i++)
    {
        array[i] = new int[m];
    }
        
        
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            array[i][j] = rand() % 200-100;
            cout << setw(5) << array[i][j];
        }
        cout << "\n";
    }
    
    cout << "Введите намер столбца, который нужно удалить: ";
    
    do
    {
        cin >> k;
        if(k <= 0 || k > m)
            cout << "Номер столбца должен быть от 1 до " << m << ":";
    } while(k <= 0 || k > m);
    
    k--; 
    for(int i = 0; i < n; i++)
    {
        for(int j = k; j < m; j++)
        {
            array[i][j] = array[i][j+1];
        }
    }
    
    m--;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << setw(5) <<array[i][j];
        }
        cout << "\n";
    }
    
    for(int i = 0; i < n; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    
    return 0;
}