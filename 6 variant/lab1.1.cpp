/*
Задание 1. Написать программу вычисления объема шара. Исходные 
данные вводятся с клавиатуры.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int r;
    cout<<"Введите радиус r:";
    cin>>r;
    
    
    double V;
    if (r < 0)
    {
       cout<<"Такого шара не существует "; 
    }
    else
    {
        V = 4.0/3*M_PI*pow(r, 3);
        cout<<"Объем шара равен: "<<V;
    }

    return 0;
}
