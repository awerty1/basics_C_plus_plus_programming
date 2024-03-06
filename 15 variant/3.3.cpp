/*
Задание 3. Задан массив из n случайных целых чисел (число n вводится с 
клавиатуры, его значение не больше 20). Удалить все двойки, если таковые 
имеются, и вывести измененный массив на экран. Дополнительные массивы 
использовать нельзя – меняем исходный массив с помощью сдвига элементов 
влево. Пример приведен в методичке. Сделать проверку на корректность ввода 
n.
*/

#include <iostream>

int main() 
{
    const int MAX_SIZE = 20;
    int n;

    do 
	{
        std::cout << "Введите количество элементов массива (не более 20): ";
        std::cin >> n;

        if (n < 1 || n > MAX_SIZE) 
		{
            std::cout << "Пожалуйста, введите корректное значение для n (от 1 до 20)." << std::endl;
        }
    } 
	while (n < 1 || n > MAX_SIZE);

    int array[MAX_SIZE];

    std::cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) 
	{
        std::cin >> array[i];
    }

    int shift = 0;

    for (int i = 0; i < n; ++i) 
	{
        if (array[i] == 2) 
		{
            shift++;
        } 
		else 
		{
            array[i - shift] = array[i];
        }
    }

    n -= shift;

    std::cout << "Измененный массив после удаления двоек: ";
    for (int i = 0; i < n; ++i) 
	{
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}