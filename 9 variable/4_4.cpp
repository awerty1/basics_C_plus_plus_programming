/*
Задание 4. Сформировать и вывести матрицу из n строк и m столбцов.
Элементы матрицы должны быть случайными числами в диапазоне от -50 до 50. 
Переставить местами столбцы матрицы так, чтобы её вторая строка (нумерация 
строк ведется со стороны пользователя, т.е. с единицы) оказалась упорядоченной 
по убыванию. Вывести преобразованную таким образом матрицу.
*/

#include <iostream>
#include <ostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число n больше 0";
    int n = 0, m = 0;
    srand(time(NULL));
    do
    {
        cin >> n;
        if(n<=0)
            cout << "Число n должно быть больше 0";
    }while(n<=0);
    n--;
    cout << "Введите число m больше 0";
    do
    {
        cin >> m;
        if(m<=0)
            cout << "Число m должно быть больше 0";
    }while(m<=0);
    m--;
    
    int** array = new int*[m];
    int* array2 = new int[n];
    int* array3 = new int[n];
    for(int i = 0; i<=m;i++)
        array[i]=new int[n];
        
    for(int i = 0; i<=m;i++)
    {
        for(int j = 0; j<=n;j++)
        {
            array[i][j] = rand() % 100-50;
            cout << array[i][j] << "\t";
            if(i == 1)
            {
                array2[j] = array[i][j];
                array3[j] = array[i][j];
            }
        }
        cout << "\n";
    }
    int numb = 0;
    for(int i = 0; i<=n;i++)
    {
        for(int j = 0; j<=i;j++)
        {
            if(array2[i]>array2[j])
            {
                numb = array2[i];
                array2[i] = array2[j];
                array2[j] = numb;
            }
        }
    }
    for(int i = 0; i<=n; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            if(array2[i]==array3[j])
            {
                array2[i] = j;
                array3[j] = -1000;
            }
        }
    }
    cout << "\n";
    for(int i = 0; i<=m; i++)
    {
        for(int j = 0; j<=n; j++)
        {
            cout << array[i][array2[j]] << "\t";
        }
        cout << "\n";
    }
}