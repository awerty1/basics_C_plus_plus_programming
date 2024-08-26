/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -50 до 50 (число n вводится с клавиатуры, его значение не больше 20). Найти 
количество отрицательных элементов и определить максимальный среди них. 
Сделать проверку на корректность ввода n.
*/

#include <iostream>
#include <iomanip>
#include <cmath>


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
          cout<<"\nРазмер массива <= 0 или > 20";
          cout<<"\nВведите размер массива:";
          cin >> SIZE;
          int arrayA[SIZE];
        }while(SIZE <= 0 || SIZE > 20);
    }
    
    srand(time(0));
    
    cout<< "Исходный массив A:\n";
    
    // Заполнение массива А случайными числами -50 до 50 и его вывод
     for(int i = 0; i < SIZE; i++) 
     {
         arrayA [i] = rand() % 101 - 50;
         cout << arrayA[i] << " "<< setw(2);
     }
     
     int count_neg = 0;
     int max_neg = arrayA[0];
     for(int i = 0; i < SIZE; i++) 
     {
         if (arrayA[i] < 0)
         {
             count_neg++;
             if (abs(max_neg) > abs(arrayA[i]))
                max_neg = arrayA[i];
         }
     }
     
    //удаление положительных элементов
//     for (int i = 0; i < SIZE; i++)
//     {
//         if (arrayA[i] > 0)
//         {
//             for(int j = i; j < SIZE-1; j++)
//             {
//                 arrayA[j] = arrayA[j+1];
//             }
//             SIZE--;
//             i--;
//         }
//     }
    
//     //поиск максимального среди негативных
//     int max_neg = arrayA[0];
// 	for(int i = 0; i < SIZE; i++) 
//      {
//          if (max_neg < arrayA[i])
//             max_neg = arrayA[i];
//      }
     
	 cout<<"\nМаксимальный элемент среди отрицательных чисел: "<<max_neg;
	 cout<<"\nКоличество негативных элементов: "<<count_neg;
     
    return 0;
}