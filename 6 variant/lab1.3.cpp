/*
Задание 3. Даны три числа a, b и c. Удвоить эти числа, если a < b < c, и 
заменить их абсолютными значениями, если это не так.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b, c;
    cout<<"Введите число a:";
    cin>>a;
     cout<<"Введите число b:";
    cin>>b;
     cout<<"Введите число c:";
    cin>>c;
    
    if(a < b && b < c)
    {
        a=a*2;
        b=b*2;
        c=c*2;
    }
    else
    {
        a=abs(a);
        b=abs(b);
        c=abs(c);    
    }
    
    
    cout<<"Число А == "<<a;
    cout<<"\nЧисло B == "<<b;
    cout<<"\nЧисло C == "<<c;

    return 0;
}
