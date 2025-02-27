/*
 *  Задание 2. Сформировать массив из N случайных целых чисел в диапазоне 
 *	от -10 до 10 (число N вводится с клавиатуры, его значение не больше 20) и 
 *	вывести элементы этого массива на экран. Вычислить следующие 
 *	характеристики массива (вычисление каждой из них оформить как отдельную 
 *	функцию, параметрами которой являются количество элементов массива и сам 
 *	массив):
 *	• сумму тех элементов массива, которые больше первого элемента 
 *	этого массива;
 *	• количество максимальных элементов массива.
 *	Выполнить следующую перестановку в массиве:
 *	• поменять местами первую и вторую половины массива – т.е. первый 
 * 	элемент поменять местами с первым элементом из второй 
 *	половины, второй – со вторым и т.д. Если в массиве нечётное 
 *	количество элементов, то средний элемент оставить на своём месте.
 *	Вывести преобразованный таким образом массив.
 */
 
#include <iostream>
#include <cstdlib>
#include <ctime>

void generateArray(int N, int array[]) 
{
    std::srand(std::time(0)); // Инициализация генератора случайных чисел
    for (int i = 0; i < N; ++i) 
    {
        array[i] = std::rand() % 21 - 10; // Генерация случайного числа от -10 до 10
    }
}

void printArray(int N, int array[]) 
{
    // Вывод массива на экран
    for (int i = 0; i < N; ++i) 
    {
        std::cout << array[i] << " ";
    }
    
    std::cout << std::endl;
}

int calculateSumGreaterThanFirst(int N, int array[]) 
{
    // Сумму элементов массива, которые больше первого элемента этого массива
    int firstElement = array[0];
    int sum = 0;
    for (int i = 1; i < N; ++i) 
    {
        if (array[i] > firstElement) 
        {
            sum += array[i];
        }
    }
    
    return sum;
}

int calculateMaxCount(int N, int array[]) 
{
	//  Количество максимальных элементов массива
    int max = array[0];
    int count = 1;
    for (int i = 1; i < N; ++i) 
    {
        if (array[i] > max) 
        {
            max = array[i];
            count = 1;
        } 
        else if (array[i] == max) 
        {
            count++;
        }
    }
    
    return count;
}

void swapFirstAndSecondHalves(int N, int array[]) 
{
// Поменять местами первую и вторую половины массива
    int middle = N / 2;
    for (int i = 0; i < middle; ++i) 
    {
        int temp = array[i];
        array[i] = array[middle + i];
        array[middle + i] = temp;
    }
}

int main() 
{
    int N;
    std::cout << "Введите количество элементов массива (не более 20): ";
    std::cin >> N;

    // обработка исключительной ситуации
    if (N > 20) 
    {
        std::cout << "Ошибка! Количество элементов превышает 20." << std::endl;
        return 0;
    }
    
    int array[20];

    generateArray(N, array);

    std::cout << "Исходный массив: ";
    printArray(N, array);

    int sum = calculateSumGreaterThanFirst(N, array);
    std::cout << "Сумма элементов больше первого элемента: " << sum << std::endl;

    int maxCount = calculateMaxCount(N, array);
    std::cout << "Количество максимальных элементов: " << maxCount << std::endl;

    swapFirstAndSecondHalves(N, array);

    std::cout << "Преобразованный массив: ";
    printArray(N, array);

    return 0;
}
