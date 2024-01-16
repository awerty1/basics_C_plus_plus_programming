/*
Задание 1. Написать программу для нахождения минимального из десяти 
произвольных чисел, вводимых с клавиатуры.
*/

#include <iostream>

int main()
{
	const int SIZE = 10;
	int numbers[SIZE];
	std::cout << "Введите 10 чесел: " << " \n";
	for (int i = 0; i < SIZE;i++) 
	{ 
		std::cin >> numbers[i]; 
	}
	
	int min = numbers[0];
	for (int i = 0; i < SIZE; i++)
	{
		//cout << a[i] << "\t";
		if (min > numbers[i]) 	
		{
			min = numbers[i];
		}
	}
	
	std::cout << "\n" << "Минимальное введенное число= " << min << "\n";
}