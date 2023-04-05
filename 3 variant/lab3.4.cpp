/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Определить, есть ли в массиве все числа 
из диапазона [2..5]
*/

#include <iostream>

using namespace std;

int main()
{
    int SIZE;
    cout<<"Введите размер массива N:";
    cin>>SIZE;
    int arrayA[SIZE];
    int arrayB[] = {2,3,4,5};
    
    srand(time(0));
     
    cout<< "Исходный массив:\n";
    
    for(int i = 0; i < SIZE; i++) 
    {
         arrayA [i] = rand() % 21 - 10;
         cout << arrayA[i] << " ";
    }
    
    //Проверяем массив на элементы и выставляем флаги
    bool elem_2 = false;
    bool elem_3 = false;
    bool elem_4 = false;
    bool elem_5 = false;
    
    for(int i=0; i < SIZE; i++)
    {
        if (arrayA[i] == arrayB[0])
            elem_2 = true;
        else if (arrayA[i] == arrayB[1])
            elem_3 = true;
        else if (arrayA[i] == arrayB[2])
            elem_4 = true;
        else if (arrayA[i] == arrayB[3])
            elem_5 = true;
    }
    
    
    if (elem_2 && elem_3 && elem_4 && elem_5)
    {
        cout << "\nЭлементы присутствуют"
             <<"\nelement 2: "<<elem_2
             <<"\nelement 3: "<<elem_3
             <<"\nelement 4: "<<elem_4
             <<"\nelement 5: "<<elem_5;
    }
    else
    {
        cout << "\nНе все элементы присутствуют"
             <<"\nelement 2: "<<elem_2
             <<"\nelement 3: "<<elem_3
             <<"\nelement 4: "<<elem_4
             <<"\nelement 5: "<<elem_5;
    }
        
     
    //  cout<< "\nМассив после преобразований:\n";
    //  for(int i = 0; i < SIZE; i++)
    //  {
    //     cout << arrayA[i] << " ";
    //  }
     
     
    return 0;
}