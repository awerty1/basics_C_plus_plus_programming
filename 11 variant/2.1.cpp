/*
Задание 1. Вывести все чётные числа начиная с числа M и до числа N. Числа 
M и N задает пользователь. Сделать проверку на корректность ввода M, N.
*/

#include <iostream>

using namespace std;

int main()
{
    double number_m;
    double number_n;
    cout<<"Введите число M:";
    cin >> number_m;
    cout<<"Введите число N:";
    cin >> number_n;
    
    if (number_m <= 0 || number_n <= 0)
    {
        cout<<"Числа M или N меньше нуля или равны нулю";
        cout<<"\nНужно ввести положительные числа";
    }
    else
    {
        for(int i = number_m; i <= number_n; i++)
        {
        if (i % 2 == 0)
            cout<<"Четное число: "
                <<i
                <<endl;
        }
    }
    
    return 0;
}
