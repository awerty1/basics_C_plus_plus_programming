/*
Задание 2. С клавиатуры вводится четырехзначное число. Найти сумму его 
цифр. 
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	Int n,s=0;
	setlocale(LC_ALL, "Russian");
	cout<< "Введите четырехзначное число \n";
	cin>> n;
	if (n <= 9999 and n >= 1000)
	{
		while (n)
			{
				s+=(n%10);
				n/=10;
			}
	cout<<"Сумма цифр в числе= "<<s;
	}
	Else printf("Введено не 4-х значное число");
}