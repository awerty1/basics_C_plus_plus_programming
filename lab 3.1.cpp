/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -10 до 10 (число n вводится с клавиатуры, его значение не больше 20). Найти 
суммы положительных и отрицательных элементов. Сделать проверку на 
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
          cout<<"\nРазмер массива > 20 или <= 0"; 
          cout<<"\nВведите размер массива:";
          cin >> SIZE;  
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
     
     // сумма негативны и позитивных
     int sum_pos = 0;
     int sum_neg = 0;
     for(int i = 0; i < SIZE; i++) 
     {
         if (arrayA [i] < 0 )
         {
             sum_neg += arrayA [i];
         } 
         else
         {
             sum_pos += arrayA [i];
         }
     }
     
     cout << "\nSum neg == "<<sum_neg<< endl;
     cout << "\nSum pos == "<<sum_pos<< endl;
     
    return 0;
}