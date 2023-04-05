/*
Задание 3. C клавиатуры вводится число n. Найти число из диапазона от 1 
до n с максимальной суммой делителей (в делители не включаются 1 и само 
число). Сделать проверку на корректность ввода n.
*/

#include <iostream>

using namespace std;

int main()
{
    
    int sum_el, max_ch, tmp;
    int ch;
    int n;
    sum_el = tmp = max_ch = 0;
    
    cout<<"Введите число N:";
    cin>>n;
    
     if (n <= 0 || n>10000)
    {
        do
        {
          cout<<"Число N<0 или N>10000";
          cout << "\nВведите число N: "; 
          cin >> n;  
        }while(n <= 0 || n>10000);
    }
    
    for(int i = 1; i < n; i++)
    {
        ch = i;
		//цикл с 2х, т.к. не нужно проверять на 1 и можно избавиться от ch != 1
        //чтобы избавиться от проверки ch != j в условии можно сделать j < i в for
        for(int j = 2; j < n; j++)
	    {
            //if(ch % j == 0 && ch != 1 && ch != j)
    	    //debug ver
    	    //cout<<"nubmer : "<<ch<<endl;
            if(ch % j == 0 && ch != j)
	        {
                sum_el+=j;
        		// debug ver
        		//cout<<del<<" ";
	        }
	       // else
	       // {
	       //     continue;
	       // }
        }

        if(sum_el > tmp)
	    {
            tmp = sum_el;
            max_ch = ch;
            //debug ver
	        //cout<<" new max sum ="<<tmp ;
        }
        sum_el = 0;
    }
    
    /*
    4 testing:
    testcase1: У числа 8 делители - 1, 2, 4, 8. Их сумма - 15
    testcase2: У числа 9 делители - 1, 3, 9. Их сумма - 13.
    testcase3: N == 0 
    testcase4: N == 1
    testcase5: N == -1
    testcase6: N > 10000
    */
 
    cout << "Maximum number of divisors " << max_ch<<endl;
    cout << "Sum of del " << tmp<<endl;
    
    return 0;
}