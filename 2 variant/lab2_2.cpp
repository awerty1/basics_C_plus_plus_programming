/*
Задание 2. Вывести на экран последовательность из n чисел Фибоначчи (1 1 
2 3 5 8 13…). Сделать проверку на корректность ввода количества чисел.
*/

#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a = 1, b = 1, n;
	cout << "Введите n \n";
	cin >> n;
	while (n--)
	{
		cout << a << "\t";
		b += a;
		a = b - a;
	}
	system("pause");
}