/*
Задание 1. Составить программу, проверяющую, является ли 
последовательность из десяти целых чисел, вводимых с клавиатуры, 
убывающей. 
*/
#include <iostream>

using namespace std;

int main()
{
    int N=10;
    int number;
    int temp;
    int error=0;
    
    cout<<"Нужно ввести последовательно 10 чисел."<<endl;
    cout<<"Программа проверит являются ли они убывающей последовательностью."<<endl;
    for (int i=1; i<=N; i++)
    {
        cout << "Введите " << i <<" число: ";
        cin >> number;
        if (i==1)
        {
            temp=number;
        }
        else
        {
            if (number < temp)
            {
                temp = number;
            }
            else
            {
                temp = number;
                error++;
                break;
            }
        }
    }
    
    if(error >= 1)
    {
        cout << "Не убывающая последовательность, " << error << " error" << endl; 
    }
    else
    {
        cout << "Убывающая последовательность = " << error << " error" << endl;
    }
    
    return 0;
}
