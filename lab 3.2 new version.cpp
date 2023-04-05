/*
Задание 2. Задан массив из n целых чисел, которые нужно ввести с 
клавиатуры (число n также вводится с клавиатуры, его значение не больше 20). 
Определить, есть ли в массиве элемент, значение которого больше суммы всех 
остальных элементов. Если есть – вывести это значение (это может быть только 
одно значение). Сделать проверку на корректность ввода n.
*/
#include <iostream>

using namespace std;

int main()
{
    int SIZE;
    cout<<"Введите размер массива:";
    cin>>SIZE;
    int arrayA[SIZE];
    if (SIZE > 20 || SIZE <= 0)
    {
        do
        {
          cout<<"\nРазмер массива > 20 или <=0:"; 
          cout<<"\nВведите размер массива:";
          cin >> SIZE;  
        }while(SIZE > 20 || SIZE <= 0);
    }
    
    
    cout<< "Исходный массив:\n";
    
    // Заполнение массива в ручную и подсчет суммы
     int biggest_el = 0;
     bool flag = false;
     int sum_el = 0;
     for(int i = 0; i < SIZE; i++) 
     {
        cout<<"Введите элемент arrayA["
			<<i+1<<"]:";
        cin >> arrayA [i];
        sum_el += arrayA [i];
     }
     
     cout<< "Исходный массив:\n";
     
     biggest_el = arrayA[0];
     for(int i = 0; i < SIZE; i++)
     {
        cout << arrayA[i] << " ";
        if (arrayA[i] > biggest_el)
        {
            biggest_el = arrayA[i];
            
        }
     }
     
    int sum_without_biggest_el =sum_el - biggest_el;
    if (biggest_el > sum_without_biggest_el)
    {
		cout << "\nThe biggest element == " <<biggest_el << endl;
        cout << "Sum of elements without biggest == " << sum_without_biggest_el << endl;
        
    }
    else
    {
        cout << "\nThe biggest element absent, sry ); " <<endl;
    }
	
    return 0;
}