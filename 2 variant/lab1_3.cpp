/*
Задание 3. Вводятся три произвольных числа a, b, c. Найти наибольшее 
среди них.
*/

#include <iostream>

using namespace std;

int main() 
{
	setlocale (LC_ALL, "Russian");
	float a,b,c;
	cout<<"Введите числоa \n";
	cin>>a;
	cout<<"Введите числоb \n";
	cin>>b;
	cout<<"Введите числоc \n";
	cin>>c;
	if (a>b and a>c) cout<<"Наибольшее число а= "<<a;
	else {
		if (b>c and b>a) 
			cout<<"Наибольшеечислоb= "<<b;
			else cout<<"Наибольшеечислоc= "<<a;
		}
}