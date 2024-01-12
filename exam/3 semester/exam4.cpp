/*
*Найти сумму всех делителей числа!
*/

#include <iostream>

int find_sum_of_divisors(int number)
{
	int sum = 0;
	int testwall;
	
	for(int i = 1; i <= number; i++)
	{
		if(number % i == 0)
		{
			sum += i;
			std::cout << "Делитель:" << i << std::endl;
		}
	}

 return sum;
}

int main()
{
	int number;
	std::cout << "Введите число:";
	std::cin >> number;
	int  sum = find_sum_of_divisors(number);
	std::cout << "Сумма всех делителей числа:" << sum << std::endl;

	return 0;
}