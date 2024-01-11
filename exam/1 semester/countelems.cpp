/*
	Посчитать количество неповторяющихся элементов в массиве
*/

#include <iostream>

using namespace std;

int main()
{
    size_t SIZE;
    cout<<"Введите размер массива:";
    cin>>SIZE;
    int arrayA[SIZE];
    if (SIZE <= 0 || SIZE > 20)
    {
        do
        {
          cout<<"\nРазмер массива <= 0 или > 20:"; 
          cout<<"\nВведите размер массива:";
          cin >> SIZE;  
        }
        while(SIZE <= 0 || SIZE > 20);
    }
    
    srand(time(0));
    
    
    
    for(int i = 0; i < SIZE; i++) 
    {
        arrayA [i] = rand() % 20 - 10;
    }
    
    cout<<"Массив до удаления:\n";
    for(int i = 0; i < SIZE; i++)
    {
        cout << arrayA[i] << " ";
    }
    
    
    //Сортировка массива C
    for(int i = 0; i < SIZE; i++)
    {
             for(int j = 0; j < SIZE-i-1; j++)
             {
                 if(arrayA[j] > arrayA[j+1])
                 {
                     int temp = arrayA[j];
                     arrayA[j] = arrayA[j+1];
                     arrayA[j+1] = temp;
                 }
             }
    }
    
    
    cout<<"\nМассив после сортировки:\n";       
    for(int i = 0; i < SIZE; i++)
    {
        cout << arrayA[i] << " ";
    } 
    
    
    //Удаление дублирующего элемента
    for (int i = 0; i < SIZE; i++)
    {
        if (arrayA[i] == arrayA[i+1])
        {
            for(int j = i; j < SIZE; j++)
            {
                arrayA[j] = arrayA[j+1];
            }
            SIZE--;
            i--;
        }
    }
    
    
    cout<<"\nМассив после удаления повторяющихся элементов:\n";       
    for(int i = 0; i < SIZE; i++)
    {
        cout << arrayA[i] << " ";
    }
    
    
    size_t count_elem = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if (arrayA[i] != arrayA[i+1])
        {
            count_elem++;
        }
    }
    
    cout << "\nВсего неповторяющихся элементов в массиве: " << count_elem << endl;
    
    
    return 0;
}
