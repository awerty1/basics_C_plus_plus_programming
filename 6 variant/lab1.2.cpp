/*
Задание 2. Вводятся два целых трехзначных числа. Вывести разность 
центральных цифр этих чисел. Например, для 657 и 412 разность будет равна 4.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b;
    cout<<"Введите трехзнчное число a:";
    cin>>a;
    cout<<"Введите трехзнчное число b:";
    cin>>b;
    
    if (a < 100 || a >999 || b < 100 || b>999)
    {
        do
        {
              cout<<"\nВы ввели не трехзначное число a или b!";
              cout<<"\nВведите трехзнчное число a:";
              cin>>a;
              cout<<"\nВведите трехзнчное число b:";
              cin>>b;  
        }while(a < 100 || a >999 || b < 100 || b>999);
    }
    
    int dozenA;
    int dozenB;
    
    dozenA = a % 100 / 10;
    dozenB = b % 100 / 10;
    
    int diff = dozenA-dozenB;
    
    
    cout<<"Разность центральных цифр чисел a && b равна:"<<diff;


    return 0;
}
