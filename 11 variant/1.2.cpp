/*
Задание 2. Вводятся два целых трехзначных числа. Вывести сумму 
центральных цифр этих чисел. Например, для 657 и 412 сумма будет равна 6.
*/
#include <iostream>

using namespace std;

int main()
{
    int thdig_number1;
    int thdig_number2;
    cout<<"Введите первое трехзначное число:";
    cin >> thdig_number1;
     cout<<"Введите второе трехзначное число:";
    cin >> thdig_number2;
    
    int cent_number1 = thdig_number1 % 100 / 10;
    int cent_number2 = thdig_number2 % 100 / 10;
    int sum = cent_number1 + cent_number2;
    cout<<"Сумма центральных цифр числа "
        <<thdig_number1
        <<" и "
        <<thdig_number2
        <<" равна " << sum << endl; 

    return 0;
}