/*
Задание 2. С клавиатуры вводится четырехзначное число. Найти сумму его 
цифр. 
*/

#include <iostream>

int main()
{
	int number; 
	int sum=0;
	
	std::cout << "Введите четырехзначное число: \n";
	std::cin >> number;
	
	if (number >= 1000 && number <= 9999)
	{
		while (number)
		{
			sum += (number % 10);
			number /= 10;
		}
		std::cout << "Сумма цифр в числе: " << sum << "\n";
	}
	else 
	{
		std::cout << "Введено не 4-х значное число\n";
	}
	
	return 0;	
}