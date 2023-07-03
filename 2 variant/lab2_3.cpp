/*
Задание 3. Вывести на экран все четырехзначные натуральные числа, в 
записи которых нет двух одинаковых цифр. 
*/

#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a,b,c,d,n=0;
	for (a = 1; a <= 9; a++)
		for (b = 0; b <= 9; b++)
			for (c = 0; (c <= 9) and (a!=b); c++)
				for (d = 0; (d <= 9) and (a!=c)&&(b!=c); d++)
					if ((a != d) && (b != d) && (c != d))
					{
						cout << a << b << c << d << "\n";
						n++;
					}
	cout << "Всего чисел: " << n;
	system("pause");
}