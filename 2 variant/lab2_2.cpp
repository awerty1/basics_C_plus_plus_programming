/*
Задание 2. Вывести на экран последовательность из n чисел Фибоначчи (1 1 
2 3 5 8 13…). Сделать проверку на корректность ввода количества чисел.
*/

#include <iostream>

int main()
{
	int a = 1; 
	int b = 1; 
	int SIZE;
	
	std::cout << "Введите количество чисел Фибоначчи: \n";
	std::cin >> SIZE;
	
	 // Проверка на корректность ввода значения SIZE
    if (std::cin.fail() || SIZE <= 0)
    {
        std::cout << "Ошибка ввода. Пожалуйста, введите положительное целое число.\n";
        return 1;
    }
	
	while (SIZE--)
	{
		std::cout << a << " ";
		b += a;
		a = b - a;
	}
	
	return 0;
}