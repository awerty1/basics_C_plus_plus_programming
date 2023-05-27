/*
Задание 2. Написать программу вывода всех трехзначных десятичных 
чисел, сумма цифр которых равна данному числу n, вводимому с клавиатуры. 
Сделать проверку на корректность ввода n. 
*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    int hundreds;
    int dozens;
    int units;
    
    cout << "Введите число N: "; 
    cin >> n;
    
    if (n <= 0 || n >27)
    {
        do
        {
          cout<<"\nТрехзначаное число не может быть найдено, n<0 || n >27";
          cout << "\nВведите число N: "; 
          cin >> n;  
        }while(n <= 0 || n >27);
    }
    
    if (n > 0 || n <=27)
    {
        for(int i = 100; i <= 999; i++)
        {
            hundreds = i / 100;
            dozens = i % 100 / 10;
            units = i % 100 % 10;
            
            int sumofnumbers = hundreds + dozens + units;
            if (n == sumofnumbers)
            {
                cout<< "Трехзначаное число =" 
    				<< i
    				<< endl; 
            }
    //debug version
    // 		else
    // 		{
    // 			cout<< "Число не трехзначное" 
    // 				<< i
    // 				<< endl; 
    // 		}
            
            }  
    }
   
    
    return 0;
}
