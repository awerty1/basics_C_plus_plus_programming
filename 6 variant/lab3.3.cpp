/*
Задание 3. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Вставить число перед всеми единицами, 
если таковые имеются. Число для вставки вводится с клавиатуры. Вывести 
измененный массив на экран. Дополнительные массивы использовать нельзя –
меняем исходный массив с помощью сдвига элементов. Пример приведен в 
методичке. Сделать проверку на корректность ввода n.
*/
#include <iostream>

using namespace std;

int main()
{
    int SIZE;
    cout<<"Введите размер массива:";
    cin>>SIZE;
    int arrayA[SIZE*2];
    if (SIZE > 20 || SIZE <= 0)
    {
        do
        {
          cout<<"\nРазмер массива > 20 или <=0:"; 
          cout<<"\nВведите размер массива:";
          cin >> SIZE;  
        }while(SIZE > 20 || SIZE <= 0);
    }
    
    int insert_number;
    cout<<"Введите число для вставки:";
    cin>>insert_number;
    
    srand(time(0));
    
    cout<< "Исходный массив:\n";
    
    // Заполнение массива случайными числами -10 до 10 и его вывод
     for(int i = 0; i < SIZE; i++) 
     {
         arrayA [i] = rand() % 1 + 1;
         cout << arrayA[i] << " ";
     }
     
     // Вставка числа в массив
     for (int i = 0; i <SIZE; i++ )
     {
         if (arrayA[i] == 1)
         {
            for(int j = SIZE+1; j > i; j--) 
            {

                   arrayA[j] = arrayA[j-1];
            }
            arrayA[i++] = insert_number;
            //i++;
            SIZE++;
         }
     }
     cout<<endl;
	 
	 cout<< "Массив после вставки:\n";
     for(int i = 0; i < SIZE; i++) 
     {
         cout << arrayA[i] << " ";
     }
     
    return 0;
}