/*
Задание 4. Написать программу для вычисления суммы бесконечного 
сходящегося ряда. Суммирование прекратить при появлении в сумме слагаемых, 
имеющих абсолютную величину, меньшую заданной погрешности вычисления 
функции d. Другими словами, производить суммирование до тех пор, пока 
текущий член ряда больше погрешности. Значение d задается при помощи 
оператора ввода, при вводе проверить, что d < 1.  
𝑆 = (1/ (1*2))−(1/(3*4))+(1/(5*6))−(1/(7*8)) ...
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double d, S = 0.0, term;
    int n = 1;
    
    cout << "Введите значение погрешности (d < 1): ";
    cin >> d;
    
    while (true)
    {
        term = pow(-1, n+1) / ((2*n-1) * (2*n));
        if (abs(term) < d) break;
        
        S += term;
        n++;
    }
    
    cout << "Сумма ряда: " << S << endl;
    cout << "Количество слагаемых: " << n << endl;
    
    return 0;
}
