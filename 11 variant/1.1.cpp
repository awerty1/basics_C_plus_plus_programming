/*
Задание 1. Написать программу пересчета расстояния из верст в километры 
(1 верста равняется 1066,8 м). Исходные данные вводятся с клавиатуры
*/
#include <iostream>

using namespace std;

int main()
{
    double miles;
    cout<<"Введите количество верст:";
    cin >> miles;
    
    double kilometers = (miles * 1066.8)/1000;
    cout<<"Введеное количество верст равно "<<kilometers<<" км"<<endl; 

    return 0;
}
