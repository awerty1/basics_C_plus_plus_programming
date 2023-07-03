/*
Задание 4. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Поменять местами первую и вторую 
половины массива – т.е. первый элемент поменять местами с первым элементом 
из второй половины, второй – со вторым и т.д. Если в массиве нечётное 
количество элементов, то средний элемент оставить на своём месте. Вывести 
преобразованный таким образом массив.
*/

#include <iostream>

using namespace std;

const int N = 20;

int main()
{
	setlocale(LC_ALL,"Russian");
    int a[N], n;
	cout<<"Введите n \n";
	cin>>n;
	for (int i=0;i<n;i++)
	{
		a[i]=rand()%100+1;
		cout<<a[i]<<"\t";
	}
    
    
	if(n%2==0)
	{
	int count = n/2;
    for (int i=0; i<n/2; i++)
		{
			int temp = a[i];
			a[i] = a[count];
			a[count++] = temp;
		}
	}
	else 
	{
		int count = n/2;
		for (int i=0; i<n/2; i++)
		{
			int temp = a[i];
			a[i] = a[count];
			a[count++] = temp;
		}
	}
    cout << "\n";
    for (int i=0; i<n; i++)
	{
		cout << a[i] <<"\t";
	}
	
    system ("pause");
	
    return 0;
}  