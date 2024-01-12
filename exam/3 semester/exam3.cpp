/*
Даны два числа. Поменять местами их значения. 
Написать процедуру, меняющую местами значения двух чисел без промежуточной переменной. 
*/

#include <iostream>

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() 
{
	int num1 = 10;
	int num2 = 20;
	
	std::cout << "num1 = " << num1 << std::endl;
	std::cout << "num2 = " << num2 << std::endl;

	swap(&num1, &num2);

	std::cout << "num1 = " << num1 << std::endl;
	std::cout << "num2 = " << num2 << std::endl;

	return 0;
}