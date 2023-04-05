/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -10 до 10 (число n вводится с клавиатуры, его значение не больше 20). Найти 
сумму и количество всех элементов с чётными номерами. Сделать проверку на 
корректность ввода n.
*/

#include <iostream>

using namespace std;

int main()
{
    int SIZE;
    cout<<"Введите размер массива:";
    cin>>SIZE;
    int arrayA[SIZE];
    if (SIZE <= 0 || SIZE > 20)
    {
        do
        {
          cout<<"\nРазмер массива > 20 или <=0"; 
          cout<<"\nВведите размер массива:";
          cin >> SIZE;
		  int arrayA[SIZE];
        }while(SIZE <= 0 || SIZE > 20);
    }
    
    srand(time(0));
    
    cout<< "Исходный массив:\n";
    
    // Заполнение массива случайными числами -10 до 10 и его вывод
     for(int i = 0; i < SIZE; i++) 
     {
         arrayA [i] = rand() % 21 - 10;
         cout << arrayA[i] << " ";
     }
     
     // сумма и количество всех элементов с четными ноерами
     int count_even = 0;
     int sum_even = 0;
     for(int i = 0; i < SIZE; i++) 
     {
         if (i % 2 == 0)
         {
             sum_even += arrayA[i];
             count_even++;
         }
     }
     
     cout << "\nСумма элементов с четными номерами: "<<sum_even<< endl;
     cout << "\nКоличество эелементов с четными номерами: "<<count_even<< endl;
     
    return 0;
}