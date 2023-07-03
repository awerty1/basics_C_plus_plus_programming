/*
Задание 1. Написать программу для нахождения минимального из десяти 
произвольных чисел, вводимых с клавиатуры.
*/

#include <iostream>
#include <locale.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	const int s=10;
	int i, a[s];
	cout << "Введите 10 чесел" << " \n";
	for (i = 0;i < s;i++) { cin >> a[i]; }
	int min = a[0];
	for (i = 0;i < s;i++)
	{
		//cout << a[i] << "\t";
		if (min > a[i]) min = a[i];
	}
	cout << "\n"<<"Минимальное введенное число= " << min << "\n";
}