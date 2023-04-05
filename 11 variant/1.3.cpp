/*
Задание 3. Даны три числа a, b и c. Утроить эти числа, если a > b > c, и 
заменить их знаки на противоположные, если это не так.
*/
#include <iostream>

using namespace std;

int main()
{
    int number1;
    int number2;
    int number3;
    cout<<"Введите число а:";
    cin >> number1;
    cout<<"Введите число b:";
    cin >> number2;
    cout<<"Введите число c:";
    cin >> number3;
    
    if (number1 > number2 && number2 > number3)
    {
        number1 = number1*3;
        number2 = number2*3;
        number3 = number3*3;
    }
    else
    {
        number1 = -number1;
        number2 = -number2;
        number3 = -number3;
    }
    
    cout<<endl<<"Числа a,b,c после условия: "
        <<"\na = "
        << number1
        <<"\nb = "
        << number2
        <<"\nc = "
        << number3
        << endl; 

    return 0;
}