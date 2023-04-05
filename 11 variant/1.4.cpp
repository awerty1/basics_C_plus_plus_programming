/*
Задание 4. Дано действительное число A. Для функции F(X), график 
которой представлен на рисунке, вычислить F(A) и вывести на экран
< -1 |=> 1/x^2 
> 2 |=> 4 
>= -1 && <= 2 |=> x^2
*/
#include <iostream>

using namespace std;

int main()
{
    double number;
    cout<<"Введите действительное число A:";
    cin >> number;
    
    double y;
    if (number < -1)
        y = 1.0/(number*number);
    else if(number > 2)
        y = 4.0;
    else
        y = number*number*1.0;
    
    
    cout<<endl<<"y = "
        << y
        << endl; 

    return 0;
}
