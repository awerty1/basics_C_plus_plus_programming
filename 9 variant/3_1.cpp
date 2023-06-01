/*
Задание 1. Сформировать массив A из n случайных целых чисел в диапазоне 
от -10 до 10 (число n вводится с клавиатуры, его значение не больше 20). Найти 
произведение и количество всех положительных четных элементов. Сделать 
проверку на корректность ввода n.
*/

#include <iostream>
using namespace std;

int main() 
{
    int n; 
    int product = 1; 
    int count = 0;
    
    //Инициализация генератора случайных чисел
    srand(time(nullptr));
    
    cout << "Введите значение n (<=20): ";
    cin >> n;

    if (n <= 0 || n > 20) 
    {
        cout << "Некорректное значение n!. \
                Пожалуйста введите число между 1 и 20." << endl;
        return 0;
    }

    int array_A[n];
    cout << "Current array:" << endl;
    for (int i = 0; i < n; i++) 
	{
        array_A[i] = rand() % 21 - 10;
        cout << array_A[i] << " ";
        if ((array_A[i] > 0) && (array_A[i] % 2 == 0)) 
		{
            product *= array_A[i];
            count++;
        }
    }
    cout << endl;
    
    if (product == 1)
    {
        product = 0;
    }

    cout << "Произведение положительных четных элементов: " << product << endl;
    cout << "Количество положительных четных элементов: " << count << endl;

    return 0;
}