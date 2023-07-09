/*
Задание 4. Сформировать два массива А и В – каждый из n (число n вводится 
с клавиатуры, его значение не больше 20) случайных целых чисел. Элементы 
массива A должны быть в диапазоне от -10 до -1, а элементы массива B – от 1 до 
10. Вывести оба массива, сначала A, потом B. Программа должна сформировать 
массив C, в который необходимо поместить только те элементы массива А, для 
которых есть равные по абсолютной величине значения в массиве В. Вывести 
массив С.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int* createDynamicArray(int size) 
{
    return new int[size];
}

void deleteDynamicArray(int* arr) 
{
    delete[] arr;
}

int main() 
{
	int n;
	do {
		std::cout << "Введите число n (не больше 20): ";
		std::cin >> n;
		  
		if (n > 20 || n <= 0) 
		{
			std::cout << "Число n должно быть от 1 до 20." << std::endl;
		}
	} while (n > 20 || n <= 0);

	// Установим генератор случайных чисел в зависимость от времени
	srand(time(0));

	int* A = createDynamicArray(n);
	int* B = createDynamicArray(n);

	std::cout << "Массив A: ";
	for (int i = 0; i < n; i++) 
	{
		A[i] = rand() % (-10 - (-1) + 1) + (-1);
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Массив B: ";
	for (int i = 0; i < n; i++) 
	{
		B[i] = rand() % (10 - 1 + 1) + 1;
		std::cout << B[i] << " ";
	}
	std::cout << std::endl;

	int* C = createDynamicArray(n);
	int cCount = 0;

	for (int i = 0; i < n; i++) 
	{
		bool isDuplicate = false;
		for(int j = 0; j < cCount; j++)
		{
			if (C[j] == A[i])
			{
				isDuplicate = true;
				break;
			}
		}
		
		if (!isDuplicate)
		{
		    for (int j = 0; j < n; j++) 
		    {
		        if (abs(A[i]) == B[j]) 
    			{
    				C[cCount] = A[i];
    				cCount++;
    				break;
    			}
		    }
		}
	}

  
	if (cCount)
    	{
	        std::cout << "Массив C: ";
	        for (int i = 0; i < cCount; i++) 
	        {
	            std::cout << C[i] << " ";
	        }
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Массив C не содержит элементов." << std::endl;
	}

	
	deleteDynamicArray(A);
	deleteDynamicArray(B);
	deleteDynamicArray(C);
	
	return 0;
}
