/*
Задание 4. Написать программу для вычисления суммы бесконечного 
сходящегося ряда. Суммирование прекратить при появлении в сумме слагаемых, 
имеющих абсолютную величину, меньшую заданной погрешности вычисления 
функции d. Другими словами, производить суммирование до тех пор, пока 
текущий член ряда больше погрешности. Значение d задается при помощи 
оператора ввода, при вводе проверить, что d < 1.

S = 1-1/2+1/2^2-1/2^3+...
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double number_d;
    cout << "Введите d = "; 
    cin>> number_d;
    if(number_d < 0.0 || number_d >= 1.0)
    {
        do
        {
            cout << "Введите d = "; 
            cin >> number_d;
        }while (number_d < 0.0 || number_d >= 1.0);
    }
    

    double sum = 0.0, memb = 1.0;
    while (fabs(memb) >= number_d)  // или >
    {
       sum += memb;
       memb /= -2.0;
       //debug verion
       //cout<< "sum while =" << sum << endl;
       //cout<< "memb =" << memb << endl;
    }

    
    cout << "sum = " << sum;
	
    return 0;
}
