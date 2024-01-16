/*
Задание 3. Вводятся три произвольных числа a, b, c. Найти наибольшее 
среди них.
*/

#include <iostream>

int main() 
{
	float a,b,c;
	std::cout << "Введите число a: \n";
	std::cin >> a;
	std::cout << "Введите число b: \n";
	std::cin >> b;
	std::cout << "Введите число c: \n";
	std::cin >> c;
	if (a > b && a > c)
	{
	    std::cout << "Наибольшее число а: " << a << '\n';
	}
	else if (b > c && b > a) 
	{
	    std::cout << "Наибольшеечисло b: " << b << '\n';
	}
	else 
	{
	    std::cout << "Наибольшеечисло c: " << a << '\n';
	}
	
	return 0;
}