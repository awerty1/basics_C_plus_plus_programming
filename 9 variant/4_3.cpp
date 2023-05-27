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
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число n больше 0";
    int n = 0, m = 0, k = 0;
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
    for(int i = 0; i<=m;i++)
        array[i]=new int[n];
        
    for(int i = 0; i<=m;i++)
    {
        for(int j = 0; j<=n;j++)
        {
            array[i][j] = rand() % 200-100;
            cout << array[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "Введите намер столбца, который нужно удалить ";
    do
    {
        cin >> k;
        if(k <= 0 || k > n + 1)
            cout << "Число k должно быть больше 0 и меньше " << n + 2;
    }while(k <= 0 || k > n + 1);
    k--; n--;
    for(int i = 0; i<=m;i++)
    {
        for(int j = k; j<=n;j++)
        {
            array[i][j] = array[i][j+1];
        }
    }
    for(int i = 0; i<=m;i++)
    {
        for(int j = 0; j<=n;j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << "\n";
    }
}
