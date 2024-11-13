/*
Задание 4. Сформировать два массива А и В – каждый из n (число n вводится 
с клавиатуры, его значение не больше 20) случайных целых чисел. Элементы 
массивов должны быть в диапазоне от -5 до 5. Вывести оба массива, сначала A, 
потом B. Программа должна сформировать массив C, в который необходимо 
поместить только те элементы массива B, которые больше соответствующего 
элемента в массиве А. Вывести массив С.
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int SIZE;
    cout<<"Введите размер массива:";
    cin>>SIZE;
    int arrayA[SIZE];
    int arrayB[SIZE];
    int arrayC[SIZE*10];
        
    if (SIZE <= 0 || SIZE > 20)
    {
        do
        {
          cout<<"\nРазмер массива <= 0 или > 20";
          cout<<"\nВведите размер массива:";
          cin >> SIZE;
          int arrayA[SIZE];
          int arrayB[SIZE];
          int arrayC[SIZE*100];
        }while(SIZE <= 0 || SIZE > 20);
    }
    
    srand(time(0));
    
    cout<< "Исходный массив A:\n";
    
    // Заполнение массива А случайными числами -5 до 5 и его вывод
     for(int i = 0; i < SIZE; i++) 
     {
         arrayA [i] = rand() % 11 - 5;
         cout << arrayA[i] << " "<< setw(2);
     }
     
     // Заполнение массива B случайными числами -5 до 5 и его вывод
     cout<< "\nИсходный массив B:\n";
     for(int i = 0; i < SIZE; i++) 
     {
         arrayB [i] = rand() % 11 - 5;
         cout << arrayB[i] << " "<< setw(2);
     }
     
     
     // Сравниваем элементы A с B
     int count = 0;
     for (int i = 0; i < SIZE; i++)
     {
         if (arrayB[i] > arrayA[i])
        {
            arrayC[count] = arrayB[i];
            count++;
        }
     }
    
	 
	 cout<< "\nМассив C после преобразований:\n";
     for(int i = 0; i < count; i++)
     {
         cout << arrayC[i] << " "<< setw(2);
     }
     
    return 0;
}